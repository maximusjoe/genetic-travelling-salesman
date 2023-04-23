# Traveling Salesman Problem Solver with Genetic Algorithm in C++ with Object-Oriented Design

This project is a C++ implementation of a genetic algorithm to solve the Traveling Salesman Problem. The solution uses object-oriented design to ensure modularity and scalability.

The program generates a random set of cities with random coordinates, and then uses a genetic algorithm to find an approximate solution to the problem.

The solution is designed using object-oriented principles to ensure modularity and scalability. The program includes the following classes:

- `City`: A class that represents a city with an x-coordinate and a y-coordinate.
- `Tour`: A class that represents a tour (i.e., a sequence of cities to be visited). The class contains functions to compute the total distance of the tour and to perform mutations and crossovers for the genetic algorithm.
- `Population`: A class that represents a population of tours. The class contains functions to generate a random population, select parents for the genetic algorithm, and evolve the population through generations.

To use the program, clone the repository, open it in your favorite C++ IDE, build and run the program. The program will output the best path found and the total distance traveled.

The project is inspired by the work of Marin Vlastelica Pogančić and his Java implementation of the genetic algorithm for the Traveling Salesman Problem.
