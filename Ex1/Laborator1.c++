#include <iostream>
#include <string>
using namespace std;

// Operația de concatenare
string concatenate(const string& s1, const string& s2) {
    return s1 + s2;
}

// Operația de inversare
string invers(const string& s) {
    string reversed = string(s.rbegin(), s.rend());
    return reversed;
}

// Operația de substituție
string substituie(const string& s, char a, char b) {
    string result = s;
    for (char& c : result) {
        if (c == a) c = b;
    }
    return result;
}

// Operația de lungime
size_t lungime(const string& s) {
    return s.length();
}

int main() {
    
    string s1 = "abc";
    string s2 = "xyz";
    cout << "Concatenare: " << concatenate(s1, s2) << endl;
    cout << "Invers: " << invers(s1) << endl;
    cout << "Substituie: " << substituie(s1, 'a', 'x') << endl;
    cout << "Lungime: " << lungime(s1) << endl;

    return 0;
}