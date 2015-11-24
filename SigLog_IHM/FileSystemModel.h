#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H

#include <QObject>
#include <QFileSystemModel>
#include <QPersistentModelIndex>
#include <QSet>
#include <QMetaObject>
#include <QMetaEnum>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QItemSelectionModel>
#include <QDateTime>
#include <QDebug>


class FileSystemModel: public QFileSystemModel
{
    Q_OBJECT
    Q_ENUMS(Roles)
    Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath)
    Q_PROPERTY(QVariant seekData NOTIFY seekDataChanged)

public:
    explicit FileSystemModel(QObject *parent = 0);
    virtual ~FileSystemModel();

    enum Roles {
        FileNameRole = Qt::UserRole + 100,
        FilePathRole,
        FileIconRole,
        FileSizeRole,
        FileTypeRole,
        FileModifiedRole,
        FileIsDirRole,
        FileIsSelectedRole,
        FileIsCurrentRole,
        FileModelIndex
    };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE bool fileExists(const QString &path) const;
    Q_INVOKABLE bool dirExists(const QString &dir) const;
    Q_INVOKABLE QString pathFromDirFile(const QString &directory, const QString &file) const;
    Q_INVOKABLE QString filenameFromPath(const QString &path) const;
    Q_INVOKABLE QString directoryFromPath(const QString &path) const;

    Q_INVOKABLE QString homePath() const;
    Q_INVOKABLE QString currentPath() const;

    Q_INVOKABLE int role(const QByteArray &roleName) const;
    Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE QString directory() const;
    Q_INVOKABLE QModelIndex directoryIndex(const QString &path = QString()) const;

    QModelIndex setDirectory(const QString &directory);

    Q_INVOKABLE void setSelected(const QModelIndex &index, bool selected);
    Q_INVOKABLE QVariantList selected() const;

signals:
    void seekDataChanged( QVariant name, QVariant value ) const;
private slots:
    void slotRootPathChanged(const QString &newPath);
    void slotDirectoryLoaded(const QString &path);
    void slotFileRenamed(const QString &path, const QString &oldName, const QString &newName);

private:
    QPersistentModelIndex m_rootIndex;
    QItemSelectionModel *m_selectionModel;
    QHash<int, QByteArray> m_roleNameMapping;
};

Q_DECLARE_METATYPE(QModelIndex)
Q_DECLARE_METATYPE(const QModelIndex *)
Q_DECLARE_METATYPE(FileSystemModel*)


#endif // FILESYSTEMMODEL_H
