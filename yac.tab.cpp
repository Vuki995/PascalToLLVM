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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yac.ypp" /* yacc.c:339  */

#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
#include<stack>
#include"naredbe.hpp"
using namespace std; 
#define YYDEBUG 1 
extern int yylex();
void yyerror(string s){ 
cerr<<s<<endl;
exit(EXIT_FAILURE);
}
string ime;
int inc=0;
vector<string>* headeri;
map<string,tip*> tipovi;
map<string,izraz*> konstante;
map<string,pair<tip*,izraz*>> globalne;
map<string,subprogram*>funkcije;
stack<map<string,pair<tip*,izraz*>>> lokalne; 

#line 90 "yac.tab.cpp" /* yacc.c:339  */

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
   by #include "yac.tab.hpp".  */
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
#line 24 "yac.ypp" /* yacc.c:355  */
 
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

#line 199 "yac.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YAC_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "yac.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      59,    60,    52,    50,    63,    51,    56,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    57,
       2,    58,     2,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    62,    54,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    86,    87,    89,   105,   121,   133,   135,
     140,   145,   149,   154,   158,   160,   163,   175,   181,   185,
     195,   200,   203,   204,   205,   206,   213,   219,   220,   221,
     224,   226,   231,   232,   234,   238,   243,   244,   248,   254,
     255,   257,   259,   261,   264,   267,   271,   272,   273,   276,
     284,   289,   295,   299,   302,   305,   307,   308,   309,   313,
     314,   318,   322,   326,   330,   334,   338,   342,   345,   349,
     353,   357,   361,   365,   369,   372,   373,   375,   378,   381,
     389,   393,   398,   400,   407,   409,   411
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "bool_token", "num_token",
  "string_token", "id_token", "begin_token", "end_token", "program_token",
  "print_token", "read_token", "if_token", "then_token", "else_token",
  "function_token", "procedure_token", "while_token", "do_token",
  "for_token", "to_token", "type_token", "forward_token", "continue_token",
  "break_token", "exit_token", "repeat_token", "until_token", "int_token",
  "float_token", "char_token", "array_token", "of_token", "const_token",
  "var_token", "bool_type", "record_token", "and_token", "or_token",
  "not_token", "bita_token", "bito_token", "bitn_token", "LT", "GT", "EQ",
  "NE", "bit_and", "bit_or", "bit_not", "'+'", "'-'", "'*'", "'/'", "'^'",
  "'['", "'.'", "';'", "'='", "'('", "')'", "':'", "']'", "','", "'@'",
  "$accept", "start", "def_types", "type_list", "consts", "const_list",
  "constE", "vars", "functions", "procedures", "types", "records", "args",
  "var_list", "arg_list", "blok", "lines", "line", "ids", "EP", "E",
  "nizE", YY_NULLPTR
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
      43,    45,    42,    47,    94,    91,    46,    59,    61,    40,
      41,    58,    93,    44,    64
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    10,    25,   -25,  -115,    16,    36,    22,  -115,    -8,
     -46,    50,    40,    36,     5,    82,    31,    42,    36,  -115,
     -32,  -115,  -115,  -115,  -115,    56,  -115,   122,     5,  -115,
    -115,   117,   123,    75,    43,   118,     5,   134,    84,    96,
    -115,  -115,  -115,  -115,  -115,    91,    36,     5,   151,     7,
    -115,   106,     5,   138,   117,    87,  -115,   107,   180,   170,
     124,   131,  -115,   127,  -115,  -115,     5,    36,   119,   120,
     130,   135,    92,   189,  -115,  -115,  -115,   180,    -1,   148,
     139,    23,   141,  -115,   194,     5,  -115,   142,   144,    41,
      92,    92,    92,  -115,  -115,  -115,   149,    92,    92,    92,
     175,   152,   158,  -115,    81,  -115,   154,  -115,  -115,    92,
     203,    88,    36,   161,  -115,   153,    36,  -115,    92,  -115,
     370,    79,   286,   307,   328,    48,   387,   370,   349,   217,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,  -115,    92,   227,    92,    92,  -115,  -115,   246,
    -115,  -115,   172,   202,     5,   370,  -115,    88,  -115,  -115,
     222,  -115,    80,  -115,  -115,   387,   387,   370,   370,   394,
     394,   394,   394,    62,    62,    69,    69,   266,  -115,   226,
     370,  -115,   179,     5,   181,  -115,   217,  -115,  -115,    92,
     -21,  -115,   -16,   223,   204,   183,   217,   186,   217,   217,
     217,  -115,   195,  -115,   196,  -115,  -115,  -115,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     8,    37,     0,
       0,     0,    15,     3,     0,     0,     0,     0,     0,    18,
       0,    25,    22,    23,    24,     0,    28,     0,     0,     6,
      36,     0,     7,     0,     0,    21,     0,     0,     0,     0,
      27,    13,    11,    12,    10,     0,    14,     0,     0,     0,
       5,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,    31,     0,    29,     9,     0,    33,    58,     0,
       0,     0,     0,     0,    47,    46,    53,     0,     0,     0,
       0,     0,     0,     2,     0,     0,    34,     0,    32,     0,
       0,     0,     0,    84,    80,    81,    79,     0,     0,     0,
       0,     0,     0,    58,     0,    38,     0,    40,    55,     0,
       0,     0,    33,     0,    30,     0,     0,    52,     0,    86,
      60,     0,     0,     0,     0,     0,    74,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,    56,    39,     0,
      57,    43,     0,     0,     0,    59,    51,     0,    41,    42,
       0,    82,     0,    75,    48,    72,    73,    65,    66,    69,
      68,    70,    71,    61,    62,    63,    64,     0,    78,     0,
      49,    54,     0,     0,     0,    85,     0,    83,    77,     0,
      15,    26,    15,    44,     0,     0,     0,     0,     0,     0,
       0,    20,     0,    17,     0,    45,    50,    19,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,  -115,  -115,   197,   -29,  -115,  -115,
     -28,  -115,   150,   243,    -3,  -114,   188,   -72,   190,  -107,
     -70,   160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    12,    17,    44,    19,    35,    49,
      29,    39,    87,    88,    34,    60,    79,    80,    81,   119,
     120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,   195,   100,    10,   151,   103,   197,   106,    50,     1,
      20,    21,    14,    18,    58,   164,     3,    15,    18,    56,
     122,   123,   124,    59,    62,     4,    36,   126,   127,   128,
     106,    15,     5,    22,    23,    24,    25,     6,    86,   149,
      26,    27,     8,    55,    93,    94,    95,    96,   155,    13,
     185,    93,    94,    95,    96,    11,    16,   114,    78,    28,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   193,   177,    18,   179,   180,   108,   109,   110,
      97,   111,   202,    98,   204,   205,   206,    97,    30,    31,
      98,    93,    94,    95,    96,    93,    94,    95,    96,    32,
      99,   117,   132,   133,    47,   118,    15,    99,   161,   132,
     133,    37,   118,    55,   140,   141,   142,   143,   144,   194,
      41,    42,    43,   142,   143,   144,   184,    97,    38,    45,
      98,    97,    46,    48,    98,   108,   109,   110,    51,   156,
     187,   147,   157,   157,    63,    52,    64,    99,    66,    54,
      15,    99,   118,    53,    68,   191,   105,    57,    69,    70,
      71,   196,    61,   198,    68,    72,    67,    73,    69,    70,
      71,    74,    75,    76,    77,    72,    82,    73,    89,    90,
      83,    74,    75,    76,    77,   146,    68,    84,    85,    91,
      69,    70,    71,   129,    92,   101,   107,    72,   113,    73,
     112,   116,   115,    74,    75,    76,    77,    78,   125,   150,
     145,   148,   130,   131,   154,   132,   133,    78,   134,   135,
     136,   137,   200,   153,    58,   138,   139,   140,   141,   142,
     143,   144,   182,   178,   183,   186,   190,   199,   192,    78,
     201,   130,   131,   203,   132,   133,   189,   134,   135,   136,
     137,    65,   207,   208,   138,   139,   140,   141,   142,   143,
     144,    33,   152,   130,   131,   102,   132,   133,   104,   134,
     135,   136,   137,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   130,   131,   162,   132,   133,     0,   134,
     135,   136,   137,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   130,   131,     0,   132,   133,   181,   134,
     135,   136,   137,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   130,   131,     0,   132,   133,   188,   134,
     135,   136,   137,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,     0,   130,   131,   158,   132,   133,     0,
     134,   135,   136,   137,     0,     0,     0,   138,   139,   140,
     141,   142,   143,   144,     0,   130,   131,   159,   132,   133,
       0,   134,   135,   136,   137,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,     0,   130,   131,   160,   132,
     133,     0,   134,   135,   136,   137,     0,     0,     0,   138,
     139,   140,   141,   142,   143,   144,     0,   130,   131,   163,
     132,   133,     0,   134,   135,   136,   137,     0,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   132,   133,     0,
     134,   135,   136,   137,   132,   133,     0,   138,   139,   140,
     141,   142,   143,   144,   138,   139,   140,   141,   142,   143,
     144
};

