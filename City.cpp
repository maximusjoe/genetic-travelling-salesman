//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#include "City.hpp"
#include "CustomException.hpp"

#include <utility>
#include <cmath>


City::City(string name, double x, double y) {
    if (x > MAP_BOUNDARY || x < 0 || y > MAP_BOUNDARY || y < 0){
        throw outOfRangeCoordinates();
    }
    this->name = std::move(name);
    this->x = x;
    this->y = y;
}

double City::get_distance_between_cities(const City *other) const {
    double xDiff = pow((this->x - other->x), 2);
    double yDiff = pow((this->y - other->y), 2);
    return sqrt(xDiff + yDiff);
}
