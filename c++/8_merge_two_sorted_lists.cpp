// author @1995YogeshSharma

// Link to execute code online - https://leetcode.com/playground/7RoVhUfq
#include <bits/stdc++.h>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode;

        ListNode *dummyHead = dummy;

        ListNode *head1 = l1; ListNode *head2 = l2;
        while (head1 != NULL and head2 != NULL) {
            if (head1->val < head2->val) {
                dummy->next = head1;
                dummy = dummy->next;
                head1 = head1->next;
            } else {
                dummy->next = head2;
                dummy = dummy->next;
                head2 = head2->next;
            }
        }

        while (head1 != NULL) {
            dummy->next = head1;
            dummy = dummy->next;
            head1 = head1->next;
        }

        while (head2 != NULL) {
            dummy->next = head2;
            dummy = dummy->next;
            head2 = head2->next;
        }

        return dummyHead->next;
    }
};

ListNode *input_ll(int size) {
   ListNode *head;
   int temp;

   head = new ListNode(-1, NULL);
   ListNode* tempHead = head;

   while (size--) {
      cin >> temp;
      ListNode *tmp = new ListNode(temp, NULL);
      head->next = tmp;
      head = head->next;
   }

   return tempHead->next;
}

void print_ll(ListNode *head) {
   while (head != NULL) {
       cout << head->val << " ";
       head = head->next;
   }
   cout << endl;
}

int main() {
    ListNode *l1, *l2;

    int n1, n2;

    cin >> n1;
    l1 = input_ll(n1);
    cin>> n2;
    l2 = input_ll(n2);
    
    print_ll(l1); cout << endl << endl; print_ll(l2); cout << endl << endl;

    print_ll(Solution().mergeTwoLists(l1, l2));
    return 0;
}
