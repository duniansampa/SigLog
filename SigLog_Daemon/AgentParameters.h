#ifndef AGENTPARAMETERS_H
#define AGENTPARAMETERS_H

#include <Includes.h>

class AgentParameters
{
private:
    string  _XMLConfigurationFullPath;
    int 	_OperationMode;
    int     _PrintLogERROR;
    string  _SnmpdConfig;
    string  _SnmptrapdConfig;
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


    void setSnmpdConfig(string name);
    string getSnmpdConfig();
};

#endif // AGENTPARAMETERS_H
