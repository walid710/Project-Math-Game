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
#include "clsQuestion.h"


class clsQuizz
{

private:
	
	short _NumberOfQuestions = 0;
	enum enQuestionsLevel;
	enQuestionsLevel _QuestionsLevel;
	enum enOperationType;
	enOperationType _OpType;
	int _NumberOfRightAnswer = 0;
	int _NumberOfWrongAnswer = 0;
	bool _isPass = false;

public :

	clsQuestion QuestionList[100] ;

	enum enQuestionsLevel
	{
		Easy = 1,
		Med = 2,
		Hard = 3,
		Mix = 4
	};
	enum enOperationType
	{
		Add = 1,
		Sub = 2,
		Mul = 3,
		Dive = 4,
		MixOp = 5
	};
	//-------------------------------------------------
	
	//PropertySetAndGEt
	void SetNumberOfQuestions(int NumberOfQuestions)
	{
		_NumberOfQuestions = NumberOfQuestions;
	}
	int GetNumberOfQuestions()
	{
		return _NumberOfQuestions;
	}
	_declspec(property(get = GetNumberOfQuestions, put = SetNumberOfQuestions))int NumberOfQuestions;
	//PropertySetAndGEt
	void SetQuestionsLevel(enQuestionsLevel QuestionsLevel)
	{
		_QuestionsLevel = QuestionsLevel;
	}
	enQuestionsLevel GetQuestionsLevel()
	{
		return _QuestionsLevel;
	}
	_declspec(property(get = GetQuestionsLevel, put = SetQuestionsLevel))enQuestionsLevel QuestionsLevel;
	//PropertySetAndGEt
	void SetOpType(enOperationType OpType)
	{
		_OpType = OpType;
	}
	enOperationType GetOpType()
	{
		return _OpType;
	}
	_declspec(property(get = GetOpType, put = SetOpType))enOperationType OpType;
	//PropertySetAndGEt
	void SetNumberOfRightAnswer(int NumberOfRightAnswer)
	{
		_NumberOfRightAnswer = NumberOfRightAnswer;
	}
	int GetNumberOfRightAnswer()
	{
		return _NumberOfRightAnswer;
	}
	_declspec(property(get = GetNumberOfRightAnswer, put = SetNumberOfRightAnswer))int NumberOfRightAnswer;
	//PropertySetAndGEt
	void SetNumberOfWrongAnswer(int NumberOfWrongAnswer)
	{
		_NumberOfWrongAnswer = NumberOfWrongAnswer;
	}
	int GetNumberOfWrongAnswer()
	{
		return _NumberOfWrongAnswer;
	}
	_declspec(property(get = GetNumberOfWrongAnswer, put = SetNumberOfWrongAnswer))int NumberOfWrongAnswer;
	//PropertySetAndGEt
	void SetisPass(bool isPass)
	{
		_isPass = isPass;
	}
	bool GetisPass()
	{
		return _isPass;
	}
	_declspec(property(get = GetisPass, put = SetisPass))bool isPass;

};

