#include "raylib.h"
#include "PlayGame.h"

const int screenWidth = 800, screenHeight = 450;

void back() {
	if (IsKeyPressed(KEY_ESCAPE)) GameMainMenu();
}

void level1() {
	Camera2D camera = { 0 };
	camera.target = { 0 };
	camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;

	const int numBoxes = 30;
	Rectangle boxes[numBoxes];
	Color boxColor = BLANK;
	//Color boxColor = RED;
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

	Rectangle rect = { 195, 15, 15, 15 };

	const float moveSpeed = 200.0f;
	Vector2 movement = { 0, 0 };

	Texture2D textureUp = LoadTexture("resources/joel_b1.png");
	Texture2D textureDown = LoadTexture("resources/joel_fr1.png");
	Texture2D textureLeft = LoadTexture("resources/joel_l1.png");
	Texture2D textureRight = LoadTexture("resources/joel_r1.png");
	Texture2D map = LoadTexture("resources/level1.png");
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

		camera.target = { rect.x + rect.width / 2.0f, rect.y + rect.height / 2.0f };

		Texture2D texture;
		if (movement.x > 0) {
			texture = textureRight;
		}
		else if (movement.x < 0) {
			texture = textureLeft;
		}
		else if (movement.y > 0) {
			texture = textureDown;
		}
		else if (movement.y < 0) {
			texture = textureUp;
		}
		else {
			texture = textureUp;
		}

		BeginDrawing();
		BeginMode2D(camera);
		ClearBackground(DARKGRAY);
		DrawTexture(map, 400 - 225, 0, WHITE);
		for (int i = 0; i < numBoxes; i++){
			DrawRectangleRec(boxes[i], boxColor);
		}

		DrawTexture(texture, rect.x, rect.y, WHITE);
		EndMode2D();
		EndDrawing();
		back();
	}
	
	UnloadTexture(map);
}

