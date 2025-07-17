#include "CSVParser.h"
#include <sstream>

Product parseProductLine(const std::string& line) {
    Product p;
    std::stringstream ss(line);
    std::string temp;

    std::getline(ss, p.id, ',');
    std::getline(ss, p.name, ',');
    std::getline(ss, p.asin, ',');
    std::getline(ss, p.price, ',');

    //handle categories
    std::getline(ss, temp, ',');
    std::stringstream catStream(temp);
    std::string category;
    while (std::getline(catStream, category, '|')) {
        p.categories.push_back(category);
    }

    return p;
}
