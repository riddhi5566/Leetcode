class Solution {
public:
    bool isHappy(int n) {
        int square = sq_digits(n);
        int count = 0;
        while(count <= 10)
        {
            if(square == 1)
            {
                return true;
            }
            else
            {
                square = sq_digits(square);
            }
            count++;
        }
        return false;
    }

    int sq_digits(int num)
    {
        int n = 0;
        while(num > 0)
        {
            int dig = num%10;
            n = n + dig*dig;
            num = num / 10;
        }

        return n;
    }
};