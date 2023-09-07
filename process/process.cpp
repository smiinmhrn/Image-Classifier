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
         << "4- Exit"
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
            cout << "c 1";
            should_exit = true;
            break;

        case START_MENU::INFO :
            clear_terminal();
            cout << "c 2";
            should_exit = true;
            break;

        case START_MENU::EXIT :
            clear_terminal();
            cout << "c 3";
            should_exit = true;
            break;

        default:
            cout << "Please choose from the options above" << endl;
            cin >> input;
            command = valide_input(input);
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