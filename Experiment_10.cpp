// Using KMP (Knuth–Morris–Pratt)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string &pat) {
    int patLen = pat.size();
    vector<int> lpsArray(patLen, 0);

    int prefixLen = 0; // length of previous longest prefix suffix
    int idx = 1;

    while (idx < patLen) {
        if (pat[idx] == pat[prefixLen]) {
            prefixLen++;
            lpsArray[idx] = prefixLen;
            idx++;
        } else {
            if (prefixLen != 0) {
                prefixLen = lpsArray[prefixLen - 1];
            } else {
                lpsArray[idx] = 0;
                idx++;
            }
        }
    }
    return lpsArray;
}

// KMP Search
vector<int> KMP(const string &sourceText, const string &queryPattern) {
    vector<int> matchingIndices;
    int sourceLen = sourceText.size(), patLen = queryPattern.size();

    if (patLen == 0 || patLen > sourceLen) return matchingIndices;

    vector<int> lpsArray = buildLPS(queryPattern);

    int textIdx = 0, patIdx = 0;
    while (textIdx < sourceLen) {
        if (sourceText[textIdx] == queryPattern[patIdx]) {
            textIdx++; patIdx++;
        }

        if (patIdx == patLen) {
            matchingIndices.push_back(textIdx - patIdx);
            patIdx = lpsArray[patIdx - 1];
        } else if (textIdx < sourceLen && sourceText[textIdx] != queryPattern[patIdx]) {
            if (patIdx != 0)
                patIdx = lpsArray[patIdx - 1];
            else
                textIdx++;
        }
    }
    return matchingIndices;
}

int main() {
    string sourceStr, patternStr;

    cout << "Enter the main text string: ";
    getline(cin, sourceStr);

    cout << "Enter the pattern to search: ";
    getline(cin, patternStr);

    vector<int> foundMatches = KMP(sourceStr, patternStr);

    if (foundMatches.empty())
        cout << "OUTCOME: Pattern was not found!\n";
    else {
        cout << "OUTCOME: Pattern matches at positions: ";
        for (int index : foundMatches)
            cout << index << " ";
        cout << endl;
    }

    return 0;
}
