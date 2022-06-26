#include <climits>
#include <queue>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution
{
public:

  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
  {

    int node = 0;
    vector<vector<int>> graph;
    unordered_map<string, int> mp;
    unordered_map<int, string> reverse_mp;

    function<void(string&,int)> addWord = [&](string& word,int index1) {
      if (mp.find(word) == mp.end())
      {
        mp[word] = node;
        reverse_mp[node] = word;
        node++;
        graph.emplace_back();
      }

      int index2 = mp[word];
      graph[index1].push_back(index2);
      graph[index2].push_back(index1);
    };

    function<void(string&)> addEdge = [&](string& word) {
      if (mp.find(word) == mp.end())
      {
        mp[word] = node;
        reverse_mp[node] = word;
        node++;
        graph.emplace_back();
      }
      int index1 = mp[word];
      for (int i = 0; i < word.size(); i++)
      {
        char ch = word[i];
        word[i] = '*';
        addWord(word,index1);
        word[i] = ch;
      }
    };

    for (int i = 0; i < wordList.size(); i++)
      addEdge(wordList[i]);
    if (mp.find(beginWord) == mp.end())
      addEdge(beginWord);

    if (mp.find(endWord) == mp.end())
      return {};

    vector<vector<int>> ans(node + 1);
    queue<int> q;
    vector<int> dis(node + 1, INT_MAX);
    int beginId = mp[beginWord], endId = mp[endId];
    q.push(beginId);
    dis[beginId] = 0;
    ans[beginId].push_back(beginId);
    while (!q.empty())
    {
      int t = q.front();
      q.pop();

      for (int i = 0; i < graph[t].size(); i++)
      {
        int id = graph[t][i];
        if (dis[id] == INT_MAX)
        {
          dis[id] = dis[t] + 1;
          ans[id].push_back(t);
        }
        else if (dis[id] == dis[t] + 1)
        {
          ans[id].push_back(t);
        }
      }
    }

    vector<vector<string>> ret;

    function<void(int,vector<string>&)> dfs = [&](int index,vector<string>& cur) {
      if (index == endId)
      {
        cur.push_back(endWord);
        ret.push_back(cur);
        return;
      }
      for (int i = 0; i < ans[index].size(); i++)
      {
        cur.push_back(reverse_mp[ans[index]]);
        dfs(ans[index][i], cur);
        cur.pop_back();
      }
    };

  }
};

#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
  {
    vector<vector<string>> res;
    // 因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表，这里命名为「字典」
    unordered_set<string> dict = {wordList.begin(), wordList.end()};
    // 修改以后看一下，如果根本就不在 dict 里面，跳过
    if (dict.find(endWord) == dict.end())
    {
      return res;
    }
    // 特殊用例处理
    dict.erase(beginWord);

    // 第 1 步：广度优先遍历建图
    // 记录扩展出的单词是在第几次扩展的时候得到的，key：单词，value：在广度优先遍历的第几层

    // 从begin到string 需要多少步
    unordered_map<string, int> steps = {{beginWord, 0}};
    
    // 记录了单词是从哪些单词扩展而来，key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
    unordered_map<string, set<string>> from = {{beginWord, {}}};
    int step = 0;
    bool found = false;
    queue<string> q = queue<string>{{beginWord}};
    int wordLen = beginWord.length();
    while (!q.empty())
    {
      step++;
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        const string currWord = move(q.front());
        string nextWord = currWord;
        q.pop();
        // 将每一位替换成 26 个小写英文字母
        for (int j = 0; j < wordLen; ++j)
        {
          const char origin = nextWord[j];
          for (char c = 'a'; c <= 'z'; ++c)
          {
            nextWord[j] = c;
            if (steps[nextWord] == step)
            {
              from[nextWord].insert(currWord);
            }
            
            if (dict.find(nextWord) == dict.end())
            {
              continue;
            }
            // 如果从一个单词扩展出来的单词以前遍历过，距离一定更远，为了避免搜索到已经遍历到，且距离更远的单词，需要将它从
            // dict 中删除
            dict.erase(nextWord);
            // 这一层扩展出的单词进入队列
            q.push(nextWord);
            // 记录 nextWord 从 currWord 而来
            from[nextWord].insert(currWord);
            // 记录 nextWord 的 step
            steps[nextWord] = step;
            if (nextWord == endWord)
            {
              found = true;
            }
          }
          nextWord[j] = origin;
        }
      }
      if (found)
      {
        break;
      }
    }
    // 第 2 步：深度优先遍历找到所有解，从 endWord 恢复到 beginWord ，所以每次尝试操作 path 列表的头部
    if (found)
    {
      vector<string> Path = {endWord};
      dfs(res, endWord, from, Path);
    }
    return res;
  }

  void dfs(vector<vector<string>>& res, const string& Node, unordered_map<string, set<string>>& from,
           vector<string>& path)
  {
    if (from[Node].empty())
    {
      res.push_back({path.rbegin(), path.rend()});
      return;
    }
    for (const string& Parent : from[Node])
    {
      path.push_back(Parent);
      dfs(res, Parent, from, path);
      path.pop_back();
    }
  }
};