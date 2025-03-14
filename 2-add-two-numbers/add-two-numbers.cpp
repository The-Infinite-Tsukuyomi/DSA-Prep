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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* l1_ptr = l1;
        struct ListNode* l2_ptr = l2;
        struct ListNode* l3_ptr = new ListNode(-1); // dummy node
        struct ListNode** ptr = &(l3_ptr->next);

        int carry = 0;

        while(l1_ptr != NULL && l2_ptr != NULL)
        {
            int sum = l1_ptr->val + l2_ptr->val + carry;
            carry = sum / 10;
            sum %= 10;

            l3_ptr->next = new ListNode(sum);
            l3_ptr = l3_ptr->next;

            l1_ptr = l1_ptr->next;
            l2_ptr = l2_ptr->next;
        }

        while(l1_ptr != NULL)
        {
            int sum = l1_ptr->val + carry;
            carry = sum / 10;
            sum %= 10;

            l3_ptr->next = new ListNode(sum);
            l3_ptr = l3_ptr->next;

            l1_ptr = l1_ptr->next;
        }

        while(l2_ptr != NULL)
        {
            int sum = l2_ptr->val + carry;
            carry = sum / 10;
            sum %= 10;

            l3_ptr->next = new ListNode(sum);
            l3_ptr = l3_ptr->next;

            l2_ptr = l2_ptr->next;
        }

        if(carry)
        {
            l3_ptr->next = new ListNode(carry);
            l3_ptr = l3_ptr->next;
        }

        return *ptr;
    }
};

// I forgot to include dummy node(witout it can also be done)
// I forgot to assign the next pointer of l3_ptr->next = new ListNode(val) instead I did   l3_ptr = new ListNode(val) which only updated the value and did not linked them properly
// I forgot to increment l1_ptr and l2_ptr to their next pointer in respective positions