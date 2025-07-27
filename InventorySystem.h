#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H

#include "HashTable.h"
#include "LinkedList.h"
#include "Product.h"
#include <string>
#include <vector>

class InventorySystem {
private:
    HashTable<std::string, Product> productTable;
    HashTable<std::string, LinkedList<Product*>*> categoryTable;

public:
    InventorySystem();
    ~InventorySystem(); //clean up

    void addProductFromCSV(const std::string& line);
    void findProductById(const std::string& id);
    void listInventoryByCategory(const std::string& category, const std::string& arg1 = "", const std::string& arg2 = "");
};

#endif


