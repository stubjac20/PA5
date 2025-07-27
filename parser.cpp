#include "parser.h"
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

static string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n\"");
    size_t end = s.find_last_not_of(" \t\r\n\"");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

Product parseProductLine(const string& line) {
    Product p;
    stringstream ss(line);
    string token;
    int col = 0;

    while (getline(ss, token, ',')) {
        token = trim(token);

        switch (col) {
            case 0: p.id = token; break;            //Uniq Id
            case 1: p.name = token; break;          //Product Name
            case 3: p.asin = token; break;          //ASIN
            case 4: {
                if (token.empty()) {
                    p.categories.push_back("NA");
                } else {
                    stringstream catStream(token);
                    string cat;
                    while (getline(catStream, cat, '|')) {
                        cat = trim(cat);
                        if (!cat.empty())
                            p.categories.push_back(cat);
                    }
                }
                break;
            }
            case 7: p.price = token; break;         //Selling Price
        }

        col++;
        if (col > 7) break;
    }

    return p;
}
