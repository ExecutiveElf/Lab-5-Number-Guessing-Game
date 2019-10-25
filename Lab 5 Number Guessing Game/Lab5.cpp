/* Benjamin Roe
 C++ Fall 2019
 Due
 Lab 5 Number Guessing Games
 Write a number-guessing game in which the computer selects a random
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
the end of each game, users should be told whether they won or lost, and then be asked
whether they want to play again. When the user quits, the program should output the
total number of wins and losses. To make the game more interesting, the program
should vary the wording of the messages that it outputs for winning, for losing, and for
asking for another game. Create 10 different messages for each of these cases, and use
random numbers to choose among them. This application should use at least one Do-
While loop and at least one Switch statement. Write your C++ code using good style and
documenting comments. You should use functions in your code as well. Your source
code file should be called Lab5.cpp.
*/

#include <iostream>
#include <time.h>
using namespace std;

int numberGuessing();
int wins();
void winResponse();
int losses();
void lossResponse();
void replayResponse();

int main()
{
	srand((unsigned int)time(NULL));
	do{
		cout << "A random number between 0 and 100 has been generated. You have 20 tries to guess the correct answer." << endl << endl;
	}while (numberGuessing() == 0); /*Outputs the initial prompt and then runs the game in order to compair its return
									its to a value.*/
	if (!cin) //Runs if the do-while loop is exited due to a failed input.
	{
		cout << "Input stream has failed. Program will be terminated." << endl << endl;
		return 1; //Return value is 1 if there is an error.
	}
	return 0; //Return value is 0 if there were no errors.
}

int numberGuessing()
{
	int userInput;
	int attempts = 0;
	int ranNum = rand() % 101; //Generates a random number in the range of 0 to 100.
	int game = 1;

	for (int attempts = 0; (attempts <= 19); attempts++) //Loops until enough guesses have been made.
	{
		cin >> userInput; //Takes user's input value
		cout << endl;
		if (userInput == ranNum) /*Compairs user's input to the randomly genrated, if they are equal, awards the player
								 whith a point before exiting the for loop.*/
		{
			wins();
			winResponse(); //Calls the function that picks one of 10 responses when guessing the number successfully.
			break; //Breaks out of the loop if the correct number is guessed.
		}
		else if (attempts == 19)
		{
			losses();
			lossResponse(); //Calls the function that picks one of the 10 responses when failing to guess the number.
		}
		else if (!cin) /*Immediatly exits the function with a value of 1 if there is a failed input. 
					   this return of 1 will also cause the do-while loop in the main function to terminate.*/
		{
			return 1;
		}
		cout << "You have " << 19 - attempts << " attempt(s) left on this number." << endl << endl;
	}

	cout << endl << "The number was " << ranNum << "." << endl << endl; //Says what the number was after current game ends.
	replayResponse();
	do { /*Will wait for you to give a valid input. If 0 is given then the function simply
		 concudes and starts a new iteration in the main function.*/
		cin >> game;
		if (game == 1) //If 1 is input then the loop in the main function will end. Outputting one's score and ending the program.
		{
			cout << "You won " << wins() << " time(s) and lost " << losses() << " time(s)." << endl << "Goodbye" << endl << endl;
		}
		else if (game != 0 && game != 1) //If a number other than 0 or 1 is given, the input will be declared invalid and ignored.
		{
			cout << endl << "Invalid Input" << endl << endl;
		}
		else if (!cin) //If the input fails then the function will exit with a return of 1, ending the loop in the main function.
		{
			return 1;
		}
	} while (game != 0 && game != 1);
	cout << endl;
	return game; //Returns either 0 or 1 depending on the user's input.
}

int wins() //Counts wins and returns the value to be called when the program ends and output score. 
{
	static int win = -1;
	win++;
	return win;
}

void winResponse() //Picks and displays one of 10 random statements whe guessing the number correctly.
{
	int endStatement = rand() % 10;
	switch (endStatement)
	{
	case 0: cout << "You win!" << endl;
		break;
	case 1: cout << "You're a winner!" << endl;
		break;
	case 2: cout << "You are correct!" << endl;
		break;
	case 3: cout << "That is the correct answer!" << endl;
		break;
	case 4: cout << "Nice job!" << endl;
		break;
	case 5: cout << "Good work!" << endl;
		break;
	case 6: cout << "You have succeded!" << endl;
		break;
	case 7: cout << "You did it!" << endl;
		break;
	case 8: cout << "Success" << endl;
		break;
	case 9: cout << "Victory" << endl;
		break;
	}
}

int losses() //Counts losses and returns the value to be called when the program ends and output score. 
{
	static int lose = -1;
	lose++;
	return lose;
}

void lossResponse() //Picks and displays one of 10 random statements when failing to guess the number correctly.
{
	int endStatement = rand() % 10;
	switch (endStatement)
	{
	case 0: cout << "You lose!" << endl;
		break;
	case 1: cout << "You failed!" << endl;
		break;
	case 2: cout << "You are a failure!" << endl;
		break;
	case 3: cout << "Ya dun goofed." << endl;
		break;
	case 4: cout << "Ok, I need you to understand. No, seriously, please, I need you to know that you are absolutely terrible. You couldn't even guess a number. Pathetic." << endl;
		break;
	case 5: cout << "Can you please stop being bad?" << endl;
		break;
	case 6: cout << "u stinky" << endl;
		break;
	case 7: cout << "You have as many brain cells as a sandwich." << endl;
		break;
	case 8: cout << "You fool. You absolute baffoon. You fell for one of the clasic blunders." << endl;
		break;
	case 9: cout << "(Insert Generic Failure Message Here)" << endl; //yes this was intentional 
	}
}

void replayResponse() //Picks and displays one of 10 random statements when being prompted to play again.
{
	int endStatement = rand() % 10;
	switch (endStatement)
	{
	case 0: cout << "Would you like to play again?" << endl;
		break;
	case 1: cout << "Replay?" << endl;
		break;
	case 2: cout << "Try again?" << endl;
		break;
	case 3: cout << "Another round?" << endl;
		break;
	case 4: cout << "Play again?" << endl;
		break;
	case 5: cout << "Are you ready to play another round?" << endl;
		break;
	case 6: cout << "Ready for another?" << endl;
		break;
	case 7: cout << "Go again" << endl;
		break;
	case 8: cout << "Continue?" << endl;
		break;
	case 9: cout << "Ready to play again?" << endl;
		break;
	}
	cout << "0: Yes" << endl << "1: No" << endl << endl;
}