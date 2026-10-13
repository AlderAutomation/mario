// Matthew Heltman 
// Oct 13 2026
//
// entity for ground and platform placement

#ifndef PLATFORM_H
#define PLATFORM_H

#include "Components.h"

typedef  struct {
	cEntTransform trans; 
	cTexture platformTexture; 
	cCollision isCollision; 

} ePlatform;  

ePlatform  platformInit(int x, int y); 

#endif
