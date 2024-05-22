# Nome do executável
TARGET = jogo_da_velha

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c11

# Diretórios de inclusão de cabeçalhos
INCLUDES = -I./src

# Diretório dos arquivos fonte
SRC_DIR = ./src

# Diretório dos arquivos objeto
OBJ_DIR = ./obj

# Encontra todos os arquivos .c no diretório src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Gera a lista de arquivos .o correspondentes
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal
all: $(TARGET)

# Regra para construir o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Regra para compilar arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regra para criar o diretório dos objetos, se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regra de limpeza
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(OBJ_DIR)

.PHONY: all clean
