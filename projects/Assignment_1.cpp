#include <iostream>

const double eVtojoules = 1.602e-19; // Electron volt constant

double calculateEnergy(int atomic_number, int initial_quantum_number, int final_quantum_number) {
    return 13.6 * atomic_number * atomic_number * (1 / (initial_quantum_number * initial_quantum_number) - 1 / (final_quantum_number * final_quantum_number));
}

int main() {
    int atomic_number, initial_quantum_number, final_quantum_number;
    char unit, repeat;

    do {
        std::cout << "Enter the atomic number: ";
        std::cin >> atomic_number;

        std::cout << "Enter the initial quantum number: ";
        std::cin >> initial_quantum_number;

        std::cout << "Enter the final quantum number: ";
        std::cin >> final_quantum_number;

        double energy = calculateEnergy(atomic_number, initial_quantum_number, final_quantum_number);

        do {
            std::cout << "Print energy in J or eV? (J/e): ";
            std::cin >> unit;

            if (unit == 'e' || unit == 'E') {
                std::cout << "The energy of the transition is " << energy << " eV\n";
                break;
            } else if (unit == 'j'|| unit == 'J'){
                energy *= eVtojoules;
                std::cout << "The energy of the transition is " << energy << " J\n";
                break;
            }
            else {
                std::cout << "Please enter a valid choice \n";
            }
        } while (true);

        do {
1            std::cout << "Repeat? (y/n): ";
            std::cin >> repeat;

            if (repeat == 'y' || repeat == 'Y' || repeat == 'n' || repeat == 'N') {
                break;
            } else {
                std::cout << "Please enter a valid choice \n";
            }
        } while (true);

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
