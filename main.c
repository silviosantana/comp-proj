#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100000000
char result[TAM];
char aux[TAM];

int end;
//S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))
//S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))((S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(KK))K)

void tiraParentese(char *result)
{
    int count = 1;
    int i;
    for(i = 1; count > 0; i++)
    {
        if(result[i] == '(')
        {
            count++;
        }
        else if(result[i] == ')')
        {
            count--;
        }
        aux[i-1] = result[i];
    }
    while(result[i] != '\0')
    {//i - 2 para sobrescrever o ) que fica no lado acima
        aux[i-2] = result[i];
        i++;
    }
    aux[i-2] = '\0';
    memcpy(result,aux,i-1);
    //memcpy(result,aux,sizeof(aux)+1);
    //resposta = aux;
}

void k_combinator(char * str){
	//char result[TAM];
	int count = 0;
	int i, j;

	//get the first argument and put it into result.
	if(str[1] == '\0')
    {
        end = 1;
        return ;
    }
	else if (str[1] != '(')
    {
		i = 1;
		j = 0;
		aux[j] = str[i];
		j++;
		i++;
		aux[j] = '\0';
	}
	else
    {
		aux[0] = str[1];
		count = 1;
		for (i = 2, j = 1; count > 0; i++, j++)
		{
			if (str[i] == '(')
            {
				count++;
			}else if (str[i] == ')')
			{
				count--;
			}
			aux[j] = str[i];
		}
		aux[j] = '\0';
	}

	//ignore the second argument
	if(str[i] == '\0')
    {
        end = 1;
        return ;
    }
	else if (str[i] != '(')
    {
		i++;
	}
	else
	{
		count = 1;
		for (i++; count > 0; i++)
		{
			if (str[i] == '(')
            {
				count++;
			}
            else if(str[i] == ')')
            {
				count--;
			}
		}
	}

	//put the rest of the string into result
	while (str[i] != '\0')
    {
		aux[j] = str[i];
		j++;
		i++;
	}
	aux[j] = '\0';

	memcpy(str, aux, j+1);
}
//S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))((S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(KK))K)

void s_combinator(char* str){
	int i, j, count = 0;
	int b_begin, b_end, c_begin, c_end;
	int i_aux = 0; //save the current position of aux

	//get the first argument and put it into aux <aux = (a >.
	aux[0] = '(';
	if(str[1] == '\0')
    {
        end = 1;
        return ;
    }
	else if (str[1] != '(')
    {
		i = 1;
		j = 1;
		aux[j] = str[i];
		i_aux = j;
		j++;
		i++;
	}else{
		aux[1] = str[1];
		count = 1;
		for (i = 2, j = 2; count > 0; i++, j++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
			aux[j] = str[i];
		}
		i_aux = j - 1;
	}

	//get the beginning and eding indexes of b
	b_begin = i;
	if(str[i] == '\0')
    {
        end = 1;
        return ;
    }
	else if (str[i] != '('){
		b_end = i;
		i++;
	}else{
		count = 1;
		for (i ++; count > 0; i++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
		}
		b_end = i - 1;
	}

	//get the beginning and eding indexes of c and concat aux and c <aux = (ac)>
	c_begin = i;
	j = i_aux + 1;
	if(str[i] == '\0')
    {
        end = 1;
        return ;
    }
	else if(str[i] != '('){
		c_end = i;
		aux[j] = str[i];
		j++;
		aux[j] = ')';
		i_aux = j;
		i++;
	}else{
		aux[j] = str[i];
		count = 1;
		for (i ++, j++; count > 0; i++, j++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
			aux[j] = str[i];
		}
		aux[j] = ')';
		i_aux = j;
		c_end = i - 1;
	}

	i_aux ++;
	aux[i_aux] = '('; // aux = "(ac)("

	//concat aux and b <aux = (ac)(b>
	for(i = b_begin, j = i_aux + 1; i <= b_end; i++, j++){
		aux[j] = str[i];
	}

	//concat aux and c <aux = (ac)(bc)>
	for(i = c_begin, j = j; i <= c_end; i++, j++){
		aux[j] = str[i];
	}
	aux[j] = ')';

	//concat aux and the rest of the string
	i = c_end + 1;
	j++;
	while (str[i] != '\0'){
		aux[j] = str[i];
		j++;
		i++;
	}

	aux[j] = '\0';
	memcpy(str, aux, j + 1);
}

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%s", result);
    printf("%s\n", result);

    end = 0;
    while(end == 0)
    {
        if(result[0] == '(')
        {
            tiraParentese(result);
            //printf("\n%s", result);
        }
        else if(result[0] == 'S')
        {
            //pegar 3 componentes e concatenar
            s_combinator(result);
            //printf("\n%s", result);
        }
        else //caso seja um K
        {
            //pegar 2 componentes e retornar o primeiro
            k_combinator(result);
            //printf("\n%s", result);
        }
    }
    printf("%s\n", result);
    return 0;
}
