// Find Min in rotated sorted  Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
//Brute Force Approach

// int findMin(vector<int> &nums)
// {
//     int n = nums.size();
//     int i = 0;
//     int j = n - 1;
//     while (i < j)
//     {
//         if (nums[i] < nums[j])
//         {
//             j--;
//         }
//         else if (nums[i] > nums[j])
//         {
//             i++;
//         }
//     }
//     int ans = nums[j];
//     return ans;
// }


//Binary search Approach
int findMin(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int m = (i + j) / 2;
        if (nums[m] < nums[j])
        {
            j = m;
        }
        else if (nums[m] > nums[j])
        {
            i = m + 1;
        }
    }
    int ans = nums[j];

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
    cout << findMin(num);

    return 0;
}