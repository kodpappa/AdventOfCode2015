
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>

class Location
{
public:
    int x;
    int y;
    int numberOfPresents;
};

int main()
{
    std::ifstream file("input.txt");

    std::string directions((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());

    Location currentLocation;
    currentLocation.x = 0;
    currentLocation.y = 0;
    currentLocation.numberOfPresents = 1;

    std::vector<Location> locations;
    locations.push_back(currentLocation);

    for each (char direction in directions)
    {
        Location newLocation;
        if (direction == '<')
        {
            newLocation.x = currentLocation.x - 1;
            newLocation.y = currentLocation.y;
        }
        else if (direction == '>')
        {
            newLocation.x = currentLocation.x + 1;
            newLocation.y = currentLocation.y;
        }
        else if (direction == '^')
        {
            newLocation.x = currentLocation.x;
            newLocation.y = currentLocation.y + 1;
        }
        else if (direction == 'v')
        {
            newLocation.x = currentLocation.x;
            newLocation.y = currentLocation.y - 1;
        }

        bool isElementNew = true;

        for (auto location : locations)
        {
            if ((location.x == newLocation.x) && (location.y == newLocation.y))
            {
                location.numberOfPresents = location.numberOfPresents + 1;
                isElementNew = false;
                break;
            }
        }

        if (isElementNew)
        {
            newLocation.numberOfPresents = 1;
            locations.push_back(newLocation);
        }

        currentLocation = newLocation;
    }
    int visitsWithPresents = 0;
    for each (Location location in locations)

        if (location.numberOfPresents > 0)
        {
            visitsWithPresents = visitsWithPresents + 1;
        }

    std::cout << visitsWithPresents;

    return 0;
}
