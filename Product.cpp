#include "Product.h"
#include <iostream>

void Product::print() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "ASIN: " << asin << endl;
    cout << "Price: " << price << endl;
    cout << "Categories: ";
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << categories[i];
        if (i != categories.size() - 1) cout << " | ";
    }
    cout << endl;
}
