#include "hangman.h"

using namespace std;

//bool win = false;

int main() {
    start:
	int live = 7;
	int choice;
	int num;
	char ans;
	string letter;
	string word;
	string guessedLetters = "";

	cout << "choose your level: \n1)Easy\n2)Medium\n3)Hard\n-->";
	cin >> choice;

	//Validate input
	while (choice < 1 || choice>3) {
		system("cls");
		cout << "You have enered a wrong number, renter your level..\n";
		cout << "choose your level: \n1)Easy\n2)Medium\n3)Hard\n-->";
		cin >> choice;
	}

	word = RandomWord(choice);
	system("cls"); // Clear the screen

	bool help = false;
	int help_counter = 0;

	while (live > 0)
	{
		win = true;
		Draw_Hangman(live);
		PrintWord(word, guessedLetters);

		if(help)
            help = false;


		if (win == true)
			break;
		cout << "\n\nIf you want to know the first letter write 'help' [Your lives will decrease!]" << endl;
		cout << "\n\nLetters guesses: " << guessedLetters << endl;
		cout << "\n\nEnter a letter: ";
		cin >> letter;

		int b = 0;
        cout << "here" << endl;
		while (letter[b] != '\0')
			b++;

		//To catch those cheatty persons who write more than a letter
		if (b >= 2)
		{
			if (letter == "help") // If you need a help to know the first letter
			{
			    if(((choice == 1) && (help_counter > 0)) || ((choice == 2) && (help_counter > 1)) || ((choice == 3) && (help_counter > 2)))
                {
                    cout << "You exceded the maximum number of helps" << endl;
                    system("pause");
                }
                else
                {
                    help_counter++;
                    live--;
                    srand(time(0));
                    int i = 0;
                    while((guessedLetters.find(word.at(i)) != -1))
                    {
                        i = rand() % word.length();
                    }
                    cout << "-->\"" << word[i] << "\"<--" << endl;
                    letter = word[i];
                    system("pause");
                }
			}
			else
			{
				system("cls");
				for (;;) //Infinity loop (like: while(true){} ..)
				{
					cout << "You are CHEATING!!!" << endl;
				}
			}
		}


		guessedLetters += letter[0];

		if (word.find(letter) != -1 || help)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			live--;
		}
	}

	if (live == 0) //If we have finished our lives
	{
		cout << "\n\n\n\t\t\t >>>You Lose!<<<\n\n";
		cout << "The word was: " << word << endl;
	}
	if (live > 0) //If we complete the word correctly
	{
		cout << "\n\n\n\t\t\t >>>You WIN!<<<\n\n";
		cout << "The word was: " << word << endl;
	}

	cout << "Do you want to play again? (y/n)" << endl;

	while((tolower(ans) != 'y') && (tolower(ans) != 'n'))
        cin >> ans;

	if(tolower(ans) == 'y')
    {
        system("cls");
        goto start;
    }
    else if(tolower(ans) == 'n')
    {
        system("cls");
        cout << "Nice to meet you :)" << endl;
    }

	return 0;
}
