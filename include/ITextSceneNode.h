// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_TEXT_SCENE_NODE_H_INCLUDED__
#define __I_TEXT_SCENE_NODE_H_INCLUDED__

#include "ISceneNode.h"

namespace engine
{
namespace scene
{

//! A scene node for displaying 2d text at a position in three dimensional space
class ITextSceneNode : public ISceneNode
{
public:

	//! constructor
	ITextSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
		const core::vector3df& position = core::vector3df(0,0,0))
			: ISceneNode(parent, mgr, id, position) {}

	//! sets the text string
	virtual void setText(const wchar_t* text) = 0;

	//! sets the color of the text
	virtual void setTextColor(video::SColor color) = 0;
};

} // end namespace scene
} // end namespace engine


#endif

