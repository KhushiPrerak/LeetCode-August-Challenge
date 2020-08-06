class node {
    public:
    char val;
    node** children;
    bool isEnd;
    
    node(char val) {
        this->val = val;
        children = new node*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEnd = false;
    }
};


class WordDictionary {
public:
    
    node* root;
     // TrieNode * root;
    
    WordDictionary() {
        root = new node('\0');
        // root = new TrieNode('\0'); 
    }
    
    
    
    void addWord(node*root, string word) {
        if(word.size()==0) {
            root->isEnd = true;
            return;
        }
        
        int index = word[0]-'a';
        node* child;
        if(root->children[index]!=NULL)
            child = root->children[index];
        else {
            child = new node(word[0]);
            root->children[index]=child;
        }
        addWord(child, word.substr(1));
        
    }
    
    bool search(node* root, string word){
        if(word.size()==0)
            return root->isEnd;
        
        // node* child;
        if(word[0]!='.') {
            if(root->children[word[0]-'a'] !=NULL){
                return search(root->children[word[0]-'a'],word.substr(1));
            }
            else 
                return false;
        }
        else {
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    bool ans = search(root->children[i], word.substr(1));
                    if(ans == true) 
                        return true;
                }
            }
            return false;
        }
    }
    
    
    void addWord(string word) {
        addWord(root,word);
    }
    
    bool search(string word) {
        return search(root, word);
    }
};