static const yytype_int16 yycheck[] =
{
      28,    22,    72,     6,   111,     6,    22,    79,    36,     9,
      13,     6,    58,    34,     7,   129,     6,    63,    34,    47,
      90,    91,    92,    16,    52,     0,    58,    97,    98,    99,
     102,    63,    57,    28,    29,    30,    31,    21,    66,   109,
      35,    36,     6,    46,     3,     4,     5,     6,   118,    57,
     157,     3,     4,     5,     6,    33,     6,    85,    59,    54,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   186,   143,    34,   145,   146,    54,    55,    56,
      39,    58,   196,    42,   198,   199,   200,    39,     6,    58,
      42,     3,     4,     5,     6,     3,     4,     5,     6,    57,
      59,    60,    40,    41,    61,    64,    63,    59,    60,    40,
      41,    55,    64,   116,    52,    53,    54,    55,    56,   189,
       3,     4,     5,    54,    55,    56,   154,    39,     6,     6,
      42,    39,    57,    15,    42,    54,    55,    56,     4,    60,
      60,    60,    63,    63,     6,    61,     8,    59,    61,    58,
      63,    59,    64,    57,     6,   183,     8,     6,    10,    11,
      12,   190,    56,   192,     6,    17,    59,    19,    10,    11,
      12,    23,    24,    25,    26,    17,     6,    19,    59,    59,
      56,    23,    24,    25,    26,    27,     6,    56,    61,    59,
      10,    11,    12,    18,    59,     6,    57,    17,     4,    19,
      59,    57,    60,    23,    24,    25,    26,    59,    59,     6,
      58,    57,    37,    38,    61,    40,    41,    59,    43,    44,
      45,    46,    18,    62,     7,    50,    51,    52,    53,    54,
      55,    56,    60,     6,    32,    13,    57,    14,    57,    59,
      57,    37,    38,    57,    40,    41,    20,    43,    44,    45,
      46,    54,    57,    57,    50,    51,    52,    53,    54,    55,
      56,    18,   112,    37,    38,    77,    40,    41,    78,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    37,    38,   125,    40,    41,    -1,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    37,    38,    -1,    40,    41,    62,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    37,    38,    -1,    40,    41,    62,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    37,    38,    60,    40,    41,    -1,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    37,    38,    60,    40,    41,
      -1,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    37,    38,    60,    40,
      41,    -1,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    37,    38,    60,
      40,    41,    -1,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    40,    41,    -1,
      43,    44,    45,    46,    40,    41,    -1,    50,    51,    52,
      53,    54,    55,    56,    50,    51,    52,    53,    54,    55,
      56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    66,     6,     0,    57,    21,    67,     6,    68,
      79,    33,    69,    57,    58,    63,     6,    70,    34,    72,
      79,     6,    28,    29,    30,    31,    35,    36,    54,    75,
       6,    58,    57,    78,    79,    73,    58,    55,     6,    76,
      75,     3,     4,     5,    71,     6,    57,    61,    15,    74,
      75,     4,    61,    57,    58,    79,    75,     6,     7,    16,
      80,    56,    75,     6,     8,    71,    61,    59,     6,    10,
      11,    12,    17,    19,    23,    24,    25,    26,    59,    81,
      82,    83,     6,    56,    56,    61,    75,    77,    78,    59,
      59,    59,    59,     3,     4,     5,     6,    39,    42,    59,
      85,     6,    81,     6,    83,     8,    82,    57,    54,    55,
      56,    58,    59,     4,    75,    60,    57,    60,    64,    84,
      85,    86,    85,    85,    85,    59,    85,    85,    85,    18,
      37,    38,    40,    41,    43,    44,    45,    46,    50,    51,
      52,    53,    54,    55,    56,    58,    27,    60,    57,    85,
       6,    84,    77,    62,    61,    85,    60,    63,    60,    60,
      60,    60,    86,    60,    80,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,     6,    85,
      85,    62,    60,    32,    75,    84,    13,    60,    62,    20,
      57,    75,    57,    80,    85,    22,    72,    22,    72,    14,
      18,    57,    80,    57,    80,    80,    80,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     3,     0,     5,     3,     3,     0,     5,
       3,     1,     1,     1,     3,     0,    12,    11,     0,    10,
       9,     0,     1,     1,     1,     1,     9,     2,     1,     4,
       5,     3,     1,     0,     5,     3,     3,     1,     3,     3,
       2,     4,     4,     3,     6,     8,     1,     1,     4,     4,
       8,     4,     3,     1,     4,     2,     3,     3,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     2,     3,     2,     4,     3,     1,
       1,     1,     3,     4,     1,     3,     1
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
        case 2:
#line 70 "yac.ypp" /* yacc.c:1646  */
    {(yyval.gl)=new Glavno(*(yyvsp[-8].nm),*(yyvsp[-4].lST),*(yyvsp[-3].vSP),*(yyvsp[-2].vSP),(yyvsp[-1].n)); 
												if(!((yyval.gl)->provera())){
													cout<<"greska"<<endl;
													exit(EXIT_FAILURE);}
												ime=*(yyvsp[-8].nm);
												if((yyval.gl)->codegen()==nullptr)
													yyerror("codegen nije uspeo");
												delete (yyvsp[-8].nm);
												argsRemover((yyvsp[-4].lST));
												functRemover((yyvsp[-3].vSP));
												functRemover((yyvsp[-2].vSP));
												delete (yyvsp[-1].n);
												delete (yyval.gl);
												mapsRemover(&tipovi);
											     }
#line 1497 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "yac.ypp" /* yacc.c:1646  */
    {argsRemover((yyvsp[-1].lST));}
#line 1503 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "yac.ypp" /* yacc.c:1646  */
    {}
#line 1509 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 89 "yac.ypp" /* yacc.c:1646  */
    {unsigned t=(*(yyvsp[-2].vS)).size();
						(yyval.lST)=(yyvsp[-4].lST);
						listmaker((yyval.lST),(yyvsp[-2].vS),(yyvsp[0].t));
						for(unsigned i=0;i<t;i++){
							if(tipovi.find((*(yyvsp[-2].vS))[i])==tipovi.end()){
								tipovi[(*(yyvsp[-2].vS))[i]]=(yyvsp[0].t)->kopija();
								if(tipovi[(*(yyvsp[-2].vS))[i]]->naziv()=="struct")
									tipovi[(*(yyvsp[-2].vS))[i]]->setime((*(yyvsp[-2].vS))[i]);
							}
							else{
								cout<<"vec je definisan taj tip"<<endl; exit(EXIT_FAILURE);
							}
						} 
						delete (yyvsp[-2].vS);
						delete (yyvsp[0].t);}
#line 1529 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=new vector<pair<string,tip*>>();
						listmaker((yyval.lST),(yyvsp[-2].vS),(yyvsp[0].t));
						unsigned t=(*(yyvsp[-2].vS)).size();
						for(unsigned i=0;i<t;i++){
							if(tipovi.find((*(yyvsp[-2].vS))[i])==tipovi.end()){
								tipovi[(*(yyvsp[-2].vS))[i]]=(yyvsp[0].t)->kopija();
								if(tipovi[(*(yyvsp[-2].vS))[i]]->naziv()=="struct")
									tipovi[(*(yyvsp[-2].vS))[i]]->setime((*(yyvsp[-2].vS))[i]);
							}
							else{
								cout<<"vec je definisan taj tip"<<endl; exit(EXIT_FAILURE);
							}
						} 
						delete (yyvsp[-2].vS);
						delete (yyvsp[0].t);}
