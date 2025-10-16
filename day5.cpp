//Maximum Subarray Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    int maxe = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum < 0)
        {
            maxe = max(maxe, sum);
            sum = 0;
        }
        else
        {
            maxe = max(maxe, sum);
        }
    }
    return maxe;
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
    cout<< maxSubArray(num);
    
    return 0;
}