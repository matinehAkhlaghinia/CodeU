/* Given two strings, write a method to decide if one is a permutation of the other.
For example:
Listen, Silent ⇒ True
Triangle, Integral ⇒ True
Apple, Pabble ⇒ False */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool mapHasOnlyZeroes(const unordered_map<char, int>& freq_map) {
  unordered_map<char, int>::const_iterator it;
  for(it = freq_map.begin(); it != freq_map.end(); it++) {
    if(it->second != 0)
      return false;
  }
  return true;
}

bool isPermutation(const string& s1, const string& s2) {
  unordered_map<char, int> frequency_map;
  if(s1.length() != s2.length())
    return false;
  for(int i = 0; i < s1.length(); i++) {
    frequency_map[s1[i]]++;
  }
  for(int j = 0; j < s2.length(); j++) {
    if(frequency_map.find(s2[j]) != frequency_map.end())
      frequency_map[s2[j]]--;
    else
      return false;
  }
  return mapIsEmpty(frequency_map);
}

int main() {
  string s1, s2;
  getline (cin,s1);
  getline (cin,s2);
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  if(isPermutation(s1, s2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}