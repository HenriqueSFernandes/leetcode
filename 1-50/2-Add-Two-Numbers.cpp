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
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode* res = NULL;
        ListNode** currentPointer = &res;
        while (l1 != NULL || l2 != NULL) {
            sum = getNextValue(l1) + getNextValue(l2) + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum %= 10;
            }
            ListNode* node = new ListNode(sum);
            *currentPointer = node;
            currentPointer = (&node->next);
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            *currentPointer = node;
        }
        return res;
    }

    int getNextValue(ListNode* l) {
        int n = 0;
        if (l != NULL) {
            n = l->val;
            l = l->next;
        }
        return n;
    }
};