
#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

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

#include "SynchronizationService.h"

//! Implementations for EDL_COM features.
namespace EDL_COM {

	//! Implementations for SDK features.
	namespace SDK {

		//! Implementations for base features.
		namespace Base {

			//! Implementations for Threads operations.
			namespace Threads {

				//! A class to define Semaphore operations.
				class Semaphore: public SynchronizationService {

				private:

					sem_t semaphore;
					int   value;

				protected:

					//Initialize semaphore
					void init();

					//Destroy semaphore
					void destroy();

				public:

					//Success.
					static int SUCCESS;

					//maximum value of semaphore
					static int VALUE_MAX;

					//minimum value of semaphore
					static int VALUE_MIN;

					//default value of semaphore
					static int VALUE_DEFAULT;

					//Constructor
					Semaphore(int value = 1);

					//Destructor
					virtual ~Semaphore();

					//Wait on semaphore
					int wait();

					//Wait on semaphore, but don't block
					int tryWait();

					//Increment semaphore
					int post();
				};

				/*!
				 * \class Semaphore
				 * \brief A class to perform semaphore operations.
				 */
			}

		}

	}

}

#endif /* SEMAPHORE_H_ */
