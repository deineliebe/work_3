#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h> 
#include <cstdlib>


//Class Stack: structure when first element which input is last which get out
class Stack
{
private:
    char* _arr;
    int _size;
public:
    Stack()
    {
        _arr = new char[0];
        _size = 0;
    };
    ~Stack()
    {
        delete[] _arr;
        _size = 0;
    }
    void add_Element(char elem);
    char get_Element();
    void delete_Element();
    void show_Stack();
    int get_Size();
};

void Stack::add_Element(char elem)
{
    char* rez_array = new char[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        rez_array[i] = _arr[i];
    }
    delete[] _arr;
    rez_array[_size++] = elem;
    _arr = rez_array;
}

char Stack::get_Element()
{
    return _arr[_size - 1];
}

void Stack::delete_Element()
{
    char* rez_array = new char[_size - 1];
    for (int i = 0; i < _size - 1; i++)
    {
        rez_array[i] = _arr[i];
    }
    delete[] _arr;
    _arr = rez_array;
    _size--;
}

void Stack::show_Stack()
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << _arr[i];
    }
    std::cout << '\n';
}

int Stack::get_Size()
{
    return _size;
}


//Class Stack for double numbers
class Number_Stack
{
private:
    double* _arr;
    int _size;
public:
    Number_Stack()
    {
        _arr = new double[0];
        _size = 0;
    };
    ~Number_Stack()
    {
        delete[] _arr;
        _size = 0;
    }
    void add_Element(double elem);
    double get_Element();
    void delete_Element();
    void show_Stack();
    int get_Size();
};

void Number_Stack::add_Element(double elem)
{
    double* rez_array = new double[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        rez_array[i] = _arr[i];
    }
    delete[] _arr;
    rez_array[_size++] = elem;
    _arr = rez_array;
}

double Number_Stack::get_Element()
{
    return _arr[_size - 1];
}

void Number_Stack::delete_Element()
{
    double* rez_array = new double[_size - 1];
    for (int i = 0; i < _size - 1; i++)
    {
        rez_array[i] = _arr[i];
    }
    delete[] _arr;
    _arr = rez_array;
    _size--;
}

void Number_Stack::show_Stack()
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << _arr[i];
    }
    std::cout << '\n';
}

int Number_Stack::get_Size()
{
    return _size;
}

//Program for getting number from string
double get_Number(std::string sentence, int& i)
{
    double number = 0;
    int part;
    double dec = 1;
    bool check = 0;
    while (i < sentence.size() and ((sentence[i] >= '0' and sentence[i] <= '9') or sentence[i] == '.'))
    {
        switch (sentence[i])
        {
        case '1':
        {
            number += 1 / dec;
            break;
        }
        case '2':
        {
            number += 2 / dec;
            break;
        }
        case '3':
        {
            number += 3 / dec;
            break;
        }
        case '4':
        {
            number += 4 / dec;
            break;
        }
        case '5':
        {
            number += 5 / dec;
            break;
        }
        case '6':
        {
            number += 6 / dec;
            break;
        }
        case '7':
        {
            number += 7 / dec;
            break;
        }
        case '8':
        {
            number += 8 / dec;
            break;
        }
        case '9':
        {
            number += 9 / dec;
            break;
        }
        case '.':
        {
            check = 1;
            number /= 10;
            break;
        }
        }
        if (check) dec *= 10;
        else number *= 10;
        i++;
    }
    if (!check) number /= 10;
    return number;
}


//Class for dynamic array with additional functions needed for my program
class Dynamic_Array
{
private:
    //I know it's possible to make one array with template, but I think this realisation is OK, too
    //Of course, it has problems with memory in big value of data
    char* _symbols;
    double* _numbers;
    int _size;
public:
    //Constructor
    Dynamic_Array()
    {
        _symbols = new char[0];
        _numbers = new double[0];
        _size = 0;
    };
    //Deconstructor
    ~Dynamic_Array()
    {
        _symbols = NULL;
        _numbers = NULL;
        _size = 0;
    }
    void make_Array(std::string sentence);
    bool make_Polish_Notation();
    bool make_Reverse_Polish_Notation();
    bool check_Array();
    double count_Array();
    double count_Polish_Notation();
    double count_Polish_Notation(std::ofstream& fout);
    double count_Reverse_Polish_Notation();
    double count_Reverse_Polish_Notation(std::ofstream& fout);
    void make_Operation(int begin, int end);
    void delete_Element(int index);
    void add_Element(double number);
    void add_Element(char operand);
    void show_Array();
    void show_Array(std::ofstream& fout);
    int get_Size();
};

