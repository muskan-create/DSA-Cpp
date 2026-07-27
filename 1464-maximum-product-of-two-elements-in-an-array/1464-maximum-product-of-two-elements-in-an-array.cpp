class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0, secondlargest = 0;
        for(int num : nums) {
            if(num > largest)  {
            secondlargest = largest;
            largest = num;
        } else if(num > secondlargest) {
            secondlargest = num;
        }

        }
        return (largest-1) * (secondlargest-1);

    }
};