#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

class Solution
{
public:
  string multiply(string num1, string num2)
  {
    vector<int> ans(num1.size() + num2.size(), 0);
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; i--)
    {
      for (int j = num2.size() - 1; j >= 0; j--)
      {
        int p1 = i + j, p2 = i + j + 1;
        int t = (num1[i] - '0') * (num2[j] - '0');
        int sum = t + ans[p2];
        ans[p2] = sum % 10;
        ans[p1] += (sum / 10);
      }
    }
    int i = 0;
    while (i < ans.size() && ans[i] == 0)
      i++;
    string ret;
    for (; i < ans.size(); i++)
    {
      ret.append(1, '0' + ans[i]);
    }
    return ret;
  }
};