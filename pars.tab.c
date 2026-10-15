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
#line 7 "pars.y"

#include <stdio.h>
#include <stdlib.h>
#include "class_nodes.h"
void yyerror(char const* s);
extern int yylex(void);
ProgramNode* global_program;

#line 80 "pars.tab.c"

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
  YYSYMBOL_29_ = 29,                       /* '*'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_ABS = 31,                       /* ABS  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_UMINUS = 33,                    /* UMINUS  */
  YYSYMBOL_34_ = 34,                       /* '.'  */
  YYSYMBOL_ARRAY = 35,                     /* ARRAY  */
  YYSYMBOL_TYPE = 36,                      /* TYPE  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_CONST_STRING = 38,              /* CONST_STRING  */
  YYSYMBOL_CONST_INTEGER = 39,             /* CONST_INTEGER  */
  YYSYMBOL_CONST_FLOAT = 40,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHARACTER = 41,           /* CONST_CHARACTER  */
  YYSYMBOL_CONST_BOOL = 42,                /* CONST_BOOL  */
  YYSYMBOL_RANGE = 43,                     /* RANGE  */
  YYSYMBOL_EXIT = 44,                      /* EXIT  */
  YYSYMBOL_WHEN = 45,                      /* WHEN  */
  YYSYMBOL_FUNCTION = 46,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 47,                 /* PROCEDURE  */
  YYSYMBOL_IS = 48,                        /* IS  */
  YYSYMBOL_RETURN = 49,                    /* RETURN  */
  YYSYMBOL_BEGIN_TOKEN = 50,               /* BEGIN_TOKEN  */
  YYSYMBOL_END = 51,                       /* END  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_DOUBLE_DOT = 53,                /* DOUBLE_DOT  */
  YYSYMBOL_54_ = 54,                       /* ':'  */
  YYSYMBOL_55_ = 55,                       /* ';'  */
  YYSYMBOL_WITH = 56,                      /* WITH  */
  YYSYMBOL_USE = 57,                       /* USE  */
  YYSYMBOL_RECORD = 58,                    /* RECORD  */
  YYSYMBOL_CONSTANT = 59,                  /* CONSTANT  */
  YYSYMBOL_CASE = 60,                      /* CASE  */
  YYSYMBOL_EXCEPTION = 61,                 /* EXCEPTION  */
  YYSYMBOL_OTHERS = 62,                    /* OTHERS  */
  YYSYMBOL_OUT = 63,                       /* OUT  */
  YYSYMBOL_MOD = 64,                       /* MOD  */
  YYSYMBOL_REM = 65,                       /* REM  */
  YYSYMBOL_ARROW = 66,                     /* ARROW  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
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
  YYSYMBOL_array_index_list = 87,          /* array_index_list  */
  YYSYMBOL_enum_id_list = 88,              /* enum_id_list  */
  YYSYMBOL_record_field_list = 89,         /* record_field_list  */
  YYSYMBOL_var_declaration = 90,           /* var_declaration  */
  YYSYMBOL_var_list = 91,                  /* var_list  */
  YYSYMBOL_func_param_list = 92,           /* func_param_list  */
  YYSYMBOL_stmt_list_empty = 93,           /* stmt_list_empty  */
  YYSYMBOL_stmt_list = 94,                 /* stmt_list  */
  YYSYMBOL_stmt = 95,                      /* stmt  */
  YYSYMBOL_return_stmt = 96,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 97,                 /* loop_stmt  */
  YYSYMBOL_for_stmt = 98,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 99,                /* while_stmt  */
  YYSYMBOL_simple_loop_stmt = 100,         /* simple_loop_stmt  */
  YYSYMBOL_exit_stmt = 101,                /* exit_stmt  */
  YYSYMBOL_if_stmt = 102,                  /* if_stmt  */
  YYSYMBOL_case_stmt = 103,                /* case_stmt  */
  YYSYMBOL_case_alternative_list = 104,    /* case_alternative_list  */
  YYSYMBOL_case_alternative = 105,         /* case_alternative  */
  YYSYMBOL_exception_part = 106,           /* exception_part  */
  YYSYMBOL_exception_handler_list = 107,   /* exception_handler_list  */
  YYSYMBOL_exception_handler = 108,        /* exception_handler  */
  YYSYMBOL_choice_list = 109,              /* choice_list  */
  YYSYMBOL_elsif_stmt_list = 110,          /* elsif_stmt_list  */
  YYSYMBOL_elsif_stmt = 111,               /* elsif_stmt  */
  YYSYMBOL_else_stmt = 112,                /* else_stmt  */
  YYSYMBOL_assigment_stmt = 113,           /* assigment_stmt  */
  YYSYMBOL_expression_list_empty = 114,    /* expression_list_empty  */
  YYSYMBOL_expression_list = 115,          /* expression_list  */
  YYSYMBOL_arg = 116,                      /* arg  */
  YYSYMBOL_expression = 117,               /* expression  */
  YYSYMBOL_range = 118,                    /* range  */
  YYSYMBOL_var_type = 119                  /* var_type  */
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
#define YYLAST   846

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
      67,    68,    29,    27,    52,    28,    34,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    55,
      23,    21,    25,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    24,    26,    31,
      32,    33,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    53,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   136,   139,   140,   143,   144,   147,   148,
     150,   151,   153,   154,   155,   156,   158,   159,   161,   162,
     164,   165,   167,   168,   171,   172,   175,   176,   177,   178,
     180,   181,   184,   186,   188,   190,   194,   195,   196,   199,
     200,   203,   204,   207,   209,   211,   213,   215,   217,   219,
     221,   224,   225,   227,   228,   231,   232,   233,   235,   236,
     238,   239,   240,   241,   242,   243,   244,   245,   247,   248,
     250,   251,   252,   255,   257,   260,   262,   264,   265,   267,
     268,   271,   275,   276,   279,   280,   283,   286,   287,   290,
     291,   294,   295,   296,   297,   299,   300,   302,   304,   305,
     307,   309,   310,   313,   314,   317,   318,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   355,   357,   358,   359,   360,   361,   362
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
  "'-'", "'*'", "'/'", "ABS", "NOT", "UMINUS", "'.'", "ARRAY", "TYPE",
  "ID", "CONST_STRING", "CONST_INTEGER", "CONST_FLOAT", "CONST_CHARACTER",
  "CONST_BOOL", "RANGE", "EXIT", "WHEN", "FUNCTION", "PROCEDURE", "IS",
  "RETURN", "BEGIN_TOKEN", "END", "','", "DOUBLE_DOT", "':'", "';'",
  "WITH", "USE", "RECORD", "CONSTANT", "CASE", "EXCEPTION", "OTHERS",
  "OUT", "MOD", "REM", "ARROW", "'('", "')'", "'|'", "'\\''", "$accept",
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

