from typing import List

class TrieNode:
    def __init__(self, val):
        self.value: str = val
        self.children: List['TrieNode'] = []
    
    def add(self, child_val: str):
        if not self.find(child_val):
            self.children.append(TrieNode(child_val))

    def find(self, child_val: str) -> 'TrieNode':
        for n in self.children:
            if n.value == child_val:
                return n
        return None

class Trie:

    def __init__(self):
        self.root: 'TrieNode' = TrieNode('\n')

    def insert(self, word: str) -> None:
        node: 'TrieNode' = self.root
        for letter in word:
            if not node.find(letter):
                node.add(letter)
            node = node.find(letter)
        if not node.find('\n'):
            node.add('\n')

    def search(self, word: str) -> bool:
        node: 'TrieNode' = self.root
        for letter in word:
            node = node.find(letter)
            if not node:
                return False
            
        if node.find('\n'):
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        node: 'TrieNode' = self.root
        for letter in prefix:
            node = node.find(letter)
            if not node:
                return False
        return True

# Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert('apple')
param_2 = obj.search('apple')
param_3 = obj.startsWith('appl')
print(param_2, param_3)