#ifndef UNICODE
#define UNICODE
#endif // Makes code into UNICODE 

#include <Windows.h> // windows header file to access windows tools

//Forward Dec
//Function that defines the behavior of the window - its appearance, how it interacs with the user and so forth
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Every window application requires an "int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)"
//just like regular c++ programs require an "int main()" to run.
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, PWSTR pCmdLine, int nCmdShow)
{
	//Register the window class.
	const wchar_t CLASS_NAME[] = L"Sample window class";

	WNDCLASS wc = {}; //establishes window class with empty properties

	//we will fill in the properties
	wc.lpfnWndProc	= WindowProc;	// elememt defines behavior of window
	wc.hInstance	= hInstance;	// element hInstance
	wc.lpszClassName = CLASS_NAME;	// element class name

	//now we register class with windows
	RegisterClass(&wc);

	//after registeration with windows operating system
	//we can create the window
	HWND hwnd = CreateWindowEx( //named here hwnd but i think i can name it whatever i chose
		0,								//optional window styles
		CLASS_NAME,						//Window class
		L"Learn to Program Windows",	//Window text
		WS_OVERLAPPEDWINDOW,			//Window style

		//size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,							//Parent Window
		NULL,							//Menu
		hInstance,						//Instance handle
		NULL							//Additional Application data
		);

	if (hwnd == NULL) //error handling section empty 
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow); //Allows the window to be viewd

	//Run the message loop. Communicates with windows operating system
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

//WindowProc() function gets called here
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)	//we pass on our window class
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps); 

		//All painting occurs here, between BeginPaint and EndPaint

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
	return 0;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}