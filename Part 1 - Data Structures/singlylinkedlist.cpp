#include <iostream>

struct Node
{
    Node* next = nullptr;
    int data = 0;
};

Node* getTailPtr(Node* head){
    Node* ptr = head;
    while(ptr->next != nullptr){
        ptr=ptr->next;
    }
    return ptr;
}

void insert(Node* head, int data){
    Node* nextTail = new Node;
    nextTail->data=data;
    getTailPtr(head)->next = nextTail;
    std::cout << getTailPtr(head) << std::endl;
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

void traverse(Node* head){
    Node* ptr = head;
    while(ptr){
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

void rtraverse(Node* head, Node* tail){
    auto getNextLastPtr = [] (Node* head, Node* last){
        Node* ptr = head;
        while(ptr->next != last){
            ptr = ptr->next;
        }
        return ptr;
    };
    Node* ptr = tail;
    while(ptr != head){
        std::cout << ptr->data << std::endl;
        ptr = getNextLastPtr(head, ptr);
    }
    std::cout << ptr->data << std::endl;
}

int main(){
    Node* head = new Node;    
    head->data = 69;
    for(int i = 0; i <= 20; i++){
        insert(head, i);
    }
    traverse(head);
    rtraverse(head, getTailPtr(head));
    remove(head, 5);
    traverse(head);
    return 0;
}
