/////////////////////////////////////
//
//	EasyWin32.h
//	by huidong <mailkey@yeah.net>
//
//	����EasyXͼ�ο��Win32�ؼ�֧�ֿ�
//	EasyX�汾��2020.9.2��
//
//	����ʱ�䣺2020.12.6
//	����޸ģ�2020.12.6
//

#pragma once

#include <windows.h>
#include <easyx.h>

// ����֧��win32�Ļ�ͼ����
// w,h				���ڴ�С
// mode				����ģʽ��Ϊ0��ʾ����cmd����Ϊ0��ʾ��ʾcmd��
// WindowProcess	������Ϣ��������ָ�루bool���ͣ�����true��ʾ��ϵͳ�������Ϣ������false��ʾϵͳ����Ҫ�ٴ������Ϣ��
// strWndTitle		���ڱ���
void initgraph_win32(int w = 640, int h = 480, int mode = 0, bool(*WindowProcess)(HWND, UINT, WPARAM, LPARAM, HINSTANCE) = NULL, LPCTSTR strWndTitle = L"EasyX with Win32");

// �õ����ھ��
HWND GetHWnd_win32();

// ǿ���ػ洰�ڣ�������WM_PAINT��Ϣ�ڻ�ͼ����Ҫʹ�ô˺�����
void Redraw_win32();
