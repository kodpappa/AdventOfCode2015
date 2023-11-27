#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int getPaperNeeds(int *numbers)
{
    int sideA = numbers[0] * numbers[1];
    int sideB = numbers[1] * numbers[2];
    int sideC = numbers[0] * numbers[2];

    return 2 * sideA + 2 * sideB + 2 * sideC + numbers[0];
}

int getRibbonLength(int *numbers)
{
    int bowLength = numbers[0] * numbers[1] * numbers[2];

    return numbers[0] + numbers[0] + numbers[1] + numbers[1] + bowLength;
}

void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    int arr1[] = {1, 3, 4};
    cout << getPaperNeeds(arr1);
    cout << "\n";

    int arr2[] = {1, 1, 10};
    cout << getPaperNeeds(arr2);
    cout << "\n";

    int arr3[] = {3, 11, 24};
    cout << getPaperNeeds(arr3);
    cout << "\n";

    int arr4[] = {2, 3, 4};
    cout << getRibbonLength(arr4);
    cout << "\n";

    int arr5[] = {1, 1, 10};
    cout << getRibbonLength(arr5);
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
            bubbleSort(dimensionValues, 3);

            int need = getPaperNeeds(dimensionValues);
            int ribbonLength = getRibbonLength(dimensionValues);
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