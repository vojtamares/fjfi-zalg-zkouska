// ConsoleAppZKOUSKA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> //std::ifstream
#include <string> // std::getline
#include "LinkedList.h"

int main()
{
    LinkedList list = LinkedList();

    std::ifstream file;

    file.open("C:\\Users\\Vojta\\Documents\\FJFI\\ZALG\\zk\\ConsoleAppZKOUSKA\\input.txt");

    if (!file.is_open()) {
        std::cerr << "Soubor nebylo mozne otevrit" << std::endl;
        return 1;
    }

    std::string str;
    while (std::getline(file, str)) {
        ListItem* item = new ListItem(str);
        list.appendItem(item);
    }

    std::cout << "Cisty input" << std::endl;

    list.print();

    std::cout << "##### Setridit #####" << std::endl;

    list.sort(); // selection sort

    std::cout << "##### Setrizeno #####" << std::endl;

    list.print();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
