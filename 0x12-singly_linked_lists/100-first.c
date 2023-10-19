#include <stdio.h>

/**
 * pre_main - Function executed before main.
 *
 * Description: This function is executed before the main function.
 * It prints a message.
 */
void __attribute__ ((constructor)) pre_main()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}

int main(void)
{
	/* Your main function code here */

	return (0);
}

