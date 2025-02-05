
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Keyboard Input");
    SetTargetFPS(60);

    Vector2 position = { 400, 225 };
    
    while (!WindowShouldClose()) {
        // キー入力による位置更新
        if (IsKeyDown(KEY_RIGHT)) position.x += 5.0f;
        if (IsKeyDown(KEY_LEFT)) position.x -= 5.0f;
        if (IsKeyDown(KEY_UP)) position.y -= 5.0f;
        if (IsKeyDown(KEY_DOWN)) position.y += 5.0f;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(position.x, position.y, 25, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}