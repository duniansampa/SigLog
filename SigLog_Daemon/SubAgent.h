#ifndef SUBAGENT_H
#define SUBAGENT_H

#include <Includes.h>


#define CLASS_NAME(n) #n
#define SHOW(a)  std::cout.precision(10); std::cout << #a << ": " << a << std::endl

double * ToDoubleVector(char * stringInteger, const char * delimiter, size_t * size);

const oid  VecTrapOid[] = {1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0};

typedef struct{


}OidType;

class AgentSubagentObject{

private:
    size_t    _SizeContent;
    u_char  _Type;
    Netsnmp_Node_Handler *_Handler;
    oid * _VecOid;
    size_t _SizeVecOid;
public:

    AgentSubagentObject(u_char type, size_t size){

         this->_Handler = NULL;
         this->_SizeContent = size;
         this->_SizeVecOid = 0;
         this->_VecOid = NULL;

        switch(type){

         case ASN_INTEGER:
            //INTEGER, INTEGER32
            //Cod: 0x02
            //signed 32-bit values.
            //snmpset -> i: INTEGER

            this->_Content.integer = new long[size];
            this->_Type = ASN_INTEGER;
            break;

        case  ASN_OCTET_STR:
           //ASN_OCTET_STR
           //Cod: 0x04
           //snmpset -> s: STRING

            this->_Content.string = new u_char[size];
            this->_Type = ASN_OCTET_STR;
            break;

        case ASN_OBJECT_ID:
            //OBJECT IDENTIFIER
            //Cod: 0x06
            //snmpset -> o: OBJID

            this->_Content.objid = new oid[size];
            this->_Type = ASN_OBJECT_ID;
            break;

        case ASN_IPADDRESS:
            //IPADDRESS
            //Cod: 0x40
            //snmpset -> a: IPADDRESS
#define CLASS_NAME(n) #n
#define SHOW(a)  std::cout.precision(10); std::cout << #a << ": " << a << std::endl
            this->_Content.string = new u_int8_t[size];
            this->_Type = ASN_IPADDRESS;
            break;

        case ASN_FLOAT:
            //Float
            //Cod: 0x48

            this->_Content.floatVal = new float[size];
            this->_Type = ASN_FLOAT;
            break;

        case ASN_DOUBLE:
            //Double
            //Cod: 0x49

            this->_Content.doubleVal = new double[size];
            this->_Type = ASN_DOUBLE;
            break;

        };
    }

   void setStringOid(char * stringOid){
       size_t size;
       double * vecDouble =  ToDoubleVector(stringOid, " ,.-", &size);
       this->_VecOid = new oid [size];
       this->_SizeVecOid = size;
       for(size_t i = 0; i < size; i++){
           this->_VecOid[i] = vecDouble[i];
       }

   }

   int setContent(char * stringContent, const char * delimiter = " "){
       size_t size;
       double * vecDouble;

       if( this->_Type != ASN_OCTET_STR){

           vecDouble = ToDoubleVector(stringContent, delimiter,  &size);

           if(size != this->_SizeContent)
               return -1;

            switch(this->_Type){

            case ASN_INTEGER:

                for(size_t i = 0; i < this->_SizeContent; i++)
                    this->_Content.integer[i] = (long)vecDouble[i];
                break;

            case ASN_IPADDRESS:

                for(size_t i = 0; i < this->_SizeContent; i++)
                    this->_Content.string[i] = (u_int8_t )vecDouble[i];
                break;

            case ASN_OBJECT_ID:

                for(size_t i = 0; i < this->_SizeContent; i++)
                    this->_Content.objid[i] = (oid) vecDouble[i];
                break;

            case ASN_FLOAT:

                for(size_t i = 0; i < this->_SizeContent; i++)
                    this->_Content.objid[i] = (float) vecDouble[i];
                break;

            case ASN_DOUBLE:

                for(size_t i = 0; i < this->_SizeContent; i++)
                    this->_Content.objid[i] = (float) vecDouble[i];
                break;

            }

       }else{

           size  = strlen(stringContent);

           if(size > this->_SizeContent)
               return -1;

           strcpy((char *) this->_Content.string, stringContent);

       }

       return 0;

   }


   //Return long vector representation of the string separated by delimiter
   double * ToDoubleVector(char * stringInteger, const char * delimiter, size_t * size){

      char * pch;
      double * vecDouble = NULL;
      char buffer[256];
      vector<double> vec;

      strcpy(buffer, stringInteger);

      pch = strtok(buffer, delimiter);
      while (pch != NULL)
      {
          vec.push_back(stod(pch));
          pch = strtok (NULL, delimiter);
      }

      if(size){
          *size = vec.size();
      }

      vecDouble = new double [vec.size()];

      for(size_t i = 0 ; i < vec.size(); i++)
          vecDouble[i] =  vec[i];

      return vecDouble;
   }

   size_t getSizeContent(){ return this->_SizeContent;}
   u_char getType(){ return this->_Type;}
   oid * getPtrVecOid(){return this->_VecOid;}
   size_t getSizeVecOid(){ return this->_SizeVecOid;}
   Netsnmp_Node_Handler * getHandler(){ return this->_Handler; }
   void setHandler(Netsnmp_Node_Handler * handler){this->_Handler = handler; }

   netsnmp_vardata _Content;
};

class SubAgent
{

private:

    // ASN_INTEGER, ASN_OCTET_STR, ASN_OBJECT_ID, ASN_IPADDRESS, ASN_FLOAT,ASN_DOUBLE
    AgentSubagentObject eldcomNumber;
    AgentSubagentObject eldcomName;
    AgentSubagentObject eldcomObjID;
    AgentSubagentObject eldcomIP;
    AgentSubagentObject eldcomFloat;
    AgentSubagentObject eldcomDouble;


protected:
    inline void registerObject(char * name, AgentSubagentObject * agentSubagentObject);

    static int netsnmpNodeHandler(netsnmp_mib_handler *handler,
                netsnmp_handler_registration *reginfo,
                netsnmp_agent_request_info *reqinfo,
                netsnmp_request_info *requests) ;
public:
    SubAgent();
    virtual ~SubAgent();

    void initObjects();

    void sendNotification(AgentSubagentObject * notificationTrap, AgentSubagentObject * agentSubagentObject);


};



#endif // SUBAGENT_H
