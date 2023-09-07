#ifndef PROCESS_PROCESS
#define PROCESS_PROCESS

#define IMAGE_SIZE 28
#define NUMBER_OF_FEATURES 32
#define NUMBER_OF_TRAINED_IMAGES 5000

void clear_terminal();

void start_menu();

void main_menu();

void info_menu();

void previous_step(string previous_step);

int valid_input(string input);

#endif