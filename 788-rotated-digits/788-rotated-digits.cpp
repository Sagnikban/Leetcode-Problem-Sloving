class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            int x=i,q=0,cnto=0;
            while(x){
                int p=x%10;
                if(p==3 || p==4 || p==7){q=1;break;}
                else if(p==1 || p==0 || p==8);
                else cnto++;
                x=x/10;
            }
            if(q==0 && cnto) cnt++;
        }
        return cnt;
    }
};