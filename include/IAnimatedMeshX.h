/*

  LTE Game Engine SDK:

   Copyright (C) 2006, SiberianSTAR <haxormail@gmail.com>

  Based on Irrlicht 1.0:
 
   Copyright (C) 2002-2006 Nikolaus Gebhardt

  For conditions of distribution and use, see copyright notice in
  engine.h
 
  http://www.ltestudios.com

*/

#ifndef __I_ANIMATED_MESH_X_H_INCLUDED__
#define __I_ANIMATED_MESH_X_H_INCLUDED__

#include "IAnimatedMesh.h"

namespace engine
{
namespace scene
{
	//! Interface for using some special functions of X meshes
	class IAnimatedMeshX : public IAnimatedMesh
	{
	public:

		//! Returns a pointer to a transformation matrix of a part of the 
		//! mesh based on a frame time. This is used for being able to attach
		//! objects to parts of animated meshes. For example a weapon to an animated 
		//! hand. 
		//! \param jointNumber: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshX::getJointCount()-1;
		//! \param frame: Frame of the animation.
		//! \return Returns a pointer to the matrix of the mesh part or 
		//! null if an error occured.
		virtual core::matrix4* getMatrixOfJoint(s32 jointNumber, s32 frame) = 0;
		
		//! Use custom bones
		//! \param lstBones: array of matrices to use as bones
		//! \param use: true: use custom bones	
		virtual void useCMeshBones(core::array<core::matrix4>* lstBones, bool use) = 0;
		
		//! Returns bones
		virtual void getBones(core::array<core::matrix4>* lstBones) = 0;

		//! Gets joint count.
		//! \return Returns amount of joints in the skeletal animated mesh.
		virtual s32 getJointCount() const = 0;

		//! Gets the name of a joint.
		//! \param number: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshX::getJointCount()-1;
		//! \return Returns name of joint and null if an error happened.
		virtual const c8* getJointName(s32 number) const = 0;

		//! Gets a joint number from its name
		//! \param name: Name of the joint.
		//! \return Returns the number of the joint or -1 if not found.
		virtual s32 getJointNumber(const c8* name) const = 0;

		//! Returns a pointer to list of points containing the skeleton.
		//! Draw a line between point 1 and 2, and 3 and 4 and 5 and 6
		//! and so on to visualize this. Only for debug purposes. If you
		//! use an .x-File with the IAnimatedMeshSceneNode and turn DebugDataVisible
		//! to true, the Scene node will visualize the skeleton using this
		//! method.
		virtual const core::array<core::vector3df>* getDrawableSkeleton(s32 frame) = 0;

		//! Returns amount of animations in .X-file.
		virtual s32 getAnimationCount() const = 0;

		//! Returns the name of an animation. 
		//! \param idx: Zero based Index of the animation. Must be a value between
		//! 0 and getAnimationCount()-1;
		//! \return Returns pointer to the string of the name of the animation. 
		//! Returns 0 if an animation with this index does not exist.
		virtual const c8* getAnimationName(s32 idx) const = 0;

		//! Sets an animation as animation to play back.
		//! \param idx: Zero based Index of the animation. Must be a value between
		//! 0 and getAnimationCount()-1;
		virtual void setCurrentAnimation(s32 idx) = 0;

		//! Sets an animation as animation to play back.
		//! \param name: Name of the animtion. 
		//! \return Returns true if successful, and false if the specified animation
		//! does not exist.
		virtual bool setCurrentAnimation(const c8* name) = 0;
	};

} // end namespace scene
} // end namespace engine

#endif


