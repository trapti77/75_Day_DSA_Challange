// Arrange Bag Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int user_logic(const string &s)
{
    // User will write their logic here
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    int ans = 0;
    int odd = 0;
    for (auto e : freq)
    {
        if (e.second % 2 == 0)
        {
            ans += e.second;
        }
        else
        {
            if (odd <= 0)
            {
                ans += e.second;
                odd += e.second;
            }
        }
    }
    return ans; // Placeholder return value
}

int main()
{
    string str;
    cin >> str;

    cout << user_logic(str);

    return 0;
}