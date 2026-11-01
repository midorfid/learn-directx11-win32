#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    const wchar_t windowName[] = L"new wind";
    const wchar_t className[] = L"windowClass";

    WNDCLASS wc = {};

    wc.lpfnWndProc = DefWindowProc;
    wc.lpszClassName = className;
    wc.hInstance = hInstance;
    
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, className, windowName, WS_OVERLAPPEDWINDOW, 0, 0, 600, 800, 0, 0, hInstance, nullptr);
    if (hwnd == nullptr)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    
    MSG msg = {};
    while (GetMessage(&msg, hwnd, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}