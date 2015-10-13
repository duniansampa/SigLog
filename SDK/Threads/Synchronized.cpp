
//! \brief This is the include for the Synchronized entity.
#include "Synchronized.h"

//! \brief This is the the SDK base Threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;

//Success.
int Synchronized::SUCCESS  = 0;

//A kernel timeout unblocked the call.
int Synchronized::TIMEOUT_UNBLOCKED = ETIMEDOUT ;

//Constructor
Synchronized::Synchronized() {

	SynchronizationService::Super(this);
	this->init();
}

//Destructor
Synchronized::~Synchronized() {

	this->destroy();
}

//Initialize this Object
void Synchronized::init(){

	pthread_cond_init(&this->condVariable, NULL);
	pthread_mutex_init(&this->mutex, NULL);
}

//Destroy this Object
void Synchronized::destroy(){

	pthread_cond_destroy(&this->condVariable);
	pthread_mutex_destroy(&this->mutex);
}

//Causes current thread to wait until another thread invokes the notify() method or the notifyAll() method for this object.
int  Synchronized::wait(){

	return pthread_cond_wait(&this->condVariable, &this->mutex );
}

//Wait on this condition variable, with a time limit
int  Synchronized::wait(long millis, int nanos){

    unsigned long long time = millis;
	time *= 1000000;
	time += nanos;
	struct timespec abs_timeout;
	abs_timeout.tv_sec   =  time / 1000000000;
	abs_timeout.tv_nsec  =  time % 1000000000;

	return pthread_cond_timedwait(&this->condVariable, &this->mutex , &abs_timeout);
}

//Wakes up a single thread that is waiting on this object's monitor.
int Synchronized::notify(){

	return pthread_cond_signal(&this->condVariable);
}

//Wakes up all threads that are waiting on this object's monitor.
int Synchronized::notifyAll(){

	return pthread_cond_broadcast(&this->condVariable);
}

//Attempt to lock mutex
int Synchronized::synchronized(){
	return  pthread_mutex_lock( &this->mutex );
}

//Unlock mutex
int Synchronized::unsynchronized(){
	return pthread_mutex_unlock( &this->mutex );
}

