#include <stdio.h>
#include <locale.h>
char str[255];
int scopes(char *str1);
int stringLength (char *string);
int main(void){
	setlocale(LC_ALL,"rus");
	printf("Введите строку: ");
	gets(str);
	switch (scopes(str))
	{
		case -1: printf("Во введенной строке нет скобок.\n"); break;
		case 0: printf("Баланс скобок во введенной строке нарушен.\n"); break;
		case 1: printf("Баланс скобок во введенной строке выдержан.\n");
	}
	printf("Длина введенной строки - %d символов.\n",stringLength(str));
	return 0;
}
int stringLength(char *string){
	int kol;
	for (kol=0;;kol++)
		if (string[kol]=='\0') break;
	return kol;
}
int scopes(char *str1){
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