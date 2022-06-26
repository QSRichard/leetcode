#include <vector>

class Heap
{
public:
  
  void downAdjust(int low, int high);
  void upAdjust(int low, int high);

  void createHeap();
  void deleteTop();
  void insert(int x);

private:
  std::vector<int> heap;
  int count = 0;
};


class Quick
{
public:
  int partition(int left, int right)
  {
    int i = left, j = right;
    int pivote = nums[left];
    while (i < j)
    {
      while (i < j && nums[i] <= pivote)
        i++;
      while (i < j && nums[j] >= pivote)
        j--;
      std::swap(nums[i], nums[j]);
    }
    nums[j] = pivote;
    return j;
  }

  void sort(int left, int right)
  {
    int t = partition(left, right);
    sort(left, t-1);
    sort(t + 1, right);
  }
private:
  std::vector<int> nums;
};
