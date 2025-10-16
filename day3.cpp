//Contain Duplicate Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto e : mp)
    {
        if (e.second > 1)
        {
            return true;
        }
    }
    return false;
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
    cout << containsDuplicate(num);
    return 0;
}