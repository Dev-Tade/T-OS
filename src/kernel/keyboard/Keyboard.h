#include "../sys/Types.h"
#include "../sys/IO.h"
#include "../screen/Screen.h"

s8int __MapKeycodes__(u8int base);
char ReadKey(bool showkey);
string ReadStr(bool newlineend);