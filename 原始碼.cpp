#include<iostream>
#define N 32*20+1
using namespace std;

int dp[N][N];

void dp_init(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=0;
}

int find_diff(int a,int b,int c){
    int max_num = a,min_num = a;
    if(b>max_num)max_num=b;
    if(b<min_num)min_num=b;
    if(c>max_num)max_num=c;
    if(c<min_num)min_num=c;

    return max_num-min_num;
}

int main(){
    int caseNum;
    cin>>caseNum;
    for(int h=1;h<=caseNum;h++){
        int num_of_candies;
        cin>>num_of_candies;

        int candy[num_of_candies],total=0;
        for(int i=0;i<num_of_candies;i++){
            cin>>candy[i];
            total+=candy[i];
        }


        dp_init();
        dp[0][0]=1;
        //cout<<"1"<<endl;
        for(int k=0;k<num_of_candies;k++)
            for(int i=total;i>=0;i--)
                for(int j=total;j>=0;j--)
                    if(dp[i][j]==1){
                        dp[i+candy[k]][j]=1;
                        dp[i][j+candy[k]]=1;
                        //cout<<i<<" "<<j<<" "<<candy[k]<<endl;
                    }
        int min_w = total;

        //

        for(int i=0;i<=total;i++)
            for(int j=0;j<=total;j++)
                if(dp[i][j]==1){
                    int c = total-i-j;
                    int d = find_diff(i,j,c);

                    if(d<min_w){
                        min_w =d;

                    }

                }

        cout<<"Case "<<h<<": "<<min_w<<endl;

    }


    return 0;
}
