// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_GUI_FILE_OPEN_DIALOG_H_INCLUDED__
#define __I_GUI_FILE_OPEN_DIALOG_H_INCLUDED__

#include "IGUIElement.h"

namespace engine
{
namespace gui
{

	//! Standard file chooser dialog.
	class IGUIFileOpenDialog : public IGUIElement
	{
	public:

		//! constructor
		IGUIFileOpenDialog(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_FILE_OPEN_DIALOG, environment, parent, id, rectangle) {}

		//! destructor
		virtual ~IGUIFileOpenDialog() {};

		//! Returns the filename of the selected file. Returns NULL, if no file was selected.
		virtual const wchar_t* getFilename() = 0;

	};


} // end namespace gui
} // end namespace engine

#endif

