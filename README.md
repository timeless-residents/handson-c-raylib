# Mac環境でのRaylib開発ガイド

## 概要
RaylibはC言語用のシンプルで使いやすいマルチプラットフォーム対応のゲーム開発ライブラリです。このガイドでは、Mac環境でのRaylib開発環境の構築方法とトラブルシューティングについて説明します。

## 基本的な環境構築

### 1. Homebrewを使用したインストール
```bash
brew update
brew install raylib
```

### 2. プロジェクトの作成
```bash
mkdir raylib_test
cd raylib_test
```

### 3. サンプルコード（main.c）
```c
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Raylib Text Example");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib!", 10, 10, 20, BLACK);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
```

## コンパイル方法

### 基本的なコンパイルコマンド
```bash
clang main.c -o text_app -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib
```

## トラブルシューティング

### 1. raylib.hが見つからない場合
エラーメッセージ: `fatal error: 'raylib.h' file not found`

解決方法:
- インクルードパスの確認
```bash
ls /opt/homebrew/include/raylib.h
```
- 正しいパスを指定してコンパイル
```bash
clang main.c -o text_app -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib
```

### 2. アーキテクチャの不一致
エラーメッセージ: `ignoring file [...] found architecture 'arm64', required architecture 'x86_64'`

確認手順:
```bash
# システムアーキテクチャの確認
uname -m

# コンパイラの場所確認
which clang
```

解決方法:
1. PATHの一時的な修正
```bash
export PATH="/opt/homebrew/bin:/usr/bin:$PATH"
```

2. システムデフォルトのclangを使用してコンパイル
```bash
clang main.c -o text_app -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib
```

### 3. Terminal.appのアーキテクチャ設定
Intel MacからApple Siliconに移行した場合:
1. Terminal.appを終了
2. Finderで「アプリケーション」→「ユーティリティ」→「Terminal」を右クリック
3. 「情報を見る」を選択
4. 「Rosettaを使用して開く」のチェックを外す
5. Terminalを再起動

## 実用的なテキスト表示例

### 1. スコア表示
```c
char scoreText[32];
int score = 100;
sprintf(scoreText, "Score: %d", score);
DrawText(scoreText, 10, 10, 20, BLACK);
```

### 2. 複数行のテキスト
```c
DrawText("Line 1", 10, 10, 20, BLACK);
DrawText("Line 2", 10, 40, 20, BLACK);
```

### 3. 動的テキスト
```c
DrawText("Moving Text", x + GetTime() * 60, y, 20, BLACK);
```

## 注意点
- テキストの位置は画面左上が原点(0,0)
- フォントサイズは整数値で指定
- カラー定数(BLACK, WHITE, RED等)が利用可能
- マルチバイト文字使用時は文字エンコーディングに注意

## 参考リンク
- [Raylib公式ドキュメント](https://www.raylib.com/cheatsheet/cheatsheet.html)
- [Homebrew公式サイト](https://brew.sh/)