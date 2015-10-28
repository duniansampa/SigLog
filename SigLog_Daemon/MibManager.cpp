#include "MibManager.h"

MibManager::MibManager()
{

    _File.setFileName("mibOutS.txt");

    _File.open(QIODevice::WriteOnly | QIODevice::Text);

    _Out.setDevice(&_File);

/*
    add_mibdir("/usr/share/snmp/mibs/");
    init_mib_internals();
    read_all_mibs();

    cout<<"Number of files: " << numberFiles << endl;
*/

}

/* Busca em profundidade */

void MibManager::dfs(struct tree * mytree, QString tab, int prof){

    if(!mytree){
        return;
    }


    //cout  << mytree->label << endl;
    //

    _Out << tab << mytree->label <<" : "<< prof << endl;
    //tab.append("\t");

    dfs(mytree->child_list, tab + "\t", prof + 1);

    dfs(mytree->next_peer, tab, prof);

}

/* Busca em largura */


void MibManager::print(){
   //print_mib(FILE *fp);

    oid anOID[MAX_OID_LEN];
    size_t anOID_len=MAX_OID_LEN;

    //read_objid(".1.3.6.1.2.1.1",anOID,&anOID_len);

    //print_objid(anOID, anOID_len);

    //print_description(anOID, anOID_len, 1000);

    //struct tree *netsnmp_read_module(const char *name);
    //struct tree *read_mib(const char *filename);
    //struct tree *read_all_mibs(void);

    //add_mibdir("/usr/share/snmp/mibs/");

    //netsnmp_init_mib();
    //read_all_mibs();
    //snmp_set_mib_warnings(2);
    //struct tree *tr = netsnmp_read_module("CISCO-RHINO-MIB");
    //add_mibdir(".");
    struct tree *tr = read_mib("NET-SNMP-EXAMPLES-MIB.txt");
    //struct tree *tr = read_mib("AGENTX-MIB.txt");

    //
    // while(tr){
    //    printf("Obj: %s\n",tr->label);
    //   tr = tr->next_peer;
    // }


     dfs(tr, "", 0);
     _File.close();
}

struct treeAxx {
    struct tree    *child_list;     /* list of children of this node */
    struct tree    *next_peer;      /* Next node in list of peers */
    struct tree    *next;   /* Next node in hashed list of names */
    struct tree    *parent;
    char           *label;  /* This node's textual name */
    u_long          subid;  /* This node's integer subidentifier */
    int             modid;  /* The module containing this node */
    int             number_modules;
    int            *module_list;    /* To handle multiple modules */
    int             tc_index;       /* index into tclist (-1 if NA) */
    int             type;   /* This node's object type */
    int             access; /* This nodes access */
    int             status; /* This nodes status */
    struct enum_list *enums;        /* (optional) list of enumerated integers */
    struct range_list *ranges;
    struct index_list *indexes;
    char           *augments;
    struct varbind_list *varbinds;
    char           *hint;
    char           *units;
    int             (*printomat) (u_char **, size_t *, size_t *, int,
                                  const netsnmp_variable_list *,
                                  const struct enum_list *, const char *,
                                  const char *);
    void            (*printer) (char *, const netsnmp_variable_list *, const struct enum_list *, const char *, const char *);   /* Value printing function */
    char           *description;    /* description (a quoted string) */
    char           *reference;    /* references (a quoted string) */
    int             reported;       /* 1=report started in print_subtree... */
    char           *defaultValue;
   char	       *parseErrorString; /* Contains the error string if there are errors in parsing MIBs */
};
