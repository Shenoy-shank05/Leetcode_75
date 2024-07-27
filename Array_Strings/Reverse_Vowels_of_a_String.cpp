class Solution {
public:
    string reverseVowels(string s) {
        
      string dummy;
      for(int i=s.length()-1;i>=0;i--){


        if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E'  || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
            dummy.push_back(s[i]);
        }
      }

        int j=0;
      for(int i=0;i<s.length();i++){

        
        if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E'  || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
            s[i]=dummy[j];
            j++;
        }
      }
        return s;
    }
};