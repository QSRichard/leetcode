#include <cctype>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int countValidWords(string sentence) {
    vector<string> words;
    int start = 0, end = sentence.size() - 1;
    while (sentence[start] == ' ')
      start++;
    if (start == sentence.size())
      return 0;
    while (sentence[end] == ' ')
      end--;
    for (int i = start + 1; i <= end; i++) {
      if (sentence[i] == ' ') {
        words.push_back(sentence.substr(start, i - start));
        while (sentence[i] == ' ')
          i++;
        start = i;
      }
    }
    words.push_back(sentence.substr(start, end - start + 1));
    // for (auto &str : words)
    //   cout << str << endl;
    int ans = 0;
    for (auto &str : words) {
      bool flag = true;
      int last = str.size() - 1;
      if (str[last] == '!' || str[last] == '.' || str[last] == ',')
        last--;
      if (last < 0) {
        ans++;
        continue;
      }
      if (!islower(str[0]))
        continue;
      if (str[last] == '-')
        continue;
      int number=0;
      for (int i = 1; i <= last; i++) {
        if (!islower(str[i])) {
          if (str[i] != '-' || number || !islower(str[i+1])) {
            flag = false;
            break;
          }
          number++;
        }
      }
      if (flag)
        ans++;
    }
    return ans;
  }
};


int main(int argc, char *argv[]) {

  Solution solution;
  string sentence = ".";
  solution.countValidWords(sentence);
  return 0;
}