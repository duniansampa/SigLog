#ifndef AGENTPARAMETERS_H
#define AGENTPARAMETERS_H



// TinyXML and TinyXPath Includes
//#include "../SDK/External_Tiny_Lib/tinyxml.h"		// TinyXML
//#include "../SDK/External_Tiny_Lib/tinystr.h"		// TinyXML
//#include "../SDK/External_Tiny_Lib/xpath_static.h"	// TinyXPath

// SMC - SDK Includes
#include "../SDK/Base_Lib.h"

// TinyXPath - Namespace
//using namespace TinyXPath;  // TinyXML objects


class AgentParameters
{
private:
    string  _XMLConfigurationFullPath;
    int 	_OperationMode;
    int     _PrintLogERROR;
protected:

public:
    static const int SUCCESS;
    static const int ERROR;

    static const int _MASTER_AGENT_;
    static const int _SUB_AGENT_;
    static const int _STDERR_LOG_;
    static const int _SYS_LOG_;


    AgentParameters(string xmlConfigurationFullPath = "");
    virtual ~AgentParameters();

    int LoadAgentParameters();

    void setXMLConfigurationPath(string xmlConfigurationFullPath);

    string getXMLConfigurationPath();

    void setOperationMode(int operationMode);

    int getOperationMode();

    int getPrintLogERROR();
};

#endif // AGENTPARAMETERS_H
