#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int myAtoi(string s)
  {
    int begin = 0;
    while(begin < s.size() && s[begin] == ' ')
    {
        begin++;
    }
    int isPostive = 1;

    if(s[begin] == '-' || s[begin] == '+')
    {
        if(s[begin] == '-')
        {
            isPostive = -1;
        }
        begin++;
    }

    long long ans = 0;
    while(begin < s.size() && isdigit(s[begin]))
    {
        ans = ans * 10 + s[begin] - '0';
        if(ans > INT_MAX)
        {
            break;
        }
        begin++;
    }
    ans = ans * isPostive;
    if(ans < INT_MIN)
    {
        return INT_MIN;
    }
    if(ans > INT_MAX)
    {
        return INT_MAX;
    }
    return ans;
  }
};

int main()
{
    Solution s;
    string str = "words and 987";
    s.myAtoi("words and 987");
    if(isdigit('9'))
    {
        std::cout<<"qiaosho"<<std::endl;
    }
}