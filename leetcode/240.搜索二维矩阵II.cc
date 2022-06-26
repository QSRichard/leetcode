#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    for (int i = 0; i < matrix.size(); i++)
    {
      int left = 0, right = matrix[0].size() - 1;
      while (left <= right)
      {
        int mid = (left + right) / 2;
        if (matrix[i][mid] == target)
          return true;
        if (matrix[i][mid] < target)
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
    return false;
  }
};