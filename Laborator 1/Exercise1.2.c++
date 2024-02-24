#include <iostream>
#include <string>
using namespace std;

// Operația de concatenare
string concatenate(const string& s1, const string& s2) {
    return s1 + s2;
}

// Operația de repetare
string repeat(const string& s, int n) {
    string result;
    for (int i = 0; i < n; ++i) {
        result += s;
    }
    return result;
}

// Operația de inversare
string reverse(const string& s) {
    return string(s.rbegin(), s.rend());
}

// Operația de extracție
string extract(const string& s, int i, int j) {
    if (i < 0 || j >= s.size() || i > j) 
    return "";
    return s.substr(i, j - i + 1);
}

// Operația de înlocuire
string replace(const string& s, const string& sub, const string& new_sub) {
    size_t pos = s.find(sub);
    if (pos == string::npos) return s; // Subsecvența nu a fost găsită
    return s.substr(0, pos) + new_sub + s.substr(pos + sub.length());
}

int main() {
    string s1 = "abc";
    string s2 = "xyz";
    
    cout << "Concatenare: " << concatenate(s1, s2) << endl;
    cout << "Repetare: " << repeat(s1, 3) << endl;
    cout << "Inversare: " << reverse(s1) << endl;
    cout << "Extracție: " << extract(s1, 1, 2) << endl;
    cout << "Înlocuire: " << replace(s1, "bc", "yz") << endl;

    return 0;
}