#define YYPACT_NINF (-168)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -168,    12,   119,  -168,   -14,     8,    33,    33,  -168,  -168,
      28,  -168,  -168,  -168,  -168,  -168,   -45,     6,  -168,    -8,
      -7,  -168,   146,    59,   157,  -168,    59,    65,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,   129,  -168,  -168,   162,
     -13,    69,  -168,    47,   157,    67,  -168,  -168,    49,  -168,
     157,  -168,   127,   416,    59,   147,   139,   130,  -168,   160,
    -168,   133,   151,  -168,    62,   150,   146,   146,   204,  -168,
     146,   -28,   156,   168,   169,   170,   171,   367,   185,   130,
     367,   367,   367,    93,  -168,  -168,  -168,  -168,  -168,    99,
     268,   367,   407,   188,   221,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,   570,  -168,   157,  -168,   130,
     146,  -168,   367,   223,  -168,   367,   137,   174,   367,    59,
     206,   407,   407,   407,   407,   407,   138,   486,   235,   196,
     504,   212,   212,  -168,   407,   211,   367,  -168,  -168,   619,
     667,    60,    24,  -168,   781,   213,   207,  -168,  -168,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   214,   367,   367,   205,   203,  -168,
     189,   602,  -168,   367,   781,   157,  -168,   367,   699,  -168,
     122,   201,  -168,    46,   198,   215,   200,   208,   209,   210,
     407,   130,   367,   252,   130,   216,   202,   716,  -168,   234,
     367,   407,  -168,   225,   287,   207,  -168,   764,   316,   316,
     316,    81,    81,    81,    81,    81,    81,     7,     7,    -5,
      -5,    -5,  -168,   212,   212,   130,   246,   274,   367,   367,
     781,   236,   219,   231,   240,  -168,   260,  -168,  -168,  -168,
    -168,  -168,  -168,   230,   248,   438,   289,   247,   195,   249,
     407,  -168,   327,   155,  -168,   781,  -168,  -168,   237,   120,
     699,  -168,  -168,  -168,   261,   256,   146,   781,   781,   130,
     302,  -168,  -168,  -168,  -168,   304,   130,   130,  -168,   367,
     130,   195,  -168,   263,  -168,    51,   251,   143,   258,  -168,
     130,   130,   367,   283,  -168,  -168,   270,   146,   267,   285,
     297,   552,  -168,  -168,   300,   339,  -168,   130,   130,   298,
     130,   130,   699,  -168,   301,   320,  -168,  -168,   346,   348,
     130,   349,   306,   130,   130,  -168,  -168,   308,   321,   322,
    -168,   323,  -168,  -168,  -168,  -168,  -168
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     0,     2,     5,
       3,    10,    12,    13,    14,    15,     0,     0,     8,     0,
       0,    11,     0,     0,    24,    19,     0,     0,     6,     7,
     142,   143,   144,   145,   146,   147,     0,    51,    53,     0,
       0,     0,    27,     0,    25,     0,    30,    31,     0,     9,
      24,    17,     0,     0,     0,     0,     0,    55,    29,     0,
      26,     0,     0,    52,     0,     0,     0,     0,    43,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,   112,   109,   110,   111,   108,   107,     0,
       0,     0,     0,     0,    56,    58,    60,    61,    71,    70,
      72,    64,    63,    66,    65,     0,    28,    24,    18,    55,
       0,    44,     0,    47,    45,     0,     0,     0,     0,     0,
       0,   101,   101,   101,   101,   101,   112,     0,     0,     0,
       0,   126,   130,    67,   101,     0,     0,    77,    69,     0,
       0,   112,     0,   103,   105,     0,     0,    59,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    36,    37,     0,    50,    24,    16,     0,     0,    34,
       0,     0,    39,     0,     0,   102,     0,     0,     0,     0,
     101,    55,     0,     0,    55,     0,   138,     0,    68,     0,
       0,     0,   140,     0,     0,    86,    87,     0,   127,   128,
     129,   117,   118,   114,   116,   113,   115,   119,   120,   121,
     124,   125,   137,   122,   123,    55,     0,     0,     0,     0,
      48,     0,     0,     0,     0,    41,     0,    33,   132,   134,
     133,   135,   136,     0,     0,     0,     0,     0,    98,   131,
       0,    78,     0,     0,    82,   106,   104,    23,     0,     0,
      91,    92,    88,   100,     0,     0,     0,    38,   141,    55,
       0,    35,    42,    40,   131,     0,    55,    55,    76,     0,
      55,    98,    95,     0,    62,     0,     0,     0,     0,    83,
       0,     0,     0,     0,    21,    49,     0,     0,     0,     0,
       0,     0,    99,    96,     0,     0,   139,     0,     0,     0,
      90,    89,    93,    94,     0,     0,    32,    75,     0,     0,
      55,     0,     0,    85,    84,    81,    22,     0,     0,     0,
      97,     0,    80,    20,    74,    73,    79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,  -168,  -168,  -168,   368,  -168,    14,  -168,  -168,
    -168,  -168,   -44,  -168,   335,  -168,   220,  -168,  -168,     2,
    -168,   356,   -78,  -167,   -92,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,   131,  -168,  -168,   178,   134,  -168,
     104,   106,  -168,   -90,   -89,   187,   -72,   -97,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     8,     2,     9,    19,    10,    42,    12,    13,
      14,    15,    43,    44,    45,    46,   170,   183,   180,    47,
      39,    40,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   253,   254,   148,   205,   206,   259,   281,
     282,   283,   104,   184,   185,   143,   105,   172,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,   129,   147,   142,    22,   127,    62,   117,   130,   131,
     132,   111,     3,   113,   114,   118,    11,   116,   139,   140,
     144,   179,    23,    16,    21,    38,    27,    27,    38,   164,
     119,   168,   186,   187,   188,   189,   161,   162,   163,   120,
     171,   164,    54,   174,   195,    17,   178,    28,    29,   144,
     144,   144,   144,   144,    24,    55,    69,   169,    58,   165,
     166,    25,   144,   167,   197,    30,    31,    32,    33,    34,
      18,   165,   166,    26,     4,     5,   201,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   202,   223,   224,   246,    37,    57,   236,    35,
     243,   230,    49,   201,    54,   171,    56,   261,   159,   160,
     161,   162,   163,   244,   237,   164,   248,    61,   144,   306,
     245,   181,    60,   310,   311,   110,   200,   190,   255,   144,
     135,   231,   260,    72,    73,    74,    75,    76,    77,    78,
     323,   324,    79,    80,   136,   165,   166,   264,   133,    30,
      31,    32,    33,    34,   137,   261,   267,   268,    81,    37,
     134,   285,    82,   135,    63,     4,     5,    83,    84,    85,
      86,    87,    88,   233,    89,     6,     7,    50,   144,    90,
     260,   107,   234,    35,    51,   175,   291,    71,   108,   292,
      91,   296,   176,    41,    37,   313,    70,    92,   299,   300,
     252,   109,   302,     4,     5,   190,   288,   301,   135,   308,
     279,   280,   292,   295,    52,   106,    53,   112,   147,   147,
     312,   115,   128,   121,    72,    73,    74,    75,    76,    77,
      78,   147,   147,    79,    80,   122,   123,   124,   125,   145,
     173,   177,   330,   182,   316,   192,   164,   193,   196,    81,
     203,   222,   204,    82,   226,   225,   235,   227,    83,    84,
      85,    86,    87,    88,   247,    89,   238,   201,   239,   250,
      90,    72,    73,    74,    75,    76,   240,   241,   242,   252,
     257,    91,   146,   265,   249,   266,   269,   270,    92,   271,
      72,    73,    74,    75,    76,   272,    81,   273,   274,   275,
      82,   277,   278,   290,   284,   126,    84,    85,    86,    87,
      88,   294,   293,   297,   305,    81,   298,   307,   309,    82,
     314,   315,   317,   138,   126,    84,    85,    86,    87,    88,
      72,    73,    74,    75,    76,    92,   318,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   319,   258,
     164,   321,   322,   325,    92,    81,   326,   327,   328,    82,
     329,   332,   331,   333,   126,    84,    85,    86,    87,    88,
      72,    73,    74,    75,    76,    20,   334,   335,   336,    59,
     165,   166,    48,   262,   289,   303,   287,   304,   256,   286,
       0,     0,     0,     0,    92,    81,     0,   232,     0,    82,
       0,     0,     0,     0,   126,    84,    85,    86,    87,    88,
      72,    73,    74,    75,    76,     0,     0,     0,     0,    30,
      31,    32,    33,    34,     0,     0,    64,     0,     0,     0,
       0,     0,     0,     0,    92,    81,     0,     0,     0,    82,
       0,     0,     0,     0,   141,    84,    85,    86,    87,    88,
     276,    65,     0,    35,     0,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   164,     0,    92,    66,     0,     0,     0,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,     0,     0,     0,     0,     0,     0,   191,     0,
       0,     0,   165,   166,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   194,     0,
     164,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   320,     0,   165,   166,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,   164,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   165,   166,   164,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,   164,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   165,   166,   164,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
     164,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,     0,     0,     0,     0,     0,
       0,   251,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,   164,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,   164,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166
};

