#include <iostream>



struct Node {
    Node* lPtr = nullptr;
    Node* rPtr = nullptr;
    int key;
};

//not implementing insert(value) -> it is redundant
//also I would rather pass a root node first. easier to program and test
//void insert(int value){}

bool contain(Node* root, int query){
    //searches the tree for an existing node with the corresponding key
    Node* ptr = root;
    if (!ptr){
        return false;
    }
    if(ptr->key == query){
        return true;
    }else{
        if(query < ptr->key){ //left
            ptr = ptr->lPtr;
            return contain(ptr, query); 
        }else if(query > ptr->key){ //right
            ptr = ptr->rPtr;
            return contain(ptr, query);
        }
    }
    
}

bool insertNode(Node* root, int data){
    //inserts a node
    //recursive
    if(contain(root, data)){
        return false;
    }else{
        Node* ptr = root;
        Node* temp = new Node;
        temp->key = data;
        if(data < ptr->key){
            if(!ptr->lPtr){
                ptr->lPtr = temp;
                return true;
            }else{
                ptr = ptr->lPtr;
                insertNode(ptr, data);
            }
        }
        if(data > ptr->key){
            if(!ptr->rPtr){
                ptr->rPtr = temp;
                return true;
            }else{
                ptr = ptr->rPtr;
                insertNode(ptr, data);
            }
        }
    }
    return false;
}

Node* findParentNode(Node* root, int value, Node* parent = nullptr){
    //returns the parent pointer of the node that contains the value
    Node* ptr = root;
    if(!contain(root, value)){ //contains?
        return nullptr;
    }
    if(value < ptr->key){//left
        parent = ptr;
        ptr = ptr->lPtr;
        return findParentNode(ptr, value, parent);
    }else if(value > ptr->key){ //right
        parent = ptr;
        ptr = ptr->rPtr;
        return findParentNode(ptr, value, parent);
    }else if(ptr->key == value){ //found parent
        return parent;
    }
}

Node* findNode(Node* root, int value){
    //returns pointer to the node that contains the value
    Node* ptr = root;
    if(!contain(root, value)){ //contains?
        return nullptr;
    }
    if(value < ptr->key){ //left
        ptr = ptr->lPtr;
        return findNode(ptr, value);
    }else if(value > ptr->key){ //right
        ptr = ptr->rPtr;
        return findNode(ptr, value);
    }else if(ptr->key == value){ //found node
        return ptr;
    }
}

Node* findMinNode(Node* node){
    //returns pointer of min node
    Node* ptr = node;
    if(!ptr->lPtr){
        return nullptr;
    }else{
        ptr = ptr->lPtr;
        return findMinNode(ptr);
    }
}

int findMin(Node* node){
    //returns smallest value
    return findMinNode(node)->key;
}


Node* findMaxNode(Node* node){
    //returns pointer of max node
    Node* ptr = node;
    if(!ptr->rPtr){
        return nullptr;
    }else{
        ptr = ptr->rPtr;
        return findMaxNode(ptr);
    }
}

int findMax(Node* node){
    //returns biggest value
    return findMaxNode(node)->key;
}



bool remove(Node* root, int value){
    //absolute shit show
    //removes a node and restructures the tree
    if (!contain(root, value)){
        return false;
    }
    Node* parent = findParentNode(root, value);
    Node* node = findNode(root, value);
    Node* infTree = node->rPtr;
    Node* supTree = node->rPtr;
    if(!supTree && !infTree){
        //if both sub trees do not exist
        if(node->key < parent->key){

        }else{

        }
    }else if(!supTree){
        //if superior tree does not exist
                if(node->key < parent->key){

        }else{
            
        }
    }else if(!infTree){
        //if inferior tree does not exist
                if(node->key < parent->key){

        }else{
            
        }
    }else{
        //both sub trees exist
                if(node->key < parent->key){

        }else{
            
        }
    }
    delete node;
    return true;

}

//TRAVERSALS

void preorder(Node* root){

}

void postorder(Node* root){

}

void inorder(Node* root){

}

void breadthFirst(Node* root){
    
}

int main(){
    int i[] ={1,4,5,20,13};
    Node* root = new Node;
    root->key = 10;
    //std::cout << insertNode(root, 3) << std::endl;
    //std::cout << contain(root, 3) << std::endl;
    for(int x : i){
        insertNode(root, x);
        //std::cout << x << std::endl;
    }
    //std::cout << findMin(root) + findMax(root) << std::endl;
    std::cout << contain(root, 5) << std::endl;
    std::cout << remove(root, 5) << std::endl;
    std::cout << contain(root, 5) << std::endl;
    
    return 0;
}