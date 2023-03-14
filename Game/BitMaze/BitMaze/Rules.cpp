#include "raylib.h"
#include "MainMenu.h"

void rules() {
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_ESCAPE)) {
			BeginDrawing();
			DrawText("Return", 30, 30, 30, RED);
			EndDrawing();
			for(int i = 0; i < 100000000; i++){}
			SetExitKey(KEY_ESCAPE);
			MainMenuGUI();
		}
		BeginDrawing();
		ClearBackground(WHITE);
		DrawRectangle(25, 25, 117, 35, BLACK);
		DrawText("Return", 30, 30, 30, WHITE);
		EndDrawing();
	}
}

