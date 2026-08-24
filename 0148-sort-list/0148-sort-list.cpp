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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        ListNode* t1 = head1;
        ListNode* t2 = head2;

        while(t1 && t2){
            if(t1->val <= t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1 != NULL){
            temp->next = t1;
        }

        if(t2 != NULL){
            temp->next = t2;
        }

        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergesort(ListNode* &head){
        if((head == NULL) || (head->next == NULL)){
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;

        middle->next = NULL;

        lefthead = mergesort(lefthead);
        righthead = mergesort(righthead);

        return merge(lefthead, righthead);
    }

    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};