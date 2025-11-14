// Power function in O(logn) time complexity

#include <iostream>
using namespace std;

int power(int x, int y) {
    int result = 1;
    
    while (y > 0) {
        if (y % 2 == 1) {
            result *= x;
        }
        x = x * x;   // square base
        y = y / 2;   // halve exponent
    }
    
    return result;
}

int main() {
    int num, exp, outcome;

    cout << "Input the base number: ";
    cin >> num;
    cout << "Input the exponent: ";
    cin >> exp;

    outcome = power(num, exp);

    cout << "Power calculation result: " << num << "^" << exp << " = " << outcome << endl;

    return 0;
}
