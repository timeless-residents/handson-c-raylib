# Raylib プロトタイプ集

このリポジトリは、Raylibを使用した基本的なゲームプログラミングの例を集めたものです。

## 必要環境

- clang
- raylib
- ImageMagick (アセット処理用)
- SoX (音声生成用)

MacOSでの環境セットアップ:
```bash
brew install raylib
brew install imagemagick
brew install sox
```

## プロジェクト構造

```
.
├── Makefile
├── README.md
├── prototype/
│   ├── app01.c  # 基本的なウィンドウ表示
│   ├── app02.c  # 図形描画
│   ├── app03.c  # アニメーション
│   ├── app04.c  # キーボード入力
│   ├── app05.c  # マウス入力
│   ├── app06.c  # 衝突判定
│   ├── app07.c  # テクスチャ
│   ├── app08.c  # サウンド
│   ├── app09.c  # パーティクル
│   └── app10.c  # シンプルなPongゲーム
└── output/      # ビルド出力ディレクトリ
```

## ビルド方法

特定のプログラムをビルド:
```bash
make app01  # app01.cをビルド
```

すべてのプログラムをビルド:
```bash
make all
```

ビルド成果物の削除:
```bash
make clean
```

## アセット作成用ユーティリティ

### 画像処理 (ImageMagick)

```bash
# 画像サイズの変更
convert input.png -resize 800x600 output.png

# 幅のみ指定（高さは比率を保持）
convert input.png -resize 800 output.png

# 高さのみ指定（幅は比率を保持）
convert input.png -resize x600 output.png

# パーセンテージでリサイズ
convert input.png -resize 50% output.png
```

### 音声生成 (SoX)

```bash
# 基本的な効果音生成
sox -n output.wav synth 1 sine 440        # 1秒のビープ音
sox -n jump.wav synth 0.15 sine 300-1200  # ジャンプ音
sox -n coin.wav synth 0.1 sine 900-2000   # コイン取得音

# エフェクト付加
sox input.wav output.wav echo 0.8 0.9 100 0.3  # エコー効果
sox input.wav output.wav reverb                 # リバーブ効果
```

## プログラム説明

1. **app01.c**: 基本的なウィンドウ表示とテキスト描画
2. **app02.c**: 基本図形（四角形、円、三角形）の描画
3. **app03.c**: 単純なアニメーション（移動する円）
4. **app04.c**: キーボード入力によるオブジェクト操作
5. **app05.c**: マウス入力とインタラクション
6. **app06.c**: 矩形の衝突判定
7. **app07.c**: 画像テクスチャの読み込みと表示
8. **app08.c**: サウンド再生の基本
9. **app09.c**: シンプルなパーティクルシステム
10. **app10.c**: Pongゲーム（プレイヤーvsCPU）

## Pongゲーム (app10.c) の詳細

主な機能:
- プレイヤーパドル（右側、青）: 上下キーで操作
- CPUパドル（左側、緑）: ボールを追跡する簡単なAI
- スコアシステム: パドルでボールを跳ね返すとスコア加算
- 自動リセット: ボールが画面外に出ると中央に戻る

ゲームの目的:
- CPUとのラリーを続け、高スコアを目指す
- ボールを取り逃がすとスコアがリセット

## ライセンス

このプロジェクトはMITライセンスの下で公開されています。