#line 1549 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "yac.ypp" /* yacc.c:1646  */
    {unsigned t=(yyvsp[-1].vSI)->size();
							for(unsigned i=0;i<t;i++){
								if(konstante.find((*(yyvsp[-1].vSI))[i].first)==konstante.end())
									konstante[(*(yyvsp[-1].vSI))[i].first]=(*(yyvsp[-1].vSI))[i].second->kopija();
								else{
									yyerror("vec je definisana konstanta " +(*(yyvsp[-1].vSI))[i].first);}	
							}
							for(unsigned i=0;i<t;i++){
								delete (*(yyvsp[-1].vSI))[i].second;
							}
							delete (yyvsp[-1].vSI);
						}
#line 1566 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "yac.ypp" /* yacc.c:1646  */
    {}
#line 1572 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vSI)=(yyvsp[-4].vSI);
						pair<string,izraz*> tmp(*(yyvsp[-2].nm),(yyvsp[0].i));
						(yyval.vSI)->push_back(tmp);
						delete (yyvsp[-2].nm);}
#line 1581 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 140 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vSI)=new vector<pair<string,izraz*>>();
						pair<string,izraz*> tmp(*(yyvsp[-2].nm),(yyvsp[0].i));
						(yyval.vSI)->push_back(tmp);
						delete (yyvsp[-2].nm);}
