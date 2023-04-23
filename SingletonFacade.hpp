//Name: Nick Hughes, Maximus Joe
//Student# : A01178826, A01256098

#pragma once

/**
 * Singleton facade for running the mutation algorithm
 */
class SingletonFacade {
protected:
    /**
     * Protected constructor for the SingletonFacade class
     */
    SingletonFacade() = default;

    /**
     * static pointer to singletonFacade object
     */
    static SingletonFacade *singletonFacade;

public:

    /**
     * Clone 'override' so that SingletonFacade cannot be cloneable
     * @param other the SingletonFacade attempting to be cloned
     */
    SingletonFacade(SingletonFacade &other) = delete;

    /**
     * Operator 'override' so that SingletonFacade cannot be assignable
     */
    void operator=(const SingletonFacade &) = delete;

    /**
     * Executes the genetic algorithm.
     */
    static void run();

    /**
     * Get the instance of the singletonFacade
     * @return the instance of the SingletonFacade
     */
    static SingletonFacade *GetInstance();

};
