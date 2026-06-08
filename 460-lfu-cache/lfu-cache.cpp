class node{
    public:
    int key,val,count;
    node* next;
    node* prev;
    node(int a,int b){
        key=a;
        val=b;
        count=1;
        next=NULL;
        prev=NULL;
    }
};


class dll{
    public:
    int size;
    node* head;
    node* tail;
    dll(){
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void add(node* fresh){
        fresh->next=head->next;      
        fresh->prev=head;
        head->next->prev=fresh;     
        head->next=fresh;
        size++;
    }

    void remove(node* rem){
        node* back=rem->prev;
        node* front=rem->next;
        back->next=front;
        front->prev=back;
        rem->next=NULL;
        rem->prev=NULL;
        size--;
    }
};



class LFUCache {
public:
    int limit;
    int maxsize;
    int leastfreq;
    map<int,dll*> freqlist;
    map<int,node*> keynode; 
    LFUCache(int capacity) {
        limit=capacity;
        maxsize=capacity;
        leastfreq=0;
    }
    
    void updatefreq(node* x){
        int freq=x->count;
        freqlist[freq]->remove(x);
        if(freqlist[freq]->size==0 && freq==leastfreq){
            leastfreq++;
        }
        dll* newfreqlist = new dll(); 
        if(freqlist.find(freq+1)!=freqlist.end()){
            newfreqlist=freqlist[freq+1];
            freqlist.erase(freq+1);
        }
        x->count++;
        newfreqlist->add(x);
        freqlist[freq+1]=newfreqlist;
    }


    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            updatefreq(keynode[key]);
            return keynode[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize==0)return;
        if(keynode.find(key)!=keynode.end()){
            keynode[key]->val=value;
            updatefreq(keynode[key]);
        }
        else{
            if(limit){
                if(freqlist.find(1)==freqlist.end()) freqlist[1]=new dll();
                dll* newfreqlist=freqlist[1];
                node* fresh=new node(key,value);
                newfreqlist->add(fresh);
                limit--;
                leastfreq=1;
                keynode[key]=fresh;
            }
            else{
                if(freqlist.find(1)==freqlist.end()) freqlist[1]=new dll();
                node* toremove=freqlist[leastfreq]->tail->prev;
                keynode.erase(toremove->key);
                freqlist[leastfreq]->remove(toremove);
                node* fresh=new node(key,value);
                freqlist[1]->add(fresh);
                leastfreq=1;
                keynode[key]=fresh;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */