// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __S_KEY_MAP_H_INCLUDED__
#define __S_KEY_MAP_H_INCLUDED__

#include "Keycodes.h"

namespace engine
{

	//! enumeration for key actions. Used for example in the FPS Camera.
	enum EKEY_ACTION
	{
		EKA_MOVE_FORWARD = 0,
		EKA_MOVE_BACKWARD,
		EKA_STRAFE_LEFT,
		EKA_STRAFE_RIGHT,
		EKA_COUNT,

		//! This value is not used. It only forces this enumeration to compile in 32 bit. 
		EKA_FORCE_32BIT = 0x7fffffff	
	};

	//! Struct storing which key belongs to which action.
	struct SKeyMap
	{
		EKEY_ACTION Action;
		EKEY_CODE KeyCode;
	};

} // end namespace

#endif

