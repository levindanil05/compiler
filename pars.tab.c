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
#line 8 "pars.y"

#include <stdio.h>
#include <stdlib.h>
#include "class_nodes.h"

void yyerror(char const* s);
extern int yylex(void);
ProgramNode* global_program;

#line 81 "pars.tab.c"

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

#include "pars.tab.h"
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
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_XOR = 20,                       /* XOR  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_NOT_EQUAL = 22,                 /* NOT_EQUAL  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_LESS_OR_EQUAL = 24,             /* LESS_OR_EQUAL  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_MORE_OR_EQUAL = 26,             /* MORE_OR_EQUAL  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_ABS = 32,                       /* ABS  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_ARRAY = 37,                     /* ARRAY  */
  YYSYMBOL_TYPE = 38,                      /* TYPE  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_CONST_STRING = 40,              /* CONST_STRING  */
  YYSYMBOL_CONST_INTEGER = 41,             /* CONST_INTEGER  */
  YYSYMBOL_CONST_FLOAT = 42,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHARACTER = 43,           /* CONST_CHARACTER  */
  YYSYMBOL_CONST_BOOL = 44,                /* CONST_BOOL  */
  YYSYMBOL_RANGE = 45,                     /* RANGE  */
  YYSYMBOL_EXIT = 46,                      /* EXIT  */
  YYSYMBOL_WHEN = 47,                      /* WHEN  */
  YYSYMBOL_FUNCTION = 48,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 49,                 /* PROCEDURE  */
  YYSYMBOL_IS = 50,                        /* IS  */
  YYSYMBOL_RETURN = 51,                    /* RETURN  */
  YYSYMBOL_BEGIN_TOKEN = 52,               /* BEGIN_TOKEN  */
  YYSYMBOL_END = 53,                       /* END  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_DOUBLE_DOT = 55,                /* DOUBLE_DOT  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_WITH = 58,                      /* WITH  */
  YYSYMBOL_USE = 59,                       /* USE  */
  YYSYMBOL_RECORD = 60,                    /* RECORD  */
  YYSYMBOL_CONSTANT = 61,                  /* CONSTANT  */
  YYSYMBOL_CASE = 62,                      /* CASE  */
  YYSYMBOL_EXCEPTION = 63,                 /* EXCEPTION  */
  YYSYMBOL_OTHERS = 64,                    /* OTHERS  */
  YYSYMBOL_OUT = 65,                       /* OUT  */
  YYSYMBOL_MOD = 66,                       /* MOD  */
  YYSYMBOL_REM = 67,                       /* REM  */
  YYSYMBOL_ARROW = 68,                     /* ARROW  */
  YYSYMBOL_69_ = 69,                       /* '.'  */
  YYSYMBOL_70_ = 70,                       /* '|'  */
  YYSYMBOL_71_ = 71,                       /* '\''  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_program = 73,                   /* program  */
  YYSYMBOL_program_body = 74,              /* program_body  */
  YYSYMBOL_context_list = 75,              /* context_list  */
  YYSYMBOL_context_item = 76,              /* context_item  */
  YYSYMBOL_dotted_name = 77,               /* dotted_name  */
  YYSYMBOL_item_list = 78,                 /* item_list  */
  YYSYMBOL_item = 79,                      /* item  */
  YYSYMBOL_func_declaration = 80,          /* func_declaration  */
  YYSYMBOL_proc_declaration = 81,          /* proc_declaration  */
  YYSYMBOL_func_implementation = 82,       /* func_implementation  */
  YYSYMBOL_proc_implementation = 83,       /* proc_implementation  */
  YYSYMBOL_declaration_list_empty = 84,    /* declaration_list_empty  */
  YYSYMBOL_decl_body_list = 85,            /* decl_body_list  */
  YYSYMBOL_declaration = 86,               /* declaration  */
  YYSYMBOL_type_declaration = 87,          /* type_declaration  */
  YYSYMBOL_array_index_list = 88,          /* array_index_list  */
  YYSYMBOL_enum_id_list = 89,              /* enum_id_list  */
  YYSYMBOL_record_field_list = 90,         /* record_field_list  */
  YYSYMBOL_var_declaration = 91,           /* var_declaration  */
  YYSYMBOL_var_list = 92,                  /* var_list  */
  YYSYMBOL_func_param_list = 93,           /* func_param_list  */
  YYSYMBOL_stmt_list_empty = 94,           /* stmt_list_empty  */
  YYSYMBOL_stmt_list = 95,                 /* stmt_list  */
  YYSYMBOL_stmt = 96,                      /* stmt  */
  YYSYMBOL_return_stmt = 97,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 98,                 /* loop_stmt  */
  YYSYMBOL_for_stmt = 99,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 100,               /* while_stmt  */
  YYSYMBOL_simple_loop_stmt = 101,         /* simple_loop_stmt  */
  YYSYMBOL_exit_stmt = 102,                /* exit_stmt  */
  YYSYMBOL_if_stmt = 103,                  /* if_stmt  */
  YYSYMBOL_case_stmt = 104,                /* case_stmt  */
  YYSYMBOL_case_alternative_list = 105,    /* case_alternative_list  */
  YYSYMBOL_case_alternative = 106,         /* case_alternative  */
  YYSYMBOL_exception_part = 107,           /* exception_part  */
  YYSYMBOL_exception_handler_list = 108,   /* exception_handler_list  */
  YYSYMBOL_exception_handler = 109,        /* exception_handler  */
  YYSYMBOL_choice_list = 110,              /* choice_list  */
  YYSYMBOL_elsif_stmt_list = 111,          /* elsif_stmt_list  */
  YYSYMBOL_elsif_stmt = 112,               /* elsif_stmt  */
  YYSYMBOL_else_stmt = 113,                /* else_stmt  */
  YYSYMBOL_assigment_stmt = 114,           /* assigment_stmt  */
  YYSYMBOL_expression_list_empty = 115,    /* expression_list_empty  */
  YYSYMBOL_expression_list = 116,          /* expression_list  */
  YYSYMBOL_arg = 117,                      /* arg  */
  YYSYMBOL_expression = 118,               /* expression  */
  YYSYMBOL_range = 119,                    /* range  */
  YYSYMBOL_var_type = 120                  /* var_type  */
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
#define YYLAST   777

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  337

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
       2,     2,     2,     2,     2,     2,     2,     2,    29,    71,
      35,    36,    30,    27,    54,    28,    69,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    57,
      23,    21,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    70,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    24,    26,    32,
      33,    34,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   162,   162,   166,   169,   171,   175,   176,   180,   181,
     185,   186,   189,   190,   191,   192,   196,   197,   200,   201,
     204,   205,   208,   209,   214,   215,   219,   220,   221,   222,
     225,   226,   231,   233,   235,   237,   242,   243,   244,   248,
     249,   253,   254,   259,   261,   263,   265,   267,   269,   271,
     273,   278,   279,   282,   283,   290,   291,   292,   295,   296,
     299,   300,   301,   302,   303,   304,   305,   306,   309,   310,
     313,   314,   315,   319,   321,   325,   328,   331,   332,   335,
     336,   340,   345,   346,   350,   351,   355,   359,   360,   364,
     365,   369,   370,   371,   372,   375,   376,   379,   382,   383,
     386,   389,   390,   394,   395,   399,   400,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   440,   443,   444,   445,   446,   447,   448
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
  "THEN", "ELSIF", "ELSE", "ASSIGNMENT", "OR", "AND", "XOR", "'='",
  "NOT_EQUAL", "'<'", "LESS_OR_EQUAL", "'>'", "MORE_OR_EQUAL", "'+'",
  "'-'", "'&'", "'*'", "'/'", "ABS", "NOT", "UMINUS", "'('", "')'",
  "ARRAY", "TYPE", "ID", "CONST_STRING", "CONST_INTEGER", "CONST_FLOAT",
  "CONST_CHARACTER", "CONST_BOOL", "RANGE", "EXIT", "WHEN", "FUNCTION",
  "PROCEDURE", "IS", "RETURN", "BEGIN_TOKEN", "END", "','", "DOUBLE_DOT",
  "':'", "';'", "WITH", "USE", "RECORD", "CONSTANT", "CASE", "EXCEPTION",
  "OTHERS", "OUT", "MOD", "REM", "ARROW", "'.'", "'|'", "'\\''", "$accept",
  "program", "program_body", "context_list", "context_item", "dotted_name",
  "item_list", "item", "func_declaration", "proc_declaration",
  "func_implementation", "proc_implementation", "declaration_list_empty",
  "decl_body_list", "declaration", "type_declaration", "array_index_list",
  "enum_id_list", "record_field_list", "var_declaration", "var_list",
  "func_param_list", "stmt_list_empty", "stmt_list", "stmt", "return_stmt",
  "loop_stmt", "for_stmt", "while_stmt", "simple_loop_stmt", "exit_stmt",
  "if_stmt", "case_stmt", "case_alternative_list", "case_alternative",
  "exception_part", "exception_handler_list", "exception_handler",
  "choice_list", "elsif_stmt_list", "elsif_stmt", "else_stmt",
  "assigment_stmt", "expression_list_empty", "expression_list", "arg",
  "expression", "range", "var_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,    16,   101,   -99,    -1,    22,    69,    69,   -99,   -99,
      80,   -99,   -99,   -99,   -99,   -99,    74,    64,   -99,     5,
      44,   -99,    81,    27,    81,   161,   -99,   -99,   109,   -99,
     -99,   -99,   116,     6,   -99,   -99,   -99,   -99,   -99,   -99,
      61,     8,   112,   -99,   131,   161,    48,   -99,   -99,   -99,
     122,    65,   142,    81,   161,   -99,    66,   152,   134,   -99,
     151,   -99,   -99,   129,   177,    27,    27,   210,    27,   -99,
     183,   161,   -99,   147,   194,   202,   203,   208,   209,   716,
     207,   134,   716,   716,   716,   733,   -12,   -99,   -99,   -99,
     -99,   -99,    53,   468,   716,   195,   301,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   252,   -99,    27,
     -99,   716,   232,   -99,   716,    95,   134,   199,   214,   219,
     716,    81,   733,   733,   733,   733,   733,   -17,   364,   245,
     215,   418,   198,   198,    25,   -11,   -99,   663,   733,   -99,
     246,   716,   -99,   -99,   511,   563,   247,   241,   -99,   -99,
     716,   716,   716,   716,   716,   716,   716,   716,   716,   716,
     716,   716,   716,   716,   716,   716,   716,   250,   -99,   254,
     496,   -99,   716,   663,   161,   -99,   238,   134,   -99,     3,
     716,   578,   -99,   105,   236,   260,   243,   275,   276,   279,
     280,   733,   134,   716,   283,   134,   716,   -99,   733,   281,
     285,   596,   -99,   277,   265,   217,   241,   -99,   648,   676,
     676,   676,   159,   159,   159,   159,   159,   159,   173,   173,
      97,    97,    97,   198,   198,   -99,   314,   716,   716,   663,
     274,   288,   278,   -99,   289,   294,   272,   282,   -99,   -99,
     -99,   -99,   -99,   -99,   297,   284,   347,   323,   291,   140,
     663,   -99,   292,   733,   -99,   259,     0,   -99,   -99,   270,
     143,   578,   -99,   -99,   -99,    27,   663,   663,   134,   293,
     307,   -99,   340,   -99,   -99,   -99,   341,   134,   134,   -99,
     716,   134,   140,   -99,   302,   -99,    19,   286,   166,   295,
     -99,   134,   134,   716,   -99,   303,   -99,   304,    27,   305,
     327,   328,   433,   -99,   -99,   344,   345,   -99,   134,   134,
     336,   134,   134,   578,   -99,   321,   -99,   -99,   -99,   386,
     387,   134,   388,   343,   134,   134,   -99,   346,   348,   349,
     -99,   350,   -99,   -99,   -99,   -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     0,     2,     5,
       3,    10,    12,    13,    14,    15,     0,     0,     8,     0,
       0,    11,     0,     0,     0,    24,    19,     6,     0,     7,
      51,    53,     0,     0,   142,   143,   144,   145,   146,   147,
       0,     0,     0,    27,     0,    25,     0,    30,    31,     9,
       0,     0,     0,     0,    24,    17,     0,     0,    55,    29,
       0,    26,    52,     0,     0,     0,     0,    43,     0,    54,
       0,    24,    18,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,   112,   109,   110,   111,
     108,   107,     0,     0,     0,     0,    56,    58,    60,    61,
      71,    70,    72,    64,    63,    66,    65,     0,    28,     0,
      44,     0,    47,    45,     0,     0,    55,     0,     0,     0,
       0,     0,   101,   101,   101,   101,   101,   112,     0,     0,
       0,     0,   126,   130,   112,     0,   103,   105,   101,    67,
       0,     0,    77,    69,     0,     0,     0,     0,    59,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      36,    37,     0,    50,    24,    16,     0,    55,    39,     0,
       0,     0,    34,     0,     0,     0,   102,     0,     0,     0,
       0,   101,    55,     0,     0,    55,     0,   140,     0,     0,
     138,     0,    68,     0,     0,     0,    86,    87,     0,   127,
     128,   129,   117,   118,   114,   116,   113,   115,   119,   120,
     121,   124,   125,   122,   123,   137,     0,     0,     0,    48,
       0,     0,     0,    33,     0,     0,     0,     0,    41,   132,
     134,   133,   135,   136,     0,     0,     0,     0,     0,    98,
     106,   104,   131,     0,    78,     0,     0,    82,    23,     0,
       0,    91,    92,    88,   100,     0,    38,   141,    55,     0,
       0,    40,     0,    35,    42,   131,     0,    55,    55,    76,
       0,    55,    98,    95,     0,    62,     0,     0,     0,     0,
      83,     0,     0,     0,    49,     0,    21,     0,     0,     0,
       0,     0,     0,    99,    96,     0,     0,   139,     0,     0,
       0,    90,    89,    93,    94,     0,    22,    32,    75,     0,
       0,    55,     0,     0,    85,    84,    81,     0,     0,     0,
      97,     0,    80,    20,    74,    73,    79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -99,   397,   -99,    11,   -99,   -99,
     -99,   -99,   -47,   -99,   363,   -99,   229,   -99,   -99,   -18,
     -99,   391,   -80,   -76,   -94,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   154,   -99,   -99,   205,   157,   -99,
     135,   136,   -99,   -97,   -82,   221,   -74,   -98,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     8,     2,     9,    19,    10,    43,    12,    13,
      14,    15,    44,    45,    46,    47,   169,   179,   183,    48,
      32,    33,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   256,   257,   149,   206,   207,   260,   282,
     283,   284,   106,   185,   186,   136,   107,   171,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   130,   148,   135,    31,   128,    31,    70,   131,   132,
     133,   137,   110,    11,   112,   113,     3,   115,   191,   144,
     145,    21,   182,   138,   117,   197,   187,   188,   189,   190,
      34,    35,    36,    37,    38,    69,   176,   170,    16,   233,
     173,   199,    52,   198,    56,   139,   181,   255,   137,   137,
     137,   137,   137,   289,   140,   307,    59,   234,   168,   140,
     191,    17,    27,    53,   137,    53,    39,   201,    34,    35,
      36,    37,    38,   198,    28,    63,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   196,   244,   247,   140,   232,   229,    24,
     141,    29,    64,   184,    39,    61,   170,   262,    18,    22,
     142,    54,   245,    28,    25,   249,    71,   137,    55,   246,
      30,    26,   250,    72,   137,    23,    65,   230,     4,     5,
      66,   261,    34,    35,    36,    37,    38,    74,    75,    76,
      77,    78,    79,    80,    30,   174,    81,    82,    49,     4,
       5,    57,   175,   266,   267,   280,   281,   262,   236,     6,
       7,    62,    83,   165,   166,   237,   167,    84,    39,    85,
      50,   286,    51,    86,    87,    88,    89,    90,    91,   137,
      92,   261,   118,    58,   119,    93,   160,   161,   295,   162,
     163,   164,   120,    68,   109,   314,    94,   300,   301,    42,
      30,   303,    73,   162,   163,   164,   302,   121,   108,     4,
       5,   292,   111,   293,   294,   311,   312,   148,   148,   313,
      74,    75,    76,    77,    78,   165,   166,   114,   167,   122,
     148,   148,   324,   325,   309,   116,   293,   123,   124,   165,
     166,   330,   167,   125,   126,    83,   129,   317,   146,   172,
      84,   177,    85,   178,   180,   193,   127,    87,    88,    89,
      90,    91,    74,    75,    76,    77,    78,   167,   194,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   259,   162,   163,   164,   200,   204,    83,   205,   225,
     226,   231,    84,   238,    85,   248,   239,   198,   127,    87,
      88,    89,    90,    91,    74,    75,    76,    77,    78,    79,
      80,   240,   241,    81,    82,   242,   243,   252,   165,   166,
     253,   167,   258,   287,   255,   265,   268,   269,   271,    83,
     272,   270,   273,   275,    84,   278,    85,   276,   291,   274,
      86,    87,    88,    89,    90,    91,   297,    92,   279,   285,
     296,   298,    93,   299,   308,   306,   315,   310,   323,   277,
     327,   316,   318,    94,   147,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   192,   162,   163,   164,
     319,   320,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   326,   162,   163,   164,   322,   328,   329,
     332,   331,   228,   333,    20,   334,   335,   336,    60,   235,
     290,   263,   288,   165,   166,    41,   167,   304,   305,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   195,   167,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   321,   162,   163,
     164,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,   162,   163,   164,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,   165,
     166,    84,   167,    85,     0,     0,     0,   127,    87,    88,
      89,    90,    91,     0,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   143,   162,   163,   164,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,   162,   163,   164,     0,     0,     0,     0,     0,     0,
     227,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,     0,   167,     0,     0,   202,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,     0,
     167,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,   162,   163,   164,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,   162,   163,
     164,     0,     0,   203,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,   162,   163,   164,   165,
     166,     0,   167,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,     0,   167,     0,     0,
       0,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,     0,   167,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,   162,   163,
     164,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,   162,   163,   164,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   264,   162,   163,   164,     0,
       0,     0,     0,     0,   165,   166,     0,   167,     0,    74,
      75,    76,    77,    78,     0,     0,     0,     0,     0,   165,
     166,     0,   167,     0,     0,     0,    74,    75,    76,    77,
      78,     0,   165,   166,    83,   167,     0,     0,     0,    84,
       0,    85,     0,     0,     0,   127,    87,    88,    89,    90,
      91,    83,     0,     0,     0,     0,    84,     0,    85,     0,
       0,     0,   134,    87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      51,    81,    96,    85,    22,    79,    24,    54,    82,    83,
      84,    85,    63,     2,    65,    66,     0,    68,    35,    93,
      94,    10,   120,    35,    71,    36,   123,   124,   125,   126,
       3,     4,     5,     6,     7,    53,   116,   111,    39,    36,
     114,   138,    36,    54,    36,    57,   120,    47,   122,   123,
     124,   125,   126,    53,    71,    36,    45,    54,   109,    71,
      35,    39,    57,    57,   138,    57,    39,   141,     3,     4,
       5,     6,     7,    54,    69,    10,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    68,   191,   193,    71,   177,   172,    35,
      47,    57,    37,   121,    39,    57,   180,   205,    39,    35,
      57,    50,   192,    69,    50,   195,    50,   191,    57,   193,
      39,    57,   196,    57,   198,    51,    61,   174,    48,    49,
      65,   205,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     8,     9,    39,    50,    12,    13,    39,    48,
      49,    39,    57,   227,   228,    15,    16,   255,    53,    58,
      59,    39,    28,    66,    67,   183,    69,    33,    39,    35,
      54,   253,    56,    39,    40,    41,    42,    43,    44,   253,
      46,   255,    35,    52,    37,    51,    27,    28,   268,    30,
      31,    32,    45,    51,    65,   293,    62,   277,   278,    38,
      39,   281,    50,    30,    31,    32,   280,    60,    57,    48,
      49,    68,    35,    70,   265,   291,   292,   311,   312,   293,
       3,     4,     5,     6,     7,    66,    67,    17,    69,    35,
     324,   325,   308,   309,    68,    52,    70,    35,    35,    66,
      67,   321,    69,    35,    35,    28,    39,   298,    53,    17,
      33,    52,    35,    39,    35,    10,    39,    40,    41,    42,
      43,    44,     3,     4,     5,     6,     7,    69,    53,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    64,    30,    31,    32,    39,    39,    28,    47,    39,
      36,    53,    33,    57,    35,    12,    36,    54,    39,    40,
      41,    42,    43,    44,     3,     4,     5,     6,     7,     8,
       9,    36,    36,    12,    13,    36,    36,    36,    66,    67,
      35,    69,    57,    64,    47,    11,    52,    39,    39,    28,
      36,    53,    60,    36,    33,    12,    35,    53,    68,    57,
      39,    40,    41,    42,    43,    44,    39,    46,    57,    57,
      57,    11,    51,    12,    68,    53,    53,    62,    13,    12,
      39,    57,    57,    62,    63,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    12,    30,    31,    32,
      53,    53,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    57,    30,    31,    32,    53,    12,    12,
      57,    13,    55,    57,     7,    57,    57,    57,    45,   180,
     256,   206,   255,    66,    67,    24,    69,   282,   282,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    14,    69,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    14,    30,    31,
      32,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    66,
      67,    33,    69,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    57,    30,    31,    32,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    69,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    -1,    -1,    50,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    66,
      67,    -1,    69,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    69,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    57,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    69,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    66,    67,    28,    69,    -1,    -1,    -1,    33,
      -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    28,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    73,    75,     0,    48,    49,    58,    59,    74,    76,
      78,    79,    80,    81,    82,    83,    39,    39,    39,    77,
      77,    79,    35,    51,    35,    50,    57,    57,    69,    57,
      39,    91,    92,    93,     3,     4,     5,     6,     7,    39,
     120,    93,    38,    79,    84,    85,    86,    87,    91,    39,
      54,    56,    36,    57,    50,    57,    36,    39,    52,    79,
      86,    57,    39,    10,    37,    61,    65,   120,    51,    91,
      84,    50,    57,    50,     3,     4,     5,     6,     7,     8,
       9,    12,    13,    28,    33,    35,    39,    40,    41,    42,
      43,    44,    46,    51,    62,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   114,   118,    57,    65,
     120,    35,   120,   120,    17,   120,    52,    84,    35,    37,
      45,    60,    35,    35,    35,    35,    35,    39,   118,    39,
      94,   118,   118,   118,    39,   116,   117,   118,    35,    57,
      71,    47,    57,    57,   118,   118,    53,    63,    96,   107,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    30,    31,    32,    66,    67,    69,   120,    88,
     118,   119,    17,   118,    50,    57,    94,    52,    39,    89,
      35,   118,   119,    90,    91,   115,   116,   115,   115,   115,
     115,    35,    12,    10,    53,    14,    68,    36,    54,   115,
      39,   118,    57,    50,    39,    47,   108,   109,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,    39,    36,    54,    55,   118,
      84,    53,    94,    36,    54,    88,    53,    91,    57,    36,
      36,    36,    36,    36,   115,    94,   118,   119,    12,    94,
     118,   117,    36,    35,    57,    47,   105,   106,    57,    64,
     110,   118,   119,   109,    57,    11,   118,   118,    52,    39,
      53,    39,    36,    60,    57,    36,    53,    12,    12,    57,
      15,    16,   111,   112,   113,    57,   116,    64,   110,    53,
     106,    68,    68,    70,   120,    94,    57,    39,    11,    12,
      94,    94,   118,    94,   112,   113,    53,    36,    68,    68,
      62,    95,    95,   118,   119,    53,    57,   120,    57,    53,
      53,    14,    53,    13,    95,    95,    57,    39,    12,    12,
      94,    13,    57,    57,    57,    57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    88,    88,    88,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    98,    98,    99,    99,   100,   101,   102,   102,   103,
     103,   104,   105,   105,   106,   106,   107,   108,   108,   109,
     109,   110,   110,   110,   110,   111,   111,   112,   113,   113,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   120,   120,   120,   120,   120,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     3,     3,     1,     3,
       1,     2,     1,     1,     1,     1,     8,     5,     6,     3,
      14,    11,    12,     9,     0,     1,     2,     1,     3,     2,
       1,     1,     9,     6,     5,     7,     1,     1,     3,     1,
       3,     2,     3,     3,     4,     4,     5,     4,     6,     8,
       5,     1,     3,     1,     3,     0,     1,     2,     1,     2,
       1,     1,     5,     1,     1,     1,     1,     2,     3,     2,
       1,     1,     1,     9,     9,     7,     5,     2,     4,     9,
       8,     7,     1,     2,     4,     4,     2,     1,     2,     4,
       4,     1,     1,     3,     3,     1,     2,     4,     0,     2,
       4,     0,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       2,     4,     4,     4,     4,     4,     4,     3,     3,     6,
       3,     3,     1,     1,     1,     1,     1,     1
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
  YY_USE (yykind);
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
#line 162 "pars.y"
                                  { (yyval.prg) = global_program = (yyvsp[0].prg); }
