#include "parser.h"
#include <sstream>
#include <vector>

using namespace std;

Product parseProductLine(const string& line) {
    Product p;
    stringstream ss(line);
    string token;
    int col = 0;

    while (getline(ss, token, ',')) {
        switch (col) {
            case 0: p.id = token; break;            //Uniq Id
            case 1: p.name = token; break;          //Product Name
            case 3: p.asin = token; break;          //ASIN
            case 7: p.price = token; break;         //Selling Price
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
            default: break;
        }
        col++;
        if (col > 7) break; //stop early
    }

    return p;
}

