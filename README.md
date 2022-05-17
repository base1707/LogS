## LogS
Небольшая библиотека, реализующая Python-style вывод сообщений в потоки std::ofstream.

## Особенности
* Поддержка С++20
* Работа со всеми __ostream__-потоками (консоль, файловая система, ...)

## Использование
```cpp
#include <LogS.h>

// # For std::cout
#include <iostream>

...

CLogS LogS(std::cout);
LogS.Print("Hello, world!");
LogS.Print("Hello, ", "world", "!", '\n', 1707, '\n', 22.17f);
```
