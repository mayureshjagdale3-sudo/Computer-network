#include <iostream>
#include <string>
using namespace std;

int main() {
    string input, output = "";
    int count = 0;

    cout << "Enter 20-bit input: ";
    cin >> input;

    for (char bit : input) {
        output += bit;

        if (bit == '1') {
            count++;
            if (count == 5) {
                output += '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    cout << "Bit Stuffed Output: " << output << endl;

    return 0;
}