#ifndef HANGMAN_H_INCLUDED // GUARD
#define HANGMAN_H_INCLUDED
// Libraries included
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string>

using namespace std;

extern bool win;

string RandomWord(int choice);
void Draw_Hangman(int live);
int PrintWord(string word, string letter);


#endif // HANGMAN_H_INCLUDED
