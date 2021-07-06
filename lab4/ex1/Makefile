CC = gcc
CFLAGS = -std=gnu99 -g

build: inversare_prop

queue: inversare_prop.c
	$(CC) $(CFLAGS) -o $@ $^

run:
	./inversare_prop

clean:
	rm -f inversare_prop
