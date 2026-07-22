class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPos = 0;
        int rightPos = numbers.size() - 1;

        while (leftPos < rightPos) {
            if (numbers[leftPos] + numbers[rightPos] > target)
                rightPos--;
            if (numbers[leftPos] + numbers[rightPos] < target)
                leftPos++;
            if (numbers[leftPos] + numbers[rightPos] == target)
                break;  
        }
        return vector<int>{leftPos + 1, rightPos + 1};
    }
};
