class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int carry=(digits[n]+1);
        while(carry>9 && n>0)
        {
            digits[n]=carry%10;
            carry/=10;
            n--;
            carry+=digits[n];
        }
        digits[n]=carry%10;
        carry=carry/10;
        if(n==0 && carry>0)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(carry);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};