#line 1503 "pars.tab.c"
    break;

  case 3: /* program_body: item_list  */
#line 166 "pars.y"
                  { (yyval.prg) = new ProgramNode((yyvsp[0].itemlst)); }
#line 1509 "pars.tab.c"
    break;

  case 10: /* item_list: item  */
#line 185 "pars.y"
                 {(yyval.itemlst) = new ItemListNode((yyvsp[0].item));}
#line 1515 "pars.tab.c"
    break;

  case 11: /* item_list: item_list item  */
#line 186 "pars.y"
                           { (yyval.itemlst) = ItemListNode::Append((yyvsp[-1].itemlst), (yyvsp[0].item)); }
#line 1521 "pars.tab.c"
    break;

  case 12: /* item: func_declaration  */
#line 189 "pars.y"
                       {(yyval.item) = (yyvsp[0].item);}
#line 1527 "pars.tab.c"
    break;

  case 13: /* item: proc_declaration  */
#line 190 "pars.y"
                           {(yyval.item) = (yyvsp[0].item);}
#line 1533 "pars.tab.c"
    break;

  case 14: /* item: func_implementation  */
#line 191 "pars.y"
                              {(yyval.item) = (yyvsp[0].item);}
#line 1539 "pars.tab.c"
    break;

  case 15: /* item: proc_implementation  */
