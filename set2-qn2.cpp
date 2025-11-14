/*
you are given an array nums of length n and an integer k.
return the number of contiguous subarrays whose sum equals to k.
sample input:
nums = [1,1,1,2,1]
k = 3
*/

#include <bits/stdc++.h>
using namespace std;

int subarraySumEqualsK(const vector<int>& nums, int k) {
    unordered_map<long long,int> count;
    count[0] = 1;
    long long cur = 0;
    int result = 0;
    for (int x : nums) {
        cur += x;
        if (count.find(cur - k) != count.end()) result += count[cur - k];
        count[cur]++; 
    }
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,1};
    int k = 3;
    cout << subarraySumEqualsK(nums, k) << '\n'; // prints 3
    return 0;
}
