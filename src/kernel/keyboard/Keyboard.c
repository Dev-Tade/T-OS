#include "Keyboard.h"

char ReadKey(bool showkey)
{
	char buff;
    bool reading = true;
    while (reading)
    {
        if (inb(0x64) & 0x1)
        {
            buff = __MapKeycodes__(inb(0x60));
            if (showkey == true) {Screen_Put(buff);}
            reading = false;
        }
    }
    return buff;
}

string ReadStr(bool newlineend)
{
    string buffstr;
    int i = 0;
    bool reading = true;
    while(reading)
    {
        if(inb(0x64) & 0x1)                 
        {
            switch(inb(0x60))
            { 
        case 1:
                Screen_Put('\0'); buffstr[i] = '\0'; reading = false;
                break;
        case 2:
                Screen_Put('1'); buffstr[i] = '1'; i++;
                break;
        case 3:
                Screen_Put('2'); buffstr[i] = '2'; i++;
                break;
        case 4:
                Screen_Put('3'); buffstr[i] = '3'; i++;
                break;
        case 5:
                Screen_Put('4'); buffstr[i] = '4'; i++;
                break;
        case 6:
                Screen_Put('5'); buffstr[i] = '5'; i++;
                break;
        case 7:
                Screen_Put('6'); buffstr[i] = '6'; i++;
                break;
        case 8:
                Screen_Put('7'); buffstr[i] = '7'; i++;
                break;
        case 9:
                Screen_Put('8'); buffstr[i] = '8'; i++;
                break;
        case 10:
                Screen_Put('9'); buffstr[i] = '9'; i++;
                break;
        case 11:
                Screen_Put('0'); buffstr[i] = '0'; i++;
                break;
        case 12:
                Screen_Put('-'); buffstr[i] = '-'; i++;
                break;
        case 13:
                Screen_Put('='); buffstr[i] = '='; i++;
                break;
        case 14:
                Screen_Put('\b'); i--; buffstr[i] = ' ';
                break;
        case 15:
                Screen_Put('\t'); buffstr[i] = '\t'; i++;
                break;
        case 16:
                Screen_Put('q'); buffstr[i] = 'q'; i++;
                break;
        case 17:
                Screen_Put('w'); buffstr[i] = 'w'; i++;
                break;
        case 18:
                Screen_Put('e'); buffstr[i] = 'e'; i++;
                break;
        case 19:
                Screen_Put('r'); buffstr[i] = 'r'; i++;
                break;
        case 20:
                Screen_Put('t'); buffstr[i] = 't'; i++;
                break;
        case 21:
                Screen_Put('y'); buffstr[i] = 'y'; i++;
                break;
        case 22:
                Screen_Put('u'); buffstr[i] = 'u'; i++;
                break;
        case 23:
                Screen_Put('i'); buffstr[i] = 'i'; i++;
                break;
        case 24:
                Screen_Put('o'); buffstr[i] = 'o'; i++;
                break;
        case 25:
                Screen_Put('p'); buffstr[i] = 'p'; i++;
                break;
        case 26:
                Screen_Put('['); buffstr[i] = '['; i++;
                break;
        case 27:
                Screen_Put(']'); buffstr[i] = ']'; i++;
                break;
        case 28:
                Screen_Put('\n'); buffstr[i] = '\n'; i++;
                if (newlineend == true) {reading = false;}
                break;
        case 30:
                Screen_Put('a'); buffstr[i] = 'a'; i++;
                break;
        case 31:
                Screen_Put('s'); buffstr[i] = 's'; i++;
                break;
        case 32:
                Screen_Put('d'); buffstr[i] = 'd'; i++;
                break;
        case 33:
                Screen_Put('f'); buffstr[i] = 'f'; i++;
                break;
        case 34:
                Screen_Put('g'); buffstr[i] = 'g'; i++;
                break;
        case 35:
                Screen_Put('h'); buffstr[i] = 'h'; i++;
                break;
        case 36:
                Screen_Put('j'); buffstr[i] = 'j'; i++;
                break;
        case 37:
                Screen_Put('k'); buffstr[i] = 'k'; i++;
                break;
        case 38:
                Screen_Put('l'); buffstr[i] = 'l'; i++;
                break;
        case 39:
                Screen_Put(';'); buffstr[i] = ';'; i++;
                break;
        case 40:
                Screen_Put('\''); buffstr[i] = '\''; i++;
                break;
        case 41:
                Screen_Put('`'); buffstr[i] = '`'; i++;
                break;
        case 44:
                Screen_Put('z'); buffstr[i] = 'z'; i++;
                break;
        case 45:
                Screen_Put('x'); buffstr[i] = 'x'; i++;
                break;
        case 46:
                Screen_Put('c'); buffstr[i] = 'c'; i++;
                break;
        case 47:
                Screen_Put('v'); buffstr[i] = 'v'; i++;
                break;                
        case 48:
                Screen_Put('b'); buffstr[i] = 'b'; i++;
                break;               
        case 49:
                Screen_Put('n'); buffstr[i] = 'n'; i++;
                break;                
        case 50:
                Screen_Put('m'); buffstr[i] = 'm'; i++;
                break;               
        case 51:
                Screen_Put(','); buffstr[i] = ','; i++;
                break;                
        case 52:
                Screen_Put('.'); buffstr[i] = '.'; i++;
                break;            
        case 53:
                Screen_Put('/'); buffstr[i] = '/'; i++;
                break;            
        case 54:
                Screen_Put('*'); buffstr[i] = '*'; i++;
                break;            
        case 55:
                Screen_Put('/'); buffstr[i] = '/'; i++;
                break;                    
        case 57:
                Screen_Put(' '); buffstr[i] = ' '; i++;
                break;
        case 121:
                Screen_Put('+'); buffstr[i] = '+'; i++;
                break;
            }
        }
    }
    buffstr[i] = 0;
    return buffstr;
}

