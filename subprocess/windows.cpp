//
// Created by Tim Shull on 10/22/16.
//


#include <windows.h>

int main(void) {
    char szPath[] = "C:\\WINDOWS\\system32\\Calc.exe";
    PROCESS_INFORMATION pif;  //Gives info on the thread and..
    //..process for the new process
    STARTUPINFO si;          //Defines how to start the program

    ZeroMemory(&si, sizeof(si)); //Zero the STARTUPINFO struct
    si.cb = sizeof(si);         //Must set size of structure

    BOOL bRet = CreateProcess(
            szPath, //Path to executable file
            NULL,   //Command string - not needed here
            NULL,   //Process handle not inherited
            NULL,   //Thread handle not inherited
            FALSE,  //No inheritance of handles
            0,      //No special flags
            NULL,   //Same environment block as this prog
            NULL,   //Current directory - no separate path
            &si,    //Pointer to STARTUPINFO
            &pif);   //Pointer to PROCESS_INFORMATION

    if (bRet == FALSE) {
        MessageBox(HWND_DESKTOP, "Unable to start program", "", MB_OK);
        return 1;
    }

    CloseHandle(pif.hProcess);   //Close handle to process
    CloseHandle(pif.hThread);    //Close handle to thread

    return 0;
}

#include <windows.h>  //You need shell32.lib for this one

int main(void) {
    char szPath[] = "C:\\WINDOWS\\system32\\Calc.exe";

    HINSTANCE hRet = ShellExecute(
            HWND_DESKTOP, //Parent window
            "open",       //Operation to perform
            szPath,       //Path to program
            NULL,         //Parameters
            NULL,         //Default directory
            SW_SHOW);     //How to open

    /*
    The function returns a HINSTANCE (not really useful in this case)
    So therefore, to test its result, we cast it to a LONG.
    Any value over 32 represents success!
    */

    if ((LONG) hRet <= 32) {
        MessageBox(HWND_DESKTOP, "Unable to start program", "", MB_OK);
        return 1;
    }

    return 0;
}
