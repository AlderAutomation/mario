// Matthew Heltman 
// Oct 10 2026
//
// Player file for data and related functions 

#ifndef PLAYER_H 
#define PLAYER_H 

#include "Components.h" 

typedef struct {
	EntTransform trans; 
	Movement movement; 
	Controller controller;  

} Player; 

Player playerInit(void); 

#endif 
