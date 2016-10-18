/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         mpparse
#define yylex           mplex
#define yyerror         mperror
#define yydebug         mpdebug
#define yynerrs         mpnerrs

#define yylval          mplval
#define yychar          mpchar

/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

/*
 * Copyright 2001, THE AUTHOR <mibparser@cvtt.net>
 * All rights reserved.
 *
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *  
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *  
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * A parser for the basic grammar to use for snmp V2c modules
 */

#pragma warning(disable : 4065 4102)

/*
#ifndef __STDC__
#define __STDC__	1
#endif
*/

#define YYMALLOC	malloc
#define YYFREE		free

#include <nms_common.h>
#include <nms_util.h>
#include <string.h>
#include <time.h>
#include "mibparse.h"
#include "nxmibc.h"
#include "nxsnmp.h"

#define YYINCLUDED_STDLIB_H		1

#ifdef YYTEXT_POINTER
extern char *mptext;
#else
extern char mptext[];
#endif

#ifdef __64BIT__
#define YYSIZE_T  INT64
#endif

extern FILE *mpin, *mpout;
extern int g_nCurrLine;

static MP_MODULE *m_pModule;
static char *m_pszCurrentFilename;

int mperror(const char *pszMsg);
int mplex(void);
void ResetScanner();

MP_SYNTAX *create_std_syntax(int nSyntax)
{
   MP_SYNTAX *p = new MP_SYNTAX;
   p->nSyntax = nSyntax;
   return p;
}

static int AccessFromText(const char *pszText)
{
   static const char *pText[] = { "read-only", "read-write", "write-only",
                                  "not-accessible", "accessible-for-notify",
                                  "read-create", NULL };
   char szBuffer[256];
   int i;

   for(i = 0; pText[i] != NULL; i++)
      if (strcmp(pszText, pText[i]))
         return i + 1;
   sprintf(szBuffer, "Invalid ACCESS value \"%s\"", pszText);
   mperror(szBuffer);
   return -1;
}


#line 177 "parser.tab.cpp" /* yacc.c:339  */

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
#ifndef YY_MP_PARSER_TAB_HPP_INCLUDED
# define YY_MP_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int mpdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENTERPRISE_SYM = 258,
    TRAP_TYPE_SYM = 259,
    VARIABLES_SYM = 260,
    EXPLICIT_SYM = 261,
    IMPLICIT_SYM = 262,
    IMPLIED_SYM = 263,
    RIGHT_BRACE_SYM = 264,
    LEFT_BRACE_SYM = 265,
    RIGHT_BRACKET_SYM = 266,
    LEFT_BRACKET_SYM = 267,
    DEFINITIONS_SYM = 268,
    ASSIGNMENT_SYM = 269,
    BEGIN_SYM = 270,
    END_SYM = 271,
    FROM_SYM = 272,
    IMPORTS_SYM = 273,
    EXPORTS_SYM = 274,
    COMMA_SYM = 275,
    SEMI_COLON_SYM = 276,
    DOT_SYM = 277,
    DESCRIPTION_SYM = 278,
    ORGANIZATION_SYM = 279,
    CONTACT_SYM = 280,
    UPDATE_SYM = 281,
    MODULE_IDENTITY_SYM = 282,
    MODULE_COMPLIANCE_SYM = 283,
    OBJECT_IDENTIFIER_SYM = 284,
    OBJECT_TYPE_SYM = 285,
    OBJECT_GROUP_SYM = 286,
    OBJECT_IDENTITY_SYM = 287,
    OBJECTS_SYM = 288,
    MANDATORY_GROUPS_SYM = 289,
    GROUP_SYM = 290,
    AGENT_CAPABILITIES_SYM = 291,
    KEYWORD_SYM = 292,
    KEYWORD_VALUE_SYM = 293,
    KEYWORD_BIND_SYM = 294,
    TOKEN_SYM = 295,
    INTEGER_SYM = 296,
    INTEGER32_SYM = 297,
    UNSIGNED32_SYM = 298,
    GAUGE32_SYM = 299,
    COUNTER_SYM = 300,
    COUNTER32_SYM = 301,
    COUNTER64_SYM = 302,
    BITS_SYM = 303,
    STRING_SYM = 304,
    OCTET_SYM = 305,
    SEQUENCE_SYM = 306,
    OF_SYM = 307,
    TIMETICKS_SYM = 308,
    IP_ADDRESS_SYM = 309,
    NETWORK_ADDRESS_SYM = 310,
    OPAQUE_SYM = 311,
    REVISION_SYM = 312,
    TEXTUAL_CONVENTION_SYM = 313,
    ACCESS_SYM = 314,
    MAX_ACCESS_SYM = 315,
    MIN_ACCESS_SYM = 316,
    SYNTAX_SYM = 317,
    STATUS_SYM = 318,
    INDEX_SYM = 319,
    REFERENCE_SYM = 320,
    DEFVAL_SYM = 321,
    LEFT_PAREN_SYM = 322,
    RIGHT_PAREN_SYM = 323,
    NOTIFICATIONS_SYM = 324,
    NOTIFICATION_GROUP_SYM = 325,
    NOTIFICATION_TYPE_SYM = 326,
    SIZE_SYM = 327,
    BAR_SYM = 328,
    VARIATION_SYM = 329,
    WRITE_SYNTAX_SYM = 330,
    SUPPORTS_SYM = 331,
    INCLUDES_SYM = 332,
    CREATION_REQUIRES_SYM = 333,
    PRODUCT_RELEASE_SYM = 334,
    CHOICE_SYM = 335,
    UNITS_SYM = 336,
    AUGMENTS_SYM = 337,
    OBJECT_SYM = 338,
    TAGS_SYM = 339,
    AUTOMATIC_SYM = 340,
    MIN_SYM = 341,
    MAX_SYM = 342,
    MODULE_SYM = 343,
    MACRO_SYM = 344,
    UCASEFIRST_IDENT_SYM = 345,
    LCASEFIRST_IDENT_SYM = 346,
    BSTRING_SYM = 347,
    HSTRING_SYM = 348,
    CSTRING_SYM = 349,
    DISPLAY_HINT_SYM = 350,
    NUMBER_SYM = 351
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 110 "parser.y" /* yacc.c:355  */

   int nInteger;
   char *pszString;
   MP_NUMERIC_VALUE number;
   Array *pList;
   ObjectArray<MP_SUBID> *pOID;
   ObjectArray<MP_IMPORT_MODULE> *pImportList;
   MP_IMPORT_MODULE *pImports;
   MP_OBJECT *pObject;
   MP_SUBID *pSubId;
   MP_SYNTAX *pSyntax;

