#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// Brute Forc Approach ----
void rotate1(vector<vector<int>> &nums)
{
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0)
    {
        for (int k = 0; k < n; k++)
        {
            ans[k][j] = nums[i][k];
        }
        i++;
        j--;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            nums[i][j] = ans[i][j];
        }
    }
}
void rotate(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = nums[n - j - 1][i];
        }
    }

    nums = ans;
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
    rotate(nums);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j];
        }
        cout << endl;
    }

    return 0;
}