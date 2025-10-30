// Trapping  Water Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
int trap1(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i] && nums[i] != 0)
            {
                int m = min(nums[j], nums[i]);
                int p = m * m;
                if (p > sum)
                {
                    ans += p - sum;
                    if (i == 0 && j == n - 1)
                    {
                        return ans;
                    }
                }
                break;
            }
            sum += nums[j];
        }
    }
    return ans;
}

//with taking space  TC-O(n) SC-O(3n)
int trap2(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i] && nums[i] != 0)
            {
                int m = min(nums[j], nums[i]);
                int p = m * m;
                if (p > sum)
                {
                    ans += p - sum;
                    if (i == 0 && j == n - 1)
                    {
                        return ans;
                    }
                }
                break;
            }
            sum += nums[j];
        }
    }
    return ans;
}

//without taking space TC-O(n)
int trap(vector<int> &nums)
{
    int n = nums.size();
    int water = 0;
    int maxl = 0;
    int maxr = 0;
    int idx = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > maxr)
        {
            maxr = nums[i];
            idx = i;
        }
    }
    for (int i = 0; i < idx; i++)
    {
        int m = min(maxl, maxr);
        int d = m - nums[i];
        if (d < 0)
        {
            water += 0;
        }
        else
        {
            water += d;
        }

        if (nums[i] > maxl)
        {
            maxl = nums[i];
        }
    }
    maxl = maxr;
    maxr = 0;
    for (int i = n - 1; i > idx; i--)
    {
        int m = min(maxl, maxr);
        int d = m - nums[i];
        if (d < 0)
        {
            water += 0;
        }
        else
        {
            water += d;
        }

        if (nums[i] > maxr)
        {
            maxr = nums[i];
        }
    }
    return water;
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
    cout << trap(num);

    return 0;
}