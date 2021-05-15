/*
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

*/

//My solution
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() <= 1) return true; // base case.
        unordered_map<char, int> map;   // store char and alphabet positions in dictionary.
        for (int i = 0; i < order.size(); i++) {
            map[order[i]] = i;
        } 
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i], word2 = words[i+1];
            int j;
            for (j = 0; j < word1.size() and j < word2.size(); j++) { // compare character by character.
                if (map[word1[j]] > map[word2[j]]) return false; // wrong order.
                else if (map[word1[j]] < map[word2[j]]) break; // correct order.
            }
            if (j == word2.size() && j!=word1.size()) return false; // word1 is longer than word2
        }
        return true;
    
    }
};
