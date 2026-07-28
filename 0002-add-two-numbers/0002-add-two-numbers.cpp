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

        vector<int> vec;

        int carry = 0;

        while(l1!=NULL && l2!=NULL){
            int sum = ((l1->val) + (l2->val) + carry);
            if(sum > 9){

                vec.push_back(sum % 10);
                carry = 1;
            }
            else{
                vec.push_back(sum % 10);
                carry=0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            int sum = ((l1->val) + carry);
            if(sum > 9){

                vec.push_back(sum % 10);
                carry = 1;
            }
            else{
                vec.push_back(sum % 10);
                carry=0;
            }
            l1 = l1->next;
        }

        while(l2 != NULL){
            int sum = ((l2->val) + carry);
            if(sum > 9){

                vec.push_back(sum % 10);
                carry = 1;
            }
            else{
                vec.push_back(sum % 10);
                carry=0;
            }
            l2 = l2->next;
        }

        if(carry == 1){
            vec.push_back(1);
        }

        ListNode* head = new ListNode(vec[0]);

        ListNode* temp = head;

        for(int i=1; i<vec.size(); i++){
            ListNode* newNode = new ListNode(vec[i]);
            temp->next = newNode;
            temp = newNode;
        }

        temp->next == NULL;

        return head;

    }
};