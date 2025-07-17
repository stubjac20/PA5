// InventorySystem.cpp

#include "InventorySystem.h"
#include "parser.h"
#include <iostream>
using namespace std;

InventorySystem::InventorySystem() {
    //nothing
}

void InventorySystem::addProductFromCSV(const string& line) {
    Product p = parseProductLine(line);

    //add by ID
    productTable.insert(p.id, p);

    //add to all category buckets
    for (const string& cat : p.categories) {
        LinkedList<Product*>* categoryList = categoryTable.get(cat);
        if (categoryList == nullptr) {
            LinkedList<Product*> newList;
            newList.insertBack(productTable.get(p.id)); 

 //get pointer
            categoryTable.insert(cat, newList);
        } else {
            categoryList->insertBack(productTable.get(p.id)); 

        }
    }
}

void InventorySystem::findProductById(const string& id) {
    Product* p = productTable.get(id);
    if (p != nullptr) {
        p->print();
    } else {
        cout << "Product not found" << endl;
    }
}

void InventorySystem::listInventoryByCategory(const string& category) {
    LinkedList<Product*>* list = categoryTable.get(category);
    if (list == nullptr) {
        cout << "Bad Category" << endl;
        return;
    }

    auto it = list->iterator();
    while (it.hasNext()) {
        Product* p = it.next();
        cout << p->id << " - " << p->name << endl;
    }
}
