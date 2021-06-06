// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the LTE 3D Engine
// (C) 2006 - LTE Studios - by SiberianSTAR
// LTE 3D Engine is based on Irrlicht 1.0
// For conditions of distribution and use, see copyright notice in engine.h

#ifndef __I_PARTICLE_EMITTER_H_INCLUDED__
#define __I_PARTICLE_EMITTER_H_INCLUDED__

#include "IUnknown.h"
#include "SParticle.h"

namespace engine
{
namespace scene
{

//! A particle emitter for using with particle systems.
/** A Particle emitter emitts new particles into a particle system.
*/
class IParticleEmitter : public IUnknown
{
public:

	//! destructor
	virtual ~IParticleEmitter() {};

	//! Prepares an array with new particles to emitt into the system
	//! and returns how much new particles there are.
	//! \param now: Current time.
	//! \param timeSinceLastCall: Time elapsed since last call, in milliseconds.
	//! \param outArray: Pointer which will point to the array with the new 
	//! particles to add into the system.
	//! \return Returns amount of new particles in the array. Can be 0.
	virtual s32 emitt(u32 now, u32 timeSinceLastCall, SParticle*& outArray) = 0;
};

} // end namespace scene
} // end namespace engine


#endif

