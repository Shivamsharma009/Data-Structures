#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NO_OF_CHARS 256

struct countChar
{
	int count, index;
};

struct countChar *getCharCountArray(char *str)
{
	struct countChar *hash = (struct countChar*)calloc(sizeof(struct countChar), NO_OF_CHARS);
	int i;
	for(i = 0; str[i]; i++)
	{
		(hash[str[i]].count)++;
		if (hash[str[i]].count == 1)
			hash[str[i]].index = i;
	}
	return hash;
}

int getFirstNonRepeatingChar(char *str)
{
	struct countChar *hash = getCharCountArray(str);
	int result = INT_MAX, i;
	for(i= 0; i < NO_OF_CHARS; i++)
	{
		if(hash[i].count == 1 && result > hash[i].index)
			result = hash[i].index;
	}
	free(hash);
	return result;
}

int main()
{
	char str[] = "ravindra";
	int index = getFirstNonRepeatingChar(str);
	if(index == INT_MAX)
		printf("Either all characters are repeating or string is empty\n");
	else
		printf("First non repeating char is = %c\n", str[index]);

	return 0;
}
