// Matthew Heltman 
// Oct 10 2026
//
// Header file for component structs 


#ifndef COMPONENTS_H 
#define COMPONENTS_H 

#include "raylib.h"

typedef struct {
	Vector2 position; 
	Vector2 size; 
	Vector2 scale; 
} cEntTransform; 

typedef struct {
	Vector2 velocity; 
	float speed; 
} cMovement; 

typedef struct {
	int rightKey; 
	int leftKey; 
	int jumpKey; 
	int pauseKey; 
} cInput; 

typedef struct {
	int score; 
} cScore; 

typedef struct {
	Texture2D texture; 
} cTexture;

cInput inputInit(void); 

#endif 

