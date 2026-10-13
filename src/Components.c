// Matthew Heltman 
// Oct 10 2026
//
// Header file for component structs 


#include "Components.h"
#include "raylib.h"

cInput inputInit(void) {
	return (cInput) {
		.rightKey = KEY_D, 
		.leftKey = KEY_A, 
		.jumpKey = KEY_SPACE, 
		.pauseKey = KEY_P
	}; 

}
