//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#pragma once

#include <vector>
#include <cmath>
#include "City.hpp"

/**
 * A class containing a list of all the cities in the simulation and a fitness rating.
 * The fitness rating evaluates the distance the traveling salesman would need to
 * travel to visit the cities in the order they appear in the tour.
 */
class Tour {
private:

    /** Vector of cities in a tour. */
    vector<City *> cities;

public:

    /**
     * Default tour constructor.
     */
    Tour() = default;

    /**
     * Default Destructor.
     */
    ~Tour() = default;

    /**
     * Gets the fitness rating of the tour.
     * @return fitness rating
     */
    double determine_fitness();

    /**
     * Gets the vector of cities in a tour.
     * @return cities
     */
    [[nodiscard]] vector<City *> &get_cities();

    /**
     * Sets the vector of cities in a tour.
     * @param newCities new cities
     */
    void set_cities(const vector<City *> &newCities);

    /**
     * Adds a city to the vector of cities in a tour.
     * @param city city to be added
     */
    void add_city(City *city);

    /**
     * Report the distance between cities as they are listed in a tour.
     * @return distance between two cities
     */
    double get_tour_distance();

    /**
     *
     * Check if a tour contains a specific city, true if contains
     * @return true if tour contains specified city, false if not
     */
    bool contains_city(City *city);

    /**
     * Prints the tour information to the console.
     * @param os output steam
     * @param c tour
     * @return os to be printed
     */
    friend ostream &operator<<(ostream &os, const Tour &t) {
        os << "(";
        for (int i = 0; i < (int) t.cities.size(); ++i) {
            os << t.cities.at(i)->name;
            os << (i < (int) t.cities.size() - 1 ? "->" : "");
        }
        os << ")" << endl;
        return os;
    }

};