#line 327 "parser.tab.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE mplval;

int mpparse (void);

#endif /* !YY_MP_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 342 "parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   433

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  424

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   252,   252,   253,   257,   258,   262,   266,   270,   274,
     278,   282,   286,   287,   291,   295,   296,   300,   304,   305,
     309,   317,   321,   328,   336,   347,   351,   365,   372,   376,
     384,   391,   398,   408,   409,   413,   414,   421,   422,   423,
     427,   434,   441,   448,   465,   492,   511,   519,   526,   527,
     531,   532,   536,   545,   552,   559,   566,   573,   578,   584,
     585,   586,   590,   591,   592,   598,   599,   600,   604,   611,
     618,   625,   632,   637,   644,   648,   652,   656,   660,   664,
     668,   682,   697,   712,   718,   724,   730,   739,   743,   747,
     751,   758,   767,   771,   775,   779,   783,   787,   791,   795,
     799,   803,   808,   812,   819,   824,   829,   834,   839,   844,
     849,   854,   859,   867,   871,   878,   887,   888,   892,   896,
     909,   927,   960,   961,   965,   972,   973,   977,   978,   982,
     989,   990,   994,   995,   999,  1009,  1017,  1021,  1025,  1029,
    1048,  1066,  1080,  1081,  1085,  1091,  1095,  1099,  1100,  1104,
    1105,  1109,  1124,  1125,  1129,  1134,  1142,  1163,  1168,  1173,
    1179,  1185,  1208,  1212,  1216,  1220,  1224,  1228,  1232,  1236,
    1237,  1238,  1242,  1243,  1247,  1251,  1252,  1256,  1260,  1264,
    1271,  1278,  1285,  1289,  1297,  1307,  1311,  1319,  1323,  1327,
    1334,  1342,  1343,  1347,  1351,  1352,  1356,  1357,  1361,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1378,  1379,  1380,  1381,
    1388,  1392,  1399,  1406,  1413,  1417
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERPRISE_SYM", "TRAP_TYPE_SYM",
  "VARIABLES_SYM", "EXPLICIT_SYM", "IMPLICIT_SYM", "IMPLIED_SYM",
  "RIGHT_BRACE_SYM", "LEFT_BRACE_SYM", "RIGHT_BRACKET_SYM",
  "LEFT_BRACKET_SYM", "DEFINITIONS_SYM", "ASSIGNMENT_SYM", "BEGIN_SYM",
  "END_SYM", "FROM_SYM", "IMPORTS_SYM", "EXPORTS_SYM", "COMMA_SYM",
  "SEMI_COLON_SYM", "DOT_SYM", "DESCRIPTION_SYM", "ORGANIZATION_SYM",
  "CONTACT_SYM", "UPDATE_SYM", "MODULE_IDENTITY_SYM",
  "MODULE_COMPLIANCE_SYM", "OBJECT_IDENTIFIER_SYM", "OBJECT_TYPE_SYM",
  "OBJECT_GROUP_SYM", "OBJECT_IDENTITY_SYM", "OBJECTS_SYM",
  "MANDATORY_GROUPS_SYM", "GROUP_SYM", "AGENT_CAPABILITIES_SYM",
  "KEYWORD_SYM", "KEYWORD_VALUE_SYM", "KEYWORD_BIND_SYM", "TOKEN_SYM",
  "INTEGER_SYM", "INTEGER32_SYM", "UNSIGNED32_SYM", "GAUGE32_SYM",
  "COUNTER_SYM", "COUNTER32_SYM", "COUNTER64_SYM", "BITS_SYM",
  "STRING_SYM", "OCTET_SYM", "SEQUENCE_SYM", "OF_SYM", "TIMETICKS_SYM",
  "IP_ADDRESS_SYM", "NETWORK_ADDRESS_SYM", "OPAQUE_SYM", "REVISION_SYM",
  "TEXTUAL_CONVENTION_SYM", "ACCESS_SYM", "MAX_ACCESS_SYM",
  "MIN_ACCESS_SYM", "SYNTAX_SYM", "STATUS_SYM", "INDEX_SYM",
  "REFERENCE_SYM", "DEFVAL_SYM", "LEFT_PAREN_SYM", "RIGHT_PAREN_SYM",
  "NOTIFICATIONS_SYM", "NOTIFICATION_GROUP_SYM", "NOTIFICATION_TYPE_SYM",
  "SIZE_SYM", "BAR_SYM", "VARIATION_SYM", "WRITE_SYNTAX_SYM",
  "SUPPORTS_SYM", "INCLUDES_SYM", "CREATION_REQUIRES_SYM",
  "PRODUCT_RELEASE_SYM", "CHOICE_SYM", "UNITS_SYM", "AUGMENTS_SYM",
  "OBJECT_SYM", "TAGS_SYM", "AUTOMATIC_SYM", "MIN_SYM", "MAX_SYM",
  "MODULE_SYM", "MACRO_SYM", "UCASEFIRST_IDENT_SYM",
  "LCASEFIRST_IDENT_SYM", "BSTRING_SYM", "HSTRING_SYM", "CSTRING_SYM",
  "DISPLAY_HINT_SYM", "NUMBER_SYM", "$accept", "ModuleDefinition",
  "AssignmentList", "Assignment", "ModuleIdentifierAssignment",
  "ModuleIdentifier", "ObjectIdentifierAssignment", "AssignedIdentifier",
  "AssignedIdentifierList", "ObjectIdentifierList", "ObjectIdentifier",
  "NumericValue", "NumberOrMinMax", "DefinedValue", "Number",
  "ObjectIdentityAssignment", "ObjectTypeAssignment",
  "ModuleIdentityAssignment", "ImportsAssignment", "ExportsAssignment",
  "SnmpRevisionPart", "SnmpRevisionList", "SnmpRevisionObject",
  "SnmpIdentityPart", "SnmpOrganisationPart", "SnmpContactInfoPart",
  "SnmpUpdatePart", "SnmpDescriptionPart", "ValueConstraint",
  "NumericValueConstraintList", "SnmpKeywordAssignment", "SnmpKeywordName",
  "SnmpKeywordValue", "SnmpKeywordBinding", "SnmpSyntax", "SnmpSyntaxPart",
  "SnmpUnitsPart", "SnmpWriteSyntaxPart", "SnmpCreationPart",
  "TypeOrValueAssignment", "Type", "NamedType", "BuiltInType",
  "BuiltInTypeAssignment", "TypeOrTextualConvention", "MacroAssignment",
  "TokenList", "TokenObject", "TextualConventionAssignment",
  "SnmpNotificationTypeAssignment", "SnmpTrapVariablePart",
  "SnmpTrapVariableList", "SnmpMandatoryGroupPart",
  "SnmpMandatoryGroupList", "SnmpMandatoryGroup", "SnmpCompliancePart",
  "SnmpComplianceList", "SnmpComplianceObject", "SnmpObjectsPart",
  "SnmpObjectGroupAssignment", "SnmpNotificationGroupAssignment",
  "ModuleComplianceAssignment", "SnmpModuleComplianceList",
  "SnmpModuleComplianceObject", "OptionalModuleName",
  "SnmpVariationsListPart", "SnmpVariationsList", "SnmpVariationPart",
  "ModuleCapabilitiesList", "ModuleCapabilitiesAssignment",
  "AgentCapabilitiesAssignment", "SnmpAccessPart", "SnmpStatusPart",
  "SnmpReferencePart", "SnmpDisplayHintPart", "SnmpIndexPart",
  "SnmpDefValPart", "DefValList", "DefValListElement", "BinaryString",
  "HexString", "CharString", "SymbolsFromModuleList", "SymbolsFromModule",
  "SymbolList", "Symbol", "SequenceItem", "SequenceList",
  "SequenceAssignment", "SnmpTypeTagPart", "SnmpTypeTagList",
  "SnmpTypeTagItem", "OctetStringType", "Value", "Identifier",
  "UCidentifier", "LCidentifier", "End", "Begin", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351
};
# endif

