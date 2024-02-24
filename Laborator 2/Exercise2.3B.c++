#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateX(int maxLength);
vector<string> generateY(int maxLength);
vector<string> generateZ(int maxLength);

vector<string> generateS(int maxLength) {
    return generateX(maxLength);
}

vector<string> generateX(int maxLength) {
    vector<string> strings;
    if (maxLength <= 0) return strings;

    for (auto& str : generateY(maxLength - 1)) {
        strings.push_back("0" + str);
    }
    for (auto& str : generateZ(maxLength - 1)) {
        strings.push_back("1" + str);
    }

    return strings;
}

vector<string> generateY(int maxLength) {
    vector<string> strings;
    if (maxLength <= 0) return strings;

    if (maxLength >= 1) strings.push_back("2");
    for (auto& str : generateX(maxLength - 1)) {
        strings.push_back(str);
    }

    return strings;
}

vector<string> generateZ(int maxLength) {
    vector<string> strings;
    if (maxLength <= 0) return strings;

    if (maxLength >= 1) {
        strings.push_back("3");
        strings.push_back("4");
    }
    for (auto& str : generateX(maxLength - 1)) {
        strings.push_back(str);
    }

    return strings;
}

int main() {
    int maxLength = 5; 
    vector<string> result = generateS(maxLength);

    for (auto& str : result) {
        cout << str << endl;
    }

    return 0;
}
