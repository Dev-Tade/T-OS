#define  VGA_ADDRESS 0xB8000

#define YELLOW 14
#define WHITE 15
#define BLACK 0
#define GREEN 2
#define RED 4

unsigned short* Terminal_Buffer;
unsigned int VGA_Index;

void Clear_Screen(void);
void Print_String(char* str, unsigned char color);

void main(void)
{
    Terminal_Buffer = (unsigned short*)VGA_ADDRESS;
    VGA_Index = 0;

    Clear_Screen();
    Print_String("An experimental OS written in:", YELLOW);
    VGA_Index = 80;
    Print_String("Assembly & C", RED);
    VGA_Index = 160;
}

void Clear_Screen(void)
{
    int Index = 0;
    while (Index < 80*25*2)
    {
        Terminal_Buffer[Index] = ' ';
        Index += 2;
    }
}

void Print_String(char* str, unsigned char color)
{
    int Index = 0;
    while (str[Index])
    {
        Terminal_Buffer[VGA_Index] = (unsigned short)str[Index] | (unsigned short)color << 8;
        Index++;
        VGA_Index++;
    }
}