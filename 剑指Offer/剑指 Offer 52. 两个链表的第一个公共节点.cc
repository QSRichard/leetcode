
#include <algorithm>


  struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
  {
    ListNode* tmp;
    int na = 0, nb = 0;
    tmp = headA;
    while (tmp != nullptr)
    {
      tmp = tmp->next;
      na++;
    }
    tmp = headB;
    while (tmp != nullptr)
    {
      tmp = tmp->next;
      nb++;
    }
    ListNode* fast = na > nb ? headA : headB;
    ListNode* slow = fast == headA ? headB : headA;
    int step = abs(na - nb);
    while (step-- > 0)
      fast = fast->next;
    while (fast != nullptr && slow != nullptr && fast != slow)
    {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};