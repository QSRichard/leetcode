#include "sort.h"


void Heap::downAdjust(int low, int high)
{
  int i = low, j = i * 2;
  while (j <= high)
  {
    if (j + 1 <= high && heap[j + 1] > heap[j])
      j = j + 1;
    if (heap[j] > heap[i])
    {
      std::swap(heap[j], heap[i]);
      i = j;
      j = i * 2;
    }
    else
      break;
  }
}

void Heap::createHeap()
{
  for (int i = count / 2; i >= 1; i--)
    downAdjust(i, count);
}

void Heap::deleteTop()
{
  heap[1] = heap[count--];
  downAdjust(1, count);
}

void Heap::upAdjust(int low, int high)
{
  int i = high, j = i / 2;
  while (j >= low)
  {
    if (heap[i] > heap[j])
    {
      std::swap(heap[i], heap[j]);
      i = j;
      j = 1 / 2;
    }
    else
      break;
  }
}

void Heap::insert(int x)
{
  heap.push_back(x);
  count++;
  upAdjust(1, count);
}
