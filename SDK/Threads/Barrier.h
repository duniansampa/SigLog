#ifndef BARRIER_H_
#define BARRIER_H_

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

				//! A class to define Barrier operations.
				class Barrier: public SynchronizationService {

				private:

					pthread_barrier_t barrier;
					int count;

				protected:

					//Initialize barrier
					void init();

					//Destroy barrier
					void destroy();

				public:

					//minimum value of barrier
					static int VALUE_MIN;

					//Constructor
					Barrier(int count);

					//Destructor
					virtual ~Barrier();

					//Synchronize participating threads at the barrier
					int wait();
				};

				/*!
				 * \class Barrier
				 * \brief A class to perform barrier operations.
				 */
			}

		}

	}

}
#endif /* BARRIER_H_ */
