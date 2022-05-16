# LogS
## Информация
Небольшая библиотека, облегчающая работу с выводом сообщений (Python-style).

## Особенности
* Поддержка С++20
* Работа со всеми __ostream__-потоками (консоль, файловая система, ...)

## Использование
```cpp
#include <iostream>
#include <LogS.h>

...

CLogS LogS(std::cout);
LogS.print("Hello, world!");
LogS.print("Hello, ", "world", "!", '\n', 1707, '\n', 22.17f);
```
