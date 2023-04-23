//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#include "AlgorithmHandler.hpp"
#include <cmath>
#include <random>
#include <algorithm>

vector<Tour *> AlgorithmHandler::select_tours(const vector<Tour *> &pop) {
    mt19937_64 random_engine{random_device{}()};
    vector<Tour *> parents;
    ranges::sample(pop, std::back_inserter(parents), TWO_PARENTS_POOL_SIZE, random_engine);
    return parents;
}

vector<City *> AlgorithmHandler::crossover(const vector<Tour *> &selectedTours) {
    vector<Tour *> set1;
    vector<Tour *> set2;
    double fitnessSet1 = 0;
    double fitnessSet2 = 0;
    Tour *parent1;
    Tour *parent2;
    vector<City *> child;

    for (int i = 0; i < PARENT_POOL_SIZE; i++) {
        set1.push_back(selectedTours[i]);
    }

    for (int j = PARENT_POOL_SIZE; j < TWO_PARENTS_POOL_SIZE; j++) {
        set2.push_back(selectedTours[j]);
    }

    for (Tour *t: set1) {
        double tempFitness = t->determine_fitness();
        if (tempFitness > fitnessSet1) {
            fitnessSet1 = tempFitness;
            parent1 = t;
        }
    }

    for (Tour *t: set2) {
        double tempFitness = t->determine_fitness();
        if (tempFitness > fitnessSet2) {
            fitnessSet2 = tempFitness;
            parent2 = t;
        }
    }

    //pick a random index within number of cities per tour
    srand((unsigned) time(nullptr));
    int random = rand() % CITIES_PER_TOUR;

    for (int i = 0; i < random; i++) {
        child.push_back(parent1->get_cities()[i]);
    }
    for (int j = 0; j < (CITIES_PER_TOUR); j++) {
        //add all cities we come across, unless we hit a duplicate city, in which case we pass over it
        if (std::find(child.begin(), child.end(), parent2->get_cities()[j]) != child.end()) {
        } else {
            child.push_back(parent2->get_cities()[j]);
        }
    }
    return child;
}

Tour AlgorithmHandler::mutate(Tour &tour) {
    random_device rd; // a random number generator
    mt19937 generator(rd()); // calls operator()
    uniform_int_distribution<> distribution(0, PERCENT);
    int mutationChance;
    for (int i = 1; i < (int) tour.get_cities().size(); ++i) {
        mutationChance = distribution(generator);
        if (MUTATION_RATE * PERCENT > mutationChance){
            swap(tour.get_cities().at(i - 1), tour.get_cities().at(i));
        }
    }
    mutationChance = distribution(generator);
    if (MUTATION_RATE * PERCENT > mutationChance){
        swap(tour.get_cities().front(), tour.get_cities().back());
    }
    return tour;
}