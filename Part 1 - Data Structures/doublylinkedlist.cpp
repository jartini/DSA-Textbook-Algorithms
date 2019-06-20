#include <iostream>


struct  Node
{
    Node* next = nullptr;
    Node* prev = nullptr;
    int data = NULL;
};

Node* getLastPtr(Node* head){
    Node* ptr = head;
    while(ptr->next){
        ptr = ptr->next;
    }
    return ptr;
}

void insert(Node* head, int data){
    Node* nextTail = new Node;
    nextTail->data = data;
    nextTail->prev = getLastPtr(head);
    getLastPtr(head)->next = nextTail;
}

bool contains(Node* head, int query){
    Node* ptr = head;
    while(ptr){
        if(ptr->data == query){
            return true;
        }else{
            ptr = ptr->next;
        }
    }
    return false;
}

bool remove(Node* head, int data){
    if(head->data == data){
        return false;
        //cannot remove head
    }else if(contains(head, data)){
        Node* ptr = head;
        Node* prevNode = nullptr;
        Node* nextNode = nullptr;
        while(true){
            if(ptr->data == data){
                prevNode->next = ptr->next;
                nextNode->prev = prevNode;
                delete ptr;
                return true;
            }
            prevNode = ptr;
            ptr = ptr->next;
            nextNode = ptr->next;
        }
    }else{
        return false;
        //not in list
    }
}

void rtraverse(Node* head){
    Node* ptr = getLastPtr(head);
    while(ptr->prev){
        std::cout<<ptr->data<<std::endl;
        ptr = ptr->prev;
    }
}

int main(){return 0;}