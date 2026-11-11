/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "parser/pars.y"

#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <string>
#include <list>
#include "class_nodes.h"
#include "ast_extensions.h"

void yyerror(char const* s);
extern int yylex(void);

ProgramNode* global_program = nullptr;

/* Создаёт объявление пользовательского типа и прикрепляет его определение. */
static DeclarationNode* make_type_declaration(
    string* name,
    TypeDefinitionNode* definition,
    RangeNode* range = nullptr,
    TypeNode* base_type = nullptr
) {
    DeclarationNode* result = DeclarationNode::TypeDeclaration(
        DeclarationNode::type_dec, name, range, base_type
    );
    result->definition = definition;
    return result;
}

/* Объединяет два списка операторов, корректно обрабатывая пустые списки. */
static StmtListNode* append_statement_lists(
    StmtListNode* first,
    StmtListNode* second
) {
    if (!first) return second;
    if (!second) return first;
    if (second->stmts) {
        for (auto* statement : *second->stmts)
            first->stmts->push_back(statement);
    }
    return first;
}

#line 114 "pars.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "pars.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 4,                    /* BOOLEAN  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHARACTER = 6,                  /* CHARACTER  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IN = 10,                        /* IN  */
  YYSYMBOL_OF = 11,                        /* OF  */
  YYSYMBOL_LOOP = 12,                      /* LOOP  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_THEN = 14,                      /* THEN  */
  YYSYMBOL_ELSIF = 15,                     /* ELSIF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_ASSIGNMENT = 17,                /* ASSIGNMENT  */
  YYSYMBOL_ARRAY = 18,                     /* ARRAY  */
  YYSYMBOL_TYPE = 19,                      /* TYPE  */
  YYSYMBOL_ID = 20,                        /* ID  */
  YYSYMBOL_CONST_STRING = 21,              /* CONST_STRING  */
  YYSYMBOL_CONST_INTEGER = 22,             /* CONST_INTEGER  */
  YYSYMBOL_CONST_FLOAT = 23,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHARACTER = 24,           /* CONST_CHARACTER  */
  YYSYMBOL_CONST_BOOL = 25,                /* CONST_BOOL  */
  YYSYMBOL_RANGE = 26,                     /* RANGE  */
  YYSYMBOL_EXIT = 27,                      /* EXIT  */
  YYSYMBOL_WHEN = 28,                      /* WHEN  */
  YYSYMBOL_FUNCTION = 29,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 30,                 /* PROCEDURE  */
  YYSYMBOL_IS = 31,                        /* IS  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_BEGIN_TOKEN = 33,               /* BEGIN_TOKEN  */
  YYSYMBOL_END = 34,                       /* END  */
  YYSYMBOL_WITH = 35,                      /* WITH  */
  YYSYMBOL_USE = 36,                       /* USE  */
  YYSYMBOL_RECORD = 37,                    /* RECORD  */
  YYSYMBOL_CONSTANT = 38,                  /* CONSTANT  */
  YYSYMBOL_CASE = 39,                      /* CASE  */
  YYSYMBOL_EXCEPTION = 40,                 /* EXCEPTION  */
  YYSYMBOL_OTHERS = 41,                    /* OTHERS  */
  YYSYMBOL_OUT = 42,                       /* OUT  */
  YYSYMBOL_ARROW = 43,                     /* ARROW  */
  YYSYMBOL_DOUBLE_DOT = 44,                /* DOUBLE_DOT  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_XOR = 46,                       /* XOR  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_ABS = 49,                       /* ABS  */
  YYSYMBOL_MOD = 50,                       /* MOD  */
  YYSYMBOL_REM = 51,                       /* REM  */
  YYSYMBOL_NOT_EQUAL = 52,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 53,             /* LESS_OR_EQUAL  */
  YYSYMBOL_MORE_OR_EQUAL = 54,             /* MORE_OR_EQUAL  */
  YYSYMBOL_55_ = 55,                       /* '='  */
  YYSYMBOL_56_ = 56,                       /* '<'  */
  YYSYMBOL_57_ = 57,                       /* '>'  */
  YYSYMBOL_58_ = 58,                       /* '+'  */
  YYSYMBOL_59_ = 59,                       /* '-'  */
  YYSYMBOL_60_ = 60,                       /* '*'  */
  YYSYMBOL_61_ = 61,                       /* '/'  */
  YYSYMBOL_UMINUS = 62,                    /* UMINUS  */
  YYSYMBOL_63_ = 63,                       /* '.'  */
  YYSYMBOL_64_ = 64,                       /* ';'  */
  YYSYMBOL_65_ = 65,                       /* '('  */
  YYSYMBOL_66_ = 66,                       /* ')'  */
  YYSYMBOL_67_ = 67,                       /* ','  */
  YYSYMBOL_68_ = 68,                       /* ':'  */
  YYSYMBOL_69_ = 69,                       /* '|'  */
  YYSYMBOL_70_ = 70,                       /* '\''  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_program = 72,                   /* program  */
  YYSYMBOL_program_body = 73,              /* program_body  */
  YYSYMBOL_context_list = 74,              /* context_list  */
  YYSYMBOL_context_item = 75,              /* context_item  */
  YYSYMBOL_dotted_name = 76,               /* dotted_name  */
  YYSYMBOL_item_list = 77,                 /* item_list  */
  YYSYMBOL_item = 78,                      /* item  */
  YYSYMBOL_func_declaration = 79,          /* func_declaration  */
  YYSYMBOL_proc_declaration = 80,          /* proc_declaration  */
  YYSYMBOL_func_implementation = 81,       /* func_implementation  */
  YYSYMBOL_proc_implementation = 82,       /* proc_implementation  */
  YYSYMBOL_declaration_list_empty = 83,    /* declaration_list_empty  */
  YYSYMBOL_decl_body_list = 84,            /* decl_body_list  */
  YYSYMBOL_declaration = 85,               /* declaration  */
  YYSYMBOL_type_declaration = 86,          /* type_declaration  */
  YYSYMBOL_array_type_definition = 87,     /* array_type_definition  */
  YYSYMBOL_array_index_list = 88,          /* array_index_list  */
  YYSYMBOL_array_index = 89,               /* array_index  */
  YYSYMBOL_enum_id_list = 90,              /* enum_id_list  */
  YYSYMBOL_record_field_list = 91,         /* record_field_list  */
  YYSYMBOL_var_declaration = 92,           /* var_declaration  */
  YYSYMBOL_var_list = 93,                  /* var_list  */
  YYSYMBOL_func_param_list = 94,           /* func_param_list  */
  YYSYMBOL_stmt_list_empty = 95,           /* stmt_list_empty  */
  YYSYMBOL_stmt_list = 96,                 /* stmt_list  */
  YYSYMBOL_stmt = 97,                      /* stmt  */
  YYSYMBOL_return_stmt = 98,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 99,                 /* loop_stmt  */
  YYSYMBOL_for_stmt = 100,                 /* for_stmt  */
  YYSYMBOL_while_stmt = 101,               /* while_stmt  */
  YYSYMBOL_simple_loop_stmt = 102,         /* simple_loop_stmt  */
  YYSYMBOL_exit_stmt = 103,                /* exit_stmt  */
  YYSYMBOL_if_stmt = 104,                  /* if_stmt  */
  YYSYMBOL_case_stmt = 105,                /* case_stmt  */
  YYSYMBOL_case_alternative_list = 106,    /* case_alternative_list  */
  YYSYMBOL_case_alternative = 107,         /* case_alternative  */
  YYSYMBOL_exception_part = 108,           /* exception_part  */
  YYSYMBOL_exception_handler_list = 109,   /* exception_handler_list  */
  YYSYMBOL_exception_handler = 110,        /* exception_handler  */
  YYSYMBOL_choice_list = 111,              /* choice_list  */
  YYSYMBOL_case_choice = 112,              /* case_choice  */
  YYSYMBOL_elsif_stmt_list = 113,          /* elsif_stmt_list  */
  YYSYMBOL_elsif_stmt = 114,               /* elsif_stmt  */
  YYSYMBOL_else_stmt = 115,                /* else_stmt  */
  YYSYMBOL_assigment_stmt = 116,           /* assigment_stmt  */
  YYSYMBOL_expression_list_empty = 117,    /* expression_list_empty  */
  YYSYMBOL_expression_list = 118,          /* expression_list  */
  YYSYMBOL_arg = 119,                      /* arg  */
  YYSYMBOL_expression = 120,               /* expression  */
  YYSYMBOL_range = 121,                    /* range  */
  YYSYMBOL_var_type = 122                  /* var_type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   802

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  349

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
      65,    66,    60,    58,    67,    59,    63,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    64,
      56,    55,    57,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   164,   170,   171,   176,   177,   182,   183,
     188,   190,   195,   196,   197,   198,   203,   205,   211,   213,
     219,   222,   229,   232,   239,   240,   246,   248,   250,   252,
     257,   258,   263,   265,   267,   269,   275,   284,   289,   304,
     306,   308,   314,   319,   328,   333,   343,   345,   347,   349,
     351,   353,   355,   364,   370,   371,   376,   377,   383,   384,
     385,   391,   392,   397,   398,   399,   401,   402,   403,   404,
     405,   410,   411,   416,   417,   418,   423,   425,   431,   437,
     443,   444,   449,   451,   457,   464,   466,   472,   479,   485,
     490,   491,   497,   498,   503,   508,   514,   515,   520,   521,
     526,   532,   533,   538,   544,   545,   550,   551,   556,   557,
     569,   570,   571,   572,   573,   574,   576,   578,   580,   582,
     584,   586,   589,   591,   593,   595,   597,   599,   602,   604,
     606,   608,   610,   612,   615,   617,   619,   621,   623,   625,
     628,   630,   632,   638,   649,   655,   656,   657,   658,   659,
     660
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "BOOLEAN",
  "FLOAT", "CHARACTER", "STRING", "WHILE", "FOR", "IN", "OF", "LOOP", "IF",
  "THEN", "ELSIF", "ELSE", "ASSIGNMENT", "ARRAY", "TYPE", "ID",
  "CONST_STRING", "CONST_INTEGER", "CONST_FLOAT", "CONST_CHARACTER",
  "CONST_BOOL", "RANGE", "EXIT", "WHEN", "FUNCTION", "PROCEDURE", "IS",
  "RETURN", "BEGIN_TOKEN", "END", "WITH", "USE", "RECORD", "CONSTANT",
  "CASE", "EXCEPTION", "OTHERS", "OUT", "ARROW", "DOUBLE_DOT", "OR", "XOR",
  "AND", "NOT", "ABS", "MOD", "REM", "NOT_EQUAL", "LESS_OR_EQUAL",
  "MORE_OR_EQUAL", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "'.'", "';'", "'('", "')'", "','", "':'", "'|'", "'\\''",
  "$accept", "program", "program_body", "context_list", "context_item",
  "dotted_name", "item_list", "item", "func_declaration",
  "proc_declaration", "func_implementation", "proc_implementation",
  "declaration_list_empty", "decl_body_list", "declaration",
  "type_declaration", "array_type_definition", "array_index_list",
  "array_index", "enum_id_list", "record_field_list", "var_declaration",
  "var_list", "func_param_list", "stmt_list_empty", "stmt_list", "stmt",
  "return_stmt", "loop_stmt", "for_stmt", "while_stmt", "simple_loop_stmt",
  "exit_stmt", "if_stmt", "case_stmt", "case_alternative_list",
  "case_alternative", "exception_part", "exception_handler_list",
  "exception_handler", "choice_list", "case_choice", "elsif_stmt_list",
  "elsif_stmt", "else_stmt", "assigment_stmt", "expression_list_empty",
  "expression_list", "arg", "expression", "range", "var_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-237)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-151)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -237,    13,   165,  -237,    -1,    29,    36,    36,  -237,  -237,
      11,  -237,  -237,  -237,  -237,  -237,   -18,   -11,  -237,    23,
      97,  -237,   215,    48,   102,  -237,    48,    59,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,    -6,  -237,  -237,   109,
     -34,   104,  -237,    94,   102,    75,  -237,  -237,    51,  -237,
     102,  -237,   124,   160,    48,   114,   117,   301,  -237,    89,
    -237,    -4,   125,  -237,   366,   103,   215,   215,   162,  -237,
     215,    -8,   116,   121,   134,   138,   141,   408,   188,   301,
     408,   174,  -237,  -237,  -237,  -237,  -237,   -13,    71,   408,
     408,   408,   408,   441,   176,   253,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,   580,  -237,   102,  -237,
     301,   215,  -237,   471,   208,  -237,   408,    -3,   169,   408,
      48,   220,  -237,   441,   441,   441,   441,   441,   -48,   506,
     226,   209,   535,  -237,   441,   229,   408,  -237,  -237,   630,
     611,   190,   190,   190,    73,   130,  -237,   710,   247,   240,
    -237,  -237,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   249,   237,
     238,  -237,   116,   121,   134,   138,   141,   -15,   179,  -237,
     651,  -237,   245,   408,   710,   102,  -237,   471,  -237,    63,
     217,  -237,   181,   213,   219,   218,   221,   223,   224,   441,
     301,   408,   270,   301,   225,   230,   670,  -237,   255,   408,
    -237,   441,   232,   168,   240,  -237,   690,   725,   725,   739,
     190,   190,    91,    91,    91,    91,    91,    91,   163,   163,
     190,   190,  -237,   301,   274,   286,   471,   408,   331,   710,
     265,   185,   262,   236,  -237,  -237,   283,  -237,  -237,  -237,
    -237,  -237,   250,   277,   487,   303,   256,   216,   263,   441,
    -237,   378,   100,  -237,   710,  -237,  -237,   276,    21,  -237,
     651,  -237,  -237,  -237,   295,   266,   215,  -237,   710,   260,
    -237,   301,   320,  -237,  -237,  -237,  -237,   327,   301,   301,
    -237,   408,   301,   216,  -237,   298,  -237,   197,   299,    45,
     302,  -237,   301,   301,   408,   323,  -237,  -237,  -237,   310,
     215,   281,   312,   313,   554,  -237,  -237,   314,   344,  -237,
     301,   301,   294,   301,   301,  -237,   297,   339,  -237,  -237,
     350,   351,   301,   352,   300,   301,   301,  -237,  -237,   304,
     311,   324,  -237,   325,  -237,  -237,  -237,  -237,  -237
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     0,     2,     5,
       3,    10,    12,    13,    14,    15,     0,     0,     8,     0,
       0,    11,     0,     0,    24,    19,     0,     0,     6,     7,
     145,   146,   147,   148,   149,   150,     0,    54,    56,     0,
       0,     0,    28,     0,    25,     0,    30,    31,     0,     9,
      24,    17,     0,     0,     0,     0,     0,    58,    29,     0,
      26,     0,     0,    55,     0,     0,     0,     0,    46,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,   115,   112,   113,   114,   111,   110,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    61,    63,    64,    74,
      73,    75,    67,    66,    69,    68,     0,    27,    24,    18,
      58,     0,    47,     0,    50,    48,     0,     0,     0,     0,
       0,     0,    32,   104,   104,   104,   104,   104,   115,     0,
       0,     0,     0,    70,   104,     0,     0,    80,    72,     0,
       0,   133,   128,   129,   115,     0,   106,   108,     0,     0,
      62,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,   145,   146,   147,   148,   149,   115,     0,    37,
       0,    39,     0,     0,    53,    24,    16,     0,    34,     0,
       0,    42,     0,     0,   105,     0,     0,     0,     0,   104,
      58,     0,     0,    58,     0,   141,     0,    71,     0,     0,
     143,     0,     0,     0,    89,    90,     0,   130,   132,   131,
     125,   126,   121,   119,   118,   120,   117,   116,   122,   123,
     124,   127,   140,    58,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,    44,    33,     0,   135,   137,   136,
     138,   139,     0,     0,     0,     0,     0,   101,   134,     0,
      81,     0,     0,    85,   109,   107,    23,     0,     0,    94,
      96,    97,    91,   103,     0,     0,     0,    38,   144,     0,
      41,    58,     0,    35,    45,    43,   134,     0,    58,    58,
      79,     0,    58,   101,    98,     0,    65,     0,     0,     0,
       0,    86,     0,     0,     0,     0,    21,    52,    40,     0,
       0,     0,     0,     0,     0,   102,    99,     0,     0,   142,
       0,     0,     0,    93,    92,    95,     0,     0,    36,    78,
       0,     0,    58,     0,     0,    88,    87,    84,    22,     0,
       0,     0,   100,     0,    83,    20,    77,    76,    82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -237,  -237,  -237,  -237,  -237,   360,  -237,     2,  -237,  -237,
    -237,  -237,   -45,  -237,   330,  -237,  -237,   189,   142,  -237,
    -237,    -2,  -237,   365,   -77,  -236,   -94,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,   115,  -237,  -237,   178,
     132,    90,  -237,   111,   112,  -237,  -118,   -90,   184,   -54,
     -76,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     8,     2,     9,    19,    10,    42,    12,    13,
      14,    15,    43,    44,    45,    46,   122,   178,   179,   192,
     189,    47,    39,    40,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   262,   263,   151,   214,   215,
     268,   269,   293,   294,   295,   105,   193,   194,   146,   106,
     181,   182
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   150,   131,   145,    11,    62,   195,   196,   197,   198,
     118,  -150,    21,     3,    22,   136,   204,   199,   119,    16,
      24,    38,   135,   129,    38,    50,   132,   108,   185,   120,
      54,    68,    55,   170,   139,   140,   141,   142,   143,   147,
       4,     5,   112,   188,   114,   115,    58,    23,   117,    17,
     199,   137,    69,    25,    26,   135,    18,   121,    51,   180,
     109,   186,   184,   169,   303,   180,   323,   324,    37,   147,
     147,   147,   147,   147,    72,    73,    74,    75,    76,    49,
     147,   252,   206,    37,   335,   336,    27,    28,   321,   171,
     304,   128,    82,    83,    84,    85,    86,   242,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   304,    54,   209,    61,   190,    90,
      91,    41,    37,   253,    56,   255,   257,    57,   261,   239,
      92,     4,     5,   180,   300,   138,    93,   271,   199,    60,
     240,   156,   157,   135,    63,   147,    70,   254,    71,   164,
     165,   166,   167,   107,   168,   264,   274,   147,   110,   270,
      27,    29,   280,    30,    31,    32,    33,    34,   113,   297,
      64,    72,    73,    74,    75,    76,    52,    53,    65,   116,
      35,   123,   180,   278,   180,   271,   124,   243,   128,    82,
      83,    84,    85,    86,     4,     5,   210,   211,    66,   125,
       6,     7,    67,   126,   309,   147,   127,   270,   130,   267,
     148,   312,   313,   156,   157,   315,    90,    91,    30,    31,
      32,    33,    34,   166,   167,   183,   168,    92,   271,   150,
     150,   291,   292,    93,   187,    35,   201,   314,   133,   134,
     191,   150,   150,   202,   135,   235,   236,   245,   246,   205,
     270,   282,   236,   168,   307,   342,    72,    73,    74,    75,
      76,    77,    78,   319,   211,    79,    80,   212,   213,   232,
     233,   238,   234,    81,    82,    83,    84,    85,    86,   247,
      87,   244,   256,   261,   248,    88,   211,   249,   328,   250,
     251,   258,    89,   149,   275,   259,   266,   276,   281,   283,
     284,    90,    91,   285,    72,    73,    74,    75,    76,    77,
      78,   287,    92,    79,    80,   289,   286,   308,    93,   302,
     290,    81,    82,    83,    84,    85,    86,   296,    87,   305,
     306,   310,   318,    88,    72,    73,    74,    75,    76,   311,
      89,   322,   320,   326,   327,   329,   330,   331,   333,    90,
      91,   128,    82,    83,    84,    85,    86,   334,   337,   339,
      92,   338,   340,   341,   344,   343,    93,    20,   345,    30,
      31,    32,    33,    34,    59,   346,   241,   301,   277,    90,
      91,    72,    73,    74,    75,    76,    35,   279,   347,   348,
      92,    48,   272,   299,   325,   265,    93,     0,   128,    82,
      83,    84,    85,    86,   316,   317,     0,     0,   111,     0,
       0,    72,    73,    74,    75,    76,     0,     0,     0,   298,
       0,     0,     0,     0,     0,     0,    90,    91,   128,    82,
      83,    84,    85,    86,     0,     0,     0,    92,     0,     0,
       0,     0,     0,    93,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,     0,
       0,   144,    82,    83,    84,    85,    86,    92,     0,     0,
       0,     0,     0,    93,   172,   173,   174,   175,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,   177,    82,    83,    84,    85,    86,     0,     0,   288,
      92,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,   237,   153,   154,   155,     0,    93,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   203,
     168,   153,   154,   155,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   332,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   155,     0,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   152,   168,   153,
     154,   155,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,   168,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   208,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   168,   153,   154,   155,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   168,   207,   237,   153,   154,   155,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,   168,   153,   154,   155,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   168,   260,   153,   154,   155,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   168,   273,   153,   154,   155,     0,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   155,   168,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     0,   168,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,     0,   168
};

static const yytype_int16 yycheck[] =
{
      22,    95,    79,    93,     2,    50,   124,   125,   126,   127,
      18,    26,    10,     0,    32,    28,   134,    65,    26,    20,
      31,    23,    70,    77,    26,    31,    80,    31,    31,    37,
      64,    53,    66,   110,    88,    89,    90,    91,    92,    93,
      29,    30,    64,   119,    66,    67,    44,    65,    70,    20,
      65,    64,    54,    64,    65,    70,    20,    65,    64,   113,
      64,    64,   116,   108,    43,   119,   302,   303,    20,   123,
     124,   125,   126,   127,     3,     4,     5,     6,     7,    20,
     134,   199,   136,    20,   320,   321,    63,    64,    43,   111,
      69,    20,    21,    22,    23,    24,    25,    34,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    69,    64,    43,    66,   120,    48,
      49,    19,    20,   200,    20,   201,   203,    33,    28,   183,
      59,    29,    30,   187,    34,    64,    65,   213,    65,    64,
     185,    50,    51,    70,    20,   199,    32,   201,    31,    58,
      59,    60,    61,    64,    63,   209,   233,   211,    33,   213,
      63,    64,   238,     3,     4,     5,     6,     7,    65,   259,
      10,     3,     4,     5,     6,     7,    67,    68,    18,    17,
      20,    65,   236,   237,   238,   261,    65,   189,    20,    21,
      22,    23,    24,    25,    29,    30,    66,    67,    38,    65,
      35,    36,    42,    65,   281,   259,    65,   261,    20,    41,
      34,   288,   289,    50,    51,   292,    48,    49,     3,     4,
       5,     6,     7,    60,    61,    17,    63,    59,   304,   323,
     324,    15,    16,    65,    65,    20,    10,   291,    64,    65,
      20,   335,   336,    34,    70,    66,    67,    66,    67,    20,
     304,    66,    67,    63,   276,   332,     3,     4,     5,     6,
       7,     8,     9,    66,    67,    12,    13,    20,    28,    20,
      33,    26,    34,    20,    21,    22,    23,    24,    25,    66,
      27,    64,    12,    28,    66,    32,    67,    66,   310,    66,
      66,    66,    39,    40,    20,    65,    64,    11,    33,    37,
      64,    48,    49,    20,     3,     4,     5,     6,     7,     8,
       9,    34,    59,    12,    13,    12,    66,    57,    65,    43,
      64,    20,    21,    22,    23,    24,    25,    64,    27,    34,
      64,    11,    34,    32,     3,     4,     5,     6,     7,    12,
      39,    39,    43,    20,    34,    64,    34,    34,    34,    48,
      49,    20,    21,    22,    23,    24,    25,    13,    64,    20,
      59,    64,    12,    12,    64,    13,    65,     7,    64,     3,
       4,     5,     6,     7,    44,    64,   187,   262,   236,    48,
      49,     3,     4,     5,     6,     7,    20,    56,    64,    64,
      59,    26,   214,   261,   304,   211,    65,    -1,    20,    21,
      22,    23,    24,    25,   293,   293,    -1,    -1,    42,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    65,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    59,    -1,    -1,
      -1,    -1,    -1,    65,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    20,    21,    22,    23,    24,    25,    -1,    -1,    12,
      59,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    44,    45,    46,    47,    -1,    65,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    14,
      63,    45,    46,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    14,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    17,    63,    45,
      46,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    31,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    63,    45,    46,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    63,    64,    44,    45,    46,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    63,    45,    46,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    63,    64,    45,    46,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    63,    64,    45,    46,    47,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    47,    63,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    63,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,    74,     0,    29,    30,    35,    36,    73,    75,
      77,    78,    79,    80,    81,    82,    20,    20,    20,    76,
      76,    78,    32,    65,    31,    64,    65,    63,    64,    64,
       3,     4,     5,     6,     7,    20,   122,    20,    92,    93,
      94,    19,    78,    83,    84,    85,    86,    92,    94,    20,
      31,    64,    67,    68,    64,    66,    20,    33,    78,    85,
      64,    66,    83,    20,    10,    18,    38,    42,   122,    92,
      32,    31,     3,     4,     5,     6,     7,     8,     9,    12,
      13,    20,    21,    22,    23,    24,    25,    27,    32,    39,
      48,    49,    59,    65,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   116,   120,    64,    31,    64,
      33,    42,   122,    65,   122,   122,    17,   122,    18,    26,
      37,    65,    87,    65,    65,    65,    65,    65,    20,   120,
      20,    95,   120,    64,    65,    70,    28,    64,    64,   120,
     120,   120,   120,   120,    20,   118,   119,   120,    34,    40,
      97,   108,    17,    45,    46,    47,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    63,    83,
      95,   122,     3,     4,     5,     6,     7,    20,    88,    89,
     120,   121,   122,    17,   120,    31,    64,    65,   121,    91,
      92,    20,    90,   117,   118,   117,   117,   117,   117,    65,
      12,    10,    34,    14,   117,    20,   120,    64,    31,    43,
      66,    67,    20,    28,   109,   110,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,    20,    33,    34,    66,    67,    44,    26,   120,
      83,    88,    34,    92,    64,    66,    67,    66,    66,    66,
      66,    66,   117,    95,   120,   121,    12,    95,    66,    65,
      64,    28,   106,   107,   120,   119,    64,    41,   111,   112,
     120,   121,   110,    64,    95,    20,    11,    89,   120,    56,
     121,    33,    66,    37,    64,    20,    66,    34,    12,    12,
      64,    15,    16,   113,   114,   115,    64,   118,    41,   111,
      34,   107,    43,    43,    69,    34,    64,   122,    57,    95,
      11,    12,    95,    95,   120,    95,   114,   115,    34,    66,
      43,    43,    39,    96,    96,   112,    20,    34,   122,    64,
      34,    34,    14,    34,    13,    96,    96,    64,    64,    20,
      12,    12,    95,    13,    64,    64,    64,    64,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    84,    84,
      85,    85,    86,    86,    86,    86,    87,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    95,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    99,    99,    99,   100,   100,   101,   102,
     103,   103,   104,   104,   105,   106,   106,   107,   107,   108,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   115,   115,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   122,   122,   122,   122,   122,
     122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     3,     3,     1,     3,
       1,     2,     1,     1,     1,     1,     8,     5,     6,     3,
      14,    11,    12,     9,     0,     1,     2,     3,     1,     2,
       1,     1,     4,     6,     5,     7,     6,     1,     3,     1,
       4,     3,     1,     3,     2,     3,     3,     4,     4,     5,
       4,     6,     8,     5,     1,     3,     1,     3,     0,     1,
       2,     1,     2,     1,     1,     5,     1,     1,     1,     1,
       2,     3,     2,     1,     1,     1,     9,     9,     7,     5,
       2,     4,     9,     8,     7,     1,     2,     4,     4,     2,
       1,     2,     4,     4,     1,     3,     1,     1,     1,     2,
       4,     0,     2,     4,     0,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     2,     4,     4,     4,     4,     4,     4,
       3,     3,     6,     3,     3,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 113 "parser/pars.y"
         { fprintf(yyo, "%s", ((*yyvaluep).id_const) ? ((*yyvaluep).id_const)->c_str() : "null"); }
#line 1173 "pars.tab.cpp"
        break;

    case YYSYMBOL_CONST_STRING: /* CONST_STRING  */
#line 113 "parser/pars.y"
         { fprintf(yyo, "%s", ((*yyvaluep).string_const) ? ((*yyvaluep).string_const)->c_str() : "null"); }
#line 1179 "pars.tab.cpp"
        break;

    case YYSYMBOL_CONST_INTEGER: /* CONST_INTEGER  */
#line 114 "parser/pars.y"
         { fprintf(yyo, "%d", ((*yyvaluep).int_const)); }
#line 1185 "pars.tab.cpp"
        break;

    case YYSYMBOL_CONST_FLOAT: /* CONST_FLOAT  */
#line 115 "parser/pars.y"
         { fprintf(yyo, "%f", ((*yyvaluep).float_const)); }
#line 1191 "pars.tab.cpp"
        break;

    case YYSYMBOL_CONST_CHARACTER: /* CONST_CHARACTER  */
#line 116 "parser/pars.y"
         { fprintf(yyo, "%c", ((*yyvaluep).char_const)); }
#line 1197 "pars.tab.cpp"
        break;

    case YYSYMBOL_CONST_BOOL: /* CONST_BOOL  */
#line 114 "parser/pars.y"
         { fprintf(yyo, "%d", ((*yyvaluep).int_const)); }
#line 1203 "pars.tab.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: context_list program_body  */
#line 159 "parser/pars.y"
      { (yyval.prg) = global_program = (yyvsp[0].prg); }
