#include <iostream>

using namespace std;

int main()
{
    int totalFrames, frame = 1;
    char acknowledgement;

    cout << "Enter total number of frames (1 to 10): ";
    cin >> totalFrames;

    if (totalFrames < 1 || totalFrames > 10)
    {
        cout << "Please enter a number between 1 and 10.";
        return 0;
    }

    while (frame <= totalFrames)
    {
        cout << "\nTransmitting Frame " << frame << "..." << endl;

        cout << "Acknowledgement received? (y/n): ";
        cin >> acknowledgement;

        if (acknowledgement == 'y' || acknowledgement == 'Y')
        {
            cout << "Acknowledgement received for Frame "
                 << frame << endl;

            frame++;
        }
        else if (acknowledgement == 'n' || acknowledgement == 'N')
        {
            cout << "Acknowledgement not received!" << endl;
            cout << "Retransmitting Frame " << frame << "..." << endl;
        }
        else
        {
            cout << "Invalid input! Enter y or n." << endl;
        }
    }

    cout << "\nAll frames have been transmitted successfully." << endl;

    return 0;
}
