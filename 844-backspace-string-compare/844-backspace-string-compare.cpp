class Solution {
public:
    bool backspaceCompare(string str, string tr) {
        stack<char> s,t;
        for(int i=0;i<str.size();i++){
            if(str[i]=='#'){
                if(s.size()!=0) s.pop();
            }else{
                s.push(str[i]);
            }
        }
        
        for(int i=0;i<tr.size();i++){
            if(tr[i]=='#'){
                if(t.size()!=0) t.pop();
            }else{
                t.push(tr[i]);
            }
        }
        return s==t;
    }
};