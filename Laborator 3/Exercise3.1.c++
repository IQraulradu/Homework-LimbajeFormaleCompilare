#include <iostream>
#include <string>

using namespace std;

// Definirea stărilor mașinii de stări finite
enum State {
    
    /*
    Initial = Starea q0 - starea inițială
    coffee_selected = Starea q1 - cafeaua a fost selectată
    tea_selected = Starea q2 - ceaiul a fost selectat
    cappuccino = Starea q3 - cappuccino-ul a fost selectat
    hot_chocolate = Starea q4 - ciocolata caldă a fost selectată
    final = Starea q4 - starea finală
    */
    INITIAL, 
    COFFEE_SELECTED, 
    TEA_SELECTED, 
    CAPPUCCINO_SELECTED, 
    HOT_CHOCOLATE_SELECTED, 
    FINAL 
};

// Declararea funcțiilor
void print_menu();
State handle_selection(State current_state, char selection);

int main() {
    State current_state = INITIAL;
    char selection = ' ';
    
    // Simulare a mașina de stări finite
    while (true) {
        print_menu();
        cin >> selection;
        
        // Gestionarea selecției utilizatorului
        current_state = handle_selection(current_state, selection);
        
        // Dacă starea finală este atinsă, băutura este eliberată și mașina se resetează
        if (current_state == FINAL) {
            cout << "Savurați băutura! Aparatul se resetează..." << endl;
            current_state = INITIAL;
        }
    }
    
    return 0;
}

void print_menu() {
    cout << "Vă rog să selectați o băutură:" << endl;
    cout << "C - Cafea" << endl;
    cout << "T - Ceai" << endl;
    cout << "A - Cappuccino" << endl;
    cout << "H - Ciocolată Caldă" << endl;
    cout << "OK - Confirmați selecția" << endl;
    cout << "Selecția: ";
}

// Această funcție gestionează selecția utilizatorului și actualizează starea mașinii
State handle_selection(State current_state, char selection) {
    switch (current_state) {
        case INITIAL:
            // Aici se gestionează starea inițială și selecția băuturii
            switch (selection) {
                case 'C': return COFFEE_SELECTED;
                case 'T': return TEA_SELECTED;
                case 'A': return CAPPUCCINO_SELECTED;
                case 'H': return HOT_CHOCOLATE_SELECTED;
                default: cout << "Selecție invalidă. Încercați din nou." << endl; return INITIAL;
            }
        case COFFEE_SELECTED:
        case TEA_SELECTED:
        case CAPPUCCINO_SELECTED:
        case HOT_CHOCOLATE_SELECTED:
            // Aici se gestionează confirmarea selecției băuturii
            if (selection == 'OK') {
                cout << "Selecția a fost confirmată." << endl;
                return FINAL;
            } else {
                cout << "Apăsați 'OK' pentru a confirma selecția." << endl;
                return current_state;
            }
        default:
            return INITIAL;
    }
}
