/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */


#pragma warning(disable : 4065 4102)

#define YYERROR_VERBOSE
#define YYINCLUDED_STDLIB_H
#define YYDEBUG			1

#include <nms_common.h>
#include "libnxsl.h"
#include "parser.tab.hpp"

void yyerror(yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler,
             NXSL_Program *pScript, const char *pszText);
int yylex(YYSTYPE *lvalp, yyscan_t scanner);


#line 84 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_ABORT = 258,
    T_ARRAY = 259,
    T_BREAK = 260,
    T_CASE = 261,
    T_CATCH = 262,
    T_CONST = 263,
    T_CONTINUE = 264,
    T_DEFAULT = 265,
    T_DO = 266,
    T_ELSE = 267,
    T_EXIT = 268,
    T_FALSE = 269,
    T_FOR = 270,
    T_FOREACH = 271,
    T_GLOBAL = 272,
    T_IF = 273,
    T_NULL = 274,
    T_PRINT = 275,
    T_PRINTLN = 276,
    T_RETURN = 277,
    T_SELECT = 278,
    T_SUB = 279,
    T_SWITCH = 280,
    T_TRUE = 281,
    T_TRY = 282,
    T_TYPE_INT32 = 283,
    T_TYPE_INT64 = 284,
    T_TYPE_REAL = 285,
    T_TYPE_STRING = 286,
    T_TYPE_UINT32 = 287,
    T_TYPE_UINT64 = 288,
    T_USE = 289,
    T_WHEN = 290,
    T_WHILE = 291,
    T_COMPOUND_IDENTIFIER = 292,
    T_IDENTIFIER = 293,
    T_STRING = 294,
    T_INT32 = 295,
    T_UINT32 = 296,
    T_INT64 = 297,
    T_UINT64 = 298,
    T_REAL = 299,
    T_ASSIGN_ADD = 300,
    T_ASSIGN_SUB = 301,
    T_ASSIGN_MUL = 302,
    T_ASSIGN_DIV = 303,
    T_ASSIGN_REM = 304,
    T_ASSIGN_CONCAT = 305,
    T_ASSIGN_AND = 306,
    T_ASSIGN_OR = 307,
    T_ASSIGN_XOR = 308,
    T_OR = 309,
    T_AND = 310,
    T_NE = 311,
    T_EQ = 312,
    T_LIKE = 313,
    T_ILIKE = 314,
    T_MATCH = 315,
    T_IMATCH = 316,
    T_LE = 317,
    T_GE = 318,
    T_LSHIFT = 319,
    T_RSHIFT = 320,
    T_INC = 321,
    T_DEC = 322,
    NEGATE = 323,
    T_REF = 324,
    T_POST_INC = 325,
    T_POST_DEC = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "parser.y" /* yacc.c:355  */

	INT32 valInt32;
	UINT32 valUInt32;
	INT64 valInt64;
	UINT64 valUInt64;
	char *valStr;
	double valReal;
	NXSL_Value *pConstant;
	NXSL_Instruction *pInstruction;

#line 207 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler, NXSL_Program *pScript);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  137
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1844

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  255
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  438

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,     2,    97,     2,    79,    62,     2,
      96,    93,    77,    75,    92,    76,    57,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    91,
      69,    45,    71,    56,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,    60,    95,    83,     2,     2,     2,
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
      46,    47,    48,    49,    50,    51,    52,    53,    54,    58,
      59,    63,    64,    65,    66,    67,    68,    70,    72,    73,
      74,    80,    81,    84,    85,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   133,   148,   164,   165,   169,   170,   171,
     172,   176,   180,   181,   185,   199,   207,   208,   213,   212,
     234,   235,   240,   239,   245,   253,   257,   258,   262,   263,
     264,   269,   273,   268,   285,   289,   290,   297,   298,   303,
     303,   309,   309,   315,   315,   321,   321,   327,   327,   333,
     333,   339,   339,   345,   345,   351,   351,   357,   357,   362,
     362,   367,   367,   372,   372,   377,   377,   382,   382,   387,
     387,   392,   392,   397,   397,   402,   406,   406,   411,   411,
     416,   416,   421,   421,   426,   426,   431,   431,   436,   436,
     441,   441,   446,   450,   454,   458,   463,   468,   473,   478,
     483,   487,   491,   495,   500,   505,   510,   515,   519,   523,
     527,   531,   535,   539,   543,   547,   551,   555,   559,   563,
     567,   571,   575,   579,   583,   587,   591,   595,   599,   603,
     607,   611,   615,   619,   619,   624,   624,   629,   633,   637,
     642,   646,   641,   654,   658,   659,   660,   661,   662,   667,
     672,   680,   688,   687,   692,   700,   699,   704,   712,   711,
     716,   723,   724,   728,   734,   738,   742,   746,   750,   754,
     761,   762,   763,   764,   765,   766,   767,   768,   769,   770,
     771,   772,   785,   801,   806,   815,   819,   823,   827,   834,
     840,   849,   848,   856,   860,   868,   867,   877,   882,   888,
     876,   906,   911,   905,   929,   934,   928,   947,   946,   961,
     960,   973,   972,   978,   986,   985,   993,   992,  1002,  1003,
    1008,  1007,  1027,  1029,  1035,  1039,  1047,  1050,  1046,  1068,
    1068,  1069,  1069,  1073,  1077,  1078,  1082,  1087,  1095,  1100,
    1108,  1109,  1113,  1114,  1122,  1129,  1134,  1138,  1143,  1147,
    1151,  1155,  1159,  1163,  1167,  1171
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ABORT", "T_ARRAY", "T_BREAK",
  "T_CASE", "T_CATCH", "T_CONST", "T_CONTINUE", "T_DEFAULT", "T_DO",
  "T_ELSE", "T_EXIT", "T_FALSE", "T_FOR", "T_FOREACH", "T_GLOBAL", "T_IF",
  "T_NULL", "T_PRINT", "T_PRINTLN", "T_RETURN", "T_SELECT", "T_SUB",
  "T_SWITCH", "T_TRUE", "T_TRY", "T_TYPE_INT32", "T_TYPE_INT64",
  "T_TYPE_REAL", "T_TYPE_STRING", "T_TYPE_UINT32", "T_TYPE_UINT64",
  "T_USE", "T_WHEN", "T_WHILE", "T_COMPOUND_IDENTIFIER", "T_IDENTIFIER",
  "T_STRING", "T_INT32", "T_UINT32", "T_INT64", "T_UINT64", "T_REAL",
  "'='", "T_ASSIGN_ADD", "T_ASSIGN_SUB", "T_ASSIGN_MUL", "T_ASSIGN_DIV",
  "T_ASSIGN_REM", "T_ASSIGN_CONCAT", "T_ASSIGN_AND", "T_ASSIGN_OR",
  "T_ASSIGN_XOR", "':'", "'?'", "'.'", "T_OR", "T_AND", "'|'", "'^'",
  "'&'", "T_NE", "T_EQ", "T_LIKE", "T_ILIKE", "T_MATCH", "T_IMATCH", "'<'",
  "T_LE", "'>'", "T_GE", "T_LSHIFT", "T_RSHIFT", "'+'", "'-'", "'*'",
  "'/'", "'%'", "T_INC", "T_DEC", "'!'", "'~'", "NEGATE", "T_REF", "'@'",
  "T_POST_INC", "T_POST_DEC", "'['", "']'", "';'", "','", "')'", "'{'",
  "'}'", "'('", "'#'", "$accept", "Script", "Module", "ModuleComponent",
  "ConstStatement", "ConstList", "ConstDefinition", "UseStatement",
  "AnyIdentifier", "Function", "$@1", "ParameterDeclaration",
  "IdentifierList", "$@2", "Block", "StatementList", "StatementOrBlock",
  "TryCatchBlock", "$@3", "$@4", "Statement", "Expression", "$@5", "$@6",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33",
  "$@34", "Operand", "TypeCast", "ArrayInitializer", "$@35",
  "ArrayElements", "$@36", "HashMapInitializer", "$@37", "HashMapElements",
  "HashMapElement", "BuiltinType", "BuiltinStatement", "SimpleStatement",
  "SimpleStatementKeyword", "PrintlnStatement", "IfStatement", "$@38",
  "IfBody", "ElseStatement", "$@39", "ForStatement", "$@40", "$@41",
  "$@42", "ForEachStatement", "$@43", "$@44", "WhileStatement", "$@45",
  "$@46", "DoStatement", "$@47", "SwitchStatement", "$@48", "CaseList",
  "$@49", "Case", "$@50", "$@51", "Default", "SelectStatement", "$@52",
  "SelectOptions", "SelectList", "SelectEntry", "$@53", "$@54",
  "ArrayStatement", "$@55", "$@56", "GlobalStatement",
  "GlobalVariableList", "GlobalVariableDeclaration", "FunctionCall",
  "ParameterList", "Parameter", "FunctionName", "StorageItem", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    61,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    58,    63,    46,   309,   310,
     124,    94,    38,   311,   312,   313,   314,   315,   316,    60,
     317,    62,   318,   319,   320,    43,    45,    42,    47,    37,
     321,   322,    33,   126,   323,   324,    64,   325,   326,    91,
      93,    59,    44,    41,   123,   125,    40,    35
};
# endif

