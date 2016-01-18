#include <Includes.h>
#include <MibManager.h>
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

    auto entry = new QStandardItem("__MODULOS_MIB_CARREGADOS__");
    this->setNothingData( entry, "Módulos Carregados");

    this->appendRow(entry);
    this->_FirstIndex =  this->indexFromItem(entry);
}

void MibTreeModel::addEntry(QString & moduleName )
{
    //Add the module's name
    QStandardItem * parentEntry = getBranch(moduleName, moduleName );

    for(int i  = 0 ; i < this->_VecMibObjects.size(); i++){


        QString parentOid;
        QString objetOid;
        QString labeledOid;

        struct tree *  tp = this->_VecMibObjects[i];
        QPair< QVector<unsigned long>, QVector<QString> > pair = MibManager::getLabeledOid(tp);

        for(int i = 0 ; i < pair.first.size(); i++){
             objetOid += ".";
             objetOid += QString::number( pair.first.at(i) );

             labeledOid += ".";
             labeledOid += pair.second.at(i);

           if(i < pair.first.size() - 1){
             parentOid +=".";
             parentOid += QString::number( pair.first.at(i) );
           }
        }

        auto childEntry = new QStandardItem(moduleName + objetOid );
        childEntry->setData( QString(tp->label), MibLabelRole );
        childEntry->setData( objetOid, MibOidRole );
        childEntry->setData( MibManager::type2string(tp->type), MibTypeRole );
        //childEntry->setData( icon,  MibIconRole);
        childEntry->setData( tp->modid,  MibModidRole);
        childEntry->setData( MibManager::status2string(tp->status),  MibStatusRole);
        childEntry->setData( MibManager::acess2string(tp->access), MibAcessRole );
        childEntry->setData( QString( tp->description), MibDescriptionRole );
        childEntry->setData( QString( tp->reference),  MibReferenceRole);
        childEntry->setData( QString(tp->defaultValue),  MibDefaultValueRole);
        childEntry->setData( QString(tp->hint),  MibHintRole);
        childEntry->setData( tp->units,  MibUnitRole);

        QStandardItem * parentEntry = getBranch(moduleName, parentOid );
        if( parentEntry){
            parentEntry->appendRow( childEntry );
        }else{
            this->appendRow( childEntry );
        }
    }
    this->_VecMibObjects.clear();

}
QVariant MibTreeModel::data(const QModelIndex & index, int role) const{

    if (!index.isValid()) {
        return QVariant();
    }
    switch (role) {

        case Qt::DisplayRole:
            return QStandardItemModel::data(index, Qt::DisplayRole);
        case MibOidRole:
             return QStandardItemModel::data(index, MibOidRole);

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

void MibTreeModel::setNothingData(QStandardItem * entry, QString label, int op){
    entry->setData( label, MibLabelRole );
    entry->setData( "", MibOidRole );
    entry->setData( "", MibTypeRole );
    //entry->setData( icon,  MibIconRole);
    entry->setData( "",  MibModidRole);
    entry->setData( "",  MibStatusRole);
    entry->setData( "", MibAcessRole );
    entry->setData( "", MibDescriptionRole );
    entry->setData( "",  MibReferenceRole);
    entry->setData( "",  MibDefaultValueRole);
    entry->setData( "",  MibHintRole);
    entry->setData( "",  MibUnitRole);
}

int MibTreeModel::role(const QByteArray &roleName) const
{
    QMetaEnum e = metaObject()->enumerator(metaObject()->indexOfEnumerator("Roles"));
    Q_ASSERT(e.isValid());
    return e.keyToValue(roleName);
}


QStandardItem *MibTreeModel::getBranch(const QString & moduloName, const QString & parentOid)
{
    QStandardItem* entry = NULL ;
    QStandardItem* parentEntry = NULL;

    auto entries = this->findItems( moduloName + parentOid, Qt::MatchRecursive, 0);

    if ( entries.count() > 0)
    {
        entry = entries.at(0);
    }else{      
         entries = this->findItems( moduloName, Qt::MatchRecursive, 0);
         if( entries.count() > 0 ){
              entry = entries.at(0);
         }else{
            entries = this->findItems("__MODULOS_MIB_CARREGADOS__", Qt::MatchRecursive, 0);

            parentEntry = entries.at(0);

            entry = new QStandardItem(moduloName);
            this->setNothingData(entry,moduloName);

            parentEntry->appendRow(entry);

            this->_ModulesLoaded.push_back(moduloName);
        }
    }
    return entry;
}



QHash<int, QByteArray> MibTreeModel::roleNames() const
{
    return m_roleNameMapping;
}

void MibTreeModel::loadMibToThree(const QString & mibFileFullPath){

    //this->_VecMibObjects.clear();

    MibManager mibManager(mibFileFullPath);

    QString moduleName  = mibManager.getModuleName();

    /*
    bool mustLoad = true;
    for(int i = 0 ; i < this->_ModulesLoaded.size(); i++ ){
        if(this->_ModulesLoaded.at(i).value<QModelIndex>().data(MibLabelRole) == moduleName){
            mustLoad = false;
        }
    }*/

    if( this->_ModulesLoaded.contains(moduleName) == false){

        cout<< "Loading the Mib..."<<endl;


        if( mibManager.loadMib() == 0){
            cout<< "The Mib loaded successfuly..."<<endl;
            cout <<"Getting the mibs objects..." << endl;

            this->_VecMibObjects = mibManager.getMibObjects();

            this->addEntry(moduleName);

            cout <<"Mibs objects was loaded sucessfuly." << endl;

        }else{
            cout<< "The Mib was not loaded successfuly"<<endl;
        }
    }else{
        cout << "Mib module is already loaded." << endl;
    }

}

void MibTreeModel::unloadMibToThree(const QModelIndex & index){

  if(index == this->firstIndex()){
      bool ok;
      int count = this->rowCount(index);

      if( (ok = this->removeRows(0, count, index))){
        this->_ModulesLoaded.clear();
      }
     // cout<<"Ok: "<< ok << " count: "<< count<< endl;
  }else{
    bool ok;
    QString moduleName = this->data(index,Qt::DisplayRole).toString();
    if( (ok = this->removeRows(index.row(), 1, index.parent()))){
        this->_ModulesLoaded.removeOne(moduleName);
    }
    //cout<<"Ok: "<< ok <<" size: "<< this->_ModulesLoaded.size() <<  endl;
  }
}

