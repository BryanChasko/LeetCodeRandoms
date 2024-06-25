// This file is the header file for the GilletteStadium class.
// It contains the class definition and method declarations.
// The header file is necessary for using the std::vector class, which is part of the C++ Standard Library.
// std::vector is a dynamic array that can resize itself automatically when elements are added or removed.
// It provides functionalities similar to arrays but with more flexibility.

#ifndef GILLETTE_STADIUM_H
#define GILLETTE_STADIUM_H

#include <vector>

// Define the GilletteStadium class. This class represents the seating arrangement at Gillette Stadium as a grid of seats.
class GilletteStadium
{
public:
    // This method calculates the fan personal space (the total number of boundary edges) of the seating arrangement.
    // The method takes a 2D vector of integers as input and returns an integer as output.
    int calculateFanPersonalSpace(const std::vector<std::vector<int>> &seats) const;

private:
    // Helper method to calculate the boundary edges for a given seat.
    int getFanPersonalSpaceForSeat(const std::vector<std::vector<int>> &seats, int row, int seat) const;
};

#endif // GILLETTE_STADIUM_H
