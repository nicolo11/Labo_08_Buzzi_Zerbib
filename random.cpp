/*
--------------------------------------------------------------------------------------------------------
Laboratory : 07 Random statistics
File       : random.cpp
Author(s)  : Jonathan Zaehringer, Jeremy Zerbib
Date       : 29.11.2017

Aim        : Generates random values

Comment(s) :

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
--------------------------------------------------------------------------------------------------------
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>


#include "random.h"

/**
 * Initialize the random
 */
void initRandom() {
    static bool done = false;

    unless (done) {
        std::srand(std::time(NULL));

        done = true;
    }
}

/**
 *
 * @param min
 * @param max
 * @return Gets a random value between two given values
 */
int getRandomNumber(int max, int min) {
    // Including the max bound
    max = max + 1 - min;

    return std::rand() % max + min;
}

/**
 * Puts in the the table every throws that land in the index value
 * @param tab
 * @param size
 * @param throws
 */
void statistics(int tab[], size_t size, int throws) {
    const int MAX_RANDOM = size - 1;
    initRandom();

    for (int i = 1; i <= throws; ++i) {
        tab[getRandomNumber(0, MAX_RANDOM)]++;
    }
}

/**
 * Displays the histogram view of the stats
 * @param percent
 * @param c
 */
void countStats(int percent, char c) {
    for (int j = 0; j < percent; ++j) {
        std::cout << c;
    }
}