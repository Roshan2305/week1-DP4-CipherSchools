#include<bits/stdc++.h>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int n = row*col;
        
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
        
        vector<int> ans;
        
        while(count < n)
        {
            // print starting row
            for(int i=startingCol; count < n && i<=endingCol; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            
            // print ending col
            for(int i=startingRow; count < n && i<=endingRow; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            
            // print ending Row
             for(int i=endingCol;count < n && i>= startingCol; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                 count++;
            }
            endingRow--;
            
            // print starging Col
            
             for(int i=endingRow; count < n && i>= startingRow; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                 count++;
            }
            startingCol++;
        }
        return ans;
    }

int main()
{
    vector<vector<int>> matrix{
        {1,2,3}, 
        {4,5,6},
        {7,8,9}
    };
    vector<int> ans = spiralOrder(matrix);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}