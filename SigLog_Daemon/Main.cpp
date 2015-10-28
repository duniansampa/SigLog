#include <QCoreApplication>

#include <iostream>

using namespace std;

#include "../SDK/Base_Lib.h"
#include "../SDK/BaseIncludes.h"

#include "Agent.h"


int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);


    Barrier * mainBarrier = new Barrier(3);

    Agent agent(mainBarrier);

    if (agent.start() == Thread::SUCCESS){
       cout<<"Agent started successfully. "<<endl;
    }else{
        cout<<"Error: Agent no started successfully. "<<endl;
    }

    mainBarrier->wait();


    return a.exec();
}
