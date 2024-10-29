//==============================================
// Find Middle Of The Linked List
//==============================================
//==================================================
// Approach 1:Traverse The List and Find Middle Node
//==================================================
Node* middleNode(Node* &head){
    Node* temp=head;
    int count=0;
    if (!(head)){
        return head;
    }
    while((temp)){
        temp=temp->next;
        count++;
    }
    temp=head;
    for(int i=0;i<int(count/2);i++){
        temp=temp->next;
    }
    return temp;
}


//==============================================
// Approach 2:Use 2 Pointer
//==============================================
Node* middleNode(Node* &head){
    Node* slow=head;
    Node* fast=head;
    if (!(head)){
        return head;
    }
    while((fast) && (fast->next)){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