#line 1590 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "yac.ypp" /* yacc.c:1646  */
    {if(((int)(yyvsp[0].f))!=(yyvsp[0].f)){ 
				(yyval.i)=new cons((yyvsp[0].f),new Float());}
	      		else
				(yyval.i)=new cons((yyvsp[0].f),new Int());  }
#line 1599 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "yac.ypp" /* yacc.c:1646  */
    {if((yyvsp[0].pr)->size()==1) 
				(yyval.i)=new cons((*(yyvsp[0].pr))[0],new Char());
			else
				(yyval.i)=new cons(*(yyvsp[0].pr),new String((yyvsp[0].pr)->size()));
			delete (yyvsp[0].pr);}
#line 1609 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 154 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new cons(*(yyvsp[0].b),new Bool());
			delete (yyvsp[0].b);}
#line 1616 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=(yyvsp[-1].lST);
				}
#line 1623 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 160 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=new vector<pair<string,tip*>>();}
#line 1629 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 163 "yac.ypp" /* yacc.c:1646  */
    {map<string,tip*> tmp;
											mapmaker(&tmp,(yyvsp[-2].lST));
											
											(yyval.vSP)=(yyvsp[-11].vSP);
											(yyval.vSP)->push_back(new funkcija(*(yyvsp[-9].nm),*(yyvsp[-7].lST),(yyvsp[-4].t),tmp,(yyvsp[-1].n)));
											delete (yyvsp[-9].nm);
											argsRemover((yyvsp[-7].lST));
											delete (yyvsp[-4].t);
											argsRemover((yyvsp[-2].lST));
											delete (yyvsp[-1].n);
											mapsRemover(&tmp);
											}
