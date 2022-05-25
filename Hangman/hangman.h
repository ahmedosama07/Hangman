#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;

extern bool win;

string RandomWord(int choice);
void Design(int live);
int PrintWord(string word, string letter);


#endif // HANGMAN_H_INCLUDED