void Dynamic_Array::make_Array(std::string sentence)
{
    double number;
    int i = 0;
    while (i < sentence.size())
    {
        std::cout << "Element " << sentence[i] << '\n';
        if (sentence[i] == '(' or sentence[i] == '*' or sentence[i] == '/' or sentence[i] == '+' or sentence[i] == '-' or sentence[i] == ')')
        {
            std::cout << "Case 1: put it in part of symbols\n";
            add_Element(sentence[i]);
            i++;
        }
        else if (sentence[i] >= '0' and sentence[i] <= '9')
        {
            std::cout << "Case 2: found number";
            number = get_Number(sentence, i);
            std::cout << ", it's value: " << number << "\nPut it in part of numbers\n";
            add_Element(number);
        }
        else if ((sentence[i] >= 'a' and sentence[i] <= 'z') or (sentence[i] >= 'A' and sentence[i] <= 'Z'))
        {
            std::cout << "Case 3: found variable " << sentence[i] << ". Write it's value: ";
            std::cin >> number;
            add_Element(number);
            i++;
        }
        else
        {
            i = sentence.size();
            std::cout << "Error happened";
        }
        show_Array();
    }
}

//Both forming & checking polish notation
bool Dynamic_Array::make_Polish_Notation()
{
    int i = _size - 1;
    int cnt_brackets = 0;
    int cnt_symbols = 0;
    Stack operands;
    Dynamic_Array result;
    std::cout << "Forming array like prefix polish notation\n";
    while (i > -1)
    {
        std::cout << "Element: ";
        if (_numbers[i] == NULL) std::cout << _symbols[i] << '\n';
        else  std::cout << _numbers[i] << '\n';
        if (cnt_symbols == 2)
        {
            std::cout << "Wrong order of operands\n";
            return 0;
        }
        if (_numbers[i])
        {
            std::cout << "It's a number. Put it in array\n";
            result.add_Element(_numbers[i]);
            cnt_symbols = 0;
        }
        else if (_symbols[i] == '(')
        {
            std::cout << "It's a closing bracket. Put elements from stack into array until open bracket\n";
            while (operands.get_Size() and operands.get_Element() != ')')
            {
                std::cout << "Element: " << operands.get_Element() << '\n';
                result.add_Element(operands.get_Element());
                operands.delete_Element();
                std::cout << "Array: ";
                result.show_Array();
                std::cout << "Stack of operands: ";
                operands.show_Stack();
            }
            if (operands.get_Element() == ')')
            {
                std::cout << "Found closing bracket. Delete it\n";
                operands.delete_Element();
            }
            else
            {
                std::cout << "There is not closing bracket for needed closing one. Check your sentence\n";
                return 0;
            }
            cnt_brackets--;
        }
        else if (_symbols[i] == '*' or _symbols[i] == '/')
        {
            std::cout << "It's an operand with middle priority\n";
            while (operands.get_Size() and operands.get_Element() != ')' and operands.get_Element() != '+' and operands.get_Element() != '-')
            {
                std::cout << "Element: " << operands.get_Element() << '\n';
                result.add_Element(operands.get_Element());
                operands.delete_Element();
                std::cout << "Array: ";
                result.show_Array();
                std::cout << "Stack of operands: ";
                operands.show_Stack();
            }
            operands.add_Element(_symbols[i]);
            cnt_symbols++;
        }
        else if (_symbols[i] == '+' or _symbols[i] == '-')
        {
            while (operands.get_Size() and operands.get_Element() != ')')
            {
                std::cout << "Element: " << operands.get_Element() << '\n';
                result.add_Element(operands.get_Element());
                operands.delete_Element();
                std::cout << "Array: ";
                result.show_Array();
                std::cout << "Stack of operands: ";
                operands.show_Stack();
            }
            operands.add_Element(_symbols[i]);
            cnt_symbols++;
        }
        else if (_symbols[i] == ')')
        {
            operands.add_Element(_symbols[i]);
            cnt_brackets++;
        }
        std::cout << "Array: ";
        result.show_Array();
        std::cout << "Stack of operands: ";
        operands.show_Stack();
        i--;
    }
    while (operands.get_Size())
    {
        result.add_Element(operands.get_Element());
        operands.delete_Element();
        result.show_Array();
        std::cout << "Stack of operands: ";
        operands.show_Stack();
    }
    if (cnt_brackets)
    {
        std::cout << "There are more open brackets then closed\n";
        return 0;
    }
    if (cnt_symbols)
    {
        std::cout << "Too many operands\n";
        return 0;
    }
    std::cout << '\n';
    std::cout << "All is OK\n";
    _size = result.get_Size();
    for (int i = 0; i < _size; i++)
    {
        _numbers[_size - i - 1] = result._numbers[i];
    }
    for (int i = 0; i < _size; i++)
    {
        _symbols[_size - i - 1] = result._symbols[i];
    }
    return 1;
}

