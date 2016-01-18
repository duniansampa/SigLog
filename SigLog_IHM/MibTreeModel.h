#ifndef MIB_TREE_MODEL_HPP
#define MIB_TREE_MODEL_HPP

#include <QStandardItemModel>
#include <QMetaObject>
#include <QMetaEnum>
#include <QObject>


class MibTreeModel : public QStandardItemModel
{
   Q_OBJECT
   Q_ENUMS(Roles)
   Q_PROPERTY(QVariant firstIndex READ firstIndex)
   Q_PROPERTY(NOTIFY loadMibChanged)
   Q_PROPERTY(NOTIFY unLoadMibChanged)
   Q_PROPERTY(QVariantList  modulesLoaded READ modulesLoaded )

    public:
        explicit MibTreeModel(QObject *parent = 0);
        virtual ~MibTreeModel() = default;

        enum Roles {

            MibLabelRole = Qt::UserRole + 100,
            MibOidRole,
            MibTypeRole,
            MibIconRole,
            MibModidRole,
            MibStatusRole,
            MibAcessRole,
            MibDescriptionRole,
            MibReferenceRole,
            MibDefaultValueRole,
            MibHintRole,
            MibUnitRole
        };


        QVariant firstIndex() const
        {
            return this->_FirstIndex;
        }
        QVariantList modulesLoaded() const{
            return this->_ModulesLoaded;
        }
        Q_INVOKABLE bool isIndexValid(const QModelIndex & index){
            return index.isValid();
        }
        Q_INVOKABLE QModelIndex indexParent(const QModelIndex & index){
            return index.parent();
        }
        Q_INVOKABLE bool hasChildren(const QModelIndex & parent = QModelIndex()){
            return QStandardItemModel::hasChildren(parent);
        }

        Q_INVOKABLE bool hasIndex(int row, int column, const QModelIndex & parent = QModelIndex()){
           return QStandardItemModel::hasIndex(row, column,  parent);
        }
        Q_INVOKABLE QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()){
            return QStandardItemModel::index(row, column, parent );
        }

        Q_INVOKABLE int rowCount(const QModelIndex & parent = QModelIndex()){
            return QStandardItemModel::rowCount(parent);
        }

        Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex()){
            return QStandardItemModel::removeRows(row, count, parent);
        }

        QHash<int, QByteArray> roleNames() const override;

        Q_INVOKABLE void loadMibToThree(const QString & mibFileFullPath);
        Q_INVOKABLE void unloadMibToThree(const QModelIndex & index);

        Q_INVOKABLE int role(const QByteArray &roleName) const;
        Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;


signals:
      void loadMibChanged();
      void unLoadMibChanged();
public slots:
        Q_INVOKABLE void addEntry(QString & moduleName );

private:
    void setNothingData(QStandardItem * entry, QString  label, int op = 0);

    QVariantList _ModulesLoaded;
    QStandardItem* getBranch(const QString & moduloName, const QString & parentOid);
    QHash<int, QByteArray> m_roleNameMapping;
    QVector< struct tree *> _VecMibObjects;
    QModelIndex _FirstIndex;

};


#endif // MIB_TREE_MODEL_HPP
