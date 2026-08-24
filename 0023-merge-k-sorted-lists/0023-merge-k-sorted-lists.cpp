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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        } 
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n==0){
            return NULL;
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i=0; i<n; i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        while(!(pq.empty())){
            ListNode* store = pq.top();
            temp->next = store;
            temp = temp->next;
            pq.pop();
            if(store->next != NULL){
                pq.push(store->next);
            }
        }

        return dummyNode->next;
    }
};