#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0;
}

int main()
{
    string received;

    cout << "Enter received codeword: ";
    cin >> received;

    int n = received.length();

    int code[100] = {0};

    // ------------------------------------------------
    // Store received codeword
    //
    // Input is written from left to right as:
    // Position n ... 3 2 1
    //
    // So rightmost bit = position 1
    // ------------------------------------------------

    for (int i = 1; i <= n; i++)
    {
        code[i] = received[n - i] - '0';
    }

    int errorPosition = 0;

    cout << "\nParity Check:" << endl;

    // ------------------------------------------------
    // Check R1, R2, R4, R8...
    // ------------------------------------------------

    for (int p = 1; p <= n; p = p * 2)
    {
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & p)
            {
                count = count + code[i];
            }
        }

        // Even parity check
        if (count % 2 == 0)
        {
            cout << "R" << p << " = 0" << endl;
        }
        else
        {
            cout << "R" << p << " = 1" << endl;

            // Add parity position to error position
            errorPosition = errorPosition + p;
        }
    }

    // ------------------------------------------------
    // Display error position
    // ------------------------------------------------

    cout << "\nDecimal equivalent = "
         << errorPosition << endl;

    if (errorPosition == 0)
    {
        cout << "No error detected." << endl;

        cout << "Correct codeword = ";

        for (int i = n; i >= 1; i--)
        {
            cout << code[i];
        }

        cout << endl;
    }
    else
    {
        cout << "Error is located at "
             << errorPosition
             << "th position." << endl;

        // ------------------------------------------------
        // Invert the error bit
        // 0 -> 1
        // 1 -> 0
        // ------------------------------------------------

        if (code[errorPosition] == 0)
            code[errorPosition] = 1;
        else
            code[errorPosition] = 0;

        cout << "After correcting the error:" << endl;

        cout << "Correct codeword = ";

        for (int i = n; i >= 1; i--)
        {
            cout << code[i];
        }

        cout << endl;
    }

    // ------------------------------------------------
    // Extract original data
    // Ignore parity positions 1,2,4,8...
    // ------------------------------------------------

    cout << "Original data = ";

    for (int i = n; i >= 1; i--)
    {
        if (!isPowerOfTwo(i))
        {
            cout << code[i];
        }
    }

    cout << endl;

    return 0;
}