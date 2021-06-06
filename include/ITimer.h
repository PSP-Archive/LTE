// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_TIMER_H_INCLUDED__
#define __I_TIMER_H_INCLUDED__

#include "IUnknown.h"

namespace engine
{

//! Interface for getting and manipulating the virtual time
class ITimer : public IUnknown
{
public:

	//! destructor
	virtual ~ITimer() {}

	//! Returns current real time in milliseconds of the system. 
	/** This value does not start with 0 when the application starts.
	For example in one implementation the value returned could be the 
	amount of milliseconds which have elapsed since the system was started. */
	virtual u32 getRealTime() = 0;

	//! Returns current virtual time in milliseconds. 
	/** This value starts with 0 and can be manipulated using setTime(), stopTimer(),
	startTimer(), etc. This value depends on the set speed of the timer if the timer 
	is stopped, etc. If you need the system time, use getRealTime() */
	virtual u32 getTime() = 0;

	//! sets current virtual time
	virtual void setTime(u32 time) = 0;

	//! Stops the virtual timer. 
	/** The timer is reference counted, which means everything which calls 
	stop() will also have to call start(), otherwise the timer may not start/stop
	corretly again. */
	virtual void stop() = 0;

	//! Starts the virtual timer.
	/** The timer is reference counted, which means everything which calls 
	stop() will also have to call start(), otherwise the timer may not start/stop
	corretly again. */
	virtual void start() = 0;

	//! Sets the speed of the timer
	/** The speed is the factor with which the time is running faster or slower then the
	real system time. */
	virtual void setSpeed(f32 speed = 1.0f) = 0;

	//! Returns current speed of the timer
	/** The speed is the factor with which the time is running faster or slower then the
	real system time. */
	virtual f32 getSpeed() = 0;

	//! Returns if the virtual timer is currently stopped
	virtual bool isStopped() = 0;

	//! Advances the virtual time
	/** Makes the virtual timer update the time value based on the real time. This is
	called automaticly when calling engineDevice::run(), but you can call it manually
	if you don't use this method. */
	virtual void tick() = 0;
};

} // end namespace

#endif
