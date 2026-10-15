Для лексера
pip install flex
\ada_lexer.exe test.adb
при наличии всех файлов(ada_lexer.exe, ada_lexer.l, lex.yy.c, test.adb)

В pars.y надо дописывать правила под:

- with PKG; и use PKG; в начале файла.

- Перечисления: type T is (A, B, C);

- Диапазонные типы: type T is range E .. E;

- Записи: type T is record ... end record;

- Константы: X : constant T := ...;

- case ... is when ... => ... end case;

- exception when ... => ...;

- in / out / in out у параметров.

- Строковые литералы как выражения в списках (уже есть), вызовы Put_Line(...) с Width => 3 (именованные параметры — отдельное правило).
(решено)

Для парсера:
bison -d pars.y
flex ada_lexer.l
g++ -x c++ pars.tab.c -x c++ lex.yy.c class_nodes.cpp -o parser.exe -lm