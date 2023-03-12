#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int playSquareX = 326;
const int playSquareY = 125;
const int playSquareW = 150;
const int playX = 335;
const int playY = 128;
const int playS = 50;

const int rulesSquareX = 308;
const int rulesSquareY = 185;
const int rulesSquareW = 185;
const int rulesX = 318;
const int rulesY = 188;
const int rulesS = 50;

void MainMenuButtons(const int squareX, const int squareY, const int squareW, const int W, const int H, const char Text[]) {
    DrawRectangle(squareX, squareY, squareW, 50, BLACK);
    DrawText(Text, W, H, 50, WHITE);
}

void MainMenuGUI() {
    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite button");

    DisableCursor();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("PRESS 'ENTER' TO PLAY, 'R' FOR RULES OR 'ESC' TO QUIT", 100, 100, 20, BLACK);
        MainMenuButtons(playSquareX, playSquareY, playSquareW, playX, playY, "PLAY");
        MainMenuButtons(rulesSquareX, rulesSquareY, rulesSquareW, rulesX, rulesY, "RULES");
        if (IsKeyPressed(KEY_ENTER)) {
            while (!WindowShouldClose()) {
                BeginDrawing();
                DrawText("PLAY", playX, playY, playS, RED);
                EndDrawing();
            }
        }

        EndDrawing();
    }
    CloseWindow();
}