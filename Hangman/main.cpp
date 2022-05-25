/*
* This project of Hangman game was made by !Programmers team as a final project for C programming & Digital Logic design subject in May, 2022
*   Team members:
*           - Ahmed Osama Mohamed Afifi                       20010038
*           - Ziad Mohamed Mohamed Abdullah                   20010643
*           - Ahmed Kamel Mohamed                             20010156
*           - Abdulrahman Hisham Desouky                      20012332
*           - Mostafa Mohamed Abdel Azeem Hassanen            20011950
*           - Mohamed Ashraf Elsayed Mahmoud                  20011488
*           - Omar Mohamed Ashmawy Ali                        20012376
*           - Ahmed Abdelhakim Abdelsalam Ali                 20010124
*           - Mostafa Khaled Khamis Abudeif                   20011922
*
*
*
*
*/

#include "hangman.h"

int main(void) {
    start:
	int live = 10;
	int choice;
	int num;
	bool help = false;
	char ans;
	string letter;
	string wrong = "..........";
	string word = "";
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

	int help_counter = 0;

	while (live > 0)
	{
		win = true;
		help = false;
		Draw_Hangman(live);
		PrintWord(word, guessedLetters);


		if (win == true)
			break;
		cout << "\n\nIf you want to know the first letter write 'help' [Your lives will decrease!]" << endl;
		cout << "\n\n\t\t\t\t\t\t\t\t\t\tLives: " << live << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t---------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t| Wrong: " << wrong << " |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t---------------------" << endl;
		cout << "\n\nEnter a letter: ";
		cin >> letter;

		for(int i = 0; i < letter.length(); i++)
        {
            letter[i] = tolower(letter[i]);
        }



		//To catch those cheatty persons who write more than a letter
		if (letter.length() >= 2)
		{
			if (letter == "help") // If you need a help to know the first letter
			{
			    if(((choice == 1) && (help_counter > 0)) || ((choice == 2) && (help_counter > 1)) || ((choice == 3) && (help_counter > 2)))
                {
                    cout << "You exceded the maximum number of helps" << endl;
                    letter = "";
                    system("pause");
                }
                else
                {
                    help_counter++;
                    wrong[10-live] = ' ';
                    live--;
                    srand(time(0));
                    int i = 0;
                    while((guessedLetters.find(word.at(i)) != -1))
                    {
                        i = rand() % word.length();
                    }
                    cout << "-->\"" << word[i] << "\"<--" << endl;
                    letter = word[i];
                    help = true;
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


		if (word.find(letter) != -1)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			wrong[10-live] = letter[0];
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