void level2() {
	Camera2D camera = { 0 };
	camera.target = { 0 };
	camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;

	const int numBoxes = 50;
	Rectangle boxes[numBoxes];
	Color boxColor = BLANK; 
	//Color boxColor = RED;
	boxes[0].x = 190;
	boxes[0].y = 0;
	boxes[0].width = 7;
	boxes[0].height = 500;

	boxes[1].x = 180;
	boxes[1].y = 10;
	boxes[1].width = 500;
	boxes[1].height = 7;

	boxes[2].x = 607;
	boxes[2].y = 0;
	boxes[2].width = 7;
	boxes[2].height = 500;

	boxes[3].x = 180;
	boxes[3].y = 431;
	boxes[3].width = 500;
	boxes[3].height = 7;

	boxes[4].x = 190;
	boxes[4].y = 35;
	boxes[4].width = 90;
	boxes[4].height = 2;

	boxes[5].x = 320;
	boxes[5].y = 35;
	boxes[5].width = 70;
	boxes[5].height = 2;

	boxes[6].x = 463;
	boxes[6].y = 52;
	boxes[6].width = 55;
	boxes[6].height = 2;

	boxes[7].x = 536;
	boxes[7].y = 53;
	boxes[7].width = 52;
	boxes[7].height = 2;

	boxes[8].x = 535;
	boxes[8].y = 125;
	boxes[8].width = 55;
	boxes[8].height = 2;

	boxes[9].x = 535;
	boxes[9].y = 107;
	boxes[9].width = 55;
	boxes[9].height = 2;

	boxes[10].x = 462;
	boxes[10].y = 107;
	boxes[10].width = 20;
	boxes[10].height = 2;

	boxes[11].x = 480;
	boxes[11].y = 142;
	boxes[11].width = 55;
	boxes[11].height = 2;

	boxes[12].x = 478;
	boxes[12].y = 164;
	boxes[12].width = 57;
	boxes[12].height = 2;

	boxes[13].x = 533;
	boxes[13].y = 198;
	boxes[13].width = 57;
	boxes[13].height = 2;

	boxes[14].x = 443;
	boxes[14].y = 250;
	boxes[14].width = 38;
	boxes[14].height = 2;

	boxes[15].x = 445;
	boxes[15].y = 287;
	boxes[15].width = 93;
	boxes[15].height = 2;

	boxes[16].x = 196;
	boxes[16].y = 341;
	boxes[16].width = 222;
	boxes[16].height = 2;

	boxes[17].x = 196;
	boxes[17].y = 287;
	boxes[17].width = 15;
	boxes[17].height = 2;

	boxes[18].x = 210;
	boxes[18].y = 234;
	boxes[18].width = 208;
	boxes[18].height = 2;

	boxes[19].x = 227;
	boxes[19].y = 214;
	boxes[19].width = 165;
	boxes[19].height = 2;

	boxes[20].x = 227;
	boxes[20].y = 144;
	boxes[20].width = 35;
	boxes[20].height = 2;

	boxes[21].x = 283;
	boxes[21].y = 144;
	boxes[21].width = 108;
	boxes[21].height = 2;

	boxes[22].x = 209;
	boxes[22].y = 126;
	boxes[22].width = 75;
	boxes[22].height = 2;


	boxes[23].x = 209;
	boxes[23].y = 88;
	boxes[23].width = 73;
	boxes[23].height = 2;

	boxes[24].x = 210;
	boxes[24].y = 52;
	boxes[24].width = 73;
	boxes[24].height = 2;

	boxes[25].x = 317;
	boxes[25].y = 71;
	boxes[25].width = 21;
	boxes[25].height = 2;

	boxes[26].x = 300;
	boxes[26].y = 89;
	boxes[26].width = 37;
	boxes[26].height = 2;

	boxes[27].x = 316;
	boxes[27].y = 106;
	boxes[27].width = 74;
	boxes[27].height = 2;

	boxes[28].x = 209;
	boxes[28].y = 52;
	boxes[28].width = 2;
	boxes[28].height = 150;

	boxes[29].x = 209;
	boxes[29].y = 234;
	boxes[29].width = 2;
	boxes[29].height = 56;

	boxes[30].x = 300;
	boxes[30].y = 10;
	boxes[30].width = 2;
	boxes[30].height = 80;

	boxes[32].x = 317;
	boxes[32].y = 36;
	boxes[32].width = 2;
	boxes[32].height = 36;

	boxes[31].x = 335;
	boxes[31].y = 71;
	boxes[31].width = 2;
	boxes[31].height = 18;

	boxes[33].x = 390;
	boxes[33].y = 34;
	boxes[33].width = 2;
	boxes[33].height = 180;

	boxes[34].x = 416;
	boxes[34].y = 36;
	boxes[34].width = 2;
	boxes[34].height = 252;

	boxes[35].x = 442;
	boxes[35].y = 36;
	boxes[35].width = 2;
	boxes[35].height = 216;


	boxes[36].x = 444;
	boxes[36].y = 286;
	boxes[36].width = 2;
	boxes[36].height = 216;

	boxes[37].x = 228;
	boxes[37].y = 146;
	boxes[37].width = 2;
	boxes[37].height = 70;

	boxes[38].x = 480;
	boxes[38].y = 108;
	boxes[38].width = 2;
	boxes[38].height = 35;

	boxes[39].x = 534;
	boxes[39].y = 108;
	boxes[39].width = 2;
	boxes[39].height = 35;

	boxes[40].x = 536;
	boxes[40].y = 18;
	boxes[40].width = 2;
	boxes[40].height = 35;

	boxes[41].x = 463;
	boxes[41].y = 54;
	boxes[41].width = 2;
	boxes[41].height = 54;

	boxes[42].x = 587;
	boxes[42].y = 54;
	boxes[42].width = 2;
	boxes[42].height = 54;

	boxes[43].x = 587;
	boxes[43].y = 124;
	boxes[43].width = 2;
	boxes[43].height = 74;

	boxes[44].x = 534;
	boxes[44].y = 198;
	boxes[44].width = 2;
	boxes[44].height = 90;

	boxes[45].x = 534;
	boxes[45].y = 142;
	boxes[45].width = 2;
	boxes[45].height = 22;

	boxes[46].x = 480;
	boxes[46].y = 166;
	boxes[46].width = 2;
	boxes[46].height = 86;

	boxes[47].x = 228;
	boxes[47].y = 360;
	boxes[47].width = 218;
	boxes[47].height = 2;

	boxes[48].x = 228;
	boxes[48].y = 360;
	boxes[48].width = 2;
	boxes[48].height = 20;

	boxes[49].x = 228;
	boxes[49].y = 412;
	boxes[49].width = 2;
	boxes[49].height = 20;
	
	Rectangle rect = { 198, 21, 10, 10 };
	Color rectColor = RED;

	const float moveSpeed = 150.0f;
	Vector2 movement = { 0, 0 };

	Texture2D map = LoadTexture("resources/level2.png");
	while (!WindowShouldClose()) {
		movement.x = ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) - (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) * moveSpeed * GetFrameTime();
		movement.y = ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) - (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))) * moveSpeed * GetFrameTime();

		rect.x += movement.x;
		rect.y += movement.y;

		bool collisionDetected = false;
		for (int i = 0; i < numBoxes; i++) {
			if (CheckCollisionRecs(rect, boxes[i])) {
				collisionDetected = true;
				break;
			}
		}

		if (collisionDetected) {
			rect.x -= movement.x;
			rect.y -= movement.y;
		}

		camera.target = { rect.x + rect.width / 2.0f, rect.y + rect.height / 2.0f };

		BeginDrawing();
		BeginMode2D(camera);
		ClearBackground(DARKGRAY);
		DrawTexture(map, 400 - 225, 0, WHITE);
		for (int i = 0; i < numBoxes; i++) {
			DrawRectangleRec(boxes[i], boxColor);
		}
		DrawRectangleRec(rect, rectColor);
		EndMode2D();
		EndDrawing();
		back();
	}
	UnloadTexture(map);
}

