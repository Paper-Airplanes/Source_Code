/********************************************************************************
* ReactPhysics3D physics library, http://www.reactphysics3d.com                 *
* Copyright (c) 2010-2016 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/

#ifndef CONCAVE_MESH_H
#define CONCAVE_MESH_H

// Libraries
#include "openglframework.h"
#include "reactphysics3d.h"
#include "PhysicsObject.h"

// Class ConcaveMesh
class ConcaveMesh : public PhysicsObject {

private:

	// -------------------- Attributes -------------------- //

	/// Previous transform (for interpolation)
	rp3d::Transform mPreviousTransform;

	/// Collision shape
	rp3d::ConcaveMeshShape* mConcaveShape;
	rp3d::ProxyShape* mProxyShape;

	/// Scaling matrix
	openglframework::Matrix4 mScalingMatrix;

	/// Structure with pointer to the shared mesh data (vertices, indices, ...)
	rp3d::TriangleMesh mPhysicsTriangleMesh;

	// -------------------- Methods -------------------- //


public:

	// -------------------- Methods -------------------- //

	/// Constructor
	ConcaveMesh(rp3d::CollisionWorld* world, const std::string& meshPath);

	/// Constructor
	ConcaveMesh(float mass, rp3d::DynamicsWorld* dynamicsWorld, const std::string& meshPath);

	/// Destructor
	~ConcaveMesh();

	/// Update the transform matrix of the object
	virtual void updateTransform(float interpolationFactor) override;
};

// Update the transform matrix of the object
inline void ConcaveMesh::updateTransform(float interpolationFactor) {
	mTransformMatrix = computeTransform(interpolationFactor, mScalingMatrix);
}

#endif