#include <iostream>
#include <cstdlib>

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
    std::cout << "PlaceHolder";
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
            default:
                std::cout << "You gave an invalid input";
                break;
        }
    }
}

