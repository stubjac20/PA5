#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "InventorySystem.h"

using namespace std;

void printHelp() {
    cout << "Supported commands:\n";
    cout << " 1. find <inventoryid> ,  Look up and print product details.\n";
    cout << " 2. listInventory <category_string> , Print all products that match the category.\n";
    cout << endl;
}

//checks if the user typed valid command
bool isValidCommand(string input) {
    return input == ":help" || input.rfind("find ", 0) == 0 || input.rfind("listInventory ", 0) == 0;
}

void handleCommand(string input, InventorySystem& system) {
    if (input == ":help") {
        printHelp();
    } else if (input.rfind("find ", 0) == 0) {
        string id = input.substr(5);
        system.findProductById(id);
    } else if (input.rfind("listInventory ", 0) == 0) {
        string category = input.substr(14);
        system.listInventoryByCategory(category);
    }
}


void setupSystem(InventorySystem& system) {
    cout << "\nLoading inventory." << endl;

    
    string fileName = "products.csv";

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: could not open " << fileName << endl;
        return;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        system.addProductFromCSV(line);
    }

    file.close();
    cout << "Done" << endl;
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
            cout << "not recognized type :help" << endl;
        }
        cout << "> ";
    }

    return 0;
}
