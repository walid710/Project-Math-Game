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


class clsQuestion
{
private:
	int _Number1 = 0;
	int _Number2 = 0;
	enum enOperationType;
	enOperationType _OperationType;
	enum enQuestionsLevel;
	enQuestionsLevel _QuestionsLevel;
	double _CorrectAnswer = 0;
	int _PlayerAnswer = 0;
	bool _AnswerResult = false;

public:
	enum enQuestionsLevel
	{
		Easy = 1,
		Med = 2,
		Hard = 3,
		Mix1 = 4
	};
	enum enOperationType
	{
		Add = 1,
		Sub = 2,
		Mul = 3,
		Dive = 4,
		MixOp = 5
	};
//----------------------------------------------------------------------------

	//PropertySetAndGEt
	void SetNumber1(int Number1)
	{
		_Number1 = Number1;
	}
	int GetNumber1()
	{
		return _Number1;
	}
	_declspec(property(get = GetNumber1, put = SetNumber1))int Number1;

	//PropertySetAndGEt
	void SetNumber2(int Number2)
	{
		_Number2 = Number2;
	}
	int GetNumber2()
	{
		return _Number2;
	}
	_declspec(property(get = GetNumber2, put = SetNumber2))int Number2;
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
	void SetOperationType(enOperationType OperationType)
	{
		_OperationType = OperationType;
	}
	enOperationType GetOperationType()
	{
		return _OperationType;
	}
	_declspec(property(get = GetOperationType, put = SetOperationType))enOperationType OperationType;
	//PropertySetAndGEt
	void SetCorrectAnswer(double CorrectAnswer)
	{
		_CorrectAnswer = CorrectAnswer;
	}
	double GetCorrectAnswer()
	{
		return _CorrectAnswer;
	}
	_declspec(property(get = GetCorrectAnswer, put = SetCorrectAnswer))double CorrectAnswer;
	//PropertySetAndGEt
	void SetPlayerAnswer(int PlayerAnswer)
	{
		_PlayerAnswer = PlayerAnswer;
	}
	int GetPlayerAnswer()
	{
		return _PlayerAnswer;
	}
	_declspec(property(get = GetPlayerAnswer, put = SetPlayerAnswer))int PlayerAnswer;
	//PropertySetAndGEt
	void SetAnswerResult(bool AnswerResult)
	{
		_AnswerResult = AnswerResult;
	}
	bool GetAnswerResult()
	{
		return _AnswerResult;
	}
	_declspec(property(get = GetAnswerResult, put = SetAnswerResult))bool AnswerResult;
};

