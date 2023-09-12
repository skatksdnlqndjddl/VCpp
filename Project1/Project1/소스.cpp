#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>

int main()
{
	printf("이은석의 VC++");

	char code;
	char exit;

	while (1) {
		printf("command>");
		while (1)
		{
			code = _getche();
			if (code == 27) {
				return(0);
			}
			if (code == 13) {
				break;
			}
		}
		printf("\n");

		switch (code) {
		case 'q':
			printf("q : qwer 화이팅\n");
			break;
		case 'w':
			printf("q : qwer 화이팅\n");
			break;
		case 'e':
			printf("q : qwer 화이팅\n");
			break;
		case 'r':
			printf("q : qwer 화이팅\n");
			break;
		default:
			printf("에러\n");
			break;

		}
	}
	return 0;
}
	