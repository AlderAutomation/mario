// Matthew Heltmn 
// Oct 10 2026
//
// A mario style game to try to learn compostion better 

#include <math.h>

#include "raylib.h"

#include "Player.h" 
#include "Platform.h"

// Enums of scenes 
typedef enum {
	MENU, 
	GAMEPLAY, 
	PAUSE, 
	GAMEOVER, 
	OPTIONS
} Scene; 

bool isLeft = false; 

int main() {

	InitWindow(1920, 1080, "Mario Bros Ripoff"); 

	SetTargetFPS(30); 

	ePlayer playerOne = playerInit(100, GetScreenHeight()-200); 

	ePlatform platforms[(int)ceil((GetScreenWidth()+140)/70.0)]; 
	
	int platformCount = sizeof(platforms) / sizeof(platforms[0]); 

	for (int i = 0 ; i < platformCount ; i ++) {
		ePlatform ground = platformInit(i*70, GetScreenHeight()-70); 
		platforms[i] = ground; 
	}
	
	Scene currentScene = MENU; 

	// 3 minute countdown timer 
	float countdownTimer = 180.0f; 
//	float countdownTimer = 3.0f; 

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
//				char optionsText[8] = "OPTIONS";
				int newGameTextWidth = MeasureText(newGameText, 48); 
//				int optionsTextwidth = MeasureText(optionsText, 48); 
				DrawText(newGameText, GetScreenWidth()/2-newGameTextWidth/2, GetScreenHeight()/2-40, 48, GREEN); 
//				DrawText(optionsText, GetScreenWidth()/2-optionsTextwidth/2, GetScreenHeight()/2+40, 48, GREEN); 

				// menu rect buttons for mouse detection 
				Rectangle newGameButton = {GetScreenWidth()/2-newGameTextWidth/2, GetScreenHeight()/2-40, newGameTextWidth, 48}; 
//				Rectangle optionsButton = {GetScreenWidth()/2-optionsTextwidth/2, GetScreenHeight()/2+40, optionsTextwidth, 48}; 

				// get mouse pos 
				Vector2 mouse = GetMousePosition(); 

				// Check for mouse click on buttons 
				if (CheckCollisionPointRec(mouse, newGameButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					currentScene = GAMEPLAY; 
				}

//				if (CheckCollisionPointRec(mouse, optionsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//					currentScene = GAMEPLAY; // temp; TODO change to Options
//				}

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
		

				// drawScore 
				DrawText(TextFormat("Score: %d", playerOne.score), 10, 10, 24, GREEN); 

		 		// drawTimer 
				DrawText(TextFormat("%d", (int)ceil(countdownTimer)), GetScreenWidth()/2, 10, 24, GREEN); 

				// remove this and the boolean. move the draw into the actual controls and the the ghost is only visible while moving
				if (!isLeft) {
					DrawTextureRec(playerOne.playerTexture.texture, 
							(Rectangle){0, 0, playerOne.playerTexture.width, playerOne.playerTexture.height},
							(Vector2){playerOne.trans.position.x, playerOne.trans.position.y}, 
							RED);
				} else {
					DrawTextureRec(playerOne.playerTexture.texture, 
							(Rectangle){0, 0, -playerOne.playerTexture.width, playerOne.playerTexture.height},
							(Vector2){playerOne.trans.position.x, playerOne.trans.position.y}, 
							RED);
				}

				if (IsKeyPressed(playerOne.input.pauseKey)) {
					currentScene = PAUSE; 
				}

				if (IsKeyDown(playerOne.input.leftKey) && playerOne.trans.position.x > 0) {
					isLeft = true; 

					playerOne.trans.position.x -= playerOne.movement.speed; 
				}

				if (IsKeyDown(playerOne.input.rightKey) && playerOne.trans.position.x < GetScreenWidth()-playerOne.playerTexture.width) {
 					isLeft = false; 

					playerOne.trans.position.x += playerOne.movement.speed; 
				}

				for (int i = 0 ; i < platformCount ; i++ ) {
					DrawTexture(platforms[i].platformTexture.texture , platforms[i].trans.position.x, platforms[i].trans.position.y, WHITE); 
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
