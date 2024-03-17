#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

    // Mapează o stare și un caracter la un set de stări următoare
class NFA {
    map<pair<int, char>, set<int>> transitions;
    // Starea de început și stările finale
    int startState;
    set<int> acceptStates;

public:
    // Constructor pentru NFA
    NFA(int start, initializer_list<int> accepts) : startState(start), acceptStates(accepts) {}

    // Adaugă o tranziție de la o stare la alta pe un caracter specific
    void addTransition(int from, char input, int to) {
        transitions[{from, input}].insert(to);
    }

    // Verifică dacă un șir este acceptat de NFA
    bool accepts(const string& input) {
        // Inițializăm un set de stări curente care conține doar starea de start
        set<int> currentStates = { startState };
        for (char c : input) { // Pentru fiecare caracter din șir
            set<int> nextStates;
            for (int state : currentStates) { // Pentru fiecare stare curentă
                // Adăugăm toate stările următoare în funcție de caracterul actual
                auto it = transitions.find({state, c});
                if (it != transitions.end()) {
                    nextStates.insert(it->second.begin(), it->second.end());
                }
            }
            currentStates = move(nextStates); // Actualizăm stările curente
        }
        // Verificăm dacă stările curente conțin cel puțin o stare finală
        for (int state : currentStates) {
            if (acceptStates.count(state)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    NFA nfa(0, {4}); 

    //Tranzițiile 
    nfa.addTransition(0, 'a', 1);
    nfa.addTransition(1, 'a', 1);
    nfa.addTransition(1, 'b', 2);
    nfa.addTransition(2, 'a', 3);
    nfa.addTransition(2, 'b', 2);
    nfa.addTransition(3, 'a', 4);
    
    // Testăm automatul cu diferite șiruri
    cout << "String 'aa' is " << (nfa.accepts("aa") ? "accepted" : "not accepted") << endl;
    cout << "String 'aab' is " << (nfa.accepts("aab") ? "accepted" : "not accepted") << endl;
    cout << "String 'aaba' is " << (nfa.accepts("aaba") ? "accepted" : "not accepted") << endl;
    cout << "String 'abba' is " << (nfa.accepts("abba") ? "accepted" : "not accepted") << endl;
    return 0;
}
