#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    vector<int> r_step = {0, 1, 0, -1};
    vector<int> c_step = {1, 0, -1, 0};
    vector<int> ans;
    int colwn = matrix[0].size();
    int row = matrix.size();
    int r = 0, c = -1, loop = 0;
    int number = matrix.size() * matrix[0].size();
    while (number>0)
    {
      for (int i = 0; i < colwn && number>0; i++)
      {
        r += r_step[loop % 4], c += c_step[loop % 4];
        ans.push_back(matrix[r][c]);
        number--;
      }
      row--;
      loop++;
      for (int i = 0; i < row && number>0; i++)
      {
        r += r_step[loop % 4], c += c_step[loop % 4];
        ans.push_back(matrix[r][c]);
        number--;
      }
      colwn--;
      loop++;
    }
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  vector<vector<int>> matrix;
  matrix.push_back({1, 2, 3, 4});
  matrix.push_back({5, 6, 7, 8});
  matrix.push_back({9, 10, 11, 12});
  vector<int> ans = solution.spiralOrder(matrix);
  for (auto i = 0; i < ans.size(); i++)
  {
    cout<<ans[i]<<" ";
  }
  return 0;
}