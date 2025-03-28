#include "Solution.h"

#include <unordered_map>

namespace p2780 {
    int Solution::minimumIndex(const std::vector<int> &nums) {
        std::unordered_map<int, int> map;
        int dominant = 0;
        int max = 0;
        int value;

        // look for dominant number

        for (int num : nums) {
            if (map.contains(num)) {
                value = map.at(num);
            } else {
                value = 0;
            }

            if (++value > max) {
                dominant = num;
                max = value;
            }

            map[num] = value;
        }

        // find place to slice

        value = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == dominant) {
                value++;
            }

            if ((i + 1) / 2 < value) {
                if ((nums.size() - (i + 1)) / 2 < max - value) {
                    return i;
                }
            }
        }

        return -1;
    }
}
