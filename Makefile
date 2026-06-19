# ===== Configuração =====
CC      := gcc
CFLAGS  := -Wall -Wextra -Iinclude -g
SRC_DIR := src
OBJ_DIR := build
BIN     := build/rsa

# Encontra todos os .c em src/ e gera a lista de .o correspondentes em build/
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# ===== Regras =====
# Alvo padrão: compila o programa
all: $(BIN)

# Liga todos os .o no executável final
$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)

# Compila cada .c em seu .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove os arquivos gerados
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)

# Compila e já roda
run: all
	./$(BIN)

.PHONY: all clean run