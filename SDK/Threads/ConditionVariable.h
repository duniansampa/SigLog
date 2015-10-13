#ifndef CONDITIONVARIABLE_H_
#define CONDITIONVARIABLE_H_

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
#include "Mutex.h"

//! Implementations for EDL_COM features.
namespace EDL_COM {

	//! Implementations for SDK features.
	namespace SDK {

		//! Implementations for base features.
		namespace Base {

			//! Implementations for Threads operations.
			namespace Threads {

				//! A class to define ConditionVariable operations.
				class ConditionVariable: public SynchronizationService {

				private:

					pthread_cond_t condVariable;

				protected:

					//Initialize condition variable
					void init();

					//Destroy condition variable
					void destroy();

				public:

					//Success.
					static int SUCCESS;

					//A kernel timeout unblocked the call.
					static int TIMEOUT_UNBLOCKED;

					//Constructor
					ConditionVariable();

					//Destructor
					virtual ~ConditionVariable();

					//Causes current thread to wait until another thread invokes the notify() method or the notifyAll() method for this object.
					int wait(Mutex * mutex);

					//Wait on this condition variable, with a time limit
					int wait(Mutex * mutex, long millis, int nanos = 0);

					//Wakes up a single thread that is waiting on this object's monitor.
					int notify();

					//Wakes up all threads that are waiting on this object's monitor.
					int notifyAll();
				};

				/*!
				 * \class ConditionVariable
				 * \brief A class to perform conditionVariable operations.
				 */
			}

		}

	}
}

#endif /* CONDITIONVARIABLE_H_ */
