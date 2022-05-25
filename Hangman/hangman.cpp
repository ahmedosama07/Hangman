#include "hangman.h"

using namespace std;

bool win = false;
// Get a random word from the wordlist depending on the level chosen
string RandomWord(int choice) {
	int i = 0;
	string line;
	string word;
	string wordlist[10] = {"act",
                           "add",
                           "bit",
                           "chip",
                           "acid",
                           "city",
                           "club",
                           "agency",
                           "extraordinary",
                           "programmer"};
    srand(time(0));
    switch (choice)
    {
    case 1:
        i = (rand() % 3);
        break;
    case 2:
        i = (rand() % 3) + 3;
        break;
    case 3:
        i = (rand() % 3) + 7;
        break;
    }

	while (i < 10)
	{
        word = wordlist[i];
        break;
	}
	return word;
}


//Design the hangman depending on lives
void Draw_Hangman(int live){
	switch (live)
	{
	case 0:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|       / \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;

	case 1:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|         \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 2:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 3:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 4:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 5:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |  " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 6:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 7:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
    case 8:
		cout << "\t\t\t|-------" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
    case 9:
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
    case 10:
		cout << "\t\t\t" << endl;
		cout << "\t\t\t         " << endl;
		cout << "\t\t\t           " << endl;
		cout << "\t\t\t         " << endl;
		cout << "\t\t\t           " << endl;
		cout << "\t\t\t" << endl;
		cout << "\t\t\t_" << endl;
		break;

	default:
		break;
	}
}

//Print chosen right letters or '-'
int PrintWord(string word, string letter){
	for (int i = 0; i < word.size(); i++)
	{
		if (letter.find(word.at(i)) != -1)
			cout << word.at(i) << " ";
		else
		{
			cout << ".";
			win = false;
		}
	}
	return 0;
}
