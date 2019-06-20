#include <iostream>

struct Node
{
    Node* next = nullptr;
    int data = 0;
};

Node* getTailPtr(Node* head){
    Node* ptr = head;
    while(ptr->next){
        ptr=ptr->next;
    }
    return ptr;
}

void insert(Node* head, int data){
    Node* nextTail;
    nextTail->data=data;
    getTailPtr(head)->next=nextTail;
}

bool contain(Node* head, int query){
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

bool remove(Node* head, int value){
    if(!head->next){
        std::cout << "CANNOT REMOVE HEAD" << std::endl;
        return false;
    }else if(contain(head, value)){
        Node* markedNode = head->next;
        Node* lastNode = head;
        while(markedNode->next){
            if(markedNode->data == value){
                break;
            }
            lastNode = markedNode;
            markedNode = markedNode->next;
        }
        lastNode->next = markedNode->next;
        delete markedNode;
        return true;
    }else{
        std::cout << "VALUE DOES NOT EXIST IN LIST" << std::endl;
        return false;
    }
}

int main(){return 0;}
