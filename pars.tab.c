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
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_item_list = 60,                 /* item_list  */
  YYSYMBOL_item = 61,                      /* item  */
  YYSYMBOL_func_declaration = 62,          /* func_declaration  */
  YYSYMBOL_proc_declaration = 63,          /* proc_declaration  */
  YYSYMBOL_func_implementation = 64,       /* func_implementation  */
  YYSYMBOL_proc_implementation = 65,       /* proc_implementation  */
  YYSYMBOL_declaration_list_empty = 66,    /* declaration_list_empty  */
  YYSYMBOL_declaration_list = 67,          /* declaration_list  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_type_declaration = 69,          /* type_declaration  */
  YYSYMBOL_var_declaration = 70,           /* var_declaration  */
  YYSYMBOL_var_list = 71,                  /* var_list  */
  YYSYMBOL_func_param_list = 72,           /* func_param_list  */
  YYSYMBOL_stmt_list_empty = 73,           /* stmt_list_empty  */
  YYSYMBOL_stmt_list = 74,                 /* stmt_list  */
  YYSYMBOL_stmt = 75,                      /* stmt  */
  YYSYMBOL_return_stmt = 76,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 77,                 /* loop_stmt  */
  YYSYMBOL_for_stmt = 78,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 79,                /* while_stmt  */
  YYSYMBOL_simple_loop_stmt = 80,          /* simple_loop_stmt  */
  YYSYMBOL_exit_stmt = 81,                 /* exit_stmt  */
  YYSYMBOL_if_stmt = 82,                   /* if_stmt  */
  YYSYMBOL_elsif_stmt_list = 83,           /* elsif_stmt_list  */
  YYSYMBOL_elsif_stmt = 84,                /* elsif_stmt  */
  YYSYMBOL_else_stmt = 85,                 /* else_stmt  */
  YYSYMBOL_assigment_stmt = 86,            /* assigment_stmt  */
  YYSYMBOL_expression_list_empty = 87,     /* expression_list_empty  */
  YYSYMBOL_expression_list = 88,           /* expression_list  */
  YYSYMBOL_expression = 89,                /* expression  */
  YYSYMBOL_range = 90,                     /* range  */
  YYSYMBOL_var_type = 91                   /* var_type  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
      35,    36,    30,    27,    54,    28,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    57,
      23,    21,    25,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   155,   156,   159,   160,   161,   162,   166,
     167,   170,   171,   174,   175,   178,   179,   183,   184,   188,
     189,   192,   193,   197,   201,   202,   203,   207,   208,   211,
     212,   218,   219,   222,   223,   226,   227,   228,   229,   230,
     231,   234,   235,   238,   239,   240,   243,   246,   249,   252,
     253,   256,   257,   260,   261,   264,   267,   268,   271,   274,
     275,   278,   279,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   309,   312,   313,
     314,   315,   316,   317
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
  "':'", "';'", "$accept", "program", "item_list", "item",
  "func_declaration", "proc_declaration", "func_implementation",
  "proc_implementation", "declaration_list_empty", "declaration_list",
  "declaration", "type_declaration", "var_declaration", "var_list",
  "func_param_list", "stmt_list_empty", "stmt_list", "stmt", "return_stmt",
  "loop_stmt", "for_stmt", "while_stmt", "simple_loop_stmt", "exit_stmt",
  "if_stmt", "elsif_stmt_list", "elsif_stmt", "else_stmt",
  "assigment_stmt", "expression_list_empty", "expression_list",
  "expression", "range", "var_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -18,    -8,    17,     4,   -79,   -79,   -79,   -79,   -79,
     -31,   -32,   -79,   -79,    32,    40,    32,    49,   -79,   -79,
     -79,   -19,   -30,   -79,   -79,   -79,   -79,   -79,   -79,   -34,
     -29,    42,    31,    49,    28,   -79,   -79,    61,    35,    53,
      32,    49,   -79,   -21,    56,    99,    57,   -79,   -79,    78,
     104,    40,   -79,    70,    49,   -79,    87,   257,    86,    99,
     257,   257,   257,   257,    95,   -79,   -79,   -79,   -79,   -79,
     -35,   186,    76,    99,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   285,   -79,   257,   257,    25,    99,    81,
     100,   102,   226,   134,    93,   241,   -79,   -79,   -22,   300,
     257,   257,   -79,   -79,    71,   108,   -79,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   181,   113,   300,    49,   -79,   101,    99,   257,
     257,    99,   257,   155,    99,   -79,   257,   146,   132,   138,
     -79,   158,   153,   166,   166,   166,    88,    88,    88,    88,
      88,    88,   121,   121,   -79,   -79,   -79,   257,   205,   165,
     179,   167,   187,   188,   169,   219,   175,    94,   300,   176,
     -79,   -79,   -79,   300,    40,    99,   177,   196,   228,   -79,
     225,    99,   -79,   257,    99,    94,   -79,   189,   -79,   -79,
     236,   -79,   183,    40,   184,   238,   256,   -79,   -79,   240,
     281,   275,   -79,   -79,   -79,   283,    99,   316,   276,   277,
     278,   -79,   279,   -79,   -79,   -79,   -79
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     5,     6,     7,     8,
       0,     0,     1,     4,     0,     0,     0,    17,    12,    27,
      29,     0,     0,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,    18,     0,    21,    22,     0,     0,     0,
       0,    17,    10,     0,     0,    31,     0,    19,    28,     0,
      24,     0,    30,     0,    17,    11,     0,     0,     0,    31,
       0,     0,     0,     0,    68,    65,    66,    67,    64,    63,
       0,     0,     0,    32,    33,    35,    36,    44,    43,    45,
      39,    38,    40,     0,    20,     0,     0,     0,    31,     0,
       0,    68,     0,     0,     0,     0,    80,    84,     0,    61,
      59,     0,    49,    42,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    17,     9,     0,    31,     0,
      59,    31,     0,     0,    31,    86,     0,     0,    60,     0,
      41,     0,     0,    81,    82,    83,    73,    74,    70,    72,
      69,    71,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    62,    85,
      50,    16,    58,    87,     0,    31,     0,     0,     0,    85,
       0,    31,    48,     0,    31,    56,    53,     0,    37,    25,
       0,    14,     0,     0,     0,     0,     0,    57,    54,     0,
       0,     0,    15,    23,    47,     0,    31,     0,     0,     0,
       0,    55,     0,    52,    13,    46,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   333,   -79,   -79,   -79,   -79,   -39,   -79,
     305,   -79,    10,   -79,   323,   -58,   -79,   267,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   156,   157,   -79,   213,
     282,   -52,   -78,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    32,    33,
      34,    35,    36,    21,    22,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   185,   186,   187,    82,   137,
     138,    83,   123,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    94,    53,    16,    14,    92,    39,    43,    95,    96,
      97,    99,   101,    87,   135,    89,    41,    12,    17,   104,
      15,    10,   102,    42,    20,    18,    20,    40,    40,    54,
     127,    11,   136,   122,   124,    37,    55,    38,    23,    24,
      25,    26,    27,    23,    24,    25,    26,    27,    99,   139,
      52,   162,     1,     2,   165,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     161,    19,    49,   164,    28,   125,   167,   122,    99,    28,
     122,    44,   126,    45,   168,    47,   159,    31,    19,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      48,   119,   120,   121,    51,   173,    56,    57,    58,   183,
     184,    59,    60,    85,    84,   117,   118,   190,   119,   120,
     121,    86,    88,   195,    90,    93,   197,    61,   140,   105,
     100,   196,    62,   128,    63,   129,   189,   130,    64,    65,
      66,    67,    68,    69,   132,    70,   133,   141,   211,   158,
      71,   119,   120,   121,   160,   203,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   166,   119,   120,
     121,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   169,   119,   120,   121,   136,   111,   112,   113,
     114,   115,   116,   117,   118,   170,   119,   120,   121,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     172,   119,   120,   121,    61,   171,   174,   175,   176,    62,
     177,    63,   180,   178,   179,    91,    65,    66,    67,    68,
      69,   181,   182,   188,   191,   192,   157,   194,   131,   193,
     202,   204,   200,   103,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   134,   119,   120,   121,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     206,   119,   120,   121,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    61,   119,   120,   121,   201,
      62,   205,    63,   207,   208,   210,    91,    65,    66,    67,
      68,    69,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   209,   119,   120,   121,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   212,
     119,   120,   121,   213,   214,   215,   216,    13,    46,    30,
     106,   198,   199,   163,     0,    98
};

static const yytype_int16 yycheck[] =
{
      38,    59,    41,    35,    35,    57,    36,    36,    60,    61,
      62,    63,    47,    51,    36,    54,    50,     0,    50,    71,
      51,    39,    57,    57,    14,    57,    16,    57,    57,    50,
      88,    39,    54,    85,    86,    54,    57,    56,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,   100,   101,
      40,   129,    48,    49,   132,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     128,    39,    37,   131,    39,    50,   134,   129,   130,    39,
     132,    39,    57,    52,   136,    57,   125,    38,    39,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      39,    30,    31,    32,    51,   157,    50,     8,     9,    15,
      16,    12,    13,    35,    57,    27,    28,   175,    30,    31,
      32,    17,    52,   181,    37,    39,   184,    28,    57,    53,
      35,   183,    33,    52,    35,    35,   174,    35,    39,    40,
      41,    42,    43,    44,    10,    46,    53,    39,   206,    36,
      51,    30,    31,    32,    53,   193,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    12,    30,    31,
      32,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    36,    30,    31,    32,    54,    21,    22,    23,
      24,    25,    26,    27,    28,    57,    30,    31,    32,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      57,    30,    31,    32,    28,    57,    11,    52,    39,    33,
      53,    35,    53,    36,    36,    39,    40,    41,    42,    43,
      44,    12,    57,    57,    57,    39,    55,    12,    12,    11,
      57,    57,    53,    57,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    14,    30,    31,    32,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      14,    30,    31,    32,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    28,    30,    31,    32,    53,
      33,    53,    35,    53,    13,    12,    39,    40,    41,    42,
      43,    44,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    39,    30,    31,    32,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    13,
      30,    31,    32,    57,    57,    57,    57,     4,    33,    16,
      73,   185,   185,   130,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,    59,    60,    61,    62,    63,    64,    65,
      39,    39,     0,    61,    35,    51,    35,    50,    57,    39,
      70,    71,    72,     3,     4,     5,     6,     7,    39,    91,
      72,    38,    66,    67,    68,    69,    70,    54,    56,    36,
      57,    50,    57,    36,    39,    52,    68,    57,    39,    37,
      91,    51,    70,    66,    50,    57,    50,     8,     9,    12,
      13,    28,    33,    35,    39,    40,    41,    42,    43,    44,
      46,    51,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    86,    89,    57,    35,    17,    91,    52,    66,
      37,    39,    89,    39,    73,    89,    89,    89,    88,    89,
      35,    47,    57,    57,    89,    53,    75,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      31,    32,    89,    90,    89,    50,    57,    73,    52,    35,
      35,    12,    10,    53,    14,    36,    54,    87,    88,    89,
      57,    39,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    55,    36,    66,
      53,    73,    90,    87,    73,    90,    12,    73,    89,    36,
      57,    57,    57,    89,    11,    52,    39,    53,    36,    36,
      53,    12,    57,    15,    16,    83,    84,    85,    57,    91,
      73,    57,    39,    11,    12,    73,    89,    73,    84,    85,
      53,    53,    57,    91,    57,    53,    14,    53,    13,    39,
      12,    73,    13,    57,    57,    57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    77,    77,    78,    79,    80,    81,
      81,    82,    82,    83,    83,    84,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    91,    91,
      91,    91,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     8,
       5,     6,     3,    14,    11,    12,     9,     0,     1,     2,
       3,     1,     1,     9,     3,     8,     5,     1,     3,     1,
       3,     0,     1,     1,     2,     1,     1,     5,     1,     1,
       1,     3,     2,     1,     1,     1,     9,     7,     5,     2,
       4,     9,     8,     1,     2,     4,     0,     2,     4,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     2,     4,     3,     3,     1,     1,
       1,     1,     1,     1
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
  case 2: /* program: item_list  */
