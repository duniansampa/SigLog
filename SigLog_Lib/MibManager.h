#ifndef MIB_MANAGER_H
#define MIB_MANAGER_H

#include "Includes.h"

#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QVector>
#include <QPair>

class MibManager: public QObject
{
    Q_OBJECT

public:
    MibManager(const QString & mibFileFullPath);
    virtual ~MibManager();

    QVector< struct tree *> & getMibObjects();

    QString getModuleName();
    int getModuleId();

    int loadMib();

    static QPair< QVector<unsigned long>, QVector<QString> > getLabeledOid(const struct tree *tp);
    static QString type2string(int control);
    static QString acess2string(int control);
    static QString status2string(int control);


signals:
    void nextObjectChanged();
public slots:


protected:
    void get_oid_report();
    void get_subtree_oid_report(struct tree *);


private:

    struct tree * _PtrTree;
    QFileInfo   * _MibFileInfo;
    int _ModId;
    QVector< struct tree *> _VecMibObjects;

};

#endif // MIB_MANAGER_H
