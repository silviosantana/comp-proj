#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char strin[1000] = "KS(KS)(KK)SK(SK)";

//((KKKS)(KS)KS)


void k_combinator(char * str){
	char result[1000];
	int count = 0;
	int i, j;

	//get the first argument and put it into result.
	if (str[1] != '('){
		i = 1;
		j = 0;
		result[j] = str[i];
		j++;
		i++;
		result[j] = '\0';
	}else{
		result[0] = str[1];
		count = 1;
		for (i = 2, j = 1; count > 0; i++, j++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
			result[j] = str[i];
		}
		result[j] = '\0';
	}
	
	//ignore the second argument
	if (str[i] != '('){
		i++;
	}else{
		count = 1;
		for (i++; count > 0; i++){
			if (str[i] == '('){
				count++;
			}else if (str[i] == ')'){
				count--;
			}
		}
	}

	//put the rest of the string into result
	while (str[i] != '\0'){
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';

	//printf("%s\n", result);

	strcpy(str, result);
}

void s_combinator(char* str){
	char a[1000];
	char b[1000];
	char c[1000];
	char rest[1000];
	int i, j, count = 0;

	//get the first argument and put it into a.
	if (str[1] != '('){
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
	if (str[i] != '('){
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
	if (str[i] != '('){
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

	strcpy(str, a);


}

int main(int argc, char const *argv[])
{
	char str[1000];

	strcpy(str, strin);
	printf("%s\n", str);

	//rem_parenthesis(str);

	//printf("%s", str);

	k_combinator(str);
	printf("%s\n", str);
	s_combinator(str);
	printf("%s\n", str);


	return 0;
}