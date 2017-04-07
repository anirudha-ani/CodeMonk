// Vaishu and Tower Arrangements

#include <bits/stdc++.h>

using namespace std ;

int main()
{
  int T ;
  int cum_minus[100005];
  int cum_plus[100005];

  scanf("%d", &T);

  for(int i = 0 ; i < T ; i++)
  {
      vector <int> data ;



      memset(cum_minus , 0 , sizeof(cum_minus));
      memset(cum_plus , 0 , sizeof(cum_plus));
      int input , N ;

      scanf("%d", &N);

      for(int j = 0 ; j < N ; j++)
      {
          scanf("%d",&input );

          data.push_back(input);

          if(j != 0)
          {
              if(input == 1)
              {
                  cum_plus[j] += cum_plus[j-1] + 1 ;
                  cum_minus[j] += cum_minus[j-1];
              }
              else if(input == -1)
              {
                  cum_plus[j] += cum_plus[j-1] ;
                  cum_minus[j] += cum_minus[j-1] + 1;
              }
          }
          else
          {
              if(input == 1)
              {
                  cum_plus[j] = 1;
              }
              else
              {
                  cum_minus[j] = 1 ;
              }
          }

      }
      int ans = 555555;
      for(int j = 0 ; j < N-1 ; j++)
      {
          //cout << j << " " ;
          //cout << cum_plus[j] << " " ;
          //cout << cum_minus[j] << endl ;

          ans = min(ans , cum_plus[j] + (cum_minus[N-1] - cum_minus[j]) );

      }
      printf("%d\n",ans  );



  }
  return 0;
}
