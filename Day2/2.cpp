#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int getSmallest(int a, int b, int c)
{
    int smallest = a;
    if (b < smallest)
    {
        smallest = b;
    }
    if (c < smallest)
    {
        smallest = c;
    }

    return smallest;
}

int getPaperNeeds(int length, int width, int height)
{
    int sideA = length * width;
    int sideB = width * height;
    int sideC = height * length;
    int smallest = getSmallest(sideA, sideB, sideC);

    return 2 * sideA + 2 * sideB + 2 * sideC + smallest;
}

int getRibbonLength(int a, int b, int c)
{
    int smaller1;
    int smaller2;
    int biggest;

    if (a > b && a > c)
    {
        biggest = a;
        smaller1 = c;
        smaller2 = b;
    }
    else if (b > a && b > c)
    {
        biggest = b;
        smaller1 = a;
        smaller2 = c;
    }

    else if (c > a && b > a)
    {
        biggest = c;
        smaller1 = a;
        smaller2 = b;
    }

    int bowLength = a * b * c;

    return smaller1 * 2 + smaller2 * 2 + bowLength;
}

int main()
{
    cout << getPaperNeeds(2, 3, 4);
    cout << "\n";
    cout << getPaperNeeds(1, 1, 10);
    cout << "\n";
    cout << getPaperNeeds(3, 11, 24);
    cout << "\n";
    cout << getRibbonLength(2, 3, 4);
    cout << "\n";
    cout << getRibbonLength(1, 1, 10);
    cout << "\n";

    int totalNeed = 0;
    int ribbonNeed = 0;

    fstream inputFile;
    inputFile.open("input.txt", ios::in);
    if (inputFile.is_open())
    {
        string measurements;
        while (getline(inputFile, measurements))
        {
            auto i = 0;
            int dimension = 0;

            string s;
            int dimensionValues[3];

            while (measurements[i] != '\0')
            {

                if (measurements[i] != 'x')
                {
                    s += measurements[i];
                }
                else
                {
                    dimensionValues[dimension] = stoi(s);
                    s.clear();
                    dimension++;
                }

                i++;
            }

            dimensionValues[dimension] = stoi(s);
            int need = getPaperNeeds(dimensionValues[0], dimensionValues[1], dimensionValues[2]);
            int ribbonLength = getRibbonLength(dimensionValues[0], dimensionValues[1], dimensionValues[2]);
            totalNeed = totalNeed + need;
            ribbonNeed = ribbonNeed + ribbonLength;
        }
        inputFile.close();

        cout << "Total paper need: ";
        cout << totalNeed;
        cout << "\nTotal ribbon length: ";
        cout << ribbonNeed;
    }
}