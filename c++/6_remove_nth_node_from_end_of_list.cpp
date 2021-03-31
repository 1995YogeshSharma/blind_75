// author @1995YogeshSharma

// link to execute code = https://leetcode.com/playground/k59xPdXt


#include <bits/stdc++.h>

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *toEnd; ListNode* toTarget;

        toEnd = head;

        if (toEnd->next == NULL and n == 1) return NULL;
        n--;
        while (n--) toEnd = toEnd->next;

        if (toEnd->next == NULL) return head->next;

        toTarget = head;
        toEnd = toEnd->next;
        while(toEnd->next != NULL) {
            toEnd = toEnd->next;
            toTarget = toTarget->next;
        }
        toTarget->next = toTarget->next->next;

        return head;
    }
};

int main() {
    int N; int temp;
    cin >> N;

    ListNode *head = NULL;
    ListNode *cur;

    while (N--) {
        cin >> temp;
        if (head == NULL) {
            head = new ListNode();
            head->val = temp;
            head->next = NULL;
            cur = head;
        }
        else {
            ListNode *tmp = new ListNode(temp);
            cur->next = tmp;
            tmp->next = NULL;
            cur = cur->next;
        }
    }

    cin >> N;

    ListNode *result = Solution().removeNthFromEnd(head, N);

    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
