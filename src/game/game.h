#pragma once
#include <stdint.h>

typedef struct {
    int64_t bits;
    int64_t bits_per_tick;
    int64_t cycle;
    float accum;
} GameState;

void game_init(GameState* g);
void game_update(GameState* g, float dt);
