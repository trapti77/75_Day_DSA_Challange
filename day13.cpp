// counting bits in Binary

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int hammingWeight(int n)
{
    int c = 0;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            c++;
        }
        n /= 2;
    }
    return c;
}
vector<int> countBits(int n)
{
    vector<int> bit;
    for (int i = 0; i <= n; i++)
    {
        bit.push_back(hammingWeight(i));
    }
    return bit;
}
int main()
{
    int n;
    cin >> n;

    vector<int> ans=countBits(n);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
        return 0;
}