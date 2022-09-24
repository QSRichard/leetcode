#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  void reorderList(ListNode* head)
  {
    if(head == nullptr|| head->next == nullptr)
    {
        return;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* newHead = reverseList(slow, nullptr);

    ListNode* cur1 = head;
    ListNode* cur2 = newHead;
    ListNode dump;
    ListNode* tail = &dump;
    while(cur1 != nullptr && cur2 != nullptr)
    {
        tail->next = cur1;
        tail = tail->next;
        cur1 = cur1->next;

        tail->next = cur2;
        cur2 = cur2->next;
        tail = tail->next;
        tail->next = nullptr;
    }
    if(cur1)
    {
        tail->next = cur1;
    }
    if(cur2)
    {
        tail->next = cur2;
    }
  }

private:

    ListNode* reverseList(ListNode* head, ListNode* tail)
    {
        if(head->next == tail)
        {
            return head;
        }

        ListNode* node = reverseList(head->next, tail);
        head->next->next = head;
        head->next = tail;
        return node;
    }
};

int main()
{
    Solution s;
    s.reorderList(nullptr);

}