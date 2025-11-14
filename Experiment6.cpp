// Subset-sum problem

#include <iostream>
#include <vector>
using namespace std;

bool findSubsetWithSum(vector<int>& nums, int targetSum) {
    int count = nums.size();
    vector<vector<bool>> dpTable(count + 1, vector<bool>(targetSum + 1, false));

    // Sum 0 is always possible (by selecting no elements)
    for (int i = 0; i <= count; i++)
        dpTable[i][0] = true;

    // Fill DP table
    for (int i = 1; i <= count; i++) {
        for (int j = 1; j <= targetSum; j++) {
            if (nums[i - 1] <= j)
                dpTable[i][j] = dpTable[i - 1][j] || dpTable[i - 1][j - nums[i - 1]];
            else
                dpTable[i][j] = dpTable[i - 1][j];
        }
    }
    return dpTable[count][targetSum];
}

int main() {
    int elementCount, requiredSum;
    cout << "How many elements in your array: ";
    cin >> elementCount;

    vector<int> elements(elementCount);
    cout << "Enter all elements: ";
    for (int i = 0; i < elementCount; i++)
        cin >> elements[i];

    cout << "What is the target sum value: ";
    cin >> requiredSum;

    if (findSubsetWithSum(elements, requiredSum))
        cout << "SUCCESS: Subset with sum " << requiredSum << " was found!" << endl;
    else
        cout << "FAILURE: No subset with sum " << requiredSum << " exists!" << endl;

    return 0;
}
