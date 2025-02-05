
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Texture Loading");
    SetTargetFPS(60);

    // テクスチャのロード（logo.pngは実際のファイルパスに変更してください）
    Texture2D texture = LoadTexture("resources/logo.png");
    Vector2 position = { 400, 225 };
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextureV(texture, position, WHITE);
        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}