#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    string ans = a.size() > b.size() ? a : b;
    string addNumber = a.size() > b.size() ? b : a;
    int carry = 0;
    for (int i = 1; i <= addNumber.size(); i++)
    {
      if (ans[ans.size() - i] == addNumber[addNumber.size() - i])
      {
        if (ans[ans.size() - i] == '0')
        {
          ans[ans.size() - i] = ans[ans.size() - i] + carry;
          carry = 0;
        }
        else
        {
          ans[ans.size() - i] = '0' + carry;
          carry = 1;
          cout<<ans<<endl;
        }
      }
      else
      {
        ans[ans.size() - i] = carry == 0 ? '1' : '0';
        carry = ans[ans.size() - i] == '1' ? 0 : 1;
      }
    }
    int index = ans.size() - addNumber.size() - 1;
    while (carry && index >= 0)
    {
      ans[index] = ans[index] == '0' ? '1' : '0';
      carry = ans[index] == '0' ? 1 : 0;
      index--;
    }
    if (carry)
    {
      string tmp = ans;
      ans.insert(ans.begin(), 1, '1');
    }
    return ans;
  }
};

int main(int argc, char* argv[])
{
  Solution solution;
  cout << solution.addBinary("11", "1") << endl;
  return 0;
}