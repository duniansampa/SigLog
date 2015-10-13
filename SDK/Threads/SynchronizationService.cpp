
//! \brief This is the include for the SynchronizationService entity.
#include "SynchronizationService.h"

//! \brief This is the the SDK base Threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;

void SynchronizationService::Super(SynchronizationService * subClass){
	Object::Super(this);
	this->ptrOfSubClass = subClass;
}

SynchronizationService::SynchronizationService() {
	// TODO Auto-generated constructor stub
	ptrOfSubClass = NULL;
}

SynchronizationService::~SynchronizationService() {
	// TODO Auto-generated destructor stub
}
SynchronizationService * SynchronizationService::getSubClass(){
	return this->ptrOfSubClass;
}
