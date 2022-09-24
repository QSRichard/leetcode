#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
  int magicTower(vector<int>& nums)
  {
    priority_queue<int, vector<int>, greater<int>> q;
    long long sum = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if(sum <= 0)
    {
        return -1;
    }
    long long boold = 1;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] < 0)
        {
            q.push(nums[i]);
            if(nums[i] + boold <= 0)
            {
                long long t = q.top();
                boold -= t;
                ans++;
                q.pop();
            }
        }
        boold += nums[i];
    }
    return ans;
  }
};