#line 192 "pars.y"
                              {(yyval.item) = (yyvsp[0].item);}
#line 1545 "pars.tab.c"
    break;

  case 16: /* func_declaration: FUNCTION ID '(' func_param_list ')' RETURN var_type ';'  */
#line 196 "pars.y"
                                                                          {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-6].id_const), (yyvsp[-4].param_lst), (yyvsp[-1].v_type), NULL, NULL);}
#line 1551 "pars.tab.c"
    break;

  case 17: /* func_declaration: FUNCTION ID RETURN var_type ';'  */
#line 197 "pars.y"
                                                                  {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-3].id_const), NULL, (yyvsp[-1].v_type), NULL, NULL);}
#line 1557 "pars.tab.c"
    break;

  case 18: /* proc_declaration: PROCEDURE ID '(' func_param_list ')' ';'  */
#line 200 "pars.y"
                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-4].id_const), (yyvsp[-2].param_lst), NULL, NULL, NULL);}
#line 1563 "pars.tab.c"
    break;

  case 19: /* proc_declaration: PROCEDURE ID ';'  */
#line 201 "pars.y"
                                                   {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-1].id_const), NULL, NULL, NULL, NULL);}
#line 1569 "pars.tab.c"
    break;

  case 20: /* func_implementation: FUNCTION ID '(' func_param_list ')' RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 204 "pars.y"
                                                                                                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-12].id_const), (yyvsp[-10].param_lst), (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1575 "pars.tab.c"
    break;

  case 21: /* func_implementation: FUNCTION ID RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 205 "pars.y"
                                                                                                                               {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-9].id_const), NULL, (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1581 "pars.tab.c"
    break;

  case 22: /* proc_implementation: PROCEDURE ID '(' func_param_list ')' IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 208 "pars.y"
                                                                                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-10].id_const), (yyvsp[-8].param_lst), NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1587 "pars.tab.c"
    break;

  case 23: /* proc_implementation: PROCEDURE ID IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 209 "pars.y"
                                                                                                                {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-7].id_const), NULL, NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1593 "pars.tab.c"
    break;

  case 24: /* declaration_list_empty: %empty  */
