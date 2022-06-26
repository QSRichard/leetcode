#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution
{
public:
  int cuttingRope(int n)
  {

    vector<int> base(n + 1);
    for (int i = 0; i < base.size(); i++)
    {
      base[i] = i;
    }

    int ans = 1;

    function<void(int, int, int)> dfs;
    dfs = [&](int index, int sum, int exp) {
      if (index > n || sum > n)
        return;
      if (sum == n)
      {
        if (exp > ans)
          ans = exp;
        return;
      }
      sum += base[index];
      dfs(index, sum, exp * base[index]);
      sum -= base[index];
      dfs(index + 1, sum, exp);
    };
    dfs(1, 0, 1);
    return ans;
  }
};


int main(int argc,char* argv[]){
  Solution solution;
  cout<<solution.cuttingRope(10);

  return 0;
}