# Process-Terminator

Usage: Create a Target.ini file under the same path, write the process name that you want to prevent from opening into the file (upper & lowercase is matter, only one name at a time), and open the program. Shift+Esc to exit the program.

Takes a snapshot of currently executing processes in the system  and then walks through the list recorded in the snapshot. For each process in turn, compare with the process name specified in the Target.ini file, and determine whether to terminate the process based on the comparison result.
