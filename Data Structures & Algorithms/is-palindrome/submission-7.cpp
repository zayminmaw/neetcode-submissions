class Solution {
public:
    bool isPalindrome(string s) {
        int leftPos = 0;
        int rightPos = s.length() - 1;
        while (leftPos < rightPos) {
            while (!isalnum(s[leftPos]) && leftPos < rightPos)
                leftPos++;
            while (!isalnum(s[rightPos]) && rightPos > leftPos)
                rightPos--;
            if (tolower(s[leftPos]) != tolower(s[rightPos]))
                return false;
            leftPos++;
            rightPos--;
            if (leftPos == rightPos - 1 )
                return true;
        }
        return true;
    }
};