#define YYPACT_NINF -200

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-200)))

#define YYTABLE_NINF -212

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     421,  -200,  -200,   -52,     4,   -50,  -200,  -200,  -200,   -42,
     -41,    11,   -39,  -200,  -200,    -7,  -200,  -200,    21,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   -21,  -200,
    -200,   193,  -200,  -200,  -200,  -200,  -200,  -200,   650,   -56,
     -30,   -11,   650,   650,  -200,   516,   650,   -28,    60,  -200,
     421,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  1182,  -200,
    -200,  -200,  -200,   -35,  -200,   -26,   650,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   547,    56,
    -200,    25,  -200,    32,     6,   -22,  -200,   516,   650,    53,
    -200,    49,     7,     8,   650,  -200,  1218,    57,    23,  -200,
      24,     2,  -200,  -200,    30,    26,   650,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   650,  -200,
     -71,    31,    34,  -200,   650,  -200,  -200,   650,  -200,   -71,
     -71,    35,   516,  1182,   764,  -200,   650,  -200,  -200,  -200,
     650,  -200,  -200,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,    87,   650,  -200,   650,  -200,   711,   141,
    -200,   711,    38,    41,   650,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,    42,    47,  1665,  -200,
       4,   103,  1254,  -200,    25,   650,  -200,   102,   802,  -200,
      46,   -29,   650,   136,  -200,   650,   711,   650,   650,   650,
     650,   650,   650,   650,   650,   650,    55,  -200,   650,  -200,
     650,  1501,  1535,  -200,  -200,  -200,   840,   650,  1567,   650,
     650,  1679,  1707,  1734,  1755,  1755,  1755,  1755,  1755,  1755,
      39,    39,    39,    39,     3,     3,   -33,   -33,   -71,   -71,
     -71,   -34,   619,  1326,   878,   650,  -200,   722,   711,   650,
     650,   650,   650,   650,   650,   650,   650,   650,    54,  -200,
    -200,  -200,    72,  -200,   115,    81,   711,  -200,  -200,   650,
      79,  -200,     2,    82,   916,  -200,   954,   711,   711,   711,
     711,   711,   711,   711,   711,   711,  1362,    83,    84,   992,
      88,   650,   650,  -200,  1397,  1598,  1650,   650,  -200,    89,
     425,  -200,   711,  -200,   711,   711,   711,   711,   711,   711,
     711,   711,   711,    25,   650,   650,   650,  -200,   516,  1030,
     139,  -200,  -200,    86,     2,  -200,   650,  -200,   650,    85,
    -200,  1431,  1466,  -200,   711,  -200,   650,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  1068,  1290,
    1106,   171,  -200,  -200,  -200,    90,   139,   191,  -200,   516,
     711,  -200,   650,   268,   311,   650,   711,   650,   650,   650,
     650,   650,   650,   650,   650,   107,  -200,  -200,  -200,  -200,
     650,  -200,  -200,   379,   189,   195,  -200,  -200,  -200,  -200,
     711,   711,   711,   711,   711,   711,   711,   711,   711,  -200,
     650,   516,   516,   711,  -200,  -200,   147,   108,   191,  1144,
    -200,  -200,   149,   150,   151,   516,  -200,  -200,  -200,   516,
     516,   516,  -200,   516,  -200,  -200,  -200,  -200
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   185,   229,     0,     0,     0,   207,   186,   254,     0,
       0,     0,     0,   255,   188,     0,   187,   220,     0,   209,
     253,    31,   164,   165,   168,   169,   166,   167,     0,   204,
     149,   148,   247,   248,   249,   250,   251,   252,     0,     0,
       0,     0,     0,     0,    36,    27,     0,     0,     0,     2,
       6,     7,    10,     8,    29,     9,    30,    28,     3,   143,
     145,   146,   147,     0,    35,     0,   184,   171,   172,   175,
     176,   174,   173,   177,   178,   179,   180,   144,     0,    94,
     150,     0,   181,     0,     0,    13,   182,     0,     0,     0,
     231,   236,     0,   235,     0,   190,     0,     0,     0,    18,
       0,     0,    17,    16,     0,     0,     0,    39,    41,    43,
      45,    47,    49,    51,    53,    55,   105,   106,     0,   244,
     100,   158,   152,   103,     0,   107,   104,     0,   108,   101,
     102,     0,    27,     0,     0,   245,     0,     1,     5,   140,
       0,   135,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,   170,   183,   148,
     239,   242,     0,   241,     0,    57,    59,    61,    63,    65,
      67,    69,    71,    73,   109,   110,    24,     0,     0,    11,
       0,     0,     0,   201,     0,     0,   233,     0,     0,   189,
     223,     0,     0,     0,    15,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   160,     0,   154,
       0,     0,     0,    25,    26,    37,     0,     0,   139,     0,
       0,   131,   132,   130,   125,   124,   120,   121,   122,   123,
     126,   127,   128,   129,   137,   138,   115,   116,   117,   118,
     119,    96,     0,     0,     0,     0,   238,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
      14,    12,     0,   197,     0,     0,   237,   234,   191,     0,
       0,    21,     0,     0,     0,    32,     0,    40,    42,    44,
      46,    48,    50,    52,    54,    56,     0,     0,   162,   155,
       0,     0,     0,   246,     0,   136,   134,     0,    98,     0,
      92,   151,   243,   240,    58,    60,    62,    64,    66,    68,
      70,    72,    74,     0,     0,     0,     0,   232,     0,     0,
       0,    19,    20,     0,     0,   205,     0,   159,     0,     0,
     153,     0,     0,   141,    95,    97,     0,    76,    78,    80,
      82,    84,    86,    88,    90,   113,   114,    23,     0,     0,
       0,   193,   192,   222,   226,     0,   225,     0,    33,     0,
     163,   161,     0,    92,    92,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,   202,   195,   194,
       0,   221,   224,     0,   219,   213,   206,   156,   111,   112,
     142,    77,    79,    81,    83,    85,    87,    89,    91,   208,
       0,     0,     0,   227,   216,   214,     0,     0,     0,     0,
     203,   196,     0,     0,     0,    27,   210,   212,   199,    27,
      27,    27,   218,     0,   228,   217,   215,   200
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,   158,  -200,  -200,    36,  -200,  -200,  -200,  -200,
    -200,  -200,  -188,  -200,   -98,  -131,     0,  -200,  -200,  -200,
    -200,     5,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -161,  -200,  -200,  -200,
    -114,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -190,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -137,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,    33,  -200,  -200,  -199,  -200,   -16,   -12,
    -184
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    48,    49,    50,    51,    84,    85,    52,   104,    53,
     201,   282,   187,   268,    54,   131,   132,    56,   101,   334,
      57,   133,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     377,   378,   379,   380,   381,   382,   383,   384,   230,   229,
     227,   375,    59,    60,    61,   220,   300,   339,    62,   218,
     297,   298,    63,    64,    65,    66,    67,    68,   328,   362,
     389,   412,    69,   325,   410,   433,    70,   274,   411,    71,
     105,   369,    72,    87,    73,   100,   394,   418,   395,   424,
     423,   417,    74,    97,   280,   365,   366,   390,   422,    75,
      81,   194,    76,    92,    93,    77,   172,   173,    78,    79,
      80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   224,    99,   203,   270,    58,   275,     8,   123,   186,
     135,   307,    13,   283,   163,    90,   102,   103,   164,    20,
      96,    22,    23,    24,    25,    26,    27,   126,   125,   128,
      30,    31,    32,    33,    34,    35,    36,    37,   121,    82,
     122,    86,    83,   120,   160,   161,   162,   129,   130,    91,
      55,   134,   163,   309,    88,    89,   164,    94,   313,    98,
     137,   166,   119,   186,   281,   167,   124,    47,   136,    38,
     190,   168,    39,    40,    41,    42,    43,   188,   158,   159,
     160,   161,   162,   171,    95,   127,    47,   191,   163,    46,
      47,   193,   164,   192,   195,   200,    45,   189,   196,   198,
     197,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   206,   156,   157,   158,   159,   160,   161,   162,   119,
     202,   204,   205,   216,   163,   251,   217,   219,   164,   221,
     223,   256,   222,   257,   -22,   357,   184,   185,   269,   272,
      91,   226,   279,   285,   164,   228,   323,   252,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   324,   253,
     326,   254,   327,   330,   364,   332,   338,   372,   337,   258,
     367,   340,   345,   388,   331,   391,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   255,   393,   409,   416,
     276,  -211,   425,   426,   429,   430,   431,   284,   138,   415,
     286,   397,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   116,   117,   296,   371,   299,   271,   118,   427,   392,
     277,     0,   304,     0,   305,   306,   368,   119,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,     0,     0,
     312,     0,   171,     0,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   116,   117,     0,     0,     0,     0,   118,
       0,     0,     0,     0,   329,     0,     0,     0,     0,   119,
       0,     0,     0,     0,   432,     0,     0,     0,   434,   435,
     436,     0,     0,     0,     0,     0,   341,   342,     0,     0,
       0,     0,   344,   346,   347,   348,   349,   350,     0,   351,
     352,   353,   354,     0,     0,     0,     0,     0,   361,   358,
     359,   360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,     0,   296,     0,     0,     0,     0,   355,   356,
       0,   376,     0,     0,     0,     0,   346,   347,   348,   349,
     350,   398,   351,   352,   353,   354,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,     0,   299,     0,     0,
     400,     0,   401,   402,   403,   404,   405,   406,   407,   408,
       0,   355,   356,     8,     0,   413,     0,     0,    13,     0,
       0,     0,     0,     0,   399,    20,     0,     0,     0,     0,
       0,   420,   421,     0,     0,   419,     0,   414,    32,    33,
      34,    35,    36,    37,     1,     2,     3,     0,     0,     4,
       5,     0,     6,   437,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     0,     0,     0,     0,
     346,   347,   348,   349,   350,     0,   351,   352,   353,   354,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
      39,    40,    41,    42,    43,   355,   356,     0,     0,     0,
       0,     0,    44,     0,     0,    45,     0,    46,    47,     1,
       2,     3,     0,     0,     0,     5,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     8,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,    20,     0,    22,    23,    24,    25,    26,
      27,     0,     0,     0,    30,   169,    32,    33,    34,    35,
      36,    37,    38,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
      45,     0,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    39,    40,    41,    42,
      43,     0,     0,     8,     0,     0,     0,     0,    13,     0,
     170,     0,     0,    46,    47,    20,     0,    22,    23,    24,
      25,    26,    27,     0,     0,     0,    30,   169,    32,    33,
      34,    35,    36,    37,     8,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,    20,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,    39,    40,
      41,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   308,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     8,     0,     0,     0,
       0,    13,     0,     0,     0,     0,    46,    47,    20,     0,
      22,    23,    24,    25,    26,    27,     0,     0,     0,    30,
     169,    32,    33,    34,    35,    36,    37,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,     0,     0,     0,   163,     0,    38,     0,
     164,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   164,     0,     0,     0,   225,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   164,     0,     0,     0,   278,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
       0,     0,     0,   303,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   164,     0,     0,
       0,   311,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   164,     0,     0,     0,   333,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   164,     0,     0,     0,   335,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   164,     0,     0,     0,  -157,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
       0,     0,     0,   363,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   164,     0,     0,
       0,   385,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   164,     0,     0,     0,   387,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   164,     0,     0,     0,   428,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   164,     0,   165,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   164,     0,   199,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   164,     0,   273,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
       0,   386,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   164,   310,   336,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   164,   343,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   164,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,     0,     0,     0,   163,     0,     0,     0,
     164,   373,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   164,   374,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,     0,     0,     0,   163,     0,     0,     0,
     301,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,     0,     0,     0,
     163,     0,     0,     0,   302,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   164,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     8,
       0,     0,     0,   163,    13,     0,     0,   164,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,    34,    35,    36,    37,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
       0,     0,     0,     0,   163,     0,     0,     0,   164,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   164,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   164,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,     0,     0,     0,
     163,     0,     0,     0,   164
};

