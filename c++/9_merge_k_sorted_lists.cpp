// author @1995YogeshSharma
//
// Link to execute code online - https://leetcode.com/playground/drNMp4vE

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode;

        ListNode* dummyHead = dummy;

        int mini = INT_MAX;
        int minIdx = INT_MAX;

        while (true) {
            // try to find min head
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL) continue;

                if (lists[i]->val < mini) {
                    mini = lists[i]->val;
                    minIdx = i;
                }
            }

            if (minIdx == INT_MAX) break;

            dummy->next = lists[minIdx];
            dummy = dummy->next;
            lists[minIdx] = lists[minIdx]->next;

            mini = INT_MAX;
            minIdx = INT_MAX;
        }

        return dummyHead->next;

    }
};

ListNode *input_ll(int N) {
    ListNode *head, *dummyhead, *tempL; int temp;

    head = new ListNode(0, NULL);
    dummyhead = head;

    while(N--) {
        cin >> temp;
        tempL = new ListNode(temp, NULL);
        head->next = tempL;
        head = head->next;
    }

    return dummyhead->next;
}

void print_ll(ListNode *l) {
    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main() {
    vector<ListNode *> lists;
    int N, temp; ListNode *tempL;

    cin >> N;
    while (N--) {
        cin >> temp;
        tempL = input_ll(temp);
        lists.push_back(tempL);
    }

    tempL = Solution().mergeKLists(lists);
    print_ll(tempL);

    return 0;
}
