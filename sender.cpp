#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0;
}

int main()
{
    string data;

    cout << "Enter data word: ";
    cin >> data;

    int m = data.length();
    int r = 0;

    // Find number of parity bits
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    int n = m + r;

    int code[100] = {0};

    // ------------------------------------------------
    // Put data bits in Ma'am's format
    // Position: n ... 1
    // Parity positions: 1, 2, 4, 8...
    // ------------------------------------------------

    int j = 0;

    for (int i = n; i >= 1; i--)
    {
        if (!isPowerOfTwo(i))
        {
            code[i] = data[j] - '0';
            j++;
        }
    }

    // ------------------------------------------------
    // Calculate parity bits
    // Even parity
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

        // Even parity
        if (count % 2 == 0)
            code[p] = 0;
        else
            code[p] = 1;
    }

    // ------------------------------------------------
    // Display
    // ------------------------------------------------

    cout << "\nNumber of data bits = " << m << endl;
    cout << "Number of parity bits = " << r << endl;
    cout << "Total bits = " << n << endl;

    cout << "\nParity Bits:" << endl;

    for (int p = 1; p <= n; p = p * 2)
    {
        cout << "R" << p << " = " << code[p] << endl;
    }

    cout << "\nPosition: ";

    for (int i = n; i >= 1; i--)
    {
        cout << i << " ";
    }

    cout << "\nCodeword: ";

    for (int i = n; i >= 1; i--)
    {
        cout << code[i] << " ";
    }

    cout << "\n\nHamming Codeword = ";

    for (int i = n; i >= 1; i--)
    {
        cout << code[i];
    }

    cout << endl;

    return 0;
}
        





































































































































    