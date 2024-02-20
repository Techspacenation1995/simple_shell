#include <stdio.h>
/**
 * addition - adds two integer numbers.
 *@a: first integer variable
 *@b: second integer variable
 *
 *Return: value of addition
 */
int addition(int a, int b)
{
	int sum = 0;

	sum = a + b;
	return (sum);
}
/**
 * main - execute the program
 *Return: always 0
*/
int main(void)
{
	int x, y, sum = 0;

	printf("please enter two numbers\n");
	scanf("%d %d", &x, &y);
	sum = addition(x, y);
	printf("sum is = %d\n", sum);
	return (0);
}
