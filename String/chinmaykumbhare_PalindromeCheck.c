

/**
 * Github Username: chinmaykumbhare
 *
 * Issue Statement:
 * Write a program to check if the given string is Palindrome or not
 * Maximum number of people can work on this issue there is no limits, 
 * make sure that the each filename should also contain your username 
 * to avoid merge conflicts and overriding.
 */

#include <stdio.h>
#include <string.h>

void main (void) {

	int num = 0;

	//enter string length
	scanf(" %d", &num);

	char str[num];

	//enter the string
	scanf("%s", str);

	int flag = 0;

	//loop to check if the string is palindrome or not

	for(int loop = 0; loop < sizeof(str); loop++) {

		if(str[loop] != str[sizeof(str) - loop - 1]) {

			flag = 1;

			break;

		}

	}

	printf("%s\n", flag ? "Entered String is not a Palindrome" : "Entered String is a Palindrome");

}
