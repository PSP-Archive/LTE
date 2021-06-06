// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_SURFACE_LOADER_H_INCLUDED__
#define __I_SURFACE_LOADER_H_INCLUDED__

#include "IUnknown.h"
#include "IReadFile.h"
#include "IImage.h"

namespace engine
{
namespace video
{

//!	Class which is able to create a image from a file.
/** If you want the engine Engine be able to load textures of 
currently unsupported file formats (e.g .gif), then implement
this and add your new Surface loader with 
IVideoDriver::addExternalImageLoader() to the engine. */
class IImageLoader : public IUnknown
{
public:

	//! destructor
	virtual ~IImageLoader() {};

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".tga")
	virtual bool isALoadableFileExtension(const c8* fileName) = 0;

	//! returns true if the file maybe is able to be loaded by this class
	virtual bool isALoadableFileFormat(engine::io::IReadFile* file) = 0;

	//! creates a surface from the file
	virtual IImage* loadImage(engine::io::IReadFile* file) = 0;
};


} // end namespace video
} // end namespace engine

#endif

