// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_GUI_IMAGE_H_INCLUDED__
#define __I_GUI_IMAGE_H_INCLUDED__

#include "IGUIElement.h"
#include "ITexture.h"

namespace engine
{
namespace gui
{

	//! GUI element displaying an image.
	class IGUIImage : public IGUIElement
	{
	public:

		//! constructor
		IGUIImage(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_IMAGE, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIImage() {};

		//! sets an image
		virtual void setImage(video::ITexture* image) = 0;

		//! sets if the image should use its alpha channel to draw itself
		virtual void setUseAlphaChannel(bool use) = 0;
	};


} // end namespace gui
} // end namespace engine

#endif