#line 214 "pars.y"
                           { (yyval.decl_lst) = 0; }
#line 1599 "pars.tab.c"
    break;

  case 25: /* declaration_list_empty: decl_body_list  */
#line 215 "pars.y"
                           { (yyval.decl_lst) = 0; }
#line 1605 "pars.tab.c"
    break;

  case 26: /* decl_body_list: declaration ';'  */
#line 219 "pars.y"
                                            { }
#line 1611 "pars.tab.c"
    break;

  case 27: /* decl_body_list: item  */
#line 220 "pars.y"
                                            { }
#line 1617 "pars.tab.c"
    break;

  case 28: /* decl_body_list: decl_body_list declaration ';'  */
#line 221 "pars.y"
                                            { }
#line 1623 "pars.tab.c"
    break;

  case 29: /* decl_body_list: decl_body_list item  */
#line 222 "pars.y"
                                            { }
#line 1629 "pars.tab.c"
    break;

  case 30: /* declaration: type_declaration  */
#line 225 "pars.y"
                              {(yyval.decl) = (yyvsp[0].decl);}
#line 1635 "pars.tab.c"
    break;

  case 31: /* declaration: var_declaration  */
#line 226 "pars.y"
                                          {(yyval.decl) = (yyvsp[0].decl);}
#line 1641 "pars.tab.c"
    break;

  case 32: /* type_declaration: TYPE ID IS ARRAY '(' array_index_list ')' OF var_type  */
