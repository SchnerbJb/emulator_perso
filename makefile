all:
# 	gcc main.c -o app.exe -O1 -Wall -std=c99 -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	gcc ./src/main.c ./src/emulator.c ./src/utils.c ./src/graphics.c -o ./build/emulator.exe -O1 -Wall -std=c99 -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lraylib -lopengl32 -lgdi32 -lwinmm
	./build/emulator.exe

# exec:
# 	./build/emulator.exe