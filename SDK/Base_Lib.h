#ifndef Base_Lib_H_
#define Base_Lib_H_

/*!
 * \mainpage  EDL_COM - System Development Kit (SDK) v1.0.0
 *
 * \section intro_sec Introduction
 *
 * This is the official EDL_COM SDK. Developed to provide a powerful set of features to a huge range of critical projects.
 *
 * \section hist_sec History
 *
 * 2014-2014 All rights reserved to  MECTRON.
 */

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


//Base
#include  "Base/Object.h"
#include  "Base/String.h"

//! \brief This is the the SDK base Base namespaces.
using namespace EDL_COM::SDK::Base::Base;

//Thread
#include  "Threads/Barrier.h"
#include  "Threads/ConditionVariable.h"
#include  "Threads/Mutex.h"
#include  "Threads/Semaphore.h"
#include  "Threads/SynchronizationService.h"
#include  "Threads/Synchronized.h"
#include  "Threads/Thread.h"

//! \brief This is the the SDK base threads namespaces.
using namespace EDL_COM::SDK::Base::Threads;


//#include "TimerTimeOuts/TimerTimeOut.h"
//#include "TimerTimeOuts/TimerTimeOutThread.h"

//! \brief This is the the SDK base timerTimeOuts namespaces.
//using namespace EDL_COM::SDK::Base::TimerTimeOuts;

#endif // Base_Lib_H_
