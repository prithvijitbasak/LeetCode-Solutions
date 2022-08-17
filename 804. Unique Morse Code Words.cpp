//Editorial: https://leetcode.com/problems/unique-morse-code-words/discuss/120675/JavaC++Python-Easy-and-Concise-Solution
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> ust;
        for(auto it:words)
        {
            string word="";
            for(char ch:it)
                word += codes[ch-'a'];
            ust.insert(word);
        }
        return ust.size();
    }
};
