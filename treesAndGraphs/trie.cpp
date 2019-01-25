#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
int max_count = 0;
struct Trie{
  bool isWord = false;
  int count = 0;
  unordered_map<char, Trie*> char_map;
};

int insert(Trie* &head, string key){
  Trie* curr = head;
  for(auto str:key){
    if(curr->char_map.find(str) == curr->char_map.end())
    curr->char_map[str] = new Trie();
  curr = curr->char_map[str];
  max_count = max(curr->count, max_count);
  }
  curr->isWord = true;
  curr->count += 1;
}

int search(Trie* &head){
  int max_count = 0;
  unordered_map<char, Trie*>::iterator it = head->char_map.begin();
  while(it != head->char_map.end()){
    max_count = max(it->second->count, max_count); 
  }
  return max_count;
}

int main(){
   // given set of keys
    string dict[] =
    {
        "code", "coder", "coding", "codable", "codec", "codecs", "coded",
        "codeless", "codec", "codecs", "codependence", "codex", "codify",
        "codependents", "codes", "code", "coder", "codesign", "codec",
        "codeveloper", "codrive", "codec", "codecs", "codiscovered"
    };

    // insert all keys into the Trie
    Trie* head = new Trie();
    for (string word: dict) {
      insert(head, word);
    }

    int count = 0;
    // perform pre-order traversal of given Trie and find key
    // with maximum frequency
    // count = search(head);
    cout << "Count: " << max_count << '\n';

    return 0;
}
