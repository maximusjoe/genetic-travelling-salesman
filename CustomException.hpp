//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#pragma once

#include <stdexcept>

using namespace std;

/**
 * Custom exception that is intended to be thrown when the coordinates of a city are out of bounds.
 * @return String containing the appropriate error message.
 */
struct outOfRangeCoordinates : public exception {
    [[nodiscard]] const char *
    what() const noexcept override { return "Coordinates must be between 0 and 1000"; }
};