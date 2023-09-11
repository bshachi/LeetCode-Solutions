class AuthenticationManager {
    unordered_map<string,int> mp;
    int timeToLive;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (mp[tokenId] > currentTime) 
            mp[tokenId] = currentTime + timeToLive;        
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto x:mp) {
            if (x.second > currentTime) count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */