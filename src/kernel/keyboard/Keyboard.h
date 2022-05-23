#include "../sys/Types.h"
#include "../sys/IO.h"
#include "../screen/Screen.h"

s8int MapKeycodes(u8int base);
s8int ReadKey(state_t hide);
string ReadStr();