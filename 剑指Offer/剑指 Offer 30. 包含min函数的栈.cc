#include <stack>

using namespace std;


class MinStack
{
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x)
  {
    data_.push(x);
    if (min_data_.empty() || min_data_.top() >= x)
      min_data_.push(x);
  }

  void pop()
  {
    int t = data_.top();
    if (t == min_data_.top())
      min_data_.pop();
    data_.pop();
  }

  int top()
  {
    return data_.top();
  }

  int min()
  {
    return min_data_.top();
  }

private:
  stack<int> data_;
  stack<int> min_data_;
};