#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int secret = rand() % 50 + 1;
    int guess;
    cout << "Number Guessing Game" << endl;
    cout << "Guess a number between 1 and 50" << endl;
    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess > secret)
            cout << "Too High!" << endl;
        else if (guess < secret)
            cout << "Too Low!" << endl;
        else
            cout << "Congratulations! You guessed the correct number." << endl;
    } while (guess != secret);
    return 0;
}