#line 148 "pars.y"
                   { (yyval.prg) = global_program = new ProgramNode((yyvsp[0].itemlst)); }
#line 1328 "pars.tab.c"
    break;

  case 3: /* item_list: item  */
#line 155 "pars.y"
                 {(yyval.itemlst) = new ItemListNode((yyvsp[0].item));}
#line 1334 "pars.tab.c"
    break;

  case 4: /* item_list: item_list item  */
#line 156 "pars.y"
                           { (yyval.itemlst) = ItemListNode::Append((yyvsp[-1].itemlst), (yyvsp[0].item)); }
#line 1340 "pars.tab.c"
    break;

  case 5: /* item: func_declaration  */
#line 159 "pars.y"
                       {(yyval.item) = (yyvsp[0].item);}
#line 1346 "pars.tab.c"
    break;

  case 6: /* item: proc_declaration  */
#line 160 "pars.y"
                           {(yyval.item) = (yyvsp[0].item);}
#line 1352 "pars.tab.c"
    break;

  case 7: /* item: func_implementation  */
#line 161 "pars.y"
                              {(yyval.item) = (yyvsp[0].item);}
#line 1358 "pars.tab.c"
    break;

  case 8: /* item: proc_implementation  */
#line 162 "pars.y"
                              {(yyval.item) = (yyvsp[0].item);}