#define YYPACT_NINF -290

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-290)))

#define YYTABLE_NINF -212

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,  -290,    51,   267,  -290,    48,  -290,  -290,    63,    63,
      41,    83,    96,   105,   126,   129,   141,   144,   176,   179,
     181,  -290,   267,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
      81,  -290,    49,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,   115,   195,   232,  -290,   197,    80,    42,  -290,    50,
    -290,  -290,  -290,    19,   111,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   205,  -290,  -290,   111,   209,   223,
     226,  -290,   203,   182,    93,   242,    15,  -290,   190,   240,
       9,   190,   177,     9,     9,  -290,    -3,  -290,  -290,  -290,
     -43,    63,  -290,  -290,  -290,   -43,   213,   160,  -290,    14,
      14,  -290,  -290,   342,   250,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,   227,  -290,   111,   244,   111,
     260,  -290,     8,  -290,   199,    17,   261,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,    80,   131,   261,
    -290,  -290,    80,   249,     5,  -290,   268,   277,   190,   249,
     111,   190,   191,   204,  -290,  -290,  -290,   193,   250,   111,
     190,   152,   210,  -290,  -290,   243,    -4,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,   246,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,    20,  -290,  -290,
     111,   249,  -290,    63,  -290,   111,   191,    87,  -290,  -290,
     293,    24,  -290,  -290,  -290,   238,   286,   251,  -290,  -290,
     111,   252,    63,    63,   249,   252,   190,   249,    80,    80,
      80,   190,   205,   305,  -290,    87,  -290,   249,  -290,  -290,
      10,   300,  -290,  -290,   315,   258,   262,   259,   281,  -290,
     291,  -290,  -290,  -290,  -290,   284,    34,  -290,   190,  -290,
      53,     8,   334,   249,  -290,  -290,  -290,   193,    80,  -290,
     111,   266,   108,   137,   252,   240,   249,   252,  -290,  -290,
    -290,   249,  -290,  -290,   252,   152,   152,   324,  -290,   120,
     152,  -290,  -290,  -290,   111,   240,   284,  -290,  -290,   249,
    -290,    87,  -290,    63,   252,   279,  -290,  -290,   -43,    12,
    -290,  -290,  -290,   240,  -290,   252,   240,   252,   182,  -290,
    -290,   120,   287,   292,   249,  -290,  -290,   252,  -290,   139,
     240,  -290,   325,  -290,  -290,  -290,  -290,   -41,  -290,   240,
    -290,  -290,  -290,   295,  -290,   -30,  -290,  -290,   351,    -7,
     325,  -290,   -43,   288,     4,  -290,  -290,  -290,   356,   357,
     302,    63,    80,    80,  -290,    -7,  -290,  -290,   297,    63,
    -290,  -290,    63,    87,   359,   240,   155,   249,   182,  -290,
     360,    18,   159,   363,   286,  -290,    31,  -290,  -290,  -290,
    -290,   303,    63,    80,  -290,   307,  -290,  -290,  -290,    76,
     370,   371,   384,   385,   390,     8,   191,   163,   182,  -290,
    -290,   171,  -290,   391,  -290,  -290,  -290,  -290,   249,   307,
     303,  -290,  -290,  -290,  -290,   191,   322,   392,   302,    63,
     249,   172,  -290,  -290
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   212,     0,     0,    20,     0,     1,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,     0,     5,     6,     7,     8,    17,    18,    19,
       0,    15,    65,    10,    80,     9,    11,    14,    13,    12,
      16,     0,   210,   211,     3,     0,     0,     0,   183,     0,
     186,   187,   188,     0,     0,   195,   195,   195,   195,   195,
     195,   195,   195,   195,     0,     4,     2,     0,     0,     0,
       0,    66,     0,    73,   195,     0,     0,    53,     0,     0,
     138,     0,     0,   138,   138,    24,     0,   189,    46,   182,
       0,     0,    47,   181,    68,     0,     0,   165,   113,    88,
      87,   106,   114,     0,   194,   197,   107,   112,   109,   110,
     111,   108,   104,   105,   215,     0,    56,     0,     0,     0,
       0,    67,   195,    72,    75,     0,     0,   179,   180,    42,
     206,    82,    81,   208,   207,   209,    86,     0,     0,     0,
      25,    26,     0,    58,     0,    23,     0,     0,     0,    58,
       0,     0,   160,     0,    21,   184,   185,     0,   195,     0,
       0,     0,     0,    90,    89,     0,     0,   102,    92,    94,
      95,    99,    96,    97,    98,   205,     0,   100,   202,   203,
     204,   103,    91,   210,   211,   196,   118,     0,   117,    54,
       0,    58,    69,     0,    71,     0,   160,     0,    83,    85,
     123,     0,    29,    31,    30,     0,   210,    41,    84,   161,
       0,   163,     0,     0,    58,   163,     0,    58,     0,     0,
       0,     0,     0,     0,   101,     0,   164,    58,    38,    39,
      64,    33,    34,    37,     0,     0,     0,     0,     0,    93,
       0,   199,   116,   115,    55,    49,     0,    74,     0,   191,
       0,   195,     0,    58,   122,    27,    28,     0,     0,    57,
       0,     0,     0,     0,   163,     0,    58,   163,   157,   158,
     159,    58,    22,   198,   163,     0,     0,     0,    61,     0,
       0,    59,   200,   201,     0,     0,    48,    51,    70,    58,
     193,     0,   190,     0,   163,     0,    40,   162,   146,     0,
     143,   136,   137,     0,    43,   163,     0,   163,    73,    63,
      62,     0,     0,     0,    58,    45,    50,   163,   192,     0,
       0,    32,   126,   145,   141,   142,   139,     0,   140,     0,
     119,    35,    36,     0,    52,   168,   124,   121,     0,   131,
     125,   128,     0,     0,     0,   153,   120,    60,     0,     0,
     174,     0,     0,     0,   144,   130,   133,   127,     0,     0,
     156,   152,     0,     0,     0,     0,     0,    58,    73,   132,
       0,   148,     0,     0,     0,    41,     0,   173,    44,   129,
     135,    77,     0,     0,   155,   147,   150,   166,   167,     0,
       0,   176,     0,     0,     0,   195,   160,     0,    73,   149,
     178,     0,   172,     0,   169,   170,   171,    76,    58,   148,
      77,   177,   175,   134,   154,   160,    79,     0,   174,     0,
      58,     0,   151,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -290,  -290,  -290,   381,  -290,   404,  -290,   -71,    43,  -290,
     207,  -290,  -247,  -129,   -45,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,   119,  -290,  -290,  -290,  -290,  -101,   306,  -145,
    -290,  -290,   337,  -290,  -290,  -289,  -290,     2,  -290,  -290,
     -69,   253,  -290,  -290,   276,  -290,  -290,   228,   339,  -290,
    -290,  -290,  -290,  -290,    74,  -290,  -290,    61,   147,  -290,
    -290,  -290,  -290,   118,  -290,    11,  -290,    33,  -290,    75,
    -290,  -186,   -74,  -199,  -290,  -290,     3,    21,  -290,    46,
      47,   -61,  -290,   378,    -9,   335,   136,  -290,   -82,   270,
    -290,   326,  -290,  -290,     0,     1,    -1,   -11,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    22,    23,     3,   343,    24,    85,   140,   201,
     202,   230,   231,   232,   233,    25,    26,    27,    28,    29,
     285,   286,   287,    30,   118,   191,    68,   211,   163,   234,
      31,    32,    71,    72,   123,   124,   196,   396,   418,    33,
      98,    99,   100,    34,   101,    35,   187,   188,   102,    36,
     253,   254,   339,   340,   341,   354,   355,   356,   148,    37,
      38,    39,   299,   300,   322,   384,   385,   386,   344,   345,
      40,   221,   143,   261,   160,   350,   365,   390,   391,   133,
     134,    94,    47,    48,    49,    50,   249,   250,   198,   103,
     104,   105,   181,   136,   235,    51,    52,    44,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,     5,    43,    41,    42,   131,   116,   149,   145,   203,
     248,    66,   114,   135,   154,   138,   265,   237,   144,   330,
      95,    43,    41,    42,   161,   138,   144,   197,   352,   130,
     275,   141,   312,   255,   348,   342,     7,   239,    91,    91,
      92,   389,   146,   288,   199,    87,   240,     1,   215,     1,
      46,     6,   349,   194,    91,    54,   189,   208,   192,    96,
     186,    45,   290,    88,   331,   303,   139,    90,   306,   158,
      91,    46,   203,   291,   214,   308,   353,   217,   147,   381,
     342,   162,   153,   276,    46,   400,   227,    69,    70,   216,
     245,   155,   383,   204,     1,   320,   157,    55,   226,   141,
     298,   129,   184,   182,   183,    95,   327,    67,   329,   410,
      56,   129,   223,   264,     1,    21,   267,   301,   335,    57,
     129,     1,    21,   127,   128,    93,   274,   129,    91,   244,
     309,   310,     1,    21,   247,   313,   200,   207,   205,   206,
      58,   209,   266,    59,   125,    73,   302,   271,   336,   259,
     272,    97,   294,     1,    21,    60,   204,    91,    61,    91,
     207,   207,   206,   206,   379,   305,     1,    21,   387,    95,
     307,    21,   409,   126,   289,    91,   243,     1,    21,    91,
     411,   423,   292,    91,   246,   127,   128,    93,   317,   129,
      62,    91,    91,    63,   304,    64,   184,   251,   183,   297,
     207,   205,   206,   262,   263,    93,   228,   229,    96,    74,
     408,    86,   295,   334,   315,    97,   129,   268,   269,   270,
     114,     1,    21,   314,   184,   182,   183,   129,   324,   416,
     151,   152,   326,   117,   373,   328,    75,   119,   228,   229,
     120,    69,     1,    21,   122,   137,    76,   203,   129,   337,
     218,   219,   220,   142,   144,   159,   150,   296,   346,    77,
      78,    79,    95,    80,    81,   158,   380,   186,    82,   190,
     193,   197,   210,   360,   207,   207,   206,   206,   212,   207,
     195,   206,   236,     7,   319,     8,     9,   213,   222,   129,
     184,   251,   183,   238,   378,   241,   228,   229,   252,   323,
       1,    21,    83,    84,    10,   257,   129,   413,   258,    11,
      12,    13,    14,    15,    16,   394,   273,   260,  -211,   422,
      17,    18,   277,    19,   278,   279,   407,   281,     5,   280,
     282,   204,   106,   107,   108,   109,   110,   111,   112,   113,
     283,   284,   366,   358,   293,     5,   311,   321,   165,   166,
     371,   367,   368,   372,   298,   332,    20,     1,    21,   338,
     333,   351,   375,   347,   374,   359,   362,   363,   364,   376,
     382,   167,   388,   397,   370,   207,   205,   206,   395,   402,
     401,   383,   398,   168,   169,   170,   171,   172,   173,   174,
     175,   403,   176,   404,   405,   177,   178,   179,   180,   406,
     417,   389,   419,    65,     4,   316,   164,   377,   256,   121,
     421,   224,   415,   132,   357,   242,   369,   325,   399,   361,
     414,   420,   392,   393,   412,    89,   156,   318,   225,     0,
     185,     0,     1,    21
};

