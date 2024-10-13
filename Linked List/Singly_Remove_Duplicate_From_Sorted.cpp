//================================================
// Remove Duplicate Value From Sorted Linked List.
//================================================
Node* removeDuplicate(Node* head){
    if (!head) return head;
    Node* Head=head;
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=nullptr){
        if (prev->data==curr->data){
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        } else{
            prev=curr;
            curr=curr->next;
        }
    }
    return Head;
}
