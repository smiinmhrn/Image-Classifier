#include "utils\\utils.hpp"
#include "utils\\timer.hpp"
#include "process.hpp"
#include <string>

using namespace std;

enum START_MENU {
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

void clear_terminal() {
    #ifdef _WIN32
    system("cls"); 
    #else
    sysetm("clear");
    #endif
}

void start_menu() {
    
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
        case START_MENU::MAIN_MENU :
            clear_terminal();
            main_menu();

            should_exit = true;
            break;

        case START_MENU::INFO :
            clear_terminal();
            cout << "c 2";

            should_exit = true;
            break;

        case START_MENU::EXIT :
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

void main_menu() {
    
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
        case MAIN_MENU_OPTIONS::EXPLORE :
            clear_terminal();
            cout << "EXPLORING...";

            should_exit = true;
            break;

        case MAIN_MENU_OPTIONS::TRAIN :
            clear_terminal();
            cout << "TRAINING...";

            should_exit = true;
            break;

        case MAIN_MENU_OPTIONS::TEST :
            clear_terminal();
            cout << "TESTING...";

            should_exit = true;
            break;

        case MAIN_MENU_OPTIONS::RETURN :
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

int valid_input(string input) {

    while (true) {

        try{
            int command = stoi(input);
            return command;
        
        } catch (invalid_argument ex) {
            cout << "unvalide commmand. try again" << endl;
            cin >> input;
        }
    }
}