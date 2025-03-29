CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -fopenmp  

SRCS = src/main.c src/parser.c src/semantic.c src/optimization.c src/memory.c src/codegen.c src/instructions.c
OBJS = $(SRCS:.c=.o)

TARGET = compile_a_thon_compiler

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
