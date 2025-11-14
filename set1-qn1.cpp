/*
you are given two strings s and t, find the length of the smallest substring in s that contains all the characters in t(including multiplicities). if no such substring exists, print -1.
sample input:
s = "ADOBECODEBANC"
t = "ABC"
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (t.size() > s.size()) {
        return "";
    }

    vector<int> need(128, 0);
    for (char c : t) {
        need[c]++;
    }

    int required = t.size();
    int left = 0;
    int minLen = INT_MAX;
    int startIndex = 0;

    for (int right = 0; right < s.size(); right++) {
        if (need[s[right]] > 0) {
            required--;
        }
        need[s[right]]--;

        while (required == 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIndex = left;
            }

            need[s[left]]++;
            if (need[s[left]] > 0) {
                required++;
            }
            left++;
        }
    }

    if (minLen == INT_MAX) {
        return "";
    }

    return s.substr(startIndex, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string ans = minWindow(s, t);

    if (ans == "") {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}