static const yytype_int16 yycheck[] =
{
      53,    79,    94,    92,    49,    77,    50,    35,    80,    81,
      82,    64,     0,    66,    67,    43,     2,    70,    90,    91,
      92,   118,    67,    37,    10,    23,    34,    34,    26,    34,
      58,   109,   122,   123,   124,   125,    29,    30,    31,    67,
     112,    34,    55,   115,   134,    37,   118,    55,    55,   121,
     122,   123,   124,   125,    48,    68,    54,   110,    44,    64,
      65,    55,   134,   107,   136,     3,     4,     5,     6,     7,
      37,    64,    65,    67,    46,    47,    52,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    68,   165,   166,   192,    37,    50,    52,    37,
     190,   173,    37,    52,    55,   177,    37,   204,    27,    28,
      29,    30,    31,   191,    68,    34,   194,    68,   190,    68,
     192,   119,    55,   290,   291,    63,    66,    67,   200,   201,
      70,   175,   204,     3,     4,     5,     6,     7,     8,     9,
     307,   308,    12,    13,    45,    64,    65,   225,    55,     3,
       4,     5,     6,     7,    55,   252,   228,   229,    28,    37,
      67,   250,    32,    70,    37,    46,    47,    37,    38,    39,
      40,    41,    42,    51,    44,    56,    57,    48,   250,    49,
     252,    48,   180,    37,    55,    48,    66,    48,    55,    69,
      60,   269,    55,    36,    37,   292,    49,    67,   276,   277,
      45,    50,   280,    46,    47,    67,    51,   279,    70,    66,
      15,    16,    69,   266,    52,    55,    54,    67,   310,   311,
     292,    17,    37,    67,     3,     4,     5,     6,     7,     8,
       9,   323,   324,    12,    13,    67,    67,    67,    67,    51,
      17,    67,   320,    37,   297,    10,    34,    51,    37,    28,
      37,    37,    45,    32,    51,    50,    55,    68,    37,    38,
      39,    40,    41,    42,    12,    44,    68,    52,    68,    67,
      49,     3,     4,     5,     6,     7,    68,    68,    68,    45,
      55,    60,    61,    37,    68,    11,    50,    68,    67,    58,
       3,     4,     5,     6,     7,    55,    28,    37,    68,    51,
      32,    12,    55,    66,    55,    37,    38,    39,    40,    41,
      42,    55,    51,    11,    51,    28,    12,    66,    60,    32,
      37,    51,    55,    55,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     7,    67,    51,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    51,    62,
      34,    51,    13,    55,    67,    28,    55,    37,    12,    32,
      12,    55,    13,    55,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     7,     7,    55,    55,    55,    44,
      64,    65,    26,   205,   253,   281,   252,   281,   201,    62,
      -1,    -1,    -1,    -1,    67,    28,    -1,   177,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    28,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      12,    35,    -1,    37,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    -1,    67,    59,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    64,    65,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    14,    -1,
      34,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    64,    65,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    64,    65,    34,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    34,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    64,    65,    34,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    72,    74,     0,    46,    47,    56,    57,    73,    75,
      77,    78,    79,    80,    81,    82,    37,    37,    37,    76,
      76,    78,    49,    67,    48,    55,    67,    34,    55,    55,
       3,     4,     5,     6,     7,    37,   119,    37,    90,    91,
      92,    36,    78,    83,    84,    85,    86,    90,    92,    37,
      48,    55,    52,    54,    55,    68,    37,    50,    78,    85,
      55,    68,    83,    37,    10,    35,    59,    63,   119,    90,
      49,    48,     3,     4,     5,     6,     7,     8,     9,    12,
      13,    28,    32,    37,    38,    39,    40,    41,    42,    44,
      49,    60,    67,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   113,   117,    55,    48,    55,    50,
      63,   119,    67,   119,   119,    17,   119,    35,    43,    58,
      67,    67,    67,    67,    67,    67,    37,   117,    37,    93,
     117,   117,   117,    55,    67,    70,    45,    55,    55,   117,
     117,    37,   115,   116,   117,    51,    61,    95,   106,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    34,    64,    65,    83,    93,   119,
      87,   117,   118,    17,   117,    48,    55,    67,   117,   118,
      89,    90,    37,    88,   114,   115,   114,   114,   114,   114,
      67,    12,    10,    51,    14,   114,    37,   117,    55,    48,
      66,    52,    68,    37,    45,   107,   108,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,    37,   117,   117,    50,    51,    68,    52,    53,
     117,    83,    87,    51,    90,    55,    52,    68,    68,    68,
      68,    68,    68,   114,    93,   117,   118,    12,    93,    68,
      67,    55,    45,   104,   105,   117,   116,    55,    62,   109,
     117,   118,   108,    55,    93,    37,    11,   117,   117,    50,
      68,    58,    55,    37,    68,    51,    12,    12,    55,    15,
      16,   110,   111,   112,    55,   115,    62,   109,    51,   105,
      66,    66,    69,    51,    55,   119,    93,    11,    12,    93,
      93,   117,    93,   111,   112,    51,    68,    66,    66,    60,
      94,    94,   117,   118,    37,    51,   119,    55,    51,    51,
      14,    51,    13,    94,    94,    55,    55,    37,    12,    12,
      93,    13,    55,    55,    55,    55,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    84,    84,
      85,    85,    86,    86,    86,    86,    87,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    99,   100,   101,   101,   102,
     102,   103,   104,   104,   105,   105,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   114,   114,   115,   115,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   118,   119,   119,   119,   119,   119,   119
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
#line 133 "pars.y"
                                  { (yyval.prg) = global_program = (yyvsp[0].prg); }
#line 1515 "pars.tab.c"
    break;

  case 3: /* program_body: item_list  */
#line 136 "pars.y"
                  { (yyval.prg) = new ProgramNode((yyvsp[0].itemlst)); }
#line 1521 "pars.tab.c"
    break;

  case 10: /* item_list: item  */
#line 150 "pars.y"
                 {(yyval.itemlst) = new ItemListNode((yyvsp[0].item));}
#line 1527 "pars.tab.c"
    break;

  case 11: /* item_list: item_list item  */
#line 151 "pars.y"
                           { (yyval.itemlst) = ItemListNode::Append((yyvsp[-1].itemlst), (yyvsp[0].item)); }
#line 1533 "pars.tab.c"
    break;

  case 12: /* item: func_declaration  */
#line 153 "pars.y"
                       {(yyval.item) = (yyvsp[0].item);}
#line 1539 "pars.tab.c"
    break;

  case 13: /* item: proc_declaration  */
#line 154 "pars.y"
                       {(yyval.item) = (yyvsp[0].item);}
#line 1545 "pars.tab.c"
    break;

  case 14: /* item: func_implementation  */
#line 155 "pars.y"
                          {(yyval.item) = (yyvsp[0].item);}
#line 1551 "pars.tab.c"
    break;

  case 15: /* item: proc_implementation  */
#line 156 "pars.y"
                          {(yyval.item) = (yyvsp[0].item);}
#line 1557 "pars.tab.c"
    break;

  case 16: /* func_declaration: FUNCTION ID '(' func_param_list ')' RETURN var_type ';'  */
#line 158 "pars.y"
                                                                          {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-6].id_const), (yyvsp[-4].param_lst), (yyvsp[-1].v_type), NULL, NULL);}