#line 1593 "pars.tab.cpp"
    break;

  case 3: /* program_body: item_list  */
#line 165 "parser/pars.y"
      { (yyval.prg) = new ProgramNode((yyvsp[0].itemlst)); }
#line 1599 "pars.tab.cpp"
    break;

  case 10: /* item_list: item  */
#line 189 "parser/pars.y"
      { (yyval.itemlst) = new ItemListNode((yyvsp[0].item)); }
#line 1605 "pars.tab.cpp"
    break;

  case 11: /* item_list: item_list item  */
#line 191 "parser/pars.y"
      { (yyval.itemlst) = ItemListNode::Append((yyvsp[-1].itemlst), (yyvsp[0].item)); }
#line 1611 "pars.tab.cpp"
    break;

  case 12: /* item: func_declaration  */
#line 195 "parser/pars.y"
                             { (yyval.item) = (yyvsp[0].item); }
#line 1617 "pars.tab.cpp"
    break;

  case 13: /* item: proc_declaration  */
#line 196 "parser/pars.y"
                             { (yyval.item) = (yyvsp[0].item); }
#line 1623 "pars.tab.cpp"
    break;

  case 14: /* item: func_implementation  */
#line 197 "parser/pars.y"
                             { (yyval.item) = (yyvsp[0].item); }
