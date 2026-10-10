// Matthew Heltman 
// Oct 10 2026
//
// Header file for component structs 


#include "Components.h"


Controller controllerInit(void) {
	return (Controller) {
		.rightKey = KEY_D, 
		.leftKey = KEY_A, 
		.jumpKey = KEY_SPACE, 
		.pauseKey = KEY_P
	}; 

}
