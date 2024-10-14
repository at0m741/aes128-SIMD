NAME = aes256

CC = clang

SRCS = $(wildcard *.c)

CFLAGS = -O3 -mavx2 -mfma -g 

OBJ = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)
	
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re