#line 1646 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 175 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vSP)=(yyvsp[-10].vSP);
											(yyval.vSP)->push_back(new funkcijaDekl(*(yyvsp[-8].nm),*(yyvsp[-6].lST),(yyvsp[-3].t)));
											delete (yyvsp[-8].nm);
											argsRemover((yyvsp[-6].lST));
											delete (yyvsp[-3].t);
											}
#line 1657 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vSP)=new vector<subprogram*>();}
#line 1663 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 185 "yac.ypp" /* yacc.c:1646  */
    {map<string,tip*> tmp;
											mapmaker(&tmp,(yyvsp[-2].lST));
											(yyval.vSP)=(yyvsp[-9].vSP);
											(yyval.vSP)->push_back(new procedur(*(yyvsp[-7].nm),*(yyvsp[-5].lST),tmp,(yyvsp[-1].n)));
											delete (yyvsp[-7].nm);
											argsRemover((yyvsp[-5].lST));
											argsRemover((yyvsp[-2].lST));
											delete (yyvsp[-1].n);
											mapsRemover(&tmp);
											}
#line 1678 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 195 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vSP)=(yyvsp[-8].vSP);
											(yyval.vSP)->push_back(new procedurDekl(*(yyvsp[-6].nm),*(yyvsp[-4].lST)));
											delete (yyvsp[-6].nm);
											argsRemover((yyvsp[-4].lST));
											}
