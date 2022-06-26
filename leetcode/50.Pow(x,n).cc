#include <vector>
#include <math.h>
#include <iostream>
#include <functional>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {

    if (n < 0) {
      x = 1 / x;
      n = -1;
    }
    function<double(double, int)> dfs;
    dfs = [&](double x, int n) -> int {
      if (n == 0)
        return 1.0;
      double tmp = dfs(x, n / 2);
      return n % 2 == 0 ?tmp * tmp : tmp * tmp * x;
    };
    return dfs(x,n);
  }
};


int main(int argc, char *argv[]) {
  Solution solution;
  solution.myPow(2.0, 10);
  cout << solution.myPow(2.0, 10);
  return 0;
}

