#include <iostream>
using namespace std;

int main() {
    int var = 20;  // actual variable declaration
    int* ptr;  // pointer variable declaration

    ptr = &var;  // store address of var in pointer variable

    cout << "Value of var: " << var << endl;
    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Value of *ptr: " << *ptr << endl;

    return 0;
}
