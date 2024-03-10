#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

// Definim o nouă structură pentru a reprezenta o stare și un caracter de intrare pentru funcția de tranziție
typedef pair<int, char> StateInputPair;

class NFA {
private:
    set<int> acceptingStates; // Stările de acceptare
    map<StateInputPair, set<int>> transitionFunction; // Funcția de tranziție

public:
    NFA() {
        acceptingStates.insert(1);

        transitionFunction[{0, 'a'}].insert(2);
        transitionFunction[{0, 'b'}].insert(3);
        transitionFunction[{2, 'a'}].insert(1);
        transitionFunction[{2, 'b'}].insert(2);
        transitionFunction[{3, 'a'}].insert(3);
        transitionFunction[{3, 'b'}].insert(1);
    }

    // Metodă pentru a verifica dacă un șir este acceptat de NFA
    bool isAccepted(const string& input) {
        // Începem de la starea inițială 0
        set<int> currentStates = {0};

        // Procesăm fiecare caracter din șir
        for (char symbol : input) {
            set<int> nextStates;
            for (int state : currentStates) {
                // Adăugăm toate stările posibile în urma tranziției
                nextStates.insert(transitionFunction[{state, symbol}].begin(), transitionFunction[{state, symbol}].end());
            }
            currentStates = nextStates; // Actualizăm stările curente
        }

        // Verificăm dacă vreo stare curentă este o stare de acceptare
        for (int state : currentStates) {
            if (acceptingStates.count(state) > 0) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    NFA automaton;

    vector<string> testStrings = {"ab", "aab", "bb", "bba"};
    for (const string& testString : testStrings) {
        cout << "Șirul \"" << testString << "\" este "
             << (automaton.isAccepted(testString) ? "acceptat" : "respins") << ".\n";
    }

    return 0;
}
