#include <iostream>
#include "some_string.h"
using namespace std;

void menu(String x);
void menu(Bin_String x);
void menu(ID x);

int main()
{

    String some_string("123fkadf49g1F");
    Bin_String bin_str("_fdafafga110adgadg00gfa0gkg2k3S");
    ID some_id("231dfa%f&&&&");
    int ch;
    cout << "What will you choose?" << endl;
    cout << "1 — String" << endl << "2 — BinString" << endl << "3 — ID" << endl;
    cout << " " << endl;
    cin >> ch;
    if(ch == 1){menu(some_string);}
    if(ch == 2){menu(bin_str);}
    if(ch == 3){menu(some_id);}
    return 0;
}

void menu(String x)
{
    int ch;
    do
    {
        cout << "1 — add symbol at the beggining" << endl << "2 — add symbol at the end" << endl << "3 — delete symbol at the beggining" << endl << "4 — delete symbol at the end" << endl << "5 — concatenation" << endl << "6 — to upper register" << endl << "7 — to down register" << endl << "8 — show" << endl << "9 — exit" << endl;
        cout << " " << endl;
        cin >> ch;
        cout << " " << endl;
        if(ch == 1){cout << "Enter a symbol" << endl; char symbol; cin >> symbol; x.add_symbol_at_the_beggining(symbol);}
        if(ch == 2){cout << "Enter a symbol" << endl; char symbol; cin >> symbol; x.add_symbol_at_the_end(symbol);}
        if(ch == 3){x.delete_symbol_at_the_beggining();}
        if(ch == 4){x.delete_symbol_at_the_end();}
        if(ch == 5){cout << "Enter a string: " << endl; char array[100]; cin >> array; x.Concatenation(array);}
        if(ch == 6){x.UpperRegister();}
        if(ch == 7){x.DownRegister();}
        if(ch == 8){x.show();}
    } while(ch != 9);
}

void menu(Bin_String x)
{
    int ch;
    do
    {
        cout << "1 — OR" << endl << "2 — AND" << endl << "3 — reverse" << endl << "4 — bin to dec" << endl << "5 — Shift Right" << endl << "6 — Shift Left" << endl << "7 — Concatenation" << endl << "8 — show" << endl << "9 — exit" << endl;
        cout << " " << endl;
        cin >> ch;
        cout << " " << endl;
        if(ch == 1){cout << "Enter a binary string: " << endl; char y[100]; cin >> y; Bin_String Y(y); x.Bin_Sum(Y);}
        if(ch == 2){cout << "Enter a binary string: " << endl; char z[100]; cin >> z; Bin_String Z(z); x.Bin_Multiplication(Z);}
        if(ch == 3){x.Bin_Reverse();}
        if(ch == 4){x.Bin_to_Dec();}
        if(ch == 5){x.Shift_Right();}
        if(ch == 6){x.Shift_Left();}
        if(ch == 7){cout << "Enter a binary string: " << endl; char array[100]; cin >> array; x.Concatenation(array);}
        if(ch == 8){x.show();}
    }while(ch != 9);
}

void menu(ID x)
{
    int ch;
    do
    {
        cout << "1 — add symbol at the beggining" << endl << "2 — add symbol at the end" << endl << "3 — delete symbol at the beggining" << endl << "4 — delete symbol at the end" << endl << "5 — concatenation" << endl << "6 — show" << endl << "7 — exit" << endl;
        cout << " " << endl;
        cin >> ch;
        cout << " " << endl;
        if(ch == 1){char symbol = '1'; while(((symbol >= 32) && (symbol <= 64)) || ((symbol >= 91) && (symbol <= 94)) || (symbol == 96) || ((symbol >= 123) && (symbol <= 127))){cout << "Please, enter a letter(a-z) or _" << endl; cin >> symbol;} x.add_symbol_at_the_beggining(symbol);}
        if(ch == 2){cout << "Enter a symbol" << endl; char symbol; cin >> symbol; x.add_symbol_at_the_end(symbol);}
        if(ch == 3){x.delete_symbol_at_the_beggining();}
        if(ch == 4){x.delete_symbol_at_the_end();}
        if(ch == 5){cout << "Enter a string: " << endl; char array[100]; cin >> array; x.Concatenation(array);}
        if(ch == 6){x.show();}
    }while(ch != 7);
}
