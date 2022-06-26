#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findContinuousSequence(int target)
  {
    vector<vector<int>> ans;
    int left = 1, right = 1;
    int sum = 0;
    //  [left,right);
    while (left <= target/2)
    {
      if (sum == target)
      {
        vector<int> tmp;
        for (int i = left; i < right; i++)
          tmp.push_back(i);
        ans.push_back(tmp);
        sum -= left;
        left++;
      }
      else if (sum < target)
      {
        sum += right;
        right++;
      }
      else if (sum > target)
      {
        sum -= left;
        left++;
      }
    }
    return ans;
  }
};