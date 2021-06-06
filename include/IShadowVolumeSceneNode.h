// Copyright (C) 2002-2003 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_SHADOW_VOLUME_SCENE_NODE_H_INCLUDED__
#define __I_SHADOW_VOLUME_SCENE_NODE_H_INCLUDED__

#include "ISceneNode.h"
#include "IMesh.h"

namespace engine
{
namespace scene
{

	//! Scene node for rendering a shadow volume into a stencil buffer.
	class IShadowVolumeSceneNode : public ISceneNode
	{
	public:

		//! constructor
		IShadowVolumeSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id)
			: ISceneNode(parent, mgr, id) {}

		//! sets the mesh from which the shadow volume should be generated.
		virtual void setMeshToRenderFrom(IMesh* mesh) = 0;
	};

} // end namespace scene
} // end namespace engine

#endif

