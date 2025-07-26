#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "InventorySystem.h"

using namespace std;

void printHelp() {
    cout << "Supported commands:\n";
    cout << " 1. find <inventoryid> , Look up and print product details.\n";
    cout << " 2. listInventory <category> [desc|merge|merge desc] , Show products in that category sorted by price.\n";
    cout << " :help , Show this help screen\n";
    cout << " :quit , Exit the program\n";
    cout << endl;
}

//basic check if command is valid
bool isValidCommand(const string& input) {
    return input == ":help" || input.rfind("find ", 0) == 0 || input.rfind("listInventory ", 0) == 0;
}

void handleCommand(const string& input, InventorySystem& system) {
    if (input == ":help") {
        printHelp();
    } else if (input.rfind("find ", 0) == 0) {
        string id = input.substr(5);
        system.findProductById(id);
    } else if (input.rfind("listInventory ", 0) == 0) {
        //break into words
        istringstream iss(input);
        string cmd, category, arg1, arg2;
        iss >> cmd >> category >> arg1 >> arg2;

        system.listInventoryByCategory(category, arg1, arg2);
    }
}

void setupSystem(InventorySystem& system) {
    cout << "\nLoading inventory..." << endl;

    string fileName = "amazon.csv";
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: could not open " << fileName << endl;
        return;
    }

    string line;
    getline(file, line); //skip header

    while (getline(file, line)) {
        system.addProductFromCSV(line);
    }

    file.close();
    cout << "Done loading.\n" << endl;
}

int main() {
    InventorySystem system;

    cout << "\nAmazon Inventory System" << endl;
    cout << ":help to see available commands or :quit to exit.\n" << endl;

    setupSystem(system);

    string input;
    cout << "> ";
    while (getline(cin, input) && input != ":quit") {
        if (isValidCommand(input)) {
            handleCommand(input, system);
        } else {
            cout << "Command not recognized. Type :help" << endl;
        }
        cout << "> ";
    }

    return 0;
}
