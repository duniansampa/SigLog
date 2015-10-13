#ifndef SYNCHRONIZATION_SERVICE_H_
#define SYNCHRONIZATION_SERVICE_H_

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

#include "../Base/Object.h"

//! \brief This is the the SDK base base namespaces.
using namespace EDL_COM::SDK::Base::Base;

//! Implementations for EDL_COM features.
namespace EDL_COM {

	//! Implementations for SDK features.
	namespace SDK {

		//! Implementations for base features.
		namespace Base {

			//! Implementations for Threads operations.
			namespace Threads {

				//! A class to define SynchronizationService operations.
				class SynchronizationService: public Object {

				private:

					SynchronizationService * ptrOfSubClass;

				protected:

					void Super(SynchronizationService * subClass);

				public:

					//Constructor
					SynchronizationService();

					//Destructor
					virtual ~SynchronizationService();

					//Returns the pointer of this Synchronization.
					SynchronizationService * getSubClass();

					//Virtual method
					virtual void init()   = 0;

					//Virtual method
					virtual void destroy() = 0;
				};

				/*!
				 * \class SynchronizationService
				 * \brief A class to perform synchronizationService operations.
				 */
			}

		}

	}

}
#endif /* SYNCHRONIZATION_SERVICE_H_ */
