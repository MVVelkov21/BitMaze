#include "raylib.h"
#include "PlayGame.h"

void back() {
	if (IsKeyPressed(KEY_ESCAPE)) GameMainMenu();
}

void level1() {
	const int numBoxes = 30;
	Rectangle boxes[numBoxes];
	//Color boxColor = BLANK; 
	Color boxColor = RED;
		boxes[0].x = 180;
		boxes[0].y = 0;
		boxes[0].width = 7;
		boxes[0].height = 500;

		boxes[1].x = 180;
		boxes[1].y = 2;
		boxes[1].width = 500;
		boxes[1].height = 7;

		boxes[2].x = 240;
		boxes[2].y = 405;
		boxes[2].width = 280;
		boxes[2].height = 7;

		boxes[3].x = 180;
		boxes[3].y = 445;
		boxes[3].width = 500;
		boxes[3].height = 7;

		boxes[4].x = 618;
		boxes[4].y = 0;
		boxes[4].width = 7;
		boxes[4].height = 500;

		boxes[5].x = 557;
		boxes[5].y = 64;
		boxes[5].width = 10;
		boxes[5].height = 136;

		boxes[6].x = 180;
		boxes[6].y = 153;
		boxes[6].width = 380;
		boxes[6].height = 10;

		boxes[7].x = 243;
		boxes[7].y = 364;
		boxes[7].width = 225;
		boxes[7].height = 10;

		boxes[8].x = 510;
		boxes[8].y = 353;
		boxes[8].width = 225;
		boxes[8].height = 10;

		boxes[9].x = 226;
		boxes[9].y = 0;
		boxes[9].width = 9;
		boxes[9].height = 65;

		boxes[10].x = 226;
		boxes[10].y = 105;
		boxes[10].width = 9;
		boxes[10].height = 20;

		boxes[11].x = 340;
		boxes[11].y = 0;
		boxes[11].width = 9;
		boxes[11].height = 130;

		boxes[12].x = 226;
		boxes[12].y = 119;
		boxes[12].width = 147;
		boxes[12].height = 10;

		boxes[13].x = 350;
		boxes[13].y = 50;
		boxes[13].width = 63;
		boxes[13].height = 10;

		boxes[14].x = 405;
		boxes[14].y = 45;
		boxes[14].width = 7;
		boxes[14].height = 15;

		boxes[15].x = 418;
		boxes[15].y = 118;
		boxes[15].width = 140;
		boxes[15].height = 10;

		boxes[16].x = 452;
		boxes[16].y = 63;
		boxes[16].width = 10;
		boxes[16].height = 60;

		boxes[17].x = 452;
		boxes[17].y = 63;
		boxes[17].width = 28;
		boxes[17].height = 10;

		boxes[18].x = 530;
		boxes[18].y = 64;
		boxes[18].width = 28;
		boxes[18].height = 10;

		boxes[19].x = 242;
		boxes[19].y = 238;
		boxes[19].width = 10;
		boxes[19].height = 135;

		boxes[20].x = 302;
		boxes[20].y = 158;
		boxes[20].width = 10;
		boxes[20].height = 95;

		boxes[21].x = 302;
		boxes[21].y = 228;
		boxes[21].width = 180;
		boxes[21].height = 7;

		boxes[22].x = 479;
		boxes[22].y = 228;
		boxes[22].width = 10;
		boxes[22].height = 23;

		boxes[23].x = 252;
		boxes[23].y = 236;
		boxes[23].width = 50;
		boxes[23].height = 10;

		boxes[24].x = 560;
		boxes[24].y = 270;
		boxes[24].width = 10;
		boxes[24].height = 43;

		boxes[25].x = 304;
		boxes[25].y = 296;
		boxes[25].width = 10;
		boxes[25].height = 19;

		boxes[26].x = 304;
		boxes[26].y = 305;
		boxes[26].width = 260;
		boxes[26].height = 10;

		boxes[27].x = 479;
		boxes[27].y = 286;
		boxes[27].width = 10;
		boxes[27].height = 19;

		boxes[28].x = 458;
		boxes[28].y = 306;
		boxes[28].width = 10;
		boxes[28].height = 60;

		boxes[29].x = 508;
		boxes[29].y = 354;
		boxes[29].width = 10;
		boxes[29].height = 55;

	Rectangle rect = { 195, 15, 20, 20 };
	Color rectColor = RED;

	const float moveSpeed = 200.0f;
	Vector2 movement = { 0, 0 };

	Texture2D map1 = LoadTexture("C:/Users/admin/source/repos/2223-9th-grade-sprint-math-games-bitmaze/Game/BitMaze/raylib/resources/level1.png");
	while (!WindowShouldClose()) {
		movement.x = ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) - (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) * moveSpeed * GetFrameTime();
		movement.y = ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) - (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))) * moveSpeed * GetFrameTime();

		rect.x += movement.x;
		rect.y += movement.y;

		bool collisionDetected = false;
		for (int i = 0; i < numBoxes; i++){
			if (CheckCollisionRecs(rect, boxes[i])){
				collisionDetected = true;
				break;
			}
		}

		if (collisionDetected){
			rect.x -= movement.x;
			rect.y -= movement.y;
		}

		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(map1, 400 - 225, 0, WHITE);
		for (int i = 0; i < numBoxes; i++){
			DrawRectangleRec(boxes[i], boxColor);
		}
		DrawRectangleRec(rect, rectColor);
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