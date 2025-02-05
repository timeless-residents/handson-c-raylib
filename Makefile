# 環境設定
export PATH := /opt/homebrew/bin:/usr/bin:$(PATH)
CC = clang
CFLAGS = -I/opt/homebrew/include -Wall -Wextra
LDFLAGS = -L/opt/homebrew/lib
LDLIBS = -lraylib

# ディレクトリ設定
SRC_DIR = prototype
OUTPUT_DIR = output

# ソースファイル
SOURCES = $(wildcard $(SRC_DIR)/app*.c)
# 実行ファイル名（.cを除いた名前）
TARGETS = $(notdir $(SOURCES:.c=))

# 出力ファイルのフルパス
OUTPUT_TARGETS = $(addprefix $(OUTPUT_DIR)/, $(TARGETS))

# デフォルトターゲット
all: setup $(OUTPUT_TARGETS)

# ディレクトリの作成
setup:
	@mkdir -p $(OUTPUT_DIR)

# 個別のビルドルール
$(OUTPUT_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

# 個別のターゲットのビルドルール
app01: $(OUTPUT_DIR)/app01
app02: $(OUTPUT_DIR)/app02
app03: $(OUTPUT_DIR)/app03
app04: $(OUTPUT_DIR)/app04
app05: $(OUTPUT_DIR)/app05
app06: $(OUTPUT_DIR)/app06
app07: $(OUTPUT_DIR)/app07
app08: $(OUTPUT_DIR)/app08
app09: $(OUTPUT_DIR)/app09
app10: $(OUTPUT_DIR)/app10

# クリーンアップ
clean:
	rm -rf $(OUTPUT_DIR)

# ヘルプ
help:
	@echo "使用可能なターゲット:"
	@echo "  make all      - すべてのプログラムをビルド"
	@echo "  make app01    - app01をビルド"
	@echo "  make app02    - app02をビルド"
	@echo "  make app03    - app03をビルド"
	@echo "  make app04    - app04をビルド"
	@echo "  make app05    - app05をビルド"
	@echo "  make app06    - app06をビルド"
	@echo "  make app07    - app07をビルド"
	@echo "  make app08    - app08をビルド"
	@echo "  make app09    - app09をビルド"
	@echo "  make app10    - app10をビルド"
	@echo "  make clean    - ビルド成果物を削除"
	@echo "  make help     - このヘルプを表示"

.PHONY: all setup clean help app01 app02 app03 app04 app05 app06 app07 app08 app09 app10