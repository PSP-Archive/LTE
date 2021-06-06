// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __E_DRIVER_TYPES_H_INCLUDED__
#define __E_DRIVER_TYPES_H_INCLUDED__

namespace engine
{
namespace video  
{
	//! Unused
	enum E_DRIVER_TYPE
	{
		EDT_NULL,     
		EDT_SOFTWARE, 
		EDT_SOFTWARE2,
		EDT_DIRECT3D8, 
		EDT_DIRECT3D9,
		EDT_OPENGL    
	};

} // end namespace video
} // end namespace engine


#endif

