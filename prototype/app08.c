
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Sound Playback");
    InitAudioDevice();
    SetTargetFPS(60);

    // サウンドのロード（sound.wavは実際のファイルパスに変更してください）
    Sound sound = LoadSound("resources/sound.wav");
    
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) PlaySound(sound);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Press SPACE to play sound!", 190, 200, 40, DARKGRAY);
        EndDrawing();
    }

    UnloadSound(sound);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