static const yytype_int16 yycheck[] =
{
       9,     0,     3,     3,     3,    74,    67,    81,    79,   138,
     196,    22,    15,    74,    86,    10,   215,   162,    14,   308,
      12,    22,    22,    22,    10,    10,    14,    10,    35,    74,
      20,    76,   279,     9,    64,    76,    16,    41,    20,    20,
      21,    10,    33,     9,   126,    46,    50,    90,   149,    90,
       8,     0,    82,   122,    20,    14,   117,   139,   119,    51,
      40,    13,     9,    21,   311,   264,    51,    17,   267,    52,
      20,     8,   201,    20,   148,   274,    83,   151,    69,   368,
      76,    67,    85,    73,     8,     9,   160,    38,    39,   150,
     191,    90,    74,   138,    90,   294,    95,    14,   159,   144,
      88,    96,   103,   103,   103,    12,   305,    26,   307,   398,
      14,    96,   157,   214,    90,    91,   217,     9,   317,    14,
      96,    90,    91,    92,    93,    94,   227,    96,    20,   190,
     275,   276,    90,    91,   195,   280,   137,   138,   138,   138,
      14,   142,   216,    14,    51,    30,     9,   221,     9,   210,
     222,    58,   253,    90,    91,    14,   201,    20,    14,    20,
     161,   162,   161,   162,     9,   266,    90,    91,     9,    12,
     271,    91,     9,    80,   248,    20,   187,    90,    91,    20,
       9,     9,   251,    20,   193,    92,    93,    94,   289,    96,
      14,    20,    20,    14,   265,    14,   197,   197,   197,   260,
     201,   201,   201,   212,   213,    94,    86,    87,    51,    14,
     396,    14,   257,   314,   285,    58,    96,   218,   219,   220,
      15,    90,    91,   284,   225,   225,   225,    96,   299,   415,
      83,    84,   303,    24,   363,   306,     4,    14,    86,    87,
      14,    38,    90,    91,    62,     3,    14,   376,    96,   320,
      59,    60,    61,    63,    14,    95,    79,   258,   329,    27,
      28,    29,    12,    31,    32,    52,   367,    40,    36,    25,
      10,    10,    23,   344,   275,   276,   275,   276,    10,   280,
      81,   280,    72,    16,   293,    18,    19,    10,    84,    96,
     291,   291,   291,    50,   365,    49,    86,    87,     5,   298,
      90,    91,    70,    71,    37,    67,    96,   408,    22,    42,
      43,    44,    45,    46,    47,   376,    11,    65,    67,   420,
      53,    54,    22,    56,     9,    67,   395,    68,   327,    67,
      49,   376,    56,    57,    58,    59,    60,    61,    62,    63,
      49,    57,   351,   342,    10,   344,    22,    68,     6,     7,
     359,   352,   353,   362,    88,    68,    89,    90,    91,    34,
      68,    10,   363,    68,   363,    77,    10,    10,    66,    10,
      10,    29,     9,   382,    77,   376,   376,   376,    75,     9,
     389,    74,   383,    41,    42,    43,    44,    45,    46,    47,
      48,    20,    50,     9,     9,    53,    54,    55,    56,     9,
      78,    10,    10,    22,     0,   286,   100,   364,   201,    72,
     419,   158,   410,    74,   340,   187,   355,   299,   385,   344,
     409,   418,   376,   376,   403,    47,    91,   291,   158,    -1,
     104,    -1,    90,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    90,    98,   101,   102,   192,     0,    16,    18,    19,
      37,    42,    43,    44,    45,    46,    47,    53,    54,    56,
      89,    91,    99,   100,   103,   112,   113,   114,   115,   116,
     120,   127,   128,   136,   140,   142,   146,   156,   157,   158,
     167,   191,   192,   193,   194,    13,     8,   179,   180,   181,
     182,   192,   193,   181,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,   100,   194,    26,   123,    38,
      39,   129,   130,    30,    14,     4,    14,    27,    28,    29,
      31,    32,    36,    70,    71,   104,    14,   193,    21,   180,
      17,    20,    21,    94,   178,    12,    51,    58,   137,   138,
     139,   141,   145,   186,   187,   188,   141,   141,   141,   141,
     141,   141,   141,   141,    15,   195,   178,    24,   121,    14,
      14,   129,    62,   131,   132,    51,    80,    92,    93,    96,
     111,   137,   145,   176,   177,   178,   190,     3,    10,    51,
     105,   111,    63,   169,    14,   104,    33,    69,   155,   169,
      79,   155,   155,    85,   195,   192,   182,   192,    52,    95,
     171,    10,    67,   125,   125,     6,     7,    29,    41,    42,
      43,    44,    45,    46,    47,    48,    50,    53,    54,    55,
      56,   189,   191,   192,   193,   188,    40,   143,   144,   178,
      25,   122,   178,    10,   137,    81,   133,    10,   185,   185,
     193,   106,   107,   110,   111,   191,   192,   193,   185,   193,
      23,   124,    10,    10,   169,   124,   178,   169,    59,    60,
      61,   168,    84,   111,   138,   186,   178,   169,    86,    87,
     108,   109,   110,   111,   126,   191,    72,   126,    50,    41,
      50,    49,   144,   194,   178,   124,   181,   178,   168,   183,
     184,   191,     5,   147,   148,     9,   107,    67,    22,   178,
      65,   170,   181,   181,   124,   170,   169,   124,   193,   193,
     193,   169,   195,    11,   124,    20,    73,    22,     9,    67,
      67,    68,    49,    49,    57,   117,   118,   119,     9,   169,
       9,    20,   137,    10,   124,   111,   193,   178,    88,   159,
     160,     9,     9,   170,   104,   124,   170,   124,   170,   126,
     126,    22,   109,   126,   178,   104,   119,   124,   183,   181,
     170,    68,   161,   192,   104,   160,   104,   170,   104,   170,
     132,   109,    68,    68,   124,   170,     9,   104,    34,   149,
     150,   151,    76,   102,   165,   166,   104,    68,    64,    82,
     172,    10,    35,    83,   152,   153,   154,   151,   192,    77,
     104,   166,    10,    10,    66,   173,   181,   193,   193,   154,
      77,   181,   181,   110,   192,   193,    10,   105,   104,     9,
     124,   132,    10,    74,   162,   163,   164,     9,     9,    10,
     174,   175,   176,   177,   178,    75,   134,   181,   193,   164,
       9,   181,     9,    20,     9,     9,     9,   137,   168,     9,
     132,     9,   174,   124,   162,   134,   168,    78,   135,    10,
     173,   181,   124,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   102,   102,   103,   103,   104,   104,   105,   106,   106,
     107,   107,   107,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   111,   112,   113,   114,   115,   116,   117,   117,
     118,   118,   119,   120,   121,   122,   123,   124,   124,   125,
     125,   125,   126,   126,   126,   127,   127,   127,   128,   129,
     130,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   137,
     137,   138,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   141,   141,   142,   143,   143,   144,   145,
     146,   146,   147,   147,   148,   149,   149,   150,   150,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   155,   156,
     157,   158,   159,   159,   160,   161,   161,   162,   162,   163,
     163,   164,   165,   165,   166,   166,   167,   168,   168,   168,
     168,   169,   170,   170,   171,   171,   172,   172,   172,   173,
     173,   173,   173,   173,   173,   174,   174,   175,   175,   176,
     177,   178,   179,   179,   180,   181,   181,   182,   182,   182,
     183,   184,   184,   185,   186,   186,   187,   187,   188,   189,
     189,   189,   189,   189,   189,   189,   190,   190,   190,   190,
     191,   191,   192,   193,   194,   195
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     3,     2,     2,     2,     3,     2,     1,
       1,     1,     4,     1,     1,     4,     4,     1,     1,     1,
       3,     1,     1,     6,    11,     7,     3,     3,     1,     0,
       2,     1,     3,     2,     2,     2,     2,     2,     0,     3,
       6,     3,     3,     3,     1,     1,     2,     3,     3,     3,
       5,     2,     1,     0,     2,     0,     2,     0,     4,     0,
       1,     3,     3,     4,     4,     4,     3,     1,     1,     2,
       2,     2,     2,     3,     2,     2,     2,     2,     2,     2,
       2,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     5,     2,     1,     1,     6,
       8,     8,     1,     0,     4,     1,     0,     2,     1,     4,
       1,     0,     2,     1,     6,     3,     4,     4,     0,     7,
       7,     7,     2,     1,     4,     1,     0,     1,     0,     2,
       1,     8,     2,     1,     7,     4,     9,     2,     2,     2,
       0,     2,     2,     0,     2,     0,     4,     4,     0,     4,
       4,     4,     4,     2,     0,     3,     1,     3,     2,     1,
       1,     1,     2,     1,     3,     3,     1,     1,     1,     2,
       2,     1,     3,     3,     1,     0,     2,     1,     4,     2,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
      yychar = yylex ();
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
        case 6:
#line 263 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1777 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 267 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1785 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 271 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1793 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 275 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1801 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 279 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1809 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 283 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1817 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 288 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1825 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 292 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1833 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 297 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1841 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 301 "parser.y" /* yacc.c:1646  */
    {
   m_pModule->pObjectList->add((yyvsp[0].pObject));
}
#line 1849 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 310 "parser.y" /* yacc.c:1646  */
    {
   m_pModule = new MP_MODULE;
   m_pModule->pszName = (yyvsp[0].pszString);
}
#line 1858 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 318 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[-3].pszString);
}
#line 1866 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 322 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[-5].pszString);
}
#line 1874 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 329 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-2].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 1886 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 337 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-1].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 1898 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 348 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pOID) = (yyvsp[0].pOID);
}
#line 1906 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 352 "parser.y" /* yacc.c:1646  */
    {
   MP_SUBID *subid;

   subid = new MP_SUBID;
   subid->dwValue = (yyvsp[0].number).value.nInt32;
   subid->pszName = NULL;
   subid->bResolved = TRUE;
   (yyval.pOID) = new ObjectArray<MP_SUBID>(16, 16, true);
   (yyval.pOID)->add(subid);
}
#line 1921 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 366 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pOID) = (yyvsp[-1].pOID);
}
#line 1929 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 373 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pOID)->add((yyvsp[0].pSubId));
}
#line 1937 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 377 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pOID) = new ObjectArray<MP_SUBID>(16, 16, true);
   (yyval.pOID)->add((yyvsp[0].pSubId));
}
#line 1946 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 385 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSubId) = new MP_SUBID;
   (yyval.pSubId)->dwValue = (yyvsp[0].number).value.nInt32;
   (yyval.pSubId)->pszName = NULL;
   (yyval.pSubId)->bResolved = TRUE;
}
#line 1957 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 392 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSubId) = new MP_SUBID;
   (yyval.pSubId)->dwValue = 0;
   (yyval.pSubId)->pszName = (yyvsp[0].pszString);
   (yyval.pSubId)->bResolved = FALSE;
}
#line 1968 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 399 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSubId) = new MP_SUBID;
   (yyval.pSubId)->dwValue = (yyvsp[-1].number).value.nInt32;
   (yyval.pSubId)->pszName = (yyvsp[-3].pszString);
   (yyval.pSubId)->bResolved = TRUE;
}
#line 1979 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 410 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 1987 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 415 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-3].pszString));
}
#line 1995 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 428 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (char *)malloc(strlen((yyvsp[-2].pszString)) + strlen((yyvsp[0].pszString)) + 2);
   sprintf((yyval.pszString), "%s.%s", (yyvsp[-2].pszString), (yyvsp[0].pszString));
   free((yyvsp[-2].pszString));
   free((yyvsp[0].pszString));
}
#line 2006 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 435 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 2014 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 442 "parser.y" /* yacc.c:1646  */
    {
   (yyval.number) = (yyvsp[0].number);
}
#line 2022 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 453 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-5].pszString);
   (yyval.pObject)->iStatus = (yyvsp[-3].nInteger);
   (yyval.pObject)->pszDescription = (yyvsp[-2].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 2036 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 475 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-10].pszString);
   (yyval.pObject)->iSyntax = (yyvsp[-8].pSyntax)->nSyntax;
   (yyval.pObject)->pszDataType = (yyvsp[-8].pSyntax)->pszStr;
   (yyvsp[-8].pSyntax)->pszStr = NULL;
   delete (yyvsp[-8].pSyntax);
   (yyval.pObject)->iAccess = (yyvsp[-6].nInteger);
   (yyval.pObject)->iStatus = (yyvsp[-5].nInteger);
   (yyval.pObject)->pszDescription = (yyvsp[-4].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 2055 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 499 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->iSyntax = MIB_TYPE_MODID;
   (yyval.pObject)->pszName = (yyvsp[-6].pszString);
   (yyval.pObject)->pszDescription = (yyvsp[-2].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 2069 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 512 "parser.y" /* yacc.c:1646  */
    {
	delete m_pModule->pImportList;
   m_pModule->pImportList = (yyvsp[-1].pImportList);
}
#line 2078 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 520 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2086 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 538 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-1].pszString));
   safe_free((yyvsp[0].pszString));
}
#line 2095 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 546 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[-1].pszString);
}
#line 2103 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 553 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2111 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 560 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2119 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 567 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2127 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 574 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 2135 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 578 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = NULL;
}
#line 2143 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 593 "parser.y" /* yacc.c:1646  */
    {
}
#line 2150 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 605 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2158 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 612 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2166 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 619 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2174 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 626 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = (yyvsp[0].pSyntax);
}
#line 2182 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 633 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = (yyvsp[0].pSyntax);
}
#line 2190 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 637 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = new MP_SYNTAX;
   (yyval.pSyntax)->nSyntax = MIB_TYPE_OTHER;
}
#line 2199 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 645 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2207 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 653 "parser.y" /* yacc.c:1646  */
    {
	delete (yyvsp[0].pSyntax);
}
#line 2215 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 661 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2223 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 669 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_TYPEDEF;
   if ((yyvsp[0].pSyntax) != NULL)
   {
      (yyval.pObject)->pszName = (yyvsp[0].pSyntax)->pszStr;
      (yyval.pObject)->iSyntax = (yyvsp[0].pSyntax)->nSyntax;
      (yyval.pObject)->pszDescription = (yyvsp[0].pSyntax)->pszDescription;
      (yyvsp[0].pSyntax)->pszStr = NULL;
      (yyvsp[0].pSyntax)->pszDescription = NULL;
      delete (yyvsp[0].pSyntax);
   }
}
#line 2241 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 683 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_TEXTUAL_CONVENTION;
   (yyval.pObject)->pszName = (yyvsp[-2].pszString);
   if ((yyvsp[0].pSyntax) != NULL)
   {
      (yyval.pObject)->iSyntax = (yyvsp[0].pSyntax)->nSyntax;
      (yyval.pObject)->pszDataType = (yyvsp[0].pSyntax)->pszStr;
      (yyval.pObject)->pszDescription = (yyvsp[0].pSyntax)->pszDescription;
      (yyvsp[0].pSyntax)->pszStr = NULL;
      (yyvsp[0].pSyntax)->pszDescription = NULL;
      delete (yyvsp[0].pSyntax);
   }
}
#line 2260 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 698 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_TYPEDEF;
   (yyval.pObject)->pszName = (yyvsp[-2].pszString);
   if ((yyvsp[0].pSyntax) != NULL)
   {
      (yyval.pObject)->iSyntax = (yyvsp[0].pSyntax)->nSyntax;
      (yyval.pObject)->pszDataType = (yyvsp[0].pSyntax)->pszStr;
      (yyval.pObject)->pszDescription = (yyvsp[0].pSyntax)->pszDescription;
      (yyvsp[0].pSyntax)->pszStr = NULL;
      (yyvsp[0].pSyntax)->pszDescription = NULL;
      delete (yyvsp[0].pSyntax);
   }
}
#line 2279 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 713 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_SEQUENCE;
   (yyval.pObject)->pszName = (yyvsp[-3].pszString);
}
#line 2289 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 719 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_SEQUENCE;
   (yyval.pObject)->pszName = (yyvsp[-3].pszString);
}
#line 2299 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 725 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_CHOICE;
   (yyval.pObject)->pszName = (yyvsp[-3].pszString);
}
#line 2309 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 731 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_VALUE;
   (yyval.pObject)->pszName = (yyvsp[-2].pszString);
}
#line 2319 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 740 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = (yyvsp[0].pSyntax);
}
#line 2327 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 744 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = (yyvsp[0].pSyntax);
}
#line 2335 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 748 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = (yyvsp[-1].pSyntax);
}
#line 2343 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 752 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = (yyvsp[-1].pSyntax);
}
#line 2351 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 759 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = new MP_SYNTAX;
   (yyval.pSyntax)->nSyntax = -1;
   (yyval.pSyntax)->pszStr = (yyvsp[0].pszString);
}
#line 2361 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 768 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_INTEGER);
}
#line 2369 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 772 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_INTEGER);
}
#line 2377 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 776 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_INTEGER32);
}
#line 2385 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 780 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_UNSIGNED32);
}
#line 2393 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 784 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_COUNTER);
}
#line 2401 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 788 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_COUNTER32);
}
#line 2409 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 792 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_COUNTER64);
}
#line 2417 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 796 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_GAUGE32);
}
#line 2425 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 800 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_TIMETICKS);
}
#line 2433 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 804 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_SEQUENCE);
   delete (yyvsp[0].pSyntax);
}
#line 2442 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 809 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_OBJID);
}
#line 2450 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 813 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_OCTETSTR);
}
#line 2458 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 820 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_IPADDR);
   (yyval.pSyntax)->pszStr = strdup("IpAddress");
}
#line 2467 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 825 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_OPAQUE);
   (yyval.pSyntax)->pszStr = strdup("Opaque");
}
#line 2476 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 830 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_INTEGER32);
   (yyval.pSyntax)->pszStr = strdup("Integer32");
}
#line 2485 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 835 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_UNSIGNED32);
   (yyval.pSyntax)->pszStr = strdup("Unsigned32");
}
#line 2494 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 840 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_TIMETICKS);
   (yyval.pSyntax)->pszStr = strdup("TimeTicks");
}
#line 2503 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 845 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_COUNTER);
   (yyval.pSyntax)->pszStr = strdup("Counter");
}
#line 2512 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 850 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_COUNTER32);
   (yyval.pSyntax)->pszStr = strdup("Counter32");
}
#line 2521 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 855 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_COUNTER64);
   (yyval.pSyntax)->pszStr = strdup("Counter64");
}
#line 2530 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 860 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = create_std_syntax(MIB_TYPE_GAUGE32);
   (yyval.pSyntax)->pszStr = strdup("Gauge32");
}
#line 2539 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 868 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[0].pSyntax);
}
#line 2547 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 872 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[0].pSyntax);
}
#line 2555 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 879 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_MACRO;
   (yyval.pObject)->pszName = (yyvsp[-4].pszString);
}
#line 2565 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 902 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pSyntax) = (yyvsp[0].pSyntax);
   (yyval.pSyntax)->pszDescription = (yyvsp[-2].pszString);
}
#line 2574 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 916 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-7].pszString);
   (yyval.pObject)->iSyntax = MIB_TYPE_NOTIFTYPE;
   (yyval.pObject)->iAccess = (yyvsp[-4].nInteger);
   (yyval.pObject)->iStatus = (yyvsp[-3].nInteger);
   (yyval.pObject)->pszDescription = (yyvsp[-2].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 2590 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 933 "parser.y" /* yacc.c:1646  */
    {
   MP_SUBID *pSubId;

   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-7].pszString);
   (yyval.pObject)->iSyntax = MIB_TYPE_TRAPTYPE;
   (yyval.pObject)->pszDescription = (yyvsp[-2].pszString);

   pSubId = new MP_SUBID;
   pSubId->pszName = (yyvsp[-4].pszString);
   (yyval.pObject)->pOID->add(pSubId);

   pSubId = new MP_SUBID;
   pSubId->pszName = (char *)malloc(strlen((yyvsp[-4].pszString)) + 3);
   sprintf(pSubId->pszName, "%s#0", (yyvsp[-4].pszString));
   pSubId->bResolved = TRUE;
   (yyval.pObject)->pOID->add(pSubId);

   for(int i = 0; i < (yyvsp[0].pOID)->size(); i++)
      (yyval.pObject)->pOID->add((yyvsp[0].pOID)->get(i));
   (yyvsp[0].pOID)->setOwner(false);
   delete (yyvsp[0].pOID);
}
#line 2619 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 966 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2627 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 983 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2635 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1004 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-4].pszString));
   delete (yyvsp[-3].pSyntax);
   safe_free((yyvsp[0].pszString));
}
#line 2645 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1010 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-1].pszString));
   safe_free((yyvsp[0].pszString));
}
#line 2654 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1018 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1022 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2670 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1035 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-6].pszString);
   (yyval.pObject)->iStatus = (yyvsp[-3].nInteger);
   (yyval.pObject)->iSyntax = MIB_TYPE_OBJGROUP;
   (yyval.pObject)->pszDescription = (yyvsp[-2].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 2685 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1054 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-6].pszString);
   (yyval.pObject)->iStatus = (yyvsp[-3].nInteger);
   (yyval.pObject)->pszDescription = (yyvsp[-2].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
}
#line 2699 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1072 "parser.y" /* yacc.c:1646  */
    {
   free((yyvsp[-6].pszString));
   safe_free((yyvsp[-3].pszString));
   delete (yyvsp[0].pOID);
}
#line 2709 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1092 "parser.y" /* yacc.c:1646  */
    {
   free((yyvsp[0].pszString));
}
#line 2717 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1116 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-6].pszString));
   delete (yyvsp[-5].pSyntax);
   safe_free((yyvsp[0].pszString));
}
#line 2727 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1130 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-5].pszString));
   delete (yyvsp[-2].pList);
}
#line 2736 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1135 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-3].pszString));
   delete (yyvsp[-1].pList);
}
#line 2745 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1149 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pObject) = new MP_OBJECT;
   (yyval.pObject)->iType = MIBC_OBJECT;
   (yyval.pObject)->pszName = (yyvsp[-8].pszString);
   (yyval.pObject)->iStatus = (yyvsp[-4].nInteger);
   (yyval.pObject)->iSyntax = MIB_TYPE_AGENTCAP;
   (yyval.pObject)->pszDescription = (yyvsp[-3].pszString);
   delete (yyval.pObject)->pOID;
   (yyval.pObject)->pOID = (yyvsp[0].pOID);
   safe_free((yyvsp[-5].pszString));
}
#line 2761 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1164 "parser.y" /* yacc.c:1646  */
    {
   (yyval.nInteger) = AccessFromText((yyvsp[0].pszString));
   free((yyvsp[0].pszString));
}
#line 2770 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1169 "parser.y" /* yacc.c:1646  */
    {
   (yyval.nInteger) = AccessFromText((yyvsp[0].pszString));
   free((yyvsp[0].pszString));
}
#line 2779 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1174 "parser.y" /* yacc.c:1646  */
    {
   (yyval.nInteger) = AccessFromText((yyvsp[0].pszString));
   free((yyvsp[0].pszString));
}
#line 2788 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1179 "parser.y" /* yacc.c:1646  */
    {
   (yyval.nInteger) = 0;
}
#line 2796 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1186 "parser.y" /* yacc.c:1646  */
    {
   static const char *pStatusText[] = { "mandatory", "optional", "obsolete", "deprecated", "current", NULL };
   int i;

   for(i = 0; pStatusText[i] != NULL; i++)
      if (!stricmp(pStatusText[i], (yyvsp[0].pszString)))
      {
         (yyval.nInteger) = i + 1;
         break;
      }
   if (pStatusText[i] == NULL)
   {
      char szBuffer[256];

      sprintf(szBuffer, "Invalid STATUS value \"%s\"", (yyvsp[0].pszString));
      mperror(szBuffer);
   }
   free((yyvsp[0].pszString));
}
#line 2820 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1209 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2828 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1217 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2836 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1225 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2844 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1229 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-1].pszString));
}
#line 2852 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1239 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-1].pszString));
}
#line 2860 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1244 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[0].pOID);
}
#line 2868 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1257 "parser.y" /* yacc.c:1646  */
    {
   delete (yyvsp[-1].pList);
}
#line 2876 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1265 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2884 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1272 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2892 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1279 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 2900 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1286 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pImportList)->add((yyvsp[0].pImports));
}
#line 2908 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1290 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pImportList) = new ObjectArray<MP_IMPORT_MODULE>(16, 16, true);
   (yyval.pImportList)->add((yyvsp[0].pImports));
}
#line 2917 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1298 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pImports) = new MP_IMPORT_MODULE;
   (yyval.pImports)->pszName = (yyvsp[0].pszString);
   delete (yyval.pImports)->pSymbols;
   (yyval.pImports)->pSymbols = (yyvsp[-2].pList);
}
#line 2928 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1308 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pList)->add((yyvsp[0].pszString));
}
#line 2936 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1312 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pList) = new Array(16, 16, true);
   (yyval.pList)->add((yyvsp[0].pszString));
}
#line 2945 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1320 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 2953 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1324 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 2961 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1328 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 2969 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1335 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-1].pszString));
   delete (yyvsp[0].pSyntax);
}
#line 2978 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1362 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[-2].pszString));
}
#line 2986 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1382 "parser.y" /* yacc.c:1646  */
    {
   safe_free((yyvsp[0].pszString));
}
#line 2994 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1389 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 3002 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1393 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 3010 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1400 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 3018 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1407 "parser.y" /* yacc.c:1646  */
    {
   (yyval.pszString) = (yyvsp[0].pszString);
}
#line 3026 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 3030 "parser.tab.cpp" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 1420 "parser.y" /* yacc.c:1906  */


MP_MODULE *ParseMIB(char *pszFilename)
{
   m_pModule = NULL;
   mpin = fopen(pszFilename, "r");
   if (mpin != NULL)
   {
	   m_pszCurrentFilename = pszFilename;
      g_nCurrLine = 1;
      InitStateStack();
      /*mpdebug=1;*/
      ResetScanner();
      mpparse();
      fclose(mpin);
   }
   else
   {
      Error(ERR_CANNOT_OPEN_FILE, pszFilename, strerror(errno));
      return NULL;
   }
   return m_pModule;
}

extern "C" int mpwrap()
{
	return 1;
}

int mperror(const char *pszMsg)
{
   Error(ERR_PARSER_ERROR, m_pszCurrentFilename, pszMsg, g_nCurrLine);
   return 0;
}
