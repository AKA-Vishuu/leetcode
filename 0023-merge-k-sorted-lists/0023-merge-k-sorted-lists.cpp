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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        ListNode* head = lists[0];

        for(int i=1; i<lists.size(); i++){
            head = merge(head, lists[i]);
        }

        return head;
    }
};