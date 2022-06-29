#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

string fileName = "main";
bool endString = true;

int main()
{
    system("cls");
    string word;
    char symbol;
    ofstream compiled("compiled.cpp");
    ifstream code(fileName + ".sakura");
    if (code.is_open())
    {
        compiled << "#include \"sakuraSkript.hpp\"" << endl;
        compiled << "" << endl;
        compiled << "using namespace std;" << endl;
        compiled << "" << endl;
        compiled << "int main()" << endl;
        compiled << "{" << endl;
        while(code.get(symbol))
        {
            if (symbol != '\n')
            {
                word += symbol;
            }
            else
            {
                compiled << symbol;
            }
            if (word == "printnl : ")
            {
                compiled << "    cout << ";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << " << endl;";
                        compiled << "" << endl;
                        endString = false;
                    }
                    else
                    {
                        compiled << symbol;
                    }
                }
                endString = true;
            }
            if (word == "print : ")
            {
                compiled << "    cout << ";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << ";";
                        compiled << "" << endl;
                        endString = false;
                    }
                    else
                    {
                        compiled << symbol;
                    }
                }
                endString = true;
            }
            if (word == "int : ")
            {
                compiled << "    int ";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << ";";
                        compiled << "" << endl;
                        endString = false;
                    }
                    else
                    {
                        compiled << symbol;
                    }
                }
                endString = true;
            }
            if (word == "string : ")
            {
                compiled << "    string ";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << ";";
                        compiled << "" << endl;
                        endString = false;
                    }
                    else
                    {
                        compiled << symbol;
                    }
                }
                endString = true;
            }
            if (word == "float : ")
            {
                compiled << "    float ";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << ";";
                        compiled << "" << endl;
                        endString = false;
                    }
                    else
                    {
                        compiled << symbol;
                    }
                }
                endString = true;
            }
            if (word == "char : ")
            {
                compiled << "    char ";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << ";";
                        compiled << "" << endl;
                        endString = false;
                    }
                    else
                    {
                        compiled << symbol;
                    }
                }
                endString = true;
            }
            if (word == "double : ")
            {
                compiled << "    double ";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << ";";
                        compiled << "" << endl;
                        endString = false;
                    }
                    else
                    {
                        compiled << symbol;
                    }
                }
                endString = true;
            }
            if (word == "system : ")
            {
                compiled << "    system(";
                word = "";
                while(code.get(symbol) && endString)
                {
                    if (symbol == ';')
                    {
                        word = "";
                        compiled << ");" << endl;
                        endString = false;
                    }
                    else
                    {
                        word += symbol;
                        if (word == "clear")
                        {
                            compiled << "\"cls\"";
                        }
                    }
                }
                endString = true;
            }
        }
        compiled << "\n    return 0;" << endl;
        compiled << "}" << endl;
    }
    else
    {
        cout << "File " + fileName + ".sakura not found\n\n";
    }
    system("g++ -o compiled compiled.cpp");
    system("compiled.exe");
}