#line 1563 "pars.tab.c"
    break;

  case 17: /* func_declaration: FUNCTION ID RETURN var_type ';'  */
#line 159 "pars.y"
                                                  {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_dec, (yyvsp[-3].id_const), NULL, (yyvsp[-1].v_type), NULL, NULL);}
#line 1569 "pars.tab.c"
    break;

  case 18: /* proc_declaration: PROCEDURE ID '(' func_param_list ')' ';'  */
#line 161 "pars.y"
                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-4].id_const), (yyvsp[-2].param_lst), NULL, NULL, NULL);}
#line 1575 "pars.tab.c"
    break;

  case 19: /* proc_declaration: PROCEDURE ID ';'  */
#line 162 "pars.y"
                                   {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_dec, (yyvsp[-1].id_const), NULL, NULL, NULL, NULL);}
#line 1581 "pars.tab.c"
    break;

  case 20: /* func_implementation: FUNCTION ID '(' func_param_list ')' RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 164 "pars.y"
                                                                                                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-12].id_const), (yyvsp[-10].param_lst), (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1587 "pars.tab.c"
    break;

  case 21: /* func_implementation: FUNCTION ID RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 165 "pars.y"
                                                                                                               {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::func_imp, (yyvsp[-9].id_const), NULL, (yyvsp[-7].v_type), (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1593 "pars.tab.c"
    break;

  case 22: /* proc_implementation: PROCEDURE ID '(' func_param_list ')' IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 167 "pars.y"
                                                                                                                           {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-10].id_const), (yyvsp[-8].param_lst), NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1599 "pars.tab.c"
    break;

  case 23: /* proc_implementation: PROCEDURE ID IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'  */
