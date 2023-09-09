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

void act_of_training(FEATURES_TMP &data);

void act_of_extracting_features(float matrix[IMAGE_SIZE][IMAGE_SIZE],
                                float save_features[]);

float act_of_distance_two_arrays(float first_array[], float second_array[], int continu);

float act_of_distance_array_and_matrix(float array[], float matrix[][NUMBER_OF_FEATURES],
                                       float distance[]);

void training(FEATURES_TMP &data);

void act_of_fill_the_vector(float &min, float &distance[NUMBER_OF_TRAINED_IMAGES],
                            FEATURES_TMP &dataset,
                            vector<int> &min_lables, vector<float> &k_min, int i);

void act_of_shift_the_vector(float &min, float &distance[NUMBER_OF_TRAINED_IMAGES],
                             FEATURES_TMP &dataset,
                             vector<int> &min_lables, vector<float> &k_min, int i);

void test_features(FEATURES_TMP &data, float distance[NUMBER_OF_FEATURES],
                   float image[IMAGE_SIZE][IMAGE_SIZE]);

int act_of_testing(float image[IMAGE_SIZE][IMAGE_SIZE], int k,
                   FEATURES_TMP &data, float &closest_distance);

int act_of_finding_most_repeated_lable(vector<int> k_times_min_lables, float &closest_distance);

void testing(FEATURES_TMP &data);

void final_massage(string predicted_lable, int lable,
                   int k, float closest_distance);

float calculate_accurancy_of_algorithm(FEATURES_TMP &data);

#endif