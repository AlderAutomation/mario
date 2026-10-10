// Matthew Heltman 
// Oct 10 2026
//
// Header file for component structs 


#ifndef COMPONENTS_H 
#define COMPONENTS_H 

#include <raylib.h> 

typedef struct {
	Vector2 position; 
	Vector2 size; 
} EntTransform; 

typedef struct {
	Vector2 velocity; 
	float speed; 
} Movement; 

typedef struct {
	int rightKey; 
	int leftKey; 
	int jumpKey; 
	int pauseKey; 
} Controller; 

Controller controllerInit(void); 

#endif 

