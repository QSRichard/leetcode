#include <cstdio>
#include <functional>
#include <vector>
#include <queue>

using namespace std;


class MedianFinder
{
public:
  /** initialize your data structure here. */
  MedianFinder()
  {
    
  }

  void addNum(int num)
  {
    size++;
    // 放入左边
    if (num < greaterHeap.top())
    {
      greaterHeap.push(num);
      if (size % 2 == 0)
      {
        lessHeap.push(greaterHeap.top());
        greaterHeap.pop();
      }
    }
    else if (num > lessHeap.top())
    {
      lessHeap.push(num);
      if (size % 2 != 0)
      {
        greaterHeap.push(lessHeap.top());
        lessHeap.pop();
      }
    }
    else
    {
      if (size % 2 == 0)
        lessHeap.push(num);
      else
        greaterHeap.push(num);
    }
  }

  double findMedian()
  {
    if (size % 2 == 1)
      return greaterHeap.top();
    else
    {
      return (greaterHeap.top() + lessHeap.top()) / 2.0;
    }
  }

private:
  priority_queue<int, deque<int>, less<int>> greaterHeap; // 保存左边数据
  priority_queue<int, deque<int>, greater<int>> lessHeap;
  int size = 0;
};