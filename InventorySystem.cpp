#include "InventorySystem.h"
#include "parser.h"
#include "sorts.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

InventorySystem::InventorySystem() {
    //nothing here
}

void InventorySystem::addProductFromCSV(const string& line) {
    Product p = parseProductLine(line);

    //add to product table
    productTable.insert(p.id, p);

    //add pointer to category lists
    for (const string& cat : p.categories) {
        LinkedList<Product*>* categoryList = categoryTable.get(cat);
        if (categoryList == nullptr) {
            LinkedList<Product*> newList;
            newList.insertBack(productTable.get(p.id));
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

//list inventory by category, optionally sorted with flags
void InventorySystem::listInventoryByCategory(const string& category, const string& arg1, const string& arg2) {
    LinkedList<Product*>* list = categoryTable.get(category);
    if (list == nullptr) {
        cout << "Bad Category" << endl;
        return;
    }

    //copy to vector so we can sort it
    vector<Product*> products;
    auto it = list->iterator();
    while (it.hasNext()) {
        products.push_back(it.next());
    }

    //figure sort mode
    string sortType = "insert";
    string sortOrder = "asc";

    if (arg1 == "desc") {
        sortOrder = "desc";
    } else if (arg1 == "merge") {
        sortType = "merge";
    }

    if (arg1 == "merge" && arg2 == "desc") {
        sortOrder = "desc";
    }

    //define comparators
    auto ascending = [](Product* a, Product* b) {
        return stof(a->price) < stof(b->price);
    };

    auto descending = [](Product* a, Product* b) {
        return stof(a->price) > stof(b->price);
    };

    if (sortType == "insert") {
        if (sortOrder == "asc") {
            insertionSort(products, ascending);
        } else {
            insertionSort(products, descending);
        }
    } else if (sortType == "merge") {
        if (sortOrder == "asc") {
            mergeSort(products, ascending);
        } else {
            mergeSort(products, descending);
        }
    }

    //print result
    for (Product* p : products) {
        cout << p->id << " - " << p->name << " ($" << p->price << ")" << endl;
    }
}
