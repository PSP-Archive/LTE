// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_DUMMY_TRANSFORMATION_SCENE_NODE_H_INCLUDED__
#define __I_DUMMY_TRANSFORMATION_SCENE_NODE_H_INCLUDED__

#include "ISceneNode.h"

namespace engine
{
namespace scene
{

//! Dummy scene node for adding additional transformations to the scene graph.
/** This scene node does not render itself, and does not respond to set/getPosition,
set/getRotation and set/getScale. Its just a simple scene node that takes a 
matrix as relative transformation, making it possible to insert any transformation
anywhere into the scene graph.
This scene node is for example used by the IAnimatedMeshSceneNode for emulating
joint scene nodes when playing skeletal animations.
*/
class IDummyTransformationSceneNode : public ISceneNode
{
public:

	//! constructor
	IDummyTransformationSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id)
		: ISceneNode(parent, mgr, id) {}

    //! Returns a reference to the current relative transformation matrix.
	//! This is the matrix, this scene node uses instead of scale, translation
	//! and rotation.
	virtual core::matrix4& getRelativeTransformationMatrix() = 0;
};

} // end namespace scene
} // end namespace engine


#endif
