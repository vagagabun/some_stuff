#ifndef SOME_STRING_H_INCLUDED
#define SOME_STRING_H_INCLUDED
#include <iostream>
#include <math.h>

class String
{
    protected:
        char content[100];
        int len;
    public:
        String(void);
        String(char x);
        String(char *x);
        void show(void);
        void add_symbol_at_the_beggining(char symbol);
        void add_symbol_at_the_end(char symbol);
        void delete_symbol_at_the_beggining(void);
        void delete_symbol_at_the_end(void);
        void Concatenation(char *x);
        void UpperRegister(void);
        void DownRegister(void);
};
class Bin_String : public String
{
public:
    Bin_String(char *y);
    Bin_String(void);
    Bin_String(char x);
    void Bin_Sum(Bin_String str);
    void Bin_Multiplication(Bin_String str);
    void Bin_Reverse();
    void Bin_to_Dec();
    void Shift_Right(void);
	void Shift_Left(void);

};

class ID : public String
{
public:
    ID(void);
    ID(char x);
    ID(char *x);
};

#endif // SOME_STRING_H_INCLUDED
