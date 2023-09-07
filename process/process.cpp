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
            cout << "EXPLORING...";

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