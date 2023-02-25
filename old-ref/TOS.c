/* GRAPICHS */
#define VGA_ADDRESS 0xB8000
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define PURPLE 5
#define BROWN 6
#define GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define YELLOW 14
#define WHITE 15

unsigned short* Terminal_Buffer;
unsigned int VGA_Index;

int len_str(char* String) {
    int x;
    for(x = 0; String[x] != '\0';x++);
    return x;
}

void Println(char* String, unsigned char Color)
{
    int Index = 0;
    int Len = len_str(String);
    char Null = ' ';
    while (String[Index])
    {
        Terminal_Buffer[VGA_Index] = (unsigned short)String[Index] | (unsigned short)Color << 8;
        Index++;
        VGA_Index++;
    }
    for (int i = 0; i < 80-Len; i++)
    {
        Terminal_Buffer[VGA_Index] = (unsigned short)Null | (unsigned short)Color << 8;
        Index++;
        VGA_Index++;
    }
}

void Putchar(char Chr, int Index, unsigned char Color)
{
    Terminal_Buffer[Index] = Chr | (unsigned)Color << 8;
    VGA_Index++;
}

void Scr_Clear(void)
{
    int Index = 0;
    while (Index < 80*25*2)
    {
        Terminal_Buffer[Index] = ' ';
        Index += 1;
    }
}