#line 1364 "pars.tab.c"
    break;

  case 9: /* func_declaration: FUNCTION ID '(' func_param_list ')' RETURN var_type ';'  */
#line 166 "pars.y"
                                                                          {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-6].id_const), (yyvsp[-4].param_lst), (yyvsp[-1].v_type), NULL, NULL);}
#line 1370 "pars.tab.c"
    break;

  case 10: /* func_declaration: FUNCTION ID RETURN var_type ';'  */
#line 167 "pars.y"
                                                                  {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-3].id_const), NULL, (yyvsp[-1].v_type), NULL, NULL);}
#line 1376 "pars.tab.c"
    break;

  case 11: /* proc_declaration: PROCEDURE ID '(' func_param_list ')' ';'  */
#line 170 "pars.y"
                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-4].id_const), (yyvsp[-2].param_lst), NULL, NULL, NULL);}
#line 1382 "pars.tab.c"
    break;

  case 12: /* proc_declaration: PROCEDURE ID ';'  */
#line 171 "pars.y"
                                                   {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-1].id_const), NULL, NULL, NULL, NULL);}
#line 1388 "pars.tab.c"
    break;

  case 13: /* func_implementation: FUNCTION ID '(' func_param_list ')' RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 174 "pars.y"
                                                                                                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-12].id_const), (yyvsp[-10].param_lst), (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1394 "pars.tab.c"
    break;

  case 14: /* func_implementation: FUNCTION ID RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 175 "pars.y"
                                                                                                                               {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-9].id_const), NULL, (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1400 "pars.tab.c"
    break;

  case 15: /* proc_implementation: PROCEDURE ID '(' func_param_list ')' IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 178 "pars.y"
                                                                                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-10].id_const), (yyvsp[-8].param_lst), NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1406 "pars.tab.c"
    break;

  case 16: /* proc_implementation: PROCEDURE ID IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 179 "pars.y"
                                                                                                                {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-7].id_const), NULL, NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1412 "pars.tab.c"
    break;

  case 17: /* declaration_list_empty: %empty  */
#line 183 "pars.y"
                                   { (yyval.decl_lst) = 0; }
#line 1418 "pars.tab.c"
    break;

  case 18: /* declaration_list_empty: declaration_list  */
#line 184 "pars.y"
                                                                   {(yyval.decl_lst) = new DeclarationListNode((yyvsp[0].decl_lst));}
#line 1424 "pars.tab.c"
    break;

  case 19: /* declaration_list: declaration ';'  */
#line 188 "pars.y"
                                   {(yyval.decl_lst) = new DeclarationListNode((yyvsp[-1].decl));}
#line 1430 "pars.tab.c"
    break;

  case 20: /* declaration_list: declaration_list declaration ';'  */
#line 189 "pars.y"
                                                                             { (yyval.decl_lst) = DeclarationListNode::Append((yyvsp[-2].decl_lst), (yyvsp[-1].decl)); }
#line 1436 "pars.tab.c"
    break;

  case 21: /* declaration: type_declaration  */
#line 192 "pars.y"
                              {(yyval.decl) = (yyvsp[0].decl);}
#line 1442 "pars.tab.c"
    break;

  case 22: /* declaration: var_declaration  */
#line 193 "pars.y"
                                          {(yyval.decl) = (yyvsp[0].decl);}
#line 1448 "pars.tab.c"
    break;

  case 23: /* type_declaration: TYPE ID IS ARRAY '(' range ')' OF var_type  */
#line 197 "pars.y"
                                                              {(yyval.decl) = DeclarationNode::TypeDeclaration (DeclarationNode::type_dec, (yyvsp[-7].id_const), (yyvsp[-3].rng),(yyvsp[0].v_type));}
#line 1454 "pars.tab.c"
    break;

  case 24: /* var_declaration: var_list ':' var_type  */
#line 201 "pars.y"
                                        {(yyval.decl) = DeclarationNode::VarDeclaration (DeclarationNode::var_dec, (yyvsp[-2].var_lst),(yyvsp[0].v_type));}
#line 1460 "pars.tab.c"
    break;

  case 25: /* var_declaration: var_list ':' ARRAY '(' range ')' OF var_type  */
#line 202 "pars.y"
                                                                                  {(yyval.decl) = DeclarationNode::VarDeclarationArray (DeclarationNode::var_dec, (yyvsp[-7].var_lst),(yyvsp[-3].rng),(yyvsp[0].v_type));}
#line 1466 "pars.tab.c"
    break;

  case 26: /* var_declaration: var_list ':' var_type ASSIGNMENT expression  */
#line 203 "pars.y"
                                                                                 {(yyval.decl) = DeclarationNode::VarDeclarationAssignment (DeclarationNode::var_dec, (yyvsp[-4].var_lst),(yyvsp[-2].v_type),(yyvsp[0].expr));}
#line 1472 "pars.tab.c"
    break;

  case 27: /* var_list: ID  */
#line 207 "pars.y"
              { (yyval.var_lst) = new VarListNode((yyvsp[0].id_const));}
#line 1478 "pars.tab.c"
    break;

  case 28: /* var_list: var_list ',' ID  */
#line 208 "pars.y"
                                    { (yyval.var_lst) = VarListNode::Append((yyvsp[-2].var_lst), (yyvsp[0].id_const)); }
#line 1484 "pars.tab.c"
    break;

  case 29: /* func_param_list: var_declaration  */
#line 211 "pars.y"
                                 {(yyval.param_lst) = new FuncParamListNode((yyvsp[0].decl));}
#line 1490 "pars.tab.c"
    break;

  case 30: /* func_param_list: func_param_list ';' var_declaration  */
#line 212 "pars.y"
                                                       { (yyval.param_lst) = FuncParamListNode::Append((yyvsp[-2].param_lst), (yyvsp[0].decl)); }
#line 1496 "pars.tab.c"
    break;

  case 31: /* stmt_list_empty: %empty  */
#line 218 "pars.y"
                             { (yyval.stmt_lst) = 0; }
#line 1502 "pars.tab.c"
    break;

  case 32: /* stmt_list_empty: stmt_list  */
#line 219 "pars.y"
                           { (yyval.stmt_lst) = new StmtListNode((yyvsp[0].stmt_lst)); }
#line 1508 "pars.tab.c"
    break;

  case 33: /* stmt_list: stmt  */
#line 222 "pars.y"
                 { (yyval.stmt_lst) = new StmtListNode((yyvsp[0].stmt)); }
#line 1514 "pars.tab.c"
    break;

  case 34: /* stmt_list: stmt_list stmt  */
#line 223 "pars.y"
                           { (yyval.stmt_lst) = StmtListNode::Append((yyvsp[-1].stmt_lst), (yyvsp[0].stmt)); }
#line 1520 "pars.tab.c"
    break;

  case 35: /* stmt: return_stmt  */
