CC 	:= avr-gcc
OBJ := avr-objcopy
DD 	:= avrdude

BIN_DIR := ./bin
H_DIR	:= ./include
SRC_DIR := ./src

AVRDUDE_PATH := /etc/avrdude/avrdude.conf
ARDUINO_PATH := /dev/ttyACM0

CC_FILES 	:= $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES 	:= $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(CC_FILES))
CC_FLAGS 	:= -mmcu=atmega328p -Os -Wall -Wextra -I $(H_DIR) -lm
OBJ_FLAGS	:= -O ihex
DD_FLAGS 	:= -c arduino -p atmega328p -C $(AVRDUDE_PATH) -c arduino -P $(ARDUINO_PATH) -b 115200

ifeq ($(OS), Windows_NT)
	TARGET := $(BIN_DIR)/nicos.elf
else 
	TARGET := $(BIN_DIR)/nicos.elf
endif

all: clean build hex flash

build: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@echo [info]  Done compiling
	@echo [info]  Start linking
	@$(CC) $(CC_FLAGS) $^ -o $@
	@echo [info]  Finished linking

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo [info]  compiling $(notdir $(basename $<)) 
	@$(CC) -c $(CC_FLAGS) $< -o $@

hex:
	@echo [info] Converting to hex file..
	@$(OBJ) $(OBJ_FLAGS) $(TARGET) $(BIN_DIR)/nicos.hex
	@echo [info] Done converting to hex file


flash:
	@echo [info] Start uploading nicos.hex
	@$(DD) $(DD_FLAGS) -U flash:w:$(BIN_DIR)/nicos.hex:i
	@echo [info] Done uploading

.PHONY: build
clean:
	@rm -rf $(BIN_DIR)
	@mkdir -p $(BIN_DIR)
	@echo [info] Cleanup bin