#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution
{
public:
  ListNode* reverseKGroup(ListNode* head, int k)
  {
    if (k == 1)
      return head;
    ListNode* ans = head;
    for (int i = 1; i < k && ans; i++)
      ans = ans->next;

    // 翻转 [first,last]
    auto reverseList = [](ListNode* first, ListNode* last) {
      ListNode* cur = first;
      ListNode* end = last->next;
      ListNode* pre = nullptr;
      while (cur != end)
      {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
    };
    ListNode* first = head;
    ListNode* last = ans;
    ListNode* next_first = last->next;
    while (first && last)
    {
      reverseList(first, last);
      int tmp = k - 1;
      ListNode* newlast = first;
      first = next_first;
      last = next_first;
      while (last && tmp)
      {
        last = last->next;
        tmp--;
        cout<<tmp<<endl;
      }
      if (last==nullptr)
      {
        newlast->next = first;
        break;
      }
      newlast->next = last;
      next_first = last->next;
    }
    return ans;
  }
};
