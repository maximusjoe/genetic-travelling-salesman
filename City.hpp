//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

constexpr double MAP_BOUNDARY = 1000;

/**
 * A city class that contains the name of a city and the longitude and latitude of the respective city.
 */
struct City {

    /** Name of the city, often a number value for a sequence. */
    string name;

    /** Longitude. */
    double x;

    /** Latitude. */
    double y;

    /**
     * City constructor.
     * @param name name of the city
     * @param x longitude
     * @param y latitude
     */
    City(string name, double x, double y);

    /** City destructor. */
    ~City() = default;

    /**
     * Calculates the distance between two cities
     * @param other other city
     * @return the distance between two cities
     */
    double get_distance_between_cities(const City *other) const;

    /**
     * Prints the city information to the console.
     * @param os output steam
     * @param c city
     * @return os to be printed
     */
    friend ostream &operator<<(ostream &os, const City &c) {
        os << "City " << c.name << fixed << setprecision(2) << ": (" << c.x << ", " << c.y << ")" << endl;
        return os;
    }

};