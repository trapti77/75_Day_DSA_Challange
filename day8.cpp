// 3 SUM Array Problem

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach  o(n^3)
vector<vector<int>>ThreeSum1(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> st;
    for (int i = 0; i < n - 2;i++){
        for (int j = i + 1; j < n - 1;j++){
            for (int k = j + 1; k < n;k++){
                
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> num;
                    num.push_back(nums[i]);
                    num.push_back(nums[j]);
                    num.push_back(nums[k]);
                    sort(num.begin(), num.end());
                    st.insert(num);
                }
            }
        }
    }
    for (auto& e:st){
        ans.push_back(e);
    }
        return ans;
}

//using Binary Search O(n^2logn)

vector<vector<int>> ThreeSum2(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            vector<int> num;
            int e = nums[i] + nums[j];
            int s, h;
            s = j + 1;
            h = n - 1;
            while(s<=h){
                int m=s+(h-s)/2;
                if(nums[m]+e==0){
                    num.push_back(nums[i]);
                    num.push_back(nums[j]);
                    num.push_back(nums[m]);
                    sort(num.begin(), num.end());
                    st.insert(num);
                    break;
                }
                else if ((nums[m] + e)>0){
                    h--;
                }
                else
                {
                    s++;
                }  
            }
        }
    }
    for (auto &e : st)
    {
        ans.push_back(e);
    }
    return ans;
}

vector<vector<int>> ThreeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
            vector<int> num;
            int e = nums[i];
            int s, h;
            s = i + 1;
            h = n - 1;
            while (s <= h)
            {
                if (nums[s]+nums[h] + e == 0)
                {
                    num.push_back(nums[i]);
                    num.push_back(nums[s]);
                    num.push_back(nums[h]);
                    sort(num.begin(), num.end());
                    st.insert(num);
                    break;
                }
                else if ((nums[s] + nums[h] + e) > 0)
                {
                    h--;
                }
                else
                {
                    s++;
                }
            }
    }
    for (auto &e : st)
    {
        ans.push_back(e);
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
    vector<vector<int>> ans = ThreeSum(num);
    for (int i = 0; i < ans.size();i++){
        for (int j = 0; j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

        return 0;
}