#line 168 "pars.y"
                                                                                                {(yyval.item) = new SubProgramItemNode(SubProgramItemNode::proc_imp, (yyvsp[-7].id_const), NULL, NULL, (yyvsp[-5].decl_lst), (yyvsp[-3].stmt_lst));}
#line 1605 "pars.tab.c"
    break;

  case 24: /* declaration_list_empty: %empty  */
#line 171 "pars.y"
                      { (yyval.decl_lst) = 0; }
#line 1611 "pars.tab.c"
    break;

  case 25: /* declaration_list_empty: decl_body_list  */
#line 172 "pars.y"
                           { (yyval.decl_lst) = 0; }
#line 1617 "pars.tab.c"
    break;

  case 26: /* decl_body_list: declaration ';'  */
#line 175 "pars.y"
                                            { }
#line 1623 "pars.tab.c"
    break;

  case 27: /* decl_body_list: item  */
#line 176 "pars.y"
                                            { }
#line 1629 "pars.tab.c"
    break;

  case 28: /* decl_body_list: decl_body_list declaration ';'  */
#line 177 "pars.y"
                                            { }
#line 1635 "pars.tab.c"
    break;

  case 29: /* decl_body_list: decl_body_list item  */
#line 178 "pars.y"
                                            { }
#line 1641 "pars.tab.c"
    break;

  case 30: /* declaration: type_declaration  */
#line 180 "pars.y"
                              {(yyval.decl) = (yyvsp[0].decl);}
#line 1647 "pars.tab.c"
    break;

  case 31: /* declaration: var_declaration  */
#line 181 "pars.y"
                              {(yyval.decl) = (yyvsp[0].decl);}
#line 1653 "pars.tab.c"
    break;

  case 32: /* type_declaration: TYPE ID IS ARRAY '(' array_index_list ')' OF var_type  */
#line 185 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1659 "pars.tab.c"
    break;

  case 33: /* type_declaration: TYPE ID IS '(' enum_id_list ')'  */
#line 187 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1665 "pars.tab.c"
    break;

  case 34: /* type_declaration: TYPE ID IS RANGE range  */
#line 189 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1671 "pars.tab.c"
    break;

  case 35: /* type_declaration: TYPE ID IS RECORD record_field_list END RECORD  */
#line 191 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::type_dec);}
#line 1677 "pars.tab.c"
    break;

  case 41: /* record_field_list: var_declaration ';'  */
#line 203 "pars.y"
                            { }
#line 1683 "pars.tab.c"
    break;

  case 42: /* record_field_list: record_field_list var_declaration ';'  */
#line 204 "pars.y"
                                              { }
#line 1689 "pars.tab.c"
    break;

  case 43: /* var_declaration: var_list ':' var_type  */
#line 208 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclaration (DeclarationNode::var_dec, (yyvsp[-2].var_lst),(yyvsp[0].v_type));}
#line 1695 "pars.tab.c"
    break;

  case 44: /* var_declaration: var_list ':' IN var_type  */
#line 210 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1701 "pars.tab.c"
    break;

  case 45: /* var_declaration: var_list ':' OUT var_type  */
#line 212 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1707 "pars.tab.c"
    break;

  case 46: /* var_declaration: var_list ':' IN OUT var_type  */
#line 214 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1713 "pars.tab.c"
    break;

  case 47: /* var_declaration: var_list ':' CONSTANT var_type  */
#line 216 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclaration (DeclarationNode::var_dec, (yyvsp[-3].var_lst),(yyvsp[0].v_type));}
#line 1719 "pars.tab.c"
    break;

  case 48: /* var_declaration: var_list ':' CONSTANT var_type ASSIGNMENT expression  */
#line 218 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclarationAssignment (DeclarationNode::var_dec, (yyvsp[-5].var_lst),(yyvsp[-2].v_type),(yyvsp[0].expr));}
#line 1725 "pars.tab.c"
    break;

  case 49: /* var_declaration: var_list ':' ARRAY '(' array_index_list ')' OF var_type  */
#line 220 "pars.y"
        {(yyval.decl) = new DeclarationNode(DeclarationNode::var_dec);}
#line 1731 "pars.tab.c"
    break;

  case 50: /* var_declaration: var_list ':' var_type ASSIGNMENT expression  */
#line 222 "pars.y"
        {(yyval.decl) = DeclarationNode::VarDeclarationAssignment (DeclarationNode::var_dec, (yyvsp[-4].var_lst),(yyvsp[-2].v_type),(yyvsp[0].expr));}
#line 1737 "pars.tab.c"
    break;

  case 51: /* var_list: ID  */
#line 224 "pars.y"
              { (yyval.var_lst) = new VarListNode((yyvsp[0].id_const));}
#line 1743 "pars.tab.c"
    break;

  case 52: /* var_list: var_list ',' ID  */
#line 225 "pars.y"
                            { (yyval.var_lst) = VarListNode::Append((yyvsp[-2].var_lst), (yyvsp[0].id_const)); }
#line 1749 "pars.tab.c"
    break;

  case 53: /* func_param_list: var_declaration  */
#line 227 "pars.y"
                                 {(yyval.param_lst) = new FuncParamListNode((yyvsp[0].decl));}
#line 1755 "pars.tab.c"
    break;

  case 54: /* func_param_list: func_param_list ';' var_declaration  */
#line 228 "pars.y"
                                                       { (yyval.param_lst) = FuncParamListNode::Append((yyvsp[-2].param_lst), (yyvsp[0].decl)); }
