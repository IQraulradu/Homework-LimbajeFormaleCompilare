#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> apply_rules(const vector<string>& strings) {
    vector<string> new_strings;

    for (const auto& str : strings) {
        new_strings.push_back("a" + str + "a");
        
        new_strings.push_back("b" + str + "b");
        new_strings.push_back("a");
        new_strings.push_back("b");
    }

    return new_strings;
}

int main() {
    vector<string> strings = {"S"};

    for (int i = 0; i < 3; ++i) {
        strings = apply_rules(strings);
        cout << "Iteratia " << (i + 1) << ":" << endl;
        for (const auto& str : strings) {
            cout << str << endl;
        }
    }

    return 0;
}
