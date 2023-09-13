#include <stdio.h>
#include <conio.h>

int main()
{
    printf("이은석의 VC++\n");

    char code;
    char exit;

    while (1) {
        printf("command>");
        code = _getche();

        if (code == 27) {
            return(0);
        }

        printf("\n");

        if (code == 13) {
            continue; 
        }

        while (true) {
            char enter = _getch();
            if (enter == '\r') 
                break;
        }

        switch (code) {
        case 'q':
            printf("q : qwer 화이팅\n");
            break;
        case 'w':
            printf("w :  과제 너무 좋다\n");
            break;
        case 'e':
            printf("e : 담주부턴 과제량 3ㅂ..네?\n");
            break;
        case 'r':
            printf("r : 행복합니다\n");
            break;
        default:
            printf("에러\n");
            break;
        }
    }
    return 0;
}