//你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
#include<iostream>
#include<vector>
using namespace std;
class Solution {public:
    vector<int>res;
    int dfs(vector<vector<int>>& arr,int row,int col){
      if(row<0 || row >= arr.size() || col< 0 || col >= arr[0].size() || arr[row][col] != 0){
         return 0;
      }
      arr[row][col]  = 1;
      return dfs(arr,row+1,col) + dfs(arr,row-1,col) + dfs(arr,row,col-1) + dfs(arr,row,col+1)
            +dfs(arr,row+1,col+1) +dfs(arr,row-1,col-1) + dfs(arr,row-1,col+1) + dfs(arr,row+1,col-1) + 1;
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
      for(int i=0;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
             if(land[i][j]==0) {
                res.push_back(dfs(land,i,j));
             }
        }
      }
     sort(res.begin(),res.end());
     return res;
    }
};
