#include "raylib.h"
#include "MainMenu.h"

void settings() {
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_ESCAPE)) {
			BeginDrawing();
			DrawText("Return", 20, 20, 20, RED);
			EndDrawing();
			for (int i = 0; i < 100000000; i++) {}
			SetExitKey(KEY_ESCAPE);
			MainMenuGUI();
		}
		BeginDrawing();
		ClearBackground(WHITE);
		DrawRectangle(15, 15, 80, 25, BLACK);
		DrawText("Return", 20, 20, 20, WHITE);
		DrawText("SETTINGS", 288, 30, 50, BLACK);
		EndDrawing();
	}
}
