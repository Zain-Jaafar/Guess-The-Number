#include <iostream>
#include <cstdlib> // Use this lib to get random number
#include <ctime> // Use this lib to get current time

int main() {
    srand(time(NULL)); // Set seed for pseudo-random number based on current unix time.

    int attemptsRemaining = 5;
    int randomNumber = rand() % 100 + 1;
    int playerGuess;
    bool playerWon;
    std::string restart;

    // Intro
    std::cout << "Welcome to Guess The Number!!!" << "\n";
    std::cout << "You need to guess a number between 1 and 100" << "\n";
    std::cout << randomNumber << "\n";

    // Main Game Loop
    while (attemptsRemaining > 0) {
        std::cout << "You have " << attemptsRemaining << " attempts remaining.\n";
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        std::cout << "\n";
        
        if (playerGuess > randomNumber) {
            attemptsRemaining--;

            if (attemptsRemaining == 0) {
                playerWon = false;
                break;
            }

            std::cout << "Too High! Try Again.\n";

        } else if (playerGuess < randomNumber) {
            attemptsRemaining--;

            if (attemptsRemaining == 0) {
                playerWon = false;
                break;
            }

            std::cout << "Too Low! Try Again.\n";

        } else {
            playerWon = true;
            break;
        }
    }
    
    // Tell player if they won or not
    if (playerWon) {
        std::cout << "You Win!\nGood Job!\n\n";
    } else {
        std::cout << "You Lose!\nUnlucky...\n\n";
    }
    
    // Check if player wants to resart game
    std::cout << "Would you like to play again? [y/n]\n";
    std::cin >> restart;
    if (restart == "y") {
        std::cout << "\n\n";
        main();
    } else if (restart == "n") {
        std::cout << "GG!\n";
    }

    return 0;
}
