#include "raylib.h"
#include "PlayGame.h"

void back() {
	if (IsKeyPressed(KEY_ESCAPE)) GameMainMenu();
}

void level1() {
	Texture2D map1 = LoadTexture("C:/Users/admin/source/repos/2223-9th-grade-sprint-math-games-bitmaze/Game/BitMaze/raylib/resources/level1.png");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(map1, 400 - 225, 0, WHITE);
		EndDrawing();
		back();
	}
	UnloadTexture(map1);
}

void level2() {
	Texture2D map2 = LoadTexture("C:/Users/admin/source/repos/2223-9th-grade-sprint-math-games-bitmaze/Game/BitMaze/raylib/resources/level2.png");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(map2, 400 - 225, 0, WHITE);
		EndDrawing();
		back();
	}
	UnloadTexture(map2);
}

void level3() {
	Texture2D map3 = LoadTexture("C:/Users/admin/source/repos/2223-9th-grade-sprint-math-games-bitmaze/Game/BitMaze/raylib/resources/level3.png");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(map3, 400 - 225, 0, WHITE);
		EndDrawing();
		back();
	}
	UnloadTexture(map3);
}

void level4() {
	Texture2D map4 = LoadTexture("C:/Users/admin/source/repos/2223-9th-grade-sprint-math-games-bitmaze/Game/BitMaze/raylib/resources/level4.png");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(map4, 400 - 225, 0, WHITE);
		EndDrawing();
		back();
	}
	UnloadTexture(map4);
}

void level5() {
	Texture2D map5 = LoadTexture("C:/Users/admin/source/repos/2223-9th-grade-sprint-math-games-bitmaze/Game/BitMaze/raylib/resources/level5.png");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(map5, 400 - 225, 0, WHITE);
		EndDrawing();
		back();
	}
	UnloadTexture(map5);
}