// Matthew Heltman 
// Oct 10 2026 
//
// Player Header file for data and related functions 


#include "Player.h"
#include "Components.h" 

ePlayer playerInit(void) {
	return (ePlayer) {
		.trans = {
			.position = {100.0f, 100.0f}, 
			.size = {16.0f, 16.0f}
		}, 
		.movement = {
			.velocity = {0.0f, 0.0f}, 
			.speed = 20.0f
		}, 
		.input = inputInit(), 
		.playerTexture = {
			.texture = LoadTexture("./assets/Art/Player/p1_stand.png"), 
			.width = 66, 
			.height = 92
		},
		.score = 0 
	};
}
