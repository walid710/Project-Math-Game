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

#include "clsQuizz.h"
#include "clsQuestion.h"

using namespace std;



class clsShowQuestionsScreen:protected clsScreen
{
private:

	static void _SetScreenColor(bool AnswerResult)
	{
		if (AnswerResult)
		{
			system("color 2F");
		}
		else
		{
			system("color 4F");
			cout << "\a";
		}
	}
	static int _ReadQuestionAnswer()
	{
		cout << "\n" << clsUtil::Tabs(5) << "  => ";
		int Answer = clsInputValidate::ReadIntNumber();
		return Answer;
	}
	static void _PrintTheQuestion(clsQuizz& Quizz,short QuestionNumber)
	{
		_DrawQuestionsScreen("Question [" + to_string(QuestionNumber+1) + "/" + to_string(Quizz.NumberOfQuestions) + "].");
		cout << "\n" << clsUtil::Tabs(5) << "  => " << Quizz.QuestionList[QuestionNumber].Number1 << endl;
		cout << "\n" << clsUtil::Tabs(5) << "  => " << clsDataProcessing::GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType) << endl;
		cout << "\n" << clsUtil::Tabs(5) << "  => " << Quizz.QuestionList[QuestionNumber].Number2 << endl;
		cout << "\n" << clsUtil::Tabs(5) << "|----------------------------|\n";
	}
	
	static void _CorrectTheQuestionAnswer(clsQuizz& Quizz, short QuestionNumber)
	{
		if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
		{
			Quizz.QuestionList[QuestionNumber].AnswerResult = false;
			Quizz.NumberOfWrongAnswer++;
			cout << "\n" << clsUtil::Tabs(5) << "Wrong Answer :-(";
			cout << "\n" << clsUtil::Tabs(5) << "The Right Answer is : [" << Quizz.QuestionList[QuestionNumber].CorrectAnswer << "]" << endl;
		}
		else
		{
			Quizz.QuestionList[QuestionNumber].AnswerResult = true;;
			Quizz.NumberOfRightAnswer++;
			cout << "\n" << clsUtil::Tabs(5) << "Right Answer : -)\n";
		}
		_SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
	}
	static void _AskAndCorrectQustionLinstAnswer(clsQuizz& Quizz)
	{
		for (short QuestionNumber = 0;QuestionNumber < Quizz.NumberOfQuestions;QuestionNumber++)
		{
			_PrintTheQuestion(Quizz, QuestionNumber);
			Quizz.QuestionList[QuestionNumber].PlayerAnswer = _ReadQuestionAnswer();
			_CorrectTheQuestionAnswer(Quizz, QuestionNumber);
		}
		Quizz.isPass = clsDataProcessing::IsPassOrFail(Quizz);
	}

	
public:

	static void ShowQuestionsScreen(clsQuizz &Quizz)
	{
		system("cls");
		_DrawScreenHeader("\t\tGet Ready To play ");
		clsDataProcessing::_GenerateQuizzQuestions(Quizz);
		_AskAndCorrectQustionLinstAnswer(Quizz);
	}


};

