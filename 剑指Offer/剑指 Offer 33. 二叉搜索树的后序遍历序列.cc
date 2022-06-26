#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution
{
public:
  bool verifyPostorder(vector<int>& postorder)
  {
    function<bool(int, int)> dfs;

    dfs = [&](int begin, int end) -> bool {
      if (begin >= end)
        return true;
      int rootVal = postorder[end];
      int right = begin;
      while (right < end && postorder[right] < rootVal)
        right++;

      for (int i = right; i < end; i++)
      {
        if (postorder[i] < rootVal)
          return false;
      }

      return dfs(begin, right - 1) && dfs(right, end - 1);
    };

    return dfs(0, postorder.size() - 1);
  }
};