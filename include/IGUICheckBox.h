// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_GUI_CHECKBOX_H_INCLUDED__
#define __I_GUI_CHECKBOX_H_INCLUDED__

#include "IGUIElement.h"

namespace engine
{
namespace gui
{

	//! GUI Check box interface.
	class IGUICheckBox : public IGUIElement
	{
	public:

		//! constructor
		IGUICheckBox(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_CHECK_BOX, environment, parent, id, rectangle) {}

		//! destructor
		~IGUICheckBox() {};

		//! Set if box is checked.
		virtual void setChecked(bool checked) = 0;

		//! Returns true if box is checked.
		virtual bool isChecked() = 0;
	};

} // end namespace gui
} // end namespace engine

#endif

