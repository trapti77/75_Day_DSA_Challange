// TWO SUM ARRAY PROBLEM
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH

// vector<int> twoSum(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     vector<int> ans;
//     int sum = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             sum = nums[i] + nums[j];
//             if (sum == target)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return {};
// }

// BETTER APPRACH -

//  vector<int> twoSum(vector<int> &nums, int target)
//  {
//      int n = nums.size();
//      vector<int> ans;
//      unordered_map<int, int> mp;
//      int sum = 0;
//      for (int i = 0; i < n ; i++)
//      {
//          if (mp.find(target-nums[i]) !=mp.end())
//          {
//              return {mp[target - nums[i]], i};
//          }
//          mp[nums[i]] = i;
//      }
//      return {};
//  }

// OPTIMIZED APPROACH--

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
    if(nums[i]+nums[j]==target){
        return {mp[nums[i]],mp[nums[j]]};
    }
    else if (nums[i] + nums[j]>target){
        j--;
    }
    else
    {
        i++;
    }
    }
    return {};
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    vector<int> ans = twoSum(num, t);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}