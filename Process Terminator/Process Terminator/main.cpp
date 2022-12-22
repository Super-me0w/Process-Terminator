#include "global.h"

int main()
{
	CString ProcessName = GetTargetName("Target.ini");

	while (KeyExit())
	{
		TerminateProcessByName(ProcessName);
	}

	return 0;
}