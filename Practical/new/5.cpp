/*5. Implement Queue as an ADT. 
*/


//==============================================
// Using Array List.
// ==============================================
#include <iostream>

class Queue {
private:
    int* arr;    
    int head;  
    int tail;    
    int capacity; 
    int count;  

public:
    Queue(int size) : capacity(size), head(0), tail(-1), count(0) {
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (count == capacity) {
            throw std::runtime_error("OverFlow Occur");
        }
        tail = (tail + 1) % capacity; 
        arr[tail] = value;
        count++;
        std::cout<<"Element "<<value<<" inserted in the queue!"<<std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("UnderFlow Occur");
        }
        std::cout<<"Element "<<arr[head]<<" deleted from the queue!"<<std::endl;
        head = (head + 1) % capacity;
        count--;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        std::cout<<"Top most element->"<<arr[head]<<std::endl;
    }

    void display() const {
        std::cout<<"Element of the queue are->";
        for (int i = 0; i < count; i++) {
            std::cout << arr[(head + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }
};


int main(){
    int num;
    std::cout<<"Enter Array size:: ";
    std::cin>>num;
    Queue queue(num);
    int choice;
    while(true){
        std::cout<<"\n1.Insert an element in queue\n2.Delete an element from queue\n3.Display the first element\n4.Check queue is empty?\n5.Check the size Queue\n6.Display the queue\n7.Exit\nEnter your choice::";
        std::cin>>choice;
        switch (choice){
            case 1:
                int value;
                std::cout<<"Enter data of queue::";
                std::cin>>value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.peek();
                break;
            case 4:
                std::cout<<"Is the queue empty? :"<<(queue.isEmpty()? "Yes":"No")<<std::endl;
                break;
            case 5:
                std::cout<<"Size of your Queue are: "<<queue.size()<<std::endl;
                break;
            case 6:
                queue.display();
                break;
            case 7:
                return 0;
        }
    }
}



//==============================================
// Using Linked List.
//==============================================
#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class Queue{
private:
    Node* head;
    Node* tail;
    int count;
public:
    Queue():head(nullptr),tail(nullptr),count(0){};
    ~Queue(){
        while(!isEmpty()){
            dequeue(false);
        }
    }
    bool isEmpty(){
        return head==nullptr;
    }
    int size(){
        return count;
    }
    void enqueue(int value){
        Node* newnode =new Node(value);
        if (isEmpty()){
            head=tail=newnode;
            std::cout<<"Element "<<value<<" inserted in the queue!"<<std::endl;
        }else{
            tail->next=newnode;
            tail=newnode;
            std::cout<<"Element "<<value<<" inserted in the queue!"<<std::endl;
        }
        count++;
    }
    void dequeue(bool flag){
        if(isEmpty()){
            throw std::runtime_error("UnderFlow Occur");
        }
        Node* temp=head;
        head=head->next;
        if (flag){
            std::cout<<"Element "<<temp->data<<" deleted from the queue!"<<std::endl;
        }
        delete temp;
        count--;
    }
    void peek() {
        if(isEmpty()){
            throw std::runtime_error("Queue is empty");
        }
        std::cout<<"Top most element->"<<head->data<<std::endl;
    }
    void display() {
        if(isEmpty()){
            throw std::runtime_error("Queue is empty");
        }
        Node* temp=head;
        std::cout<<"Element of the queue are->";
        while(temp){
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }
        std::cout<<std::endl;
    }
};

int main(){
    Queue queue;
    int choice;
    while(true){
        std::cout<<"\n1.Insert an element in queue\n2.Delete an element from queue\n3.Display the first element\n4.Check queue is empty?\n5.Check the size Queue\n6.Display the queue\n7.Exit\nEnter your choice::";
        std::cin>>choice;
        switch (choice){
            case 1:
                int value;
                std::cout<<"Enter data of queue::";
                std::cin>>value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue(true);
                break;
            case 3:
                queue.peek();
                break;
            case 4:
                std::cout<<"Is the queue empty? :"<<(queue.isEmpty()? "Yes":"No")<<std::endl;
                break;
            case 5:
                std::cout<<"Size of your Queue are: "<<queue.size()<<std::endl;
                break;
            case 6:
                queue.display();
                break;
            case 7:
                return 0;
        }
    }
}