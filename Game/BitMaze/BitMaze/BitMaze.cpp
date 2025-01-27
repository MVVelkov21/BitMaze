#include "raylib.h"
#include "MainMenu.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main(){
	InitWindow(screenWidth, screenHeight, "BitMaze");
	Image icon = LoadImage("resources/logo.png");

	SetWindowIcon(icon);

	UnloadImage(icon);

	DisableCursor();

	SetTargetFPS(60);
	MainMenuGUI();
}