#line 1761 "pars.tab.c"
    break;

  case 55: /* stmt_list_empty: %empty  */
#line 231 "pars.y"
                                { (yyval.stmt_lst) = 0; }
#line 1767 "pars.tab.c"
    break;

  case 56: /* stmt_list_empty: stmt_list  */
#line 232 "pars.y"
                                     { (yyval.stmt_lst) = new StmtListNode((yyvsp[0].stmt_lst)); }
#line 1773 "pars.tab.c"
    break;

  case 57: /* stmt_list_empty: stmt_list exception_part  */
#line 233 "pars.y"
                                     { (yyval.stmt_lst) = new StmtListNode((yyvsp[-1].stmt_lst)); }
#line 1779 "pars.tab.c"
    break;

  case 58: /* stmt_list: stmt  */
#line 235 "pars.y"
                 { (yyval.stmt_lst) = new StmtListNode((yyvsp[0].stmt)); }
#line 1785 "pars.tab.c"
    break;

  case 59: /* stmt_list: stmt_list stmt  */
#line 236 "pars.y"
                           { (yyval.stmt_lst) = StmtListNode::Append((yyvsp[-1].stmt_lst), (yyvsp[0].stmt)); }
#line 1791 "pars.tab.c"
    break;

  case 60: /* stmt: return_stmt  */
