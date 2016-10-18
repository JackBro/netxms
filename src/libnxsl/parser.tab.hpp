/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 28 "parser.y" /* yacc.c:1909  */

	INT32 valInt32;
	UINT32 valUInt32;
	INT64 valInt64;
	UINT64 valUInt64;
	char *valStr;
	double valReal;
	NXSL_Value *pConstant;
	NXSL_Instruction *pInstruction;

#line 137 "parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (yyscan_t scanner, NXSL_Lexer *pLexer, NXSL_Compiler *pCompiler, NXSL_Program *pScript);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
