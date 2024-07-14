#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int middlePoint = (nums1.size() + nums2.size()) / 2;
        vector<int> sorted = {};
        int index1 = 0;
        int index2 = 0;
        while (index1 < nums1.size() && index2 < nums2.size()) {
            sorted.push_back(nums1[index1] < nums2[index2] ? nums1[index1++]
                                                           : nums2[index2++]);
            if (sorted.size() > middlePoint) {
                break;
            }
        }
        while (index1 < nums1.size()) {
            sorted.push_back(nums1[index1++]);
            if (sorted.size() > middlePoint) {
                break;
            }
        }
        while (index2 < nums2.size()) {
            sorted.push_back(nums2[index2++]);
            if (sorted.size() > middlePoint) {
                break;
            }
        }
        return (nums1.size() + nums2.size()) % 2 == 0
                   ? (sorted[middlePoint] + sorted[middlePoint - 1]) / 2.0
                   : sorted[middlePoint];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
}