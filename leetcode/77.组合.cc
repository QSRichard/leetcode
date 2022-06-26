#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<vector<int>> ans;
    vector<int> base(n + 1, 1);
    vector<int> isUsed(n + 1, 0);
    vector<int> selected(k, 0);
    for (int i = 0; i < base.size(); i++)
      base[i] = i;
    function<void(int)> dfs;
    dfs = [&](int count) {
      if (count == k)
      {
        ans.push_back(selected);
        return;
      }
      auto tmp = isUsed;
      for (int i = 1; i <= n; i++)
      {
        if (isUsed[i] == 0)
        {
          isUsed[i] = 1;
          selected[count] = i;
          dfs(count + 1);
          selected[count] = 0;
        }
      }
      isUsed = tmp;
    };
    dfs(0);
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  auto ans = solution.combine(4, 2);
  for (auto& i : ans)
  {
    for (auto& item : i)
    {
      cout<<item<<" ";
    }
    cout << endl;
  }
  return 0;
}