static const yytype_int16 yycheck[] =
{
       0,   132,    18,   101,   188,     0,   194,    14,    38,    38,
      38,    45,    19,   201,    85,     4,    37,    38,    89,    26,
      15,    28,    29,    30,    31,    32,    33,    38,    40,    41,
      37,    38,    39,    40,    41,    42,    43,    44,    94,    91,
      96,    91,    38,    38,    77,    78,    79,    42,    43,    38,
      50,    46,    85,   252,    96,    96,    89,    96,   257,    38,
       0,    96,    96,    38,    93,    91,    96,    97,    96,    76,
      92,    66,    79,    80,    81,    82,    83,    45,    75,    76,
      77,    78,    79,    78,    91,    96,    97,    87,    85,    96,
      97,    38,    89,    88,    45,    38,    94,    91,    91,    94,
      92,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,   106,    73,    74,    75,    76,    77,    78,    79,    96,
      96,    91,    96,   118,    85,    38,    95,    93,    89,   124,
      95,    93,   127,    92,    92,   323,    80,    81,    91,    36,
      38,   136,    96,     7,    89,   140,    92,   163,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    96,   164,
      55,   166,    91,    94,    35,    93,    92,    92,    95,   174,
      94,    93,    93,    12,   282,    95,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     6,    91,    10,
     195,     6,    55,    95,    55,    55,    55,   202,    50,   393,
     205,   372,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    80,    81,   218,   338,   220,   190,    86,   418,   366,
     197,    -1,   227,    -1,   229,   230,   334,    96,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
     255,    -1,   257,    -1,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    80,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,   425,    -1,    -1,    -1,   429,   430,
     431,    -1,    -1,    -1,    -1,    -1,   301,   302,    -1,    -1,
      -1,    -1,   307,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,   328,   324,
     325,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   336,    -1,   338,    -1,    -1,    -1,    -1,    80,    81,
      -1,   346,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    93,    51,    52,    53,    54,    -1,    -1,    -1,   369,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
     375,    -1,   377,   378,   379,   380,   381,   382,   383,   384,
      -1,    80,    81,    14,    -1,   390,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    93,    26,    -1,    -1,    -1,    -1,
      -1,   411,   412,    -1,    -1,   410,    -1,    38,    39,    40,
      41,    42,    43,    44,     3,     4,     5,    -1,    -1,     8,
       9,    -1,    11,   433,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    80,    81,    82,    83,    80,    81,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    96,    97,     3,
       4,     5,    -1,    -1,    -1,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    14,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    76,    -1,    -1,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    80,    81,    82,
      83,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      93,    -1,    -1,    96,    97,    26,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    14,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    76,    -1,    -1,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      80,    81,    82,    83,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    96,    97,    26,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    76,    -1,
      89,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    93,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    93,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    93,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    93,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    93,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    93,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    91,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    91,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    91,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      -1,    91,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    90,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    90,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    90,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    14,
      -1,    -1,    -1,    85,    19,    -1,    -1,    89,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,     9,    11,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    76,    79,
      80,    81,    82,    83,    91,    94,    96,    97,    99,   100,
     101,   102,   105,   107,   112,   114,   115,   118,   119,   150,
     151,   152,   156,   160,   161,   162,   163,   164,   165,   170,
     174,   177,   180,   182,   190,   197,   200,   203,   206,   207,
     208,   198,    91,    38,   103,   104,    91,   181,    96,    96,
       4,    38,   201,   202,    96,    91,   119,   191,    38,   206,
     183,   116,    37,    38,   106,   178,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    80,    81,    86,    96,
     119,    94,    96,    38,    96,   207,    38,    96,   207,   119,
     119,   113,   114,   119,   119,    38,    96,     0,   100,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    85,    89,    91,    96,    91,   119,    38,
      93,   119,   204,   205,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    80,    81,    38,   110,    45,    91,
      92,   114,   119,    38,   199,    45,    91,    92,   119,    91,
      38,   108,    96,   112,    91,    96,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   119,    95,   157,    93,
     153,   119,   119,    95,   113,    93,   119,   148,   119,   147,
     146,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,    38,   206,   119,   119,    55,    93,    92,   119,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   111,    91,
     208,   103,    36,    91,   175,   110,   119,   201,    93,    96,
     192,    93,   109,   110,   119,     7,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   158,   159,   119,
     154,    89,    89,    93,   119,   119,   119,    45,    93,   204,
      90,    93,   119,   204,   119,   119,   119,   119,   119,   119,
     119,   119,   119,    92,    96,   171,    55,    91,   166,   119,
      94,   112,    93,    93,   117,    93,    55,    95,    92,   155,
      93,   119,   119,    55,   119,    93,    45,    46,    47,    48,
      49,    51,    52,    53,    54,    80,    81,   110,   119,   119,
     119,   114,   167,    93,    35,   193,   194,    94,   112,   179,
     119,   158,    92,    90,    90,   149,   119,   138,   139,   140,
     141,   142,   143,   144,   145,    93,    91,    93,    12,   168,
     195,    95,   193,     6,   184,   186,   114,   154,    93,    93,
     119,   119,   119,   119,   119,   119,   119,   119,   119,    91,
     172,   176,   169,   119,    38,   208,    10,   189,   185,   119,
     114,   114,   196,   188,   187,    55,    95,   184,    93,    55,
      55,    55,   113,   173,   113,   113,   113,   114
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    98,    99,    99,    99,   100,   100,   101,   101,   101,
     101,   102,   103,   103,   104,   105,   106,   106,   108,   107,
     109,   109,   111,   110,   110,   112,   113,   113,   114,   114,
     114,   116,   117,   115,   118,   118,   118,   119,   119,   120,
     119,   121,   119,   122,   119,   123,   119,   124,   119,   125,
     119,   126,   119,   127,   119,   128,   119,   129,   119,   130,
     119,   131,   119,   132,   119,   133,   119,   134,   119,   135,
     119,   136,   119,   137,   119,   119,   138,   119,   139,   119,
     140,   119,   141,   119,   142,   119,   143,   119,   144,   119,
     145,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   146,   119,   147,   119,   119,   119,   119,
     148,   149,   119,   119,   150,   150,   150,   150,   150,   150,
     150,   151,   153,   152,   152,   155,   154,   154,   157,   156,
     156,   158,   158,   159,   160,   160,   160,   160,   160,   160,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   162,   162,   163,   163,   163,   163,   164,
     164,   166,   165,   167,   167,   169,   168,   171,   172,   173,
     170,   175,   176,   174,   178,   179,   177,   181,   180,   183,
     182,   185,   184,   184,   187,   186,   188,   186,   189,   189,
     191,   190,   192,   192,   193,   193,   195,   196,   194,   198,
     197,   199,   197,   200,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   206,   207,   207,   208,   208,   208,
     208,   208,   208,   208,   208,   208
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     1,     0,     5,
       2,     1,     0,     4,     1,     3,     2,     0,     1,     1,
       1,     0,     0,     6,     2,     1,     1,     3,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     6,     0,     7,     0,     7,
       0,     7,     0,     7,     0,     7,     0,     7,     0,     7,
       0,     7,     4,     3,     1,     5,     3,     5,     4,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     7,     7,     5,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     4,     0,     4,     3,     3,     3,
       0,     0,     7,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     5,     3,     0,     4,     1,     0,     5,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     3,
       2,     0,     6,     1,     2,     0,     3,     0,     0,     0,
      12,     0,     0,     9,     0,     0,     7,     0,     8,     0,
       9,     0,     3,     1,     0,     5,     0,     5,     3,     0,
       0,     7,     3,     0,     2,     1,     0,     0,     6,     0,
       4,     0,     5,     3,     3,     1,     1,     3,     3,     2,
       3,     1,     1,     3,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (scanner, pLexer, pCompiler, pScript, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner, pLexer, pCompiler, pScript); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler, NXSL_Program *pScript)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (scanner);
  YYUSE (pLexer);
  YYUSE (pCompiler);
  YYUSE (pScript);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler, NXSL_Program *pScript)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner, pLexer, pCompiler, pScript);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler, NXSL_Program *pScript)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , scanner, pLexer, pCompiler, pScript);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner, pLexer, pCompiler, pScript); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler, NXSL_Program *pScript)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  YYUSE (pLexer);
  YYUSE (pCompiler);
  YYUSE (pScript);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 37: /* T_COMPOUND_IDENTIFIER  */
#line 109 "parser.y" /* yacc.c:1257  */
      { safe_free(((*yyvaluep).valStr)); }
#line 1686 "parser.tab.cpp" /* yacc.c:1257  */
        break;

    case 38: /* T_IDENTIFIER  */
#line 109 "parser.y" /* yacc.c:1257  */
      { safe_free(((*yyvaluep).valStr)); }
#line 1692 "parser.tab.cpp" /* yacc.c:1257  */
        break;

    case 39: /* T_STRING  */
#line 109 "parser.y" /* yacc.c:1257  */
      { safe_free(((*yyvaluep).valStr)); }
#line 1698 "parser.tab.cpp" /* yacc.c:1257  */
        break;

    case 106: /* AnyIdentifier  */
#line 109 "parser.y" /* yacc.c:1257  */
      { safe_free(((*yyvaluep).valStr)); }
#line 1704 "parser.tab.cpp" /* yacc.c:1257  */
        break;

    case 163: /* SimpleStatementKeyword  */
#line 111 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).pInstruction); }
#line 1710 "parser.tab.cpp" /* yacc.c:1257  */
        break;

    case 206: /* FunctionName  */
#line 109 "parser.y" /* yacc.c:1257  */
      { safe_free(((*yyvaluep).valStr)); }
#line 1716 "parser.tab.cpp" /* yacc.c:1257  */
        break;

    case 208: /* Constant  */
