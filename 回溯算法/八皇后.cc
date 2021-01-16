//设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整个棋盘的那两条对角线。
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
  vector<vector<string>>res;
  bool judge(vector<string>& map,int rows,int cols){
     //同行不能有
     int r = rows;
     int l = cols;
     for(int i=0;i<map[0].size();i++){
       if(map[rows][i]=='Q'){
         return false;
       }
     }
     //同列不能有
     r=rows;
     l=cols;
     for(int i=0;i<map.size();i++){
       if(map[i][cols]=='Q'){
         return false;
       }
     }
     //左上
     r=rows;
     l=cols;
     while(r>=0 && l>=0){
       if(map[r][l]=='Q'){
         return false;
       }
       r--;
       l--;
     }
     //右下
     while(r<map.size() && l < map[0].size()){
       if(map[r][l] == 'Q'){
         return false;
       }
       r++;
       l++;
     }
     //右上
     r=rows;
     l=cols;
     while(l < map[0].size() && r >= 0){
       if(map[r][l] == 'Q'){
         return false;
       }
       r--;
       l++;
     }
     //左下
     r=rows;
     l=cols;
     while(r < map.size() && l>=0){
       if(map[r][l]=='Q'){
         return false; 
       }
       r++;
       l--;
     }
     return true;
  }
  void dfs(vector<string>tmp,int n,int row){
    if(row>=n){
      res.push_back(tmp);
      return;
    }
    for(int i=0;i<n;i++){
      if(!judge(tmp,row,i)){
        continue;
      }
      tmp[row][i] = 'Q';
      dfs(tmp,n,row+1);
      tmp[row][i] = '.';
    }
  }
  vector<vector<string>> solvequeen(int n){
    vector<string>arr(n,string(n,'.'));
    dfs(arr,n,0);
    return res; 
  }
};
int main(){
  Solution s;
  vector<vector<string>>arr= s.solvequeen(4);
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[0].size();j++)
    {
      cout << arr[i][j] << endl;
    }
    cout << endl;
  }
}
