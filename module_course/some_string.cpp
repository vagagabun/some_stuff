#include <iostream>
#include <math.h>
#include "some_string.h"

using namespace std;


String::String(void){content[0] = '\0'; len = 0;}
String::String(char x){content[0] = x; content[1] = '\0'; len = 1;}
String::String(char *x)
        {
         int cnt = 0;
	    	while (x[cnt] != '\0')
	      {
	     		content[cnt] = x[cnt];
	     		cnt++;
		  }
	    	content[cnt] ='\0';
	    	len = cnt;
        }
void String::show(void){cout << "ваша строка: " << content << "   длина вашей строки: " << len << endl;}
void String::add_symbol_at_the_beggining(char symbol)
        {
            for(int i=0; i<=len; i++) content[len+1-i]=content[len-i];
            content[0]=symbol;
            content[len + 1] = '\0';
            len += 1;
        }
void String::add_symbol_at_the_end(char symbol)
        {
            content[len] = symbol;
            content[++len] = '\0';
        }
void String::delete_symbol_at_the_beggining(void)
        {
            int i=0;
            while(content[i]!='\0')
            {
                content[i]=content[i+1]; i++;
            }
            content[i]='\0'; len = i;
        }
void String::delete_symbol_at_the_end(void)
        {
            content[--len] = '\0';
        }
void String::Concatenation(char *x)
        {
            int i = 0;
            int k = 0;
            while (x[i] != '\0')
            {
                i++;
            }
            for(int j = len; j < len + i; j++)
            {
                content[j] = x[k];
                k++;
            }
            len += i;
            content[len] = '\0';
        }
void String::UpperRegister(void)
        {
            int k = 0;
            while(content[k] != '\0')
            {
                if(content[k] > 96 && content[k] < 123)
                {
                    content[k] -= 32;
                }
                k++;
            }
        }
void String::DownRegister(void)
        {
            int k = 0;
            while(content[k] != '\0')
            {
                if(content[k] > 64 && content[k] < 91)
                {
                    content[k] += 32;
                }
                k++;
            }
        }
Bin_String::Bin_String(void):String(){;}
Bin_String::Bin_String(char x):String(x){if (x != '0' && x != '1') {content[0] = '\0'; len = 0;}}
Bin_String::Bin_String(char *y):String(y)
    {
        int i = 0, j = 0;
        while(content[i] != '\0')
        {
            if(content[i] == 48 || content[i] == 49)
            {
                content[j] = content[i];
                j++;

            }
            i++;
        }
        content[j] = '\0';
        len = j;

    }
void Bin_String::Bin_Sum(Bin_String str)
    {

        if(str.len > len)
        {
            while(len < str.len)
            {
                add_symbol_at_the_beggining('0');
            }
        }
        if(len > str.len)
        {
            while(str.len < len)
            {
                str.add_symbol_at_the_beggining('0');
            }
        }
        for(int i = 0; i < len; i++)
        {
            content[i] = content[i] | str.content[i];
        }
    }
void Bin_String::Bin_Multiplication(Bin_String str)
    {
        if(str.len > len)
        {
            while(len < str.len)
            {
                add_symbol_at_the_beggining('0');
            }
        }
        if(len > str.len)
        {
            while(str.len < len)
            {
                str.add_symbol_at_the_beggining('0');
            }
        }
        for(int i = 0; i < len; i++)
        {
            content[i] = content[i] & str.content[i];
        }
    }
void Bin_String::Bin_Reverse()
    {
        for(int i = 0; i < len; i++)
        {
            if(content[i] == '0'){content[i] = '1';}
            else{content[i] = '0';}
        }
    }
void Bin_String::Bin_to_Dec()
    {
        int j = 0;
        char reverse_content[100];
        for(int i = len - 1; i >= 0; i--)
        {
            reverse_content[j] = content[i];
            j++;
        }
        unsigned long long decimal_num = 0;
        for(int i = 0; i < len; i++)
        {
            if(reverse_content[i] == '1')
            {
                decimal_num += pow(2 , i);
            }
        }
        cout << "Ваша строка " << content <<  " в десятичной форме: " << decimal_num << endl;
    }
void Bin_String::Shift_Left(void) {add_symbol_at_the_end('0');}
void Bin_String::Shift_Right(void) {delete_symbol_at_the_end();}
ID::ID(void):String(){;}
ID::ID(char x):String(x) {if(!(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')) {content[0] = '\0'; len = 0;}}
ID::ID(char *x):String(x)
    {
        int i = 0, j = 0;
        while(content[i] != '\0')
        {
            if(content[i] >= 'a' && content[i] <= 'z' || content[i] >= 'A' && content[i] <= 'Z' || content[i] >= '0' && content[i] <= '9' || content[i] == '_')
            {
                content[j] = content[i];
                j++;
            }
            i++;
        }
        content[j] = '\0';
        len = j;
        i = 0;
        while(content[0] >= '0' && content[0] <= '9')
        {
            delete_symbol_at_the_beggining();
        }
    }
