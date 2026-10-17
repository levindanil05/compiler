# Лексер и парсер языка Ada

Учебная реализация лексического и синтаксического анализаторов языка Ada с использованием Flex, Bison и C++.

## Полезные ссылки

- [Ada Reference Manual](https://www.adaic.org/ada-resources/standards/ada95/)
- [WinFlexBison](https://github.com/lexxmark/winflexbison/releases)
- [MSYS2](https://www.msys2.org/)
- [Visual Studio Code](https://code.visualstudio.com/)

## Настройка Windows

### 1. Установка Flex и Bison

Скачайте [WinFlexBison](https://github.com/lexxmark/winflexbison/releases), распакуйте архив и добавьте путь к папке с `win_flex.exe` и `win_bison.exe` в переменную среды `Path`.

Проверьте установку в PowerShell:

```powershell
win_flex --version
win_bison --version
```

### 2. Установка GCC и G++

Установите [MSYS2](https://www.msys2.org/), откройте терминал **MSYS2 UCRT64** и выполните:

```bash
pacman -Syu
pacman -S --needed mingw-w64-ucrt-x86_64-gcc make
```

Добавьте папку `ucrt64\bin` из каталога установки MSYS2 в переменную среды `Path`. Проверьте установку:

```powershell
g++ --version
```

### 3. Visual Studio Code

Установите [Visual Studio Code](https://code.visualstudio.com/) и расширение `C/C++`. Откройте корневую папку проекта.

## Структура проекта

```text
compiler/
├── lexer/
│   └── lexer.l
├── parser/
│   └── pars.y
├── ast/
│   ├── class_nodes.h
│   └── class_nodes.cpp
├── tests/
│   └── test.adb
└── README.md
```

## Как запустить через терминал

Откройте PowerShell в корневой папке проекта, где находятся каталоги `lexer`, `parser`, `ast` и `tests`.

**1. Сгенерируйте парсер:**

```powershell
win_bison -d -o pars.tab.c parser/pars.y
```

**2. Сгенерируйте лексер:**

```powershell
win_flex -o lex.yy.c lexer/lexer.l
```

**3. Скомпилируйте проект:**

```powershell
g++ -std=c++11 -Iast -x c++ pars.tab.c -x c++ lex.yy.c ast/class_nodes.cpp -o compiler.exe -lm
```

**4. Запустите на тестовом файле:**

```powershell
.\compiler.exe tests/test.adb
```

Для запуска на другом файле укажите путь к нему вместо `tests/test.adb`.

После изменения `lexer/lexer.l` или `parser/pars.y` повторите шаги 1–4.

