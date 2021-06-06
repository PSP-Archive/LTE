// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_OS_OPERATOR_H_INCLUDED__
#define __I_OS_OPERATOR_H_INCLUDED__

#include "IUnknown.h"

namespace engine
{

//! The Operating system operator provides operation system specific methods and informations.
/** Currently only 3 methods are supported. But it will be extended with more functionality
soon. */
class IOSOperator : public IUnknown
{
public:

	//! destructor
	virtual ~IOSOperator() {}

	//! returns the current operation system version as string.
	virtual const wchar_t* getOperationSystemVersion() = 0;

	//! copies text to the clipboard
	virtual void copyToClipboard(const c8* text) = 0;

	//! gets text from the clipboard
	//! \return Returns 0 if no string is in there.
	virtual c8* getTextFromClipboard() = 0;	
};

} // end namespace

#endif

