#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int TOTAL_GUESS_CHANCE = 5;

int main() {
    int answer;
    srand(time(0)); // NOLINT
    answer = (rand() % 100) + 1; // NOLINT

    int minNumber = 1;
    int maxNumber = 100;
    int guessCount = 5;
    int guess;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    for (int chanceCount = 1; chanceCount <= TOTAL_GUESS_CHANCE; chanceCount++) {
        cout << "Range: [" << minNumber << "," << maxNumber << "], Number of guesses left: " << guessCount << endl;
        cout << "Your guess: ";
        cin >> guess;
        guessCount--;
        if (guess != answer && chanceCount == TOTAL_GUESS_CHANCE) {
            cout << "Out of guesses! My number is " << answer << endl;
            return 0;
        }

        if (guess == answer) {
            cout << "Congrats! You guessed my number in " << chanceCount << " guesses." << endl;
            return 0;
        }

        if (guess < answer) {
            minNumber = guess + 1;
            cout << "Wrong! My number is bigger." << endl;
            cout << endl;
        }
        if (guess > answer) {
            maxNumber = guess - 1;
            cout << "Wrong! My number is smaller." << endl;
            cout << endl;
        }

    }

    return 0;
}
