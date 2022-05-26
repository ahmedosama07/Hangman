#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED

// Libraries included
#include <iostream>
#include <time.h>

#include <stdlib.h>
#include <windows.h>
#include <string>

// Using std namespace
using namespace std;

// Making win accessible by the other files
extern bool win;

// Declaring functions
string GetWord(int choice);                  // Function picks random word from wordlist
void Draw_Hangman(int live, int score);                    // Function to draw hangman
int PrintWord(string word, string guessedLetters);      // Function to print the word being guessed


#endif // HANGMAN_H_INCLUDED