#line 232 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1647 "pars.tab.c"
    break;

  case 33: /* type_declaration: TYPE ID IS '(' enum_id_list ')'  */
#line 234 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1653 "pars.tab.c"
    break;

  case 34: /* type_declaration: TYPE ID IS RANGE range  */
#line 236 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1659 "pars.tab.c"
    break;

  case 35: /* type_declaration: TYPE ID IS RECORD record_field_list END RECORD  */
#line 238 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1665 "pars.tab.c"
    break;

  case 41: /* record_field_list: var_declaration ';'  */
#line 253 "pars.y"
                            { }
#line 1671 "pars.tab.c"
    break;

  case 42: /* record_field_list: record_field_list var_declaration ';'  */
#line 254 "pars.y"
                                              { }
#line 1677 "pars.tab.c"
    break;

  case 43: /* var_declaration: var_list ':' var_type  */
#line 260 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclaration (DeclarationNode::var_dec, (yyvsp[-2].var_lst),(yyvsp[0].v_type));}
#line 1683 "pars.tab.c"
    break;

  case 44: /* var_declaration: var_list ':' IN var_type  */
#line 262 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1689 "pars.tab.c"
    break;

  case 45: /* var_declaration: var_list ':' OUT var_type  */
#line 264 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1695 "pars.tab.c"
    break;

  case 46: /* var_declaration: var_list ':' IN OUT var_type  */
#line 266 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1701 "pars.tab.c"
    break;

  case 47: /* var_declaration: var_list ':' CONSTANT var_type  */
#line 268 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclaration (DeclarationNode::var_dec, (yyvsp[-3].var_lst),(yyvsp[0].v_type));}
#line 1707 "pars.tab.c"
    break;

  case 48: /* var_declaration: var_list ':' CONSTANT var_type ASSIGNMENT expression  */
