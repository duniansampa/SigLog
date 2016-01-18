#include "MibManager.h"

MibManager::MibManager(const QString & mibFileFullPath) : QObject(0)
{

    this->_PtrTree = NULL;
    this->_MibFileInfo = new QFileInfo(mibFileFullPath);

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

 QVector< struct tree *> & MibManager::getMibObjects(){

    this->_VecMibObjects.clear();

    this->get_oid_report();

    return this->_VecMibObjects;
}

void MibManager::get_oid_report()
{
    struct tree    *tp;

    clear_tree_flags(this->_PtrTree);

    for (tp = this->_PtrTree; tp; tp = tp->next_peer){
        this->get_subtree_oid_report(tp);
    }
}

QString MibManager::getModuleName(){
    return this->_MibFileInfo->baseName();
}

int MibManager::getModuleId(){
    return this->_ModId;
}


QPair< QVector<unsigned long>, QVector<QString> > MibManager::getLabeledOid(const struct tree *tp){

    const struct tree * temp;
    QVector<unsigned long> oidVector;
    QVector<QString> labVector;

    temp = tp;

    while (temp) {
            oidVector.push_front(temp->subid);
            labVector.push_front( QString(temp->label) );
            temp = temp->parent;
    }


    return qMakePair(oidVector, labVector);
}


void MibManager::get_subtree_oid_report(struct tree *tree)
{
    struct tree    *tp;


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


        if(this->_ModId == tp->modid ){
              this->_VecMibObjects.push_back(tp);
        }

        this->get_subtree_oid_report(tp->child_list);
    }
}


QString MibManager::type2string(int control){


    stringstream ss;
    switch (control) {

        case TYPE_OTHER:
            ss << "OTHER";
            break;

        case TYPE_OBJID:
            ss << "OBJID";
            break;
            QString getModuleName();
            int getModuleId();

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
    return QString(ss.str().c_str());
}


QString MibManager::status2string(int control){


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
    return QString(ss.str().c_str());
}


QString MibManager::acess2string(int control){


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
    return QString(ss.str().c_str());
}
