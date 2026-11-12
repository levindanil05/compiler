/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARS_TAB_HPP_INCLUDED
# define YY_YY_PARS_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "parser/pars.y"

#include <string>
#include <list>
#include "class_nodes.h"
#include "ast_extensions.h"
using namespace std;

#line 57 "pars.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    BOOLEAN = 259,                 /* BOOLEAN  */
    FLOAT = 260,                   /* FLOAT  */
    CHARACTER = 261,               /* CHARACTER  */
    STRING = 262,                  /* STRING  */
    WHILE = 263,                   /* WHILE  */
    FOR = 264,                     /* FOR  */
    IN = 265,                      /* IN  */
    OF = 266,                      /* OF  */
    LOOP = 267,                    /* LOOP  */
    IF = 268,                      /* IF  */
    THEN = 269,                    /* THEN  */
    ELSIF = 270,                   /* ELSIF  */
    ELSE = 271,                    /* ELSE  */
    ASSIGNMENT = 272,              /* ASSIGNMENT  */
    ARRAY = 273,                   /* ARRAY  */
    TYPE = 274,                    /* TYPE  */
    ID = 275,                      /* ID  */
    CONST_STRING = 276,            /* CONST_STRING  */
    CONST_INTEGER = 277,           /* CONST_INTEGER  */
    CONST_FLOAT = 278,             /* CONST_FLOAT  */
    CONST_CHARACTER = 279,         /* CONST_CHARACTER  */
    CONST_BOOL = 280,              /* CONST_BOOL  */
    RANGE = 281,                   /* RANGE  */
    EXIT = 282,                    /* EXIT  */
    WHEN = 283,                    /* WHEN  */
    FUNCTION = 284,                /* FUNCTION  */
    PROCEDURE = 285,               /* PROCEDURE  */
    IS = 286,                      /* IS  */
    RETURN = 287,                  /* RETURN  */
    BEGIN_TOKEN = 288,             /* BEGIN_TOKEN  */
    END = 289,                     /* END  */
    WITH = 290,                    /* WITH  */
    USE = 291,                     /* USE  */
    RECORD = 292,                  /* RECORD  */
    CONSTANT = 293,                /* CONSTANT  */
    CASE = 294,                    /* CASE  */
    EXCEPTION = 295,               /* EXCEPTION  */
    OTHERS = 296,                  /* OTHERS  */
    OUT = 297,                     /* OUT  */
    ARROW = 298,                   /* ARROW  */
    DOUBLE_DOT = 299,              /* DOUBLE_DOT  */
    OR = 300,                      /* OR  */
    XOR = 301,                     /* XOR  */
    AND = 302,                     /* AND  */
    NOT = 303,                     /* NOT  */
    ABS = 304,                     /* ABS  */
    MOD = 305,                     /* MOD  */
    REM = 306,                     /* REM  */
    NOT_EQUAL = 307,               /* NOT_EQUAL  */
    LESS_OR_EQUAL = 308,           /* LESS_OR_EQUAL  */
    MORE_OR_EQUAL = 309,           /* MORE_OR_EQUAL  */
    UMINUS = 310                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 81 "parser/pars.y"

    ProgramNode* prg;
    int int_const;
    float float_const;
    string* string_const;
    string* id_const;
    char char_const;

    SubProgramItemNode* item;
    ItemListNode* itemlst;
    DeclarationListNode* decl_lst;
    DeclarationNode* decl;
    VarListNode* var_lst;
    FuncParamListNode* param_lst;
    StmtListNode* stmt_lst;
    StmtNode* stmt;
    ElseStmtNode* els_stmt;
    ElsifStmtNode* elsf_stmt;
    ElsifStmtListNode* elsf_lst_stmt;
    ExprNode* expr;
    ExprListNode* expr_list;
    RangeNode* rng;
    TypeNode* v_type;

    TypeDefinitionNode* type_definition;
    ArrayIndexNode* array_index;
    CaseChoiceNode* case_choice;
    CaseAlternativeNode* case_alternative;
    CaseAlternativeListNode* case_alternative_list;
    list<CaseChoiceNode*>* choice_list;

#line 161 "pars.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARS_TAB_HPP_INCLUDED  */
