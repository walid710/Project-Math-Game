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

#include "clsQuizz.h"
#include "clsQuestion.h"
using namespace std;


class clsDataProcessing 
{

private :

	static double _SimpleCalculator(int Number1, int Number2, clsQuestion::enOperationType OperationType)
	{
		switch (OperationType)
		{
		case clsQuizz::enOperationType::Add:
			return (Number1 + Number2);
		case clsQuizz::enOperationType::Sub:
			return (Number1 - Number2);
		case clsQuizz::enOperationType::Mul:
			return (Number1 * Number2);
		case clsQuizz::enOperationType::Dive:
			return (double)Number1 / Number2;
		default:
			return (Number1 + Number2);
		}
	}
	static clsQuizz::enOperationType _GetRandomOperationType()
	{
		int Op = clsUtil::RandomNumber(1, 4);
		return (clsQuizz::enOperationType)Op;
	}
	static clsQuestion _GenerateQuestion(clsQuizz::enQuestionsLevel QuestionLevel, clsQuizz::enOperationType OpType)
	{
		clsQuestion Quistion;
		if (QuestionLevel == clsQuizz::enQuestionsLevel::Mix)
		{
			QuestionLevel = (clsQuizz::enQuestionsLevel)clsUtil::RandomNumber(1, 3);
		}
		if (OpType == clsQuizz::enOperationType::MixOp)
		{
			OpType = _GetRandomOperationType();
		}
		Quistion.OperationType = (clsQuestion::enOperationType)OpType;
		switch (QuestionLevel)
		{

		case clsQuizz::enQuestionsLevel::Easy:
			Quistion.Number1 = clsUtil::RandomNumber(1, 10);
			Quistion.Number2 = clsUtil::RandomNumber(1, 10);
			Quistion.CorrectAnswer = _SimpleCalculator(Quistion.Number1, Quistion.Number2, Quistion.OperationType);
			Quistion.QuestionsLevel = (clsQuestion::enQuestionsLevel)QuestionLevel;
			return Quistion;
		case clsQuizz::enQuestionsLevel::Med:
			Quistion.Number1 = clsUtil::RandomNumber(10, 50);
			Quistion.Number2 = clsUtil::RandomNumber(10, 50);
			Quistion.CorrectAnswer = _SimpleCalculator(Quistion.Number1, Quistion.Number2, Quistion.OperationType);
			Quistion.QuestionsLevel = (clsQuestion::enQuestionsLevel)QuestionLevel;
			return Quistion;
		case clsQuizz::enQuestionsLevel::Hard:
			Quistion.Number1 = clsUtil::RandomNumber(50, 100);
			Quistion.Number2 = clsUtil::RandomNumber(50, 100);
			Quistion.CorrectAnswer = _SimpleCalculator(Quistion.Number1, Quistion.Number2, Quistion.OperationType);
			Quistion.QuestionsLevel = (clsQuestion::enQuestionsLevel)QuestionLevel;
			return Quistion;
		}
	}


public :

	static void _GenerateQuizzQuestions(clsQuizz& Quizz)
	{
		for (short Q = 0;Q < Quizz.NumberOfQuestions;Q++)
		{
			Quizz.QuestionList[Q] = _GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
		}
	}
	
	static string  GetOpTypeSymbol(clsQuestion::enOperationType OperationType)
	{
		//string OpTypeArr[5] = { "+","-","*","/","Mix"};
		//return OpTypeArr[OperationType - 1];
		switch (OperationType)
		{
		case clsQuestion::enOperationType::Add:
			return "+";
		case clsQuestion::enOperationType::Sub:
			return "-";
		case clsQuestion::enOperationType::Mul:
			return "*";
		case clsQuestion::enOperationType::Dive:
			return "/";
		case clsQuestion::enOperationType::MixOp:
			return "Mix";
		}
	}
	static string GetFinalResultsText(bool IsPassOrNot)
	{

		if (IsPassOrNot)
			return "Pass :-)";
		else
			return "Fail :-(";
	}

	static string GetQuestionLevelText(clsQuizz::enQuestionsLevel QuestionLevel)
	{
		string QuestionLevelText[4] = { "Easy","Med","Hard","Mix" };
		return QuestionLevelText[QuestionLevel - 1];
	}

	static bool IsPassOrFail(clsQuizz& Quizz)
	{
		return (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWrongAnswer);
	}
};

