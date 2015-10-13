
//! \brief This is the include for the Mutex entity.
#include "Mutex.h"

//! \brief This is the the SDK base Threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;

//Success.
int Mutex::SUCCESS = 0;

//A kernel timeout unblocked the call.
int Mutex::TIMEOUT_UNBLOCKED = ETIMEDOUT;

//Constructor
Mutex::Mutex() {

	SynchronizationService::Super(this);

	this->init();
}

//Destuctor
Mutex::~Mutex() {

	this->destroy();
}

//Initialize mutex
void Mutex::init(){

	pthread_mutex_init(&this->mutex, NULL);
}

//Destroy this mutex
void Mutex::destroy(){

	pthread_mutex_destroy(&this->mutex);
}

//Lock mutex
int Mutex::lock(){

    return  pthread_mutex_lock( &this->mutex );
}

//Attempt to lock mutex
int Mutex::tryLock(){

	return pthread_mutex_trylock( &this->mutex );
}

//Attempt to lock mutex
int Mutex::timedLock(long millis, int nanos){

    unsigned long long time = millis;
	time *= 1000000;
	time += nanos;
	struct timespec abs_timeout;
	abs_timeout.tv_sec   =  time / 1000000000;
	abs_timeout.tv_nsec  =  time % 1000000000;

	return pthread_mutex_timedlock( &this->mutex, &abs_timeout );
}

//Unlock mutex
int Mutex::unlock(){

	return pthread_mutex_unlock( &this->mutex );
}
