#include <iostream>
#include <vector>

int find(const std::vector<int>& nums, int target, bool find_first) {
    int left = 0;
    int right = nums.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid; 
            if (find_first) {
                right = mid - 1; 
            }
            else {
                left = mid + 1;  
            }
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

void solve(const std::vector<int>& nums, int target) {
    int first = find(nums, target, true);

    if (first == -1) {
        std::cout << "Element not found in the array" << std::endl;
        return;
    }

    int last = find(nums, target, false);
    std::cout << "The first occurrence of element " << target << " is located at index " << first << std::endl;
    std::cout << "The last occurrence of element " << target << " is located at index " << last << std::endl;
}

int main() {
    std::vector<int> nums1 = { 2, 5, 5, 5, 6, 6, 8, 9, 9, 9 };
    int target1 = 5;
    solve(nums1, target1);

    std::vector<int> nums2 = { 2, 5, 5, 5, 6, 6, 8, 9, 9, 9 };
    int target2 = 4;
    solve(nums2, target2);

    return 0;
}
