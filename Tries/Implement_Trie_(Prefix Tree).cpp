
class Node{
    public:
    Node* links[26];
    bool flag=false;
    bool contains(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* next(char ch){
        return links[ch-'a'];

    }



};

class Trie {
private: Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i])){
                node->put(word[i],new Node());
            }

            node=node->next(word[i]);
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node* node=root;
            for(int i=0;i<word.length();i++){
                if(node->contains(word[i])){
                   node= node->next(word[i]);
                }
                else{
                    return false;
                }

            }
            return node->flag;
    }
    
    bool startsWith(string prefix) {

        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(node->contains(prefix[i])){
                node=node->next(prefix[i]);
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */