#include "game/game.h"

static void tick(GameState* g) {
    g->cycle++;
    g->bits += g->bits_per_tick;
}

void game_init(GameState* g) {
    g->bits = 0;
    g->bits_per_tick = 1;
    g->cycle = 0;
    g->accum = 0.0f;
}

void game_update(GameState* g, float dt) {
    g->accum += dt;

    while (g->accum >= 1.0f) {
        tick(g);
        g->accum -= 1.0f;
    }
}

int game_action(GameState* g, GameAction action) {
    switch (action) {
        case GAME_ACTION_PULSE:
            g->bits += 5;
            return 1;
        default:
            return 0;
    }
}
