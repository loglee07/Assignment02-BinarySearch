#include <iostream>
#include <vector>
#include <string>

int binarySearchIterative(
    const std::vector<int>& nums,
    int target,
    int& comparisons) {

    int left = 0;
    int right = nums.size() - 1;
    comparisons = 0;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        comparisons++;

        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(
    const std::vector<int>& nums,
    int target,
    int left,
    int right,
    int& comparisons) {

    if (left > right) {
        return -1;
    }

    int middle = left + (right - left) / 2;
    comparisons++;

    if (nums[middle] == target) {
        return middle;
    }

    if (nums[middle] < target) {
        return binarySearchRecursive(
            nums,
            target,
            middle + 1,
            right,
            comparisons);
    }

    return binarySearchRecursive(
        nums,
        target,
        left,
        middle - 1,
        comparisons);
}

int linearSearch(
    const std::vector<int>& nums,
    int target,
    int& comparisons) {

    comparisons = 0;

    for (int i = 0; i < nums.size(); i++) {
        comparisons++;

        if (nums[i] == target) {
            return i;
        }
    }

    return -1;
}

void runTest(
    const std::vector<int>& nums,
    int target,
    const std::string& testName) {

    int linearComparisons = 0;
    int iterativeComparisons = 0;
    int recursiveComparisons = 0;

    int linearIndex = linearSearch(
        nums, target, linearComparisons);

    int iterativeIndex = binarySearchIterative(
        nums, target, iterativeComparisons);

    int recursiveIndex = binarySearchRecursive(
        nums,
        target,
        0,
        nums.size() - 1,
        recursiveComparisons);

    std::cout << "= " << testName << " =\n";
    std::cout << "Target: " << target << '\n';

    std::cout << "Linear Search: index "
              << linearIndex
              << ", comparisons "
              << linearComparisons << '\n';

    std::cout << "Iterative Binary Search: index "
              << iterativeIndex
              << ", comparisons "
              << iterativeComparisons << '\n';

    std::cout << "Recursive Binary Search: index "
              << recursiveIndex
              << ", comparisons "
              << recursiveComparisons << "\n\n";
}

int main() {
    std::vector<int> nums =
        {4, 9, 15, 22, 31, 45, 58, 63, 77, 84, 96};

    runTest(nums, 4, "First Element");
    runTest(nums, 96, "Last Element");
    runTest(nums, 45, "Middle Element");
    runTest(nums, 0, "Missing Below Range");
    runTest(nums, 50, "Missing Inside Range");

    return 0;
}
