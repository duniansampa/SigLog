
//! \brief This is the include for the ConditionVariable entity.
#include "ConditionVariable.h"

//! \brief This is the the SDK base Threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;

//Success.
int ConditionVariable::SUCCESS  = 0;

//A kernel timeout unblocked the call.
int ConditionVariable::TIMEOUT_UNBLOCKED = ETIMEDOUT ;

//Constructor
ConditionVariable::ConditionVariable() {

	SynchronizationService::Super(this);
	this->init();
}

//Destructor
ConditionVariable::~ConditionVariable() {

	this->destroy();
}

//Initialize condition variable
void ConditionVariable::init(){

	pthread_cond_init(&this->condVariable, NULL);
}

//Destroy condition variable
void ConditionVariable::destroy(){

	pthread_cond_destroy(&this->condVariable);
}

//Causes current thread to wait until another thread invokes the notify() method or the notifyAll() method for this object.
int  ConditionVariable::ConditionVariable::wait(Mutex * mutex){

	return pthread_cond_wait(&this->condVariable, & mutex->mutex );
}

//Wait on this condition variable, with a time limit
int  ConditionVariable::wait(Mutex * mutex, long millis, int nanos){

    unsigned long long time = millis;
	time *= 1000000;
	time += nanos;
	struct timespec abs_timeout;
	abs_timeout.tv_sec   =  time / 1000000000;
	abs_timeout.tv_nsec  =  time % 1000000000;

	return pthread_cond_timedwait(&this->condVariable, &mutex->mutex , &abs_timeout);
}

//Wakes up a single thread that is waiting on this object's monitor.
int ConditionVariable::notify(){

	return pthread_cond_signal(&this->condVariable);
}

//Wakes up all threads that are waiting on this object's monitor.
int ConditionVariable::notifyAll(){

	return pthread_cond_broadcast(&this->condVariable);
}
