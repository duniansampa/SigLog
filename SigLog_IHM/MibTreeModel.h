#ifndef MIB_TREE_MODEL_HPP
#define MIB_TREE_MODEL_HPP


#include <Includes.h>

#include <MibManager.h>

#include <QStandardItemModel>
#include <QMetaObject>
#include <QMetaEnum>

class MibTreeModel : public QStandardItemModel
{
    Q_OBJECT
    Q_ENUMS(Roles)

    public:
        explicit MibTreeModel(QObject *parent = 0);
        virtual ~MibTreeModel() = default;

        enum Roles {

            MibLabelRole = Qt::UserRole + 100,
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


        QHash<int, QByteArray> roleNames() const override;

        Q_INVOKABLE void loadMibToThree(const QString & mibFileFullPath);

        Q_INVOKABLE int role(const QByteArray &roleName) const;
        Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        Q_INVOKABLE void addEntry( const QString& moduloName, const struct tree * tp);

private:
    QStandardItem* getBranch( const QString& branchName );
    QHash<int, QByteArray> m_roleNameMapping;
};

#endif // MIB_TREE_MODEL_HPP