void level3() {
	Camera2D camera = { 0 };
	camera.target = { 0 };
	camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;

	const int numBoxes = 40;
	Rectangle boxes[numBoxes];
	Color boxColor = BLANK; 
	//Color boxColor = RED;
	boxes[0].x = 175;
	boxes[0].y = 0;
	boxes[0].width = 7;
	boxes[0].height = 500;

	boxes[1].x = 617;
	boxes[1].y = 0;
	boxes[1].width = 7;
	boxes[1].height = 500;

	boxes[2].x = 175;
	boxes[2].y = 0;
	boxes[2].width = 500;
	boxes[2].height = 7;

	boxes[3].x = 216;
	boxes[3].y = 0;
	boxes[3].width = 72;
	boxes[3].height = 77;

	boxes[4].x = 210;
	boxes[4].y = 320;
	boxes[4].width = 72;
	boxes[4].height = 77;

	boxes[5].x = 280;
	boxes[5].y = 250;
	boxes[5].width = 54;
	boxes[5].height = 155;

	boxes[6].x = 365;
	boxes[6].y = 250;
	boxes[6].width = 74;
	boxes[6].height = 153;

	boxes[7].x = 400;
	boxes[7].y = 375;
	boxes[7].width = 155;
	boxes[7].height = 28;

	boxes[8].x = 520;
	boxes[8].y = 340;
	boxes[8].width = 35;
	boxes[8].height = 50;

	boxes[9].x = 175;
	boxes[9].y = 445;
	boxes[9].width = 500;
	boxes[9].height = 7;

	boxes[10].x = 175;
	boxes[10].y = 98;
	boxes[10].width = 160;
	boxes[10].height = 10;

	boxes[11].x = 220;
	boxes[11].y = 140;
	boxes[11].width = 88;
	boxes[11].height = 10;

	boxes[12].x = 332;
	boxes[12].y = 136;
	boxes[12].width = 42;
	boxes[12].height = 10;

	boxes[13].x = 416;
	boxes[13].y = 138;
	boxes[13].width = 42;
	boxes[13].height = 10;

	boxes[14].x = 332;
	boxes[14].y = 45;
	boxes[14].width = 42;
	boxes[14].height = 10;

	boxes[15].x = 420;
	boxes[15].y = 44;
	boxes[15].width = 90;
	boxes[15].height = 10;

	boxes[16].x = 300;
	boxes[16].y = 178;
	boxes[16].width = 175;
	boxes[16].height = 10;

	boxes[19].x = 256;
	boxes[19].y = 220;
	boxes[19].width = 144;
	boxes[19].height = 10;

	boxes[17].x = 216;
	boxes[17].y = 286;
	boxes[17].width = 46;
	boxes[17].height = 10;

	boxes[18].x = 175;
	boxes[18].y = 396;
	boxes[18].width = 46;
	boxes[18].height = 10;

	boxes[20].x = 428;
	boxes[20].y = 213;
	boxes[20].width = 25;
	boxes[20].height = 7;

	boxes[21].x = 455;
	boxes[21].y = 338;
	boxes[21].width = 75;
	boxes[21].height = 5;

	boxes[22].x = 330;
	boxes[22].y = 46;
	boxes[22].width = 10;
	boxes[22].height = 100;

	boxes[23].x = 364;
	boxes[23].y = 100;
	boxes[23].width = 10;
	boxes[23].height = 40;

	boxes[24].x = 416;
	boxes[24].y = 100;
	boxes[24].width = 10;
	boxes[24].height = 40;

	boxes[25].x = 300;
	boxes[25].y = 140;
	boxes[25].width = 10;
	boxes[25].height = 40;

	boxes[26].x = 216;
	boxes[26].y = 140;
	boxes[26].width = 10;
	boxes[26].height = 146;

	boxes[27].x = 255;
	boxes[27].y = 220;
	boxes[27].width = 10;
	boxes[27].height = 70;

	boxes[28].x = 450;
	boxes[28].y = 215;
	boxes[28].width = 7;
	boxes[28].height = 120;

	boxes[29].x = 470;
	boxes[29].y = 180;
	boxes[29].width = 7;
	boxes[29].height = 120;

	boxes[30].x = 475;
	boxes[30].y = 220;
	boxes[30].width = 7;
	boxes[30].height = 120;

	boxes[31].x = 455;
	boxes[31].y = 50;
	boxes[31].width = 10;
	boxes[31].height = 120;

	boxes[32].x = 460;
	boxes[32].y = 150;
	boxes[32].width = 10;
	boxes[32].height = 30;

	boxes[33].x = 506;
	boxes[33].y = 0;
	boxes[33].width = 45;
	boxes[33].height = 220;

	boxes[34].x = 550;
	boxes[34].y = 150;
	boxes[34].width = 38;
	boxes[34].height = 70;

	boxes[35].x = 520;
	boxes[35].y = 246;
	boxes[35].width = 45;
	boxes[35].height = 66;

	boxes[36].x = 520;
	boxes[36].y = 246;
	boxes[36].width = 100;
	boxes[36].height = 10;

	boxes[37].x = 310;
	boxes[37].y = 400;
	boxes[37].width = 10;
	boxes[37].height = 100;

	Rectangle rect = { 190, 15, 10, 10 };
	Color rectColor = RED;

	const float moveSpeed = 200.0f;
	Vector2 movement = { 0, 0 };

	Texture2D map = LoadTexture("resources/level3.png");
	while (!WindowShouldClose()) {
		movement.x = ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) - (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) * moveSpeed * GetFrameTime();
		movement.y = ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) - (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))) * moveSpeed * GetFrameTime();

		rect.x += movement.x;
		rect.y += movement.y;

		bool collisionDetected = false;
		for (int i = 0; i < numBoxes; i++) {
			if (CheckCollisionRecs(rect, boxes[i])) {
				collisionDetected = true;
				break;
			}
		}

		if (collisionDetected) {
			rect.x -= movement.x;
			rect.y -= movement.y;
		}

		camera.target = { rect.x + rect.width / 2.0f, rect.y + rect.height / 2.0f };

		BeginDrawing();
		BeginMode2D(camera);
		ClearBackground(DARKGRAY);
		DrawTexture(map, 400 - 225, 0, WHITE);
		for (int i = 0; i < numBoxes; i++) {
			DrawRectangleRec(boxes[i], boxColor);
		}
		DrawRectangleRec(rect, rectColor);
		EndMode2D();
		EndDrawing();
		back();
	}
	UnloadTexture(map);
}

