#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string findSubstring(string s, int k) {
    int index = -1;
    map<char,char>mp;
    mp.insert('a', 'a');
    mp.insert('A', 'A');
    mp.insert('e', 'e');
    mp.insert('E', 'E');
    mp.insert('i', 'i');
    mp.insert('I', 'I');
    mp.insert('o', 'o');
    mp.insert('O', 'O');
    mp.insert('u', 'u');
    mp.insert('U', 'U');
    int largest_vowel = 0;
    int largest_index = 0;
    for(int i = 0;i<s.length();i++){
        int total_vowel = 0;
        for(int j = i;j<i+k;j++){
            if(mp.count(s[j]) > 0){
                total_vowel ++;
            }
        }
        if(total_vowel > largest_vowel){
            largest_vowel = total_vowel;
            largest_index = i;
        }
    }
    if(largest_index == 0){
        return "Not found!";
    }else{
        return s.substr(largest_index,k);
    }
}

int main()