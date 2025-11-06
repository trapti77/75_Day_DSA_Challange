#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// Brute Forc Approach ---- O(n^3)  
void SetZeroMatrix1(vector<vector<int>> &nums)
{
    
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    nums[k][j] = -1;
                }
                for (int k = 0; k < n; k++)
                {
                    nums[i][k] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i][j] == -1)
            {
                nums[i][j] = 0;
            }
        }
    }
}

// Better Approach ---- Tc--O(n^2)  SC-O(2*n);
void SetZeroMatrix2(vector<vector<int>> &nums)
{

    int n = nums.size();
    vector<int>row(n,0);
    vector<int> col(n,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i]==1||col[j]==1)
            {
                nums[i][j] = 0;
            }
        }
    }
}

// Optimized Approach ---- 
void SetZeroMatrix(vector<vector<int>> &nums)
{

    int n = nums.size();
    vector<int> row(n, 0);
    vector<int> col(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                nums[i][j] = 0;
            }
        }
    }
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
    SetZeroMatrix(nums);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< nums[i][j];
        }
        cout << endl;
    }
    return 0;
}