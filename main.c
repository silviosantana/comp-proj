// Gerador para K e S

#include <stdio.h>
#include <stdlib.h>

char resposta[1000];
char aux[1000];

int begin , end;

S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))((S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(KK))K)

void tiraParentese()
{
    int contEsq = 1, contDir = 0;
    int i;
    for(i = 1; contEsq != contDir; i++)
    {
        if(resposta[i] == '(')
        {
            contEsq++;
        }
        else if(resposta[i] == ')')
        {
            contDir++;
        }
        aux[i] = resposta[i];
    }
    while(resposta[i] != '\0')
    {
        aux[i-1] = resposta[i];
        i++;
    }
    aux[i-1] = '\0';

    //resposta = aux;
}

char pegaCadeia(int i)
{
    if(resposta[i] == 'K' || resposta[i] == 'S')
    {
        return resposta[i];
    }
    else
    {
        //pega termo entre parenteses
    }
}

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%s", resposta);

    for(condição de parada?)
    {
        if(resposta[0] == '(')
        {
            tiraParentese();
        }
        else if(resposta[0] == 'S')
        {
            //pegar 3 componentes e concatenar
        }
        else //caso seja um K
        {
            //pegar 2 componentes e retornar o primeiro
        }
    }

    return 0;
}



