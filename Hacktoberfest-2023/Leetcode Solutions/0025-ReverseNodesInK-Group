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
// Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr,*prev,*forw,*cursor;
        cursor=head;
        for(int i=0;i<k;i++){
            if(cursor==NULL)
                return head;
            cursor=cursor->next;
        }
        curr=head;
        prev=NULL;
        forw=NULL;
        int c=0;
        while(c<k && curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            c++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};