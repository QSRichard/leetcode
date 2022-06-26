#include <vector>
#include <math.h>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int>& heights)
  {
    stack<int> s;
    int ans = -1;
    for (int i = 0; i < heights.size(); i++)
    {
      while (!s.empty() && heights[s.top()] > heights[i])
      {
        int h = heights[s.top()];
        s.pop();
        int weight = i;
        if (!s.empty())
        {
          weight = i - s.top() - 1;
        }
        ans = max(ans, h * weight);
      }
      s.push(i);
    }

    while (!s.empty())
    {
      int h = heights[s.top()];
      s.pop();
      int weight = heights.size();
      if (!s.empty())
      {
        weight = heights.size() - s.top() - 1;
      }
      ans = max(ans, h * weight);
    }
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  vector<int> h = {2, 1, 5, 6, 2, 3};
  cout<<solution.largestRectangleArea(h)<<endl;

  return 0;
}