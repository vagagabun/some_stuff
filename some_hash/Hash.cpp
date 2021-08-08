#include "Hash.h"

#include <utility>

unsigned int Hash::hashFunction(string input)
{
	unsigned int Magic = 5674056;
	unsigned int Hash;
	for (int i = 0; i < input.length(); i++)
	{
		Hash = Hash ^ (input[i]);
		Hash = Hash << Magic;
	}
	return Hash;
}

void Hash::setQuestion(string question)
{
	this->controlQuestion.setQuestion(question);
}

void Hash::setAnswer(string answer)
{
	this->controlQuestion.setAnswer(answer);
}

Hash::Hash()
{
	login = "";
	password = "";
}

Hash::Hash(string login, string password, ControlQuestion c)
{

	if (!login.empty() && !password.empty())
	{
		this->login = login;
		this->password = std::to_string(hashFunction(password));
		controlQuestion.setQuestion(c.getQuestion());
		controlQuestion.setAnswer(std::to_string(hashFunction(c.getAnswer())));
	}
	else
	{
		cout << "Incorrect input data\n";
		return;
	}
}

string Hash::getLogin()
{
	return this->login;
}

string Hash::getPassword()
{
	return this->password;
}

void Hash::setLogin(string login)
{
	this->login = login;
}

void Hash::setPassword(string password)
{
	this->password = password;
}

ControlQuestion Hash::getCQ()
{
	return this->controlQuestion;
}

bool Hash::enter(string login, string password)
{
	if (login == this->login && std::to_string(hashFunction(password)) == this->password)
	{
		cout << "You have logged successful\n";
		return true;
	}
	cout << "Incorrect data. Please, try again\n";
		return false;
}

void Hash::recover(string password, ControlQuestion c)
{
	bool check = std::to_string(hashFunction(c.getAnswer())) == controlQuestion.getAnswer();
	bool question = c.getQuestion() == controlQuestion.getQuestion();
	if (check == 0 || question == 0)
	{
		cout << "Wrong Control Q&A. Please, try again.\n";
	}
	else
	{
		cout << "Great! Q&A are correct.\n";
		cout << "Setting a new password...\n";
		this->password = std::to_string(hashFunction(std::move(password)));
	}
}

void Hash::show()
{
	cout << "login: " << login << " \n"
		<< "password hash: " << password << "\n"
		<< "control answer hash: " << controlQuestion.getAnswer() << "\n";
}