bool Dynamic_Array::make_Reverse_Polish_Notation()
{
    int i = 0;
    int cnt_brackets = 0;
    int cnt_symbols = 0;
    Stack operands;
    Dynamic_Array result;
    std::cout << "Forming array like reverse polish notation\n";
    while (i < _size)
    {
        std::cout << "Element: ";
        if (_numbers[i] == NULL) std::cout << _symbols[i] << '\n';
        else  std::cout << _numbers[i] << '\n';
        //if for checking order of symbols
        if (cnt_symbols == 2)
        {
            std::cout << "Wrong order of operands\n";
            return 0;
        }
        //Algorithm of forming reverse polish notation
        if (_numbers[i])
        {
            std::cout << "It's a number. Put it in array\n";
            result.add_Element(_numbers[i]);
            cnt_symbols = 0;
        }
        else if (_symbols[i] == ')')
        {
            std::cout << "It's a closing bracket. Put elements from stack into array until open bracket\n";
            while (operands.get_Size() and operands.get_Element() != '(')
            {
                std::cout << "Element: " << operands.get_Element() << '\n';
                result.add_Element(operands.get_Element());
                operands.delete_Element();
                std::cout << "Array: ";
                result.show_Array();
                std::cout << "Stack of operands: ";
                operands.show_Stack();
            }
            if (operands.get_Element() == '(')
            {
                std::cout << "Found open bracket. Delete it\n";
                operands.delete_Element();
            }
            else
            {
                std::cout << "There is not open bracket for needed closing one. Check your sentence\n";
                return 0;
            }
            cnt_brackets--;
        }
        else if (_symbols[i] == '*' or _symbols[i] == '/')
        {
            std::cout << "It's an operand with middle priority\n";
            while (operands.get_Size() and operands.get_Element() != '(' and operands.get_Element() != '+' and operands.get_Element() != '-')
            {
                std::cout << "Element: " << operands.get_Element() << '\n';
                result.add_Element(operands.get_Element());
                operands.delete_Element();
                std::cout << "Array: ";
                result.show_Array();
                std::cout << "Stack of operands: ";
                operands.show_Stack();
            }
            operands.add_Element(_symbols[i]);
            cnt_symbols++;
        }
        else if (_symbols[i] == '+' or _symbols[i] == '-')
        {
            while (operands.get_Size() and operands.get_Element() != '(')
            {
                std::cout << "Element: " << operands.get_Element() << '\n';
                result.add_Element(operands.get_Element());
                operands.delete_Element();
                std::cout << "Array: ";
                result.show_Array();
                std::cout << "Stack of operands: ";
                operands.show_Stack();
            }
            operands.add_Element(_symbols[i]);
            cnt_symbols++;
        }
        else if (_symbols[i] == '(')
        {
            operands.add_Element(_symbols[i]);
            cnt_brackets++;
        }
        std::cout << "Array: ";
        result.show_Array();
        std::cout << "Stack of operands: ";
        operands.show_Stack();
        i++;
    }
    while (operands.get_Size())
    {
        result.add_Element(operands.get_Element());
        operands.delete_Element();
        result.show_Array();
        std::cout << "Stack of operands: ";
        operands.show_Stack();
    }
    if (cnt_brackets)
    {
        std::cout << "There are more open brackets then closed\n";
        return 0;
    }
    if (cnt_symbols)
    {
        std::cout << "Too many operands\n";
        return 0;
    }
    std::cout << '\n';
    std::cout << "All is OK\n";
    _size = result.get_Size();
    for (int i = 0; i < _size; i++)
    {
        _numbers[i] = result._numbers[i];
    }
    for (int i = 0; i < _size; i++)
    {
        _symbols[i] = result._symbols[i];
    }
    return 1;
}

