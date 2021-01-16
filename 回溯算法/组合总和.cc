//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
   vector<vector<int>>res;
   void dfs(vector<int>& arr ,int target ,vector<int>tmp,int startIndex)
   {
      if(target<=0) 
      {
        if(target==0)
        res.push_back(tmp);
        return;
      }
      for(int i=startIndex;i<arr.size();i++)
      {
         tmp.push_back(arr[i]);
         dfs(arr,target-arr[i],tmp,i+1);
         tmp.pop_back();
      }
   }
   
   vector<vector<int>> combinationSum(vector<int>arr,int target)
   {
    dfs(arr,target,vector<int>(),0);     
    return res;
   }
};
int main()
{
  vector<int>arr = {1,2,3,4,5,6};
  Solution s;
  vector<vector<int>>res = s.combinationSum(arr,7);
  for(int i=0;i<res.size();i++)
  {
    for(int j=0 ; j < res[i].size() ;j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
