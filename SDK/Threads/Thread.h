
#ifndef THREAD_H_
#define THREAD_H_

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

//! \brief This is the EDL_COM SDK base base namespaces.
using namespace EDL_COM::SDK::Base::Base;

#include "Mutex.h"

//! Implementations for MECTRON features.
namespace EDL_COM {

	//! Implementations for SDK features.
	namespace SDK {

		//! Implementations for base features.
		namespace Base {

			//! Implementations for Threads operations.
			namespace Threads {

				//! A class to define Thread operations.
				class Thread;

                class PointerParameters{
                public:
                    PointerParameters(){
                        _PThread = NULL;
                        _PInt = NULL;
                    };
                    Thread * _PThread;
                    pthread_t    * _PInt;
                };
                class Thread: public Object{

				private:
                    pthread_t       id;
					string          name;
					pthread_attr_t  attribute;
					Thread *        ptrOfSubClass;
					static 		    map<pthread_t, Thread *> mapPtrSubClassRun;
					static void *   execute(void *);
					static Mutex *  prtMutex;

					//This method is called to execute the Thead
					virtual void run() = 0;
					void erase(int id);
				protected:
					void Super(Thread * subClass);
				public:
					static int RROBIN_ALG;
					static int FIFO_ALG;
                    //static int SPORADIC_ALG;
					static int CREATE_DETACHED;
					static int CREATE_JOINABLE;
					static int PRIORITY_MAX;
					static int PRIORITY_MIN;
					static int STACK_SIZE_DEFAULT;
                    static int SUCCESS;

					virtual ~Thread();

					//Returns the number of active threads in the current process.
					static int activeCount();

					//Returns a reference to the currently executing thread object.
					static Thread *	currentThread();

					//Detach a thread from a process
					void detach();

					//Get thread detach state
					int getDetachState();

					//Get thread scheduling policy
					int getSchedulingPolicy();

					//Returns the identifier of this Thread.
					pthread_t getId();

					// Returns this thread's name.
					string	getName();

					//Returns this thread's priority.
					int getPriority();

					//get the stack size
					size_t getStackSize();

					// Returns the state of this thread.
					int getState();

					//Waits for this thread to die.
					void join();

					//Waits at most millis milliseconds plus nanos nanoseconds for this thread to die.
					void join(long millis, int nanos = 0);

					//Set thread detach state attribute
					void setDetachState(int detachstate );

					//Changes the name of this thread to be equal to the argument name.
					void setName(const string & name);

					// Changes the priority of this thread.
					void setPriority(int newPriority);

					//set thread scheduling policy
					void setSchedulingPolicy(int policy);

					//Causes the currently executing thread to sleep (cease execution) for the specified number of milliseconds plus the specified number of nanoseconds.
					static void	sleep(long millis, int nanos = 0);

					//set the stack size
					void setStackSize(size_t stacksize);

					//Causes this thread to begin execution;  The run method is called of this thread to execute.
                    int start();

					//Returns a string representation of this thread, including the thread's name, priority, and thread group.
					string	toString();

					//Causes the currently executing thread object to temporarily pause and allow other threads to execute.
					static void	yield();

				};
				/*!
				 * \class Thread
				 * \brief A class to perform thread operations.
				 */
			}

		}

	}

}


#endif /* THREAD_H_ */
