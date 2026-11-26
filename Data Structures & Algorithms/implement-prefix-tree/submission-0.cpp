class PrefixTree {
private:
    struct Node { 
        array<Node* , 26> children{};
        bool isEnd=false;
    };
    Node* root;
public: PrefixTree() {
        root = new Node();
}
    
    void insert(string word) {
        Node* curr=root;
        for (char c : word) {
            int idx= c-'a';
            if (curr->children[idx] == nullptr){
                curr->children[idx]=new Node();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;                     
            }
            curr = curr->children[idx];           
        }
        return curr->isEnd;                      
    }

    bool startsWith(const std::string& prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;                    
            }
            curr = curr->children[idx];   }        
        return true;                              
    }
};
