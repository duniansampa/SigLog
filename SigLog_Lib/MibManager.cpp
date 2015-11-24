#include "MibManager.h"

MibManager::MibManager(const char * mibFileFullPath, bool isPrintToFile)
{

    this->_PtrTree = NULL;
    this->_OutFile = NULL;

    this->_MibFileInfo = new QFileInfo(mibFileFullPath);

    if(isPrintToFile){
        this->_OutFile = new QFile();

        this->_OutFile->setFileName("Out_" + this->_MibFileInfo->fileName() );

        this->_OutFile->open(QIODevice::WriteOnly | QIODevice::Text);

        this->_Fout.setDevice(this->_OutFile);
    }

    this->isPrint_labeledoid  = false;
    this->isPrint_oid         = false;
    this->isPrint_symbolic    = false;
    this->isPrint_mibchildoid = false;
    this->isPrint_suffix      = false;
    this->isPrint_custom      = false;
    this->isPrint_function    = false;

}

int MibManager::loadMib(){

    if(!this->_PtrTree){

        add_mibdir(this->_MibFileInfo->absolutePath().toStdString().c_str());
        this->_PtrTree = read_mib(this->_MibFileInfo->absoluteFilePath().toStdString().c_str());
        this->_ModId = which_module(this->_MibFileInfo->baseName().toStdString().c_str());
    }

    return this->_PtrTree == NULL;
}

MibManager::~MibManager(){

}

void MibManager::print(){

    this->loadMib();

    this->isPrint_labeledoid  = false;
    this->isPrint_oid         = false;
    this->isPrint_symbolic    = false;
    this->isPrint_mibchildoid = false;
    this->isPrint_suffix      = false;
    this->isPrint_custom      = true;
    this->isPrint_function    = false;

     this->print_oid_report();

     if(this->_OutFile)
        this->_OutFile->close();
}

void MibManager::print_oid_report()
{
    struct tree    *tp;

    clear_tree_flags(this->_PtrTree);

    for (tp = this->_PtrTree; tp; tp = tp->next_peer)
        this->print_subtree_oid_report(tp, 0);
}


string MibManager::print_parent_labeledoid(struct tree *tp, stringstream * ss)
{
    if (tp) {
        if (tp->parent) {
           this->print_parent_labeledoid(tp->parent, ss);
        }
       (*ss) <<"."<< tp->label << "("  << tp->subid  << ")";
    }

    return (*ss).str();
}

string MibManager::print_parent_oid(struct tree *tp, stringstream * ss)
{
    if (tp) {
        if (tp->parent) {
            this->print_parent_oid(tp->parent,ss);
        }
        (*ss) <<"."<< tp->subid;
    }

    return (*ss).str();
}

static QString getObjectOid(struct tree *tp){
    QString ss;
    static struct tree *temp;
    unsigned long elems[100];
    int elem_cnt = 0;
    int i = 0;
    temp = tp;
    if (temp) {
        while (temp->parent) {
                elems[elem_cnt++] = temp->subid;
                temp = temp->parent;
        }
        elems[elem_cnt++] = temp->subid;
    }
    for (i = elem_cnt - 1; i >= 0; i--) {
        ss += (char) elems[i];
    }
    return ss;
}

string MibManager::print_parent_mibchildoid(struct tree *tp, stringstream * ss)
{
    static struct tree *temp;
    unsigned long elems[100];
    int elem_cnt = 0;
    int i = 0;
    temp = tp;
    if (temp) {
        while (temp->parent) {
                elems[elem_cnt++] = temp->subid;
                temp = temp->parent;
        }
        elems[elem_cnt++] = temp->subid;
    }
    for (i = elem_cnt - 1; i >= 0; i--) {

       (*ss) <<"."<< elems[i];
    }
    return (*ss).str();
}

string MibManager::print_parent_label(struct tree *tp, stringstream * ss)
{
    if (tp) {
        if (tp->parent) {
            this->print_parent_label(tp->parent);
        }
        (*ss) << "."<< tp->label;
    }
    return (*ss).str();
}



void MibManager::print_subtree_oid_report(struct tree *tree, int count)
{
    struct tree    *tp;

    count += 2;

    /*
     * sanity check
     */

    if (!tree) {
        return;
    }

    /*
     * find the not reported peer with the lowest sub-identifier.
     * if no more, break the loop and cleanup.
     * set "reported" flag, and create report for this peer.
     * recurse using the children of this peer, if any.
     */
    while (1) {
        register struct tree *ntp;

        tp = NULL;
        for (ntp = tree; ntp; ntp = ntp->next_peer) {
            if (ntp->reported){
                continue;
            }

            //tp is the pointer for the element with the lowest subid
            if (!tp || (tp->subid > ntp->subid))
                tp = ntp;
        }
        if (!tp)
            break;

        tp->reported = 1;

        if (this->isPrint_labeledoid && this->_OutFile) {
            this->_Fout <<  QString::fromStdString( this->print_parent_labeledoid(tp) ) << endl;
        }
        if (this->isPrint_oid && this->_OutFile) {
            this->_Fout << QString::fromStdString( this->print_parent_oid(tp) ) << endl;
        }
        if (this->isPrint_symbolic && this->_OutFile) {
            this->_Fout << QString::fromStdString( this->print_parent_label(tp) ) << endl;
        }
        if (this->isPrint_mibchildoid && this->_OutFile) {
            this->_Fout <<"\"" << tp->label <<"\"\t";
            this->_Fout << "\t\t\"";
            this->_Fout << QString::fromStdString( this->print_parent_mibchildoid(tp) ) << endl;
            this->_Fout << "\"" << endl;
        }
        if (this->isPrint_suffix && this->_OutFile) {
            int i;
            for (i = 0; i < count; i++)
                this->_Fout <<  "  ";
            this->_Fout << tp->label << "(" <<  tp->subid<< ")" << " type=" << tp->type;
            if (tp->tc_index != -1)
                this->_Fout <<" tc="<< tp->tc_index;
            if (tp->hint)
                this->_Fout <<" hint="<< tp->hint;
            if (tp->units)
                this->_Fout <<" units="<< tp->units;

            this->_Fout << endl;
        }

        if (this->isPrint_custom && this->_OutFile) {

            if(this->_ModId == tp->modid ){
                QString tab(count, ' ');

                this->_Fout << tab << "-----------------------------------"  << endl;

                this->_Fout << tab << tp->label    <<" : "<< QString::fromStdString(this->print_parent_mibchildoid(tp)) << endl;

                this->_Fout << tab << "  + type: " << QString::fromStdString( MibManager::type2string(tp->type)) << endl;

                this->_Fout << tab << "  + modid: " << tp->modid << endl;

                this->_Fout << tab << "  + status: " << QString::fromStdString( MibManager::status2string(tp->status)) << endl;

                this->_Fout << tab << "  + access: " << QString::fromStdString( MibManager::acess2string(tp->access)) << endl;

                if(tp->augments)
                    this->_Fout << tab << "  + augments: " << tp->augments << endl;

                if(tp->description)
                    this->_Fout << tab << "  + description: " << tp->description << endl;

                if(tp->reference)
                    this->_Fout << tab << "  + reference: "   << tp->reference  << endl;

                if(tp->defaultValue)
                    this->_Fout << tab << "  + defaultValue: "<< tp->defaultValue << endl;

                if (tp->hint)
                    this->_Fout << tab << "  + hint: "<<tp->hint << endl;

                if (tp->units)
                    this->_Fout << tab << "  + unit: "<< tp->units  << endl;
            }
        }

        if(this->isPrint_function && (this->_ModId == tp->modid) ){
            if( !this->_OutFile && this->_PrtMibTreeModel && this->_PtrMibFunction){
                 QString ss = getObjectOid(tp);
                ( (*_PrtMibTreeModel).*_PtrMibFunction)(_MibFileInfo->baseName(), tp,  ss );
            }
        }

        this->print_subtree_oid_report(tp->child_list, count);
    }
}

 void MibManager::printToFunction( ){

     this->loadMib();

     this->isPrint_labeledoid  = false;
     this->isPrint_oid         = false;
     this->isPrint_symbolic    = false;
     this->isPrint_mibchildoid = false;
     this->isPrint_suffix      = false;
     this->isPrint_custom      = false;
     this->isPrint_function    = true;

     this->print_oid_report();
 }

