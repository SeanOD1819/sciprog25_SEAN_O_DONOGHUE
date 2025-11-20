# Makefile
# Made with help of Youtube, Canvas notes and ChatGPT
# $() -> using a variable

# Compiler
CC = gcc
# Compile code so that the math library is linked (-lm) and some mistakes will be flagged even if the code successfully compiles (-Wall)
CFLAGS = -Wall -lm

# Target name: name of executable file that is generated 
TARGET = make_matmult

# Source files: c files which are compiled together
SRCS = my_main.c my_mult.c

# Object files (automatically derived): creates object file for each source file given
OBJS = $(SRCS:.c=.o)

# Build rule: This is the line that compiles the code from the compiler provided
# basically the line: gcc my_main.o my_mult.o -o make_mult -Wall -lm
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

# Compile .c to .o
# take the .c files and make .o files from them
%.o: %.c
	$(CC) -c $< -o $@

# Clean rule
# remove the .o files
clean:
	rm -f $(OBJS)

