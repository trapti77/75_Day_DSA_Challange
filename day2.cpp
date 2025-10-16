// BUY AND SELL ARRAY PROBLEM
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums)
{
    int n = nums.size();
    int m = INT_MAX;
    int buy = nums[0];
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < buy)
        {
            buy = nums[i];
        }
        else
        {
            int cost = nums[i] - buy;
            profit = max(profit, cost);
        }
    }
    return profit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout<<maxProfit(num);
    return 0;
}