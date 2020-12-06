#include "EasyWin32.h"
#include <conio.h>

#define IDC_EDIT 100
#define IDC_BTN 101

HWND hEdit;
HWND hBtn;

wchar_t str[512] = L"Hello, EasyX.";

bool WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, HINSTANCE hInstance)
{
	switch (msg)
	{
	case WM_CREATE:

		// ����һ�������һ����ť
		hEdit = CreateWindow(L"edit", L"Edit at here.",
			WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER,
			130, 50, 200, 20,
			hwnd, (HMENU)IDC_EDIT, hInstance, NULL);

		hBtn = CreateWindow(L"button", L"Click Me!",
			WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER,
			330, 50, 100, 20,
			hwnd, (HMENU)IDC_BTN, hInstance, NULL);

		// ���������û�ͼ����
		setbkcolor(WHITE);
		setlinecolor(BLACK);
		setfillcolor(BLUE);
		settextcolor(GREEN);
		settextstyle(32, 0, L"system");

		break;

	case WM_PAINT:

		// ��㻭��ʲô
		cleardevice();
		setlinestyle(0, 5);
		line(0, 0, 300, 100);
		line(0, 0, getwidth(), getheight());
		fillrectangle(200,200,600,400);
		outtextxy(130, 150, str);

		break;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{

		// ���°�ť
		case IDC_BTN:

			// �õ�������ı���ǿ���ػ�
			GetWindowText(hEdit, str, 512);
			Redraw_win32();

			break;
		}

		break;

	default:
		// ��Ҫϵͳ���������Ϣ
		return true;
		break;
	}

	// �Ѿ��������Ϣ������ϵͳ�ٴ���
	return false;
}

int main()
{
	// ����һ��֧��win32�ؼ���ͼ�ν���
	initgraph_win32(640, 480, 0, WndProc);
	return 0;
}
