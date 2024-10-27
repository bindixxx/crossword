#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printCrossword(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed[i]) {
            cout << "\033[1;33m" << word[i] << "\033[0m ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool checkLetter(const string& word, char letter, vector<bool>& guessed) {
    bool found = false;
    for (size_t i = 0; i < word.size(); ++i) {
        if (tolower(word[i]) == tolower(letter)) {
            guessed[i] = true;
            found = true;
        }
    }
    return found;
}

int main() {
    string word;
    cout << "Enter the word for the crossword puzzle: ";
    cin >> word;

    vector<bool> guessed(word.size(), false);

    char letter;
    while (true) {
        printCrossword(word, guessed);
        cout << "Enter a letter (or '0' to exit): ";
        cin >> letter;

        if (letter == '0') {
            cout << "You are out of the game." << endl;
            break;
        }

        if (checkLetter(word, letter, guessed)) {
            cout << "You guessed the letter!" << endl;
        }
        else {
            cout << "The letter is not in the word." << endl;
        }

        if (all_of(guessed.begin(), guessed.end(), [](bool g) { return g; })) {
            cout << "Congratulations! You guessed the word: " << word << endl;
            break;
        }
    }

    return 0;
}