#line 110 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).pConstant); }
#line 1722 "parser.tab.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler, NXSL_Program *pScript)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 120 "parser.y" /* yacc.c:1646  */
    {
	char szErrorText[256];

	// Add implicit main() function
	if (!pScript->addFunction("$main", 0, szErrorText))
	{
		pCompiler->error(szErrorText);
		YYERROR;
	}
	
	// Implicit return
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_RET_NULL));
}
#line 2002 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 134 "parser.y" /* yacc.c:1646  */
    {
	char szErrorText[256];

	// Add implicit return
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_RETURN));

	// Add implicit main() function
	if (!pScript->addFunction("$main", 0, szErrorText))
	{
		pCompiler->error(szErrorText);
		YYERROR;
	}
}
#line 2020 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 148 "parser.y" /* yacc.c:1646  */
    {
	char szErrorText[256];

	// Add implicit return
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_RET_NULL));

	// Add implicit main() function
	if (!pScript->addFunction("$main", 0, szErrorText))
	{
		pCompiler->error(szErrorText);
		YYERROR;
	}
}
#line 2038 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 186 "parser.y" /* yacc.c:1646  */
    {
	if (!pScript->addConstant((yyvsp[-2].valStr), (yyvsp[0].pConstant)))
	{
		pCompiler->error("Constant already defined");
		delete_and_null((yyvsp[0].pConstant));
		YYERROR;
	}
	safe_free_and_null((yyvsp[-2].valStr));
	(yyvsp[0].pConstant) = NULL;
}
#line 2053 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 200 "parser.y" /* yacc.c:1646  */
    {
	pScript->addRequiredModule((yyvsp[-1].valStr), pLexer->getCurrLine());
	safe_free_and_null((yyvsp[-1].valStr));
}
#line 2062 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 213 "parser.y" /* yacc.c:1646  */
    {
		char szErrorText[256];

		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, INVALID_ADDRESS));
		
		if (!pScript->addFunction((yyvsp[0].valStr), INVALID_ADDRESS, szErrorText))
		{
			pCompiler->error(szErrorText);
			YYERROR;
		}
		safe_free_and_null((yyvsp[0].valStr));
		pCompiler->setIdentifierOperation(OPCODE_BIND);
	}
