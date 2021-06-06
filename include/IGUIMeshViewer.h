// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_GUI_MESH_VIEWER_H_INCLUDED__
#define __I_GUI_MESH_VIEWER_H_INCLUDED__

#include "IGUIElement.h"

namespace engine
{

namespace video
{
	struct SMaterial;
}

namespace scene
{
	class IAnimatedMesh;
}

namespace gui
{

	//! 3d mesh viewing GUI element.
	class IGUIMeshViewer : public IGUIElement
	{
	public:

		//! constructor
		IGUIMeshViewer(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_MESH_VIEWER, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIMeshViewer() {};

		//! sets the mesh to be shown
		virtual void setMesh(scene::IAnimatedMesh* mesh) = 0;

		//! sets the material
		virtual void setMaterial(const video::SMaterial& material) = 0;

		//! gets the material
		virtual const video::SMaterial& getMaterial() = 0;

	};


} // end namespace gui
} // end namespace engine

#endif

