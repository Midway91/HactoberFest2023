class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
    Node *odd=head;
    Node *even=head->next;
    Node *evenHead=head->next;
     if(head==NULL || head->next==NULL){
         return;
     }
     
     while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    }
};
