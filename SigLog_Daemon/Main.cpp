#include <QCoreApplication>


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

    QObject::connect(agent, SIGNAL(finished()), &a , SLOT(quit()));

    agent->wait();


    return a.exec();
}
