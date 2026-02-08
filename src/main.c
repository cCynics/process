#include "raylib.h"
#include "game/game.h"
#include "ui/ui.h"

int main(void) {
    InitWindow(1920, 1080, "PROCESS");
    SetTargetFPS(60);

    GameState game;
    game_init(&game);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        game_update(&game, dt);

        BeginDrawing();
        ClearBackground(BLACK);

        ui_render(&game);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}