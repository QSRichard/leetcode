#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  int lastRemaining(int n, int m)
  {
    int ans = 0;
    for (int i = 2; i <= n; i++)
      ans = (ans + m) % i;
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  cout<<solution.lastRemaining(10, 17);
  return 0;
}