
//! \brief This is the include for the Thread entity.
#include "Thread.h"

//! \brief This is the the SDK base Threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;


map<pthread_t, Thread *> Thread::mapPtrSubClassRun   =  map<pthread_t, Thread *>();
Mutex *   Thread::prtMutex                           =  new Mutex();

int Thread::RROBIN_ALG         = SCHED_RR;
int Thread::FIFO_ALG           = SCHED_FIFO;
//int Thread::SPORADIC_ALG       = SCHED_SPORADIC;
int Thread::CREATE_DETACHED    = PTHREAD_CREATE_DETACHED;
int Thread::CREATE_JOINABLE    = PTHREAD_CREATE_JOINABLE;
int Thread::STACK_SIZE_DEFAULT = PTHREAD_STACK_MIN;
int Thread::PRIORITY_MAX       = 63;
int Thread::PRIORITY_MIN       = 1;
int Thread::SUCCESS            = 0;

Thread::~Thread(){
	prtMutex->lock();
	Thread::mapPtrSubClassRun.erase(this->id);
	prtMutex->unlock();

    this->ptrOfSubClass = NULL;
    if(this->id != ULONG_MAX)
    	pthread_cancel(this->id );
    this->id = ULONG_MAX;

}

void * Thread::execute(void * ptr){

	Thread::sleep( 0, 100);

	PointerParameters *  pointerParameters  = (PointerParameters *) ptr;
	Thread  *  ptrOfSubClass =   pointerParameters->_PThread;
    pthread_t * prtId =  pointerParameters->_PInt;
	ptrOfSubClass->run();

	prtMutex->lock();
	Thread::mapPtrSubClassRun.erase(* prtId);
	prtMutex->unlock();

    *prtId = ULONG_MAX;

	return NULL;
}

void Thread::Super(Thread * ptrOfSubClass){

	this->ptrOfSubClass = ptrOfSubClass;

    id = ULONG_MAX;
	name = "";
	pthread_attr_init(&this->attribute);
}

//Returns the number of active threads in the current process.
int Thread::activeCount(){
	prtMutex->lock();

	return Thread::mapPtrSubClassRun.size();

	prtMutex->unlock();
}

//Returns a reference to the currently executing thread object.
Thread  * Thread::currentThread(){

	pthread_t id = pthread_self();

	Thread  * t = NULL;

	prtMutex->lock();

	map<pthread_t, Thread *>::iterator it = Thread::mapPtrSubClassRun.find(id);
	if(it != Thread::mapPtrSubClassRun.end())
		t = it->second;

	prtMutex->unlock();

	return t;


}

//Detach a thread from a process
void Thread::detach(){
    if(this->id != ULONG_MAX)
		pthread_detach(this->id);
}

//Get thread detach state
int Thread::getDetachState(){
	int detachstate;
	pthread_attr_getdetachstate(&this->attribute, &detachstate);
	return detachstate;
}

//Get thread scheduling policy
int Thread::getSchedulingPolicy(){
	int policy;
	pthread_attr_getschedpolicy(&this->attribute,  &policy );
	return policy;
}

//Returns the identifier of this Thread.
pthread_t Thread::getId(){
	return this->id;
}

// Returns this thread's name.
string	Thread::getName(){
	return this->name;
}

//Returns this thread's priority.
int Thread::getPriority(){

	sched_param schedParameters;
	// Set the priority to the thread attribute
	pthread_attr_getschedparam(&this->attribute, &schedParameters);

	return schedParameters.sched_priority;
}

// Returns the state of this thread.
int Thread::getState(){
    //return STATE_RUNNING;
    return 1;
}

//get the stack size
size_t Thread::getStackSize(){
	size_t  stacksize;
	pthread_attr_getstacksize( &this->attribute, &stacksize);
	return stacksize;
}

//Waits for this thread to die.
void Thread::join(){
    if(this->id != ULONG_MAX)
		pthread_join(this->id, NULL);
}

//Waits at most millis milliseconds plus nanos nanoseconds for this thread to die.
void Thread::join(long millis, int nanos){

    if(this->id != ULONG_MAX){
        //unsigned long long time = millis;
        //time *= 1000000;
        //time += nanos;
        //struct timespec abstime;
        //abstime.tv_sec   =  time / 1000000000;
        //abstime.tv_nsec  =  time % 1000000000;
        //pthread_timedjoin( this->id, NULL, &abstime);
        pthread_join( this->id, NULL);
	}
}

//Set thread detach state
void Thread::setDetachState(int detachstate){
    if(this->id == ULONG_MAX)
		pthread_attr_getdetachstate(&this->attribute, &detachstate);
}

//Changes the name of this thread to be equal to the argument name.
void Thread::setName(const string & name){
	// Set the thread name
    if(this->id == ULONG_MAX){
		this->name = name;
	}
}

// Changes the priority of this thread.
void Thread::setPriority(int newPriority){

    if(this->id == ULONG_MAX){
		sched_param schedParameters;
		//Set the priority
		schedParameters.sched_priority = newPriority;
        //schedParameters.sched_ss_low_priority = newPriority - 1;

		//Set the priority to the thread attribute
		pthread_attr_setschedparam(&this->attribute, &schedParameters);
	}
}

//Set the thread scheduling policy attribute
void Thread::setSchedulingPolicy(int policy){

    if(this->id == ULONG_MAX){

		//Enable the "threadAttribute" to define the sched
		pthread_attr_setinheritsched(&this->attribute, PTHREAD_EXPLICIT_SCHED);

		//Set the scheduler policy
		pthread_attr_setschedpolicy(&this->attribute, policy);
	}
}

//Causes the currently executing thread to sleep (cease execution) for the specified number of milliseconds plus the specified number of nanoseconds.
void Thread::sleep(long millis, int nanos){
    unsigned long long timeout = millis;
    //timeout *=  1000000;
    //timeout += nanos;
    //TimerTimeout( CLOCK_REALTIME,  _NTO_TIMEOUT_NANOSLEEP, NULL , &timeout, NULL );
    usleep(timeout*1000);
}

//set the stack size
void Thread::setStackSize(size_t stacksize){
    if(this->id == ULONG_MAX){
		pthread_attr_setstacksize(&this->attribute, stacksize);
	}
}

//Causes this thread to begin execution;  The run method is called of this thread to execute.
int Thread::start(){

    if(this->id == ULONG_MAX){

		PointerParameters *  pointerParameters  = new PointerParameters();
		pointerParameters->_PThread = this->ptrOfSubClass;
		pointerParameters->_PInt = &this->id;

        if( (0 == pthread_create(&this->id , &this->attribute,  &Thread::execute, pointerParameters)) ){
            pthread_setname_np(this->id, this->name.c_str());

            prtMutex->lock();
            Thread::mapPtrSubClassRun[this->id] = this->ptrOfSubClass;

            prtMutex->unlock();

            return Thread::SUCCESS;
        }
        return !(Thread::SUCCESS);
	}
    return !(Thread::SUCCESS);
}

//Returns a string representation of this thread, including the thread's name, Id, priority.
string	Thread::toString(){

    stringstream s;

    s<<" Name: "<<this->name<<".";
    s<<" Id: "<<this->id<<".";
    s<<" Priority: "<<this->getPriority()<<".";

	return  s.str();
}

//Causes the currently executing thread object to temporarily pause and allow other threads to execute.
void Thread::yield(){
	 sched_yield();
}
