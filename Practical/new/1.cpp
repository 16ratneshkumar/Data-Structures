/*1. Write a program to implement singly linked list as an ADT(Abstract Data Type) that supports the following operations: 
    1. Insert an element x at the beginning of the singly linked list 
    2. Insert an element x at ith position in the singly linked list 
    3. Remove an element from the beginning of the singly linked list  
    4. Remove an element from ith position in the singly linked list. 
    5. Search for an element x in the singly linked list and return its pointer 
*/

#include <iostream>
struct Node{
    int data;
    Node* next;
};


void insert_at_begin(Node* &head,int value){
    Node* newnode= new Node();
    newnode->data=value;
    newnode->next=head;
    head = newnode;
}

void insert_at_postion(Node* &head,int value,int position){
    Node* newnode= new Node();
    newnode->data=value;
    newnode->next=nullptr;
    if (position==1){
        newnode->next=head;
        head = newnode;
        std::cout<<head->data<<"->"<<"Inserted"<<std::endl;
        return;
    }
    Node* temp=head;
    for (int i=1;i<position-1 && temp!=nullptr;i++){
        temp=temp->next;
    }
    if (temp==nullptr){
        std::cout<<"Position out of bound"<<std::endl;
        delete newnode;
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    std::cout<<value<<"->"<<"Inserted"<<std::endl;
}

void remove_from_begin(Node* &head){
    if (head==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    std::cout<<temp->data<<"->"<<"Deleted"<<std::endl;
    delete temp;
}

void remove_from_postion(Node* &head,int position){
    if (head==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    Node* temp=head;
    Node* prev=nullptr;
    if (position==1){
        head=head->next;
        std::cout<<temp->data<<"->"<<"Deleted"<<std::endl;
        delete temp;
        return;
    }
    for (int i=0;i<position && temp !=nullptr ;i++){
        prev=temp;
        temp=temp->next;
    }
    if (temp==nullptr){
        std::cout<<"Position out of bound"<<std::endl;
        return;
    }
    prev->next=temp->next;
    std::cout<<temp->data<<"->"<<"Deleted"<<std::endl;
    delete temp;
}

Node* search(Node* head,int value){
    Node* temp=head;
    while(temp!=nullptr){
        if (temp->data==value){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}

void display(Node* head){
    if (head ==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    Node* temp =head;
    while(temp!=nullptr){
        std::cout<<temp->data<<"->";
        temp=temp->next;
    }
        std::cout<<"Null"<<std::endl;
}

Node* head=nullptr;
int main(){
    int choice,value,position;
    while (true){
        std::cout<<"1.Insert an element at begin\n2.Insert an element at given position\n3.Remove an element from begin\n4.Remove an element from given position \n5.Search for an element\n6.View the elements of list\n7.Exit\nEnter Your choice:: ";
        std::cin>>choice;
        switch (choice){
            case 1:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                insert_at_begin(head,value);
                break;
            case 2:
                std::cout<<"Enter value:: ";
                std::cin>>value;
                std::cout<<"Enter position:: ";
                std::cin>>position;
                insert_at_postion(head,value,position);
                break;
            case 3:
                remove_from_begin(head);
                break;
            case 4:
                std::cout<<"Enter position:: ";
                std::cin>>position;
                remove_from_postion(head,position);
                break;
            case 6:
                display(head);
                break;
            case 5:
                Node* ptr;
                std::cout<<"Enter value:: ";
                std::cin>>value;
                ptr=search(head,value);
                if (ptr!= nullptr){
                    std::cout<<"Element "<<value<<" found at memory address: "<<ptr<<std::endl;
                }else{
                    std::cout<<"Element "<<value<<" not found in the list."<<std::endl;
                }
                break;
            case 7:
                return 0;
        }
    }
}