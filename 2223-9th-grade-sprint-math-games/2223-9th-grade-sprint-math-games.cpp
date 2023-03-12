#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int playW = 335;
    const int playH = 128;
    const int playS = 50;
    bool play = 0;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite button");

    DisableCursor();

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);
            DrawRectangle(325, 125, 150, 50, BLACK);
            DrawText("PLAY", playW, playH, playS, WHITE);
            if (IsKeyPressed(KEY_ENTER)) {
                while (!WindowShouldClose()) {
                    BeginDrawing();
                    DrawText("PLAY", playW, playH, playS, RED);
                    EndDrawing();
                }
            }
        EndDrawing();
    }
    CloseWindow();
}