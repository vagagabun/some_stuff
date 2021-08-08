#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::cin;
using std::cout;

class ControlQuestion
{
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

	unsigned int hashFunction(string input);
	string login{};
	string password{};
	ControlQuestion controlQuestion;
public:
	void setQuestion(string question);
	void setAnswer(string answer);
	Hash();
	Hash(string login, string password, ControlQuestion c); // register constructor
	string getLogin();
	string getPassword();
	void setLogin(string login);
	void setPassword(string password);
	ControlQuestion getCQ();
	bool enter(string login, string password);
	void recover(string password, ControlQuestion c);
	void show();
};

#endif // HASH_H_INCLUDED
