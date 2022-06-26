#include <string>

using namespace std;

class Solution
{
public:
  string reverseLeftWords(string s, int n)
  {
    if (n == s.size())
      return s;
    string left = s.substr(0, n);
    string right = s.substr(n, s.size() - n);
    return right + left;
  }
};
