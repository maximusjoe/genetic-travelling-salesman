//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#pragma once

#include "Tour.hpp"
#include "Population.hpp"

constexpr int PARENT_POOL_SIZE = 5;             //Number of parents in a set.
constexpr int TWO_PARENTS_POOL_SIZE = 10;       //2xNumber of parents in a set.
constexpr int CITIES_PER_TOUR = 32;             //Number of cities in a Tour.
constexpr double MUTATION_RATE = 0.15;          //Chance of mutation.
constexpr double FITNESS_SCALAR = 10000000;     //Scalar for mutation chance.
constexpr int PERCENT = 100;                    //Percentage modifier.

/**
 * Handler class containing the Genetic Algorithm methods
 */
class AlgorithmHandler {

public:

    /**
     * Select tours for crossover from a population
     * @return tours ready for crossover
     */
    static vector<Tour *> select_tours(const vector<Tour *> &parents);

    /**
     * Generate a new tour from a given set of parent tours
     * @return a new 'crossed' vector of cities
     */
    static vector<City *> crossover(const vector<Tour *> &);

    /**
     * Possibly mutate a tour, depending on mutation chance
     * @return a new, mutated tour
     */
    static Tour mutate(Tour &tour);

};
