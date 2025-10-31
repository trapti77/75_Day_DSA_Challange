// Number of bit in Binary

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

int main()
{
    int n ;
    cin >> n;

    cout << hammingWeight(n);

    return 0;
}