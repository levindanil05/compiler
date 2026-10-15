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