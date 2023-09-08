#include "utils\\utils.hpp"
#include "utils\\timer.hpp"
#include "process.hpp"
#include <string>

using namespace std;

enum START_MENU
{
    MAIN_MENU = 1,
    INFO = 2,
    EXIT = 3
};

enum MAIN_MENU_OPTIONS
{
    EXPLORE = 1,
    TRAIN = 2,
    TEST = 3,
    RETURN = 4
};

enum INFO_OPTIONS
{
    ABOUT_PROGRAM = 1,
    ABOUT_AUTHOR = 2,
    INFO_RETURN = 3
};

struct FEATURES_LABELS
{
    float features_of_matrix[NUMBER_OF_TRAINED_IMAGES][NUMBER_OF_FEATURES];
    int label[NUMBER_OF_TRAINED_IMAGES];
};

void clear_terminal()
{
#ifdef _WIN32
    system("cls");
#else
    sysetm("clear");
#endif
}

void start_menu()
{

    cout << "[ IMAGE CLASSIFIER ]"
         << endl
         << "1- Main Menu"
         << endl
         << "2- Info"
         << endl
         << "3- Exit"
         << endl
         << "Please enter your command :"
         << endl;

    string input;
    cin >> input;

    int command = valid_input(input);

    bool should_exit = false;

    while (!should_exit)
    {
        switch (command)
        {

        case START_MENU::MAIN_MENU:
            clear_terminal();
            main_menu();

            should_exit = true;
            break;

        case START_MENU::INFO:
            clear_terminal();
            info_menu();

            should_exit = true;
            break;

        case START_MENU::EXIT:
            clear_terminal();
            cout << "Program closed 100%";

            should_exit = true;
            break;

        default:
            cout << "Please choose from the options above" << endl;
            cin >> input;
            command = valid_input(input);
            break;
        }
    }
}

void main_menu()
{

    cout << "[ MAIN MENU ]"
         << endl
         << "1- Explore images from dataset"
         << endl
         << "2- Train"
         << endl
         << "3- Test"
         << endl
         << "4- Return"
         << endl
         << "Please enter your command :"
         << endl;

    string input;
    cin >> input;

    int command = valid_input(input);

    bool should_exit = false;

    while (!should_exit)
    {
        switch (command)
        {

        case MAIN_MENU_OPTIONS::EXPLORE:
            clear_terminal();
            explore_images_from_dataset();

            should_exit = true;
            break;

        case MAIN_MENU_OPTIONS::TRAIN:
            clear_terminal();
            cout << "TRAINING...";

            should_exit = true;
            break;

        case MAIN_MENU_OPTIONS::TEST:
            clear_terminal();
            cout << "TESTING...";

            should_exit = true;
            break;

        case MAIN_MENU_OPTIONS::RETURN:
            clear_terminal();
            start_menu();

            should_exit = true;
            break;

        default:
            cout << "Please choose from the options above" << endl;
            cin >> input;
            command = valid_input(input);
            break;
        }
    }
}

void info_menu()
{

    cout << "[ INFORMATIONES ]"
         << endl
         << "1- About Program {}"
         << endl
         << "2- About Author {}"
         << endl
         << "3- Return"
         << endl
         << "Please enter your command :"
         << endl;

    string input;
    cin >> input;

    int command = valid_input(input);

    bool should_exit = false;

    while (!should_exit)
    {
        switch (command)
        {

        case INFO_OPTIONS::ABOUT_PROGRAM:
            clear_terminal();
            cout << "About Program {"
                 << endl
                 << "Image classification is the task of classifying an input image among certain classes"
                 << endl
                 << "given an input image we should put a label on the image from a set of predefined labels."
                 << endl
                 << "As an example, consider the case of classifying an image based on which number is present"
                 << endl
                 << "in the image. To be more precise, the algorithm is given an image as the input and"
                 << endl
                 << "it should predict which digit is present in the image among ten different digits zero, one, two... "
                 << endl
                 << "}"
                 << endl;

            previous_step("info_menu");

            should_exit = true;
            break;

        case INFO_OPTIONS::ABOUT_AUTHOR:
            clear_terminal();
            cout << "About Author {"
                 << endl
                 << "Programmer -> Samin Mehran"
                 << endl
                 << "Keep in touch with -> smiinmhrn@gmail.com"
                 << endl
                 << "}"
                 << endl;

            previous_step("info_menu");

            should_exit = true;
            break;

        case INFO_OPTIONS::INFO_RETURN:
            clear_terminal();
            start_menu();

            should_exit = true;
            break;

        default:
            cout << "Please choose from the options above" << endl;
            cin >> input;
            command = valid_input(input);
            break;
        }
    }
}

