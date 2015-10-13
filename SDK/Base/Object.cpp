
//! \brief This is the include for the Object entity.
#include "Object.h"

//! \brief This is the the SDK base Base namespaces.
using namespace EDL_COM::SDK::Base::Base;

Object::Object(){
	ptrOfSubClass = NULL;
}

Object::~Object(){

}
void Object::Super(Object * subClass){
	this->ptrOfSubClass = subClass;
}


//Creates and returns a copy of this object.
Object Object::clone(){
	return *this;
}

// Returns a string representation of the object.
string Object::toString(){
	return "Object";
}

//Indicates whether some other object is "equal to" this one.
bool Object::equals(const Object & obj){
	if(this->ptrOfSubClass == obj.ptrOfSubClass)
		return true;
	return false;
}
//Returns the pointer of this Object.
Object * Object::getSubClass(){
	return this->ptrOfSubClass;
}
