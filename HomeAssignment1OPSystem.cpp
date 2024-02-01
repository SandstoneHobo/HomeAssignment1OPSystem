#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

//function to generate the menu of the program
void generateMenu(){
    std::cout << std::endl;
    std::cout << "1. List directory contents" << std::endl;
    std::cout << "2. Print working directoy" << std::endl;
    std::cout << "3. Create a new directory" << std::endl;
    std::cout << "4. Display a message" << std::endl;
    std::cout << "5. Concatenate and display content of a file" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << std::endl;
}

//function for listing the directory
void listDirectory() {
    //runs the dir command with newlines before and after
    std::cout << std::endl;
    system("dir");
    std::cout << std::endl;
}

//function to print the current working directory
void printDirectory() {
    //runs the cd command with newlines before and after
    std::cout << std::endl;
    system("cd");
    std::cout << std::endl;
}

//function for creating a directory
void createDirectory(){
    //variable to store the name of the directory the user wants to make
    std::string dir_name;

    //gets the user input for the directory name
    std::cout << std::endl << "What do you want to name the new directory?: ";
    std::cin >> dir_name;

    // uses the given directory name to make a command string that can then be run
    std::cout << std::endl;
    std::string cmd = "mkdir ";
    cmd += dir_name;
    //uses .data() to convert the string into a const char*
    system(cmd.data());
    std::cout << std::endl;
}

//function to display a message
void displayMessage() {
    //variable to store the user's message
    std::string message;

    //gets the user input for the message
    std::cout << std::endl << "What message do you want to display?: ";
    std::cin >> message;

    //creates the command to be run by system()
    std::cout << std::endl;
    std::string cmd = "echo ";
    cmd += message;
    //uses .data() to convert the string to const char*
    system(cmd.data());
    std::cout << std::endl;
}

//function to concatenate files the user wants to merge
void concatenateFiles() {
    //variables to store a list of files given by the user and each name
    std::vector<std::string> file_list;
    std::string file_name;

    //loop allows the user to enter multiple file names
    while (file_name != "next") {
        std::cout << std::endl << "Enter a file you want to add to the list of concatenations (next to move on or back to remove the most recent file entered): ";
        std::cin >> file_name;

        //adds the given input to the list of files to concatenate
        if(file_name != "next" && file_name != "back") {
            file_list.push_back(file_name);
        }
        //checks if the user inputted back to remove a file from the list and if there are no files, returns them to the menu
        if (file_name == "back" && file_list.size() != 0) {
            file_list.pop_back();
        }   
        else if (file_name == "back" && file_list.size() == 0) {
            std::cout << "Returning to main menu" << std::endl;
            return;
        }
    }

    //variable for storing the final command that will be run
    std::string cmd = "type ";
    //loop puts all the list items in the command
    for (int i = 0; i < file_list.size(); i++) {
        cmd += file_list.at(i);
        cmd += " ";
    }

    //gets user input for which file they want the final concatenation to be outputted to
    std::cout << "Enter the name of the file you want the output to be: ";
    std::cin >> file_name;
    cmd += ">> " + file_name;
    //uses .data() to convert the string to const char*
    system(cmd.data());
}

//function to display the contents of a file
void displayFile() {
    //variable to store the name of the file the user wants to display
    std::string file_name;

    //gets the user input for which file they want to display 
    std::cout << std::endl << "What file do you want to display?: ";
    std::cin >> file_name;
    
    //makes the command using the user input
    std::string cmd = "echo " + file_name;
    //uses .data() to convert the string to const char*
    system(cmd.data());
    std::cout << std::endl;
}

int main()
{
    char input = '0';
    while (input != '6') {
        bool valid = false;
        char mode = '0';
        generateMenu();
        std::cin >> input;
        switch (input) {
            case '1':
                listDirectory();
                break;
            case '2':
                printDirectory();
                break;
            case '3':
                createDirectory();
                break;
            case '4':
                displayMessage();
                break;
            case '5':
                while (mode != 'd' && mode != 'c' && mode != 'q') {
                    std::cout << std::endl << "Do you want to display a file (d) or concatenate a file(c)? (q to quit): ";
                    std::cin >> mode;
                    switch (mode) {
                        case 'd':
                            displayFile();
                            break;
                        case 'c':
                            concatenateFiles();
                            break;
                        case 'q':
                            std::cout << "Returning to menu" << std::endl;
                            break;
                        default:
                            std::cout << "Invalid input" << std::endl;
                            break;
                    }
                }
                break;
            default:
                std::cout << "You gave an invalid input";
                break;
        }
    }
    return 0;
}

