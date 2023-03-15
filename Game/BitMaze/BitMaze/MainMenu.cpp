#include "raylib.h"
#include "PlayGame.h"
#include "Rules.h"
#include "Settings.h"
#include "MainMenu.h"

void MainMenuButtons() {
    DrawRectangle(326, 125, 150, 50, BLACK);
    DrawText("PLAY", 335, 128, 50, WHITE);
    DrawRectangle(308, 185, 185, 50, BLACK);
    DrawText("RULES", 318, 188, 50, WHITE);
    DrawRectangle(255, 245, 283, 50, BLACK);
    DrawText("SETTINGS", 260, 248, 50, WHITE);
    if (IsKeyPressed(KEY_ONE)) {
       SetExitKey(KEY_ONE);
       while (!WindowShouldClose()) {
            BeginDrawing();
            DrawText("PLAY", 335, 128, 50, RED);
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)) {
                GameMainMenu();
            }
       }
       SetExitKey(KEY_ESCAPE);
    }
    if (IsKeyPressed(KEY_TWO)) {
        SetExitKey(KEY_TWO);
        while (!WindowShouldClose()) {
            BeginDrawing();
            DrawText("RULES", 318, 188, 50, RED);
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)) {
                rules();
            }
        }
        SetExitKey(KEY_ESCAPE);
    }
    if (IsKeyPressed(KEY_THREE)) {
        SetExitKey(KEY_THREE);
        while (!WindowShouldClose()) {
            BeginDrawing();
            DrawText("SETTINGS", 260, 248, 50, RED);
            EndDrawing();
        }
        SetExitKey(KEY_ESCAPE);
    }
}

void MainMenuGUI() {

    while (1 > 0){
        if (IsKeyPressed(KEY_ESCAPE)) CloseWindow();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("PRESS '1' TO PLAY, '2' FOR RULES OR '3' FOR SETTINGS", 100, 90, 20, BLACK);
        MainMenuButtons();
        EndDrawing();
    }
}