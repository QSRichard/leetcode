#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <utility>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {

    if (numRows <= 1)
      return s;
    vector<char> v;
    int k = (numRows - 1) * 2;
    for (int j = 0; j < s.size(); j += k) {
      v.push_back(s[j]);
    }
    for (int i = 1; i < numRows - 1; i++) {
      int step = k - (numRows - 1 - i) * 2;
      for (int j = i; j < s.size(); j += step) {
        v.push_back(s[j]);
        step=k-step;
      }
    }
    for (int j = numRows - 1;j < s.size(); j += k) {
      v.push_back(s[j]);
    }
    return string(v.begin(), v.end());
  }
};


int main(int argc, char *argv[]) {

  Solution solution;
  string s = "PAYPALISHIRING";
  if (solution.convert(s, 3) == "PAHNAPLSIIGYIR") {
    cout<<"succefull"<<endl;
  }
  return 0;
}