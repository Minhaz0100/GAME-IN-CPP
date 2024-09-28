#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int playerGuess, randomNumber;
    char playAgain;
    int balance = 100;
    int betAmount;

    srand(time(0));

    cout << "Welcome to the Casino Number Guessing Game!\n";
    cout << "You start with a balance of $100. Try to guess the number to win!\n";

    do {
        do {
            cout << "Place your bet (you have $" << balance << "): ";
            cin >> betAmount;
            if (betAmount > balance || betAmount <= 0) {
                cout << "Invalid bet amount! Please bet within your balance.\n";
            }
        } while (betAmount > balance || betAmount <= 0);

        randomNumber = rand() % 100 + 1;

        cout << "Guess a number between 1 and 100: ";
        cin >> playerGuess;

        if (playerGuess == randomNumber) {
            cout << "Congratulations! You've guessed the correct number!\n";
            balance += betAmount;
            cout << "You won $" << betAmount << "! Your new balance is $" << balance << ".\n";
        } else {
            cout << "Sorry, the correct number was " << randomNumber << ". You lost your bet.\n";
            balance -= betAmount;
            cout << "Your new balance is $" << balance << ".\n";
        }

        if (balance > 0) {
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
        } else {
            cout << "You are out of balance! Game over.\n";
            break;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Your final balance is $" << balance << ".\n";

    return 0;
}
