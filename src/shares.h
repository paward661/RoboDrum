/** @file shares.h
 *  This file contains extern declarations of shares and queues which are used
 *  in more than one file of the project.
 * 
 *  @author Patrick Ward
 *  @date   2021-Nov-30 Original file 
 */
#ifndef _SHARES_H_
#define _SHARES_H_
#include "taskqueue.h"
#include "taskshare.h"
/// A share which holds boolean value for if the program should continue to record data
extern Share<bool> listening;
/// A queue which holds a bunch of data taken by a measurement task
extern Queue<uint32_t> strike_timeB;
/// A queue which holds a bunch of data taken by a measurement task
extern Queue<uint32_t> strike_timeS;
#endif // _SHARES_H_