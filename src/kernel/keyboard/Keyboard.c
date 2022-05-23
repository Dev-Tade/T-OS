#include "Keyboard.h"

s8int ReadKey(state_t hide)
{
	s8int buff;
    int reading = 1;
    while (reading)
    {
        if (inb(0x64) & 0x1)
        {
            buff = MapKeycodes(inb(0x60));
            if (hide == on) {Screen_Put(buff);}
            reading = 0;
        }
    }
    return buff;
}

string ReadStr(state_t hide)
{
    string buff;
    char key;
    int reading = 1;
    int i = 0;
    while (reading)
    {
        if (inb(0x64) & 0x1)
        {
            switch (key = inb(0x60))
            {
            case 28:
                buff[i] = '\0';
                Screen_Put('\n');
                reading = 0;
                break;
            default:
                buff[i] = MapKeycodes(key);
                if (hide == on) {Screen_Put(buff[i]);}
                i++;
                break;
            }
        }
    }
}

s8int MapKeycodes(u8int base)
{
    switch(base)
            { 
        case 1:
                return (char)27;
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
                return '.';
                break;            
        case 55:
                return '/';
                break;                    
        case 57:
                return ' ';
                break;
    }
}