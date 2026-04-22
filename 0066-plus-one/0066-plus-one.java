class Solution {
    public int[] plusOne(int[] digits) {
        
        // Traverse from last
        for (int i = digits.length - 1; i >= 0; i--) {
            
            if (digits[i] < 9) {
                digits[i]++;   // simple increment
                return digits; // done
            }
            
            digits[i] = 0; // carry forward
        }
        
        // If all digits were 9
        int[] result = new int[digits.length + 1];
        result[0] = 1;
        
        return result;
    }
}