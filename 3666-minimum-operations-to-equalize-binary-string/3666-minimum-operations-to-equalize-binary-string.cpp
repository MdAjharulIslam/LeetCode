class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        
        int zero=0;
        for(int i=0;i<n;i++) zero+=(s[i]=='0');

        queue<int> q;
        vector<int> dis(n+1,1e9);
        q.push(zero);
        dis[zero]=0;
        
        set<int> even,odd;
        for(int i=0;i<=n;i+=2){
            if(i==zero) continue;
            even.insert(i);
        }
        for(int i=1;i<=n;i+=2){
            if(i==zero) continue;
            odd.insert(i);
        }

        while(!q.empty()){
            int curZero=q.front();
            int curOne=n-curZero;
            q.pop();
            if(!curZero) return dis[curZero]; 
            int maxNewZero=curZero-max(k-curOne,0)+(k-max(k-curOne,0));
            int minNewZero=curZero-min(k,curZero)+(k-min(k,curZero));
            
            auto it1=odd.begin(),it2=odd.begin();
            if(minNewZero&1){
                it1=odd.lower_bound(minNewZero);
                it2=odd.upper_bound(maxNewZero);
            }
            else{
                it1=even.lower_bound(minNewZero);
                it2=even.upper_bound(maxNewZero);
            }
            while(it1!=it2){
                int y=*it1;
                it1++;
                q.push(y);
                dis[y]=dis[curZero]+1;
                if(minNewZero&1) odd.erase(y);
                else even.erase(y);
                
            }
            /*for(int zeroTake=max(k-curOne,0);zeroTake<=min(k,curZero);zeroTake++){
                int oneTake=k-zeroTake;
                int newZero=curZero-zeroTake+oneTake;
                if(dis[newZero]!=1e9) continue;
                q.push(newZero);
                dis[newZero]=dis[curZero]+1;
            }*/
        }
        return -1;
    }
};