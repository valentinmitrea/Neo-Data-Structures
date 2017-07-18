# compiler, compilation flags and name of executable
CC = gcc
CFLAGS = -std=c99 -O3 -Werror -pedantic -Wall -Wextra -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wcast-qual
LIBS = -lnds
EXECUTABLE = main

# program used for removing executable and object files generated during compilation
RM = rm -rf

.PHONY: build
all: build

# target used if we want to rebuild the whole application
.PHONY: rebuild
rebuild: clean build

build: Person.o main.o
	$(CC) $(CFLAGS) $^ -o $(EXECUTABLE) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) *.o
