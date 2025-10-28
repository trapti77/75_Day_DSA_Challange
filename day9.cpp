//Container With Most Water Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

//Brute Force Approach
int maxArea1(vector<int> &height)
{
    int n = height.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}


// Using Two Pointer
int maxArea(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    int ans = INT_MIN;
    while (i < j)
    {
        int d = j - i;
        int m = min(nums[i], nums[j]);
        ans = max(ans, d * m);
        if (nums[i] < nums[j])
        {
            i++;
        }
        else if (nums[j] < nums[i])
        {
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
    return ans;
}

//Using Array



int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << maxArea(num);

    return 0;
}