#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1)
      return strs[0];
    sort(strs.begin(), strs.end());
    string &low = strs[0];
    string &high = strs[strs.size() - 1];
    int k = 0;
    while (k < low.size() && low[k] == high[k])
      k++;
    if (k == 0)
      return "";
    return strs[0].substr(0, k);
  }
};