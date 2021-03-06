/*

  LTE Game Engine SDK:

   Copyright (C) 2006, SiberianSTAR <haxormail@gmail.com>

  Based on Irrlicht 1.0:
 
   Copyright (C) 2002-2006 Nikolaus Gebhardt

  For conditions of distribution and use, see copyright notice in
  engine.h
 
  http://www.ltestudios.com

*/

#ifndef __I_SCENE_PARAMETERS_H_INCLUDED__
#define __I_SCENE_PARAMETERS_H_INCLUDED__

/*! \file SceneParameters.h
    \brief Header file containing all scene parameters for modifying mesh loading etc.
    
    This file includes all parameter names which can be set using ISceneManager::getParameters()
	to modify the behaviour of plugins and mesh loaders.
*/

namespace engine
{
namespace scene
{
	//! Name of the parameter for changing the texture path of the built-in csm loader.
	/** Use it like this:
	 \code
	 SceneManager->getParameters()->setParameter(
	    scene::CSM_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const char* const CSM_TEXTURE_PATH = "CSM_TexturePath";

	//! Name of the parameter for changing the texture path of the built-in lmts loader.
	/** Use it like this:
	 \code
	 SceneManager->getParameters()->setParameter(
	   scene::LMTS_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const char* const LMTS_TEXTURE_PATH = "LMTS_TexturePath";

	//! Name of the parameter for changing the texture path of the built-in my3d loader.
	/** Use it like this:
	 \code
	 SceneManager->getParameters()->setParameter(
	   scene::MY3D_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const char* const MY3D_TEXTURE_PATH = "MY3D_TexturePath";

	//! Name of the parameter specifying the COLLADA mesh loading mode
	/**
	Specifies if the COLLADA loader should create instances of the models, lights and
	cameras when loading COLLADA meshes. By default, this is set to false. If this is
	set to true, the ISceneManager::getMesh() method will only return a pointer to a
	dummy mesh and create instances of all meshes and lights and cameras in the collada
	file by itself. Example:
	\code
	 SceneManager->getParameters()->setParameter(
	   scene::COLLADA_CREATE_SCENE_INSTANCES, true);
	\endcode
	*/
	const char* const COLLADA_CREATE_SCENE_INSTANCES = "COLLADA_CreateSceneInstances";

	//! Name of the parameter for changing the texture path of the built-in DMF loader.
	/** Use it like this:
	 \code
	 SceneManager->getStringParameters()->setParameter(
	   scene::DMF_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const char* const DMF_TEXTURE_PATH = "DMF_TexturePath";
	
	//! Name of the parameter for preserving DMF textures dir structure with built-in DMF loader.
	/** Use it like this:
	 \code
	 //this way you won't use this setting
	 SceneManager->getParameters()->setParameter(
	   scene::DMF_USE_MATERIALS_DIRS, false); 
	 \endcode
	 \code
     //this way you'll use this setting
     SceneManager->getParameters()->setParameter(
	   scene::DMF_USE_MATERIALS_DIRS, true); 
	\endcode
	**/ 
	const char* const DMF_USE_MATERIALS_DIRS = "DMF_MaterialsDir";

	//! Name of the parameter for setting reference value of alpha in transparent materials.
	/** Use it like this:
	 \code
	 //this way you'll set alpha ref to 0.1
     SceneManager->getParameters()->setParameter(
	   scene::DMF_ALPHA_CHANNEL_REF, 0.1); 
	\endcode
	**/ 
	const char* const DMF_ALPHA_CHANNEL_REF = "DMF_AlphaRef";
	
	//! Name of the parameter for choose to flip or not tga files.
	/** Use it like this:
	 \code
	 //this way you'll choose to flip alpha textures
     SceneManager->()->setParameter(
	   scene::DMF_FLIP_ALPHA_TEXTURES, true); 
	\endcode
	**/ 
	const char* const DMF_FLIP_ALPHA_TEXTURES = "DMF_FlipAlpha";

} // end namespace scene
} // end namespace engine

#endif


