/*

  LTE Game Engine SDK:

   Copyright (C) 2006, SiberianSTAR <haxormail@gmail.com>

  Based on Irrlicht 1.0:
 
   Copyright (C) 2002-2006 Nikolaus Gebhardt

  For conditions of distribution and use, see copyright notice in
  engine.h
 
  http://www.ltestudios.com

*/

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
			Stencilbuffer = false;
			Vsync = false;
			AntiAlias = false;
			EventReceiver = 0;
			WindowId = 0;
			SDK_version_do_not_use = engine_SDK_VERSION;
		}

		//! Type of the device. 
		/** This can currently be video::EDT_NULL, 
		video::EDT_SOFTWARE, video::EDT_DIRECT3D8, video::EDT_DIRECT3D9 and video::EDT_OPENGL. 
		Default: Software. */
		video::E_DRIVER_TYPE DriverType;

		//! Size of the window or the video mode in fullscreen mode. Default: 800x600
		core::dimension2d<s32> WindowSize;

		//! Bits per pixel in fullscreen mode. Ignored if windowed mode. Default: 16.
		u32 Bits;

		//! Should be set to true if the device should run in fullscreen. 
		/** Otherwise the device runs in windowed mode. Default: false.  */
		bool Fullscreen;

		//! Specifies if the stencil buffer should be enabled. 
		/** Set this to true,
	    if you want the engine be able to draw stencil buffer shadows. Note that not all
		devices are able to use the stencil buffer. If they don't no shadows will be drawn. 
		Default: false. */
		bool Stencilbuffer;

		//! Specifies vertical syncronisation.
		/** If set to true, the driver will wait for the vertical retrace period, otherwise not.
		Default: false */
		bool Vsync;

		//! Specifies if the device should use fullscreen anti aliasing
		/** Makes sharp/pixellated edges softer, but requires more performance. Also, 2D 
		elements might look blurier with this switched on. The resulting rendering quality 
		also depends on the hardware and driver you are using, your program might look
		different on different hardware with this. So if you are writing a 
		game/application with antiAlias switched on, it would be a good idea to make it
		possible to switch this option off again by the user.
		This is only supported in D3D9 and D3D8. In D3D9, both sample types are supported,
		D3DMULTISAMPLE_X_SAMPLES and D3DMULTISAMPLE_NONMASKABLE. Default value: false */
		bool AntiAlias;

		//! A user created event receiver.
		IEventReceiver* EventReceiver;

		//! Window Id.
		/** If this is set to a value other than 0, the engine Engine will be created in 
		an already existing window. For windows, set this to the HWND of the window you want.
		The windowSize and FullScreen options will be ignored when using the WindowId parameter.
		Default this is set to 0. 
		To make engine run inside the custom window, you still will have to draw engine
		on your own. You can use this loop, as usual:
		\code
		while (device->run())
		{
			driver->beginScene(true, true, 0);
			smgr->drawAll();
			driver->endScene();
		}
		\endcode
		Instead of this, you can also simply use your own message loop
		using GetMessage, DispatchMessage and whatever. Calling
		engineDevice::run() will cause engine to dispatch messages internally too. 
		You need not call Device->run() if you want to do your own message 
		dispatching loop, but engine will not be able to fetch
		user input then and you have to do it on your own using the window
		messages, DirectInput, or whatever. Also, you'll have to increment the engine timer.
		An alternative, own message dispatching loop without device->run() would
		look like this:
		\code
		MSG msg;
		while (true)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_QUIT)
					break;
			}

			// increase virtual timer time
			device->getTimer()->tick();

			// draw engine picture
			driver->beginScene(true, true, 0);
			smgr->drawAll();
			driver->endScene();
		}
		\endcode
		However, there is no need to draw the picture this often. Just do it how you like.
		*/
		s32 WindowId;

		//! Don't use or change this parameter. 
		/** Always set it to engine_SDK_VERSION, which is done by default.
		This is needed for sdk version checks. */
		const char* SDK_version_do_not_use;
	};


} // end namespace

#endif