void MibManager::setFunction(MibTreeModel *mibTreeModel, void (MibTreeModel::*ptrFunc)(const QString &, const tree *, QString & )){
    this->_PrtMibTreeModel = mibTreeModel;
    this->_PtrMibFunction = ptrFunc;
}

string MibManager::type2string(int control){


    stringstream ss;
    switch (control) {

        case TYPE_OTHER:
            ss << "OTHER";
            break;

        case TYPE_OBJID:
            ss << "OBJID";
            break;

        case TYPE_OCTETSTR:
            ss << "OCTETSTR";
            break;

        case TYPE_INTEGER:
            ss << "INTEGER";
            break;

        case TYPE_NETADDR:
            ss << "NETADDR";
            break;

        case TYPE_IPADDR:
            ss << "IPADDR";
            break;

        case TYPE_COUNTER:
            ss << "COUNTER";
            break;

        case TYPE_GAUGE:
            ss << "GAUGE";
            break;

        case TYPE_TIMETICKS:
            ss << "TIMETICKS";
            break;

        case TYPE_OPAQUE:
            ss << "OPAQUE";
            break;

        case TYPE_NULL:
            ss << "NULL";
            break;

        case TYPE_COUNTER64:
            ss << "COUNTER64";
            break;

        case TYPE_BITSTRING:
            ss << "BITSTRING";
            break;

        case TYPE_NSAPADDRESS:
            ss << "NSAPADDRESS";
            break;

        case TYPE_UINTEGER:
            ss << "UINTEGER";
            break;

        case TYPE_UNSIGNED32:
            ss << "UNSIGNED32";
            break;

        case TYPE_INTEGER32: //TYPE_SIMPLE_LAST
            ss << "INTEGER32";
            break;

        case TYPE_TRAPTYPE:
            ss << "TRAPTYPE";
            break;

        case TYPE_NOTIFTYPE:
            ss << "NOTIFTYPE";
            break;

        case TYPE_OBJGROUP:
            ss << "OBJGROUP";
            break;

        case TYPE_NOTIFGROUP:
            ss << "NOTIFGROUP";
            break;

        case TYPE_MODID:
            ss << "MODID";
            break;


        case TYPE_AGENTCAP:
            ss << "AGENTCAP";
            break;


        case TYPE_MODCOMP:
            ss << "MODCOMP";
            break;

        case TYPE_OBJIDENTITY:
            ss << "OBJIDENTITY";
            break;

    default:

        ss << "";
        break;
    }
    return ss.str();
}


string MibManager::status2string(int control){


    stringstream ss;
    switch (control) {

    case MIB_STATUS_MANDATORY:
        ss << "MANDATORY";
        break;

    case MIB_STATUS_OPTIONAL:
        ss << "OPTIONAL";
        break;

    case MIB_STATUS_OBSOLETE:
        ss << "OBSOLETE";
        break;

    case MIB_STATUS_DEPRECATED:
        ss << "DEPRECATED";
        break;

    case MIB_STATUS_CURRENT:
        ss << "CURRENT";
        break;
    default:

        ss << "";
        break;
    }
    return ss.str();
}


string MibManager::acess2string(int control){


    stringstream ss;
    switch (control) {
    case MIB_ACCESS_READONLY:
        ss << "READONLY";
        break;

    case MIB_ACCESS_READWRITE:
        ss << "READWRITE";
        break;

    case MIB_ACCESS_WRITEONLY:
        ss << "WRITEONLY";
        break;

    case MIB_ACCESS_NOACCESS:
        ss << "NOACCESS";
        break;

    case MIB_ACCESS_NOTIFY:
        ss << "NOTIFY";
        break;

    case MIB_ACCESS_CREATE:
        ss << "CREATE";
        break;


    default:

        ss << "";
        break;
    }
    return ss.str();
}
