#pragma once
#pragma comment(linker, "/entry:\"mainCRTStartup\"")

#include <Windows.h>
#include <TlHelp32.h>
#include <atlstr.h>
#include <iostream>
#include <fstream>

using namespace std;

int TerminateProcessByName(CString);
CString GetTargetName(string);
BOOL KeyExit();