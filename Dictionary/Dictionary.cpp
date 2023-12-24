#include <iostream>
#include <map>
#include <string>

using namespace std;

void printMenu() {
    cout << "\nMenu:\n"
        << "1. Add a word\n"
        << "2. Remove a word\n"
        << "3. Edit a word\n"
        << "4. Find a word\n"
        << "5. Exit\n"
        << "Choose an action: ";
}

int main() {
    map<string, string> dictionary;

    while (true) {
        printMenu();

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string word, translation;
            cout << "Enter the word: ";
            getline(cin, word);
            cout << "Enter the translation: ";
            getline(cin, translation);
            dictionary[word] = translation;
            cout << "Word added to the dictionary.\n";
            break;
        }
        case 2: {
            string word;
            cout << "Enter the word to remove: ";
            getline(cin, word);
            if (dictionary.erase(word) > 0) {
                cout << "Word removed from the dictionary.\n";
            }
            else {
                cout << "Word not found in the dictionary.\n";
            }
            break;
        }
        case 3: {
            string word, newTranslation;
            cout << "Enter the word to edit: ";
            getline(cin, word);
            cout << "Enter the new translation: ";
            getline(cin, newTranslation);
            if (dictionary.find(word) != dictionary.end()) {
                dictionary[word] = newTranslation;
                cout << "Word edited.\n";
            }
            else {
                cout << "Word not found in the dictionary.\n";
            }
            break;
        }
        case 4: {
            string word;
            cout << "Enter the word to find: ";
            getline(cin, word);
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                cout << "Translation: " << it->second << "\n";
            }
            else {
                cout << "Word not found in the dictionary.\n";
            }
            break;
        }
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
