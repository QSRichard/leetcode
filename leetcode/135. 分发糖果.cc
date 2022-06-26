#include <vector>

using namespace std;

class Solution
{
public:
  int candy(vector<int>& ratings)
  {
    int len = ratings.size();
    vector<int> ans(len, 1);
    if (ratings[0] > ratings[1])
      ans[0] = max(ans[1] + 1, ans[0]);
    if (ratings[len - 1] > ratings[len - 2])
      ans[len - 1] = max(ans[len - 2] + 1, ans[len - 1]);
    for (int i = 1; i < len - 1; i++)
    {
      if (ratings[i] > ratings[i - 1])
        ans[i] = max(ans[i], ans[i - 1] + 1);
      if (ratings[i] > ratings[i + 1])
        ans[i] = max(ans[i], ans[i + 1] + 1);
    }
    if (ratings[0] > ratings[1])
      ans[0] = max(ans[1] + 1, ans[0]);
    if (ratings[len - 1] > ratings[len - 2])
      ans[len - 1] = max(ans[len - 2] + 1, ans[len - 1]);
    for (int i = len - 2; i >= 1; i--)
    {
      if (ratings[i] > ratings[i - 1])
        ans[i] = max(ans[i], ans[i - 1] + 1);
      if (ratings[i] > ratings[i + 1])
        ans[i] = max(ans[i], ans[i + 1] + 1);
    }
    if (ratings[0] > ratings[1])
      ans[0] = max(ans[1] + 1, ans[0]);
    if (ratings[len - 1] > ratings[len - 2])
      ans[len - 1] = max(ans[len - 2] + 1, ans[len - 1]);
    int ret = 0;
    for (int i = 0; i < ans.size(); i++)
      ret += ans[i];
    return ret;
  }
};