bool Dynamic_Array::check_Array()
{
    std::cout << "Checking brackets and order of elements\n";
    int cnt_brackets = 0;
    int cnt_symbols = 0;
    if (_symbols[0] == '-' and 0 < _size - 1 and _symbols[1] == NULL)
    {
        _numbers[1] *= (-1);
        delete_Element(0);
        cnt_symbols = 0;
    }
    for (int i = 0; i < _size; i++)
    {
        if (_symbols[i] == '(')
        {
            std::cout << "There is open bracket with index " << i << '\n';
            cnt_brackets += 1;
            if (i < _size - 2 and i > 0 and _symbols[i + 1] == '-' and _symbols[i + 2] == NULL)
            {
                _numbers[i + 2] *= (-1);
                delete_Element(i + 1);
            }
        }
        else if (_symbols[i] == ')')
        {
            std::cout << "There is closed bracket with index " << i << '\n';
            if (cnt_brackets == 0)
            {
                std::cout << "There are not open brackets for it\n";
                return 0;
            }
            cnt_brackets--;
        }
        else if (_symbols[i] != NULL)
        {
            cnt_symbols += 1;
            if (cnt_symbols == 2)
            {
                if (_symbols[i] == '-' and i < _size - 1 and _symbols[i + 1] == NULL)
                {
                    _numbers[i + 1] *= (-1);
                    delete_Element(i);
                    cnt_symbols = 0;
                }
                else
                {
                    std::cout << "Too many operands\n";
                    return 0;
                }
            }
        }
        else
        {
            cnt_symbols = 0;
        }
    }
    if (cnt_brackets)
    {
        std::cout << "There are more openning brackets then closed\n";
        return 0;
    }
    if (cnt_symbols)
    {
        std::cout << "Too many operands\n";
        return 0;
    }
    std::cout << '\n';
    std::cout << "All is OK\n";
    return 1;
}

double Dynamic_Array::count_Array()
{
    //Variable i notice on the end of part of array
    int i = 0;
    //Variable j on the beginning one
    int j;
    std::cout << "At first we must find brackets (if they are) and do all operations in them\n";
    while (i < _size)
    {
        if (_symbols[i] == ')')
        {
            j = i;
            while (_symbols[j] != '(')
            {
                j--;
            }
            make_Operation(j, i + 1);
            delete_Element(j + 1);
            delete_Element(j + 2);
            std::cout << "Delete brackets\n";
            i = j;
        }
        i++;
    }
    double* s_numbers = new double[_size];
    char* s_symbols = new char[_size];
    for (int i = 0; i < _size; i++)
    {
        s_numbers[i] = _numbers[i];
        s_symbols[i] = _symbols[i];
    }
    _numbers = s_numbers;
    _symbols = s_symbols;
    make_Operation(0, _size);
    return _numbers[0];
}

double Dynamic_Array::count_Polish_Notation()
{
    Number_Stack numbers_stack;
    double temp, temp_two;
    for (int i = _size - 1; i > -1; i--)
    {
        if (_numbers[i])
        {
            std::cout << "Element: " << _numbers[i] << "\nIt's a number, so put it in array of numbers\n";
            numbers_stack.add_Element(_numbers[i]);
        }
        else
        {
            std::cout << "Element: " << _symbols[i] << '\n';
            temp = numbers_stack.get_Element();
            numbers_stack.delete_Element();
            temp_two = numbers_stack.get_Element();
            std::cout << "It's a symbol. Operation " << temp << _symbols[i];
            if (_symbols[i] == '-') temp -= temp_two;
            else if (_symbols[i] == '+') temp += temp_two;
            else if (_symbols[i] == '*') temp *= temp_two;
            else if (_symbols[i] == '/') temp /= temp_two;
            std::cout << temp_two << '=' << temp << '\n';
            numbers_stack.delete_Element();
            numbers_stack.add_Element(temp);
        }
    }
    return numbers_stack.get_Element();
}

