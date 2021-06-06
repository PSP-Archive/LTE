/* engine.h -- interface of the 'LTE 3D Engine'

  LTE 3D Engine is
   Copyright (C) 2006 LTE Studios, SiberianSTAR

  Based on Irrlicht 1.0 

  Irrlicht is
   Copyright (C) 2002-2006 Nikolaus Gebhardt

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial purposes. Please read license.txt included in the 
  SDK archive.

*/

#ifndef __engine_H_INCLUDED__
#define __engine_H_INCLUDED__

#include "engineCompileConfig.h"
#include "aabbox3d.h"
#include "engineArray.h"
#include "SColor.h"
#include "SLight.h"
#include "dimension2d.h"
#include "EDriverTypes.h"
#include "heapsort.h"
#include "IAnimatedMesh.h"
#include "IAnimatedMeshMD2.h"
#include "IAnimatedMeshMS3D.h"
#include "IAnimatedMeshX.h"
#include "IAnimatedMeshSceneNode.h"
#include "ICameraSceneNode.h"
#include "IDummyTransformationSceneNode.h"
#include "IEventReceiver.h"
#include "IFileList.h"
#include "IFileSystem.h"
#include "IGUIButton.h"
#include "IGUICheckBox.h"
#include "IGUIContextMenu.h"
#include "IGUIComboBox.h"
#include "IGUIElement.h"
#include "IGUIEditBox.h"
#include "IGUIEnvironment.h"
#include "IGUIFileOpenDialog.h"
#include "IGUIFont.h"
#include "IGUIImage.h"
#include "IGUIInOutFader.h"
#include "IGUIListBox.h"
#include "IGUIMeshViewer.h"
#include "IGUIScrollBar.h"
#include "IGUISkin.h"
#include "IGUIStaticText.h"
#include "IGUITabControl.h"
#include "IGUIWindow.h"
#include "IGUIToolbar.h"
#include "ILightSceneNode.h"
#include "ILogger.h"
#include "IMesh.h"
#include "IMeshBuffer.h"
#include "IMeshManipulator.h"
#include "IMetaTriangleSelector.h"
#include "IReadFile.h"
#include "engineDevice.h"
#include "engineMath.h"
#include "engineString.h"
#include "ISceneManager.h"
#include "ISceneNode.h"
#include "IStringParameters.h"
#include "ITriangleSelector.h"
#include "ISceneNodeAnimator.h"
#include "ISceneCollisionManager.h"
#include "IMaterialRenderer.h"
#include "ISceneNodeAnimatorCollisionResponse.h"
#include "IShaderConstantSetCallBack.h"
#include "IParticleSystemSceneNode.h"
#include "ITerrainSceneNode.h"
#include "ITextSceneNode.h"
#include "IParticleEmitter.h"
#include "IParticleAffector.h"
#include "IBillboardSceneNode.h"
#include "ITexture.h"
#include "IUnknown.h"
#include "IVideoDriver.h"
#include "IVideoModeList.h"
#include "IWriteFile.h"
#include "IXMLReader.h"
#include "IXMLWriter.h"
#include "Keycodes.h"
#include "line2d.h"
#include "line3d.h"
#include "engineList.h"
#include "matrix4.h"
#include "plane3d.h"
#include "plane3d.h"
#include "vector2d.h"
#include "vector3d.h"
#include "triangle3d.h"
#include "position2d.h"
#include "quaternion.h"
#include "rect.h"
#include "S3DVertex.h"
#include "SAnimatedMesh.h"
#include "SKeyMap.h"
#include "SMaterial.h"
#include "SMesh.h"
#include "SMeshBuffer.h"
#include "SMeshBufferLightMap.h"
#include "SMeshBufferTangents.h"
#include "engineTypes.h"
#include "IAudioDriver.h"

//! engine SDK Version
#define engine_SDK_VERSION "1.0"

#include <wchar.h>
#include "SengineCreationParameters.h"

//! Everything in the LTE 3D Engine can be found in this namespace.
namespace engine
{
	//! Creates an engine device. The engine device is the root object for using the engine.
	/**
	\param receiver: A user created event receiver.
	\param showLogo: true if you want to show the logo when the game starts.
   If you don't show the logo the engine will run only for 10minutes, useful for debugging.
	\return Returns pointer to the created engineDevice or null if the 
	device could not be created.
	*/
	engineDevice*  createDevice(
		IEventReceiver* receiver = 0, bool showLogo = true);

	//! unused
	 engineDevice*  createDeviceEx(
		const SengineCreationParameters& parameters);


	// THE FOLLOWING IS AN EMPTY LIST OF ALL SUB NAMESPACES
	// EXISTING ONLY FOR THE DOCUMENTATION SOFTWARE DOXYGEN.

	//! In this namespace can be found basic classes like vectors, planes, arrays, lists and so on.
	namespace core
	{
	}

	//! The gui namespace contains useful classes for easy creation of a graphical user interface.
	namespace gui
	{
	}

	//! This namespace provides interfaces for input/output: Reading and writing files, accessing zip archives, xml files, ...
	namespace io
	{
	}

	//! All scene management can be found in this namespace: Mesh loading, special scene nodes like octrees and billboards, ...
	namespace scene
	{
	}

	//! The video namespace contains classes for accessing the video driver. All 2d and 3d rendering is done here.
	namespace video
	{
	}
  //! The audio namespace contains classes for accessing the audio driver. All audio playing is done here. 
  namespace audio
  {
  }
}

/*! \file engine.h
    \brief Main header file of the engine, the only file needed to include.
*/

#endif

