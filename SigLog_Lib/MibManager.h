#ifndef MIB_MANAGER_H
#define MIB_MANAGER_H

#include "Includes.h"

#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

class MibTreeModel;

class MibManager
{
public:
    MibManager(const char * mibFileFullPath, bool isPrintToFile);
    ~MibManager();

    void print();
    int loadMib();
    void print_oid_report();

    static string type2string(int control);
    static string acess2string(int control);
    static string status2string(int control);

    void printToFunction();

    void setFunction(MibTreeModel * mibTreeModel, void  (MibTreeModel:: * ptrFunc)(const QString & moduleName, const struct tree * pt, QString & oid));

    bool isPrint_labeledoid;
    bool isPrint_oid;
    bool isPrint_symbolic;
    bool isPrint_mibchildoid;
    bool isPrint_suffix;
    bool isPrint_custom;
    bool isPrint_function;

protected:
    string print_parent_labeledoid(struct tree *, stringstream * ss =  new stringstream());
    string print_parent_oid(struct tree *, stringstream * ss =  new stringstream());
    string print_parent_mibchildoid(struct tree *, stringstream * ss =  new stringstream());
    string print_parent_label(struct tree *, stringstream * ss =  new stringstream());
    void print_subtree_oid_report(struct tree *, int);

private:
    QFile       * _OutFile;
    struct tree * _PtrTree;
    QFileInfo   * _MibFileInfo;
    QTextStream   _Fout;
    int _ModId;
    MibTreeModel * _PrtMibTreeModel;
    void  (MibTreeModel:: * _PtrMibFunction)(const QString &, const struct tree *, QString & oid);

    ;
};

#endif // MIB_MANAGER_H
