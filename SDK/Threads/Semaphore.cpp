
//! \brief This is the include for the Semaphore entity.
#include "Semaphore.h"

//! \brief This is the the SDK base Threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;

//Success.
int Semaphore::SUCCESS           = 0;

//maximum value of semaphore
int Semaphore::VALUE_MAX         = SEM_VALUE_MAX;

//minimum value of semaphore
int Semaphore::VALUE_MIN         = 0;

//default value of semaphore
int Semaphore::VALUE_DEFAULT     = 1;

//Constructor
Semaphore::Semaphore(int value) {

	SynchronizationService::Super(this);

	if(this->value > Semaphore::VALUE_MAX || this->value < Semaphore::VALUE_MIN )
		this->value =  Semaphore::VALUE_DEFAULT;
	else
		this->value = value;

	this->init();

}

//Destructor
Semaphore::~Semaphore() {

	this->destroy();
}

//Initialize mutex
void Semaphore::init(){

	sem_init(&this->semaphore, 0, this->value);
}
//Destroy this mutex
void Semaphore::destroy(){

	sem_destroy(&this->semaphore);
}
//Wait on semaphore
int Semaphore::wait(){

	return sem_wait(&this->semaphore);
}

//Wait on semaphore, but don't block
int Semaphore::tryWait(){

	return sem_trywait(&this->semaphore);
}

//Increment semaphore
int Semaphore::post(){

	return sem_post(&this->semaphore);
}
