#include <iostream>
#include <string>

using namespace std;

// Această metodă determină starea finală a automatului după procesarea unei secvențe de intrare.
char processInput(const string& input) {
    char state = 'A';  
    
    // Iterăm prin fiecare simbol din șirul de intrare
    for (char symbol : input) {
        switch (state) {
            case 'A':
                state = (symbol == '0') ? 'B' : 'A';
                break;
            case 'B':
                state = (symbol == '0') ? 'A' : 'B';
                break;
            default:
                cerr << "Eroare: Stare nevalidă" << endl;
                exit(EXIT_FAILURE);
        }
    }
    
    return state;
}

int main() {
    // Testăm automatul cu secvențe date 
    string inputs[] = {"010", "110", "1001"};
    
    for (const string& input : inputs) {
        cout << "Secventa \"" << input << "\": starea finală este '" << processInput(input) << "'" << endl;
    }

    return 0;
}
