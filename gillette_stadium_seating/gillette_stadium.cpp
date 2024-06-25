#include "gillette_stadium.h"

// Calculate the fan personal space (the total number of boundary edges) for the entire seating arrangement.
int GilletteStadium::calculateFanPersonalSpace(const std::vector<std::vector<int>> &seats) const
{
    int fanPersonalSpace = 0;       // Initialize the fan personal space to 0
    int numRows = seats.size();     // Get the number of rows in the seating grid
    int numSeats = seats[0].size(); // Get the number of columns in the seating grid

    // Iterate over the rows of the seating grid
    for (int row = 0; row < numRows; ++row)
    {
        // Iterate over the seats in each row
        for (int seat = 0; seat < numSeats; ++seat)
        {
            // If the seat is occupied, calculate its contribution to the fan personal space
            if (seats[row][seat] == 1)
            {
                fanPersonalSpace += getFanPersonalSpaceForSeat(seats, row, seat);
            }
        }
    }

    return fanPersonalSpace; // Return the calculated fan personal space
}

// Calculate the fan personal space (boundary edges) for a specific seat.
int GilletteStadium::getFanPersonalSpaceForSeat(const std::vector<std::vector<int>> &seats, int row, int seat) const
{
    int fanPersonalSpace = 0;       // Initialize the fan personal space for this seat
    int numRows = seats.size();     // Get the number of rows in the seating grid
    int numSeats = seats[0].size(); // Get the number of columns in the seating grid

    // Check if the seat above is empty or if this seat is at the top edge of the grid
    if (row == 0 || seats[row - 1][seat] == 0)
    {
        ++fanPersonalSpace; // Increment the fan personal space
    }

    // Check if the seat below is empty or if this seat is at the bottom edge of the grid
    if (row == numRows - 1 || seats[row + 1][seat] == 0)
    {
        ++fanPersonalSpace; // Increment the fan personal space
    }

    // Check if the seat to the left is empty or if this seat is at the left edge of the grid
    if (seat == 0 || seats[row][seat - 1] == 0)
    {
        ++fanPersonalSpace; // Increment the fan personal space
    }

    // Check if the seat to the right is empty or if this seat is at the right edge of the grid
    if (seat == numSeats - 1 || seats[row][seat + 1] == 0)
    {
        ++fanPersonalSpace; // Increment the fan personal space
    }

    return fanPersonalSpace; // Return the fan personal space for this seat
}
