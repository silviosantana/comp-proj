// Gerador para K e S

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
char result[TAM];
char aux[TAM];

int end;

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
    memcpy(result,aux,sizeof(aux)+1);
    //resposta = aux;
}

void k_combinator(char * str){
	char result[TAM];
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
		result[j] = str[i];
		j++;
		i++;
		result[j] = '\0';
	}
	else
    {
		result[0] = str[1];
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
			result[j] = str[i];
		}
		result[j] = '\0';
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
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';

	//printf("%s\n", result);

	memcpy(str, result,sizeof(result));
}

void s_combinator(char* str){
	char a[TAM];
	char b[TAM];
	char c[TAM];
	char rest[TAM];
	int i, j, count = 0;

	//get the first argument and put it into a.

	if(str[1] == '\0')
    {
        end = 1;
        return ;
    }
	else if (str[1] != '(')
    {
		i = 1;
		j = 0;
		a[j] = str[i];
		j++;
		i++;
		a[j] = '\0';
	}else{
		a[0] = str[1];
		count = 1;
		for (i = 2, j = 1; count > 0; i++, j++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
			a[j] = str[i];
		}
		a[j] = '\0';
	}
	//printf("%s\n", a);

	//get the second argument and put it into b.
	if(str[i] == '\0')
    {
        end = 1;
        return ;
    }
	else if (str[i] != '('){
		b[0] = str[i];
		b[1] = '\0';
		i++;
	}else{
		b[0] = str[i];
		count = 1;
		for (i ++, j = 1; count > 0; i++, j++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
			b[j] = str[i];
		}
		b[j] = '\0';
	}
	//printf("%s\n", b);

	//get the second argument and put it into b.
	if(str[i] == '\0')
    {
        end = 1;
        return ;
    }
	else if(str[i] != '('){
		c[0] = str[i];
		c[1] = '\0';
		i++;
	}else{
		c[0] = str[i];
		count = 1;
		for (i ++, j = 1; count > 0; i++, j++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
			c[j] = str[i];
		}
		c[j] = '\0';
	}
	//printf("%s\n", c);

	j = 0;
	while (str[i] != '\0'){
		rest[j] = str[i];
		j++;
		i++;
	}
	rest[j] = '\0';

	//printf("%s\n", rest);

	strcat(a,c);
	strcat(b,c);
	strcat(a,b);
	strcat(a,rest); //a has the resulting string.

	//printf("%s\n", a);
	memcpy(str, a,sizeof(a));
}

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%s", result);
    printf("%s", result);

    end = 0;
    while(end == 0)
    {
        if(result[0] == '(')
        {
            tiraParentese(result);
            printf("\n%s", result);
        }
        else if(result[0] == 'S')
        {
            //pegar 3 componentes e concatenar
            s_combinator(result);
            printf("\n%s", result);
        }
        else //caso seja um K
        {
            //pegar 2 componentes e retornar o primeiro
            k_combinator(result);
            printf("\n%s", result);
        }
    }

    return 0;
}



