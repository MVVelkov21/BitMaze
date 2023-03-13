#include "raylib.h"
#include "MainMenu.h"

void GameMainMenu() {
	while (!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("SUCCESS", 400, 225, 50, BLACK);
		EndDrawing();
	}
}