/*
   -----------------------------------------------------------------------------------
Laboratory : 06 Nombre de jours
File       : io.cpp
Author(s)  : Jonathan Zaehringer, Pierre Kohler, Jeremy Zerbib
Date       : 20.11.2017

Aim        : Library to interacte with user and display a table

Comment(s) : 

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2 
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <string>

#include "io.h"
#include "misc.h"
#include "date.h"

using namespace std;

// -------------------------------
// User input functions
// -------------------------------
/**
 *
 * @param question
 * @return Asks a question to the user and returns a character
 */
char getChar(const string& question) {
    const string error = "La valeur n'est pas un caractère.";

    char result;
    bool badValue;

    do {
        cout << question;
        badValue = !getCin(error, result);

        CLEAN_BUFFER;

    } while (badValue);

    return result;
}

/**
 *
 * @param question
 * @return Asks a question to the user and returns an integer
 */
int getInt(const string& question) {
    const string error = "La valeur n'est pas un entier.";

    int result;
    bool badValue;

    do {
        cout << question;
        badValue = !getCin(error, result);
        CLEAN_BUFFER;
    } while (badValue);

    return result;
}

/**
 *
 * @param min
 * @param max
 * @param question
 * @return The number of value between two bounds
 */
int getIntBetween(int min, int max, const string& question) {
    int result;

    do {
        result = getInt(question);
    } while (checkBounds(result, min, max));

    return result;
}

/**
 *
 * @param question
 * @param day
 * @param month
 * @param year
 * @param separator
 */
void getDate(const string& question, int& day, int& month, int& year,
             const char& separator) {
    const string errorGlobal     = "Saisie invalide, on recommence.";
    const string errorSeparator1 = "Premier separateur saisi incorrect.";
    const string errorSeparator2 = "Deuxieme separateur saisi incorrect.";
    const string errorDate       = "Cette date n'existe pas.";
    const string fatalErrorDay   = "Le jour n'est pas une valeur entiere.";
    const string fatalErrorMonth = "Le mois n'est pas une valeur entiere.";
    const string fatalErrorYear  = "L'annee n'est pas une valeur entiere.";

    const int START_DAY   = 1;
    const int START_MONTH = 1;
    const int START_YEAR  = 1900;
    const int END_DAY     = 31;
    const int END_MONTH   = 12;
    const int END_YEAR    = 2100;

    bool goodValue;
    char userSeparator;

    do {
        cout << question;
        // gets day
        // Checks the input format and if this input has an incorrect type,
        // it stops analysing afterwards.
        if(!(goodValue = getCin(fatalErrorDay, day))){
            CLEAN_BUFFER;
            continue;
        }
        goodValue  = checkBounds(day, START_DAY, END_DAY, "jour");

        // gets first separator
        goodValue &= getCin(errorSeparator1, userSeparator) &&
                (userSeparator == separator || !(cout << errorSeparator1 << endl));

        // gets month
        if(!(goodValue = getCin(fatalErrorMonth, month))){
            CLEAN_BUFFER;
            continue;
        }
        goodValue &= checkBounds(month, START_MONTH, END_MONTH, "mois");

        //gets second separator
        goodValue &= getCin(errorSeparator2, userSeparator) &&
                (userSeparator == separator || !(cout << errorSeparator2 << endl));

        //gets year
        goodValue &= getCin(fatalErrorYear, year)
                     && checkBounds(year, START_YEAR, END_YEAR, "annee");

        // checks if date is valid
        goodValue = goodValue &&
                (isDateValid(day, month, year) || !(cout << errorDate << endl));
        CLEAN_BUFFER;

    } while (!goodValue && cout << errorGlobal << endl);
}

/**
 *
 * @param error
 * @param result
 * @return A boolean that tells us whether the cin is ok or not
 */
bool getCin(const string& error, char& result) {
    cin >> result;
    return testCinFail(error);
}

/**
 *
 * @param error
 * @param result
 * @return A boolean that tells us whether the cin is ok or not
 */

bool getCin(const string& error, int& result) {
    cin >> result;
    return testCinFail(error);
}

/**
 *
 * @param yes
 * @param no
 * @param question
 * @return a bool that makes the program go on or exit.
 */
bool wantsUserRedo(const char& yes, const char& no, const string& question) {
    const string error = " ne répond pas à la question.";

    char result;

    do {
        result = (char) (tolower(getChar(question)));
    } while ((result != yes && result != no) &&
            cout << "'" << result << "'" << error << endl);

    return (result == yes);
}

/**
 * Waits for the user to interact with the program.
 */
void waitUserInteraction() {
    cout << "presser ENTER pour quitter";
    
    CLEAN_BUFFER;
}

// -------------------------------
// Printing functions
// -------------------------------

/**
 * Prints a cell
 * @param value
 * @param width
 */
void printCell(int value, int width) {
    cout << right << setw(width) << value;
}

/**
 * Prints a cell
 * @param value
 * @param width
 */
void printCell(char value, int width) {
    cout << right << setw(width) << value;
}

// -------------------------------
// Check functions
// -------------------------------
/**
 *
 * @param error
 * @return a boolean that tells us if the buffer is ok or not
 */
bool testCinFail(const string& error) {
    if (cin.fail()) {
        CLEAR_BUFFER;
        cout << error << endl;
        return false;
    }
    return true;
}

