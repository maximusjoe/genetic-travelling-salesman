//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#pragma once

#include "Tour.hpp"

/**
 * A class containing a population of tours.
 */
class Population {
private:

    /** Vector of tours in a population */
    vector<Tour *> tours;

    /** Most fit tour in a population (shortest distance to for a tour). */
    Tour* fittest;

public:

    /**
     * Gets the vector of tours in a population.
     * @return vector of tours
     */
    [[nodiscard]] const vector<Tour *> &getTours() const;

    /**
     * Sets the vector of tours in a population.
     * @param tours vector to be set
     */
    void setTours(const vector<Tour *> &tours);

    /**
     * Gets the fittest tour of the population.
     * @return fittest tour
     */
    [[nodiscard]] Tour * getFittest();

    /**
     * Sets the most fit tour of the population.
     * @param fittest most fit tour
     */
    void setFittest(Tour *fittest);

    /**
     * Adds a tour to the population.
     * @param tour tour to be added
     */
    void addTour(Tour *tour);

    /**
     * Get the best non elite Tour.
     * @return the best non-elite Tour.
     */
    Tour *getBestNonElite();

};