
#include "raylib.h"

#define MAX_PARTICLES 100

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float radius;
    float life;
    Color color;
} Particle;

int main(void) {
    InitWindow(800, 450, "Particle System");
    SetTargetFPS(60);

    Particle particles[MAX_PARTICLES] = { 0 };
    
    while (!WindowShouldClose()) {
        // パーティクル更新
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            for (int i = 0; i < MAX_PARTICLES; i++) {
                if (particles[i].life <= 0) {
                    particles[i].position = GetMousePosition();
                    particles[i].velocity.x = (float)GetRandomValue(-100, 100)/100.0f;
                    particles[i].velocity.y = (float)GetRandomValue(-100, 100)/100.0f;
                    particles[i].radius = (float)GetRandomValue(2, 8);
                    particles[i].life = 1.0f;
                    particles[i].color = (Color){
                        GetRandomValue(50, 255),
                        GetRandomValue(50, 255),
                        GetRandomValue(50, 255),
                        255
                    };
                    break;
                }
            }
        }

        // パーティクルの更新と描画
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            for (int i = 0; i < MAX_PARTICLES; i++) {
                if (particles[i].life > 0) {
                    particles[i].position.x += particles[i].velocity.x;
                    particles[i].position.y += particles[i].velocity.y;
                    particles[i].life -= 0.01f;
                    
                    DrawCircleV(particles[i].position, particles[i].radius, particles[i].color);
                }
            }
            
            DrawText("Click and hold to create particles!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}