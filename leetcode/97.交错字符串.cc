#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class Solution
{
public:
  bool isInterleave(string s1, string s2, string s3)
  {
    if (s1.size() + s2.size() != s3.size())
      return false;
    
    bool flag = false;

    function<void(int, int, int)> dfs;

    dfs = [&](int s1Index, int s2Index, int s3Index) {
      if (s3Index == s3.size())
        flag = true;
      if (flag)
        return;
      // 递增s1;
      int s1Add = 0;
      int x = s1Index, y = s3Index;
      while (x < s1.size() && y < s3.size() && s1[x] == s3[y])
      {
        s1Add++;
        x++;
        y++;
      }

      int s2Add = 0;
      int xx = s2Index, yy = s3Index;
      while (xx < s2.size() && yy < s3.size() && s2[xx] == s3[yy])
      {
        s2Add++;
        xx++;
        yy++;
      }

      if (s1Add == s2Add == 0)
        return;
      for (int i = 1; i <= s1Add; i++)
      {
        if (flag)
          return;
        dfs(s1Index + i, s2Index, s3Index + i);
      }

      for (int i = 1; i <= s2Add; i++)
      {
        if (flag)
          return;
        dfs(s1Index, s2Index + i, s3Index + i);
      }
    };

    dfs(0, 0, 0);
    return flag;
  }
};