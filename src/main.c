// Matthew Heltmn 
// Oct 10 2026
//
// A mario style game to try to learn compostion better 


#include <raylib.h>

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


	while (!WindowShouldClose()) {

		BeginDrawing(); 

		ClearBackground(BLACK); 
		
		DrawTexture(playerOne.playerTexture.texture , playerOne.trans.position.x, playerOne.trans.position.y, RED); 

		// drawScore 
		DrawText(TextFormat("Score: %d", playerOne.score), 10, 10, 24, GREEN); 

	 	// drawTimer 
		DrawText("Time", GetScreenWidth()/2, 10, 24, GREEN); 

		EndDrawing(); 
	
	}


	return 0; 
}
