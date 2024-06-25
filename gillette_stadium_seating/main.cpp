#include <iostream>
#include <vector>             // we want a vector rather than array to handle the variable size of the seating arrangement
#include "gillette_stadium.h" // we use include guards to avoid multiple inclusions of the same header file

int main()
{
    // Define the total number of seats and seating arrangement based on different levels
    constexpr int totalSeats = 68756; // Total number of occupied seats
    constexpr int numRows = 300;      // Number of rows in the seating grid
    constexpr int numColumns = 230;   // Number of seats per row in the seating grid

    // Create a seating grid with all seats initially empty
    std::vector<std::vector<int>> seats(numRows, std::vector<int>(numColumns, 0));

    // Define the seating levels
    constexpr int lowerBowlRows = 100; // Number of rows in the lower bowl
    constexpr int upperBowlRows = 100; // Number of rows in the upper bowl
    constexpr int clubLevelRows = 50;  // Number of rows in the club level
    constexpr int suiteLevelRows = 50; // Number of rows in the suite level

    int occupiedSeats = 0; // Initialize the number of occupied seats to 0

    // Fill the lower bowl with fans
    for (int row = 0; row < lowerBowlRows && occupiedSeats < totalSeats; ++row)
    {
        // Iterate over the seats in the lower bowl rows to fill them with fans
        for (int seat = 0; seat < numColumns && occupiedSeats < totalSeats; ++seat)
        {
            seats[row][seat] = 1; // Set the seat to occupied
            ++occupiedSeats;      // Increment the number of occupied seats
        }
    }

    // Fill the upper bowl with fans
    for (int row = lowerBowlRows; row < lowerBowlRows + upperBowlRows && occupiedSeats < totalSeats; ++row)
    {
        // Iterate over the seats in the upper bowl rows to fill them with fans
        for (int seat = 0; seat < numColumns && occupiedSeats < totalSeats; ++seat)
        {
            seats[row][seat] = 1; // Set the seat to occupied
            ++occupiedSeats;      // Increment the number of occupied seats
        }
    }

    // Fill the club level with fans
    for (int row = lowerBowlRows + upperBowlRows; row < lowerBowlRows + upperBowlRows + clubLevelRows && occupiedSeats < totalSeats; ++row)
    {
        // Iterate over the seats in the club level rows to fill them with fans
        for (int seat = 0; seat < numColumns && occupiedSeats < totalSeats; ++seat)
        {
            seats[row][seat] = 1; // Set the seat to occupied
            ++occupiedSeats;      // Increment the number of occupied seats
        }
    }

    // Fill the suites with fans
    for (int row = lowerBowlRows + upperBowlRows + clubLevelRows; row < numRows && occupiedSeats < totalSeats; ++row)
    {
        // Iterate over the seats in the suite rows to fill them with fans
        for (int seat = 0; seat < numColumns && occupiedSeats < totalSeats; ++seat)
        {
            seats[row][seat] = 1; // Set the seat to occupied
            ++occupiedSeats;      // Increment the number of occupied seats
        }
    }

    // Create an instance of the GilletteStadium class
    GilletteStadium gilletteStadium;

    // Calculate the fan personal space of occupied seats
    int fanPersonalSpace = gilletteStadium.calculateFanPersonalSpace(seats);

    // Print the result
    std::cout << "The fan personal space is: " << fanPersonalSpace << std::endl;

    return 0;
}
