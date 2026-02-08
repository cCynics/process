#pragma once
#include <stdint.h>

typedef struct {
    int64_t bits;
    int64_t bits_per_tick;
    int64_t cycle;
    float accum;
} GameState;

typedef enum {
    GAME_ACTION_PULSE = 1
} GameAction;

void game_init(GameState* g);
void game_update(GameState* g, float dt);
int  game_action(GameState* g, GameAction action);
