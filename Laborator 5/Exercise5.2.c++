#include <iostream>
#include <map>
#include <string>

using namespace std;

// Definirea tipului de automat Moore
class MooreMachine {
private:
    enum State { S1, S2 }; // Stările automatei
    State currentState; 

    // Tabelul de tranziții
    map<pair<State, char>, State> transitionTable{
        {{S1, 'A'}, S1},
        {{S1, 'B'}, S2},
        {{S2, 'A'}, S1},
        {{S2, 'B'}, S2}
    };

    // Funcția care determină ieșirea pe baza stării curente
    string output(State state) {
        switch(state) {
            case S1: return "O1";
            case S2: return "O2";
        }
        return "";
    }

public:
    // Constructorul inițializează starea curentă la S1
    MooreMachine() : currentState(S1) {}

    // Procesează o intrare și returnează ieșirea corespunzătoare
    string processInput(char input) {
        currentState = transitionTable[{currentState, input}];
        return output(currentState);
    }

    // Afisează tabelul de tranziție
    void displayTransitionTable() {
        cout << "Tabelul de tranziție pentru mașina Moore:" << endl;
        cout << "Stare curentă, Intrare -> Stare următoare, Ieșire" << endl;
        for (const auto& entry : transitionTable) {
            cout << "S" << entry.first.first + 1 << ", " << entry.first.second << " -> "
                 << "S" << entry.second + 1 << ", " << output(entry.second) << endl;
        }
    }
};

int main() {
    MooreMachine moore;

    // Afișăm tabelul de tranziție
    moore.displayTransitionTable();

    // Procesăm o serie de intrări și afișăm ieșirile
    string inputs = "ABABABA";
    cout << "Procesăm intrările: " << inputs << endl;
    cout << "Ieșirile sunt: ";
    for (char input : inputs) {
        cout << moore.processInput(input) << " ";
    }
    cout << endl;

    return 0;
}