#line 2080 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 227 "parser.y" /* yacc.c:1646  */
    {
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_RET_NULL));
		pScript->resolveLastJump(OPCODE_JMP);
	}
#line 2089 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 240 "parser.y" /* yacc.c:1646  */
    {
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), pCompiler->getIdentifierOperation(), (yyvsp[0].valStr)));
		(yyvsp[0].valStr) = NULL;
	}
#line 2098 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 246 "parser.y" /* yacc.c:1646  */
    {
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), pCompiler->getIdentifierOperation(), (yyvsp[0].valStr)));
		(yyvsp[0].valStr) = NULL;
	}
#line 2107 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 269 "parser.y" /* yacc.c:1646  */
    {
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CATCH, INVALID_ADDRESS));
	}
#line 2115 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 273 "parser.y" /* yacc.c:1646  */
    {
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CPOP));
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, INVALID_ADDRESS));
		pScript->resolveLastJump(OPCODE_CATCH);
	}
#line 2125 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 279 "parser.y" /* yacc.c:1646  */
    {
		pScript->resolveLastJump(OPCODE_JMP);
	}
#line 2133 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 286 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_POP, (short)1));
}
#line 2141 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 291 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NOP));
}
#line 2149 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 299 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-2].valStr)));
	(yyvsp[-2].valStr) = NULL;
}
#line 2158 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 303 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2164 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 304 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ADD));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2174 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 309 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2180 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 310 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SUB));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2190 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 315 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2196 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 316 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_MUL));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2206 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 321 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2212 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 322 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DIV));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2222 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 327 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2228 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 328 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_REM));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2238 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 333 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2244 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 334 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CONCAT));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2254 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 339 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2260 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 340 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_AND));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2270 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 345 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2276 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 346 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_OR));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2286 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 351 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, strdup((yyvsp[-1].valStr)))); }
#line 2292 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 352 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_XOR));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET, (yyvsp[-3].valStr)));
	(yyvsp[-3].valStr) = NULL;
}
#line 2302 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 357 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2308 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 358 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ADD));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2317 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 362 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2323 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 363 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SUB));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2332 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 367 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2338 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 368 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_MUL));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2347 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 372 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2353 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 373 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DIV));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2362 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 377 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2368 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 378 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_REM));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2377 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 382 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2383 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 383 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CONCAT));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2392 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 387 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2398 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 388 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_AND));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2407 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 392 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2413 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 393 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_OR));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2422 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 397 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ, (short)1)); }
#line 2428 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 398 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_XOR));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2437 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 403 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2445 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 406 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2451 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 407 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ADD));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2460 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 411 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2466 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 412 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SUB));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2475 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 416 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2481 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 417 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_MUL));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2490 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 421 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2496 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 422 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DIV));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2505 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 426 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2511 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 427 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CONCAT));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2520 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 431 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2526 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 432 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_AND));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2535 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 436 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2541 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 437 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_OR));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2550 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 441 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PEEK_ELEMENT)); }
#line 2556 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 442 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_XOR));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ELEMENT));
}
#line 2565 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 447 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_GET_ELEMENT));
}
#line 2573 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 451 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_WRITE));
}
#line 2581 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 455 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_READ));
}
#line 2589 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 459 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SET_ATTRIBUTE, (yyvsp[-2].valStr)));
	(yyvsp[-2].valStr) = NULL;
}
#line 2598 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 464 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_GET_ATTRIBUTE, (yyvsp[0].valStr)));
	(yyvsp[0].valStr) = NULL;
}
#line 2607 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 469 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CALL_METHOD, (yyvsp[-2].valStr), (yyvsp[-1].valInt32)));
	(yyvsp[-2].valStr) = NULL;
}
#line 2616 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 474 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CALL_METHOD, (yyvsp[-1].valStr), 0));
	(yyvsp[-1].valStr) = NULL;
}
#line 2625 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 479 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SAFE_GET_ATTR, (yyvsp[-2].valStr)));
	(yyvsp[-2].valStr) = NULL;
}
#line 2634 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 484 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NEG));
}
#line 2642 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 488 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NOT));
}
#line 2650 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 492 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_NOT));
}
#line 2658 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 496 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_INCP, (yyvsp[0].valStr)));
	(yyvsp[0].valStr) = NULL;
}
#line 2667 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 501 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DECP, (yyvsp[0].valStr)));
	(yyvsp[0].valStr) = NULL;
}
#line 2676 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 506 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_INC, (yyvsp[-1].valStr)));
	(yyvsp[-1].valStr) = NULL;
}
#line 2685 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 511 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DEC, (yyvsp[-1].valStr)));
	(yyvsp[-1].valStr) = NULL;
}
#line 2694 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 516 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_INCP));
}
#line 2702 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 520 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_DECP));
}
#line 2710 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 524 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_INC));
}
#line 2718 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 528 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_STORAGE_DEC));
}
#line 2726 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 532 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_INCP_ELEMENT));
}
#line 2734 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 536 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DECP_ELEMENT));
}
#line 2742 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 540 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_INC_ELEMENT));
}
#line 2750 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 544 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DEC_ELEMENT));
}
#line 2758 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 548 "parser.y" /* yacc.c:1646  */
    { 
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ADD));
}
#line 2766 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 552 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SUB));
}
#line 2774 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 556 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_MUL));
}
#line 2782 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 560 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_DIV));
}
#line 2790 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 564 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_REM));
}
#line 2798 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 568 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_LIKE));
}
#line 2806 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 572 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ILIKE));
}
#line 2814 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 576 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_MATCH));
}
#line 2822 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 580 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_IMATCH));
}
#line 2830 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 584 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_EQ));
}
#line 2838 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 588 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NE));
}
#line 2846 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 592 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_LT));
}
#line 2854 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 596 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_LE));
}
#line 2862 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 600 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_GT));
}
#line 2870 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 604 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_GE));
}
#line 2878 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 608 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_AND));
}
#line 2886 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 612 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_OR));
}
#line 2894 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 616 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_BIT_XOR));
}
#line 2902 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 619 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ_PEEK, INVALID_ADDRESS)); }
#line 2908 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 620 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_AND));
	pScript->resolveLastJump(OPCODE_JZ_PEEK);
}
#line 2917 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 624 "parser.y" /* yacc.c:1646  */
    { pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JNZ_PEEK, INVALID_ADDRESS)); }
