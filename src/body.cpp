////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2016/17      wulfihm, https://github.com/wulfihm/
///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "body.h"

static const float G = 6.67408e-11;	// gravitational constant
static float EPS = 4e1;

////////////////////////////////////////////////////////////////////////////////////////////////////
// user constructor
////////////////////////////////////////////////////////////////////////////////////////////////////
Body::Body(float m, vec3 p, vec3 v, bool im) : 
	mass(m), 
	position(p), 
	velocity(v),
	isMoveable(im)
{ }


////////////////////////////////////////////////////////////////////////////////////////////////////
// adds the force from body k as velocity to the body
////////////////////////////////////////////////////////////////////////////////////////////////////
void 
Body::bodyInteraction(Body &othBody) {
	vec3 dir = othBody.position - this->position;
	float dist = dir.x*dir.x + dir.y*dir.y + dir.z*dir.z;  // L^2-Norm without root ie. dot product
	this->velocity += dir * othBody.mass / sqrt(pow(dist + EPS*EPS,3));
}


////////////////////////////////////////////////////////////////////////////////////////////////////
// updates the position of the body in reference to the timespan dt and the gravitational constant
////////////////////////////////////////////////////////////////////////////////////////////////////
void
Body::updatePosition(float dt) {
	if(isMoveable) this->position += dt * this->velocity * G;
}