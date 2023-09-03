#include <bits/stdc++.h>
#define ll long long
#define MaI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endL "\n"
using namespace std;

void solution() {
    srand(time(0));
    int num = 1 + (rand() % 100);
    int guess = 0;

    cout << "Welcome to the Number Guessing Game!" << endL;
    cout << "The Number is Between 1 and 100. Try to guess it." << endL;

    while (guess != num) {
        cout << "Enter your guess: ";
        cin >> guess;

        int difference = abs(num - guess);

        if (guess < num)
            cout << "Too low! Try again." << endL;
        else if (guess > num)
            cout << "Too high! Try again." << endL;
        else {
            cout << "Congratulations! You guessed the number (" << num << ")." << endL;
            break;
        }
        if (difference <= 10)
            cout << "Keep Going, you are too close." << endL;
    }
}

int main() {
    solution();
    return 0;
}
