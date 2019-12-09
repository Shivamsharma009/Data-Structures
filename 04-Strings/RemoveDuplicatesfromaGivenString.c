#include<stdio.h>
#include<string.h>
#define count 256

char* RemoveDuplicatesCharacter(char* str)
{
	int hash[count] = {0};
	int currindex=0,finindex=0;
	char temp;
	while(str[currindex])
	{
       temp = str[currindex];
       if(hash[temp] == 0)
       {
        hash[temp] = 1;
        str[finindex++] = str[currindex];
       }
       currindex++;
	}
	str[finindex] = '\0';
	return str;
}
//Driver program

int main()
{
  char str[] = "abbacdefbbdd";
   printf(" The Remove Duplicate string is %s ",RemoveDuplicatesCharacter(str));

    return 0;

}
