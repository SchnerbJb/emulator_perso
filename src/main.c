#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "raylib.h"
#include "emulator.h"

int main(int argc, char **argv)
{

    Emulator *emulatorptr;

    emulatorptr = initEmulator();

    if (loadRom(emulatorptr, "./asset/tetris.gb") != 0)
    {
        perror("Can't load file properly\n");
    }

    const int screenWidth = 640;
    const int screenHeight = 576;

    InitWindow(screenWidth, screenHeight, "EMULATOR");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT))
            break;

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    // Mainloop
    // clock_t old = clock();
    // clock_t delta;
    // while (0)
    // {
    //     delta = clock() - old;
    //     old = clock();
    //     update(emulatorptr, delta);
    // }

    free(emulatorptr->memory);
    free(emulatorptr->cdptr->hd);
    free(emulatorptr->cdptr);
    free(emulatorptr);
    return 0;
}