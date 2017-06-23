#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 500

void should_return_inverse_string ();
char str[255];
int scopes(char str1[255]){
	bool any = false;
	int r = 0, s = 0, f = 0;
	for (int i = 0; str1[i] != '\0'; i++){
		if (str1[i] == '('){
			r++;
			any = true;
		}
		if (str1[i] == '['){
			s++;
			any = true;
		}
		if (str1[i] == '{'){
			f++;
			any = true;
		}
		if (str1[i] == ')'){
			r--;
			any = true;
		}
		if (str1[i] == ']'){
			s--;
			any = true;
		}
		if (str1[i] == '}'){
			f--;
			any = true;
		}
	}
	if (any){
		if (r == 0 && s == 0 & f == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return -1;
	}
}

int main(void){
	
	gets(str);
	int res = scopes(str);
	printf("res: %d\n%s\n", res, str);
	printf("Now the inverce_string function will execute...\n");
	should_return_inverse_string();
	return 0;
}

void should_return_inverse_string ()

{
	char initial_string[MAX_LENGTH]={'\0'};
	char inverse_string[MAX_LENGTH]={'\0'};
	
	printf("Input initial string:");
	fgets(initial_string, MAX_LENGTH, stdin);
	
	for(int i=strlen(initial_string)-1;  i!=-1; i--)
	{
		strncat(inverse_string,initial_string+i,1);
	}
	puts(inverse_string);
}

