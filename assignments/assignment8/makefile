SRC_DIR = ./src_files
INC_DIR = ./inc_files
OBJ_DIR = ./obj_files
BIN_DIR = ./bin_files

CC = gcc
_OBJS = stddev.o mean.o print_table.o mean_stddev.o
OBJS = $(patsubst %, $(OBJ_DIR)/%, $(_OBJS))
_SRCS = $(patsubst %.o, %.c, $(_OBJS))
SRCS = $(patsubst %, $(SRC_DIR)/%, $(_SRCS))
CFLAGS = -g -I$(INC_DIR)
LDFLAGS = -lm 

all: $(BIN_DIR)/mean_stddev

$(BIN_DIR)/compute: $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

dependencies:  $(SRCS)
	$(CC) -I$(INC_DIR) -MM $^ | sed '/^.*.o:/ s#^#$(OBJ_DIR)/#' > $@