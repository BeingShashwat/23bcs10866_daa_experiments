// Naive String Search

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findOccurrences(const string &mainText, const string &searchPattern) {
    vector<int> matchPositions;
    int textLength = mainText.size();
    int patternLength = searchPattern.size();

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (mainText[i + j] != searchPattern[j])
                break;
        }
        if (j == patternLength)
            matchPositions.push_back(i);
    }
    return matchPositions;
}

int main() {
    string inputText, inputPattern;

    cout << "Input the main text: ";
    getline(cin, inputText);

    cout << "Input the search pattern: ";
    getline(cin, inputPattern);

    vector<int> matchResults = findOccurrences(inputText, inputPattern);

    if (matchResults.empty())
        cout << "RESULT: Pattern not located!\n";
    else {
        cout << "RESULT: Pattern matches at positions: ";
        for (int position : matchResults)
            cout << position << " ";
        cout << endl;
    }

    return 0;
}
}
