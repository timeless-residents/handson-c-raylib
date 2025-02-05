
#include "raylib.h"

typedef struct {
    Vector2 position;
    float radius;
    Color color;
} Ball;

typedef struct {
    Rectangle rect;
    Color color;
} Paddle;

int main(void) {
    InitWindow(800, 450, "Simple Pong");
    SetTargetFPS(60);

    Ball ball = {
        .position = { 400, 225 },
        .radius = 10,
        .color = RED
    };
    
    Vector2 ballSpeed = { 7.0f, 7.0f };

    Paddle player = {
        .rect = { 750, 175, 20, 100 },
        .color = BLUE
    };
    
    Paddle cpu = {
        .rect = { 30, 175, 20, 100 },
        .color = GREEN
    };
    
    int score = 0;
    
    while (!WindowShouldClose()) {
        // ボールの更新
        ball.position.x += ballSpeed.x;
        ball.position.y += ballSpeed.y;
        
        // 壁での反射
        if (ball.position.y >= 450-ball.radius || ball.position.y <= ball.radius) {
            ballSpeed.y *= -1;
        }
        
        // プレイヤーのパドル移動
        if (IsKeyDown(KEY_UP)) player.rect.y -= 5.0f;
        if (IsKeyDown(KEY_DOWN)) player.rect.y += 5.0f;
        
        // CPUのパドル移動（簡単なAI）
        if (cpu.rect.y + cpu.rect.height/2 < ball.position.y) cpu.rect.y += 3.0f;
        if (cpu.rect.y + cpu.rect.height/2 > ball.position.y) cpu.rect.y -= 3.0f;
        
        // パドルとの衝突判定
        if (CheckCollisionCircleRec(ball.position, ball.radius, player.rect) ||
            CheckCollisionCircleRec(ball.position, ball.radius, cpu.rect)) {
            ballSpeed.x *= -1;
            score++;
        }
        
        // ゲームリセット（ボールが画面外に出た場合）
        if (ball.position.x >= 800 || ball.position.x <= 0) {
            ball.position = (Vector2){ 400, 225 };
            score = 0;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawCircleV(ball.position, ball.radius, ball.color);
            DrawRectangleRec(player.rect, player.color);
            DrawRectangleRec(cpu.rect, cpu.color);
            
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}