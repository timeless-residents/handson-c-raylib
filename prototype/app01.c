#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Basic Window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("My First Raylib Program", 190, 200, 40, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}