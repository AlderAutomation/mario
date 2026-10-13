// Matthew Heltman 
// Oct 13 2026
//
// entity for ground and platform placement

#include "raylib.h"
#include "Platform.h"

ePlatform platformInit(int x, int y) {
	return (ePlatform) {
		.trans = {
			.position = {
				.x = x, 
				.y = y
			}, 
			.size = {70.0f, 70.0f}, 
			.scale = 1.0f 
		}, 
		.isCollision = true, 
		.platformTexture = {
			.texture = LoadTexture("./assets/Art/Tiles/grass.png"), 
			.width = 70.0f, 
			.height = 70.0f
		}
	};
}
