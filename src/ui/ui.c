#include "ui/ui.h"
#include "raylib.h"

void ui_render(const GameState* g) {
    const int x = 50;
    const int y0 = 50;
    const int line = 30;
    const int fontSize = 20;

    DrawText(TextFormat("BITS: %lld", (long long)g->bits), x, y0 + line * 0, fontSize, GREEN);
    DrawText(TextFormat("BITS/TICK: %lld", (long long)g->bits_per_tick), x, y0 + line * 1, fontSize, GREEN);
    DrawText(TextFormat("CYCLE: %lld", (long long)g->cycle), x, y0 + line * 2, fontSize, GREEN);
}