// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_PARTICLE_AFFECTOR_H_INCLUDED__
#define __I_PARTICLE_AFFECTOR_H_INCLUDED__

#include "IUnknown.h"
#include "SParticle.h"

namespace engine
{
namespace scene
{

//! A particle affector modifies particles.
class IParticleAffector : public IUnknown
{
public:

	//! Affects an array of particles.
	//! \param now: Current time. (Same as ITimer::getTime() would return)
	//! \param particlearray: Array of particles.
	//! \param count: Amount of particles in array.
	virtual void affect(u32 now, SParticle* particlearray, u32 count) = 0;

};

} // end namespace scene
} // end namespace engine


#endif

