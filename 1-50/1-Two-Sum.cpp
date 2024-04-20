#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
   /**
    * @brief Given an array of numbers, find the indices of the 2 numbers that add up to a target value.
    * This solution iterates over the array, for each number it saves its complement (target - number) to a map. 
    * If the number is already in the map, the solution has been found.
    * @param nums The array.
    * @param target The target.
    * @return vector<int> 
    */
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[target - nums[i]] = i;
            } else {
                result.push_back(i);
                result.push_back(map[nums[i]]);
            }
        }
    }
};