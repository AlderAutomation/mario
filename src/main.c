// Matthew Heltmn 
// Oct 10 2026
//
// A mario style game to try to learn compostion better 

#include <math.h>

#include "raylib.h"

#include "Player.h" 

// Enums of scenes 
typedef enum {
	MENU, 
	GAMEPLAY, 
	PAUSE, 
	GAMEOVER, 
	OPTIONS
} Scene; 


int main() {

	InitWindow(1920, 1080, "Mario Bros Ripoff"); 

	ePlayer playerOne = playerInit(); 

	Scene currentScene = GAMEPLAY; 

	// 3 minute countdown timer 
	float countdownTimer = 3.0f; 

	while (!WindowShouldClose()) {

		switch (currentScene) { 
			case GAMEPLAY: 
				float dt = GetFrameTime(); 
	
				if (countdownTimer > 0.0f) {
					countdownTimer -= dt; 
				} else {
					countdownTimer = 0.0f; 
					currentScene = GAMEOVER; 
				}

				BeginDrawing(); 

				ClearBackground(BLACK); 
		
				DrawTexture(playerOne.playerTexture.texture , playerOne.trans.position.x, playerOne.trans.position.y, RED); 

				// drawScore 
				DrawText(TextFormat("Score: %d", playerOne.score), 10, 10, 24, GREEN); 

		 		// drawTimer 
				DrawText(TextFormat("%d", (int)ceil(countdownTimer)), GetScreenWidth()/2, 10, 24, GREEN); 

			break;

			case GAMEOVER: 
				BeginDrawing();

				ClearBackground(RED); 

				DrawText("You Died!", GetScreenWidth()/2, GetScreenHeight()/2, 96, GREEN); 
			break; 

		}

		

		EndDrawing(); 
	
	}


	return 0; 
}
