
#include "MibTreeModel.h"

MibTreeModel::MibTreeModel(QObject *parent) :
    QStandardItemModel(parent)
{

    m_roleNameMapping[MibLabelRole] = "mibLabel";
    m_roleNameMapping[MibOidRole]  = "mibOid";
    m_roleNameMapping[MibTypeRole] = "mibType";
    m_roleNameMapping[MibIconRole] = "mibIcon";
    m_roleNameMapping[MibModidRole] = "mibModaddEntryid";
    m_roleNameMapping[MibStatusRole] = "mibStatus";
    m_roleNameMapping[MibAcessRole] = "mibAcess";
    m_roleNameMapping[MibDescriptionRole] = "mibDescription";
    m_roleNameMapping[MibReferenceRole] = "mibReference";
    m_roleNameMapping[MibDefaultValueRole] = "mibDefaultValue";
    m_roleNameMapping[MibHintRole] = "mibHint";
    m_roleNameMapping[MibUnitRole] = "mibUnit";

    init_snmp("snmpd");
    //init_mib_modules();

}

void MibTreeModel::addEntry( const QString & moduloName, const struct tree * tp, QString & oid)
{

    stringstream parentOid;
    stringstream objetOid;


    for(int i = 0 ; i < oid.size(); i++){
       objetOid << "." << (int) oid[i].cell();

       if(i < oid.size() - 1){
         parentOid <<"." << (int) oid[i].cell();
       }
    }


    auto childEntry = new QStandardItem( QString::fromStdString(objetOid.str()));
    childEntry->setData( QString(tp->label), MibLabelRole );
    //childEntry->setData( tp->type, MibTypeRole );
    //childEntry->setData( icon,  MibIconRole);
    //childEntry->setData( tp->modid,  MibModidRole);
    //childEntry->setData( tp->status,  MibStatusRole);
   // childEntry->setData( tp->access, MibAcessRole );
   //childEntry->setData( tp->description, MibDescriptionRole );
    //childEntry->setData( tp->reference,  MibReferenceRole);
   // childEntry->setData( tp->defaultValue,  MibDefaultValueRole);
    //childEntry->setData( tp->hint,  MibHintRole);
    //childEntry->setData( tp->units,  MibUnitRole);

    //parentOid = parentOid.size() == 0? "MIB":parentOid;
    QStandardItem * parentEntry = getBranch( QString::fromStdString(parentOid.str()));
    if( parentEntry){
        parentEntry->appendRow( childEntry );
    }else{
        this->appendRow( childEntry );
    }
}
QVariant MibTreeModel::data(const QModelIndex & index, int role) const{

    if (!index.isValid()) {
        return QVariant();
    }
    switch (role) {

        case Qt::DisplayRole:
        case MibOidRole:
            return QStandardItemModel::data(index, Qt::DisplayRole);

        case MibLabelRole:
            return QStandardItemModel::data(index, MibLabelRole);

        case MibTypeRole:
             return QStandardItemModel::data(index, MibTypeRole);

        case Qt::DecorationRole:
        case MibIconRole:
             return QStandardItemModel::data(index, Qt::DecorationRole);

        case MibModidRole:
             return QStandardItemModel::data(index, MibModidRole).toString();

        case MibStatusRole:
             return QStandardItemModel::data(index, MibStatusRole);

        case MibAcessRole:
             return QStandardItemModel::data(index,MibAcessRole);

        case MibDescriptionRole:
             return QStandardItemModel::data(index, MibDescriptionRole);

        case MibReferenceRole:
              return QStandardItemModel::data(index, MibReferenceRole);

        case MibDefaultValueRole:
              return QStandardItemModel::data(index, MibDefaultValueRole);

        case MibHintRole:
              return QStandardItemModel::data(index, MibHintRole);

         case MibUnitRole:
              return QStandardItemModel::data(index, MibUnitRole);
        default:
            break;
    }

    return QVariant();
}


int MibTreeModel::role(const QByteArray &roleName) const
{
    QMetaEnum e = metaObject()->enumerator(metaObject()->indexOfEnumerator("Roles"));
    Q_ASSERT(e.isValid());
    return e.keyToValue(roleName);
}


QStandardItem *MibTreeModel::getBranch(const QString & parentOid)
{
    QStandardItem* entry = NULL ;
    auto entries = this->findItems( parentOid, Qt::MatchRecursive, 0);
    if ( entries.count() > 0 )
    {
        entry = entries.at(0);
    }
    return entry;
}

QHash<int, QByteArray> MibTreeModel::roleNames() const
{
    return m_roleNameMapping;
}

void MibTreeModel::loadMibToThree(const QString & mibFileFullPath){
    MibManager * mibManager = new MibManager(mibFileFullPath.toStdString().c_str(), false);

    mibManager->loadMib();

    mibManager->setFunction(this, &MibTreeModel::addEntry);
    mibManager->printToFunction();

    delete mibManager;
}
