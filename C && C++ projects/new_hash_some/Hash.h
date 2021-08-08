#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class ControlQuestion
{
protected:
	string question;
	string answer;
public:
	ControlQuestion()
	{
		this->question = "";
		this->answer = "";
	}

	ControlQuestion(string question, string answer)
	{
		this->question = question;
		this->answer = answer;
	}

	void setQuestion(string input)
	{
		this->question = input;
	}

	void setAnswer(string input)
	{
		this->answer = input;
	}

	string getQuestion()
	{
		return this->question;
	}

	string getAnswer()
	{
		return this->answer;
	}
};

class Hash
{
protected:
	unsigned int hashFunction(string input);
	string login{};
	string password{};
	ControlQuestion controlQuestion;
public:
    Hash(void);
	Hash(string login, string password, ControlQuestion c); // register constructor
	bool enter(string login, string password);
	void recover(string password, ControlQuestion c);
	void show();
	int log_check(string log);
	int pass_check(string pass);
};
#endif // HASH_H_INCLUDED
