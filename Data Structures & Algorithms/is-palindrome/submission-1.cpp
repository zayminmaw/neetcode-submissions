class Solution {
public:
    bool isPalindrome(string s) {
        int leftSkip = 0;
        int rightSkip = 0;
        for (int i = 0; i < s.length(); i++) {
            int leftPos = i + leftSkip;
            int rightPos = s.length() - 1 - i - rightSkip;
            while (!isalnum(s[leftPos]) && leftPos < rightPos)
            {
                leftSkip++; 
                leftPos++;
            }
            while (!isalnum(s[rightPos]) && rightPos > leftPos)
            {
                rightSkip++; 
                rightPos--;
            }
            if (tolower(s[leftPos]) != tolower(s[rightPos]))
                return false;
            if (leftPos == rightPos || leftPos + 1 == rightPos || leftPos == rightPos - 1)
                return true;
        }
        return true;
    }
};
