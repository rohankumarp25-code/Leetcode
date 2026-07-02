//Reverse Integer solution
class Solution {
public:
    int reverse(int x) {
        int n;
        vector<int>range={2,1,4,7,4,8,3,6,4,7};
        vector<int>rev;
        if(x==-2147483648)
        return 0;
        
          if (x < 0){

            n = -x;
        }
            else if(x==0)
            return 0;
        else
            n = x;
        int ans = 0;
        while(n>0){
            rev.push_back(n%10);
            n=n/10;
        }
        if(rev[0]>2&&rev.size()>=10){
            return 0;
        }
        if(rev[0]==2&&rev.size()==10){
            for(int i=0;i<10;i++){
                if(range[i]<rev[i])
                return 0;
                if(rev[i]<range[i])
                break;
            }
        }
        for(int i=0;i<rev.size();i++){
            ans=ans*10+rev[i];
        }
       if (x < 0)
            return -ans;
            return ans;
    }
};