#line 1629 "pars.tab.cpp"
    break;

  case 15: /* item: proc_implementation  */
#line 198 "parser/pars.y"
                            { (yyval.item) = (yyvsp[0].item); }
#line 1635 "pars.tab.cpp"
    break;

  case 16: /* func_declaration: FUNCTION ID '(' func_param_list ')' RETURN var_type ';'  */
#line 204 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-6].id_const), (yyvsp[-4].param_lst), (yyvsp[-1].v_type), NULL, NULL); }
#line 1641 "pars.tab.cpp"
    break;

  case 17: /* func_declaration: FUNCTION ID RETURN var_type ';'  */
#line 206 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-3].id_const), NULL, (yyvsp[-1].v_type), NULL, NULL); }
#line 1647 "pars.tab.cpp"
    break;

  case 18: /* proc_declaration: PROCEDURE ID '(' func_param_list ')' ';'  */
#line 212 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-4].id_const), (yyvsp[-2].param_lst), NULL, NULL, NULL); }
#line 1653 "pars.tab.cpp"
    break;

  case 19: /* proc_declaration: PROCEDURE ID ';'  */
#line 214 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-1].id_const), NULL, NULL, NULL, NULL); }
#line 1659 "pars.tab.cpp"
    break;

  case 20: /* func_implementation: FUNCTION ID '(' func_param_list ')' RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 221 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-12].id_const), (yyvsp[-10].param_lst), (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst)); }
#line 1665 "pars.tab.cpp"
    break;

  case 21: /* func_implementation: FUNCTION ID RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 224 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-9].id_const), NULL, (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst)); }
#line 1671 "pars.tab.cpp"
    break;

  case 22: /* proc_implementation: PROCEDURE ID '(' func_param_list ')' IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 231 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-10].id_const), (yyvsp[-8].param_lst), NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst)); }
#line 1677 "pars.tab.cpp"
    break;

  case 23: /* proc_implementation: PROCEDURE ID IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 234 "parser/pars.y"
      { (yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-7].id_const), NULL, NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst)); }
#line 1683 "pars.tab.cpp"
    break;

  case 24: /* declaration_list_empty: %empty  */
