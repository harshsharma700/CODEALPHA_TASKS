#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

void playGame() {
    srand(time(0)); // Seed random number generator
    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "🎉 Welcome to the Number Guessing Game! 🎉\n";
    cout << "I have chosen a number between 1 and 100.\n";
    cout << "Can you guess what it is? 🤔\n";

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "📉 Too high! Try again.\n";
        } else if (guess < secretNumber) {
            cout << "📈 Too low! Try again.\n";
        } else {
            cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts! 🎯\n";
        }
    } while (guess != secretNumber);
}

int main() {
    char choice;

    do {
        playGame(); // Start a new game

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing! Goodbye! 👋\n";

    return 0;
}
