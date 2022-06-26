#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Trie
{
public:
  Trie() {}

  void insert(string word)
  {
    int index = 0;
    Node* tmp = &root;
    while (index < word.size())
    {
      if (tmp->v[word[index] - 'a'] == nullptr)
        tmp->v[word[index] - 'a'] = new Node(word[index]);
      tmp = tmp->v[word[index] - 'a'];
      index++;
    }
    tmp->end_number++;
  }

  bool search(string word)
  {
    int index = 0;
    Node* tmp=&root;
    while (index < word.size())
    {
      if (tmp->v[word[index] - 'a'] == nullptr)
        return false;
      tmp = tmp->v[word[index] - 'a'];
      index++;
    }
    if (tmp->end_number == 0)
      return false;
    return true;
  }

  bool startsWith(string prefix)
  {
    int index = 0;
    Node* tmp = &root;
    while (index < prefix.size())
    {
      if (tmp->v[prefix[index] - 'a'] == nullptr)
        return false;
      tmp = tmp->v[prefix[index] - 'a'];
      index++;
    }
    return true;
  }

private:
  struct Node
  {
    Node()
    {
      v.resize(57);
      end_number = 0;
    }
    Node(char ch_)
    {
      ch = ch_;
      end_number = 0;
      v.resize(57);
    }
    char ch;
    int end_number;
    vector<Node*> v;
  };
  Node root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */