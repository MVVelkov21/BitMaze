#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int playSquareX = 326;
const int playSquareY = 125;
const int playSquareW = 150;
const int playX = 335;
const int playY = 128;
const int playS = 50;
const int playKey = KEY_ONE;

const int rulesSquareX = 308;
const int rulesSquareY = 185;
const int rulesSquareW = 185;
const int rulesX = 318;
const int rulesY = 188;
const int rulesS = 50;
const int rulesKey = KEY_TWO;

void MainMenuButtons(const int squareX, const int squareY, const int squareW, const int W, const int H, const char Text[], const int key) {
    DrawRectangle(squareX, squareY, squareW, 50, BLACK);
    DrawText(Text, W, H, 50, WHITE);
    if (IsKeyPressed(key)) {
        while (!WindowShouldClose()) {
            BeginDrawing();
            DrawText(Text, W, H, 50, RED);
            EndDrawing();
        }
    }
}

void MainMenuGUI() {
    InitWindow(screenWidth, screenHeight, "BitMaze");

    DisableCursor();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("PRESS 'ENTER' TO PLAY, 'R' FOR RULES OR 'ESC' TO QUIT", 100, 100, 20, BLACK);
        MainMenuButtons(playSquareX, playSquareY, playSquareW, playX, playY, "PLAY", playKey);
        MainMenuButtons(rulesSquareX, rulesSquareY, rulesSquareW, rulesX, rulesY, "RULES", rulesKey);
        EndDrawing();
    }
}