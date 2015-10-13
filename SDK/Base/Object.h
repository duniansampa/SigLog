#ifndef OBJECT_H_
#define OBJECT_H_

/*!
 * \brief     Sample application.
 * \details   This application is used to show some doxygen tips.
 * \author    Dunian Coutinho Sampa
 * \version   1.0a
 * \date      2014-2014
 * \pre       Have a Linux and C/C++ environment configured.
 * \bug       No bug.
 * \warning   N/A
 * \copyright MECTRON LTDA.
 */

#include "../BaseIncludes.h"

//! Implementations for EDL_COM features.
namespace EDL_COM {

	//! Implementations for SDK features.
	namespace SDK {

		//! Implementations for base features.
		namespace Base {

			//! Implementations for Base operations.
			namespace Base {

				#define CLASS_NAME(n) #n
				#define SHOW(a)  std::cout.precision(10); std::cout << #a << ": " << a << std::endl

				typedef unsigned char byte;
				typedef long long  bigLong;

				//! A class to define Object operations.
				class Object {
				private:
					Object * ptrOfSubClass;
				protected:
					//Creates and returns a copy of this object.
					virtual Object clone();

					void Super(Object * subClass);

				public:

					Object();

					virtual ~Object();

					//Indicates whether some other object is "equal to" this one.
					virtual bool equals(const Object & obj);

					//Returns a string representation of the object.
					virtual string toString();

					//Returns the pointer of this Number.
					Object * getSubClass();

				};

				/*!
				 * \class Object
				 * \brief A class to perform object operations.
				 */
			}
		}
	}
}

#endif /* OBJECT_H_ */
