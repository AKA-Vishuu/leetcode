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
    ListNode* findKthNode(ListNode* &head, int k){
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if((k==1) || (head->next == NULL)){
            return head;
        }

        ListNode* temp = head;
        ListNode* NextNode = NULL;
        ListNode* PrevNode = NULL;

        while(temp){
            ListNode* KthNode = findKthNode(temp, k);
            if(KthNode == NULL){
                if(PrevNode){
                    PrevNode->next = temp;
                }
                break;
            }
            NextNode = KthNode->next;
            KthNode->next = NULL;

            ListNode* newHead = reverse(temp);
            if(temp == head){
                head = newHead;
            }
            else{
                PrevNode->next = KthNode;
            }
            PrevNode = temp;
            temp = NextNode;
        }
        return head;
    }
};