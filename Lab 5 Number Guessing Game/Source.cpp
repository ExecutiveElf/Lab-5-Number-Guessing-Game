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
using namespace std;

//Example Function

int main()
{
	void numberGuessing;
	numberGuessing();
	return 0;
}

void numberGuessing()
{
	int ranNum;
	ranNum = rand() % 100;

	while (true)
	{
		int userInput;
		int attempts = 0;

		cin >> userInput;
		attempts++;
		if (userInput = ranNum)
		{
			cout << "You got it right!";
		}
		if (attempts = 20)
		{
			cout << "You have failed!";
		}
	}
}