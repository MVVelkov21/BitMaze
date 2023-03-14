#include "raylib.h"
#include "MainMenu.h"

void GameMainMenu() {
	while (!WindowShouldClose()){
		if (IsKeyPressed(KEY_ESCAPE)) {
			SetExitKey(KEY_ESCAPE);
			MainMenuGUI();
		}
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("LEVELS", 288, 30, 50, BLACK);
		EndDrawing();
	}
}