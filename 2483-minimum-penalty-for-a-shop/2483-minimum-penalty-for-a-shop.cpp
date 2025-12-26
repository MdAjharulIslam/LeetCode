class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> ans; 
        int c = 0;
        
        for(int i = 0; i < customers.size(); i++){
            if(customers[i] == 'Y') c++;
        }
        
        int min = c, hr = 0;
        
        for(int i = 0; i < customers.size(); i++){
            if(customers[i] == 'Y'){
                c--;
                if(min > c){
                    min = c;
                    hr = i + 1;
                }
            } else {
                c++;
            }
        }
        
        return hr;
    }
};