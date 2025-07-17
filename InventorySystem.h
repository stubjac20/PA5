// InventorySystem.h

#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H

#include "HashTable.h"
#include "LinkedList.h"
#include "Product.h"
#include <string>

class InventorySystem {
private:
    HashTable<std::string, Product> productTable; //lookup by ID
    HashTable<std::string, LinkedList<Product*>> categoryTable; //by category

public:
    InventorySystem();

    void addProductFromCSV(const std::string& line);
    void findProductById(const std::string& id);
    void listInventoryByCategory(const std::string& category);
};

#endif
