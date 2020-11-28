// C:\Users\Vicky\Desktop\Dev C++\keyword

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
 
int main() 
{ 
	char file[50] = "access modifier in class.cpp"; 
	printf("Enter File name : "); 
	gets(file); 
	printf("\n");
	
	FILE * fp = fopen(file, "r");
	FILE * kout = fopen("keyword.txt", "w");
	FILE * iout = fopen("identifier.txt", "w");
 
	if (fp == NULL) 
	{
		printf("\n'%s' file not found...\n", file);
		getch();
		return 1;
	} 
		
	int k, result, count, kcount; 
	char c, str[10];
	kcount = count = 0;
	
	char keywords[][10] = {"auto", "break", "case", "char", "const", "continue", "default",
				"do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
				"long", "register", "return", "short", "signed", "sizeof", "static", "struct",
				"switch", "typedef", "union", "unsigned", "void", "volatile", "while" };

	while((c = fgetc(fp)) != EOF) 
	{ 
		if(c == ' ' || c == '\n') 
		{ 
			++count; 
//			printf("%d). %s\n", count, str);
			
			for(k=0; k<32; k++)
			{
				result = strcmp(keywords[k], str);
				if (result == 0)
				{
					++kcount;
					printf(str);
					printf("\n");
					break;
				}
			}
			
			if (result == 0)
				fprintf(kout, "%s\n", str);
			else
				fprintf(iout, "%s\n", str);
	
			strcpy(str,"");
		} 
		else 
		{ 
			if (isalpha(c) && c!=' ')
				strncat(str, &c, 1);
		} 
	} 
	
	fclose(fp); 
 	fclose(kout);
 	fclose(iout);

	printf("\n\t...'%s' file has %d words in it.\n", "keyword.txt", kcount); 
	getch();
	return 0; 
} 
