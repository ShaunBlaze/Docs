class Solution {
public:
    int consecutiveNumbersSum(int N)
    {
      int ans=1;
      for(int k=2;k<sqrt(2*N);k++)
      {
        int x=(k*(k-1))/2;
        if((N-x)%k==0)
          ans++;
      }
      return ans;
    }
};
