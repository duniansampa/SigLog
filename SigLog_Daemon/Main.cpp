#include <QCoreApplication>


//#include "../SDK/BaseIncludes.h"

#include "Agent.h"


int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);

    Agent * agent = new Agent();

    agent->start();

    if(agent->isFinished()){
        cout<<"Error: Agent no started successfully. "<<endl;
    }else{
        cout<<"Agent started successfully. "<<endl;
    }

    agent->wait();


    return a.exec();
}