#line 1688 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vSP)=new vector<subprogram*>();}
#line 1694 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 203 "yac.ypp" /* yacc.c:1646  */
    {(yyval.t)=new Int();}
#line 1700 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 204 "yac.ypp" /* yacc.c:1646  */
    {(yyval.t)=new Float();}
#line 1706 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 205 "yac.ypp" /* yacc.c:1646  */
    {(yyval.t)=new Char();}
#line 1712 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 206 "yac.ypp" /* yacc.c:1646  */
    {if(tipovi.find(*(yyvsp[0].nm))!=tipovi.end())
							(yyval.t)=tipovi[*(yyvsp[0].nm)]->kopija();
						 else{
							cout<<"ne postoji taj tip"<<endl;
							exit(EXIT_FAILURE);
							}
						delete (yyvsp[0].nm);}
#line 1724 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 213 "yac.ypp" /* yacc.c:1646  */
    {if(((yyvsp[-6].f)!=(int)(yyvsp[-6].f))||((yyvsp[-3].f)!=(int)(yyvsp[-3].f))||(yyvsp[-6].f)>(yyvsp[-3].f)){
									cout<<"lose definisan indeks niza"<<endl;
									exit(EXIT_FAILURE);}
								   (yyval.t)=new Array((yyvsp[0].t),(yyvsp[-6].f),(yyvsp[-3].f));
								   delete (yyvsp[0].t);}
#line 1734 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 219 "yac.ypp" /* yacc.c:1646  */
    {(yyval.t)=new Pointer((yyvsp[0].t));delete (yyvsp[0].t);}
#line 1740 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 220 "yac.ypp" /* yacc.c:1646  */
    {(yyval.t)=new Bool();}
#line 1746 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 221 "yac.ypp" /* yacc.c:1646  */
    {(yyval.t)=new Struct(imestr+to_string(inc),*(yyvsp[-2].lST));inc++;argsRemover((yyvsp[-2].lST));}
#line 1752 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 224 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=(yyvsp[-4].lST); (yyval.lST)->push_back(pair<string,tip*>(*(yyvsp[-2].nm),(yyvsp[0].t)->kopija())); delete (yyvsp[-2].nm); delete (yyvsp[0].t);}
#line 1758 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 226 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=new vector<pair<string,tip*>>();
					 (yyval.lST)->push_back(pair<string,tip*>(*(yyvsp[-2].nm),(yyvsp[0].t)->kopija()));
						delete (yyvsp[-2].nm);delete (yyvsp[0].t);}
#line 1766 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 231 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=(yyvsp[0].lST);}
#line 1772 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 232 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=new vector<pair<string,tip*>>();}
#line 1778 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 234 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=(yyvsp[-4].lST);
						listmaker((yyval.lST),(yyvsp[-2].vS),(yyvsp[0].t));
						delete (yyvsp[-2].vS);
						delete (yyvsp[0].t);}
#line 1787 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 238 "yac.ypp" /* yacc.c:1646  */
    {(yyval.lST)=new vector<pair<string,tip*>>();
						listmaker((yyval.lST),(yyvsp[-2].vS),(yyvsp[0].t));
						delete (yyvsp[-2].vS);
						delete (yyvsp[0].t);}
#line 1796 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 243 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vS)=(yyvsp[-2].vS); (yyval.vS)->push_back(*(yyvsp[0].nm)); delete (yyvsp[0].nm);}
#line 1802 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 244 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vS)=new vector<string>();
				     (yyval.vS)->push_back(*(yyvsp[0].nm));delete (yyvsp[0].nm);}
#line 1809 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 248 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new blok(*(yyvsp[-1].vN));
					unsigned t=(yyvsp[-1].vN)->size();
					for(unsigned i=0;i<t;i++)
						delete (*(yyvsp[-1].vN))[i];
					 delete (yyvsp[-1].vN);}
