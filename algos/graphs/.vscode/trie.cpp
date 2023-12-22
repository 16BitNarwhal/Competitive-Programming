class TrieNode{
  public:
  char data;
  unordered_map<char, TrieNode*> children;
  bool isEnd;

  TrieNode(char data){
    this->data = data;
    isEnd = false;
  }
};

class Trie {
  TrieNode* root;

  void insertWord(TrieNode* root, string word){
    if(word.length() == 0) {
      root->isEnd = true;
      return;
    }
    TrieNode* child;
    if(root->children.find(word[0]) != root->children.end()) // child character found, keep going
      child = root->children[word[0]];
    else {
      root->children[word[0]] = new TrieNode(word[0]); // child character not found, create new node
      child = root->children[word[0]];
    }
    insertWord(child, word.substr(1));
  }

  int doSearch(TrieNode* root, string word) {
    if(word.length() == 0) { 
      if(root->isEnd) // no more characters left in word and has reached end of the trie
        return 1;
      return 0; // this is strictly prefix of word
    }
    if(root->children.find(word[0])!=root->children.end()) // if child is found, keep going
      return doSearch(root->children[word[0]], word.substr(1));
    return -1;
  }
public:
  Trie() {
    root = new TrieNode('\0'); // create empty trie node
  }
  void insert(string word) {
    insertWord(root, word); // calls recurive function, insertWord
  }

  bool search(string word) { // calls recurvise function, doSearch
    if(doSearch(root, word) == 1)
      return true;
    return false;
  }

  bool startsWith(string prefix) { // call recursive function, doSearch
    int res = doSearch(root, prefix);
    if(res>=0)
      return true;
    return false;
  }
};