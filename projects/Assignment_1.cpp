#include <iostream>

const double eVtojoules = 1.602e-19; // Electron volt constant

double calculateEnergy(int atmoic_number, int initial_quantum_number, int final_quantum_number) {
    return 13.6 * atmoic_number * atmoic_number * (1 / (initial_quantum_number * initial_quantum_number) - 1 / (final_quantum_number * final_quantum_number));
}

int main() {
    int atmoic_number, initial_quantum_number, final_quantum_number;
    char unit, repeat;

    do {
        std::cout << "Enter the atomic number: ";
        std::cin >> atmoic_number;

        std::cout << "Enter the initial quantum number: ";
        std::cin >> initial_quantum_number;

        std::cout << "Enter the final quantum number: ";
        std::cin >> final_quantum_number;

        std::cout << "Print energy in J or eV? (J/e): ";
        std::cin >> unit;

        double energy = calculateEnergy(atmoic_number, initial_quantum_number, final_quantum_number);

        if (unit == 'e' || unit == 'E') {
            std::cout << "The energy of the transition is " << energy << " eV\n";
        } else {
            energy * eVtojoules;
            std::cout << "The energy of the transition is " << energy << " J\n";
        }

        std::cout << "Repeat? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
