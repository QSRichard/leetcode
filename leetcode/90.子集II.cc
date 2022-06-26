#include <vector>
#include <map>
#include <functional>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    map<int,int> mp;
    for (int i = 0; i < nums.size(); i++)
      mp[nums[i]]++;
    vector<pair<int, int>> base;
    for (auto& it : mp)
      base.push_back({it.first, it.second});
    vector<vector<int>> ans;
    vector<int> subset;
    cout<<"dfs"<<endl;
    function<void(int index)> dfs;
    dfs = [&](int index) {
      if (index >= base.size())
      {
        ans.push_back(subset);
        return;
      }

      dfs(index + 1);

      for (int i = 1; i <= base[index].second; i++)
      {
        for (int j = 0; j < i; j++)
          subset.push_back(base[index].first);
        dfs(index + 1);
        for (int j = 0; j < i; j++)
          subset.pop_back();
      }
    };
    dfs(0);
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  vector<int> v = {1, 2, 2};
  solution.subsetsWithDup(v);
  return 0;
}