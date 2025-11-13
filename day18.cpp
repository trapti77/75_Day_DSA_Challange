#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// Brute Forc Approach ----
bool exist(vector<vector<string>> &board,string word)
{
   
}

int main()
{
    int n,m;
    cin >> n>>m;
    string word;
    cin >> word;
    vector<vector<string>> board(n,vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    bool res = exist(board, word);
    if (res == true)
    {
        cout << "exist" << endl;
    }
   else
   {
       cout << "not exist" << endl;
   }
   
    return 0;
}