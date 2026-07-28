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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        if(head->next == NULL){
            return head;
        }

        int mid=1;
        ListNode* midel = head;
        int length=1;

        ListNode* temp = head;

        while(temp){
            if(mid != ((length/2)+1)){
                mid = (length/2)+1;
                midel = midel->next;
            }
            temp = temp->next;
            length++;
        }
        return midel;
    }
};