// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_Q3_LEVEL_MESH_H_INCLUDED__
#define __I_Q3_LEVEL_MESH_H_INCLUDED__

#include "IAnimatedMesh.h"

namespace engine
{
namespace scene
{

	//! Interface for a Mesh wich can be loaded directly from a Quake3 .bsp-file.
	/** The Mesh tries to load all textures of the map. There are currently 
	no additional methods in this class, but maybe there will be some in later
	releases if there are feature requests. */
	class IQ3LevelMesh : public IAnimatedMesh
	{
	public:

		//! destructor
		virtual ~IQ3LevelMesh() {};
	};

} // end namespace scene
} // end namespace engine

#endif

