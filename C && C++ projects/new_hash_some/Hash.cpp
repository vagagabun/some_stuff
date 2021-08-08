#include "Hash.h"

#include <utility>

unsigned int Hash::hashFunction(string input)
{
    unsigned int Magic = 5674056;
	unsigned int Hash;
	for(int i = 0; i < input.length(); i++)
	{
		Hash = Hash ^ (input[i]);
		Hash = Hash << Magic;
	}
	return Hash;
}

Hash::Hash(string login, string password, ControlQuestion c)
{

	if (!login.empty() && !password.empty())
	{
		this->login = login;
		this->password = std::to_string(hashFunction(password));
		controlQuestion.setQuestion(c.getQuestion());
		controlQuestion.setAnswer(std::to_string(hashFunction(c.getAnswer())));
		cout << "Object has been successful registered\n";
	}
	else
	{
		cout << "Incorrect input data\n";
		return;
	}
}

bool Hash::enter(string login, string password)
{
	if (login != this->login && password != this->password)
	{
		cout << "Incorrect data. Please, try again\n";
		return false;
	}
	else
	{
		cout << "You have logged successful\n";
		return true;
	}
}

void Hash::recover(string password, ControlQuestion c)
{
	bool check = std::to_string(hashFunction(c.getAnswer()))==controlQuestion.getAnswer();
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

int Hash::log_check(string log)
{
        if (log.size() <6 || log.size() >20) return 0;
		if ((log[0] <= 'A' || log[0] >= 'Z') && (log[0] <= 'a' || log[0] >= 'z')) return 0;
		int i = 0;
		while (log[i] != 0)
		{
			if (!(log[i] >= 'A' && log[i] <= 'Z') && !(log[i] >= 'a' && log[i] <= 'z') && !(log[i] >= '0' && log[i] <= '9'))
			{
            if (log[i] != '.' && log[i] != '_' && log[i] != '-') return 0;
			}
			if (log[i] == ' ')return 0;
			i++;
		}
		i--;
		if (log[i] == '.') return 0;
		return 1;
}
int Hash::pass_check(string pass)
{
		if (pass.size() < 6) return 0;
		int i = 0, hr = 0, lr = 0, sim = 0, num = 0;
		while (pass[i] != 0)
		{
			if (pass[i] >= 'A' && pass[i] <= 'Z') hr = 1;
			if (pass[i] >= 'a' && pass[i] <= 'z') lr = 1;
			if (pass[i] >= '0' && pass[i] <= '9') num = 1;
			else
			{
				if (pass[i] != '!' && pass[i] != '_' && pass[i] != '?' &&
					(pass[i] <= '#' && pass[i] >= '&') && (pass[i] <= '*' && pass[i] >= '/')) sim = 0;
				else sim = 1;
			}
			if (pass[i] == ' ') return 0;
			i++;
		}
		int check = hr * lr * sim * num;
		return check;
}
