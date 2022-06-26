#include <vector>
#include <functional>

using namespace std;

class Solution
{
public:
  vector<int> getLeastNumbers(vector<int>& arr, int k)
  {

    function<void(int, int)> downAdjust;
    downAdjust = [&](int low, int high) {
      int i = low, j = 2 * i;
      while (j <= high)
      {
        if (j + 1 <= high && arr[j + 1-1] < arr[j-1])
          j = j + 1;
        if (arr[j-1] < arr[i-1])
        {
          swap(arr[j-1], arr[i-1]);
          i = j;
          j = i * 2;
        }
        else
          break;
      }
    };

    function<void()> createHeap;
    createHeap = [&]() {
      int len = arr.size();
      for (int i = len / 2; i >= 1; i--)
      {
        downAdjust(i, len);
      }
    };

    createHeap();
    vector<int> ans;

    function<void(int)> deleteTop;
    deleteTop = [&](int number) {
      int len = arr.size();
      for (int i = 0; i < number; i++)
      {
        ans.push_back(arr[0]);
        arr[0] = arr[--len];
        downAdjust(1, len);
      }
    };

    deleteTop(k);
    return ans;
  }
};