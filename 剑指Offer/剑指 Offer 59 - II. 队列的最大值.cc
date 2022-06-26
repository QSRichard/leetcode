#include <queue>

using namespace std;

class MaxQueue
{
public:
  MaxQueue() {}

  int max_value()
  {
    return max_queue.front();
  }

  void push_back(int value)
  {
    data_queue.push(value);
    
  }

  int pop_front() {}

private:
  queue<int> data_queue;
  queue<int> max_queue;
};