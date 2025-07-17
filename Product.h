#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
using namespace std;

struct Product {
    string id;
    string name;
    string asin;
    string price;
    vector<string> categories;

    void print() const; // just declare it here
};

#endif

