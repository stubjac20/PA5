#include "parser.h"
#include <sstream>
#include <vector>

using namespace std;

Product parseProductLine(const string& line) {
    Product p;
    stringstream ss(line);
    string token;
    int column = 0;

    //split by comma
    while (getline(ss, token, ',')) {
        switch (column) {
            case 0: p.id = token; break;
            case 1: p.name = token; break;
            case 2: p.asin = token; break;
            case 3: p.price = token; break;
            case 4: {
                if (token.empty()) {
                    p.categories.push_back("NA");
                } else {
                    stringstream catStream(token);
                    string cat;
                    while (getline(catStream, cat, '|')) {
                        p.categories.push_back(cat);
                    }
                }
                break;
            }
        }
        column++;
    }

    return p;
}
