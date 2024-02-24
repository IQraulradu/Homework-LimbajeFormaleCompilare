#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateA(int remainingLength);
vector<string> generateB(int remainingLength);

vector<string> generateS(int maxLength) {
    vector<string> strings;
    for (int i = 0; i <= maxLength; ++i) {
        for (const string& a : generateA(i)) {
            for (const string& b : generateB(maxLength - i)) {
                strings.push_back(a + b);
            }
        }
    }
    return strings;
}

vector<string> generateA(int remainingLength) {
    vector<string> strings;
    if (remainingLength == 0) {
        strings.push_back("");
        return strings;
    }
    
    for (const string& str : generateA(remainingLength - 1)) {
        strings.push_back("a" + str);
    }
    return strings;
}

vector<string> generateB(int remainingLength) {
    vector<string> strings;
    if (remainingLength == 0) {
        strings.push_back("");
        return strings;
    }

    for (const string& str : generateB(remainingLength - 1)) {
        strings.push_back("b" + str);
    }
    return strings;
}

int main() {
    int maxLength = 5;
    vector<string> result = generateS(maxLength);

    for (const auto& str : result) {
        cout << str << endl;
    }

    return 0;
}
