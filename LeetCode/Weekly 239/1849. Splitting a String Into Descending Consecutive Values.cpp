class Solution {
public:
    
    
    bool solve(string &s,uint64_t prev,uint64_t pos,uint64_t cur =  -1){
        
        if(pos == s.length()){
            cout << prev << " " << cur;
            cout << " : " << (prev + 1 == cur) << endl;
            return prev - 1 == cur;
        }
        
       
        uint64_t x = s[pos] - '0';

        uint64_t t = (cur == -1) ? x : 10 * cur + x;
       
        
        if(prev == -1 or prev - 1 == t)
            return solve(s,prev,pos+1,t) or solve(s,t,pos+1,-1);
        
        
        return solve(s,prev,pos+1,t);
        
    }
    
    bool splitString(string s) {
        int c = 0;
        for(char ch : s){
            if(ch == '0'){
                c++;
            }
        }
        if(c == s.length()){
            return false;
        }
        return solve(s,-1,0,-1);   
    }
};