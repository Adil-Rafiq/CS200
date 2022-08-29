#include <iostream>
#include <cmath>
using namespace std;

// helper functions
int hexCharToDecimal(char c);
char hexDigit(string bits4);

// conversion functions
int hexa2Deci(string hexa);
string deci2Binary(int decimal);
string binary2Hexa(string binary);

// validator functions
bool isBinary(string binary);
bool isHexa(string hexa);

int main() {
    int numType;
    bool flag = true;
    do
    {
        cout << "\n*** \t Select a number system \t ***" << endl;
        cout << "1- Decimal Number System" << endl
             << "2- Binary Number System" << endl
             << "3- Hexadecimal Number System" << endl
             << "0- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> numType;
        while(cin.fail()){
            cout << "Wrong choice. Try Again: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> numType;
        }

        switch (numType)
        {
        case 1:
            {
                int decimal;
                cout << "Enter a decimal number: ";
                cin >> decimal;
                // If User enters a non-integer input.
                while(cin.fail()){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid Number. Try Again:\n";
                    cin >> decimal;
                }
                cout << "Binary: ";
                cout << deci2Binary(decimal) << '\n';
                cout << "HexaDecimal: ";
                cout << binary2Hexa(deci2Binary(decimal)) << '\n';
            }
            break;
        case 2:
            {
                cout << "Enter a binary number: ";
                string binary;
                cin >> binary;
                while(!isBinary(binary)){
                    cout << "Invalid Number. Try Again:\n";
                    cin >> binary;
                }
                cout << "HexaDecimal: ";
                cout << binary2Hexa(binary) << '\n';
                cout << "Decimal: ";
                cout << hexa2Deci(binary2Hexa(binary)) << '\n';
            }
            break;
        case 3:
            {
                cout << "Enter a hexadecimal number: ";
                string hexa;
                cin >> hexa;
                while(!isHexa(hexa)){
                    cout << "Invalid Number. Try Again:\n";
                    cin >> hexa;
                }
                cout << "Decimal: ";
                cout << hexa2Deci(hexa) << '\n';
                cout << "Binary: ";
                cout << deci2Binary(hexa2Deci(hexa)) << '\n';
            }
            break;
        case -1:
            flag = false;
            break;

        default:
            cout << "Wrong Choice. Enter -1 to Exit.\n";
        }
    } while (flag);

    return 0;
}

int hexCharToDecimal(char c){
    if(c >= '0' && c<= '9') return c - '0';
    if(c >= 'a' && c<= 'f') return c - 'a' + 10;
    if(c >= 'A' && c<= 'F') return c - 'A' + 10;
    return -1;
}

int hexa2Deci(string hexa){
    int deci = 0;
    int pow16 = 1;
    for(int i = hexa.size() - 1; i >= 0  ; --i){
        deci += hexCharToDecimal(hexa[i]) * pow16;
        pow16 *= 16;
    }
    return deci;
}

string deci2Binary(int decimal){
    string binary = "";
    int length = 0;

    // run until decimal/(2^length) has a non-zero integral part
    while(int(decimal/pow(2,length)))
        length++;

    // will check the nth bit using (decimal >> n) & 1
    // where (>>) is the right shift operator equivalent to dividing by 2^n
    for(int i = length - 1; i >= 0 ; --i)
        // if nth bit is set add '1' else add '0'
        binary += (decimal >> i) & 1 ? '1' : '0';

    return binary;
}

// Will map 4bits to 1hex digit: 0111 -> 8 , 1111 -> f
char hexDigit(string bits4){
    // every four bits of a binary are equiuvalent to one hex digit
    int digit = 0;
    int pow2 = 8;
    for(int i = 0; i < 4; ++i){
        if(bits4[i] != '0'){
            digit += pow2;
        }
        pow2 /= 2;
    }
    return (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
}

string binary2Hexa(string binary){
    string hexa = "";

    if(binary.size() % 4){
        int paddingZeros = 4 - (binary.size() % 4);
        while(paddingZeros--){
            binary = '0' + binary;
        }
    }

    for(int i = 0; i < binary.size() ; i += 4){
        hexa += hexDigit(binary.substr(i,4));
    }

    return hexa;
}

bool isBinary(string binary){
    for(int i = 0; i < binary.size(); ++i){
        if( !(binary[i] == '0' || binary[i] == '1')){
            return false;
        }
    }
    return true;
}

bool isHexa(string hexa){
    for(int i = 0; i < hexa.size() ; ++i){
        if(hexCharToDecimal(hexa[i]) == -1){
            return false;
        }
    }
    return true;
}
