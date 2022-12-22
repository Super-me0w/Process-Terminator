#include "global.h"

int TerminateProcessByName(CString ProcessName)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 ProcessList;
	ZeroMemory(&ProcessList, sizeof(ProcessList));
	ProcessList.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hSnapShot, &ProcessList))
	{
		CloseHandle(hSnapShot);

		return 0;
	}

	while (Process32Next(hSnapShot, &ProcessList))
	{
		CString CurrentProcessName = ProcessList.szExeFile;

		if (!CurrentProcessName.Compare(ProcessName))
		{
			DWORD dwProcessID = ProcessList.th32ProcessID;
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessID);

			if (hProcess != INVALID_HANDLE_VALUE)
			{
				TerminateProcess(hProcess, (UINT)0);
			}

			CurrentProcessName.ReleaseBuffer();
			ProcessName.ReleaseBuffer();
			CloseHandle(hProcess);
			CloseHandle(hSnapShot);

			return 1;
		}

		CurrentProcessName.ReleaseBuffer();
	}

	ProcessName.ReleaseBuffer();
	CloseHandle(hSnapShot);

	return 0;
}

CString GetTargetName(string file)
{
	char name[1024] = { 0 };
	ifstream readFile(file);

	readFile >> name;
	readFile.close();

	return CString(name);
}

BOOL KeyExit()
{
	int i = 0;

	if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000f) && (GetAsyncKeyState(VK_ESCAPE) & 0x8000f))
	{
		i = MessageBoxA(NULL, "Terminate Current Process? (PT.exe)", "Process", MB_OKCANCEL | MB_ICONWARNING);
		if (i == IDOK)
		{
			MessageBoxA(NULL, "PT.exe Terminated Successfully", "Process", MB_ICONINFORMATION);

			return FALSE;
		}
	}

	return TRUE;
}