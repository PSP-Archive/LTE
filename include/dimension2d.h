// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __engine_DIMENSION2D_H_INCLUDED__
#define __engine_DIMENSION2D_H_INCLUDED__

#include "engineTypes.h"

namespace engine
{
namespace core
{

	//! Specifies a 2 dimensional size.
	template <class T>
	class dimension2d
	{
		public:

			dimension2d()
				: Width(0), Height(0) {};

			dimension2d(T width, T height)
				: Width(width), Height(height) {};

			dimension2d(const dimension2d<T>& other)
				: Width(other.Width), Height(other.Height) {};


			bool operator == (const dimension2d<T>& other) const
			{
				return Width == other.Width && Height == other.Height;
			}


			bool operator != (const dimension2d<T>& other) const
			{
				return Width != other.Width || Height != other.Height;
			}

			const dimension2d<T>& operator=(const dimension2d<T>& other) 
			{
				Width = other.Width;
				Height = other.Height;
				return *this;
			}

			T Width, Height;
	};

} // end namespace core
} // end namespace engine

#endif

