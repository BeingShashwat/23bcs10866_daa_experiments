// 0-1 Knapsack

#include <iostream>
#include <vector>
using namespace std;

bool checkSubsetSum(vector<int>& items, int sum) {
    int itemCount = items.size();
    vector<vector<bool>> memo(itemCount + 1, vector<bool>(sum + 1, false));

    // Sum 0 is always possible (by selecting no elements)
    for (int i = 0; i <= itemCount; i++)
        memo[i][0] = true;

    // Fill DP table
    for (int i = 1; i <= itemCount; i++) {
        for (int j = 1; j <= sum; j++) {
            if (items[i - 1] <= j)
                memo[i][j] = memo[i - 1][j] || memo[i - 1][j - items[i - 1]];
            else
                memo[i][j] = memo[i - 1][j];
        }
    }
    return memo[itemCount][sum];
}

int main() {
    int itemCount, capacityLimit;
    cout << "Count of items available: ";
    cin >> itemCount;

    vector<int> weights(itemCount);
    cout << "Enter weights: ";
    for (int i = 0; i < itemCount; i++)
        cin >> weights[i];

    cout << "Enter maximum capacity: ";
    cin >> capacityLimit;

    if (checkSubsetSum(weights, capacityLimit))
        cout << "YES: Items with sum " << capacityLimit << " can be selected!" << endl;
    else
        cout << "NO: Cannot achieve sum of " << capacityLimit << "!" << endl;

    return 0;
}
