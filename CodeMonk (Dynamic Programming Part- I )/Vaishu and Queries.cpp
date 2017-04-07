#include <bits/stdc++.h>

using namespace std ;
struct dataline
{
    int R ;
    int B ;
}data[105];

int DP[105][105][105];
int N ;

int calc(int remaining_red, int remaining_blue , int current_line)
{
    if(current_line >= N)
    {
        return 0;
    }
    if(DP[remaining_red][remaining_blue][current_line] != -1)
    {
        return DP[remaining_red][remaining_blue][current_line];
    }

    int ans1 = 0 , ans2 = 0 ;

     if(data[current_line].R <= remaining_red && data[current_line].B <= remaining_blue)
     {
         ans1 = 1+ calc(remaining_red - data[current_line].R , remaining_blue - data[current_line].B , current_line + 1);
     }
     ans2 =  calc(remaining_red  , remaining_blue  , current_line + 1);

     DP[remaining_red][remaining_blue][current_line] = max(ans1 , ans2);

     return DP[remaining_red][remaining_blue][current_line];

}

int main()
{

    string input ;
    memset(DP , -1 , sizeof(DP));
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++)
    {
        cin >> input ;

        int length = input.size();
        int Red = 0 ;
        int Blue = 0 ;
        for(int j = 0 ; j < length ; j++)
        {
            if(input[j] == 'R')
            {
                Red++;
            }
            else
            {
                Blue++;
            }
        }
        data[i].R = Red ;
        data[i].B = Blue ;


    }
    int query ,given_red , given_blue;

    scanf("%d", &query);

    for(int i = 0 ; i < query ; i++)
    {
        scanf("%d %d", &given_red , &given_blue);
        printf("%d\n", calc(given_red , given_blue , 0));
    }
    return 0;
}
