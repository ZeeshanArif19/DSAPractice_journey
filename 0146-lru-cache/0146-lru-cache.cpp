class Node{
    public:
    int val;
    int key;
    Node* next=nullptr;
    Node* prev=nullptr;

    Node(int key,int val,Node* next=nullptr,Node* prev=nullptr){
        this->key=key;
        this->val=val;
        this->next=next;
        this->prev=prev;
    }
};
class LRUCache {
public:
    int capacity;
    Node* dummyHead;
    Node* dummyTail;
    unordered_map<int,Node*> mpp; //key,node address

    LRUCache(int capacity) {
        this->capacity=capacity;
        dummyHead= new Node(-1,-1);
        dummyTail= new Node(-1,-1);
        dummyHead->next=dummyTail;
        dummyTail->prev=dummyHead;
    }

    void insertAfterHead(Node* node){
        Node* afterHead=dummyHead->next;
        dummyHead->next=node;
        node->prev=dummyHead;
        node->next=afterHead;
        afterHead->prev=node;
    }
    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* afterNode=node->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
            return;
        }
        if(mpp.size()==capacity){
            Node* beforeTail=dummyTail->prev;
            deleteNode(beforeTail);
            mpp.erase(beforeTail->key);
        }
        Node* newNode=new Node(key,value);
        mpp[key]=newNode;
        insertAfterHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */