class Trie {
private:
    struct node {
        node* arr[26];
        bool flag = false; 
    };
    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* ptr = root;
        for (char c:word) {
            if (!ptr->arr[c-'a']) ptr->arr[c-'a'] = new node();
            ptr = ptr->arr[c-'a'];
        }
        ptr->flag = true;
    }
    
    bool search(string word) {
        node* ptr = root;
        for (char c:word) {
            if (!ptr->arr[c-'a']) return false;
            ptr = ptr->arr[c-'a'];
        }
        return ptr->flag;
    }
    
    bool startsWith(string prefix) {
        node* ptr = root;
        for (char c:prefix) {
            if (!ptr->arr[c-'a']) return false;
            ptr = ptr->arr[c-'a'];
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