#line 2923 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 625 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_OR));
	pScript->resolveLastJump(OPCODE_JNZ_PEEK);
}
#line 2932 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 630 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_LSHIFT));
}
#line 2940 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 634 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_RSHIFT));
}
#line 2948 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 638 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CONCAT));
}
#line 2956 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 642 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ, INVALID_ADDRESS));
}
#line 2964 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 646 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, INVALID_ADDRESS));
	pScript->resolveLastJump(OPCODE_JZ);
}
#line 2973 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 651 "parser.y" /* yacc.c:1646  */
    {
	pScript->resolveLastJump(OPCODE_JMP);
}
#line 2981 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 663 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_VARIABLE, (yyvsp[0].valStr)));
	(yyvsp[0].valStr) = NULL;
}
#line 2990 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 668 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTREF, (yyvsp[0].valStr)));
	(yyvsp[0].valStr) = NULL;
}
#line 2999 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 673 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTANT, (yyvsp[0].pConstant)));
	(yyvsp[0].pConstant) = NULL;
}
#line 3008 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 681 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CAST, (short)(yyvsp[-3].valInt32)));
}
#line 3016 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 688 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NEW_ARRAY));
}
#line 3024 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 693 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NEW_ARRAY));
}
#line 3032 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 700 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ADD_TO_ARRAY));
}
#line 3040 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 705 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ADD_TO_ARRAY));
}
#line 3048 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 712 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NEW_HASHMAP));
}
#line 3056 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 717 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NEW_HASHMAP));
}
#line 3064 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 729 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_HASHMAP_SET));
}
#line 3072 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 735 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valInt32) = NXSL_DT_INT32;
}
#line 3080 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 739 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valInt32) = NXSL_DT_INT64;
}
#line 3088 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 743 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valInt32) = NXSL_DT_UINT32;
}
#line 3096 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 747 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valInt32) = NXSL_DT_UINT64;
}
#line 3104 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 751 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valInt32) = NXSL_DT_REAL;
}
#line 3112 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 755 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valInt32) = NXSL_DT_STRING;
}
#line 3120 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 773 "parser.y" /* yacc.c:1646  */
    {
	if (pCompiler->canUseBreak())
	{
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NOP));
		pCompiler->addBreakAddr(pScript->getCodeSize() - 1);
	}
	else
	{
		pCompiler->error("\"break\" statement can be used only within loops, \"switch\", and \"select\" statements");
		YYERROR;
	}
}
#line 3137 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 786 "parser.y" /* yacc.c:1646  */
    {
	UINT32 dwAddr = pCompiler->peekAddr();
	if (dwAddr != INVALID_ADDRESS)
	{
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, dwAddr));
	}
	else
	{
		pCompiler->error("\"continue\" statement can be used only within loops");
		YYERROR;
	}
}
#line 3154 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 802 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction((yyvsp[-1].pInstruction));
	(yyvsp[-1].pInstruction) = NULL;
}
#line 3163 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 807 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTANT, new NXSL_Value));
	pScript->addInstruction((yyvsp[0].pInstruction));
	(yyvsp[0].pInstruction) = NULL;
}
#line 3173 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 816 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pInstruction) = new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_ABORT);
}
#line 3181 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 820 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pInstruction) = new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_EXIT);
}
#line 3189 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 824 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pInstruction) = new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_RETURN);
}
#line 3197 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 828 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pInstruction) = new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PRINT);
}
#line 3205 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 835 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTANT, new NXSL_Value(_T("\n"))));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CONCAT));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PRINT));
}
#line 3215 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 841 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTANT, new NXSL_Value(_T("\n"))));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PRINT));
}
#line 3224 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 849 "parser.y" /* yacc.c:1646  */
    {
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ, INVALID_ADDRESS));
	}
#line 3232 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 857 "parser.y" /* yacc.c:1646  */
    {
	pScript->resolveLastJump(OPCODE_JZ);
}
#line 3240 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 861 "parser.y" /* yacc.c:1646  */
    {
	pScript->resolveLastJump(OPCODE_JMP);
}
#line 3248 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 868 "parser.y" /* yacc.c:1646  */
    {
		pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, INVALID_ADDRESS));
		pScript->resolveLastJump(OPCODE_JZ);
	}