void previous_step(string previous_step)
{
    cout << endl
         << "0. Return"
         << endl;

    string input;
    cin >> input;
    int command = valid_input(input);

    while (true)
    {
        if (command == 0)
            break;
        else
        {
            cout << "Please choose from the options above" << endl;
            cin >> input;
            command = valid_input(input);
        }
    }

    if (previous_step == "main_menu")
    {
        clear_terminal();
        main_menu();
    }
    else if (previous_step == "info_menu")
    {
        clear_terminal();
        info_menu();
    }
    else
    {
        clear_terminal();
        start_menu();
    }
}

int valid_input(string input)
{

    while (true)
    {
        try
        {
            int command = stoi(input);
            return command;
        }
        catch (invalid_argument ex)
        {
            cout << "unvalide commmand. try again" << endl;
            cin >> input;
        }
    }
}

void print_image(float image[IMAGE_SIZE][IMAGE_SIZE])
{

    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            if (image[i][j] == 0)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void explore_images_from_dataset()
{
    cout << "[ EXPLORE IMAGES FROM DATASET]"
         << endl
         << "Enter the lable from 0 to 9 :"
         << endl;

    string input_lable;
    cin >> input_lable;

    int lable = valid_input(input_lable);

    while (true)
    {
        if (lable >= 0 && lable <= 9)
            break;
        else
        {
            cout << "your choice is out of bound. Please try again :"
                 << endl;

            cin >> input_lable;
            lable = valid_input(input_lable);
        }
    }

    string image_path = interpolation("data\\mnist", "train", to_string(lable));

    cout << "Enter the number of images from 0 to 1000 :"
         << endl;

    string input_number;
    cin >> input_number;

    int number = valid_input(input_number);

    while (true)
    {
        if (number >= 0 && number <= 1000)
            break;
        else
        {
            cout << "your choice is out of bound. Please try again :"
                 << endl;

            cin >> input_number;
            number = valid_input(input_number);
        }
    }

    float image[IMAGE_SIZE][IMAGE_SIZE];

    load_image(image_path, number, image);

    print_image(image);

    cout << "FINAL RESULT IS ->"
         << endl
         << " LABLE OF CHOSEN IMAGE : "
         << lable
         << " NUMBER OF CHOSEN IMAGE : "
         << number
         << endl;

    previous_step("main_menu");
}

float math_matrix_average(float matrix[IMAGE_SIZE][IMAGE_SIZE],
                          int x_start, int x_end, int y_start, int y_end)
{
    float sum = 0;

    for (int i = x_start; i < x_end; i++)
    {
        for (int j = y_start; j < y_end; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum / 49;
}

float math_matrix_standard_deviation(float matrix[IMAGE_SIZE][IMAGE_SIZE],
                                     int x_start, int x_end, int y_start, int y_end, float avrg)
{
    float sum = 0;

    for (int i = x_start; i < x_end; i++)
    {
        for (int j = y_start; j < y_end; j++)
        {
            sum += pow((matrix[i][j] - avrg), 2);
        }
    }
    return sqrt(sum / 48);
}

void act_of_training(FEATURES_LABELS &data)
{
    int index = 0;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        string lable = '0' + i;

        string image_path = interpolation("data\\mnist", "train", lable);

        for (int j = 0; i < 500; i++)
        {
            float image[IMAGE_SIZE][IMAGE_SIZE];

            int number = (rand() % file_count(image_path)) + 1;

            load_image(image_path, number, image);

            act_of_extracting_features(data.features_of_matrix[index], image);
            dataset.label[index] = i;

            index += 1;
        }
    }
}

void act_of_extracting_features(float matrix[IMAGE_SIZE][IMAGE_SIZE],
                                float save_features[])
{
    int index = 0;

    for (int i = 0; i < IMAGE_SIZE; i += 7)
    {
        for (int j = 0; j < IMAGE_SIZE; j += 7)
        {
            int x_end = i + 7;
            int y_end = j + 7;

            float avrg = math_matrix_average(matrix, i, x_end, j, y_end);
            save_features[index] = avrg;
            save_features[index + 1] = math_matrix_standard_deviation(matrix, i, x_end, j, y_end, avrg);
            index += 2;
        }
    }
}

float act_of_distance_two_arrays(float first_array[], float second_array[], int continu)
{
    float sum = 0;

    for (int i = 0; i < continu; i++)
    {
        sum += pow((first_array[i] - second_array[i], 2));
    }
    return sqrt(sum);
}

float act_of_distance_array_and_matrix(float array[], float matrix[][NUMBER_OF_FEATURES],
                                       float distance[])
{
    for (int i = 0; i < NUMBER_OF_TRAINED_IMAGES; i++)
    {
        distance[i] = act_of_distance_two_arrays(array, matrix[i], NUMBER_OF_FEATURES);
    }
}