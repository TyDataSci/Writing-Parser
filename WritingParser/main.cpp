#include <iostream>
#include <string>
using namespace std;


string ShortenSpace(string userLine) {
    string findStr = "  ";
    size_t strPos = 0;

    while (userLine.find(findStr) != string::npos) {
        strPos = userLine.find(findStr);
        userLine.insert(strPos + 2, " ");
        userLine.replace(strPos, 2, "");
    }

    return userLine;
}

string ReplaceExclamation(string userLine) {
    string findStr = "!";
    size_t strPos = 0;

    while (userLine.find(findStr) != string::npos) {
        strPos = userLine.find(findStr);
        userLine.insert(strPos + 1, ".");
        userLine.replace(strPos, 1, "");
    }

    return userLine;
}

int  FindText(string findStr, string userPhrase) {
    int count = 0;
    int i = 0;
    size_t found = 0;

    while ((found = userPhrase.find(findStr, found + i)) != string::npos) {
        i++;
        count++;
    }
    return count;
}

int GetNumOfNonWSCharacters(const string userStr) {
    int charCount = 0;

    for (int i = userStr.length(); i > 0; i--) {
        if (userStr[i] != ' ') {
            charCount += 1;
        }
    }
    return charCount;
}

int GetNumOfWords(const string userStr) {
    int wordCount = 1;
    int NUM_SIZE = userStr.length();

    for (int i = userStr.length(); i > 0; i--) {
        if (userStr[i] == ' ' && i != NUM_SIZE - 1 && userStr[i - 1] != ' ') {
            wordCount += 1;
        }
    }
    return wordCount;
}


string PrintMenu(string userStr) {

    char option;
    string findStr;

    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl << endl;

    cout << "Choose an option:" << endl;
    cin >> option;

    switch (option) {

    case 'q':
    case 'Q':
        break;

    case 'c':
    case 'C':
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userStr) << endl << endl;
        PrintMenu(userStr);
        break;


    case 'w':
    case 'W':
        cout << "Number of words: " << GetNumOfWords(userStr) << endl << endl;
        PrintMenu(userStr);
        break;

    case 'F':
    case 'f':
        cin.ignore();
        cout << "Enter a word or phrase to be found:" << endl;
        getline(cin, findStr);
        cout << "\"" << findStr << "\" instances: " << FindText(findStr, userStr) << endl << endl;
        PrintMenu(userStr);
        break;

    case 'R':
    case 'r':
        cout << "Edited text: " << ReplaceExclamation(userStr) << endl << endl;
        PrintMenu(userStr);
        break;

    case 'S':
    case 's':
        cout << "Edited text: " << ShortenSpace(userStr) << endl << endl;
        PrintMenu(userStr);
        break;

    default:
        PrintMenu(userStr);

    }

    return "";
}


int main() {

    string inputText;

    cout << "Enter a sample text:" << endl << endl;
    getline(cin, inputText);
    cout << "You entered: " << inputText << endl << endl;
    PrintMenu(inputText);


    return 0;
}