#line 239 "parser/pars.y"
             { (yyval.decl_lst) = nullptr; }
#line 1689 "pars.tab.cpp"
    break;

  case 25: /* declaration_list_empty: decl_body_list  */
#line 240 "parser/pars.y"
                     { (yyval.decl_lst) = (yyvsp[0].decl_lst); }
#line 1695 "pars.tab.cpp"
    break;

  case 26: /* decl_body_list: declaration ';'  */
#line 247 "parser/pars.y"
      { (yyval.decl_lst) = new DeclarationListNode((yyvsp[-1].decl)); }
#line 1701 "pars.tab.cpp"
    break;

  case 27: /* decl_body_list: decl_body_list declaration ';'  */
#line 249 "parser/pars.y"
      { (yyval.decl_lst) = DeclarationListNode::Append((yyvsp[-2].decl_lst), (yyvsp[-1].decl)); }
#line 1707 "pars.tab.cpp"
    break;

  case 28: /* decl_body_list: item  */
#line 251 "parser/pars.y"
      { (yyval.decl_lst) = new DeclarationListNode(DeclarationNode::SubProgramDeclaration((yyvsp[0].item))); }
#line 1713 "pars.tab.cpp"
    break;

  case 29: /* decl_body_list: decl_body_list item  */
#line 253 "parser/pars.y"
      { (yyval.decl_lst) = DeclarationListNode::Append((yyvsp[-1].decl_lst), DeclarationNode::SubProgramDeclaration((yyvsp[0].item))); }
#line 1719 "pars.tab.cpp"
    break;

  case 30: /* declaration: type_declaration  */
#line 257 "parser/pars.y"
                       { (yyval.decl) = (yyvsp[0].decl); }
#line 1725 "pars.tab.cpp"
    break;

  case 31: /* declaration: var_declaration  */
#line 258 "parser/pars.y"
                       { (yyval.decl) = (yyvsp[0].decl); }
#line 1731 "pars.tab.cpp"
    break;

  case 32: /* type_declaration: TYPE ID IS array_type_definition  */
#line 264 "parser/pars.y"
      { (yyval.decl) = make_type_declaration((yyvsp[-2].id_const), (yyvsp[0].type_definition)); }
#line 1737 "pars.tab.cpp"
    break;

  case 33: /* type_declaration: TYPE ID IS '(' enum_id_list ')'  */
#line 266 "parser/pars.y"
      { (yyval.decl) = make_type_declaration((yyvsp[-4].id_const), (yyvsp[-1].type_definition)); }
#line 1743 "pars.tab.cpp"
    break;

  case 34: /* type_declaration: TYPE ID IS RANGE range  */
#line 268 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::TypeDeclaration(DeclarationNode::type_dec, (yyvsp[-3].id_const), (yyvsp[0].rng), nullptr); }
#line 1749 "pars.tab.cpp"
    break;

  case 35: /* type_declaration: TYPE ID IS RECORD record_field_list END RECORD  */
#line 270 "parser/pars.y"
      { (yyval.decl) = make_type_declaration((yyvsp[-5].id_const), (yyvsp[-2].type_definition)); }
#line 1755 "pars.tab.cpp"
    break;

  case 36: /* array_type_definition: ARRAY '(' array_index_list ')' OF var_type  */
#line 276 "parser/pars.y"
      {
          (yyval.type_definition) = (yyvsp[-3].type_definition);
          (yyval.type_definition)->element_type = (yyvsp[0].v_type);
      }
#line 1764 "pars.tab.cpp"
    break;

  case 37: /* array_index_list: array_index  */
#line 285 "parser/pars.y"
      {
          (yyval.type_definition) = new TypeDefinitionNode(TypeDefinitionNode::array_type);
          (yyval.type_definition)->addIndex((yyvsp[0].array_index));
      }
#line 1773 "pars.tab.cpp"
    break;

  case 38: /* array_index_list: array_index_list ',' array_index  */
#line 290 "parser/pars.y"
      {
          (yyval.type_definition) = (yyvsp[-2].type_definition);
          (yyval.type_definition)->addIndex((yyvsp[0].array_index));
      }
#line 1782 "pars.tab.cpp"
    break;

  case 39: /* array_index: range  */
#line 305 "parser/pars.y"
      { (yyval.array_index) = new ArrayIndexNode((yyvsp[0].rng), nullptr, false); }
#line 1788 "pars.tab.cpp"
    break;

  case 40: /* array_index: var_type RANGE '<' '>'  */
#line 307 "parser/pars.y"
      { (yyval.array_index) = new ArrayIndexNode(nullptr, (yyvsp[-3].v_type), true); }
#line 1794 "pars.tab.cpp"
    break;

  case 41: /* array_index: var_type RANGE range  */
#line 309 "parser/pars.y"
      { (yyval.array_index) = new ArrayIndexNode((yyvsp[0].rng), (yyvsp[-2].v_type), false); }
#line 1800 "pars.tab.cpp"
    break;

  case 42: /* enum_id_list: ID  */
#line 315 "parser/pars.y"
      {
          (yyval.type_definition) = new TypeDefinitionNode(TypeDefinitionNode::enum_type);
          (yyval.type_definition)->addLiteral((yyvsp[0].id_const));
      }
#line 1809 "pars.tab.cpp"
    break;

  case 43: /* enum_id_list: enum_id_list ',' ID  */
#line 320 "parser/pars.y"
      {
          (yyval.type_definition) = (yyvsp[-2].type_definition);
          (yyval.type_definition)->addLiteral((yyvsp[0].id_const));
      }
#line 1818 "pars.tab.cpp"
    break;

  case 44: /* record_field_list: var_declaration ';'  */
#line 329 "parser/pars.y"
      {
          (yyval.type_definition) = new TypeDefinitionNode(TypeDefinitionNode::record_type);
          (yyval.type_definition)->addField((yyvsp[-1].decl));
      }
#line 1827 "pars.tab.cpp"
    break;

  case 45: /* record_field_list: record_field_list var_declaration ';'  */
#line 334 "parser/pars.y"
      {
          (yyval.type_definition) = (yyvsp[-2].type_definition);
          (yyval.type_definition)->addField((yyvsp[-1].decl));
      }
#line 1836 "pars.tab.cpp"
    break;

  case 46: /* var_declaration: var_list ':' var_type  */
#line 344 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, (yyvsp[-2].var_lst), (yyvsp[0].v_type)); }
#line 1842 "pars.tab.cpp"
    break;

  case 47: /* var_declaration: var_list ':' IN var_type  */
