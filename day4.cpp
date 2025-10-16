// Product Of Accept self Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int c = 0;
    vector<int> ans(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            c++;
        }
    }
    if (c > 1)
    {
        return ans;
    }
    else if (c == 1)
    {
        int p = 1;
        int id = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                id = i;
                continue;
            }
            else
            {
                ans[i] = 0;
                p *= nums[i];
            }
        }
        ans[id] = p;
    }
    else
    {
        int p = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            p *= nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int n = p / nums[i];
            ans[i] = n;
        }
    }
    return ans;
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
    vector<int> ans = productExceptSelf(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}