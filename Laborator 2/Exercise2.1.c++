#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate_palindromes(int n, string str, int len) {
    if (n == 0) {
        string palindrom = str + string(str.rbegin(), str.rend());
        cout << palindrom << endl;
        return;
    }

    if (n == 1) {
        for (int i = 0; i <= 2; ++i) {
            string palindrom = str + to_string(i) + string(str.rbegin(), str.rend());
            cout << palindrom << endl;
        }
        return;
    }

    for (int i = 0; i <= 2; ++i) {
        generate_palindromes(n - 2, str + to_string(i), len);
    }
}

int main() {
    for (int len = 1; len <= 5; ++len) {
        cout << "Palindromes of length " << len << ":" << endl;
        if (len % 2 == 0) {
            generate_palindromes(len / 2, "", len);
        } else {
            generate_palindromes((len - 1) / 2, "", len);
        }
    }
    return 0;
}
