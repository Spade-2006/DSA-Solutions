class RecentCounter {
public:
    vector<int> requests;
    RecentCounter() {
        requests.clear();
    }
    
    int ping(int t) {
        requests.push_back(t);
        vector<int>::iterator it; 
        it = requests.begin();

        while(requests.front()<t-3000){
            requests.erase(it);
            it = requests.begin();
        }
        
        return requests.size();
    }
};