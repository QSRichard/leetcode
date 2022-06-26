#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string minNumber(vector<int>& nums)
  {
    vector<string> strs;
    string ans;
    for (int i = 0; i < nums.size(); i++)
      strs.push_back(to_string(nums[i]));

    sort(strs.begin(), strs.end(), [](string& x, string& y) { return x + y < y + x; });
    for (int i = 0; i < strs.size(); i++)
      ans.append(strs[i]);
    return ans;
  }
};