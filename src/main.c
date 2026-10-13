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

	Scene currentScene = MENU; 

	// 3 minute countdown timer 
//	float countdownTimer = 180.0f; 
	float countdownTimer = 3.0f; 

	while (!WindowShouldClose()) {

		BeginDrawing(); 

		switch (currentScene) { 
			case MENU: 
				ClearBackground(BLACK); 

				// Title 
				char title[10] = "Not Mario"; 
				int titleWidth = MeasureText(title, 128); 
				DrawText(title, GetScreenWidth()/2-titleWidth/2, 100, 128, GREEN); 

				// menu 
				char newGameText[9] = "NEW GAME"; 
				char optionsText[8] = "OPTIONS";
				int newGameTextWidth = MeasureText(newGameText, 48); 
				int optionsTextwidth = MeasureText(optionsText, 48); 
				DrawText(newGameText, GetScreenWidth()/2-newGameTextWidth/2, GetScreenHeight()/2-40, 48, GREEN); 
				DrawText(optionsText, GetScreenWidth()/2-optionsTextwidth/2, GetScreenHeight()/2+40, 48, GREEN); 

				// menu rect buttons for mouse detection 
				Rectangle newGameButton = {GetScreenWidth()/2-newGameTextWidth/2, GetScreenHeight()/2-40, newGameTextWidth, 48}; 
				Rectangle optionsButton = {GetScreenWidth()/2-optionsTextwidth/2, GetScreenHeight()/2+40, optionsTextwidth, 48}; 

				// get mouse pos 
				Vector2 mouse = GetMousePosition(); 

				// Check for mouse click on buttons 
				if (CheckCollisionPointRec(mouse, newGameButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					currentScene = GAMEPLAY; 
				}

				if (CheckCollisionPointRec(mouse, optionsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					currentScene = GAMEPLAY; // temp; TODO change to Options
				}

			break; 

			case GAMEPLAY: 
				ClearBackground(BLACK); 

				float dt = GetFrameTime(); 
	
				if (countdownTimer > 0.0f) {
					countdownTimer -= dt; 
				} else {
					countdownTimer = 0.0f; 
					currentScene = GAMEOVER; 
				}
		
				DrawTexture(playerOne.playerTexture.texture , playerOne.trans.position.x, playerOne.trans.position.y, RED); 

				// drawScore 
				DrawText(TextFormat("Score: %d", playerOne.score), 10, 10, 24, GREEN); 

		 		// drawTimer 
				DrawText(TextFormat("%d", (int)ceil(countdownTimer)), GetScreenWidth()/2, 10, 24, GREEN); 

				if (IsKeyPressed(playerOne.input.pauseKey)) {
					currentScene = PAUSE; 
				}

			break;

			case PAUSE: 
				ClearBackground(BLACK); 

				char pauseText[8] = "Paused"; 
				int pauseTextWidth = MeasureText(pauseText, 96); 
				DrawText(pauseText, GetScreenWidth()/2 - pauseTextWidth/2, GetScreenHeight()/2, 96, GREEN); 

				if (IsKeyPressed(playerOne.input.pauseKey)) {
					currentScene = GAMEPLAY; 
				}


			break; 

			case GAMEOVER: 
				ClearBackground(MAROON); 

				char youDiedText[11] = "YOU DIED!"; 
				char restartText[24] = "Press any key to retry"; 

				int youDiedTextWidth = MeasureText(youDiedText, 96); 
				int restartTextWidth = MeasureText(restartText, 48); 

				DrawText(youDiedText, GetScreenWidth()/2-youDiedTextWidth/2, GetScreenHeight()/2, 96, GREEN); 
				DrawText(restartText, GetScreenWidth()/2-restartTextWidth/2, GetScreenHeight()/2+100, 48, GREEN); 
			break; 

			case OPTIONS: 

			break; 

		}


		EndDrawing(); 
	
	}


	return 0; 
}
