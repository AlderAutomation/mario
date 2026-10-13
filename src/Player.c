// Matthew Heltman 
// Oct 10 2026 
//
// Player Header file for data and related functions 


#include "Player.h"
#include "Components.h" 

ePlayer playerInit(int x, int y) {
	return (ePlayer) {
		.trans = {
			.position = {
				.x = x, 
				.y = y
			}, 
			.size = {66.0f, 92.0f}, 
			.scale = 1.0f
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
		.score = 0, 
		.isCollision = true
	};
}
