// Matthew Heltman 
// Oct 10 2026
//
// Player file for data and related functions 

#ifndef PLAYER_H 
#define PLAYER_H 

#include "Components.h" 

typedef struct {
	cEntTransform trans; 
	cMovement movement; 
	cInput input;  
	cTexture playerTexture; 
	cScore score; 
	cCollision isCollision; 
} ePlayer; 

ePlayer playerInit(int x, int y); 

#endif 
