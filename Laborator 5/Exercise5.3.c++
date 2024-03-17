#include <iostream>
#include <map>
#include <string>

using namespace std;

// Definirea tipului de automat Mealy
class MealyMachine {
private:
    enum State { Q1, Q2 }; // Stările automatei
    State currentState; // Starea curentă a automatei

    // Structura pentru a defini ieșirea și starea următoare
    struct TransitionOutput {
        State nextState;
        string output;
    };

    // Tabelul de tranziții
    map<pair<State, char>, TransitionOutput> transitionTable;

public:
    // Constructorul inițializează starea curentă la Q1 și tabelul de tranziții
    MealyMachine() : currentState(Q1) {
        // Inițializăm manual tranzițiile
        transitionTable[{Q1, 'X'}] = {Q2, "O1"};
        transitionTable[{Q1, 'Y'}] = {Q1, "O1"};
        transitionTable[{Q2, 'X'}] = {Q1, "O2"};
        transitionTable[{Q2, 'Y'}] = {Q2, "O2"};
    }

    // Procesează o intrare și returnează ieșirea corespunzătoare
    string processInput(char input) {
        if (transitionTable.find({currentState, input}) != transitionTable.end()) {
            TransitionOutput transition = transitionTable[{currentState, input}];
            currentState = transition.nextState;
            return transition.output;
        }
        return "Intrare invalida";
    }

    // Afisează tabelul de tranziție
    void displayTransitionTable() {
        cout << "Tabelul de tranziție și de ieșire pentru mașina Mealy:" << endl;
        cout << "Stare curentă, Intrare -> Stare următoare, Ieșire" << endl;
        for (const auto& entry : transitionTable) {
            cout << "Q" << entry.first.first + 1 << ", " << entry.first.second << " -> "
                 << "Q" << entry.second.nextState + 1 << ", " << entry.second.output << endl;
        }
    }
};

int main() {
    MealyMachine mealy;

    // Afișăm tabelul de tranziție și de ieșire
    mealy.displayTransitionTable();

    // Procesăm o serie de intrări și afișăm ieșirile
    string inputs = "XYXYX";
    cout << "Procesăm intrările: " << inputs << endl;
    cout << "Ieșirile sunt: ";
    for (char input : inputs) {
        cout << mealy.processInput(input) << " ";
    }
    cout << endl;

    return 0;
}
