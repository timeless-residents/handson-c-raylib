
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Mouse Input");
    SetTargetFPS(60);

    Color ballColor = RED;
    
    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballColor = BLUE;
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballColor = RED;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(mousePos.x, mousePos.y, 25, ballColor);
            DrawText("Click to change color!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