#line 270 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclarationAssignment (DeclarationNode::var_dec, (yyvsp[-5].var_lst),(yyvsp[-2].v_type),(yyvsp[0].expr));}
#line 1713 "pars.tab.c"
    break;

  case 49: /* var_declaration: var_list ':' ARRAY '(' array_index_list ')' OF var_type  */
#line 272 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1719 "pars.tab.c"
    break;

  case 50: /* var_declaration: var_list ':' var_type ASSIGNMENT expression  */
#line 274 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclarationAssignment (DeclarationNode::var_dec, (yyvsp[-4].var_lst),(yyvsp[-2].v_type),(yyvsp[0].expr));}
#line 1725 "pars.tab.c"
    break;

  case 51: /* var_list: ID  */
#line 278 "pars.y"
              { (yyval.var_lst) = new VarListNode((yyvsp[0].id_const));}
#line 1731 "pars.tab.c"
    break;

  case 52: /* var_list: var_list ',' ID  */
#line 279 "pars.y"
                                    { (yyval.var_lst) = VarListNode::Append((yyvsp[-2].var_lst), (yyvsp[0].id_const)); }
#line 1737 "pars.tab.c"
    break;

  case 53: /* func_param_list: var_declaration  */
#line 282 "pars.y"
                                 {(yyval.param_lst) = new FuncParamListNode((yyvsp[0].decl));}
#line 1743 "pars.tab.c"
    break;

  case 54: /* func_param_list: func_param_list ';' var_declaration  */
#line 283 "pars.y"
                                                       { (yyval.param_lst) = FuncParamListNode::Append((yyvsp[-2].param_lst), (yyvsp[0].decl)); }
#line 1749 "pars.tab.c"
    break;

  case 55: /* stmt_list_empty: %empty  */
#line 290 "pars.y"
                                     { (yyval.stmt_lst) = 0; }
#line 1755 "pars.tab.c"
    break;

  case 56: /* stmt_list_empty: stmt_list  */
#line 291 "pars.y"
                                     { (yyval.stmt_lst) = new StmtListNode((yyvsp[0].stmt_lst)); }
#line 1761 "pars.tab.c"
    break;

  case 57: /* stmt_list_empty: stmt_list exception_part  */
#line 292 "pars.y"
                                     { (yyval.stmt_lst) = new StmtListNode((yyvsp[-1].stmt_lst)); }
#line 1767 "pars.tab.c"
    break;

  case 58: /* stmt_list: stmt  */
#line 295 "pars.y"
                 { (yyval.stmt_lst) = new StmtListNode((yyvsp[0].stmt)); }
#line 1773 "pars.tab.c"
    break;

  case 59: /* stmt_list: stmt_list stmt  */
#line 296 "pars.y"
                           { (yyval.stmt_lst) = StmtListNode::Append((yyvsp[-1].stmt_lst), (yyvsp[0].stmt)); }
#line 1779 "pars.tab.c"
    break;

  case 60: /* stmt: return_stmt  */
