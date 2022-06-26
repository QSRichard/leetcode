#include <vector>

using namespace std;

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
  ListNode* deleteDuplicates(ListNode* head)
  {
    ListNode* ans = new ListNode();
    ListNode* last = ans;
    ListNode* cur=head;

    while (cur && cur->next)
    {
      if (cur->val != cur->next->val)
      {
        last->next = cur;
        last = cur;
        cur=cur->next;
      }
      else
      {
        int t = cur->val;
        while (cur && cur->val == t)
          cur=cur->next;
      }
    }
    last->next = cur;
    return ans->next;
  }
};