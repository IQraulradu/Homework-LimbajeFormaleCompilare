#include <iostream>
#include <vector>

using namespace std;

class ParkingAutomaton {
private:
    vector<bool> parkingSpots; // Vector pentru a reprezenta locurile de parcare; true pentru ocupat, false pentru liber

public:
    // Constructor care inițializează parcare cu un număr dat de locuri libere
    ParkingAutomaton(int numSpots) : parkingSpots(numSpots, false) {}

    // Încearcă să parcheze o mașină în cel mai apropiat loc liber
    bool parkCar() {
        for (int i = 0; i < parkingSpots.size(); ++i) {
            if (!parkingSpots[i]) { // Dacă locul este liber
                parkingSpots[i] = true; // Parchează mașina
                cout << "Masina a fost parcata in locul " << i + 1 << ".\n";
                return true;
            }
        }
        cout << "Nu mai sunt locuri libere de parcare.\n";
        return false; // Parcarea este plină
    }

    // Încearcă să scoată o mașină din parcare de la un loc specific
    bool leaveParking(int spotNumber) {
        if (spotNumber - 1 < parkingSpots.size() && parkingSpots[spotNumber - 1]) { // Verifică dacă locul este ocupat
            parkingSpots[spotNumber - 1] = false; // Eliberează locul
            cout << "Masina a parasit locul de parcare " << spotNumber << ".\n";
            return true;
        }
        cout << "Locul de parcare " << spotNumber << " este deja liber sau nu exista.\n";
        return false; // Locul este deja liber sau nu există
    }

    void displayParkingState() {
        cout << "Starea locurilor de parcare: ";
        for (bool spot : parkingSpots) {
            cout << (spot ? "Ocupat " : "Liber ");
        }
        cout << endl;
    }

    // Returnează numărul de locuri de parcare libere
    int getAvailableSpots() {
        int freeCount = 0;
        for (bool spot : parkingSpots) {
            if (!spot) freeCount++;
        }
        return freeCount;
    }
};

int main() {
    ParkingAutomaton automaton(5); 

    automaton.parkCar(); 
    automaton.parkCar(); 
    automaton.leaveParking(1); 
    automaton.displayParkingState();
    cout << "Locuri de parcare disponibile: " << automaton.getAvailableSpots() << endl; 

    return 0;
}
