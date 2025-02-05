
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Collision Detection");
    SetTargetFPS(60);

    Rectangle player = { 400, 225, 50, 50 };
    Rectangle target = { 100, 100, 80, 80 };
    bool collision = false;
    
    while (!WindowShouldClose()) {
        // プレイヤーの移動
        if (IsKeyDown(KEY_RIGHT)) player.x += 5.0f;
        if (IsKeyDown(KEY_LEFT)) player.x -= 5.0f;
        if (IsKeyDown(KEY_UP)) player.y -= 5.0f;
        if (IsKeyDown(KEY_DOWN)) player.y += 5.0f;

        // 衝突判定
        collision = CheckCollisionRecs(player, target);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleRec(target, collision ? RED : GREEN);
            DrawRectangleRec(player, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