#line 299 "pars.y"
                   {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1785 "pars.tab.c"
    break;

  case 61: /* stmt: loop_stmt  */
#line 300 "pars.y"
                    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1791 "pars.tab.c"
    break;

  case 62: /* stmt: ID '(' expression_list_empty ')' ';'  */
#line 301 "pars.y"
                                           {(yyval.stmt) = StmtNode:: StmtFromIdAndExpr ((yyvsp[-4].id_const),(yyvsp[-2].expr_list));}
#line 1797 "pars.tab.c"
    break;

  case 63: /* stmt: if_stmt  */
#line 302 "pars.y"
               {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1803 "pars.tab.c"
    break;

  case 64: /* stmt: exit_stmt  */
#line 303 "pars.y"
                 {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1809 "pars.tab.c"
    break;

  case 65: /* stmt: assigment_stmt  */
#line 304 "pars.y"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1815 "pars.tab.c"
    break;

  case 66: /* stmt: case_stmt  */
#line 305 "pars.y"
                    {(yyval.stmt) = 0;}
#line 1821 "pars.tab.c"
    break;

  case 67: /* stmt: ID ';'  */
#line 306 "pars.y"
                 {(yyval.stmt) = StmtNode:: StmtFromIdAndExpr ((yyvsp[-1].id_const), NULL);}
#line 1827 "pars.tab.c"
    break;

  case 68: /* return_stmt: RETURN expression ';'  */
#line 309 "pars.y"
                                    {(yyval.stmt) = StmtNode:: StmtFromReturn ((yyvsp[-1].expr));}
#line 1833 "pars.tab.c"
    break;

  case 69: /* return_stmt: RETURN ';'  */
#line 310 "pars.y"
                                     {(yyval.stmt) = StmtNode:: StmtFromReturn (NULL);}
#line 1839 "pars.tab.c"
    break;

  case 70: /* loop_stmt: while_stmt  */
#line 313 "pars.y"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1845 "pars.tab.c"
    break;

  case 71: /* loop_stmt: for_stmt  */
#line 314 "pars.y"
                    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1851 "pars.tab.c"
    break;

  case 72: /* loop_stmt: simple_loop_stmt  */
#line 315 "pars.y"
                            {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1857 "pars.tab.c"
    break;

  case 73: /* for_stmt: FOR ID IN range LOOP stmt_list_empty END LOOP ';'  */
#line 320 "pars.y"
        {(yyval.stmt) = StmtNode:: StmtFromForLoop ((yyvsp[-7].id_const),(yyvsp[-5].rng),(yyvsp[-3].stmt_lst));}
#line 1863 "pars.tab.c"
    break;

  case 74: /* for_stmt: FOR ID IN expression LOOP stmt_list_empty END LOOP ';'  */
#line 322 "pars.y"
        {(yyval.stmt) = StmtNode:: StmtFromForLoop ((yyvsp[-7].id_const), NULL, (yyvsp[-3].stmt_lst));}
#line 1869 "pars.tab.c"
    break;

  case 75: /* while_stmt: WHILE expression LOOP stmt_list_empty END LOOP ';'  */
#line 325 "pars.y"
                                                               {(yyval.stmt) = StmtNode:: StmtFromWhileLoop ((yyvsp[-5].expr),(yyvsp[-3].stmt_lst));}
#line 1875 "pars.tab.c"
    break;

  case 76: /* simple_loop_stmt: LOOP stmt_list_empty END LOOP ';'  */
#line 328 "pars.y"
                                                    {(yyval.stmt) = StmtNode:: StmtFromSimpleLoop ((yyvsp[-3].stmt_lst));}
#line 1881 "pars.tab.c"
    break;

  case 77: /* exit_stmt: EXIT ';'  */
#line 331 "pars.y"
                    {(yyval.stmt) = StmtNode:: StmtFromExit (NULL);}
#line 1887 "pars.tab.c"
    break;

  case 78: /* exit_stmt: EXIT WHEN expression ';'  */
#line 332 "pars.y"
                                           {(yyval.stmt) = StmtNode:: StmtFromExit ((yyvsp[-1].expr));}
#line 1893 "pars.tab.c"
    break;

  case 79: /* if_stmt: IF expression THEN stmt_list_empty elsif_stmt_list else_stmt END IF ';'  */
#line 335 "pars.y"
                                                                                  {(yyval.stmt) = StmtNode:: StmtFromIfWithElsif ((yyvsp[-7].expr), (yyvsp[-5].stmt_lst), (yyvsp[-4].elsf_lst_stmt), (yyvsp[-3].els_stmt));}
#line 1899 "pars.tab.c"
    break;

  case 80: /* if_stmt: IF expression THEN stmt_list_empty else_stmt END IF ';'  */
#line 336 "pars.y"
                                                                                  {(yyval.stmt) = StmtNode:: StmtFromIf ((yyvsp[-6].expr), (yyvsp[-4].stmt_lst), (yyvsp[-3].els_stmt));}
#line 1905 "pars.tab.c"
    break;

  case 81: /* case_stmt: CASE expression IS case_alternative_list END CASE ';'  */
#line 341 "pars.y"
        {(yyval.stmt) = 0;}
#line 1911 "pars.tab.c"
    break;

  case 86: /* exception_part: EXCEPTION exception_handler_list  */
#line 355 "pars.y"
                                         { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 1917 "pars.tab.c"
    break;

  case 89: /* exception_handler: WHEN choice_list ARROW stmt_list  */
#line 364 "pars.y"
                                         { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 1923 "pars.tab.c"
    break;

  case 90: /* exception_handler: WHEN OTHERS ARROW stmt_list  */
#line 365 "pars.y"
                                         { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 1929 "pars.tab.c"
    break;

  case 95: /* elsif_stmt_list: elsif_stmt  */
#line 375 "pars.y"
                            { (yyval.elsf_lst_stmt) = new ElsifStmtListNode((yyvsp[0].elsf_stmt)); }
#line 1935 "pars.tab.c"
    break;

  case 96: /* elsif_stmt_list: elsif_stmt_list elsif_stmt  */
#line 376 "pars.y"
                                                             { (yyval.elsf_lst_stmt) = ElsifStmtListNode::Append((yyvsp[-1].elsf_lst_stmt), (yyvsp[0].elsf_stmt)); }
#line 1941 "pars.tab.c"
    break;

  case 97: /* elsif_stmt: ELSIF expression THEN stmt_list_empty  */
#line 379 "pars.y"
                                                        { (yyval.elsf_stmt) = new ElsifStmtNode((yyvsp[-2].expr), (yyvsp[0].stmt_lst)); }
#line 1947 "pars.tab.c"
    break;

  case 98: /* else_stmt: %empty  */
#line 382 "pars.y"
                             { (yyval.els_stmt) = 0; }
#line 1953 "pars.tab.c"
    break;

  case 99: /* else_stmt: ELSE stmt_list_empty  */
#line 383 "pars.y"
                                         { (yyval.els_stmt) = new ElseStmtNode((yyvsp[0].stmt_lst)); }
#line 1959 "pars.tab.c"
    break;

  case 100: /* assigment_stmt: expression ASSIGNMENT expression ';'  */
#line 386 "pars.y"
                                                     {(yyval.stmt) = StmtNode:: StmtFromAssigment ((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1965 "pars.tab.c"
    break;

  case 101: /* expression_list_empty: %empty  */
#line 389 "pars.y"
                                     { (yyval.expr_list) = 0; }
#line 1971 "pars.tab.c"
    break;

  case 102: /* expression_list_empty: expression_list  */
#line 390 "pars.y"
                                     { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr_list)); }
#line 1977 "pars.tab.c"
    break;

  case 103: /* expression_list: arg  */
#line 394 "pars.y"
                                { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr)); }
#line 1983 "pars.tab.c"
    break;

  case 104: /* expression_list: expression_list ',' arg  */
#line 395 "pars.y"
                                { (yyval.expr_list) = ExprListNode::Append((yyvsp[-2].expr_list), (yyvsp[0].expr)); }
#line 1989 "pars.tab.c"
    break;

  case 105: /* arg: expression  */
#line 399 "pars.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1995 "pars.tab.c"
    break;

  case 106: /* arg: ID ARROW expression  */
#line 400 "pars.y"
                                { (yyval.expr) = ExprNode::ExprFromId (ExprNode::id_,(yyvsp[-2].id_const)); }
#line 2001 "pars.tab.c"
    break;

  case 107: /* expression: CONST_BOOL  */
#line 403 "pars.y"
                       {(yyval.expr) = ExprNode::ExprFromBoolConst (ExprNode::const_bool,(yyvsp[0].int_const)); }
#line 2007 "pars.tab.c"
    break;

  case 108: /* expression: CONST_CHARACTER  */
#line 404 "pars.y"
                            {(yyval.expr) = ExprNode::ExprFromCharConst (ExprNode::const_character,(yyvsp[0].char_const)); }
#line 2013 "pars.tab.c"
    break;

  case 109: /* expression: CONST_STRING  */
#line 405 "pars.y"
                         {(yyval.expr) = ExprNode::ExprFromStringConst (ExprNode::const_string,(yyvsp[0].string_const)); }
#line 2019 "pars.tab.c"
    break;

  case 110: /* expression: CONST_INTEGER  */
#line 406 "pars.y"
                                  {(yyval.expr) = ExprNode::ExprFromIntConst (ExprNode::const_integer,(yyvsp[0].int_const)); }
#line 2025 "pars.tab.c"
    break;

  case 111: /* expression: CONST_FLOAT  */
#line 407 "pars.y"
                                {(yyval.expr) = ExprNode::ExprFromFloatConst (ExprNode::const_float,(yyvsp[0].float_const)); }
#line 2031 "pars.tab.c"
    break;

  case 112: /* expression: ID  */
#line 408 "pars.y"
               {(yyval.expr) = ExprNode::ExprFromId (ExprNode::id_,(yyvsp[0].id_const)); }
#line 2037 "pars.tab.c"
    break;

  case 113: /* expression: expression '>' expression  */
#line 409 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_more_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2043 "pars.tab.c"
    break;

  case 114: /* expression: expression '<' expression  */
#line 410 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_less_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2049 "pars.tab.c"
    break;

  case 115: /* expression: expression MORE_OR_EQUAL expression  */
#line 411 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_more_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2055 "pars.tab.c"
    break;

  case 116: /* expression: expression LESS_OR_EQUAL expression  */
#line 412 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_less_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2061 "pars.tab.c"
    break;

  case 117: /* expression: expression '=' expression  */
#line 413 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2067 "pars.tab.c"
    break;

  case 118: /* expression: expression NOT_EQUAL expression  */
#line 414 "pars.y"
                                            {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_not_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2073 "pars.tab.c"
    break;

  case 119: /* expression: expression '+' expression  */
#line 415 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_plus_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2079 "pars.tab.c"
    break;

  case 120: /* expression: expression '-' expression  */
#line 416 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_minus_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2085 "pars.tab.c"
    break;

  case 121: /* expression: expression '*' expression  */
#line 417 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_mult_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2091 "pars.tab.c"
    break;

  case 122: /* expression: expression MOD expression  */
#line 418 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_mult_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2097 "pars.tab.c"
    break;

  case 123: /* expression: expression REM expression  */
#line 419 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_mult_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2103 "pars.tab.c"
    break;

  case 124: /* expression: expression '/' expression  */
#line 420 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_div_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2109 "pars.tab.c"
    break;

  case 125: /* expression: expression ABS expression  */
#line 421 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_abs_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2115 "pars.tab.c"
    break;

  case 126: /* expression: '-' expression  */
#line 422 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::uminus_expr,(yyvsp[0].expr), NULL); }
#line 2121 "pars.tab.c"
    break;

  case 127: /* expression: expression OR expression  */
#line 423 "pars.y"
                                     {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_or_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2127 "pars.tab.c"
    break;

  case 128: /* expression: expression AND expression  */
#line 424 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_and_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2133 "pars.tab.c"
    break;

  case 129: /* expression: expression XOR expression  */
#line 425 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_xor_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2139 "pars.tab.c"
    break;

  case 130: /* expression: NOT expression  */
#line 426 "pars.y"
                           {(yyval.expr) = ExprNode::ExprOperation (ExprNode::not_expr,(yyvsp[0].expr), NULL); }
#line 2145 "pars.tab.c"
    break;

  case 131: /* expression: ID '(' expression_list_empty ')'  */
#line 427 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprFromFuncCall (ExprNode::func_call,(yyvsp[-3].id_const), (yyvsp[-1].expr_list)); }
#line 2151 "pars.tab.c"
    break;

  case 132: /* expression: INTEGER '(' expression_list_empty ')'  */
#line 428 "pars.y"
                                                           {(yyval.expr) = 0; }
#line 2157 "pars.tab.c"
    break;

  case 133: /* expression: FLOAT '(' expression_list_empty ')'  */
#line 429 "pars.y"
                                                   {(yyval.expr) = 0; }
#line 2163 "pars.tab.c"
    break;

  case 134: /* expression: BOOLEAN '(' expression_list_empty ')'  */
#line 430 "pars.y"
                                                   {(yyval.expr) = 0; }
#line 2169 "pars.tab.c"
    break;

  case 135: /* expression: CHARACTER '(' expression_list_empty ')'  */
#line 431 "pars.y"
                                                    {(yyval.expr) = 0; }
#line 2175 "pars.tab.c"
    break;

  case 136: /* expression: STRING '(' expression_list_empty ')'  */
#line 432 "pars.y"
                                                   {(yyval.expr) = 0; }
#line 2181 "pars.tab.c"
    break;

  case 137: /* expression: expression '.' ID  */
#line 433 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::id_,(yyvsp[-2].expr), NULL); }
#line 2187 "pars.tab.c"
    break;

  case 138: /* expression: ID '\'' ID  */
#line 434 "pars.y"
                       {(yyval.expr) = ExprNode::ExprFromId (ExprNode::id_,(yyvsp[-2].id_const)); }
#line 2193 "pars.tab.c"
    break;

  case 139: /* expression: ID '\'' ID '(' expression_list ')'  */
#line 435 "pars.y"
                                               {(yyval.expr) = ExprNode::ExprFromFuncCall (ExprNode::func_call,(yyvsp[-5].id_const), (yyvsp[-1].expr_list)); }
#line 2199 "pars.tab.c"
    break;

  case 140: /* expression: '(' expression_list ')'  */
#line 436 "pars.y"
                                    {(yyval.expr) = ExprNode::ExprFromExprLiteral (ExprNode::literal,(yyvsp[-1].expr_list)); }
#line 2205 "pars.tab.c"
    break;

  case 141: /* range: expression DOUBLE_DOT expression  */
#line 440 "pars.y"
                                          {(yyval.rng) = new RangeNode((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2211 "pars.tab.c"
    break;

  case 142: /* var_type: INTEGER  */
#line 443 "pars.y"
                  { (yyval.v_type) = new TypeNode(TypeNode::const_integer); }
#line 2217 "pars.tab.c"
    break;

  case 143: /* var_type: BOOLEAN  */
#line 444 "pars.y"
                  { (yyval.v_type) = new TypeNode(TypeNode::const_bool); }
#line 2223 "pars.tab.c"
    break;

  case 144: /* var_type: FLOAT  */
#line 445 "pars.y"
                { (yyval.v_type) = new TypeNode(TypeNode::const_float); }
#line 2229 "pars.tab.c"
    break;

  case 145: /* var_type: CHARACTER  */
#line 446 "pars.y"
                    { (yyval.v_type) = new TypeNode(TypeNode::const_character); }
#line 2235 "pars.tab.c"
    break;

  case 146: /* var_type: STRING  */
#line 447 "pars.y"
                 { (yyval.v_type) = new TypeNode(TypeNode::const_string); }
#line 2241 "pars.tab.c"
    break;

  case 147: /* var_type: ID  */
#line 448 "pars.y"
             { (yyval.v_type) = new TypeNode(TypeNode::id_,(yyvsp[0].id_const)); }
#line 2247 "pars.tab.c"
    break;


#line 2251 "pars.tab.c"

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

#line 451 "pars.y"



