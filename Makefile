CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS = -lncurses

#fichiers sources
SRC = src/main.c \
      src/user.c \
      src/produit.c \
      src/client.c \
      src/fournisseur.c \
	  src/menu.c

OBJ = $(SRC:.c=.o)

TARGET = magasin

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean