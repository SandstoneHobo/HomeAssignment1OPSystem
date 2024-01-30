#include <iostream>
#include <cstdlib>
#include <string>

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

void listDirectory() {
    std::cout << std::endl;
    system("dir");
    std::cout << std::endl;
}

void printDirectory() {
    std::cout << std::endl;
    system("cd");
    std::cout << std::endl;
}

void createDirectory(){
    std::string file_name;
    std::cout << std::endl << "What do you want to name the new directory?: ";
    std::cin >> file_name;
    std::cout << std::endl;
    std::string cmd = "mkdir ";
    cmd += file_name;
    system(cmd.data());
    std::cout << std::endl;

}

int main()
{
    char input = '0';
    while (input != '6') {
        bool valid = false;
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
            default:
                std::cout << "You gave an invalid input";
                break;
        }
    }
    return 0;
}

