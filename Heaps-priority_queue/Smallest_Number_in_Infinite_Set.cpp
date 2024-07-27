class SmallestInfiniteSet {
private: priority_queue<int,vector<int>,greater<int>> q;
        unordered_map<int,bool> mp;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            q.push(i);
            mp[i]=1;
        }
    }
    
    int popSmallest() {
        int ans=q.top();
        mp[ans]=0;
        q.pop();
        return ans;
    }
    
    void addBack(int num) {
        if(mp.find(num)==mp.end()){
            mp[num]=1;
            q.push(num);
        }
        else if(!mp[num]){
            q.push(num);
            mp[num]=1;
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */