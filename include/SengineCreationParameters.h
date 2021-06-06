// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_engine_CREATION_PARAMETERS_H_INCLUDED__
#define __I_engine_CREATION_PARAMETERS_H_INCLUDED__

namespace engine
{
	//! Structure for holding advanced engine Device creation parameters.
	/** This structure is only used in the createDeviceEx() function. */
	struct SengineCreationParameters
	{
		//! Constructs a SengineCreationParameters structure with default values.
		SengineCreationParameters()
		{
			DriverType = video::EDT_SOFTWARE;
			WindowSize = core::dimension2d<s32>(800, 600);
			Bits = 16;
			Fullscreen = false;
      showLogo = true;
			Stencilbuffer = false;
			Vsync = false;
			AntiAlias = false;
			EventReceiver = 0;
			WindowId = 0;
			SDK_version_do_not_use = engine_SDK_VERSION;
		}


		video::E_DRIVER_TYPE DriverType;

		core::dimension2d<s32> WindowSize;

		//! Bits per pixel in fullscreen mode. Ignored if windowed mode. Default: 16.
		u32 Bits;

		bool Fullscreen;


		bool Stencilbuffer;

		bool Vsync;

		bool AntiAlias;
    bool showLogo;

		IEventReceiver* EventReceiver;
		s32 WindowId;

		//! Don't use or change this parameter. 
		/** Always set it to engine_SDK_VERSION, which is done by default.
		This is needed for sdk version checks. */
		const char* SDK_version_do_not_use;
	};


} // end namespace

#endif

