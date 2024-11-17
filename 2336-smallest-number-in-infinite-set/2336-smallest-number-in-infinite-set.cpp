class SmallestInfiniteSet {
public:
    
    int curr=1;
    
    set<int> added;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(added.empty()){
            return curr++;
        }
        
        int smallest=*added.begin();
        added.erase(added.begin());
        return smallest;
    }
    
    void addBack(int num) {
        if(num<curr){
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */