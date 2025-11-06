#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int i = nums[0];
        int j = 0;
        while(j<n){
            if(i+1!=nums[j+1]){
                
            }
        }
        return ans;
    }

    int main()
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<int> ans = findMissingElements(nums);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        return 0;
    }