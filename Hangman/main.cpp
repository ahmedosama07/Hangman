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
*       1- The game starts by asking the user for a number from 1 to 10, each number corresponding to a word
*       2- If the user provides invalid input, go to step 1
*       3- The user is then asked to guess the letters of the word
*       4- If the user inputs more than one letter, check if he inputs the word "help"
*       5- If the user inputs "help", then check if he used help less than three times
*       6- If true, he is given a letter of the word and his lives decreases by one
*       7- Else, he is told that he reached the limit of hints he have and his lives remain as they are
*       8- If he was providing more than one letter and not the word "help", he is considered a cheater and he gets punished by an infinite loop
*       9- If the user provided a right letter then it is printed in the word. Otherwise his lives decreased by one and the letter is added to the wrong list
*       10- If the lives of the user reached zero before guessing the right word he loses the game
*       11- If the user won the game his score updates for the next game
*       12- The user is asked if he wants to play again or not
*       13- If the answer was yes, the game restarts with the new score
*       14- If the answer was no, the game ends and prints the score
*
*/

#include "hangman.h"

#define MAXLIVES 10

int main(void) {

    char ans;
    int score = 0;
    int choice;
    bool old_choices[10];
    for(int i = 0; i < 10; i++)
        old_choices[i] = false;

    do
    {
        // Clear the screen at the beginning of new game
        system("cls");
        // Set the number of lives to be 10 each game
        int live = MAXLIVES;
        bool help = false;
        int help_counter = 0;
        ans = '\0';
        string letter;
        string wrong = "..........";
        string word = "";
        string right = "";

        cout << "choose number from 1 to 10: ";
        cin >> choice;

        //Validate input
        while (choice < 1 || choice>10 || old_choices[choice-1] == true) {
            system("cls");
            cout << "You have enered a wrong number" << endl;
            cout << "choose number from 1 to 10: ";
            cin >> choice;
        }



        word = GetWord(choice);
        system("cls"); // Clear the screen



        while (live > 0)
        {
            win = true;
            help = false;

            Draw_Hangman(live, score);
            PrintWord(word, right);


            if (win == true)
                break;

            cout << "\n\nIf you want to know the first letter write 'help' [warning: Your lives will decrease!]. You have " << 3 - help_counter << " remaining." << endl;

            cout << "\n\n\t\t\t\t\t\t\t\t\t\tLives: " << live << endl;
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t---------------------" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t| Wrong: " << wrong << " |" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t---------------------" << endl;
            cout << "\n\nEnter a letter: ";
            cin >> letter;

            // To cover upper case problems
            for(int i = 0; i < letter.length(); i++)
            {
                letter[i] = tolower(letter[i]);
            }

            if (letter.length() >= 2)
            {
                // Help
                if (letter == "help")
                {
                    if(help_counter > 2)
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
                        while((right.find(word.at(i)) != -1))
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
                    // Anti cheating system
                    system("cls");
                    while(true)
                    {
                        cout << "You are CHEATING!!!" << endl;
                    }
                }
            }



            // Letter found
            if (word.find(letter) != -1)
            {
                system("cls");
                right += letter[0];
                continue;
            }
            // Letter not found
            else
            {
                system("cls");
                wrong[10-live] = letter[0];
                live--;
            }
        }


        // If alive
        if (live > 0)
        {
            cout << "\n\n\n\t\t\t >>>You WIN!<<<\n\n";
            score++;
            cout << "The word was: " << word << endl;
        }
        // If dead
        else
        {
            Draw_Hangman(live, score);
            cout << "\n\n\n\t\t\t >>>You Lose!<<<\n\n";
            cout << "The word was: " << word << endl;
        }

        // Restart game
        cout << "Do you want to play again? (y/n)" << endl;

        while((tolower(ans) != 'y') && (tolower(ans) != 'n'))
            cin >> ans;

        if(tolower(ans) == 'n')
        {
            system("cls");
            cout << "Nice to meet you :)" << endl;
            cout << "Your score is: " << score << endl;
            system("pause");
            break;
        }

        // Don't play the same game
        if(win)
            old_choices[choice-1] = true;
    } while((tolower(ans) == 'y') && score <= 10);


	return 0;
}
