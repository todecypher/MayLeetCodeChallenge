
class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<int , Trie*> children;
    bool isEnd;
    Trie() {
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(root ==NULL)
            root =  new Trie();
        Trie* runner = root;
        for(auto i : word){
            int index = i - 'a';
            if(runner->children[index] ==NULL)
                runner->children[index] = new Trie();
            runner= runner->children[index];
        }
        runner->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(!root) return false;
        Trie* runner = root;
        for(auto i : word){
            int index = i - 'a';
            if(runner->children[index] ==NULL)
                return false;
            runner = runner->children[index];
        }
        return (runner->isEnd);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(!root) return false;
        Trie* runner = root;
        for(auto i : prefix){
            int index = i - 'a';
            if(runner->children[index] ==NULL)
                return false;
            runner = runner->children[index];
        }
        return true;
    }
    private :
        Trie* root=NULL;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */