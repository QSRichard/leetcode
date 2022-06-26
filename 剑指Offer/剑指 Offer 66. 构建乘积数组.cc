#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> constructArr(vector<int>& a)
  {
    if (a.empty() || a.size() < 2)
      return {};
    int len = a.size();
    vector<int> left(len), right(len);

    left[1] = a[0], right[len - 2] = a[len - 1];
    left[0] = right[len - 1] = 1;
    for (int i = 2; i < len; i++)
    {
      left[i] = left[i - 1] * a[i - 1];
    }
    for (int i = len - 3; i >= 0; i--)
      right[i] = right[i + 1] * a[i + 1];

    vector<int> ans(a.size());
    for (int i = 0; i < a.size(); i++)
    {
      ans[i] = left[i] * right[i];
    }
    return ans;
  }
};