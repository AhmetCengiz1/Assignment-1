// The Bohr atom - Assignment 1
// This code takes user inputs for the atomic number, initial and final 
// principal quantum number values for the initial and final state of an electrons 
// energy transition, then it outputs the energy of the transition in Joules or eV.
// Student ID: 10932388, d52799ac, 08/02/2024

#include <iostream>
#include <cmath>
#include <iomanip>

const double evtojoules = 1.602e-19; // Electron volt constant

// Sets up a validation function that can be used differently depending on the type of input it recieves
template <typename T>
T validate_input(const std::string& prompt)
{
  T value;
  while (true) 
  {
    std::cout << prompt;
    std::cin >> value;

    if (std::cin.fail() || std::cin.peek() != '\n') 
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid value.\n";
    }

    else 
    {
      break;
    }
  }
  return value;
}

double calculate_energy(int atomic_number, int initial_quantum_number, int final_quantum_number) 
{
  return 13.6 * (pow(atomic_number,2)) * (1.0 / pow(initial_quantum_number, 2) - 1.0 / pow(final_quantum_number,2));
}

int main() 
{
  //Initialise variables
  int atomic_number, initial_quantum_number, final_quantum_number;
  char unit, repeat;

do // Asks for inputs
{
  atomic_number = validate_input<int>("Enter the atomic number: ");
  do 
  {
    initial_quantum_number = validate_input<int>("Enter the initial quantum number: ");
    final_quantum_number = validate_input<int>("Enter the final quantum number: ");
    if(initial_quantum_number <= final_quantum_number)
    {
      std::cout << "Initial quantum number must be greater than the final quantum number. Please enter again.\n";
    }
    else
    {
      break;
    }
  } while(true);

    double energy = calculate_energy(atomic_number, initial_quantum_number, final_quantum_number);

  do // Asks for units 
  {
    unit = validate_input<char>("Print energy in J or eV? (J/e): ");

    if (unit == 'e' || unit == 'E') 
    {
      std::cout << "The energy of the transition is " << std::setprecision(3) << energy << " eV\n";
      break;
    } 
    else if (unit == 'j'|| unit == 'J')
    {
      energy *= evtojoules;
      std::cout << "The energy of the transition is " << std::setprecision(3) << energy << " J\n";
      break;
    }

    else 
    {
      std::cout << "Invalid input. Please enter a valid value.\n";
    }
  } 
  while (true);

    do // Asks if user wants to repeat
    {
      repeat = validate_input<char>("Repeat? (y/n): ");

      if (repeat == 'y' || repeat == 'Y' || repeat == 'n' || repeat == 'N') 
      {
        break;
      } 
      else 
      {
        std::cout << "Invalid input. Please enter a valid value. \n";
      }
    } 
    while (true); // Loops until there is a valid input 

  } 
  while (repeat == 'y' || repeat == 'Y'); // Loops while the repeat is still y/Y

  return 0;
}
