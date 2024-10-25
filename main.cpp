#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <json/json.h> 


long long decodeValue(int base, const std::string& value) {
    return std::stoll(value, nullptr, base);
}
double lagrangeInterpolation(const std::vector<std::pair<int, long long>>& points) {
    double c = 0;
    int k = points.size();

    for (int i = 0; i < k; i++) {
        int xi = points[i].first;
        long long yi = points[i].second;

        double li = 1;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                int xj = points[j].first;
                li *= (0.0 - xj) / (xi - xj);
            }
        }
        c += yi * li;
    }
    return c;
}
void findConstantTerm(const std::string& filePath) {
    std::ifstream file(filePath);
    Json::Value data;
    file >> data;

    int n = data["keys"]["n"].asInt();
    int k = data["keys"]["k"].asInt();

    std::vector<std::pair<int, long long>> points;
    for (int i = 1; i <= n; i++) {
        std::string index = std::to_string(i);
        if (data.isMember(index)) {
            int x = i;
            int base = std::stoi(data[index]["base"].asString());
            std::string value = data[index]["value"].asString();
            long long y = decodeValue(base, value);
            points.push_back({x, y});
        }
    }

    std::vector<std::pair<int, long long>> selectedPoints(points.begin(), points.begin() + k);


    double constantTerm = lagrangeInterpolation(selectedPoints);

    std::cout << "Constant term (c): " << constantTerm << std::endl;
}

int main() {
    findConstantTerm("input.json"); 
    return 0;
}
