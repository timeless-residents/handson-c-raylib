
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Basic Shapes");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(100, 100, 200, 100, RED);
            DrawCircle(500, 150, 50, BLUE);
            DrawTriangle(
                (Vector2){500, 300},
                (Vector2){400, 400},
                (Vector2){600, 400},
                GREEN
            );
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
