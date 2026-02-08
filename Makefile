APP_NAME := process
BIN_DIR  := bin
OBJ_DIR  := build/obj

# raylib submodule paths
RAYLIB_DIR := external/raylib
RAYLIB_INC := $(RAYLIB_DIR)/src
RAYLIB_LIB := $(RAYLIB_DIR)/src/libraylib.a

# Compiler / linker
CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -O2
INCLUDES:= -Isrc -I$(RAYLIB_INC)

# Windows libs for raylib
LDLIBS  := -L$(RAYLIB_DIR)/src -lraylib -lopengl32 -lgdi32 -lwinmm

# Collect all .c files 
SRCS := $(wildcard src/*.c src/*/*.c src/*/*/*.c)
OBJS := $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

EXE  := $(BIN_DIR)/$(APP_NAME).exe

# ---- Default target ----
all: $(EXE)

# ---- Link game ----
$(EXE): $(RAYLIB_LIB) $(OBJS)
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CC) $(OBJS) -o $@ $(LDLIBS)

# ---- Build each object ----
$(OBJ_DIR)/%.o: src/%.c
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ---- Build raylib ----
RAYLIB_MAKE := mingw32-make

$(RAYLIB_LIB):
	$(RAYLIB_MAKE) -C $(RAYLIB_DIR)/src PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=STATIC

# ---- Convenience targets ----
run: $(EXE)
	$(EXE)

clean:
	@rmdir /s /q build 2>nul || exit 0

distclean: clean
	@rmdir /s /q $(BIN_DIR) 2>nul || exit 0
	$(RAYLIB_MAKE) -C $(RAYLIB_DIR)/src clean

print-src:
	@echo $(SRCS)
