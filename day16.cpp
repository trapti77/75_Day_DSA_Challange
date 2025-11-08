#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// Brute Forc Approach ----O(n^2)
vector<int> spiralOrder(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<int> ans;
    int rn = n - 1;
    int cn = nums[0].size() - 1;
    int r = 0;
    int c = 0;
    while (r <= rn && c <= cn)
    {
        // row
        for (int i = c; i <= cn; i++)
        {
            ans.push_back(nums[r][i]);
        }
        r++;
        // col
        for (int i = r; i <= rn; i++)
        {
            ans.push_back(nums[i][cn]);
        }
        cn--;
        // row
        if (r <= rn)
        {
            for (int i = cn; i >= c; i--)
            {
                ans.push_back(nums[rn][i]);
            }
            rn--;
        }
        // col
        if (c <= cn)
        {
            for (int i = rn; i >= r; i--)
            {
                ans.push_back(nums[i][c]);
            }
            c++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }
    vector<int>ans=spiralOrder(nums);
    
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[j] << " ";
        }
   
    return 0;
}