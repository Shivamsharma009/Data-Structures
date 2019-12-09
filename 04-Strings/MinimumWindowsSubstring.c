// C program to find smallest window containing all characters of a pattern.
#include<stdio.h>
#include<string.h>

#define no_of_chars 256
char* substring(char s[],  int p, int l) {
char sub[40];
   int c = 0;

   while (c < l) {
      sub[c] = s[p+c];
      c++;
   }
   sub[c] = '\0';
return sub;
}
// Function to find smallest window containing
// all characters of 'pat'
char* smallestwindow(char str[40], char pat[20])
{        int hash_pat[no_of_chars] = {0};
	int hash_str[no_of_chars] = {0};
	int len1,len2,i,j,len_window;
char sub[20];
	int count = 0; // count of characters
		int start = 0, start_index = -1, min_len = 9999;
	 len1 = strlen(str);
	len2 = strlen(pat);
	// check if string's length is less than pattern's
	// length. If yes then no such window can exist
	if (len1 < len2)
	{
		printf("No such window exists");
		return "";
	}



	// store occurrence ofs characters of pattern
	for (i = 0; i < len2; i++)
		hash_pat[pat[i]]++;



	// start traversing the string

	for (j = 0; j < len1 ; j++)
	{
		// count occurrence of characters of string
		hash_str[str[j]]++;

		// If string's char matches with pattern's char
		// then increment count
		if (hash_pat[str[j]] != 0 &&
			hash_str[str[j]] <= hash_pat[str[j]] )
			count++;

		// if all the characters are matched
		if (count == len2)
		{
			// Try to minimize the window i.e., check if
			// any character is occurring more no. of times
			// than its occurrence in pattern, if yes
			// then remove it from starting and also remove
			// the useless characters.
			while ( hash_str[str[start]] > hash_pat[str[start]]
				|| hash_pat[str[start]] == 0)
			{

				if (hash_str[str[start]] > hash_pat[str[start]])
					hash_str[str[start]]--;
				start++;
			}

			// update window size
			len_window = j - start + 1;
			if (min_len > len_window)
			{
				min_len = len_window;
				start_index = start;
			}
		}
	}

	printf("min====%d\nstart=%d\n",min_len,start_index);
	// If no window found
	if (start_index == -1)
	{
	printf("No such window exists");
	return "";
	}

	// Return substring starting from start_index
	// and length min_len

strcpy(sub,substring(str,start_index, min_len));
printf("\n%s\n",sub);
	return sub;
}


int main()
{
	char str1[40],str2[20];
	printf("enter string");
	gets(str1);
	printf("enter substring");
	scanf("%s",str2);
	printf("Smallest window is : %s", smallestwindow(str1,str2));
	return 0;
}