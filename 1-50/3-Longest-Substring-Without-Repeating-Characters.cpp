#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
   /**
    * @brief Given a string s find the longest substring without repeating characters.
    * This solution starts by saving the current substring, and if it finds a repeated character, it removes all characters up to the repeating character.
    * Example:
    * s = "pwwkew"
    * 1.
    *   current char: 'p'
    *   chars: []
    *   res: 0
    *   since 'p' is not in chars, add it
    * 2.
    *   current char: 'w'
    *   chars: ['p']
    *   res: 1
    *   since 'w' is not in chars, add it
    * 3.
    *   current char: 'w'
    *   chars: ['p', 'w']
    *   res: 2
    *   since 'w' is already in chars, remove all elements until 'w'
    * 4.
    *   current char: 'k'
    *   chars: ['w']
    *   res: 2
    *   since 'k' is not in chars, add it
    * 5.
    *   current char: 'e'
    *   chars: ['w', 'k']
    *   res: 2
    *   since 'e' is not in chars, add it
    * 6.
    *   current char: 'w'
    *   chars: ['w', 'k', 'e']
    *   res: 3
    *   since 'w' is already in chars, remove all elements until 'w'
    * @param s The string
    * @return int The length of the longest substring. 
    */
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<char> chars;
        for (char c : s) {
            std::vector<char>::iterator position = find(chars.begin(), chars.end(), c);
            if (position == chars.end()) {
                chars.push_back(c);
            } else {
                chars.erase(chars.begin(), ++position);
                chars.push_back(c);
            }
            if (chars.size() > res) {
                res = chars.size();
            }
        }
        return res;
    }
};