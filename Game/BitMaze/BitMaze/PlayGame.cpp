#include "raylib.h"
#include "MainMenu.h"

void levelButtons() {
	if (IsKeyPressed(KEY_ONE)) {
		SetExitKey(KEY_ONE);
		while (!WindowShouldClose()) {
			BeginDrawing();
			DrawText("LEVEL 1", 110, 205, 30, RED);
			EndDrawing();
		}
		SetExitKey(KEY_ESCAPE);
	}
	if (IsKeyPressed(KEY_FOUR)) {
		SetExitKey(KEY_FOUR);
		while (!WindowShouldClose()) {
			BeginDrawing();
			DrawText("LEVEL 4", 110, 380, 30, RED);
			EndDrawing();
		}
		SetExitKey(KEY_ESCAPE);
	}
	if (IsKeyPressed(KEY_TWO)) {
		SetExitKey(KEY_TWO);
		while (!WindowShouldClose()) {
			BeginDrawing();
			DrawText("LEVEL 2", 335, 205, 30, RED);
			EndDrawing();
		}
		SetExitKey(KEY_ESCAPE);
	}
	if (IsKeyPressed(KEY_FIVE)) {
		SetExitKey(KEY_FIVE);
		while (!WindowShouldClose()) {
			BeginDrawing();
			DrawText("LEVEL 5", 335, 380, 30, RED);
			EndDrawing();
		}
		SetExitKey(KEY_ESCAPE);
	}
	if (IsKeyPressed(KEY_THREE)) {
		SetExitKey(KEY_THREE);
		while (!WindowShouldClose()) {
			BeginDrawing();
			DrawText("LEVEL 3", 560, 205, 30, RED);
			EndDrawing();
		}
		SetExitKey(KEY_ESCAPE);
	}
	if (IsKeyPressed(KEY_SIX)) {
		SetExitKey(KEY_SIX);
		while (!WindowShouldClose()) {
			BeginDrawing();
			DrawText("RANDOM", 560, 380, 30, RED);
			EndDrawing();
		}
		SetExitKey(KEY_ESCAPE);
	}
}

void GameMainMenu() {
	while (!WindowShouldClose()){
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
		DrawText("LEVELS", 288, 30, 50, BLACK);
		DrawRectangle(70, 100, 200, 150, BLACK);
		DrawText("LEVEL 1", 110, 205, 30, WHITE);
		DrawRectangle(70, 275, 200, 150, BLACK);
		DrawText("LEVEL 4", 110, 380, 30, WHITE);
		DrawRectangle(295, 100, 200, 150, BLACK);
		DrawText("LEVEL 2", 335, 205, 30, WHITE);
		DrawRectangle(295, 275, 200, 150, BLACK);
		DrawText("LEVEL 5", 335, 380, 30, WHITE);
		DrawRectangle(520, 100, 200, 150, BLACK);
		DrawText("LEVEL 3", 560, 205, 30, WHITE);
		DrawRectangle(520, 275, 200, 150, BLACK);
		DrawText("RANDOM", 560, 380, 30, WHITE);
		levelButtons();
		EndDrawing();
	}
}