#line 226 "pars.y"
                   {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1526 "pars.tab.c"
    break;

  case 36: /* stmt: loop_stmt  */
#line 227 "pars.y"
                    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1532 "pars.tab.c"
    break;

  case 37: /* stmt: ID '(' expression_list_empty ')' ';'  */
#line 228 "pars.y"
                                           {(yyval.stmt) = StmtNode:: StmtFromIdAndExpr ((yyvsp[-4].id_const),(yyvsp[-2].expr_list));}
#line 1538 "pars.tab.c"
    break;

  case 38: /* stmt: if_stmt  */
#line 229 "pars.y"
               {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1544 "pars.tab.c"
    break;

  case 39: /* stmt: exit_stmt  */
#line 230 "pars.y"
                 {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1550 "pars.tab.c"
    break;

  case 40: /* stmt: assigment_stmt  */
#line 231 "pars.y"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1556 "pars.tab.c"
    break;

  case 41: /* return_stmt: RETURN expression ';'  */
#line 234 "pars.y"
                                    {(yyval.stmt) = StmtNode:: StmtFromReturn ((yyvsp[-1].expr));}
#line 1562 "pars.tab.c"
    break;

  case 42: /* return_stmt: RETURN ';'  */
#line 235 "pars.y"
                                     {(yyval.stmt) = StmtNode:: StmtFromReturn (NULL);}
#line 1568 "pars.tab.c"
    break;

  case 43: /* loop_stmt: while_stmt  */
#line 238 "pars.y"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1574 "pars.tab.c"
    break;

  case 44: /* loop_stmt: for_stmt  */
#line 239 "pars.y"
                    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1580 "pars.tab.c"
    break;

  case 45: /* loop_stmt: simple_loop_stmt  */
#line 240 "pars.y"
                            {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1586 "pars.tab.c"
    break;

  case 46: /* for_stmt: FOR ID IN range LOOP stmt_list_empty END LOOP ';'  */
#line 243 "pars.y"
                                                            {(yyval.stmt) = StmtNode:: StmtFromForLoop ((yyvsp[-7].id_const),(yyvsp[-5].rng),(yyvsp[-3].stmt_lst));}
#line 1592 "pars.tab.c"
    break;

  case 47: /* while_stmt: WHILE expression LOOP stmt_list_empty END LOOP ';'  */
#line 246 "pars.y"
                                                               {(yyval.stmt) = StmtNode:: StmtFromWhileLoop ((yyvsp[-5].expr),(yyvsp[-3].stmt_lst));}
#line 1598 "pars.tab.c"
    break;

  case 48: /* simple_loop_stmt: LOOP stmt_list_empty END LOOP ';'  */
#line 249 "pars.y"
                                                    {(yyval.stmt) = StmtNode:: StmtFromSimpleLoop ((yyvsp[-3].stmt_lst));}
#line 1604 "pars.tab.c"
    break;

  case 49: /* exit_stmt: EXIT ';'  */
#line 252 "pars.y"
                    {(yyval.stmt) = StmtNode:: StmtFromExit (NULL);}
#line 1610 "pars.tab.c"
    break;

  case 50: /* exit_stmt: EXIT WHEN expression ';'  */
#line 253 "pars.y"
                                           {(yyval.stmt) = StmtNode:: StmtFromExit ((yyvsp[-1].expr));}
#line 1616 "pars.tab.c"
    break;

  case 51: /* if_stmt: IF expression THEN stmt_list_empty elsif_stmt_list else_stmt END IF ';'  */
#line 256 "pars.y"
                                                                                  {(yyval.stmt) = StmtNode:: StmtFromIfWithElsif ((yyvsp[-7].expr), (yyvsp[-5].stmt_lst), (yyvsp[-4].elsf_lst_stmt), (yyvsp[-3].els_stmt));}
#line 1622 "pars.tab.c"
    break;

  case 52: /* if_stmt: IF expression THEN stmt_list_empty else_stmt END IF ';'  */
#line 257 "pars.y"
                                                                                  {(yyval.stmt) = StmtNode:: StmtFromIf ((yyvsp[-6].expr), (yyvsp[-4].stmt_lst), (yyvsp[-3].els_stmt));}
#line 1628 "pars.tab.c"
    break;

  case 53: /* elsif_stmt_list: elsif_stmt  */
#line 260 "pars.y"
                            { (yyval.elsf_lst_stmt) = new ElsifStmtListNode((yyvsp[0].elsf_stmt)); }
#line 1634 "pars.tab.c"
    break;

  case 54: /* elsif_stmt_list: elsif_stmt_list elsif_stmt  */
#line 261 "pars.y"
                                                             { (yyval.elsf_lst_stmt) = ElsifStmtListNode::Append((yyvsp[-1].elsf_lst_stmt), (yyvsp[0].elsf_stmt)); }
#line 1640 "pars.tab.c"
    break;

  case 55: /* elsif_stmt: ELSIF expression THEN stmt_list_empty  */
#line 264 "pars.y"
                                                        { (yyval.elsf_stmt) = new ElsifStmtNode((yyvsp[-2].expr), (yyvsp[0].stmt_lst)); }
#line 1646 "pars.tab.c"
    break;

  case 56: /* else_stmt: %empty  */
#line 267 "pars.y"
                             { (yyval.els_stmt) = 0; }
#line 1652 "pars.tab.c"
    break;

  case 57: /* else_stmt: ELSE stmt_list_empty  */
#line 268 "pars.y"
                                         { (yyval.els_stmt) = new ElseStmtNode((yyvsp[0].stmt_lst)); }
#line 1658 "pars.tab.c"
    break;

  case 58: /* assigment_stmt: expression ASSIGNMENT expression ';'  */
#line 271 "pars.y"
                                                     {(yyval.stmt) = StmtNode:: StmtFromAssigment ((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1664 "pars.tab.c"
    break;

  case 59: /* expression_list_empty: %empty  */
#line 274 "pars.y"
                                     { (yyval.expr_list) = 0; }
#line 1670 "pars.tab.c"
    break;

  case 60: /* expression_list_empty: expression_list  */
#line 275 "pars.y"
                                     { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr_list)); }
#line 1676 "pars.tab.c"
    break;

  case 61: /* expression_list: expression  */
#line 278 "pars.y"
                            { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr)); }
#line 1682 "pars.tab.c"
    break;

  case 62: /* expression_list: expression_list ',' expression  */
#line 279 "pars.y"
                                                                 { (yyval.expr_list) = ExprListNode::Append((yyvsp[-2].expr_list), (yyvsp[0].expr)); }
#line 1688 "pars.tab.c"
    break;

  case 63: /* expression: CONST_BOOL  */
#line 282 "pars.y"
                       {(yyval.expr) = ExprNode::ExprFromBoolConst (ExprNode::const_bool,(yyvsp[0].int_const)); }
#line 1694 "pars.tab.c"
    break;

  case 64: /* expression: CONST_CHARACTER  */
#line 283 "pars.y"
                            {(yyval.expr) = ExprNode::ExprFromCharConst (ExprNode::const_character,(yyvsp[0].char_const)); }
#line 1700 "pars.tab.c"
    break;

  case 65: /* expression: CONST_STRING  */
#line 284 "pars.y"
                         {(yyval.expr) = ExprNode::ExprFromStringConst (ExprNode::const_string,(yyvsp[0].string_const)); }
#line 1706 "pars.tab.c"
    break;

  case 66: /* expression: CONST_INTEGER  */
#line 285 "pars.y"
                                  {(yyval.expr) = ExprNode::ExprFromIntConst (ExprNode::const_integer,(yyvsp[0].int_const)); }
#line 1712 "pars.tab.c"
    break;

  case 67: /* expression: CONST_FLOAT  */
#line 286 "pars.y"
                                {(yyval.expr) = ExprNode::ExprFromFloatConst (ExprNode::const_float,(yyvsp[0].float_const)); }
#line 1718 "pars.tab.c"
    break;

  case 68: /* expression: ID  */
#line 287 "pars.y"
               {(yyval.expr) = ExprNode::ExprFromId (ExprNode::id_,(yyvsp[0].id_const)); }
#line 1724 "pars.tab.c"
    break;

  case 69: /* expression: expression '>' expression  */
#line 288 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_more_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1730 "pars.tab.c"
    break;

  case 70: /* expression: expression '<' expression  */
#line 289 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_less_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1736 "pars.tab.c"
    break;

  case 71: /* expression: expression MORE_OR_EQUAL expression  */
#line 290 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_more_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1742 "pars.tab.c"
    break;

  case 72: /* expression: expression LESS_OR_EQUAL expression  */
#line 291 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_less_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1748 "pars.tab.c"
    break;

  case 73: /* expression: expression '=' expression  */
#line 292 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1754 "pars.tab.c"
    break;

  case 74: /* expression: expression NOT_EQUAL expression  */
#line 293 "pars.y"
                                            {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_not_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1760 "pars.tab.c"
    break;

  case 75: /* expression: expression '+' expression  */
#line 294 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_plus_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1766 "pars.tab.c"
    break;

  case 76: /* expression: expression '-' expression  */
#line 295 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_minus_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1772 "pars.tab.c"
    break;

  case 77: /* expression: expression '*' expression  */
#line 296 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_mult_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1778 "pars.tab.c"
    break;

  case 78: /* expression: expression '/' expression  */
#line 297 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_div_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1784 "pars.tab.c"
    break;

  case 79: /* expression: expression ABS expression  */
#line 298 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_abs_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1790 "pars.tab.c"
    break;

  case 80: /* expression: '-' expression  */
#line 299 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::uminus_expr,(yyvsp[0].expr), NULL); }
#line 1796 "pars.tab.c"
    break;

  case 81: /* expression: expression OR expression  */
#line 300 "pars.y"
                                     {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_or_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1802 "pars.tab.c"
    break;

  case 82: /* expression: expression AND expression  */
#line 301 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_and_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1808 "pars.tab.c"
    break;

  case 83: /* expression: expression XOR expression  */
#line 302 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_xor_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 1814 "pars.tab.c"
    break;

  case 84: /* expression: NOT expression  */
#line 303 "pars.y"
                           {(yyval.expr) = ExprNode::ExprOperation (ExprNode::not_expr,(yyvsp[0].expr), NULL); }
#line 1820 "pars.tab.c"
    break;

  case 85: /* expression: ID '(' expression_list_empty ')'  */
#line 304 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprFromFuncCall (ExprNode::func_call,(yyvsp[-3].id_const), (yyvsp[-1].expr_list)); }
#line 1826 "pars.tab.c"
    break;

  case 86: /* expression: '(' expression_list ')'  */
#line 305 "pars.y"
                                    {(yyval.expr) = ExprNode::ExprFromExprLiteral (ExprNode::literal,(yyvsp[-1].expr_list)); }
#line 1832 "pars.tab.c"
    break;

  case 87: /* range: expression DOUBLE_DOT expression  */
#line 309 "pars.y"
                                          {(yyval.rng) = new RangeNode((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1838 "pars.tab.c"
    break;

  case 88: /* var_type: INTEGER  */
#line 312 "pars.y"
                  { (yyval.v_type) = new TypeNode(TypeNode::const_integer); }
#line 1844 "pars.tab.c"
    break;

  case 89: /* var_type: BOOLEAN  */
#line 313 "pars.y"
                  { (yyval.v_type) = new TypeNode(TypeNode::const_bool); }
#line 1850 "pars.tab.c"
    break;

  case 90: /* var_type: FLOAT  */
#line 314 "pars.y"
                { (yyval.v_type) = new TypeNode(TypeNode::const_float); }
#line 1856 "pars.tab.c"
    break;

  case 91: /* var_type: CHARACTER  */
#line 315 "pars.y"
                    { (yyval.v_type) = new TypeNode(TypeNode::const_character); }
#line 1862 "pars.tab.c"
    break;

  case 92: /* var_type: STRING  */
#line 316 "pars.y"
                 { (yyval.v_type) = new TypeNode(TypeNode::const_string); }
#line 1868 "pars.tab.c"
    break;

  case 93: /* var_type: ID  */
#line 317 "pars.y"
             { (yyval.v_type) = new TypeNode(TypeNode::id_,(yyvsp[0].id_const)); }
#line 1874 "pars.tab.c"
    break;


#line 1878 "pars.tab.c"

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

#line 320 "pars.y"