#line 1819 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 254 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vN)=(yyvsp[-2].vN); (yyval.vN)->push_back((yyvsp[-1].n));}
#line 1825 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vN)=new vector<naredba*>(); (yyval.vN)->push_back((yyvsp[-1].n));}
#line 1831 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 257 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new ispisE((yyvsp[-1].i));
							delete (yyvsp[-1].i);}
#line 1838 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 259 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new citajE((yyvsp[-1].i));
							delete (yyvsp[-1].i);}
#line 1845 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 261 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new dodelaE((yyvsp[-2].i),(yyvsp[0].i)); 
							delete (yyvsp[-2].i);
							delete (yyvsp[0].i);}
#line 1853 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 264 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new ifThen((yyvsp[-3].i),(yyvsp[0].n)); 
							delete (yyvsp[-3].i); 
							delete (yyvsp[0].n);}
#line 1861 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 267 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new ifThenElse((yyvsp[-5].i),(yyvsp[-2].n),(yyvsp[0].n)); 
							delete (yyvsp[-5].i); 
							delete (yyvsp[-2].n); 
							delete (yyvsp[0].n);}
#line 1870 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 271 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new Break();}
#line 1876 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 272 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new Continue();}
#line 1882 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 273 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new While((yyvsp[-2].i),(yyvsp[0].n)); 
							delete (yyvsp[-2].i); 
							delete (yyvsp[0].n);}
#line 1890 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 276 "yac.ypp" /* yacc.c:1646  */
    {naredba* tmp=new blok(*(yyvsp[-2].vN));
						       (yyval.n)=new repeatUntil((yyvsp[0].i),tmp); 				
							unsigned t=(yyvsp[-2].vN)->size();
							for(unsigned i=0;i<t;i++)
								delete (*(yyvsp[-2].vN))[i];
							delete (yyvsp[-2].vN);
							delete tmp; 
							delete (yyvsp[0].i);}
#line 1903 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 284 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new forTo(*(yyvsp[-6].nm),(yyvsp[-4].i),(yyvsp[-2].i),(yyvsp[0].n));
							delete (yyvsp[-6].nm); 
							delete (yyvsp[-4].i); 
							delete (yyvsp[-2].i); 
							delete (yyvsp[0].n);}
#line 1913 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 289 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new procedura(*(yyvsp[-3].nm),*(yyvsp[-1].vE));
							delete (yyvsp[-3].nm);
							unsigned t=(yyvsp[-1].vE)->size();
							for(unsigned i=0;i<t;i++)
								delete (*(yyvsp[-1].vE))[i];
							delete (yyvsp[-1].vE);}
#line 1924 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 295 "yac.ypp" /* yacc.c:1646  */
    {vector<izraz*>* tmp=new vector<izraz*>();
							(yyval.n)=new procedura(*(yyvsp[-2].nm),*tmp);
							delete (yyvsp[-2].nm);
							delete tmp;}
#line 1933 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 299 "yac.ypp" /* yacc.c:1646  */
    {(yyval.n)=new kraj();}
#line 1939 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 302 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new Niz((yyvsp[-3].i),(yyvsp[-1].i));
			delete (yyvsp[-3].i);
			delete (yyvsp[-1].i);}
#line 1947 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 305 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new pokazivac((yyvsp[-1].i));
			delete (yyvsp[-1].i);}
#line 1954 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 307 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=(yyvsp[-1].i);}
#line 1960 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 308 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new struktura((yyvsp[-2].i),*(yyvsp[0].nm));delete (yyvsp[-2].i); delete (yyvsp[0].nm);}
#line 1966 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 309 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new prom(*(yyvsp[0].nm),new Tmp());
			delete (yyvsp[0].nm);}
#line 1973 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 313 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new adresa((yyvsp[0].i)); delete (yyvsp[0].i);}
#line 1979 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 314 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=(yyvsp[0].i);}
#line 1985 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 318 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new zbir((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i); 
		}
#line 1994 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 322 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new razlika((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2003 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 326 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new proizvod((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2012 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 330 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new kolicnik((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2021 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 334 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new BitAnd((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2030 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 338 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new BitOr((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2039 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 342 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new BitNot((yyvsp[0].i));
		delete (yyvsp[0].i);
		}