s8int __MapKeycodes__(u8int base)
{
switch(base)
        { 
        case 1:
                return '\0';
                break;
        case 2:
                return '1';
                break;
        case 3:
                return '2';
                break;
        case 4:
                return '3';
                break;
        case 5:
                return '4';
                break;
        case 6:
                return '5';
                break;
        case 7:
                return '6';
                break;
        case 8:
                return '7';
                break;
        case 9:
                return '8';
                break;
        case 10:
                return '9';
                break;
        case 11:
                return '0';
                break;
        case 12:
                return '-';
                break;
        case 13:
                return '=';
                break;
        case 14:
                return 0;
                break;
        case 15:
                return '\t';
                break;
        case 16:
                return 'q';
                break;
        case 17:
                return 'w';
                break;
        case 18:
                return 'e';
                break;
        case 19:
                return 'r';
                break;
        case 20:
                return 't';
                break;
        case 21:
                return 'y';
                break;
        case 22:
                return 'u';
                break;
        case 23:
                return 'i';
                break;
        case 24:
                return 'o';
                break;
        case 25:
                return 'p';
                break;
        case 26:
                return '[';
                break;
        case 27:
                return ']';
                break;
        case 28:
                return '\n';
                break;
        case 30:
                return 'a';
                break;
        case 31:
                return 's';
                break;
        case 32:
                return 'd';
                break;
        case 33:
                return 'f';
                break;
        case 34:
                return 'g';
                break;
        case 35:
                return 'h';
                break;
        case 36:
                return 'j';
                break;
        case 37:
                return 'k';
                break;
        case 38:
                return 'l';
                break;
        case 39:
                return ';';
                break;
        case 40:
                //   Single quote (')
                return (char)44;
                break;
        case 41:
                // Back tick (`)
                return (char)44;
                break;
        case 44:
                return 'z';
                break;
        case 45:
                return 'x';
                break;
        case 46:
                return 'c';
                break;
        case 47:
                return 'v';
                break;                
        case 48:
                return 'b';
                break;               
        case 49:
                return 'n';
                break;                
        case 50:
                return 'm';
                break;               
        case 51:
                return ',';
                break;                
        case 52:
                return '.';
                break;            
        case 53:
                return '/';
                break;            
        case 54:
                return '*';
                break;            
        case 55:
                return '/';
                break;                    
        case 57:
                return ' ';
                break;
    }
}