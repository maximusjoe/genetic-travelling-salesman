//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#include "Tour.hpp"

constexpr double FITNESS_SCALAR = 10000000;

double Tour::determine_fitness() {
    return (1 / (this->get_tour_distance()) * FITNESS_SCALAR);
}

vector<City *> &Tour::get_cities() {
    return cities;
}

void Tour::set_cities(const vector<City *> &newCities) {
    Tour::cities = newCities;
}

void Tour::add_city(City *city) {
    cities.push_back(city);
}

double Tour::get_tour_distance() {
    if (cities.empty()) {
        return -1;
    }
    double totalDistance = 0;
    for (int i = 1; i < (int) cities.size(); ++i) {
        totalDistance += cities.at(i - 1)->get_distance_between_cities(cities.at(i));
    }
    totalDistance += cities.front()->get_distance_between_cities(cities.back());
    return totalDistance;
}

bool Tour::contains_city(City *city) {
    vector<City *> tempCities = cities;
    for (auto &tempCity: tempCities) {
        if (tempCity == city) {
            //city exists in the tour
            return true;
        }
    }
    //city does not exist in the tour
    return false;
}
