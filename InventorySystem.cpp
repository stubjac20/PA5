#include "InventorySystem.h"
#include "parser.h"
#include "sorts.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

InventorySystem::InventorySystem() {}

InventorySystem::~InventorySystem() {
    for (int i = 0; i < categoryTable.size(); ++i) {
        auto bucket = categoryTable.getBucketArray()[i].iterator();
        while (bucket.hasNext()) {
            auto& entry = bucket.next();
            delete entry.second;
        }
    }
}

void InventorySystem::addProductFromCSV(const string& line) {
    Product p = parseProductLine(line);
    productTable.insert(p.id, p);

    for (const string& cat : p.categories) {
        cout << "CATEGORY: [" << cat << "]" << endl;
        LinkedList<Product*>** listPtr = categoryTable.get(cat);
        if (listPtr == nullptr) {
            LinkedList<Product*>* newList = new LinkedList<Product*>();
            newList->insertBack(productTable.get(p.id));
            categoryTable.insert(cat, newList);
        } else {
            (*listPtr)->insertBack(productTable.get(p.id));
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

void InventorySystem::listInventoryByCategory(const string& category, const string& arg1, const string& arg2) {
    LinkedList<Product*>** listPtr = categoryTable.get(category);
    if (listPtr == nullptr) {
        cout << "Bad Category" << endl;
        return;
    }

    LinkedList<Product*>* list = *listPtr;

    vector<Product*> products;
    auto it = list->iterator();
    while (it.hasNext()) {
        products.push_back(it.next());
    }

    string sortType = "insert";
    string sortOrder = "asc";

    if (arg1 == "desc") sortOrder = "desc";
    else if (arg1 == "merge") sortType = "merge";

    if (arg1 == "merge" && arg2 == "desc") sortOrder = "desc";

    auto asc = [](Product* a, Product* b) { return stof(a->price) < stof(b->price); };
    auto desc = [](Product* a, Product* b) { return stof(a->price) > stof(b->price); };

    if (sortType == "insert") {
        if (sortOrder == "asc") insertionSort(products, asc);
        else insertionSort(products, desc);
    } else {
        if (sortOrder == "asc") mergeSort(products, asc);
        else mergeSort(products, desc);
    }

    for (Product* p : products) {
        cout << p->id << " - " << p->name << " ($" << p->price << ")" << endl;
    }
}