double Dynamic_Array::count_Polish_Notation(std::ofstream& fout)
{
    Number_Stack numbers_stack;
    double temp, temp_two;
    for (int i = _size - 1; i > -1; i--)
    {
        if (_numbers[i])
        {
            fout << "Element: " << _numbers[i] << "\nIt's a number, so put it in array of numbers\n";
            numbers_stack.add_Element(_numbers[i]);
        }
        else
        {
            fout << "Element: " << _symbols[i] << '\n';
            temp = numbers_stack.get_Element();
            numbers_stack.delete_Element();
            temp_two = numbers_stack.get_Element();
            fout << "It's a symbol. Operation " << temp << _symbols[i];
            if (_symbols[i] == '-') temp -= temp_two;
            else if (_symbols[i] == '+') temp += temp_two;
            else if (_symbols[i] == '*') temp *= temp_two;
            else if (_symbols[i] == '/') temp /= temp_two;
            fout << temp_two << '=' << temp << '\n';
            numbers_stack.delete_Element();
            numbers_stack.add_Element(temp);
        }
    }
    return numbers_stack.get_Element();
}

double Dynamic_Array::count_Reverse_Polish_Notation()
{
    Number_Stack numbers_stack;
    double temp, temp_two;
    for (int i = 0; i < _size; i++)
    {
        if (_numbers[i])
        {
            std::cout << "Element: " << _numbers[i] << "\nIt's a number, so put it in array of numbers\n";
            numbers_stack.add_Element(_numbers[i]);
        }
        else
        {
            std::cout << "Element: " << _symbols[i] << '\n';
            temp = numbers_stack.get_Element();
            numbers_stack.delete_Element();
            temp_two = numbers_stack.get_Element();
            std::cout << "It's a symbol. Operation " << temp_two << _symbols[i];
            if (_symbols[i] == '-') temp_two -= temp;
            else if (_symbols[i] == '+') temp_two += temp;
            else if (_symbols[i] == '*') temp_two *= temp;
            else if (_symbols[i] == '/') temp_two /= temp;
            std::cout << temp << '=' << temp_two << '\n';
            numbers_stack.delete_Element();
            numbers_stack.add_Element(temp_two);
        }
    }
    return numbers_stack.get_Element();
}

double Dynamic_Array::count_Reverse_Polish_Notation(std::ofstream& fout)
{
    Number_Stack numbers_stack;
    double temp, temp_two;
    for (int i = 0; i < _size; i++)
    {
        if (_numbers[i])
        {
            fout << "Element: " << _numbers[i] << "\nIt's a number, so put it in array of numbers\n";
            numbers_stack.add_Element(_numbers[i]);
        }
        else
        {
            fout << "Element: " << _symbols[i] << '\n';
            temp = numbers_stack.get_Element();
            numbers_stack.delete_Element();
            temp_two = numbers_stack.get_Element();
            fout << "It's a symbol. Operation " << temp_two << _symbols[i];
            if (_symbols[i] == '-') temp_two -= temp;
            else if (_symbols[i] == '+') temp_two += temp;
            else if (_symbols[i] == '*') temp_two *= temp;
            else if (_symbols[i] == '/') temp_two /= temp;
            fout << temp << '=' << temp_two << '\n';
            numbers_stack.delete_Element();
            numbers_stack.add_Element(temp_two);
        }
    }
    return numbers_stack.get_Element();
}

void Dynamic_Array::make_Operation(int begin, int end)
{
    int i = begin + 1;
    while (i < end)
    {
        if (_symbols[i] == '*')
        {
            show_Array();
            std::cout << "Operation '*': " << _numbers[i - 1] << " * " << _numbers[i + 1] << '\n';
            _numbers[i - 1] *= _numbers[i + 1];
            delete_Element(i + 1);
            delete_Element(i + 1);
            end -= 2;
        }
        else if (_symbols[i] == '/')
        {
            show_Array();
            std::cout << "Operation '/': " << _numbers[i - 1] << " / " << _numbers[i + 1] << '\n';
            _numbers[i - 1] /= _numbers[i + 1];
            delete_Element(i + 1);
            delete_Element(i + 1);
            end -= 2;
        }
        else i++;
    }
    i = begin + 1;
    while (i < end)
    {
        if (_symbols[i] == '+')
        {
            show_Array();
            std::cout << "Operation '+': " << _numbers[i - 1] << " + " << _numbers[i + 1] << '\n';
            _numbers[i - 1] += _numbers[i + 1];
            delete_Element(i + 1);
            delete_Element(i + 1);
            end -= 2;
        }
        else if (_symbols[i] == '-')
        {
            show_Array();
            std::cout << "Operation '-': " << _numbers[i - 1] << " - " << _numbers[i + 1] << '\n';
            _numbers[i - 1] -= _numbers[i + 1];
            delete_Element(i + 1);
            delete_Element(i + 1);
            end -= 2;
        }
        else i++;
    }
}

void Dynamic_Array::add_Element(double number)
{
    char* rez_array_symb = new char[_size + 1];
    double* rez_array_numb = new double[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        rez_array_symb[i] = _symbols[i];
        rez_array_numb[i] = _numbers[i];
    }
    delete[] _symbols;
    delete[] _numbers;
    rez_array_symb[_size++] = NULL;
    _symbols = rez_array_symb;
    _numbers = rez_array_numb;
    _numbers[_size - 1] = number;
}

void Dynamic_Array::add_Element(char operand)
{
    char* rez_array_symb = new char[_size + 1];
    double* rez_array_numb = new double[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        rez_array_symb[i] = _symbols[i];
        rez_array_numb[i] = _numbers[i];
    }
    delete[] _symbols;
    delete[] _numbers;
    rez_array_symb[_size++] = operand;
    _symbols = rez_array_symb;
    rez_array_numb[_size - 1] = NULL;
    _numbers = rez_array_numb;
}

void Dynamic_Array::delete_Element(int index)
{
    char* rez_array_symb = new char[_size - 1];
    double* rez_array_numb = new double[_size - 1];
    for (int i = 0; i < index; i++)
    {
        rez_array_symb[i] = _symbols[i];
        rez_array_numb[i] = _numbers[i];
    }
    for (int i = index; i < _size; i++)
    {
        rez_array_symb[i - 1] = _symbols[i];
        rez_array_numb[i - 1] = _numbers[i];
    }
    delete[] _symbols;
    delete[] _numbers;
    _symbols = rez_array_symb;
    _numbers = rez_array_numb;
    _size--;
}

void Dynamic_Array::show_Array()
{
    for (int i = 0; i < _size; i++)
    {
        if (_symbols[i] == NULL) std::cout << _numbers[i] << ' ';
        else std::cout << _symbols[i] << ' ';
    }
    std::cout << '\n';
}

void Dynamic_Array::show_Array(std::ofstream& fout)
{
    for (int i = 0; i < _size; i++)
    {
        if (_symbols[i] == NULL) fout << _numbers[i] << ' ';
        else fout << _symbols[i] << ' ';
    }
    fout << "\n\n";
}

int Dynamic_Array::get_Size()
{
    return _size;
}

void result_Of_Simple_Expression(std::string sentence, int begin, int end, Dynamic_Array arr)
{
    bool check;
    check = arr.check_Array();
    if (check) std::cout << '\n' << "Result: " << arr.count_Array() << '\n';
}

void result_Of_Straight_Polish_Notation(std::string sentence, int begin, int end, Dynamic_Array arr)
{
    bool check;
    check = arr.make_Polish_Notation();
    if (check)
    {
        arr.show_Array();
        std::cout << '\n' << "Result: " << arr.count_Polish_Notation() << '\n';
    }
}

void result_Of_Reverse_Polish_Notation(std::string sentence, int begin, int end, Dynamic_Array arr)
{
    if (arr.make_Reverse_Polish_Notation()) std::cout << '\n' << "Result: " << arr.count_Reverse_Polish_Notation() << '\n';
}

