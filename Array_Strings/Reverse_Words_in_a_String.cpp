class Solution {
public:
    string reverseWords(string s) {
        

       stack<string> st;
       string temp;
       string ans;
       int i=0;
       while(i<s.length()){

            while(i<s.length() && s[i]!=32){
                temp.push_back(s[i]);
                i++;
            }
            if(temp.length()){
                st.push(temp);
                 temp.clear();
            }
            i++;
           
       } 

    while(!st.empty()){

        ans+=st.top();
        if(st.size()>1){
            ans+=" ";
        }
        
        st.pop();
    }

    return ans;
    }
};