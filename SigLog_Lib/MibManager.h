#ifndef MIB_MANAGER_H
#define MIB_MANAGER_H

#include "Includes.h"

#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

class MibManager
{
public:
    MibManager(const char * mibFileName);
    ~MibManager();

    void print();
    void loadMib();
    void print_oid_report();

    static string type2string(int control);
    static string acess2string(int control);
    static string status2string(int control);

    bool isPrint_labeledoid;
    bool isPrint_oid;
    bool isPrint_symbolic;
    bool isPrint_mibchildoid;
    bool isPrint_suffix;
    bool isPrint_custom;

private:
    string print_parent_labeledoid(struct tree *, stringstream * ss =  new stringstream());
    string print_parent_oid(struct tree *, stringstream * ss =  new stringstream());
    string print_parent_mibchildoid(struct tree *, stringstream * ss =  new stringstream());
    string print_parent_label(struct tree *, stringstream * ss =  new stringstream());
    void print_subtree_oid_report(struct tree *, int);

    QFile         _OutFile;
    struct tree * _PtrTree;
    const char  * _MibFullPath;
    QFileInfo   * _MibFileInfo;
    QTextStream   _Fout;
    int _ModId;
};

#endif // MIB_MANAGER_H
