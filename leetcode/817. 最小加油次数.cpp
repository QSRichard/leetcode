#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
  {
    priority_queue<int, vector<int>, less<int>> q;

    int local = 0;
    int ans = 0;
    int index = 0;
    int remain = startFuel;

    while(local < target)
    {
        if(remain == 0)
        {
            if(!q.empty())
            {
                ans++;
                remain = q.top();
                q.pop();
            }
            else
            {
                return -1;
            }
        }
        local += remain;
        remain = 0;
        while(index < stations.size() && stations[index][0] <= local)
        {
            q.push(stations[index][1]);
            index++;
        }
    }
    return ans;
  }
};