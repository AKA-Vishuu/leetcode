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
        int length = 0;

        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }

        n = length + 1 - n;

        if(head->next == NULL){
            if(n==1){
                delete head;
                return NULL;
            }
            else{
                return head;
            }
        }

        if(n==1){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }

        int count = 1;
        ListNode* req = head;
        ListNode* prev = NULL;

        while(req){
            if(count == n){
                prev->next = req->next;
                req->next = NULL;
                delete req;
                return head;
            }
            prev = req;
            req = req->next;
            count++;
        }

        return head;
    }
};