#line 346 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, (yyvsp[-3].var_lst), (yyvsp[0].v_type)); }
#line 1848 "pars.tab.cpp"
    break;

  case 48: /* var_declaration: var_list ':' OUT var_type  */
#line 348 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, (yyvsp[-3].var_lst), (yyvsp[0].v_type)); }
#line 1854 "pars.tab.cpp"
    break;

  case 49: /* var_declaration: var_list ':' IN OUT var_type  */
#line 350 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, (yyvsp[-4].var_lst), (yyvsp[0].v_type)); }
#line 1860 "pars.tab.cpp"
    break;

  case 50: /* var_declaration: var_list ':' CONSTANT var_type  */
#line 352 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, (yyvsp[-3].var_lst), (yyvsp[0].v_type)); }
#line 1866 "pars.tab.cpp"
    break;

  case 51: /* var_declaration: var_list ':' CONSTANT var_type ASSIGNMENT expression  */
#line 354 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::VarDeclarationAssignment(DeclarationNode::var_dec, (yyvsp[-5].var_lst), (yyvsp[-2].v_type), (yyvsp[0].expr)); }
#line 1872 "pars.tab.cpp"
    break;

  case 52: /* var_declaration: var_list ':' ARRAY '(' array_index_list ')' OF var_type  */
#line 356 "parser/pars.y"
      {
          DeclarationNode* declaration = DeclarationNode::VarDeclaration(
              DeclarationNode::var_dec, (yyvsp[-7].var_lst), (yyvsp[0].v_type)
          );
          declaration->definition = (yyvsp[-3].type_definition);
          declaration->definition->element_type = (yyvsp[0].v_type);
          (yyval.decl) = declaration;
      }
#line 1885 "pars.tab.cpp"
    break;

  case 53: /* var_declaration: var_list ':' var_type ASSIGNMENT expression  */
#line 365 "parser/pars.y"
      { (yyval.decl) = DeclarationNode::VarDeclarationAssignment(DeclarationNode::var_dec, (yyvsp[-4].var_lst), (yyvsp[-2].v_type), (yyvsp[0].expr)); }
#line 1891 "pars.tab.cpp"
    break;

  case 54: /* var_list: ID  */
#line 370 "parser/pars.y"
         { (yyval.var_lst) = new VarListNode((yyvsp[0].id_const)); }
#line 1897 "pars.tab.cpp"
    break;

  case 55: /* var_list: var_list ',' ID  */
#line 371 "parser/pars.y"
                      { (yyval.var_lst) = VarListNode::Append((yyvsp[-2].var_lst), (yyvsp[0].id_const)); }
#line 1903 "pars.tab.cpp"
    break;

  case 56: /* func_param_list: var_declaration  */
#line 376 "parser/pars.y"
                      { (yyval.param_lst) = new FuncParamListNode((yyvsp[0].decl)); }
#line 1909 "pars.tab.cpp"
    break;

  case 57: /* func_param_list: func_param_list ';' var_declaration  */
#line 377 "parser/pars.y"
                                          { (yyval.param_lst) = FuncParamListNode::Append((yyvsp[-2].param_lst), (yyvsp[0].decl)); }
#line 1915 "pars.tab.cpp"
    break;

  case 58: /* stmt_list_empty: %empty  */
#line 383 "parser/pars.y"
             { (yyval.stmt_lst) = nullptr; }
#line 1921 "pars.tab.cpp"
    break;

  case 59: /* stmt_list_empty: stmt_list  */
