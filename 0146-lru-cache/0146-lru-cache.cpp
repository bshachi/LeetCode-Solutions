class LRUCache {
public:
    struct hash_node {
        int key;
        int val;
        hash_node* prev;
        hash_node* next;
        hash_node() : key(0), val(0), prev(nullptr), next(nullptr) {};
        hash_node(int k, int x) : key(k), val(x), prev(nullptr), next(nullptr) {};
        hash_node(int k, int x, hash_node* p, hash_node* n) : key(k), val(x), prev(p), next(n) {};
    };

    int cap, size;
    unordered_map<int,hash_node*> mp;
    hash_node* least;
    hash_node* most;

    void update_usage(int key) {
        if (mp[key]->next == NULL) return;
        
        mp[key]->next->prev = mp[key]->prev;

        if (mp[key]->prev != NULL) mp[key]->prev->next = mp[key]->next;
        else least = mp[key]->next;

        mp[key]->prev = most;
        mp[key]->next = nullptr;
        most->next = mp[key];
        most = mp[key];
    }

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        least = NULL;
        most = NULL;
    }
    
    int get(int key) {
        if (mp[key] == NULL) return -1;
        update_usage(key);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp[key] != NULL) {
            mp[key]->val = value;
            update_usage(key);
            return;
        }

        hash_node* temp = new hash_node(key, value, most, nullptr);
        most = temp;
        if (least == NULL) least = temp;
        else temp->prev->next = temp;
        
        mp[key] = temp;

        size++;
        if (size > cap) {
            temp = least;
            least = least->next;
            least->prev = nullptr;
            mp[temp->key] = nullptr;
            delete(temp);
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */