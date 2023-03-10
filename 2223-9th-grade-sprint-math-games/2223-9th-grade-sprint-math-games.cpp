#include "raylib.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Test");
    SetTargetFPS(60);
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Test", 360, 200, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
}