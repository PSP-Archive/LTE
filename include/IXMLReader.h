// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_XML_READER_H_INCLUDED__
#define __I_XML_READER_H_INCLUDED__

#include "IUnknown.h"
#include "engineXML.h"

namespace engine
{
namespace io
{
	//! A xml reader for wide characters, derived from IUnknown.
	//! This XML Parser can read any type of text files from any source where engine
	//! can read. Just call IFileSystem::createXMLReader(). 
	//! For more informations on how to use the parser, see IengineXMLReader
	typedef IengineXMLReader<wchar_t, IUnknown> IXMLReader;

	//! A xml reader for ASCII or UTF-8 characters, derived from IUnknown.
	//! This XML Parser can read any type of text files from any source where engine
	//! can read. Just call IFileSystem::createXMLReaderUTF8(). 
	//! For more informations on how to use the parser, see IengineXMLReader
	typedef IengineXMLReader<c8, IUnknown> IXMLReaderUTF8;

} // end namespace engine
} // end namespace io

#endif

