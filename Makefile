CC		= gcc
OUT		= status-bar
SRC		= src/main.c src/utils/*.c src/utils_recursive/*.c

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

.PHONY:	all, clean
