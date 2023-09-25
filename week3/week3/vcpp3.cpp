#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <chrono>
#define ESC 27
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
using namespace std;

int main() {
    chrono::system_clock::time_point Start = chrono::system_clock::now(); // 시간 측정 START에 저장


    while (1) {

        int a, b = 0;

        int adogen = 0;
        int ppangppang = 0;
        int ttangttang = 0;
        int chacha = 0;
        int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;

        while ((a = _getch()) != ESC) {
            if (a != 224) {
                b = a;
                printf("%c", b);

                switch (b) {
                case UP:
                    printf("↑");
                    break;
                case DOWN:
                    printf("↓");
                    break;
                case RIGHT:
                    printf("→");
                    break;
                case LEFT:
                    printf("←");
                    break;
                }

                if ((adogen == 1 && b != RIGHT) || (adogen == 2 && b != 'a')) // 조건이 충족되지 않으면 초기화 (아도겐)
                {
                    cnt = 0;
                    adogen = 0;
                }
                if ((ppangppang == 1 && b != DOWN) || (ppangppang == 2 && b != UP) || (ppangppang == 3 && b != 's')) // 조건이 충족되지 않으면 초기화 (팡팡)
                {
                    cnt1 = 0;
                    ppangppang = 0;
                }
                if ((ttangttang == 1 && b != UP) || (ttangttang == 2 && b != RIGHT) || (ttangttang == 3 && b != 'd')) // 조건이 충족되지 않으면 초기화 (탕탕)
                {
                    cnt2 = 0;
                    ttangttang = 0;
                }
                if ((chacha == 1 && b != UP) || (chacha == 2 && b != RIGHT) || (chacha == 3 && b != DOWN) || (chacha == 4 && b != 'f')) // 조건이 충족되지 않으면 초기화 (차차)
                {
                    cnt3 = 0;
                    chacha = 0;
                }

            }
            else { // 방향키일 시 입력값 받음
                b = _getch();

                switch (b) {
                case UP:
                    printf("↑");
                    break;
                case DOWN:
                    printf("↓");
                    break;
                case RIGHT:
                    printf("→");
                    break;
                case LEFT:
                    printf("←");
                    break;
                }

                if ((adogen == 1 && b != RIGHT) || (adogen == 2 && b != 'a')) // 조건이 충족되지 않으면 초기화 (아도겐)
                {
                    cnt = 0;
                    adogen = 0;
                }
                if ((ppangppang == 1 && b != DOWN) || (ppangppang == 2 && b != UP) || (ppangppang == 3 && b != 's')) // 조건이 충족되지 않으면 초기화 (팡팡)
                {
                    cnt1 = 0;
                    ppangppang = 0;
                }
                if ((ttangttang == 1 && b != UP) || (ttangttang == 2 && b != RIGHT) || (ttangttang == 3 && b != 'd')) // 조건이 충족되지 않으면 초기화 (탕탕)
                {
                    cnt2 = 0;
                    ttangttang = 0;
                }
                if ((chacha == 1 && b != UP) || (chacha == 2 && b != RIGHT) || (chacha == 3 && b != DOWN) || (chacha == 4 && b != 'f')) // 조건이 충족되지 않으면 초기화 (차차)
                {
                    cnt3 = 0;
                    chacha = 0;
                }

                if ((b == DOWN)) {
                    adogen++;
                    cnt++;
                    Start = chrono::system_clock::now(); // 시간 시작
                }
                if ((b == RIGHT) && (cnt == 1)) {
                    adogen++;
                    cnt++;
                }

                if ((b == RIGHT)) {
                    ppangppang++;
                    cnt1++;
                    Start = chrono::system_clock::now(); // 시간 시작
                }
                if ((b == DOWN) && (cnt1 == 1)) {
                    ppangppang++;
                    cnt1++;
                }
                if ((b == UP) && (cnt1 == 2)) {
                    ppangppang++;
                    cnt1++;
                }

                if ((b == RIGHT)) {
                    ttangttang++;
                    cnt2++;
                    Start = chrono::system_clock::now();
                }
                if ((b == UP) && (cnt2 == 1)) {
                    ttangttang++;
                    cnt2++;
                }
                if ((b == RIGHT) && (cnt2 == 2)) {
                    ttangttang++;
                    cnt2++;
                }
                if ((b == LEFT)) {
                    chacha++;
                    cnt3++;
                    Start = chrono::system_clock::now();
                }
                if ((b == UP) && (cnt3 == 1)) {
                    chacha++;
                    cnt3++;
                }
                if ((b == RIGHT) && (cnt3 == 2)) {
                    chacha++;
                    cnt3++;
                }
                if ((b == DOWN) && (cnt3 == 3)) {
                    chacha++;
                    cnt3++;
                }

            }
            if ((b == 'a') && (cnt == 2) && (adogen == 2)) {    // 아도겐의 4번째 카운트가 a일때 탈출

                break;
            }
            if ((b == 's') && (cnt1 == 3) && (ppangppang == 3)) { // 팡팡의 4번째 카운트가 s일때 탈출
                break;
            }
            if ((b == 'd') && (cnt2 == 3) && (ttangttang == 3)) { // 탕탕의 4번째 카운트가 d일때 탈출
                break;
            }
            if ((b == 'f') && (cnt3 == 4) && (chacha == 4)) { //  차차의 5번째 카운트가 f일때 탈출
                break;
            }
        }
        chrono::system_clock::time_point EndTime = chrono::system_clock::now(); // 시간 종료
        chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(EndTime - Start); // 시간 저장
        if ((b == 'a') && (cnt == 2) && (adogen == 2) && (mill.count() <= 500)) { // 아도겐의 3번째가 a이며 0.5초안에 입력됐을때
            printf("\n아도겐! =o \n");
            cnt = 0;
            adogen = 0;
        }
        else if ((b == 's') && (cnt1 == 3) && (ppangppang == 3) && (mill.count() <= 500)) { // 명치 빵의 4번째가 s이며 0.5초안에 입력됐을때
            printf("\n명치 빵\n");
            cnt1 = 0;
            ppangppang = 0;
        }
        else if ((b == 'd') && (cnt2 == 3) && (ttangttang == 3) && (mill.count() <= 500)) { // 명치 빵의 4번째가 s이며 0.5초안에 입력됐을때
            printf("\n무릎 땅\n");
            cnt2 = 0;
            ttangttang = 0;
        }
        else if ((b == 'f') && (cnt3 == 4) && (chacha == 4) && (mill.count() <= 500)) { // 으라차차의 5번째가 f이며 0.5초안에 입력됐을때
            printf("\n++~@@@~++\n");
            printf("\n으라차차\n");
            printf("\n++~@@@~++\n");
            cnt3 = 0;
            chacha = 0;
        }

        if (a == ESC) break;
    }

    return 0;
}