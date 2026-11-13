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
#include "clsInputValidate.h"
#include "clsUtil.h"

#include "clsScreen.h"

#include "clsQuizz.h"
//#include "clsDataProcessing.h"
#include "clsShowQuestionsScreen.h"
#include "clsShowGameOverScreen.h"
using namespace std;


class clsShowGameStartScreen:protected clsScreen
{

private:

	static int _ReadHowManyQuestions()
	{
		cout << "\nHow Many Questions do you want to answer ? => ";
		int NumberOfQuestions= clsInputValidate::ReadIntNumberBetween(1, 100);
		return NumberOfQuestions;
	}
	static clsQuizz::enQuestionsLevel _ReadQuestionsLevel()
	{
		cout << "\n\nEnter Questions level [1] Easy, [2] Med, [3] Hard, [4] Mix ? => ";
		short QuestionLevel = clsInputValidate::ReadShortNumberBetween(1, 4);
		return (clsQuizz::enQuestionsLevel)QuestionLevel;
	}
	static clsQuizz::enOperationType _ReadOpType()
	{
		cout << "\n\nEnter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? => ";
		short OpType = clsInputValidate::ReadShortNumberBetween(1, 5);
		return (clsQuizz::enOperationType)OpType;
	}
	static clsQuizz _ReadDataOfQuizzFromPlayer()
	{
		clsQuizz Quizz;
		
		Quizz.NumberOfQuestions = _ReadHowManyQuestions();
		Quizz.QuestionsLevel = _ReadQuestionsLevel();
		Quizz.OpType = _ReadOpType();
		return Quizz;
	}
	
public:

	static void ShowGameStartScreen()
	{
		_DrawScreenHeader("\t  Welcome To Math Game Quize");
		clsQuizz Quizz = _ReadDataOfQuizzFromPlayer();
		clsShowQuestionsScreen::ShowQuestionsScreen(Quizz);
		clsShowGameOverScreen::ShowQuizzResultsScreen(Quizz);
	}

};

