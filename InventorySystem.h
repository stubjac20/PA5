#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H

#include "HashTable.h"
#include "LinkedList.h"
#include "Product.h"
#include <string>
#include <vector>

class InventorySystem {
private:
    HashTable<std::string, Product> productTable; //lookup by ID
    HashTable<std::string, LinkedList<Product*>> categoryTable; //by category

public:
    InventorySystem();

    void addProductFromCSV(const std::string& line);
    void findProductById(const std::string& id);

    //updated listinventorybycategory for PA5
    void listInventoryByCategory(const std::string& category, const std::string& arg1 = "", const std::string& arg2 = "");
};

#endif

