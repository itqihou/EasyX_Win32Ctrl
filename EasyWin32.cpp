/////////////////////////////////////
//
//	EasyWin32.cpp
//	by huidong <mailkey@yeah.net>
//
//	����EasyXͼ�ο��Win32�ؼ�֧�ֿ�
//	EasyX�汾��2020.9.2��
//
//	����ʱ�䣺2020.12.6
//	����޸ģ�2020.12.11
//

#include "EasyWin32.h"
#include "AHGraphics.h"

// ������
WNDCLASSEX WndClassEx;

// ��������
wchar_t pszClassName[] = L"EasyX_Win32_Class";

HWND hWnd;      // ���ھ��
MSG Msg;        // ��Ϣ�ṹ��

// �û�����Ϣ��Ӧ����
bool(*funcWndProc)(HWND, UINT, WPARAM, LPARAM, HINSTANCE);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// ����Ԥ�ȴ����һЩ��Ϣ
	switch (msg)
	{
	case WM_CREATE:
		// ���û�ͼ����
		InitDrawing(hwnd);
		break;

	case WM_SIZE:
		// �Զ�������ͼ����С
		MainImageFitWindow();
		break;
	}

	bool r;
	if (funcWndProc)
		r = funcWndProc(hwnd, msg, wParam, lParam,GetModuleHandle(0));

	// �������û�������Ϣ������һЩ��������
	switch (msg)
	{
	case WM_PAINT:
		// �Զ������ͼ���棬���ٴ��ػ�win32���ڣ��ؼ��ȣ�
		FlushDrawingToWnd();
		DefWindowProc(hwnd, msg, wParam, lParam);
		break;
	}

	if (!r)
		return 0;

	// ��������
	switch (msg)
	{
	case WM_CLOSE:
		EndDrawing();
		DestroyWindow(hwnd);
		PostQuitMessage(NULL);
		exit(0);
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void Redraw_win32()
{
	InvalidateRect(hWnd, NULL, false);
}

void initgraph_win32(int w, int h, int mode, bool(*WindowProcess)(HWND, UINT, WPARAM, LPARAM, HINSTANCE), LPCTSTR strWndTitle)
{
	// ����cmd
	if (mode == 0)
		ShowWindow(GetConsoleWindow(), SW_HIDE);

	// ��д�ṹ��
	WndClassEx.cbSize = sizeof(WNDCLASSEX);
	WndClassEx.style = CS_VREDRAW | CS_HREDRAW;
	WndClassEx.lpfnWndProc = WndProc;
	WndClassEx.cbClsExtra = 0;
	WndClassEx.cbWndExtra = 0;
	WndClassEx.hInstance = GetModuleHandle(0);
	WndClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClassEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClassEx.lpszMenuName = NULL;
	WndClassEx.lpszClassName = pszClassName;
	WndClassEx.hIconSm = NULL;

	// ע�ᴰ����
	RegisterClassEx(&WndClassEx);

	// ������Ϣ��Ӧ����
	funcWndProc = WindowProcess;

	// ��������
	hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, pszClassName, strWndTitle, WS_OVERLAPPEDWINDOW, 200, 200, w, h, NULL, NULL, GetModuleHandle(0), NULL);

	// ��ʾ����
	ShowWindow(hWnd, SW_SHOWNORMAL);

	// ���´���
	UpdateWindow(hWnd);

	// ѭ�������Ϣ
	while (GetMessage(&Msg, NULL, NULL, NULL))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
}

HWND GetHWnd_win32()
{
	return hWnd;
}