void level4() {
	Camera2D camera = { 0 };
	camera.target = { 0 };
	camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;

	const int numBoxes = 30;
	Rectangle boxes[numBoxes];
	Color boxColor = BLANK; 
	//Color boxColor = RED;
	
	boxes[0].x = 175;
	boxes[0].y = 0;
	boxes[0].width = 17;
	boxes[0].height = 500;

	boxes[1].x = 610;
	boxes[1].y = 0;
	boxes[1].width = 7;
	boxes[1].height = 500;

	boxes[2].x = 175;
	boxes[2].y = 13;
	boxes[2].width = 500;
	boxes[2].height = 7;

	boxes[3].x = 175;
	boxes[3].y = 430;
	boxes[3].width = 500;
	boxes[3].height = 7;

	boxes[4].x = 175;
	boxes[4].y = 45;
	boxes[4].width = 130;
	boxes[4].height = 20;

	boxes[5].x = 175;
	boxes[5].y = 130;
	boxes[5].width = 100;
	boxes[5].height = 20;

	boxes[6].x = 220;
	boxes[6].y = 90;
	boxes[6].width = 84;
	boxes[6].height = 20;

	boxes[7].x = 460;
	boxes[7].y = 45;
	boxes[7].width = 150;
	boxes[7].height = 20;

	boxes[8].x = 390;
	boxes[8].y = 70;
	boxes[8].width = 35;
	boxes[8].height = 20;

	boxes[9].x = 460;
	boxes[9].y = 94;
	boxes[9].width = 100;
	boxes[9].height = 20;

	boxes[10].x = 410;
	boxes[10].y = 135;
	boxes[10].width = 165;
	boxes[10].height = 20;

	boxes[11].x = 225;
	boxes[11].y = 176;
	boxes[11].width = 304;
	boxes[11].height = 20;

	boxes[12].x = 225;
	boxes[12].y = 370;
	boxes[12].width = 304;
	boxes[12].height = 20;

	boxes[13].x = 275;
	boxes[13].y = 330;
	boxes[13].width = 210;
	boxes[13].height = 20;

	boxes[14].x = 275;
	boxes[14].y = 230;
	boxes[14].width = 50;
	boxes[14].height = 20;

	boxes[15].x = 520;
	boxes[15].y = 230;
	boxes[15].width = 55;
	boxes[15].height = 20;

	boxes[16].x = 520;
	boxes[16].y = 275;
	boxes[16].width = 55;
	boxes[16].height = 20;

	boxes[17].x = 515;
	boxes[17].y = 230;
	boxes[17].width = 20;
	boxes[17].height = 160;

	boxes[18].x = 465;
	boxes[18].y = 180;
	boxes[18].width = 20;
	boxes[18].height = 160;

	boxes[19].x = 555;
	boxes[19].y = 140;
	boxes[19].width = 20;
	boxes[19].height = 100;

	boxes[20].x = 555;
	boxes[20].y = 285;
	boxes[20].width = 20;
	boxes[20].height = 120;

	boxes[21].x = 265;
	boxes[21].y = 230;
	boxes[21].width = 20;
	boxes[21].height = 120;

	boxes[22].x = 220;
	boxes[22].y = 150;
	boxes[22].width = 20;
	boxes[22].height = 140;

	boxes[23].x = 225;
	boxes[23].y = 342;
	boxes[23].width = 20;
	boxes[23].height = 40;

	boxes[24].x = 285;
	boxes[24].y = 60;
	boxes[24].width = 20;
	boxes[24].height = 40;

	boxes[25].x = 345;
	boxes[25].y = 20;
	boxes[25].width = 20;
	boxes[25].height = 135;

	boxes[26].x = 410;
	boxes[26].y = 20;
	boxes[26].width = 20;
	boxes[26].height = 135;

	boxes[27].x = 460;
	boxes[27].y = 60;
	boxes[27].width = 20;
	boxes[27].height = 50;

	Rectangle rect = { 195, 25, 10, 10 };
	Color rectColor = RED;

	const float moveSpeed = 150.0f;
	Vector2 movement = { 0, 0 };

	Texture2D map = LoadTexture("resources/level4.png");
	while (!WindowShouldClose()) {
		movement.x = ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) - (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) * moveSpeed * GetFrameTime();
		movement.y = ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) - (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))) * moveSpeed * GetFrameTime();

		rect.x += movement.x;
		rect.y += movement.y;

		bool collisionDetected = false;
		for (int i = 0; i < numBoxes; i++) {
			if (CheckCollisionRecs(rect, boxes[i])) {
				collisionDetected = true;
				break;
			}
		}

		if (collisionDetected) {
			rect.x -= movement.x;
			rect.y -= movement.y;
		}

		camera.target = { rect.x + rect.width / 2.0f, rect.y + rect.height / 2.0f };

		BeginDrawing();
		BeginMode2D(camera);
		ClearBackground(DARKGRAY);
		DrawTexture(map, 400 - 225, 0, WHITE);
		for (int i = 0; i < numBoxes; i++) {
			DrawRectangleRec(boxes[i], boxColor);
		}
		DrawRectangleRec(rect, rectColor);
		EndMode2D();
		EndDrawing();
		back();
	}
	UnloadTexture(map);
}

