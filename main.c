#include "raylib.h"

int main(void) {
    // ウィンドウの初期化 (800x450)
    InitWindow(800, 450, "Raylib Text Example");

    // フレームレート設定
    SetTargetFPS(60);

    // メインゲームループ
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib!", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