#line 3257 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 877 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_POP, (short)1));
	pCompiler->pushAddr(pScript->getCodeSize());
}
#line 3266 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 882 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ, INVALID_ADDRESS));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, INVALID_ADDRESS));
	pCompiler->pushAddr(pScript->getCodeSize());
}
#line 3276 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 888 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_POP, (short)1));
	UINT32 addrPart3 = pCompiler->popAddr();
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, pCompiler->popAddr()));
	pCompiler->pushAddr(addrPart3);
	pCompiler->newBreakLevel();
	pScript->resolveLastJump(OPCODE_JMP);
}
#line 3289 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 897 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, pCompiler->popAddr()));
	pScript->resolveLastJump(OPCODE_JZ);
	pCompiler->closeBreakLevel(pScript);
}
#line 3299 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 906 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTANT, new NXSL_Value((yyvsp[0].valStr))));
	safe_free_and_null((yyvsp[0].valStr));
}
#line 3308 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 911 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_FOREACH));
	pCompiler->pushAddr(pScript->getCodeSize());
	pCompiler->newBreakLevel();
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NEXT));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ, INVALID_ADDRESS));
}
#line 3320 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 919 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, pCompiler->popAddr()));
	pScript->resolveLastJump(OPCODE_JZ);
	pCompiler->closeBreakLevel(pScript);
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_POP, (short)1));
}
#line 3331 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 929 "parser.y" /* yacc.c:1646  */
    {
	pCompiler->pushAddr(pScript->getCodeSize());
	pCompiler->newBreakLevel();
}
#line 3340 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 934 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ, INVALID_ADDRESS));
}
#line 3348 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 938 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, pCompiler->popAddr()));
	pScript->resolveLastJump(OPCODE_JZ);
	pCompiler->closeBreakLevel(pScript);
}
#line 3358 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 947 "parser.y" /* yacc.c:1646  */
    {
	pCompiler->pushAddr(pScript->getCodeSize());
	pCompiler->newBreakLevel();
}
#line 3367 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 952 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(),
				OPCODE_JNZ, pCompiler->popAddr()));
	pCompiler->closeBreakLevel(pScript);
}
#line 3377 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 961 "parser.y" /* yacc.c:1646  */
    { 
	pCompiler->newBreakLevel();
}
#line 3385 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 965 "parser.y" /* yacc.c:1646  */
    {
	pCompiler->closeBreakLevel(pScript);
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_POP, (short)1));
}
#line 3394 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 973 "parser.y" /* yacc.c:1646  */
    { 
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, pScript->getCodeSize() + 3));
	pScript->resolveLastJump(OPCODE_JZ);
}
#line 3403 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 979 "parser.y" /* yacc.c:1646  */
    {
	pScript->resolveLastJump(OPCODE_JZ);
}
#line 3411 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 986 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CASE, (yyvsp[0].pConstant)));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ, INVALID_ADDRESS));
	(yyvsp[0].pConstant) = NULL;
}
#line 3421 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 993 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CASE_CONST, (yyvsp[0].valStr)));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JZ, INVALID_ADDRESS));
	(yyvsp[0].valStr) = NULL;
}
#line 3431 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1008 "parser.y" /* yacc.c:1646  */
    { 
	pCompiler->newBreakLevel();
	pCompiler->newSelectLevel();
}
#line 3440 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1013 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_SELECT, (yyvsp[-4].valStr), (yyvsp[-1].valInt32)));
	pCompiler->closeBreakLevel(pScript);

	UINT32 addr = pCompiler->popSelectJumpAddr();
	if (addr != INVALID_ADDRESS)
	{
		pScript->createJumpAt(addr, pScript->getCodeSize());
	}
	pCompiler->closeSelectLevel();
}
#line 3456 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1029 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTANT, new NXSL_Value()));
}
#line 3464 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1036 "parser.y" /* yacc.c:1646  */
    { 
	(yyval.valInt32) = (yyvsp[0].valInt32) + 1; 
}
#line 3472 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1040 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valInt32) = 1;
}
#line 3480 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1047 "parser.y" /* yacc.c:1646  */
    {
}
#line 3487 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1050 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSHCP, (short)2));
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_JMP, INVALID_ADDRESS));
	UINT32 addr = pCompiler->popSelectJumpAddr();
	if (addr != INVALID_ADDRESS)
	{
		pScript->createJumpAt(addr, pScript->getCodeSize());
	}
}
#line 3501 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1060 "parser.y" /* yacc.c:1646  */
    {
	pCompiler->pushSelectJumpAddr(pScript->getCodeSize());
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NOP));
	pScript->resolveLastJump(OPCODE_JMP);
}
#line 3511 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1068 "parser.y" /* yacc.c:1646  */
    { pCompiler->setIdentifierOperation(OPCODE_ARRAY); }
#line 3517 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1069 "parser.y" /* yacc.c:1646  */
    { pCompiler->setIdentifierOperation(OPCODE_GLOBAL_ARRAY); }
#line 3523 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_GLOBAL, (yyvsp[0].valStr), 0));
	(yyvsp[0].valStr) = NULL;
}
#line 3532 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1088 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_GLOBAL, (yyvsp[-2].valStr), 1));
	(yyvsp[-2].valStr) = NULL;
}
#line 3541 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1096 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CALL_EXTERNAL, (yyvsp[-2].valStr), (yyvsp[-1].valInt32)));
	(yyvsp[-2].valStr) = NULL;
}
#line 3550 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1101 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_CALL_EXTERNAL, (yyvsp[-1].valStr), 0));
	(yyvsp[-1].valStr) = NULL;
}
#line 3559 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1108 "parser.y" /* yacc.c:1646  */
    { (yyval.valInt32) = (yyvsp[0].valInt32) + 1; }
#line 3565 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1109 "parser.y" /* yacc.c:1646  */
    { (yyval.valInt32) = 1; }
#line 3571 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1115 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_NAME, (yyvsp[-2].valStr)));
	(yyvsp[-2].valStr) = NULL;
}
#line 3580 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
	(yyval.valStr) = (yyvsp[-1].valStr);
}
#line 3588 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1130 "parser.y" /* yacc.c:1646  */
    {
	pScript->addInstruction(new NXSL_Instruction(pLexer->getCurrLine(), OPCODE_PUSH_CONSTANT, new NXSL_Value((yyvsp[0].valStr))));
	safe_free_and_null((yyvsp[0].valStr));
}
#line 3597 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1139 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((yyvsp[0].valStr));
	safe_free_and_null((yyvsp[0].valStr));
}
#line 3606 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1144 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((yyvsp[0].valInt32));
}
#line 3614 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1148 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((yyvsp[0].valUInt32));
}
#line 3622 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1152 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((yyvsp[0].valInt64));
}
#line 3630 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1156 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((yyvsp[0].valUInt64));
}
#line 3638 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1160 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((yyvsp[0].valReal));
}
#line 3646 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1164 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((LONG)1);
}
#line 3654 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1168 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value((LONG)0);
}
#line 3662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1172 "parser.y" /* yacc.c:1646  */
    {
	(yyval.pConstant) = new NXSL_Value;
}
#line 3670 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 3674 "parser.tab.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, pLexer, pCompiler, pScript, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, pLexer, pCompiler, pScript, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, scanner, pLexer, pCompiler, pScript);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, scanner, pLexer, pCompiler, pScript);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, pLexer, pCompiler, pScript, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner, pLexer, pCompiler, pScript);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, scanner, pLexer, pCompiler, pScript);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
