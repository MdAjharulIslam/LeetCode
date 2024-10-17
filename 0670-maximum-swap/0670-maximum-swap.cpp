class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        string ncopy = n;
        sort(n.begin(), n.end());
        reverse(n.begin(), n.end());
        char swappedInt = '\0';
        char swappedWithInt = '\0';
        for(int i = 0;i < n.size(); ++i){
            if(n[i] != ncopy[i]){
                swappedInt = ncopy[i];
                swappedWithInt = n[i];
                ncopy[i] = n[i];
                break;
            }
        }
        for(int i = n.size()-1;i >= 0; --i){
            if(ncopy[i] == swappedWithInt){
                ncopy[i] = swappedInt;
                break;
            }
        }
        return stoi(ncopy);
    }
};