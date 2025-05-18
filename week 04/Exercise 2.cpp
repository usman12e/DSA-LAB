#include <iostream>
#include "Example 2.h"  
using namespace std;

int main() {
    Que<string> Q1(10);
    string names[] = { "Ahmed", "Usman", "Ali", "Umer", "Umar", "Faseeh", "Hamza", "Rayyan", "Ukasha", "Saim" };

    
    for (int i = 0; i < 10; i++) {
        Q1.Insert(names[i]);
    }

    
    string name;
    cout << "Removed names from the queue:\n";
    for (int i = 0; i < 10; i++) {
        Q1.Remove(name);
        cout << name << endl;
    }

    return 0;
}
