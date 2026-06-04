class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int a,int b){
        key=a;
        val=b;
        next=NULL;
        prev=NULL;
    }
};


class LRUCache {
public:
    int limit;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* temp=m[key];
        Node* back=temp->prev;
        Node* front=temp->next;
        back->next=front;
        front->prev=back;
        Node* temp2=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=temp2;
        temp2->prev=temp;

        return temp->val;
    }
    
    void put(int key, int value) {
        if(limit){
            if(m.find(key)!=m.end()){
                Node* temp=m[key];
                m.erase(key);
                Node* back=temp->prev;
                Node* front=temp->next;
                back->next=front;
                front->prev=back;
                Node* temp2=head->next;
                head->next=temp;
                temp->next=temp2;
                temp2->prev=temp;
                temp->prev=head;
                temp->val=value;
                m[key]=temp;
            }
            else{
                Node* fresh=new Node(key,value);
                Node* temp=head->next;
                fresh->prev=head;
                head->next=fresh;
                fresh->next=temp;
                temp->prev=fresh;
                m[key]=fresh;
                limit--;
            }
        }
        else{
            if(m.find(key)!=m.end()){
                Node* temp=m[key];
                m.erase(key);
                Node* back=temp->prev;
                Node* front=temp->next;
                back->next=front;
                front->prev=back;
                Node* temp2=head->next;
                head->next=temp;
                temp->next=temp2;
                temp2->prev=temp;
                temp->prev=head;
                temp->val=value;
                m[key]=temp;
            }
            else{
                Node* temp=tail->prev;
                Node* back=temp->prev;
                Node* front=temp->next;

                back->next=front;
                front->prev=back;
                m.erase(temp->key);
                temp->next=NULL;
                temp->prev=NULL;
                Node* fresh=new Node(key,value);
                Node* temp2=head->next;

                head->next=fresh;
                fresh->prev=head;
                fresh->next=temp2;
                temp2->prev=fresh;
                m[key]=fresh;
            }
        }
    }
};

/**
 * Your LRUCache object will be instituted and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */