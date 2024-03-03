#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

bool verify_invoice_format(const string& invoice_data) {
    regex invoice_regex(R"(ID Client: \w+, Produs: [\w\s]+, Pret: \d+(\.\d{1,2})?, TVA: \d+(\.\d{1,2})?, Cantitate: \d+)");
    
    // Verificăm dacă datele din factura se potrivesc cu expresia regulată
    return regex_match(invoice_data, invoice_regex);
}

// Funcția citește fișierul text și verifică formatul fiecărei linii.
void read_and_verify_file(const string& file_path) {
    ifstream file(file_path);
    string line;
    bool format_correct = true;
    
    // Verificăm dacă fișierul a fost deschis cu succes
    if (file.is_open()) {
        // Citim fiecare linie din fișier și verificăm formatul
        while (getline(file, line)) {
            if (!verify_invoice_format(line)) {
                cout << "Eroare de format în linia: " << line << endl;
                format_correct = false;
            }
        }
        file.close();
        
        // Dacă toate liniile sunt corecte, afișăm un mesaj corespunzător
        if (format_correct) {
            cout << "Toate liniile respectă formatul specificat." << endl;
        }
    } else {
        cout << "Fișierul nu a putut fi deschis." << endl;
    }
}

int main() {
    // Calea predefinită către fișier
    string file_path = "./facturi.txt";
    
    read_and_verify_file(file_path);
    
    return 0;
}