#line 2047 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 345 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new grtr((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2056 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 349 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new lss((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2065 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 353 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new eq((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2074 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 357 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new neq((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2083 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 361 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new And((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2092 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 365 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new Orr((yyvsp[-2].i),(yyvsp[0].i));
		delete (yyvsp[-2].i);
		delete (yyvsp[0].i);
		}
#line 2101 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 369 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new Not((yyvsp[0].i));
		delete (yyvsp[0].i);
		}
#line 2109 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 372 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=(yyvsp[-1].i);}
#line 2115 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 373 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new pokazivac((yyvsp[-1].i));
		delete (yyvsp[-1].i);}
#line 2122 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 375 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new Niz((yyvsp[-3].i),(yyvsp[-1].i));
		delete (yyvsp[-3].i);
		delete (yyvsp[-1].i);}
#line 2130 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 378 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new struktura((yyvsp[-2].i),*(yyvsp[0].nm));
		  delete (yyvsp[-2].i);
		  delete (yyvsp[0].nm);}
#line 2138 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 381 "yac.ypp" /* yacc.c:1646  */
    {if(konstante.find(*(yyvsp[0].nm))==konstante.end())
			(yyval.i)=new prom(*(yyvsp[0].nm),new Tmp());
		else{
			tip* tmp=konstante[*(yyvsp[0].nm)]->provera();
			(yyval.i)=new cons(konstante[*(yyvsp[0].nm)],tmp->kopija());
			delete tmp;
		}
		delete (yyvsp[0].nm);}
#line 2151 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 389 "yac.ypp" /* yacc.c:1646  */
    {if(((int)(yyvsp[0].f))!=(yyvsp[0].f)){ 
		(yyval.i)=new cons((yyvsp[0].f),new Float());}
	      else{
		(yyval.i)=new cons((int)(yyvsp[0].f),new Int());}  }
#line 2160 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 393 "yac.ypp" /* yacc.c:1646  */
    {if((yyvsp[0].pr)->size()==1) 
			(yyval.i)=new cons((*(yyvsp[0].pr))[0],new Char());
		else
			(yyval.i)=new cons(*(yyvsp[0].pr),new String((yyvsp[0].pr)->size()));
		delete (yyvsp[0].pr);}
#line 2170 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 398 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new poziv(*(yyvsp[-2].nm),vector<izraz*>(),new Tmp());
			delete (yyvsp[-2].nm);}
#line 2177 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 400 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new poziv(*(yyvsp[-3].nm),*(yyvsp[-1].vE),new Tmp());
			delete (yyvsp[-3].nm); 
			unsigned t=(yyvsp[-1].vE)->size();
			for(unsigned i=0;i<t;i++)
				delete (*(yyvsp[-1].vE))[i]; 
			delete (yyvsp[-1].vE);
			}
#line 2189 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 407 "yac.ypp" /* yacc.c:1646  */
    {(yyval.i)=new cons(*(yyvsp[0].b),new Bool());delete (yyvsp[0].b);}
#line 2195 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 409 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vE)=(yyvsp[-2].vE);
		(yyval.vE)->push_back((yyvsp[0].i));}
#line 2202 "yac.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 411 "yac.ypp" /* yacc.c:1646  */
    {(yyval.vE)=new vector<izraz*>();
	(yyval.vE)->push_back((yyvsp[0].i));}
#line 2209 "yac.tab.cpp" /* yacc.c:1646  */
    break;


#line 2213 "yac.tab.cpp" /* yacc.c:1646  */
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
#line 414 "yac.ypp" /* yacc.c:1906  */


int main(){
yydebug=0; 
TheModule= new Module(ime,TheContext);

TheFPM=new legacy::FunctionPassManager(TheModule);
TheFPM->add(createInstructionCombiningPass());
TheFPM->add(createReassociatePass());
TheFPM->add(createNewGVNPass());
TheFPM->add(createCFGSimplificationPass());
TheFPM->doInitialization();
yyparse();
TheModule->print(outs(),nullptr);


delete TheModule;
delete TheFPM;
return 0;
}
