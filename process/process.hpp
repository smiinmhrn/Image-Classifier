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

void print_image(float image[IMAGE_SIZE][IMAGE_SIZE]);

void explore_images_from_dataset();

float math_matrix_average(float matrix[IMAGE_SIZE][IMAGE_SIZE],
                          int x_start, int x_end, int y_start, int y_end);

float math_matrix_standard_deviation(float matrix[IMAGE_SIZE][IMAGE_SIZE],
                                     int x_start, int x_end, int y_start, int y_end, float avrg);

void act_of_training(FEATURES_LABELS &data);

void act_of_extracting_features(float matrix[IMAGE_SIZE][IMAGE_SIZE],
                                float save_features[]);

float act_of_distance_two_arrays(float first_array[], float second_array[], int continu);

float (float array[], float matrix[][NUMBER_OF_FEATURES],
                                       float distance[]);

void training(FEATURES_LABELS &data);

#endif