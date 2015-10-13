#include "AgentParameters.h"

const int AgentParameters::SUCCESS        =  0;
const int AgentParameters::ERROR          = -1;

const int AgentParameters::_MASTER_AGENT_ = 0;
const int AgentParameters::_SUB_AGENT_    = 1;

const int AgentParameters::_STDERR_LOG_   = 0;
const int AgentParameters::_SYS_LOG_      = 1;


AgentParameters::AgentParameters(string  xmlConfigurationFullPath){
    this->_XMLConfigurationFullPath = xmlConfigurationFullPath;
    this->_OperationMode = AgentParameters::_SUB_AGENT_;
    this->_PrintLogERROR = AgentParameters::_STDERR_LOG_;
}
AgentParameters::~AgentParameters(){

}
int AgentParameters::LoadAgentParameters() {

    /*
    // Local variables
     Open a xml document
     TiXmlDocument xmlDoc(this->_XMLConfigurationFullPath.c_str());
     TiXmlElement * xmlRoot;
     string expression;




    // Load a xml file
    if (!(xmlDoc.LoadFile())) {
        //It was not possible to load SystemConfig.xml file.
        return AgentParameters::ERROR;
    }
    // Get the root element of the XML file
    xmlRoot = xmlDoc.RootElement();

    // The root is valid
    if (!(xmlRoot)){
        //It was not possible to get the root element of SystemConfig.xml.
        return AgentParameters::ERROR;
    }

    // Set XPath expression
    expression = "//agent/operationMode/@mode";



    string s  = S_xpath_string(xmlRoot, expression.c_str()).c_str();

    if( s == "_SUB_AGENT_"){
        this->_OperationMode = AgentParameters::_SUB_AGENT_;
        puts("The Operation Mode is \"_SUB_AGENT_\". ");
    }else{
        this->_OperationMode = AgentParameters::_MASTER_AGENT_;
        puts("The Operation Mode is \"_MASTER_AGENT_\". ");
    }

    // Set XPath expression
    //expression = "//agent/operationMode/@mode";


    */

    // Return the right collection
    return AgentParameters::SUCCESS;
}

void AgentParameters::setXMLConfigurationPath(string xmlConfigurationFullPath){
    this->_XMLConfigurationFullPath = xmlConfigurationFullPath;
}

string AgentParameters::getXMLConfigurationPath(){
    return this->_XMLConfigurationFullPath;
}

void AgentParameters::setOperationMode(int operationMode){
    this->_OperationMode = operationMode;
}

int AgentParameters::getOperationMode(){
    return this->_OperationMode;
}


int AgentParameters::getPrintLogERROR(){
    return this->_PrintLogERROR;
}
