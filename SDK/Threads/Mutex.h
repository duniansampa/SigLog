#ifndef MUTEX_H_
#define MUTEX_H_


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

				//! A class to define Mutex operations.
				class Mutex: public SynchronizationService {

				private:

					pthread_mutex_t mutex;

				protected:

					//Initialize mutex
					void init();

					//Destroy this mutex
					void destroy();

				public:

					//Success.
					static int SUCCESS;

					//A kernel timeout unblocked the call.
					static int TIMEOUT_UNBLOCKED;

					//Constructor
					Mutex();

					//Destuctor
					virtual ~Mutex();

					//Lock mutex
					int lock();

					//Attempt to lock mutex
					int tryLock();

					//Attempt to lock mutex
					int timedLock(long millis, int nanos = 0);

					//Unlock mutex
					int unlock();

					//Friend class
					friend class ConditionVariable;
				};

				/*!
				 * \class Mutex
				 * \brief A class to perform mutex operations.
				 */
			}

		}

	}

}


#endif /* MUTEX_H_ */
