//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#include "Population.hpp"

void Population::addTour(Tour *tour) {
    tours.push_back(tour);
}

const vector<Tour *> &Population::getTours() const {
    return tours;
}

void Population::setTours(const vector<Tour *> &newTours) {
    Population::tours = newTours;
}

Tour * Population::getFittest() {
    return fittest;
}

void Population::setFittest(Tour *newFittest) {
    fittest = newFittest;
}

Tour *Population::getBestNonElite() {
    Tour* best = tours.at(31);
    Tour* secondBest = tours.at(31);
    for (auto tour : tours) {
        if (tour->get_tour_distance() < best->get_tour_distance()){
            secondBest = best;
            best = tour;
        }
    }
    return secondBest;
}
