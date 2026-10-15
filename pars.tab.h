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

#ifndef YY_YY_PARS_TAB_H_INCLUDED
# define YY_YY_PARS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "pars.y"

#include <string>
#include <list>
#include "class_nodes.h"
using namespace std;

#line 56 "pars.tab.h"

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
    OR = 273,                      /* OR  */
    AND = 274,                     /* AND  */
    XOR = 275,                     /* XOR  */
    NOT_EQUAL = 276,               /* NOT_EQUAL  */
    LESS_OR_EQUAL = 277,           /* LESS_OR_EQUAL  */
    MORE_OR_EQUAL = 278,           /* MORE_OR_EQUAL  */
    ABS = 279,                     /* ABS  */
    NOT = 280,                     /* NOT  */
    UMINUS = 281,                  /* UMINUS  */
    ARRAY = 282,                   /* ARRAY  */
    TYPE = 283,                    /* TYPE  */
    ID = 284,                      /* ID  */
    CONST_STRING = 285,            /* CONST_STRING  */
    CONST_INTEGER = 286,           /* CONST_INTEGER  */
    CONST_FLOAT = 287,             /* CONST_FLOAT  */
    CONST_CHARACTER = 288,         /* CONST_CHARACTER  */
    CONST_BOOL = 289,              /* CONST_BOOL  */
    RANGE = 290,                   /* RANGE  */
    EXIT = 291,                    /* EXIT  */
    WHEN = 292,                    /* WHEN  */
    FUNCTION = 293,                /* FUNCTION  */
    PROCEDURE = 294,               /* PROCEDURE  */
    IS = 295,                      /* IS  */
    RETURN = 296,                  /* RETURN  */
    BEGIN_TOKEN = 297,             /* BEGIN_TOKEN  */
    END = 298,                     /* END  */
    DOUBLE_DOT = 299,              /* DOUBLE_DOT  */
    WITH = 300,                    /* WITH  */
    USE = 301,                     /* USE  */
    RECORD = 302,                  /* RECORD  */
    CONSTANT = 303,                /* CONSTANT  */
    CASE = 304,                    /* CASE  */
    EXCEPTION = 305,               /* EXCEPTION  */
    OTHERS = 306,                  /* OTHERS  */
    OUT = 307,                     /* OUT  */
    MOD = 308,                     /* MOD  */
    REM = 309,                     /* REM  */
    ARROW = 310                    /* ARROW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "pars.y"
 

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

#line 157 "pars.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARS_TAB_H_INCLUDED  */
