// Matthew Heltmn 
// Oct 10 2026
//
// A mario style game to try to learn compostion better 


#include <raylib.h>
#include <stdio.h>

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

	Player playerOne = playerInit(); 


	while (!WindowShouldClose()) {

		BeginDrawing(); 

		ClearBackground(SKYBLUE); 
		
		EndDrawing(); 
	
	}


	return 0; 
}
