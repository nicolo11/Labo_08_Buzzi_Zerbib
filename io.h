/*
-----------------------------------------------------------------------------------
Laboratory : 06 Nombre de jours
File       : io.h
Author(s)  : Jonathan Zaehringer, Pierre Kohler, Jeremy Zerbib
Date       : 20.11.2017

Aim        : Header of io.cpp, define macro to clean buffer, reset buffer,
                wait interaction from user and user want redo the software

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2 
-----------------------------------------------------------------------------------
*/
#ifndef IO_HEADER
#define IO_HEADER

#include <string>
#include <iostream>
#include <limits>

#define CLEAN_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define CLEAR_BUFFER cin.clear()
#define RESET_BUFFER CLEAR_BUFFER; CLEAN_BUFFER


// ---------------------
// User input functions
// ---------------------
char getChar(const std::string& question); 
int getInt(const std::string& question); 
int getIntBetween(int min, int max, const std::string& question);
void getDate(const std::string& question, int& day, int& month, int& year, const char& separator = '-'); 
bool getCin(const std::string& error, int& result); 
bool getCin(const std::string& error, char& result); 

bool wantsUserRedo(const char& yes, const char& no, const std::string& question);
void waitUserInteraction();

// ---------------------
// Printing functions
// ---------------------
void printCell(int value, int width);
void printCell(char value, int width);

// -------------------------------
// Check functions
// -------------------------------
bool checkBounds (int value, int min, int max, const std::string& s = "");
bool testCinFail(const std::string& error); 

#endif
