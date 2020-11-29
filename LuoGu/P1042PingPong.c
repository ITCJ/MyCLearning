#include <stdio.h>

void showResult(int W, int L, int mode)
{
    while (W!=0 && L!=0 )
    {
        int resultW; int resultL;

        if (W-mode >= mode) 
        {
            resultW = mode;
            W -= mode;
        }
        else if (W-mode < mode)
        {
            resultW = W;
            W = 0;
        }
        
        if (L-mode >= mode)
        {
            L -= mode;
            resultL = mode;
        }
        else if (L-mode < mode)
        {
            resultL = L;
            L = 0;
        }

        printf("%d:%d\n", resultW, resultL);
    }

}

int main()
{
    char score[2][30] = {0};
    int W[2], L[2];
        W = L = 0;
    
    scanf("%s", &score[0]);
    scanf("%s", &score[1]);

    for (int i = 0; i < 2; i++)
    {
        int j = 0;
        while (score[i][j] != 'E')
        {
            if (score[i][j] == 'W')
            {
                W++;
            }
            else if(score[i][j] == 'L')
            {
                L++;
            }
            
            j++;
        }
    }
    showResult(W, L, 11);
    showResult(W, L, 21);
    
    return 0;
}