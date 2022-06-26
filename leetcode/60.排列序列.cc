#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string getPermutation(int n, int k)
  {
    vector<int> ans(n);
    for (int i = 1; i <= n; i++)
      ans[i - 1] = i;
    for (int i = 1; i < k; i++)
    {
      next_permutation(ans.begin(), ans.end());
    }
    string ret;
    for (int i = 0; i < ans.size(); i++)
    {
      ret.append(1, ans[i] + '0');
    }
    return ret;
  }
};