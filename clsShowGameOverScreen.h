#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>
#include "clsString.h"
#include "clsScreen.h"

#include "clsDataProcessing.h"

using namespace std;


class clsShowGameOverScreen
{
private:
	static void _SetWinnerScreenColor(clsQuizz& Quizz)
	{
		if (Quizz.isPass)
		{
			system("color 2F");
		}
		else
		{
			system("color 4F");
			cout << "\a";
		}
	}
	static void _ShowGameOverScreen(clsQuizz& Quizz)
	{
		cout << "\n\n" << clsUtil::Tabs(5) << "|--------------------------------------------------------|";
		cout << "\n\n" << clsUtil::Tabs(5) << "  Final Results is " << clsDataProcessing::GetFinalResultsText(Quizz.isPass);
		cout << "\n\n" << clsUtil::Tabs(5) << "|--------------------------------------------------------|\n";
	}
	static void _ShowFinalGameResults(clsQuizz& Quizz)
	{
		cout << "\n" << clsUtil::Tabs(5) << "|____________________[ Game Results ]___________________|";
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Number Of Questions     : " << Quizz.NumberOfQuestions;
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Questions Level         : " << clsDataProcessing::GetQuestionLevelText(Quizz.QuestionsLevel);
		cout << "\n\n" << clsUtil::Tabs(5) << "   * OpType                  : " << clsDataProcessing::GetOpTypeSymbol((clsQuestion::enOperationType)Quizz.OpType);
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Number of Right Answers : " << Quizz.NumberOfRightAnswer;
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Number of Wrong Answers : " << Quizz.NumberOfWrongAnswer;
		cout << "\n\n" << clsUtil::Tabs(5) << "|______________________________________________________|\n";
		_SetWinnerScreenColor(Quizz);
	}
public:
	static void ShowQuizzResultsScreen(clsQuizz& Quizz)
	{
		_ShowGameOverScreen(Quizz);
		_ShowFinalGameResults(Quizz);
	}

};

