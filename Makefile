export PATH="/opt/homebrew/bin:/usr/bin:$PATH"
CC = clang
CFLAGS = -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib
LDLIBS = -lraylib

text_app: main.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f text_app