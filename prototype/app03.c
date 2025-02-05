
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Animation");
    SetTargetFPS(60);

    float circleX = 400.0f;
    float speed = 5.0f;
    
    while (!WindowShouldClose()) {
        // 更新
        circleX += speed;
        if (circleX > 750 || circleX < 50) speed *= -1;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(circleX, 225, 25, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}