#line 238 "pars.y"
                   {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1797 "pars.tab.c"
    break;

  case 61: /* stmt: loop_stmt  */
#line 239 "pars.y"
                {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1803 "pars.tab.c"
    break;

  case 62: /* stmt: ID '(' expression_list_empty ')' ';'  */
#line 240 "pars.y"
                                           {(yyval.stmt) = StmtNode:: StmtFromIdAndExpr ((yyvsp[-4].id_const),(yyvsp[-2].expr_list));}
#line 1809 "pars.tab.c"
    break;

  case 63: /* stmt: if_stmt  */
#line 241 "pars.y"
               {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1815 "pars.tab.c"
    break;

  case 64: /* stmt: exit_stmt  */
#line 242 "pars.y"
                 {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1821 "pars.tab.c"
    break;

  case 65: /* stmt: assigment_stmt  */
#line 243 "pars.y"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1827 "pars.tab.c"
    break;

  case 66: /* stmt: case_stmt  */
#line 244 "pars.y"
                {(yyval.stmt) = 0;}
#line 1833 "pars.tab.c"
    break;

  case 67: /* stmt: ID ';'  */
#line 245 "pars.y"
             {(yyval.stmt) = StmtNode:: StmtFromIdAndExpr ((yyvsp[-1].id_const), NULL);}
#line 1839 "pars.tab.c"
    break;

  case 68: /* return_stmt: RETURN expression ';'  */
#line 247 "pars.y"
                                    {(yyval.stmt) = StmtNode:: StmtFromReturn ((yyvsp[-1].expr));}
#line 1845 "pars.tab.c"
    break;

  case 69: /* return_stmt: RETURN ';'  */
#line 248 "pars.y"
                         {(yyval.stmt) = StmtNode:: StmtFromReturn (NULL);}
#line 1851 "pars.tab.c"
    break;

  case 70: /* loop_stmt: while_stmt  */
#line 250 "pars.y"
                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1857 "pars.tab.c"
    break;

  case 71: /* loop_stmt: for_stmt  */
#line 251 "pars.y"
                    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1863 "pars.tab.c"
    break;

  case 72: /* loop_stmt: simple_loop_stmt  */
#line 252 "pars.y"
                            {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1869 "pars.tab.c"
    break;

  case 73: /* for_stmt: FOR ID IN range LOOP stmt_list_empty END LOOP ';'  */
#line 256 "pars.y"
        {(yyval.stmt) = StmtNode:: StmtFromForLoop ((yyvsp[-7].id_const),(yyvsp[-5].rng),(yyvsp[-3].stmt_lst));}
#line 1875 "pars.tab.c"
    break;

  case 74: /* for_stmt: FOR ID IN expression LOOP stmt_list_empty END LOOP ';'  */
#line 258 "pars.y"
        {(yyval.stmt) = StmtNode:: StmtFromForLoop ((yyvsp[-7].id_const), NULL, (yyvsp[-3].stmt_lst));}
#line 1881 "pars.tab.c"
    break;

  case 75: /* while_stmt: WHILE expression LOOP stmt_list_empty END LOOP ';'  */
#line 260 "pars.y"
                                                               {(yyval.stmt) = StmtNode:: StmtFromWhileLoop ((yyvsp[-5].expr),(yyvsp[-3].stmt_lst));}
#line 1887 "pars.tab.c"
    break;

  case 76: /* simple_loop_stmt: LOOP stmt_list_empty END LOOP ';'  */
#line 262 "pars.y"
                                                    {(yyval.stmt) = StmtNode:: StmtFromSimpleLoop ((yyvsp[-3].stmt_lst));}
#line 1893 "pars.tab.c"
    break;

  case 77: /* exit_stmt: EXIT ';'  */
#line 264 "pars.y"
                    {(yyval.stmt) = StmtNode:: StmtFromExit (NULL);}
#line 1899 "pars.tab.c"
    break;

  case 78: /* exit_stmt: EXIT WHEN expression ';'  */
#line 265 "pars.y"
                                   {(yyval.stmt) = StmtNode:: StmtFromExit ((yyvsp[-1].expr));}
#line 1905 "pars.tab.c"
    break;

  case 79: /* if_stmt: IF expression THEN stmt_list_empty elsif_stmt_list else_stmt END IF ';'  */
#line 267 "pars.y"
                                                                                  {(yyval.stmt) = StmtNode:: StmtFromIfWithElsif ((yyvsp[-7].expr), (yyvsp[-5].stmt_lst), (yyvsp[-4].elsf_lst_stmt), (yyvsp[-3].els_stmt));}
#line 1911 "pars.tab.c"
    break;

  case 80: /* if_stmt: IF expression THEN stmt_list_empty else_stmt END IF ';'  */
#line 268 "pars.y"
                                                                        {(yyval.stmt) = StmtNode:: StmtFromIf ((yyvsp[-6].expr), (yyvsp[-4].stmt_lst), (yyvsp[-3].els_stmt));}
#line 1917 "pars.tab.c"
    break;

  case 81: /* case_stmt: CASE expression IS case_alternative_list END CASE ';'  */
#line 272 "pars.y"
        {(yyval.stmt) = 0;}
#line 1923 "pars.tab.c"
    break;

  case 86: /* exception_part: EXCEPTION exception_handler_list  */
#line 283 "pars.y"
                                         { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 1929 "pars.tab.c"
    break;

  case 89: /* exception_handler: WHEN choice_list ARROW stmt_list  */
#line 290 "pars.y"
                                         { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 1935 "pars.tab.c"
    break;

  case 90: /* exception_handler: WHEN OTHERS ARROW stmt_list  */
#line 291 "pars.y"
                                         { (yyval.stmt_lst) = (yyvsp[0].stmt_lst); }
#line 1941 "pars.tab.c"
    break;

  case 95: /* elsif_stmt_list: elsif_stmt  */
#line 299 "pars.y"
                            { (yyval.elsf_lst_stmt) = new ElsifStmtListNode((yyvsp[0].elsf_stmt)); }
#line 1947 "pars.tab.c"
    break;

  case 96: /* elsif_stmt_list: elsif_stmt_list elsif_stmt  */
#line 300 "pars.y"
                                             { (yyval.elsf_lst_stmt) = ElsifStmtListNode::Append((yyvsp[-1].elsf_lst_stmt), (yyvsp[0].elsf_stmt)); }
#line 1953 "pars.tab.c"
    break;

  case 97: /* elsif_stmt: ELSIF expression THEN stmt_list_empty  */
#line 302 "pars.y"
                                                       { (yyval.elsf_stmt) = new ElsifStmtNode((yyvsp[-2].expr), (yyvsp[0].stmt_lst)); }
#line 1959 "pars.tab.c"
    break;

  case 98: /* else_stmt: %empty  */
#line 304 "pars.y"
                       { (yyval.els_stmt) = 0; }
#line 1965 "pars.tab.c"
    break;

  case 99: /* else_stmt: ELSE stmt_list_empty  */
#line 305 "pars.y"
                                    { (yyval.els_stmt) = new ElseStmtNode((yyvsp[0].stmt_lst)); }
#line 1971 "pars.tab.c"
    break;

  case 100: /* assigment_stmt: expression ASSIGNMENT expression ';'  */
#line 307 "pars.y"
                                                     {(yyval.stmt) = StmtNode:: StmtFromAssigment ((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1977 "pars.tab.c"
    break;

  case 101: /* expression_list_empty: %empty  */
#line 309 "pars.y"
                                { (yyval.expr_list) = 0; }
#line 1983 "pars.tab.c"
    break;

  case 102: /* expression_list_empty: expression_list  */
#line 310 "pars.y"
                                     { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr_list)); }
#line 1989 "pars.tab.c"
    break;

  case 103: /* expression_list: arg  */
#line 313 "pars.y"
                                { (yyval.expr_list) = new ExprListNode((yyvsp[0].expr)); }
#line 1995 "pars.tab.c"
    break;

  case 104: /* expression_list: expression_list ',' arg  */
#line 314 "pars.y"
                                { (yyval.expr_list) = ExprListNode::Append((yyvsp[-2].expr_list), (yyvsp[0].expr)); }
#line 2001 "pars.tab.c"
    break;

  case 105: /* arg: expression  */
#line 317 "pars.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2007 "pars.tab.c"
    break;

  case 106: /* arg: ID ARROW expression  */
#line 318 "pars.y"
                                { (yyval.expr) = ExprNode::ExprFromId (ExprNode::id_,(yyvsp[-2].id_const)); }
#line 2013 "pars.tab.c"
    break;

  case 107: /* expression: CONST_BOOL  */
#line 320 "pars.y"
                       {(yyval.expr) = ExprNode::ExprFromBoolConst (ExprNode::const_bool,(yyvsp[0].int_const)); }
#line 2019 "pars.tab.c"
    break;

  case 108: /* expression: CONST_CHARACTER  */
#line 321 "pars.y"
                            {(yyval.expr) = ExprNode::ExprFromCharConst (ExprNode::const_character,(yyvsp[0].char_const)); }
#line 2025 "pars.tab.c"
    break;

  case 109: /* expression: CONST_STRING  */
#line 322 "pars.y"
                         {(yyval.expr) = ExprNode::ExprFromStringConst (ExprNode::const_string,(yyvsp[0].string_const)); }
#line 2031 "pars.tab.c"
    break;

  case 110: /* expression: CONST_INTEGER  */
#line 323 "pars.y"
                          {(yyval.expr) = ExprNode::ExprFromIntConst (ExprNode::const_integer,(yyvsp[0].int_const)); }
#line 2037 "pars.tab.c"
    break;

  case 111: /* expression: CONST_FLOAT  */
#line 324 "pars.y"
                        {(yyval.expr) = ExprNode::ExprFromFloatConst (ExprNode::const_float,(yyvsp[0].float_const)); }
#line 2043 "pars.tab.c"
    break;

  case 112: /* expression: ID  */
#line 325 "pars.y"
               {(yyval.expr) = ExprNode::ExprFromId (ExprNode::id_,(yyvsp[0].id_const)); }
#line 2049 "pars.tab.c"
    break;

  case 113: /* expression: expression '>' expression  */
#line 326 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_more_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2055 "pars.tab.c"
    break;

  case 114: /* expression: expression '<' expression  */
#line 327 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_less_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2061 "pars.tab.c"
    break;

  case 115: /* expression: expression MORE_OR_EQUAL expression  */
#line 328 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_more_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2067 "pars.tab.c"
    break;

  case 116: /* expression: expression LESS_OR_EQUAL expression  */
#line 329 "pars.y"
                                                {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_less_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2073 "pars.tab.c"
    break;

  case 117: /* expression: expression '=' expression  */
#line 330 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2079 "pars.tab.c"
    break;

  case 118: /* expression: expression NOT_EQUAL expression  */
#line 331 "pars.y"
                                            {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_not_equal_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2085 "pars.tab.c"
    break;

  case 119: /* expression: expression '+' expression  */
#line 332 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_plus_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2091 "pars.tab.c"
    break;

  case 120: /* expression: expression '-' expression  */
#line 333 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_minus_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2097 "pars.tab.c"
    break;

  case 121: /* expression: expression '*' expression  */
#line 334 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_mult_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2103 "pars.tab.c"
    break;

  case 122: /* expression: expression MOD expression  */
#line 335 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_mult_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2109 "pars.tab.c"
    break;

  case 123: /* expression: expression REM expression  */
#line 336 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_mult_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2115 "pars.tab.c"
    break;

  case 124: /* expression: expression '/' expression  */
#line 337 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_div_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2121 "pars.tab.c"
    break;

  case 125: /* expression: expression ABS expression  */
#line 338 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_abs_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2127 "pars.tab.c"
    break;

  case 126: /* expression: '-' expression  */
#line 339 "pars.y"
                                        {(yyval.expr) = ExprNode::ExprOperation (ExprNode::uminus_expr,(yyvsp[0].expr), NULL); }
#line 2133 "pars.tab.c"
    break;

  case 127: /* expression: expression OR expression  */
#line 340 "pars.y"
                                     {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_or_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2139 "pars.tab.c"
    break;

  case 128: /* expression: expression AND expression  */
#line 341 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_and_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2145 "pars.tab.c"
    break;

  case 129: /* expression: expression XOR expression  */
#line 342 "pars.y"
                                      {(yyval.expr) = ExprNode::ExprOperation (ExprNode::expr_xor_expr,(yyvsp[-2].expr),(yyvsp[0].expr)); }
#line 2151 "pars.tab.c"
    break;

  case 130: /* expression: NOT expression  */
#line 343 "pars.y"
                           {(yyval.expr) = ExprNode::ExprOperation (ExprNode::not_expr,(yyvsp[0].expr), NULL); }
#line 2157 "pars.tab.c"
    break;

  case 131: /* expression: ID '(' expression_list_empty ')'  */
#line 344 "pars.y"
                                              {(yyval.expr) = ExprNode::ExprFromFuncCall (ExprNode::func_call,(yyvsp[-3].id_const), (yyvsp[-1].expr_list)); }
#line 2163 "pars.tab.c"
    break;

  case 132: /* expression: INTEGER '(' expression_list_empty ')'  */
#line 345 "pars.y"
                                                   {(yyval.expr) = 0; }
#line 2169 "pars.tab.c"
    break;

  case 133: /* expression: FLOAT '(' expression_list_empty ')'  */
#line 346 "pars.y"
                                                   {(yyval.expr) = 0; }
#line 2175 "pars.tab.c"
    break;

  case 134: /* expression: BOOLEAN '(' expression_list_empty ')'  */
#line 347 "pars.y"
                                                   {(yyval.expr) = 0; }
#line 2181 "pars.tab.c"
    break;

  case 135: /* expression: CHARACTER '(' expression_list_empty ')'  */
#line 348 "pars.y"
                                                    {(yyval.expr) = 0; }
#line 2187 "pars.tab.c"
    break;

  case 136: /* expression: STRING '(' expression_list_empty ')'  */
#line 349 "pars.y"
                                                   {(yyval.expr) = 0; }
#line 2193 "pars.tab.c"
    break;

  case 137: /* expression: expression '.' ID  */
#line 350 "pars.y"
                                        {(yyval.expr) = ExprNode::ExprOperation (ExprNode::id_,(yyvsp[-2].expr), NULL); }
#line 2199 "pars.tab.c"
    break;

  case 138: /* expression: ID '\'' ID  */
#line 351 "pars.y"
                       {(yyval.expr) = ExprNode::ExprFromId (ExprNode::id_,(yyvsp[-2].id_const)); }
#line 2205 "pars.tab.c"
    break;

  case 139: /* expression: ID '\'' ID '(' expression_list ')'  */
#line 352 "pars.y"
                                               {(yyval.expr) = ExprNode::ExprFromFuncCall (ExprNode::func_call,(yyvsp[-5].id_const), (yyvsp[-1].expr_list)); }
#line 2211 "pars.tab.c"
    break;

  case 140: /* expression: '(' expression_list ')'  */
#line 353 "pars.y"
                                    {(yyval.expr) = ExprNode::ExprFromExprLiteral (ExprNode::literal,(yyvsp[-1].expr_list)); }
#line 2217 "pars.tab.c"
    break;

  case 141: /* range: expression DOUBLE_DOT expression  */
#line 355 "pars.y"
                                          {(yyval.rng) = new RangeNode((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2223 "pars.tab.c"
    break;

  case 142: /* var_type: INTEGER  */
#line 357 "pars.y"
                  { (yyval.v_type) = new TypeNode(TypeNode::const_integer); }
#line 2229 "pars.tab.c"
    break;

  case 143: /* var_type: BOOLEAN  */
#line 358 "pars.y"
              { (yyval.v_type) = new TypeNode(TypeNode::const_bool); }
#line 2235 "pars.tab.c"
    break;

  case 144: /* var_type: FLOAT  */
#line 359 "pars.y"
            { (yyval.v_type) = new TypeNode(TypeNode::const_float); }
#line 2241 "pars.tab.c"
    break;

  case 145: /* var_type: CHARACTER  */
#line 360 "pars.y"
                { (yyval.v_type) = new TypeNode(TypeNode::const_character); }
#line 2247 "pars.tab.c"
    break;

  case 146: /* var_type: STRING  */
#line 361 "pars.y"
             { (yyval.v_type) = new TypeNode(TypeNode::const_string); }
#line 2253 "pars.tab.c"
    break;

  case 147: /* var_type: ID  */
#line 362 "pars.y"
         { (yyval.v_type) = new TypeNode(TypeNode::id_,(yyvsp[0].id_const)); }
#line 2259 "pars.tab.c"
    break;


#line 2263 "pars.tab.c"

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

#line 364 "pars.y"

