#include <Windows.h>
#include <cmath>
HRGN Drawcube(HWND hWnd, HDC hdc, POINT startPoint, POINT endPoint) {
	// �߾Ӽ� ���߿� �����
	/*
	MoveToEx(hdc, 376, 0, NULL);
	LineTo(hdc, 376, 480);
	MoveToEx(hdc, 0, 188, NULL);
	LineTo(hdc, 800, 188);
	*/

	int width = abs(startPoint.x - endPoint.x);
	int height = abs(startPoint.y - endPoint.y);
	int centerX = width / 2;
	int centerY = height / 2;

	POINT MINPOINT = { 0 };
	POINT MAXPOINT = { 0 };

	MINPOINT.x = min(startPoint.x, endPoint.x);
	MINPOINT.y = min(startPoint.y, endPoint.y);
	MAXPOINT.x = max(startPoint.x, endPoint.x);
	MAXPOINT.y = max(startPoint.y, endPoint.y);

	POINT centerPoint = { MINPOINT.x + centerX, MINPOINT.y + centerY };

	if (MINPOINT.x <= 376 && MINPOINT.y < 188) {//�»�
		MoveToEx(hdc, MINPOINT.x, MAXPOINT.y, NULL); //�ظ� �ݽð��
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y);

		MoveToEx(hdc, MAXPOINT.x, MAXPOINT.y - centerY / 2, NULL); // �ո� �ݽð��
		LineTo(hdc, MAXPOINT.x, MINPOINT.y);
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y);
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y - centerY / 2);

		MoveToEx(hdc, MINPOINT.x + centerX / 2, MINPOINT.y, NULL); // ���� ���Ͻ��� �ݽð�
		LineTo(hdc, MINPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x, MAXPOINT.y}, // 1�� ������
		   {MAXPOINT.x - centerX / 2, MAXPOINT.y}, // 2�� ������
		   {MAXPOINT.x, MAXPOINT.y - centerY / 2}, // 3�� ������
		   {MAXPOINT.x, MINPOINT.y}, // 4�� ������
		   {MINPOINT.x + centerX / 2, MINPOINT.y}, // 5�� ������
		   {MINPOINT.x, MINPOINT.y + centerY / 2}  // 6�� ������
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}
	if (MINPOINT.x <= 376 && MINPOINT.y >= 188) {//����
		MoveToEx(hdc, MINPOINT.x, MINPOINT.y, NULL); //�ظ�
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y);
		LineTo(hdc, MINPOINT.x, MINPOINT.y);//����

		MoveToEx(hdc, MINPOINT.x + centerX / 2, MINPOINT.y + centerY / 2, NULL); // �ո�
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y + centerY / 2);//�ϳ��� �̹� ������ �׷��� ����

		MoveToEx(hdc, MINPOINT.x, MINPOINT.y, NULL); // ����
		LineTo(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x, MINPOINT.y}, // 1�� ������
		   {MINPOINT.x, MAXPOINT.y - centerY / 2}, // 2�� ������
		   {MINPOINT.x + centerX / 2, MAXPOINT.y}, // 3�� ������
		   {MAXPOINT.x, MAXPOINT.y}, // 4�� ������
		   {MAXPOINT.x, MINPOINT.y + centerY / 2}, // 5�� ������
		   {MAXPOINT.x - centerX / 2, MINPOINT.y}  // 6�� ������
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}
	if (MINPOINT.x > 376 && MINPOINT.y < 188) {//���
		MoveToEx(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2, NULL); //�ظ� �ݽð��
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2);

		MoveToEx(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y - centerY / 2, NULL); // �ո� �ݽð��
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y);
		LineTo(hdc, MINPOINT.x, MINPOINT.y);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2);

		MoveToEx(hdc, MAXPOINT.x, MAXPOINT.y, NULL); // ���� ���Ͻ��� �ݽð�
		LineTo(hdc, MAXPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x, MINPOINT.y}, // 1�� ������
		   {MINPOINT.x, MAXPOINT.y - centerY / 2}, // 2�� ������
		   {MINPOINT.x + centerX / 2, MAXPOINT.y}, // 3�� ������
		   {MAXPOINT.x, MAXPOINT.y}, // 4�� ������
		   {MAXPOINT.x, MINPOINT.y + centerY / 2}, // 5�� ������
		   {MAXPOINT.x - centerX / 2, MINPOINT.y}  // 6�� ������
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}
	if (MINPOINT.x > 376 && MINPOINT.y >= 188) {//����
		MoveToEx(hdc, MINPOINT.x + centerX / 2, MINPOINT.y, NULL); //�ظ�
		LineTo(hdc, MINPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x, MINPOINT.y);
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y);

		MoveToEx(hdc, MINPOINT.x, MINPOINT.y + centerY / 2, NULL); // �ո�
		LineTo(hdc, MINPOINT.x, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y + centerY / 2);//�ϳ��� �̹� ������ �׷��� ����

		MoveToEx(hdc, MAXPOINT.x, MINPOINT.y, NULL); // ����
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x + centerX / 2, MINPOINT.y}, // 1�� ������
		   {MINPOINT.x, MINPOINT.y + centerY / 2}, // 2�� ������
		   {MINPOINT.x, MAXPOINT.y}, // 3�� ������
		   {MAXPOINT.x - centerX / 2, MAXPOINT.y}, // 4�� ������
		   {MAXPOINT.x, MAXPOINT.y - centerY / 2}, // 5�� ������
		   {MAXPOINT.x, MINPOINT.y}  // 6�� ������
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}
}

void Movecube(POINT* MINPOINT, POINT* MAXPOINT, int deltaX, int deltaY) {
	MINPOINT->x += deltaX; // MINPOINT�� X ��ǥ �̵�
	MINPOINT->y += deltaY; // MINPOINT�� Y ��ǥ �̵�
	MAXPOINT->x += deltaX; // MAXPOINT�� X ��ǥ �̵�
	MAXPOINT->y += deltaY; // MAXPOINT�� Y ��ǥ �̵�
}

void ScaleCube(LPARAM lParam, POINT* minPoint, POINT* maxPoint, POINT standard) {
	int mouseX = LOWORD(lParam);
	int mouseY = HIWORD(lParam);

	// ���� ��ġ���� ���� ���콺 ��ġ���� �̵��� �Ÿ� ���
	int deltaX = mouseX - standard.x;

	double scaleFactor = 1.0;
	if (deltaX > 0) {
		scaleFactor = 1.0 + static_cast<double>(deltaX) / 100.0;
	}
	else if (deltaX < 0) {
		scaleFactor = 1.0 / (1.0 - static_cast<double>(deltaX) / 100.0);
	}

	// �߽����� double Ÿ������ ���
	double centerX = minPoint->x + (maxPoint->x - minPoint->x) / 2.0;
	double centerY = minPoint->y + (maxPoint->y - minPoint->y) / 2.0;

	// ���ο� �ʺ�� ���̸� double Ÿ������ ���
	double newWidth = (maxPoint->x - minPoint->x) * scaleFactor;
	double newHeight = (maxPoint->y - minPoint->y) * scaleFactor;

	// ���ο� ��ġ�� ����Ͽ� minPoint�� maxPoint�� ������Ʈ
	// ����� ���� �ݿø� �Լ��� ���� ��ǥ�� ���
	minPoint->x = static_cast<int>(std::round(centerX - newWidth / 2.0));
	minPoint->y = static_cast<int>(std::round(centerY - newHeight / 2.0));
	maxPoint->x = static_cast<int>(std::round(minPoint->x + newWidth));
	maxPoint->y = static_cast<int>(std::round(minPoint->y + newHeight));
}