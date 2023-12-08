#include "YuhanCG.h"

void DrawRect(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    HBRUSH BBrush = CreateSolidBrush(RGB(255, 0, 0)); 
    RECT rect = { left, top, right, bottom }; // RECT 타입의 변수를 생성하고 값을 설정
    FillRect(hdc, &rect, BBrush); // 핑크색 사각형 그리기
    DeleteObject(BBrush); // 브러시 삭제
}

void DrawCircle(HWND hWnd, HDC hdc, int radius, POINT center)
{
    HBRUSH BBrush = CreateSolidBrush(RGB(255, 0, 255));
    Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
    SelectObject(hdc, BBrush);

    DeleteObject(BBrush); // 브러시 삭제
}

void DrawBonobono(HWND hwnd, HDC hdc, int blink)
{
    RECT rc;
    // 배경을 그립니다.
    if (blink)
    {
        HBRUSH qoBrush = CreateSolidBrush(RGB(0, 0, 0)); // 배경색 지정
        HBRUSH BBrush = CreateSolidBrush(RGB(255, 240, 200)); // 배경색 지정
        FillRect(hdc, &rc, BBrush);
        DeleteObject(BBrush);
        HBRUSH anjBrush = CreateSolidBrush(RGB(127, 200, 255));
        HBRUSH PBrush = CreateSolidBrush(RGB(255, 150, 255));//분홍색
        HBRUSH HBrush = CreateSolidBrush(RGB(255, 255, 255));//하얀색
        SelectObject(hdc, anjBrush); // 파랑색 브러시 선택
        Ellipse(hdc, 250, 100, 550, 400);// 얼굴
        SelectObject(hdc, PBrush); // 파랑색 브러시 선택
        Ellipse(hdc, 377, 244, 424, 322);
        SelectObject(hdc, HBrush); // 흰색 브러시 선택
        Ellipse(hdc, 353, 245, 400, 292); //왼쪽 입가
        Ellipse(hdc, 400, 245, 447, 292);
        SelectObject(hdc, qoBrush);
        Ellipse(hdc, 275, 225, 284, 242); //눈
        Ellipse(hdc, 525, 225, 534, 242);
        SelectObject(hdc, HBrush);
        Ellipse(hdc, 278, 228, 281, 236); //왼쪽 안눈
        Ellipse(hdc, 528, 227, 531, 236); //오른쪽 안 눈
        SelectObject(hdc, qoBrush);
        Ellipse(hdc, 383, 234, 417, 272); //코
        MoveToEx(hdc, 340, 285, NULL);
        LineTo(hdc, 368, 272);
        MoveToEx(hdc, 340, 255, NULL);
        LineTo(hdc, 380, 262);
        MoveToEx(hdc, 430, 275, NULL);
        LineTo(hdc, 468, 282); //오른쪽아래 수염
        MoveToEx(hdc, 470, 255, NULL);
        LineTo(hdc, 420, 272);
    }
    else
    {
        HDC hdc = GetDC(hwnd);
        RECT rect;
        GetClientRect(hwnd, &rect);
        HBRUSH qoBrush = CreateSolidBrush(RGB(0, 0, 0)); // 배경색 지정
        HBRUSH anjBrush = CreateSolidBrush(RGB(127, 200, 255));
        HBRUSH PBrush = CreateSolidBrush(RGB(255, 150, 255));//분홍색
        HBRUSH HBrush = CreateSolidBrush(RGB(255, 255, 255));//하얀색
        SelectObject(hdc, anjBrush); // 파랑색 브러시 선택
        Ellipse(hdc, 250, 100, 550, 400);// 얼굴
        SelectObject(hdc, PBrush); // 파랑색 브러시 선택
        Ellipse(hdc, 377, 244, 424, 322);
        SelectObject(hdc, HBrush); // 흰색 브러시 선택
        Ellipse(hdc, 353, 245, 400, 292); //왼쪽 입가
        Ellipse(hdc, 400, 245, 447, 292);
        MoveToEx(hdc, 275, 225, NULL);
        LineTo(hdc, 290, 245); //눈
        MoveToEx(hdc, 514, 245, NULL);
        LineTo(hdc, 529, 225);
        MoveToEx(hdc, 290, 245, NULL);
        LineTo(hdc, 275, 265); //눈
        MoveToEx(hdc, 514, 245, NULL);
        LineTo(hdc, 529, 265);
        SelectObject(hdc, qoBrush);
        Ellipse(hdc, 383, 234, 417, 272); //코
        MoveToEx(hdc, 340, 285, NULL);
        LineTo(hdc, 368, 272);
        MoveToEx(hdc, 340, 255, NULL);
        LineTo(hdc, 380, 262);
        MoveToEx(hdc, 430, 275, NULL);
        LineTo(hdc, 468, 282); //오른쪽아래 수염
        MoveToEx(hdc, 470, 255, NULL);
        LineTo(hdc, 420, 272);

        ReleaseDC(hwnd, hdc);
    }
}

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    double Rength = 0, Length = 0;

    Rength = right - left;
    Length = bottom - top;

    HBRUSH hLeftEarColor = CreateSolidBrush(RGB(255, 200, 15));  // 노란색 귀
    SelectObject(hdc, hLeftEarColor);
    Ellipse(hdc, left, top, left + Rength / 3, top + Length / 3);  // 왼쪽 귀의 높이를 높임
    DeleteObject(hLeftEarColor);

    //// 오른쪽 귀 (노란색)
    HBRUSH hRightEarColor = CreateSolidBrush(RGB(255, 200, 15));  // 노란색 귀
    SelectObject(hdc, hRightEarColor);
    Ellipse(hdc, left + Rength * 2 / 3, top, left + Rength, top + Length / 3);  // 오른쪽 귀의 높이를 높임
    DeleteObject(hRightEarColor);

    //// 얼굴 그리기 (노란색)
    HBRUSH hFaceColor = CreateSolidBrush(RGB(255, 200, 15));  // 노란색 얼굴
    SelectObject(hdc, hFaceColor);
    Ellipse(hdc, left + Rength / 18, top + Length / 13, left + Rength / 18 * 17, top + Length);
    DeleteObject(hFaceColor);

    //// 눈썹 그리기 (가운데 정렬)
    SelectObject(hdc, GetStockObject(BLACK_PEN));

    // 왼쪽 눈 가로선 그리기
    MoveToEx(hdc, left + Rength * 7 / 27, top + Length * 40 / 144, NULL);
    LineTo(hdc, left + Rength * 11 / 27, top + Length * 40 / 144);
    MoveToEx(hdc, left + Rength * 10 / 18, top + Length * 40 / 144, NULL);
    LineTo(hdc, left + Rength * 13 / 18, top + Length * 40 / 144);

    // 왼쪽 눈 세로선 그리기
    MoveToEx(hdc, left + Rength * 7 / 27, top + Length * 41 / 144, NULL);
    LineTo(hdc, left + Rength * 11 / 27, top + Length * 41 / 144);
    MoveToEx(hdc, left + Rength * 10 / 18, top + Length * 41 / 144, NULL);
    LineTo(hdc, left + Rength * 13 / 18, top + Length * 41 / 144);

    // 왼쪽 눈 밑 부분 그리기
    MoveToEx(hdc, left + Rength * 7 / 27, top + Length * 42 / 144, NULL);
    LineTo(hdc, left + Rength * 11 / 27, top + Length * 42 / 144);
    MoveToEx(hdc, left + Rength * 10 / 18, top + Length * 42 / 144, NULL);
    LineTo(hdc, left + Rength * 13 / 18, top + Length * 42 / 144);

    // 눈 그리기 (검정색)
    SelectObject(hdc, GetStockObject(BLACK_BRUSH));

    // 왼쪽 눈
    Ellipse(hdc, left + Rength * 17 / 54, top + Length * 27 / 72, left + Rength * 20 / 54, top + Length * 31 / 72);

    // 오른쪽 눈
    Ellipse(hdc, left + Rength * 32 / 54, top + Length * 27 / 72, left + Rength * 35 / 54, top + Length * 31 / 72);



    // 입 그리기 (가운데 정렬, 흰색)
    HBRUSH hMouthColor = CreateSolidBrush(RGB(255, 255, 255));  // 흰색 입
    SelectObject(hdc, hMouthColor);
    int mouthLeft = left + Rength * 8 / 20;  // 입 왼쪽 부분
    int mouthRight = left + Rength / 2;  // 입 오른쪽 부분
    int mouthTop = top + Length * 35 / 72;
    int mouthBottom = top + Length * 42 / 72;
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    mouthLeft = left + Rength / 2;  // 두 번째 원의 왼쪽 부분
    mouthRight = left + Rength * 12 / 20;  // 두 번째 원의 오른쪽 부분
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    DeleteObject(hMouthColor);
}

void DrawCube(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    double xlength = 0, ylength = 0;

    xlength = right - left;
    ylength = bottom - top;

    MoveToEx(hdc, left + xlength * 5 / 16, top, NULL); //1 가로
    LineTo(hdc, left + xlength, top);

    MoveToEx(hdc, left + xlength * 5 / 16, top, NULL);
    LineTo(hdc, left, top + ylength * 9 / 36);

    MoveToEx(hdc, left + xlength, top, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength * 9 / 36);

    MoveToEx(hdc, left, top + ylength * 9 / 36, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength * 9 / 36); //2

    MoveToEx(hdc, left, top + ylength * 9 / 36, NULL);
    LineTo(hdc, left, top + ylength);

    MoveToEx(hdc, left + xlength * 11 / 16, top + ylength * 9 / 36, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength);

    MoveToEx(hdc, left, top + ylength, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength); //3

    MoveToEx(hdc, left + xlength, top, NULL);
    LineTo(hdc, left + xlength, top + ylength * 11 / 16);

    MoveToEx(hdc, left + xlength * 11 / 16, top + ylength, NULL);
    LineTo(hdc, left + xlength, top + ylength * 11 / 16);
}