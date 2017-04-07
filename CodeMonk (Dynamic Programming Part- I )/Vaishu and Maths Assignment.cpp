#include <bits/stdc++.h>

using namespace std ;
int L , N , X , Y ,input;

vector <int> data ;
int possible[1000005];
int DP[1000005][105];
int calc(int currently_have , int current_position)
{
    if(current_position == N)
    {
        if(currently_have >= X && currently_have <= Y)
        {
            possible[currently_have] = 1 ;
        }
        return 1;
    }

    if(currently_have < X || currently_have > Y)
    {
        return -1 ;
    }
    if(DP[currently_have][current_position] == 1)
    {
        return 1;
    }
    else if(DP[currently_have][current_position] == -1)
    {
        return -1;
    }


    int ans1 = calc(currently_have + data[current_position] , current_position+1);
    int ans2 = calc(currently_have - data[current_position] , current_position+1);

    if(ans1 == 1 || ans2 == 1)
    {
        DP[currently_have][current_position] = 1 ;
        possible[currently_have] = 1 ;
    }
    else
    {
        DP[currently_have][current_position] = -1 ;
    }
    return DP[currently_have][current_position];

}
int main()
{


    scanf("%d %d %d %d", &L , &N , &X , &Y);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &input );

        data.push_back(input);
    }

    calc(L , 0);

    int cum_sum[10005];

    cum_sum[0] = possible[0];

    for(int i = 0 ; i < 10005 ; i++)
    {
        cum_sum[i] = cum_sum[i-1] + possible[i];
    }

    int Q ;
    char input_char ;

    scanf("%d", &Q);

    for(int i = 0 ; i < Q ; i++)
    {
        scanf("%c", &input_char);
        scanf("%c %d", &input_char , &input);
        //cout << input_char << endl ;
        if(input_char == '<')
        {
            if(input == 0)
            {
                printf("NO\n");
            }
            else if(cum_sum[input-1] > 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n" );
            }
        }
        else if(input_char == '>')
        {

            if(cum_sum[Y]- cum_sum[input] > 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n" );
            }
        }
    }
}
