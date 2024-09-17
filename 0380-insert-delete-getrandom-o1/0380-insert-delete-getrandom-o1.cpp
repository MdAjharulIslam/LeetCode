class RandomizedSet {
public:
unordered_set<int>st;
vector<int>ans;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)!=st.end())
        return false;
        else{
            ans.push_back(val);
            st.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            for(int i=0;i<ans.size();i++){
                if(ans[i]==val){
                    swap(ans[i],ans[ans.size()-1]);
                    ans.pop_back();
                }
            }
            st.erase(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        int i=rand()%ans.size();
        return ans[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */