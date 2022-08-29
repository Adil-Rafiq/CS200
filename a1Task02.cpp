
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void enterNumber(char *, int, int);
bool validate(char *, int, int);
int char_to_int(char *, int);
void inverted_array(char *, int);
char *deci_to_bin(char *, int, int &);
char *deci_to_hexa(char *, int, int &);
char *bin_to_deci(char *, int, int &);
char *bin_to_hexa(char *, int, int &);
char *hexa_to_deci(char *, int, int &);
char *hexa_to_bin(char *, int, int &);
void print(char *, int);

int main()
{
    int numType, size, new_size;
    char *ptr;
    bool flag;
    do
    {
        cout << "\n*** \t Select a number system \t ***" << endl;
        cout << "1- Decimal Number System" << endl
             << "2- Binary Number System" << endl
             << "3- Hexadecimal Number System" << endl
             << "0- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> numType;

        if (numType == 1 || numType == 2 || numType == 3)
        {
            cout << "\nEnter the number size: ";
            cin >> size;
            char *num = new char[size];

            switch (numType)
            {
            case 1:
                cout << "Enter a decimal number: ";
                enterNumber(num, size, numType);
                ptr = deci_to_bin(num, size, new_size);
                cout << "Binary: ";
                print(ptr, new_size);
                ptr = deci_to_hexa(num, size, new_size);
                cout << "Hexadecimal: ";
                print(ptr, new_size);

                break;
            case 2:
                cout << "Enter a binary number: ";
                enterNumber(num, size, numType);
                ptr = bin_to_deci(num, size, new_size);
                cout << "Decimal: ";
                print(ptr, new_size);
                ptr = bin_to_hexa(num, size, new_size);
                cout << "Hexadecimal: ";
                print(ptr, new_size);

                break;
            case 3:
                cout << "Enter a hexadecimal number: ";
                enterNumber(num, size, numType);
                ptr = hexa_to_deci(num, size, new_size);
                cout << "Decimal: ";
                print(ptr, new_size);
                ptr = hexa_to_bin(num, size, new_size);
                cout << "Binary: ";
                print(ptr, new_size);

                break;
            }

            continue;
        }
        else if (numType == 0)
        {
            break;
        }
        else
        {
            cout << "\nIncorrect input! Please try again" << endl;
            continue;
        }

    } while (numType != 0);

    return 0;
}

void enterNumber(char *num, int size, int numType)
{
    bool flag;
    do
    { // entering the number
        for (int i = 0; i < size; i++)
        {
            cin >> *(num + i);
        }

        // validating the number
        flag = validate(num, size, numType);
        if (!flag)
            cout << "incorrect format!\nPlease enter again: ";
    } while (!flag);
}

void print(char *num, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << num[i];
    }

    cout << endl;
}

bool validate(char *num, int size, int numType)
{
    if (numType == 1)
    {
        // decimal validation
        for (int i = 0; i < size; i++)
        {
            if (int(num[i]) < 48 || int(num[i]) > 57)
            {
                return false;
            }
        }
    }
    else if (numType == 2)
    {
        // binary validation
        for (int i = 0; i < size; i++)
        {
            if (int(num[i]) < 48 || int(num[i]) > 49)
            {
                return false;
            }
        }
    }
    else
    {
        // hexadecimal validation
        int n;
        for (int i = 0; i < size; i++)
        {
            n = int(num[i]);
            if (!(n >= 48 && n <= 57) && !(n >= 65 && n <= 70) && !(n >= 97 && n <= 102))
            {
                return false;
            }
        }
    }

    return true;
}

int char_to_int(char *num, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        n *= 10;
        n += int(num[i] - 48);
    }

    return n;
}

void inverted_array(char *num, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        char temp = num[i];
        num[i] = num[size - (i + 1)];
        num[size - (i + 1)] = temp;
    }
}

char *deci_to_bin(char *num, int size, int &new_size)
{
    // converting the char array to number
    int n = char_to_int(num, size);

    // converting to binary and then storing in new char array
    int r = 0;
    new_size = 0;
    char *ptr = new char[new_size];

    while (n > 0)
    {
        r = n % 2;
        n /= 2;
        r += 48;
        ptr[new_size] = char(r);
        new_size++;
    }

    // inverting the char array
    n = new_size;
    inverted_array(ptr, n);

    return ptr;
}

char *deci_to_hexa(char *num, int size, int &new_size)
{
    // converting the char array to number
    int n = char_to_int(num, size);

    // converting to hexa and then storing in new char array
    int r = 0;
    new_size = 0;
    char *ptr = new char[new_size];

    while (n > 0)
    {
        r = n % 16;
        n /= 16;
        if (r > 9)
            r += 87;
        else
            r += 48;

        ptr[new_size] = char(r);
        new_size++;
    }

    // inverting the char array
    n = new_size;
    inverted_array(ptr, n);

    return ptr;
}

char *bin_to_deci(char *num, int size, int &new_size)
{
    // converting the char array to number
    int n = char_to_int(num, size);

    // converting to decimal and then storing in new char array
    int sum = 0;
    new_size = 0;
    char *ptr = new char[new_size];

    for (int i = 0; i < size; i++)
    {
        sum += n % 10 * pow(2, i);
        n /= 10;
    }

    while (sum > 0)
    {
        ptr[new_size] = char(sum % 10 + 48);
        sum /= 10;
        new_size++;
    }

    // inverting the char array
    n = new_size;
    inverted_array(ptr, n);

    return ptr;
}

char *hexa_to_deci(char *num, int size, int &new_size)
{
    // converting hexa char array to a decimal number
    int sum = 0, n;
    for (int i = 0; i < size; i++)
    {
        n = num[size - (i + 1)];
        if (n >= 65 && n <= 70)
        {
            sum += (n - 55) * pow(16, i);
        }
        else if (n >= 97 && n <= 102)
        {
            sum += (n - 87) * pow(16, i);
        }
        else
        {
            sum += (n - 48) * pow(16, i);
        }
    }

    // storing the decimal number in char array
    new_size = 0;
    char *ptr = new char[new_size];
    while (sum > 0)
    {
        ptr[new_size] = char(sum % 10 + 48);
        sum /= 10;
        new_size++;
    }

    // inverting the char array
    n = new_size;
    inverted_array(ptr, n);

    return ptr;
}

char *bin_to_hexa(char *num, int size, int &new_size)
{
    char *ptr = bin_to_deci(num, size, new_size);
    size = new_size;
    ptr = deci_to_hexa(ptr, size, new_size);

    return ptr;
}

char *hexa_to_bin(char *num, int size, int &new_size)
{
    char *ptr = hexa_to_deci(num, size, new_size);
    size = new_size;
    ptr = deci_to_bin(ptr, size, new_size);

    return ptr;
}
