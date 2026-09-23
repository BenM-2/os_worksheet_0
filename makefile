SRC = src/
BUILD_DIR = build/
EXE_DIR = $(BUILD_DIR)exec/
GCC_FLAGS = -Wall -Wextra -Werror -g -std=c11

.PHONY: all dirs clean task_1 task_2 task_3 task_4 task_5 TTT


all: task_1 task_2 task_3 task_4 task_5 TTT


dirs: 
	mkdir -p $(BUILD_DIR) $(EXE_DIR)

task_1: $(EXE_DIR)task_1
$(EXE_DIR)task_1: $(SRC)task_1.c | dirs
	gcc $(GCC_FLAGS) $(SRC)task_1.c -o $(EXE_DIR)task_1

task_2: $(EXE_DIR)task_2
$(EXE_DIR)task_2: $(SRC)task_2.c | dirs
	gcc $(GCC_FLAGS) $(SRC)task_2.c -o $(EXE_DIR)task_2

task_3: $(EXE_DIR)task_3
$(EXE_DIR)task_3: $(SRC)task_3.c | dirs
	gcc $(GCC_FLAGS) $(SRC)task_3.c -o $(EXE_DIR)task_3

task_4: $(EXE_DIR)task_4
$(EXE_DIR)task_4: $(SRC)task_4.c | dirs
	gcc $(GCC_FLAGS) $(SRC)task_4.c -o $(EXE_DIR)task_4
	
task_5: $(EXE_DIR)task_5
$(EXE_DIR)task_5: $(SRC)task_5.c | dirs
	gcc $(GCC_FLAGS) $(SRC)task_5.c -o $(EXE_DIR)task_5

task_6: $(EXE_DIR)task_6
$(EXE_DIR)task_6: $(SRC)task_6.c | dirs
	gcc $(GCC_FLAGS) $(SRC)task_6.c -o $(EXE_DIR)task_6

TTT: $(EXE_DIR)TTT
$(EXE_DIR)TTT: $(SRC)tic_tac_toe.c | dirs
	gcc $(GCC_FLAGS) $(SRC)tic_tac_toe.c -o $(EXE_DIR)TTT


clean:
	rm -rf $(BUILD_DIR)