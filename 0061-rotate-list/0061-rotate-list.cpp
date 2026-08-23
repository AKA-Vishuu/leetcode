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
    ListNode* find(ListNode* head, int k){
        ListNode* temp = head;
        int count = 0;

        while(temp){
            count++;
            if(count == k){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        int len = 0;

        ListNode* temp = head;
        ListNode* tail = NULL;

        while(temp){
            len++;
            if(temp->next == NULL){
                tail = temp;
            }
            temp = temp->next;
        }

        if(k%len == 0){
            return head;
        }

        k = k%len;

        ListNode* req_idx= find(head, len-k); // req_idx = len-k
        ListNode* newHead = req_idx->next;
        req_idx->next = NULL;
        tail->next = head;

        return newHead;
    }
};