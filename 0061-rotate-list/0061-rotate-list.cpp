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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0){
            return head;
        }

        if(head==NULL || head->next==NULL){
            return head;
        }

        int length = 0;

        ListNode* temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }

        k = k%length;
        k = length-k;

        temp = head;

        int count = 0;
        ListNode* NextNode = NULL;

        ListNode* newHead1 = NULL;
        ListNode* newHead2 = NULL;

        while(temp){
            count++;
            if(count == k){
                NextNode = temp->next;
                temp->next = NULL;
                newHead1 = reverse(head);
                newHead2 = reverse(NextNode);
                head->next = newHead2;
                break;
            }
            temp = temp->next;
        }

        return reverse(newHead1);
    }
};