#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
bool cmp(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }
class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>> &properties) {

    sort(properties.begin(), properties.end(), cmp);
    // for (int i = 0; i < properties.size(); i++) {
    //   for (int j = 0; j < properties[i].size(); j++) {
    //     cout << " " << properties[i][j];
    //   }
    //   cout<<endl;
    // }
    int ans = 0;
    int index = 0;
    for (int i = 1; i < properties.size(); i++) {
      if (properties[i][0] > properties[index][0] &&
          properties[i][1] > properties[index][1]) {
        while (index < i &&
               properties[index][0]<properties[i][0] && properties[index][1]<properties[i][1]) {
          ans++;
          index++;
        } 
      } else if (properties[i][1] < properties[index][1]) {
        index=i;
      }
    }
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  vector<vector<int>> pro = {{1, 1}, {2, 1}, {2, 2}, {1, 2}};
  cout<<solution.numberOfWeakCharacters(pro)<<endl;
  return 0;
}