void level5() {
	/*Camera2D camera = { 0 };
	camera.target = { 0 };
	camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 3.0f;*/

	const int numBoxes = 40;
	Rectangle boxes[numBoxes];
	//Color boxColor = BLANK; 
	Color boxColor = RED;
	
	boxes[0].x = 175;
	boxes[0].y = 0;
	boxes[0].width = 7;
	boxes[0].height = 500;

	boxes[1].x = 175;
	boxes[1].y = 0;
	boxes[1].width = 500;
	boxes[1].height = 7;

	boxes[2].x = 620;
	boxes[2].y = 0;
	boxes[2].width = 7;
	boxes[2].height = 500;

	boxes[3].x = 175;
	boxes[3].y = 450;
	boxes[3].width = 500;
	boxes[3].height = 7;

	boxes[4].x = 175;
	boxes[4].y = 45;
	boxes[4].width = 310;
	boxes[4].height = 10;

	boxes[5].x = 175;
	boxes[5].y = 200;
	boxes[5].width = 375;
	boxes[5].height = 10;

	boxes[6].x = 175;
	boxes[6].y = 323;
	boxes[6].width = 150;
	boxes[6].height = 12;

	boxes[7].x = 175;
	boxes[7].y = 404;
	boxes[7].width = 145;
	boxes[7].height = 12;

	boxes[8].x = 175;
	boxes[8].y = 113;
	boxes[8].width = 132;
	boxes[8].height = 12;

	boxes[9].x = 382;
	boxes[9].y = 426;
	boxes[9].width = 180;
	boxes[9].height = 12;

	boxes[10].x = 540;
	boxes[10].y = 392;
	boxes[10].width = 180;
	boxes[10].height = 12;

	boxes[11].x = 540;
	boxes[11].y = 247;
	boxes[11].width = 40;
	boxes[11].height = 13;

	boxes[12].x = 610;
	boxes[12].y = 247;
	boxes[12].width = 40;
	boxes[12].height = 13;

	boxes[13].x = 530;
	boxes[13].y = 43;
	boxes[13].width = 44;
	boxes[13].height = 13;

	boxes[14].x = 605;
	boxes[14].y = 43;
	boxes[14].width = 40;
	boxes[14].height = 13;

	boxes[15].x = 353;
	boxes[15].y = 322;
	boxes[15].width = 40;
	boxes[15].height = 13;

	boxes[16].x = 380;
	boxes[16].y = 200;
	boxes[16].width = 13;
	boxes[16].height = 180;

	boxes[17].x = 225;
	boxes[17].y = 200;
	boxes[17].width = 13;
	boxes[17].height = 130;

	boxes[18].x = 225;
	boxes[18].y = 200;
	boxes[18].width = 13;
	boxes[18].height = 130;

	boxes[19].x = 464;
	boxes[19].y = 200;
	boxes[19].width = 13;
	boxes[19].height = 164;

	boxes[20].x = 538;
	boxes[20].y = 0;
	boxes[20].width = 13;
	boxes[20].height = 140;

	boxes[21].x = 540;
	boxes[21].y = 310;
	boxes[21].width = 13;
	boxes[21].height = 140;

	boxes[22].x = 463;
	boxes[22].y = 393;
	boxes[22].width = 13;
	boxes[22].height = 140;

	boxes[23].x = 307;
	boxes[23].y = 393;
	boxes[23].width = 13;
	boxes[23].height = 140;

	boxes[24].x = 382;
	boxes[24].y = 407;
	boxes[24].width = 13;
	boxes[24].height = 140;

	boxes[25].x = 539;
	boxes[25].y = 182;
	boxes[25].width = 13;
	boxes[25].height = 100;

	boxes[26].x = 462;
	boxes[26].y = 52;
	boxes[26].width = 13;
	boxes[26].height = 70;

	boxes[27].x = 462;
	boxes[27].y = 156;
	boxes[27].width = 13;
	boxes[27].height = 70;

	boxes[28].x = 295;
	boxes[28].y = 52;
	boxes[28].width = 13;
	boxes[28].height = 15;

	boxes[29].x = 295;
	boxes[29].y = 86;
	boxes[29].width = 13;
	boxes[29].height = 60;

	boxes[30].x = 295;
	boxes[30].y = 175;
	boxes[30].width = 13;
	boxes[30].height = 30;

	boxes[31].x = 306;
	boxes[31].y = 325;
	boxes[31].width = 13;
	boxes[31].height = 30;

	Rectangle rect = { 195, 15, 15, 15 };
	Color rectColor = RED;

	const float moveSpeed = 150.0f;
	Vector2 movement = { 0, 0 };

	Texture2D map = LoadTexture("resources/level5.png");
	while (!WindowShouldClose()) {
		movement.x = ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) - (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))) * moveSpeed * GetFrameTime();
		movement.y = ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) - (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))) * moveSpeed * GetFrameTime();

		rect.x += movement.x;
		rect.y += movement.y;

		bool collisionDetected = false;
		for (int i = 0; i < numBoxes; i++) {
			if (CheckCollisionRecs(rect, boxes[i])) {
				collisionDetected = true;
				break;
			}
		}

		if (collisionDetected) {
			rect.x -= movement.x;
			rect.y -= movement.y;
		}

		//camera.target = { rect.x + rect.width / 2.0f, rect.y + rect.height / 2.0f };

		BeginDrawing();
		//BeginMode2D(camera);
		ClearBackground(DARKGRAY);
		DrawTexture(map, 400 - 225, 0, WHITE);
		for (int i = 0; i < numBoxes; i++) {
			DrawRectangleRec(boxes[i], boxColor);
		}
		DrawRectangleRec(rect, rectColor);
		//EndMode2D();
		EndDrawing();
		back();
	}
	UnloadTexture(map);
}