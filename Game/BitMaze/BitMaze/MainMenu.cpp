#include "raylib.h"
#include "PlayGame.h"
#include "Rules.h"
#include "Settings.h"
#include "MainMenu.h"

const int screenWidth = 800;
const int screenHeight = 450;

void MainMenuButtons() {
    DrawRectangle(326, 125, 150, 50, BLACK);
    DrawText("PLAY", 335, 128, 50, WHITE);
    DrawRectangle(308, 185, 185, 50, BLACK);
    DrawText("RULES", 318, 188, 50, WHITE);
    DrawRectangle(255, 245, 283, 50, BLACK);
    DrawText("SETTINGS", 260, 248, 50, WHITE);
    if (IsKeyPressed(KEY_ONE)) {
       while (!IsKeyDown(KEY_ONE)) {
            DrawText("PLAY", 335, 128, 50, RED);
            if (IsKeyPressed(KEY_ENTER)) {
                GameMainMenu();
            }
        }
    }
    if (IsKeyPressed(KEY_TWO)) {
        /*while (!WindowShouldClose()) {
            BeginDrawing();
            DrawText("RULES", 318, 188, 50, RED);
            EndDrawing();
        }*/
    }
    if (IsKeyPressed(KEY_THREE)) {
        /*while (!WindowShouldClose()) {
            BeginDrawing();
            DrawText("SETTINGS", 260, 248, 50, RED);
            EndDrawing();
        }*/
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
        DrawText("PRESS 'ENTER' TO PLAY, 'R' FOR RULES OR 'ESC' TO QUIT", 100, 90, 20, BLACK);
        MainMenuButtons();
        EndDrawing();
    }
}