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

        ListNode* head = new ListNode(-1);
        ListNode* current = head;

        int carry = 0;

        while(l1!=NULL && l2!=NULL){
            int sum = ((l1->val) + (l2->val) + carry);
            if(sum > 9){
                current->next = new ListNode(sum % 10);
                current = current->next;
                carry = 1;
            }
            else{
                current->next = new ListNode(sum % 10);
                current = current->next;
                carry=0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            int sum = ((l1->val) + carry);
            if(sum > 9){
                current->next = new ListNode(sum % 10);
                current = current->next;
                carry = 1;
            }
            else{
                current->next = new ListNode(sum % 10);
                current = current->next;
                carry=0;
            }
            l1 = l1->next;
        }

        while(l2 != NULL){
            int sum = ((l2->val) + carry);
            if(sum > 9){
                current->next = new ListNode(sum % 10);
                current = current->next;
                carry = 1;
            }
            else{
                current->next = new ListNode(sum % 10);
                current = current->next;
                carry=0;
            }
            l2 = l2->next;
        }

        if(carry == 1){
            current->next = new ListNode(1);
            current = current->next;
        }

        return head->next;

    }
};