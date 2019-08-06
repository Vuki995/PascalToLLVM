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

#ifndef YY_YY_YAC_TAB_HPP_INCLUDED
# define YY_YY_YAC_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    bool_token = 258,
    num_token = 259,
    string_token = 260,
    id_token = 261,
    begin_token = 262,
    end_token = 263,
    program_token = 264,
    print_token = 265,
    read_token = 266,
    if_token = 267,
    then_token = 268,
    else_token = 269,
    function_token = 270,
    procedure_token = 271,
    while_token = 272,
    do_token = 273,
    for_token = 274,
    to_token = 275,
    type_token = 276,
    forward_token = 277,
    continue_token = 278,
    break_token = 279,
    exit_token = 280,
    repeat_token = 281,
    until_token = 282,
    int_token = 283,
    float_token = 284,
    char_token = 285,
    array_token = 286,
    of_token = 287,
    const_token = 288,
    var_token = 289,
    bool_type = 290,
    record_token = 291,
    and_token = 292,
    or_token = 293,
    not_token = 294,
    bita_token = 295,
    bito_token = 296,
    bitn_token = 297,
    LT = 298,
    GT = 299,
    EQ = 300,
    NE = 301,
    bit_and = 302,
    bit_or = 303,
    bit_not = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "yac.ypp" /* yacc.c:1909  */
 
bool* b;
izraz* i;
naredba* n;
float f;
string* nm;
string* pr;
vector<izraz*> *vE;
vector<naredba*> *vN;
vector<string>* vS;
vector<pair<string,tip*>>* lST;
vector<pair<string,izraz*>>* vSI;
tip* t;
vector<subprogram*>* vSP;
pair<string,tip*>* pST;
map<string,tip*>*mST;
Glavno* gl;

#line 123 "yac.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YAC_TAB_HPP_INCLUDED  */