void generate_Work(std::ofstream& task, std::ofstream& answer)
{
    int cnt = 0;
    int number;
    bool check = 0;
    int i = 0;
    Dynamic_Array arr;
    answer << '\n';
    number = rand() % 15;
    if (number % 2 == 0) number += 1;
    if (rand() % 2 - 1)
    {
        task << "Count this polish notation: ";
        cnt--;
        while (i < number)
        {
            check = rand() % 2 - 1;
            if (check and cnt > 0)
            {
                arr.add_Element(rand() % 20 - 10 * 1.);
                cnt--;
            }
            else
            {
                switch (rand() % 4)
                {
                case(0):
                {
                    arr.add_Element('+');
                    break;
                }
                case(1):
                {
                    arr.add_Element('-');
                    break;
                }
                case(2):
                {
                    arr.add_Element('*');
                    break;
                }
                case(3):
                {
                    arr.add_Element('/');
                    break;
                }
                }
                cnt++;
            }
            i++;
        }
        while (cnt > -2)
        {
            arr.add_Element(rand() % 20 - 10 * 1.);
            cnt--;
        }
        arr.show_Array(task);
        answer << '\n' << "Result: " << arr.count_Polish_Notation(answer) << '\n';
    }
    else
    {
        task << "Count this reverse polish notation: ";
        cnt++;
        while (i < number)
        {
            check = rand() % 2 - 1;
            if (check or cnt > -1)
            {
                arr.add_Element(rand() % 20 - 10 * 1.);
                cnt--;
            }
            else
            {
                switch (rand() % 4)
                {
                case(0):
                {
                    arr.add_Element('+');
                    break;
                }
                case(1):
                {
                    arr.add_Element('-');
                    break;
                }
                case(2):
                {
                    arr.add_Element('*');
                    break;
                }
                case(3):
                {
                    arr.add_Element('/');
                    break;
                }
                }
                cnt++;
            }
            i++;
        }
        while (cnt < 0)
        {
            switch (rand() % 4)
            {
            case(0):
            {
                arr.add_Element('+');
                break;
            }
            case(1):
            {
                arr.add_Element('-');
                break;
            }
            case(2):
            {
                arr.add_Element('*');
                break;
            }
            case(3):
            {
                arr.add_Element('/');
                break;
            }
            }
            cnt++;
        }
        arr.show_Array(task);
        answer << '\n' << "Result: " << arr.count_Reverse_Polish_Notation(answer) << '\n';
    }
}

int main()
{
    std::string sentence;
    int method;
    Stack symbols;
    Dynamic_Array arr;
    int index = 0;
    srand(4541);
    try
    {
        std::ifstream fin("data.txt");
        std::ofstream task("task.txt");
        std::ofstream answer("answer.txt");
        if (!fin.is_open()) throw "Check file: data.txt must exist";
        std::cout << "Write 0 if you want to write sentence from console, 1 if from file: ";
        std::cin >> method;
        if (!std::cin) throw "Error in choosing method";
        if (!method)
        {
            std::cout << "Write sentence (without spaces, in infix form):\n";
            std::cin >> sentence;
        }
        else
        {
            fin >> sentence;
        }
        std::cout << "Write 0 if you want to write see work with simple expression, 1 if with straight polish notation and 2 with reverse polish notation: ";
        std::cin >> method;
        if (!std::cin) throw "Error in choosing method";
        std::cout << "First step: form array of expression's elements\n";
        std::cout << '\n';
        arr.make_Array(sentence);
        std::cout << '\n';
        if (method == 0)
        {
            result_Of_Simple_Expression(sentence, 0, sentence.size(), arr);
        }
        else if (method == 1)
        {
            result_Of_Straight_Polish_Notation(sentence, 0, sentence.size(), arr);
        }
        else if (method == 2)
        {
            result_Of_Reverse_Polish_Notation(sentence, 0, sentence.size(), arr);
        }
        std::cout << "\nWrite number of works you want to get: ";
        std::cin >> method;
        if (!std::cin) throw "Error in choosing method";
        for (int i = 0; i < method; i++)
        {
            task << "Task " << i + 1 << ":\n";
            answer << "Task " << i + 1 << ":\n";
            generate_Work(task, answer);
            answer << '\n';
        }
        fin.close();
        task.close();
        answer.close();
    }
    catch (const char* ex)
    {
        std::cout << ex;
    }
    return 0;
}