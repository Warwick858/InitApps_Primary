// ******************************************************************************************************************
//  This file is part of Swagger_Example.
//
//  Swagger_Example - simple example to demonstrate swagger UI.
//  Copyright(C) 2019  James LoForti
//  Contact Info: jamesloforti@gmail.com
//
//  Swagger_Example is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.If not, see<https://www.gnu.org/licenses/>.
//									     ____.           .____             _____  _______   
//									    |    |           |    |    ____   /  |  | \   _  \  
//									    |    |   ______  |    |   /  _ \ /   |  |_/  /_\  \ 
//									/\__|    |  /_____/  |    |__(  <_> )    ^   /\  \_/   \
//									\________|           |_______ \____/\____   |  \_____  /
//									                             \/          |__|        \/ 
//
// ******************************************************************************************************************
//
#include <iostream>
#include <fstream>
#include <thread>
#include <tchar.h>
#include <windows.h>
#include "OutputConstants.h"
using namespace std;

int main()
{
	//Class Cars:
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(si);
	char* argsEmpty = new char();
	OutputConstants* oc = new OutputConstants();

	//Maximize console
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);

	//Draw matrix
	//oc->drawMatrix();
	thread th(&OutputConstants::drawMatrix, oc);

	//CHROME - LEFT
	char argsChromeLft[] = "chrome.exe /new-window chrome://bookmarks https://github.com/Warwick858?tab=repositories";
	auto pChromeLft = CreateProcess("C:/Program Files (x86)/Google/Chrome/Application/chrome.exe", argsChromeLft, 0, 0, 0, 0, 0, 0, &si, &pi);
	SwitchToThisWindow(hwnd, true);

	//EXPLORER1
	char argsExplorer1[] = "C:/Windows/explorer.exe D:";
	auto pExplorer1 = CreateProcess("C:/Windows/explorer.exe", argsExplorer1, 0, 0, 0, 0, 0, 0, &si, &pi);
	SwitchToThisWindow(hwnd, true);

	//EXPLORER2
	char argsExplorer2[] = "C:/Windows/explorer.exe D:";
	auto pExplorer2 = CreateProcess("C:/Windows/explorer.exe", argsExplorer2, 0, 0, 0, 0, 0, 0, &si, &pi);
	SwitchToThisWindow(hwnd, true);

	//NOTEPAD
	auto pNotepad = CreateProcess("C:/Program Files (x86)/Notepad++/notepad++.exe", argsEmpty, 0, 0, 0, 0, 0, 0, &si, &pi);
	SwitchToThisWindow(hwnd, true);

	//BASH SHELL
	auto pBash = CreateProcess("C:/Program Files/Git/git-bash.exe", argsEmpty, 0, 0, 0, 0, 0, 0, &si, &pi);
	SwitchToThisWindow(hwnd, true);

	//SPOTIFY
	auto pSpotify = CreateProcess("C:/Users/Jimmy/AppData/Roaming/Spotify/Spotify.exe", argsEmpty, 0, 0, 0, 0, 0, 0, &si, &pi);
	SwitchToThisWindow(hwnd, true);

	//CHROME - RIGHT
	char argsChromeRht[] = "chrome.exe /new-window chrome://bookmarks https://www.facebook.com/";
	auto pChromeRht = CreateProcess("C:/Program Files (x86)/Google/Chrome/Application/chrome.exe", argsChromeRht, 0, 0, 0, 0, 0, 0, &si, &pi);
	SwitchToThisWindow(hwnd, true);

	th.join();
	SwitchToThisWindow(hwnd, true);

	delete argsEmpty;
	delete oc;

	return 0;
}