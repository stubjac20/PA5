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
        //manually trim leading/trailing spaces and quotes
        while (!token.empty() && (token.front() == ' ' || token.front() == '\t' || token.front() == '"'))
            token.erase(token.begin());
        while (!token.empty() && (token.back() == ' ' || token.back() == '\t' || token.back() == '"'))
            token.pop_back();

        switch (col) {
            case 0: p.id = token; break;
            case 1: p.name = token; break;
            case 3: p.asin = token; break;
            case 4: {
                if (token.empty()) {
                    p.categories.push_back("NA");
                } else {
                    stringstream catStream(token);
                    string cat;
                    while (getline(catStream, cat, '|')) {
                        //trim each category
                        while (!cat.empty() && (cat.front() == ' ' || cat.front() == '\t' || cat.front() == '"'))
                            cat.erase(cat.begin());
                        while (!cat.empty() && (cat.back() == ' ' || cat.back() == '\t' || cat.back() == '"'))
                            cat.pop_back();
                        if (!cat.empty()) p.categories.push_back(cat);
                    }
                }
                break;
            }
            case 7: p.price = token; break;
        }

        col++;
        if (col > 7) break;
    }

    return p;
}

