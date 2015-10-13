
//! \brief This is the include for the Barrier entity.
#include "Barrier.h"

//! \brief This is the the SDK base Threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;

//minimum value of barrier
int Barrier::VALUE_MIN      = 1;

//Constructor
Barrier::Barrier(int count) {

	SynchronizationService::Super(this);
	if(	count < Barrier::VALUE_MIN)
		this->count = Barrier::VALUE_MIN;
	else
		this->count = count;

	this->init();
}

//Destructor
Barrier::~Barrier(){

	this->destroy();
}

//Initialize barrier
void Barrier::init(){

	pthread_barrier_init(&this->barrier, NULL, this->count);
}

//Destoy barrier
void Barrier::destroy(){

	pthread_barrier_destroy(&this->barrier);
}

//Synchronize participating threads at the barrier
int Barrier::wait(){

	return pthread_barrier_wait( &this->barrier);
}
