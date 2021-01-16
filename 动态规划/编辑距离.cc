/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
*/
#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
class Solution{
  public:
    int minDistance(string word1,string word2){
      vector<vector<int>>arr(word1.size()+1,vector<int>(word2.size()+1,INT_MAX));
      for(int i=0;i<arr.size();i++){
        arr[i][0] = i;
      }
      for(int i=0;i<arr[0].size();i++){
        arr[0][i] = i;
      }
      for(int i=1;i<=word1.size();i++) {
        for(int j=1;j<=word2.size();j++){
          if(word1[i-1] == word2[j-1]){
            arr[i][j] = arr[i-1][j-1];
          }else{
            int num1 = arr[i-1][j] + 1 ; 
            int num2 = arr[i-1][j-1] + 1;
            int num3 = arr[i][j-1] + 1;
            arr[i][j]   = min(num3,min(num1,num2));
          }
        }
      }
      return arr[word1.size()][word2.size()];
    }
};
int main(){
  string word1 = "horse", word2 = "ros";
  Solution s;
  cout << s.minDistance(word1,word2) << endl;
  return 0;
}
