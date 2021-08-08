#include "DB.h"
#include <sstream>
#include <iterator>

using namespace std;

DB::DB()
{
}

DB::DB(string filename)
{
	std::ifstream in(filename);
	string line;

	if (in.is_open())
	{

		string delimiter = " ";
		string substr;
		while(std::getline(in,line))
		{
			std::istringstream iss(line);
			std::vector<string> parsedString(std::istream_iterator<std::string>{iss}
											,std::istream_iterator<std::string>());
			string login = parsedString.at(0);
			string password = parsedString.at(1);
			string question = parsedString.at(2);
			string answer = parsedString.at(3);
			auto* h = new Hash();
			h->setLogin(login);
			h->setPassword(password);
			h->setQuestion(question);
			h->setAnswer(answer);
			this->objects.push_back(*h);
			delete h;
		}
		cout << "The DataBase has been loaded from successfully\n";
		in.close();
	}
	else
		cout << "Unable to open file\n";
}

void DB::reg()
{
	string login, password, q, a;
	int check_log = 3;
	int check_pass = 5;
	cout << "Enter login. Login must consist A-Z, a-z, 0-9, _" << endl;
    while(1)
    {
        cin >> login;
        for(int i = 0; i < login.length(); i++)
        {
            if(login[i] == '!' || login[i] == '@' || login[i] == '#' || login[i] == '$'
            || login[i] == '%' || login[i] == '^' || login[i] == '&' || login[i] == '*'
            || login[i] == '(' || login[i] == ')' || login[i] == '-' || login[i] == '{'
            || login[i] == '}' || login[i] == '[' || login[i] == ']' || login[i] == ':'
            || login[i] == ';' || login[i] == '"' || login[i] == '\'' || login[i] == '<'
            || login[i] == '>' || login[i] == '.' || login[i] == '/' || login[i] == '?'
            || login[i] == '~' || login[i] == '`' || login[i] == '+' || login[i] == '-')
            {
                check_log = 0;
                break;
            }
            else
            {
                check_log = 1;
            }
        }
        if(check_log == 0)
        {
            cout << "Please, retry your input" << endl;
            continue;
        }
        else
        {
            break;
        }
}
    cout << "Enter password. Password must consist A-Z, a-z, 0-9, _, @" << endl;
        while(1)
    {
        cin >> password;
        for(int i = 0; i < password.length(); i++)
        {
            if(password[i] == '!' || password[i] == '#' || password[i] == '$'
            || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*'
            || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '{'
            || password[i] == '}' || password[i] == '[' || password[i] == ']' || password[i] == ':'
            || password[i] == ';' || password[i] == '"' || password[i] == '\'' || password[i] == '<'
            || password[i] == '>' || password[i] == '.' || password[i] == '/' || password[i] == '?'
            || password[i] == '~' || password[i] == '`' || password[i] == '+' || password[i] == '-')
            {
                check_pass = 0;
                break;
            }
            else
            {
                check_pass = 1;
            }
        }
        if(check_pass == 0 || password.length() > 20 || password.length() < 5)
        {
            cout << "Please, retry your input" << endl;
            continue;
        }
        else
        {
            break;
        }
    }

	cout << "Enter control question: ";
	cin >> q;
	cout << "Enter control answer: ";
	cin >> a;
	bool found = false;
	for (auto& object : this->objects)
	{
		if (object.getLogin() == login)
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		cout << "Registration is uncompleted: user already exists.\n";
		return;
	}
	auto* c = new ControlQuestion(q,a);
	auto* h = new Hash(login, password, *c);
	push(*h);
	delete c;
	delete h;
}

void DB::enter()
{
	string login, password;
	cout << "Enter login and password (space is a delimiter): ";
	cin >> login >> password;
	bool found = false;
	for (auto& object: this->objects)
	{
		if (object.getLogin() == login)
		{
			found = true;
			object.enter(login, password);
		}
	}
	if (!found)
		cout << "The user can't to be found\n";
}

void DB::push(const Hash &hash)
{
	this->objects.push_back(hash);
}

void DB::recover()
{
	string login, password, q, a;
	int check_pass = 5;
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter a new password: ";
	        while(1)
    {
        cin >> password;
        for(int i = 0; i < password.length(); i++)
        {
            if(password[i] == '!' || password[i] == '#' || password[i] == '$'
            || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*'
            || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '{'
            || password[i] == '}' || password[i] == '[' || password[i] == ']' || password[i] == ':'
            || password[i] == ';' || password[i] == '"' || password[i] == '\'' || password[i] == '<'
            || password[i] == '>' || password[i] == '.' || password[i] == '/' || password[i] == '?'
            || password[i] == '~' || password[i] == '`' || password[i] == '+' || password[i] == '-')
            {
                check_pass = 0;
                break;
            }
            else
            {
                check_pass = 1;
            }
        }
        if(check_pass == 0 || password.length() > 20 || password.length() < 5)
        {
            cout << "Please, retry your input" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
	cout << "Enter control question: ";
	cin >> q;
	cout << "Enter control answer: ";
	cin >> a;
	auto* c = new ControlQuestion(q,a);
	for (auto& object: this->objects)
	{
		if (object.getLogin() == login)
			object.recover(password, *c);
	}
	delete c;
}

void DB::show_DB()
{
	for (int i = 0; i < this->objects.size(); i++)
	{
		cout << i << " object\n";
		this->objects.at(i).show();
	}
}

void DB::save_file(string filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		for (auto& object: this->objects)
		{
			file << object.getLogin() << " " << object.getPassword() << " "
				<< object.getCQ().getQuestion() << " " << object.getCQ().getAnswer();
			file << std::endl;
		}
		cout << "DB has been saved successfully\n";
		file.close();
	}
	else
		std::cout << "Unable to open file\n";

}
