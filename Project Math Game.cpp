#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>

#include "clsUtil.h"
#include "clsShowGameStartScreen.h"
using namespace std;


void ResetScreen()
{
    system("cls");
    system("color 0F");
}


int main()
{
    char PlayAgain = 'y';
    do
    {
        clsUtil::Srand();
        ResetScreen();
        clsShowGameStartScreen::ShowGameStartScreen();
        cout << "\n" << clsUtil::Tabs(5) << "Do you want to play again? [Y/N]=> ";
        cin >> PlayAgain;
    } while (toupper(PlayAgain) == 'Y');

	return 0;
}