#line 384 "parser/pars.y"
                { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 1927 "pars.tab.cpp"
    break;

  case 60: /* stmt_list_empty: stmt_list exception_part  */
#line 386 "parser/pars.y"
      { (yyval.stmt_lst) = append_statement_lists((yyvsp[-1].stmt_lst), (yyvsp[0].stmt_lst)); }
#line 1933 "pars.tab.cpp"
    break;

  case 61: /* stmt_list: stmt  */
#line 391 "parser/pars.y"
           { (yyval.stmt_lst) = new StmtListNode((yyvsp[0].stmt)); }
#line 1939 "pars.tab.cpp"
    break;

  case 62: /* stmt_list: stmt_list stmt  */
#line 392 "parser/pars.y"
                     { (yyval.stmt_lst) = StmtListNode::Append((yyvsp[-1].stmt_lst), (yyvsp[0].stmt)); }
#line 1945 "pars.tab.cpp"
    break;

  case 63: /* stmt: return_stmt  */
#line 397 "parser/pars.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1951 "pars.tab.cpp"
    break;

  case 64: /* stmt: loop_stmt  */
#line 398 "parser/pars.y"
                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1957 "pars.tab.cpp"
    break;

  case 65: /* stmt: ID '(' expression_list_empty ')' ';'  */
#line 400 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromIdAndExpr((yyvsp[-4].id_const), (yyvsp[-2].expr_list)); }
#line 1963 "pars.tab.cpp"
    break;

  case 66: /* stmt: if_stmt  */
#line 401 "parser/pars.y"
              { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1969 "pars.tab.cpp"
    break;

  case 67: /* stmt: exit_stmt  */
#line 402 "parser/pars.y"
                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1975 "pars.tab.cpp"
    break;

  case 68: /* stmt: assigment_stmt  */
#line 403 "parser/pars.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1981 "pars.tab.cpp"
    break;

  case 69: /* stmt: case_stmt  */
#line 404 "parser/pars.y"
                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1987 "pars.tab.cpp"
    break;

  case 70: /* stmt: ID ';'  */
#line 405 "parser/pars.y"
             { (yyval.stmt) = StmtNode::StmtFromIdAndExpr((yyvsp[-1].id_const), nullptr); }
#line 1993 "pars.tab.cpp"
    break;

  case 71: /* return_stmt: RETURN expression ';'  */
#line 410 "parser/pars.y"
                            { (yyval.stmt) = StmtNode::StmtFromReturn((yyvsp[-1].expr)); }
#line 1999 "pars.tab.cpp"
    break;

  case 72: /* return_stmt: RETURN ';'  */
#line 411 "parser/pars.y"
                 { (yyval.stmt) = StmtNode::StmtFromReturn(nullptr); }
#line 2005 "pars.tab.cpp"
    break;

  case 73: /* loop_stmt: while_stmt  */
#line 416 "parser/pars.y"
                 { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2011 "pars.tab.cpp"
    break;

  case 74: /* loop_stmt: for_stmt  */
#line 417 "parser/pars.y"
               { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2017 "pars.tab.cpp"
    break;

  case 75: /* loop_stmt: simple_loop_stmt  */
#line 418 "parser/pars.y"
                       { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2023 "pars.tab.cpp"
    break;

  case 76: /* for_stmt: FOR ID IN range LOOP stmt_list_empty END LOOP ';'  */
#line 424 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromForLoop((yyvsp[-7].id_const), (yyvsp[-5].rng), (yyvsp[-3].stmt_lst)); }
#line 2029 "pars.tab.cpp"
    break;

  case 77: /* for_stmt: FOR ID IN expression LOOP stmt_list_empty END LOOP ';'  */
#line 426 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromForLoop((yyvsp[-7].id_const), nullptr, (yyvsp[-3].stmt_lst)); }
#line 2035 "pars.tab.cpp"
    break;

  case 78: /* while_stmt: WHILE expression LOOP stmt_list_empty END LOOP ';'  */
#line 432 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromWhileLoop((yyvsp[-5].expr), (yyvsp[-3].stmt_lst)); }
#line 2041 "pars.tab.cpp"
    break;

  case 79: /* simple_loop_stmt: LOOP stmt_list_empty END LOOP ';'  */
#line 438 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromSimpleLoop((yyvsp[-3].stmt_lst)); }
#line 2047 "pars.tab.cpp"
    break;

  case 80: /* exit_stmt: EXIT ';'  */
#line 443 "parser/pars.y"
               { (yyval.stmt) = StmtNode::StmtFromExit(nullptr); }
#line 2053 "pars.tab.cpp"
    break;

  case 81: /* exit_stmt: EXIT WHEN expression ';'  */
#line 444 "parser/pars.y"
                               { (yyval.stmt) = StmtNode::StmtFromExit((yyvsp[-1].expr)); }
#line 2059 "pars.tab.cpp"
    break;

  case 82: /* if_stmt: IF expression THEN stmt_list_empty elsif_stmt_list else_stmt END IF ';'  */
#line 450 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromIfWithElsif((yyvsp[-7].expr), (yyvsp[-5].stmt_lst), (yyvsp[-4].elsf_lst_stmt), (yyvsp[-3].els_stmt)); }
#line 2065 "pars.tab.cpp"
    break;

  case 83: /* if_stmt: IF expression THEN stmt_list_empty else_stmt END IF ';'  */
#line 452 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromIf((yyvsp[-6].expr), (yyvsp[-4].stmt_lst), (yyvsp[-3].els_stmt)); }
#line 2071 "pars.tab.cpp"
    break;

  case 84: /* case_stmt: CASE expression IS case_alternative_list END CASE ';'  */
#line 458 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromCase((yyvsp[-5].expr), (yyvsp[-3].case_alternative_list)); }
#line 2077 "pars.tab.cpp"
    break;

  case 85: /* case_alternative_list: case_alternative  */
#line 465 "parser/pars.y"
      { (yyval.case_alternative_list) = new CaseAlternativeListNode((yyvsp[0].case_alternative)); }
#line 2083 "pars.tab.cpp"
    break;

  case 86: /* case_alternative_list: case_alternative_list case_alternative  */
#line 467 "parser/pars.y"
      { (yyval.case_alternative_list) = (yyvsp[-1].case_alternative_list); (yyval.case_alternative_list)->add((yyvsp[0].case_alternative)); }
#line 2089 "pars.tab.cpp"
    break;

  case 87: /* case_alternative: WHEN choice_list ARROW stmt_list  */
#line 473 "parser/pars.y"
      {
          auto it = (yyvsp[-2].choice_list)->begin();
          (yyval.case_alternative) = new CaseAlternativeNode(*it, (yyvsp[0].stmt_lst));
          for (++it; it != (yyvsp[-2].choice_list)->end(); ++it)
              (yyval.case_alternative)->addChoice(*it);
      }
#line 2100 "pars.tab.cpp"
    break;

  case 88: /* case_alternative: WHEN OTHERS ARROW stmt_list  */
#line 480 "parser/pars.y"
      { (yyval.case_alternative) = new CaseAlternativeNode(new CaseChoiceNode(true), (yyvsp[0].stmt_lst)); }
#line 2106 "pars.tab.cpp"
    break;

  case 89: /* exception_part: EXCEPTION exception_handler_list  */
#line 485 "parser/pars.y"
                                       { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 2112 "pars.tab.cpp"
    break;

  case 90: /* exception_handler_list: exception_handler  */
#line 490 "parser/pars.y"
                        { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 2118 "pars.tab.cpp"
    break;

  case 91: /* exception_handler_list: exception_handler_list exception_handler  */
#line 492 "parser/pars.y"
      { (yyval.stmt_lst) = append_statement_lists((yyvsp[-1].stmt_lst), (yyvsp[0].stmt_lst)); }
#line 2124 "pars.tab.cpp"
    break;

  case 92: /* exception_handler: WHEN choice_list ARROW stmt_list  */
#line 497 "parser/pars.y"
                                       { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 2130 "pars.tab.cpp"
    break;

  case 93: /* exception_handler: WHEN OTHERS ARROW stmt_list  */
#line 498 "parser/pars.y"
                                  { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 2136 "pars.tab.cpp"
    break;

  case 94: /* choice_list: case_choice  */
#line 504 "parser/pars.y"
      {
          (yyval.choice_list) = new list<CaseChoiceNode*>();
          (yyval.choice_list)->push_back((yyvsp[0].case_choice));
      }
#line 2145 "pars.tab.cpp"
    break;

  case 95: /* choice_list: choice_list '|' case_choice  */
#line 509 "parser/pars.y"
      { (yyval.choice_list) = (yyvsp[-2].choice_list); (yyval.choice_list)->push_back((yyvsp[0].case_choice)); }
#line 2151 "pars.tab.cpp"
    break;

  case 96: /* case_choice: expression  */
#line 514 "parser/pars.y"
                 { (yyval.case_choice) = new CaseChoiceNode((yyvsp[0].expr)); }
#line 2157 "pars.tab.cpp"
    break;

  case 97: /* case_choice: range  */
#line 515 "parser/pars.y"
            { (yyval.case_choice) = new CaseChoiceNode((yyvsp[0].rng)); }
#line 2163 "pars.tab.cpp"
    break;

  case 98: /* elsif_stmt_list: elsif_stmt  */
#line 520 "parser/pars.y"
                 { (yyval.elsf_lst_stmt) = new ElsifStmtListNode((yyvsp[0].elsf_stmt)); }
#line 2169 "pars.tab.cpp"
    break;

  case 99: /* elsif_stmt_list: elsif_stmt_list elsif_stmt  */
#line 521 "parser/pars.y"
                                 { (yyval.elsf_lst_stmt) = ElsifStmtListNode::Append((yyvsp[-1].elsf_lst_stmt), (yyvsp[0].elsf_stmt)); }
#line 2175 "pars.tab.cpp"
    break;

  case 100: /* elsif_stmt: ELSIF expression THEN stmt_list_empty  */
#line 527 "parser/pars.y"
      { (yyval.elsf_stmt) = new ElsifStmtNode((yyvsp[-2].expr), (yyvsp[0].stmt_lst)); }
#line 2181 "pars.tab.cpp"
    break;

  case 101: /* else_stmt: %empty  */
#line 532 "parser/pars.y"
             { (yyval.els_stmt) = nullptr; }
#line 2187 "pars.tab.cpp"
    break;

  case 102: /* else_stmt: ELSE stmt_list_empty  */
#line 533 "parser/pars.y"
                           { (yyval.els_stmt) = new ElseStmtNode((yyvsp[0].stmt_lst)); }
#line 2193 "pars.tab.cpp"
    break;

  case 103: /* assigment_stmt: expression ASSIGNMENT expression ';'  */
#line 539 "parser/pars.y"
      { (yyval.stmt) = StmtNode::StmtFromAssigment((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2199 "pars.tab.cpp"
    break;

  case 104: /* expression_list_empty: %empty  */
#line 544 "parser/pars.y"
             { (yyval.expr_list) = nullptr; }
#line 2205 "pars.tab.cpp"
    break;

  case 105: /* expression_list_empty: expression_list  */
#line 545 "parser/pars.y"
                      { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr_list)); }
#line 2211 "pars.tab.cpp"
    break;

  case 106: /* expression_list: arg  */
#line 550 "parser/pars.y"
          { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr)); }
#line 2217 "pars.tab.cpp"
    break;

  case 107: /* expression_list: expression_list ',' arg  */
#line 551 "parser/pars.y"
                              { (yyval.expr_list) = ExprListNode::Append((yyvsp[-2].expr_list), (yyvsp[0].expr)); }
#line 2223 "pars.tab.cpp"
    break;

  case 108: /* arg: expression  */
#line 556 "parser/pars.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2229 "pars.tab.cpp"
    break;

  case 109: /* arg: ID ARROW expression  */
#line 558 "parser/pars.y"
      {
          (yyval.expr) = ExprNode::ExprOperation(
              ExprNode::expr_equal_expr,
              ExprNode::ExprFromId(ExprNode::id_, (yyvsp[-2].id_const)), (yyvsp[0].expr)
          );
      }
#line 2240 "pars.tab.cpp"
    break;

  case 110: /* expression: CONST_BOOL  */
#line 569 "parser/pars.y"
                 { (yyval.expr) = ExprNode::ExprFromBoolConst(ExprNode::const_bool, (yyvsp[0].int_const)); }
#line 2246 "pars.tab.cpp"
    break;

  case 111: /* expression: CONST_CHARACTER  */
#line 570 "parser/pars.y"
                      { (yyval.expr) = ExprNode::ExprFromCharConst(ExprNode::const_character, (yyvsp[0].char_const)); }
#line 2252 "pars.tab.cpp"
    break;

  case 112: /* expression: CONST_STRING  */
#line 571 "parser/pars.y"
                   { (yyval.expr) = ExprNode::ExprFromStringConst(ExprNode::const_string, (yyvsp[0].string_const)); }
#line 2258 "pars.tab.cpp"
    break;

  case 113: /* expression: CONST_INTEGER  */
#line 572 "parser/pars.y"
                    { (yyval.expr) = ExprNode::ExprFromIntConst(ExprNode::const_integer, (yyvsp[0].int_const)); }
#line 2264 "pars.tab.cpp"
    break;

  case 114: /* expression: CONST_FLOAT  */
#line 573 "parser/pars.y"
                  { (yyval.expr) = ExprNode::ExprFromFloatConst(ExprNode::const_float, (yyvsp[0].float_const)); }
#line 2270 "pars.tab.cpp"
    break;

  case 115: /* expression: ID  */
#line 574 "parser/pars.y"
         { (yyval.expr) = ExprNode::ExprFromId(ExprNode::id_, (yyvsp[0].id_const)); }
#line 2276 "pars.tab.cpp"
    break;

  case 116: /* expression: expression '>' expression  */
#line 577 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_more_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2282 "pars.tab.cpp"
    break;

  case 117: /* expression: expression '<' expression  */
#line 579 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_less_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2288 "pars.tab.cpp"
    break;

  case 118: /* expression: expression MORE_OR_EQUAL expression  */
#line 581 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_more_equal_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2294 "pars.tab.cpp"
    break;

  case 119: /* expression: expression LESS_OR_EQUAL expression  */
#line 583 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_less_equal_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2300 "pars.tab.cpp"
    break;

  case 120: /* expression: expression '=' expression  */
#line 585 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_equal_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2306 "pars.tab.cpp"
    break;

  case 121: /* expression: expression NOT_EQUAL expression  */
#line 587 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_not_equal_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2312 "pars.tab.cpp"
    break;

  case 122: /* expression: expression '+' expression  */
#line 590 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_plus_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2318 "pars.tab.cpp"
    break;

  case 123: /* expression: expression '-' expression  */
#line 592 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_minus_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2324 "pars.tab.cpp"
    break;

  case 124: /* expression: expression '*' expression  */
#line 594 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_mult_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2330 "pars.tab.cpp"
    break;

  case 125: /* expression: expression MOD expression  */
#line 596 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_mod_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2336 "pars.tab.cpp"
    break;

  case 126: /* expression: expression REM expression  */
#line 598 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_rem_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2342 "pars.tab.cpp"
    break;

  case 127: /* expression: expression '/' expression  */
#line 600 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_div_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2348 "pars.tab.cpp"
    break;

  case 128: /* expression: ABS expression  */
#line 603 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_abs_expr, (yyvsp[0].expr), nullptr); }
#line 2354 "pars.tab.cpp"
    break;

  case 129: /* expression: '-' expression  */
#line 605 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::uminus_expr, (yyvsp[0].expr), nullptr); }
#line 2360 "pars.tab.cpp"
    break;

  case 130: /* expression: expression OR expression  */
#line 607 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_or_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2366 "pars.tab.cpp"
    break;

  case 131: /* expression: expression AND expression  */
#line 609 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_and_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2372 "pars.tab.cpp"
    break;

  case 132: /* expression: expression XOR expression  */
#line 611 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::expr_xor_expr, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2378 "pars.tab.cpp"
    break;

  case 133: /* expression: NOT expression  */
#line 613 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprOperation(ExprNode::not_expr, (yyvsp[0].expr), nullptr); }
#line 2384 "pars.tab.cpp"
    break;

  case 134: /* expression: ID '(' expression_list_empty ')'  */
#line 616 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromFuncCall(ExprNode::func_call, (yyvsp[-3].id_const), (yyvsp[-1].expr_list)); }
#line 2390 "pars.tab.cpp"
    break;

  case 135: /* expression: INTEGER '(' expression_list_empty ')'  */
#line 618 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Integer"), (yyvsp[-1].expr_list)); }
#line 2396 "pars.tab.cpp"
    break;

  case 136: /* expression: FLOAT '(' expression_list_empty ')'  */
#line 620 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Float"), (yyvsp[-1].expr_list)); }
#line 2402 "pars.tab.cpp"
    break;

  case 137: /* expression: BOOLEAN '(' expression_list_empty ')'  */
#line 622 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Boolean"), (yyvsp[-1].expr_list)); }
#line 2408 "pars.tab.cpp"
    break;

  case 138: /* expression: CHARACTER '(' expression_list_empty ')'  */
#line 624 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Character"), (yyvsp[-1].expr_list)); }
#line 2414 "pars.tab.cpp"
    break;

  case 139: /* expression: STRING '(' expression_list_empty ')'  */
#line 626 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("String"), (yyvsp[-1].expr_list)); }
#line 2420 "pars.tab.cpp"
    break;

  case 140: /* expression: expression '.' ID  */
#line 629 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromFuncCall(ExprNode::func_call, (yyvsp[0].id_const), new ExprListNode((yyvsp[-2].expr))); }
#line 2426 "pars.tab.cpp"
    break;

  case 141: /* expression: ID '\'' ID  */
#line 631 "parser/pars.y"
      { (yyval.expr) = ExprNode::ExprFromId(ExprNode::id_, (yyvsp[-2].id_const)); }
#line 2432 "pars.tab.cpp"
    break;

  case 142: /* expression: ID '\'' ID '(' expression_list ')'  */
#line 633 "parser/pars.y"
      {
          (yyval.expr) = ExprNode::ExprFromFuncCall(
              ExprNode::func_call, new string(*(yyvsp[-5].id_const) + "'" + *(yyvsp[-3].id_const)), (yyvsp[-1].expr_list)
          );
      }
#line 2442 "pars.tab.cpp"
    break;

  case 143: /* expression: '(' expression_list ')'  */
#line 639 "parser/pars.y"
      {
          if ((yyvsp[-1].expr_list) && (yyvsp[-1].expr_list)->exprs->size() == 1)
              (yyval.expr) = (yyvsp[-1].expr_list)->exprs->front();
          else
              (yyval.expr) = ExprNode::ExprFromExprLiteral(ExprNode::literal, (yyvsp[-1].expr_list));
      }
#line 2453 "pars.tab.cpp"
    break;

  case 144: /* range: expression DOUBLE_DOT expression  */
#line 650 "parser/pars.y"
      { (yyval.rng) = new RangeNode((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2459 "pars.tab.cpp"
    break;

  case 145: /* var_type: INTEGER  */
#line 655 "parser/pars.y"
              { (yyval.v_type) = new TypeNode(TypeNode::const_integer); }
#line 2465 "pars.tab.cpp"
    break;

  case 146: /* var_type: BOOLEAN  */
#line 656 "parser/pars.y"
              { (yyval.v_type) = new TypeNode(TypeNode::const_bool); }
#line 2471 "pars.tab.cpp"
    break;

  case 147: /* var_type: FLOAT  */
#line 657 "parser/pars.y"
            { (yyval.v_type) = new TypeNode(TypeNode::const_float); }
#line 2477 "pars.tab.cpp"
    break;

  case 148: /* var_type: CHARACTER  */
#line 658 "parser/pars.y"
                { (yyval.v_type) = new TypeNode(TypeNode::const_character); }
#line 2483 "pars.tab.cpp"
    break;

  case 149: /* var_type: STRING  */
#line 659 "parser/pars.y"
             { (yyval.v_type) = new TypeNode(TypeNode::const_string); }
#line 2489 "pars.tab.cpp"
    break;

  case 150: /* var_type: ID  */
#line 660 "parser/pars.y"
         { (yyval.v_type) = new TypeNode(TypeNode::id_, (yyvsp[0].id_const)); }
#line 2495 "pars.tab.cpp"
    break;


#line 2499 "pars.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 663 "parser/pars.y"
