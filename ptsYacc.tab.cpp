/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEFINE = 258,
     PENTESTGOAL = 259,
     PENTESTTIME = 260,
     PENTESTTARGET = 261,
     LEFT_BIG_BRACKET = 262,
     RIGHT_BIG_BRACKET = 263,
     LEFT_SMALL_BRACKET = 264,
     RIGHT_SMALL_BRACKET = 265,
     COMM = 266,
     PATH = 267,
     DOMAIN = 268,
     ASSIGN = 269,
     GOALPRIVILEGE = 270,
     EXPECTEPRIVILEGE = 271,
     LARGER = 272,
     LESS = 273,
     EQUAL = 274,
     NOTEQUAL = 275,
     LARGEREQUAL = 276,
     LESSEQUAL = 277,
     AND = 278,
     OR = 279,
     NOT = 280,
     OWN = 281,
     CONNECT = 282,
     SERVICE = 283,
     TRUST = 284,
     FTP = 285,
     TELNET = 286,
     WEB = 287,
     GAINPRIVILEGE = 288,
     GUEST = 289,
     USER = 290,
     ADMINISTRATOR = 291,
     ROOT = 292,
     GOAL = 293,
     TIME = 294,
     EXPECTATION = 295,
     STRING = 296,
     TIMECONSTANT = 297,
     NOW = 298,
     NUMBER = 299,
     IPADDR = 300,
     CVENUMBER = 301,
     MASK = 302,
     IF = 303,
     THEN = 304,
     ENDIF = 305,
     USE = 306,
     EXPLOIT = 307,
     FOR = 308,
     PENETRATE = 309,
     EXPECT = 310,
     OUT = 311,
     OVERFLOW = 312,
     RACECONDITON = 313,
     PASSWORDCRACK = 314,
     LOGIN = 315
   };
#endif
/* Tokens.  */
#define DEFINE 258
#define PENTESTGOAL 259
#define PENTESTTIME 260
#define PENTESTTARGET 261
#define LEFT_BIG_BRACKET 262
#define RIGHT_BIG_BRACKET 263
#define LEFT_SMALL_BRACKET 264
#define RIGHT_SMALL_BRACKET 265
#define COMM 266
#define PATH 267
#define DOMAIN 268
#define ASSIGN 269
#define GOALPRIVILEGE 270
#define EXPECTEPRIVILEGE 271
#define LARGER 272
#define LESS 273
#define EQUAL 274
#define NOTEQUAL 275
#define LARGEREQUAL 276
#define LESSEQUAL 277
#define AND 278
#define OR 279
#define NOT 280
#define OWN 281
#define CONNECT 282
#define SERVICE 283
#define TRUST 284
#define FTP 285
#define TELNET 286
#define WEB 287
#define GAINPRIVILEGE 288
#define GUEST 289
#define USER 290
#define ADMINISTRATOR 291
#define ROOT 292
#define GOAL 293
#define TIME 294
#define EXPECTATION 295
#define STRING 296
#define TIMECONSTANT 297
#define NOW 298
#define NUMBER 299
#define IPADDR 300
#define CVENUMBER 301
#define MASK 302
#define IF 303
#define THEN 304
#define ENDIF 305
#define USE 306
#define EXPLOIT 307
#define FOR 308
#define PENETRATE 309
#define EXPECT 310
#define OUT 311
#define OVERFLOW 312
#define RACECONDITON 313
#define PASSWORDCRACK 314
#define LOGIN 315




/* Copy the first part of user declarations.  */
#line 1 "pentestparser.y"

#include "global.h"
using namespace std;

extern Scheme* scheme;

extern int lineNo;
extern int yylex();									//调用lex
extern char bufError[100];								//存储错误信息
void yyerror(char *s);								//error处理

PentestCase* pentestcase;							//渗透测试用例
PentestPath* pentestpath;							//渗透测试路径
Variable* vari;										//变量
std::vector<Variable*>	vecVariable;				//存储变量,未赋值
Variable variother;
std::vector<Variable> vecVariableother;
std::vector<Variable*>::iterator	itorVariable;	//用于Variable类型的vev浮标
std::vector<string> pathName;						//路径名
int variableType;					//变量的类型
int expType;						//比较字符串的类型
Goal finalGoal;						//方案的最终目标
Goal* caseGoal;						//测试用例的目标
Exceptation* caseExceptation;		//测试用例的期望
std::string strTime;				//时间string
std::string strIp;					//IP string
std::string strMethod;				//渗透测试手段
std::string strCveNumber;			//利用的漏洞号
std::string strGoalName;			//goal的名字
std::string strExcepteName;			//期望的名字
std::string temp;					//临时string
std::string strPathName;			//渗透测试路径的名字


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 36 "pentestparser.y"
typedef union YYSTYPE {
  char	*sval;
  int	ival;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 244 "ptsYacc.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 256 "ptsYacc.tab.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  49
/* YYNRULES -- Number of rules. */
#define YYNRULES  84
/* YYNRULES -- Number of states. */
#define YYNSTATES  189

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     7,    11,    19,    21,    23,    25,    27,
      33,    40,    42,    44,    46,    48,    54,    56,    60,    62,
      64,    66,    68,    71,    73,    77,    79,    81,    83,    86,
      89,    91,    93,    95,    97,   101,   103,   105,   107,   114,
     121,   123,   126,   132,   134,   136,   139,   142,   150,   152,
     156,   160,   163,   167,   169,   171,   173,   175,   177,   179,
     181,   200,   202,   206,   210,   213,   215,   217,   224,   226,
     228,   230,   239,   250,   257,   259,   261,   263,   265,   267,
     269,   271,   273,   275,   277
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      62,     0,    -1,    63,    80,    87,    -1,    64,    68,    71,
      -1,     3,     5,     7,    65,    11,    65,     8,    -1,    66,
      -1,    67,    -1,    43,    -1,    42,    -1,     3,     4,     7,
      69,     8,    -1,    33,     9,    72,    11,    70,    10,    -1,
      35,    -1,    34,    -1,    37,    -1,    36,    -1,     3,     6,
       7,    72,     8,    -1,    73,    -1,    72,    11,    73,    -1,
      74,    -1,    79,    -1,    75,    -1,    77,    -1,    13,    76,
      -1,    41,    -1,    45,    47,    78,    -1,    44,    -1,    45,
      -1,    81,    -1,    80,    81,    -1,    82,    41,    -1,    83,
      -1,    39,    -1,    38,    -1,    40,    -1,    41,    14,    84,
      -1,    65,    -1,    85,    -1,    86,    -1,    15,     9,    72,
      11,    70,    10,    -1,    16,     9,    72,    11,    70,    10,
      -1,    88,    -1,    87,    88,    -1,    12,    89,     7,    90,
       8,    -1,    41,    -1,    91,    -1,    90,    91,    -1,    83,
      92,    -1,    48,     9,    93,    10,    49,    97,    50,    -1,
      94,    -1,    93,    23,    94,    -1,    93,    24,    94,    -1,
      25,    93,    -1,    95,    96,    95,    -1,    41,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    48,     9,    98,    10,    49,    51,   106,    52,    41,
      53,   107,    54,    72,    55,   108,    56,   109,    50,    -1,
      94,    -1,    93,    23,    94,    -1,    93,    24,    94,    -1,
      25,    93,    -1,    99,    -1,   100,    -1,    26,     9,    72,
      11,    70,    10,    -1,   101,    -1,   102,    -1,   103,    -1,
      27,     9,    72,    11,    72,    11,   105,    10,    -1,    28,
       9,    72,    11,    72,    11,   104,    11,   105,    10,    -1,
      29,     9,    72,    11,    72,    10,    -1,    30,    -1,    31,
      -1,    32,    -1,    44,    -1,    57,    -1,    58,    -1,    59,
      -1,    60,    -1,    41,    -1,    41,    -1,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   119,   119,   121,   123,   129,   129,   130,   131,   136,
     138,   148,   149,   150,   151,   153,   154,   154,   155,   155,
     156,   156,   157,   159,   164,   173,   177,   181,   182,   184,
     191,   192,   193,   194,   196,   224,   228,   232,   242,   267,
     291,   291,   293,   297,   302,   303,   305,   306,   314,   315,
     316,   317,   318,   320,   323,   327,   328,   329,   330,   331,
     335,   360,   361,   362,   363,   365,   366,   367,   368,   369,
     370,   371,   373,   375,   377,   378,   379,   380,   385,   389,
     393,   397,   412,   417,   422
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"define\"", "\"penetestgoal\"",
  "\"pentesttime\"", "\"pentesttarget\"", "\"{\"", "\"}\"", "\"(\"",
  "\")\"", "\",\"", "\"path\"", "DOMAIN", "\"=\"", "GOALPRIVILEGE",
  "EXPECTEPRIVILEGE", "\">\"", "\"<\"", "\"==\"", "\"!=\"", "\">=\"",
  "\"<=\"", "\"&&\"", "\"||\"", "\"!\"", "\"own\"", "\"connect\"",
  "\"service\"", "\"trust\"", "\"ftp\"", "\"telnet\"", "\"web\"",
  "GAINPRIVILEGE", "\"guest\"", "\"user\"", "\"administrator\"",
  "\"root\"", "\"goal\"", "\"time\"", "\"expectation\"", "STRING",
  "TIMECONSTANT", "NOW", "NUMBER", "IPADDR", "CVENUMBER", "MASK", "\"if\"",
  "\"then\"", "\"endif\"", "\"use\"", "\"exploit\"", "\"for\"",
  "\"penetrate\"", "\"expect\"", "\"out\"", "\"overflow\"",
  "\"raceconditon\"", "\"passwordcrack\"", "\"login\"", "$accept", "ptsdl",
  "scheme_declaration", "time_declaration", "time_value", "function",
  "time", "goal_declaration", "final_goal", "privilege_variable",
  "target_declaration", "target_variable", "target_variable_statement",
  "network", "domain", "domain_name", "subnet", "mask_constant",
  "computer", "global_variable_definition", "global_variable_statement",
  "var_type", "assign_sentences", "variable_value", "goal_value",
  "expectation_value", "scheme_description", "path_block", "path_name",
  "pentest_scheme_statement", "pentest_case_statement", "constraints",
  "condition", "condition_sentence", "expression", "exp_mark",
  "pentest_case", "precondition", "privilegecondition",
  "relationcondition", "connectcondition", "servicecondition",
  "trustcondition", "service_variable", "port", "method_variable",
  "goal_variable", "expectation_variable", "status_variable", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    61,    62,    63,    64,    65,    65,    66,    67,    68,
      69,    70,    70,    70,    70,    71,    72,    72,    73,    73,
      74,    74,    75,    76,    77,    78,    79,    80,    80,    81,
      81,    82,    82,    82,    83,    84,    84,    84,    85,    86,
      87,    87,    88,    89,    90,    90,    91,    92,    93,    93,
      93,    93,    94,    95,    96,    96,    96,    96,    96,    96,
      97,    98,    98,    98,    98,    94,    94,    99,   100,   100,
     100,   101,   102,   103,   104,   104,   104,   105,   106,   106,
     106,   106,   107,   108,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     3,     3,     7,     1,     1,     1,     1,     5,
       6,     1,     1,     1,     1,     5,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     6,     6,
       1,     2,     5,     1,     1,     2,     2,     7,     1,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
      18,     1,     3,     3,     2,     1,     1,     6,     1,     1,
       1,     8,    10,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,    32,    31,    33,
       0,     0,    27,     0,    30,     0,     0,     0,     0,     0,
      28,     2,    40,    29,     0,     0,     3,     8,     7,     0,
       5,     6,     0,     0,    35,    34,    36,    37,    43,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    16,    18,    20,    21,    19,     0,
       0,     0,    44,     0,     9,     0,     4,    23,    22,     0,
       0,     0,     0,    46,    42,    45,     0,    15,     0,    25,
      24,    12,    11,    14,    13,     0,    17,     0,     0,     0,
      38,    39,     0,     0,     0,     0,     0,    53,     0,    48,
       0,    65,    66,    68,    69,    70,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,     0,    10,     0,     0,     0,     0,     0,    49,    50,
      52,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     0,    47,    67,     0,     0,    73,     0,     0,
      48,     0,    77,     0,    74,    75,    76,     0,    64,     0,
       0,     0,    71,     0,    49,    50,     0,     0,     0,    72,
      78,    79,    80,    81,     0,     0,     0,     0,    82,     0,
       0,     0,     0,    83,     0,     0,    84,     0,    60
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,     4,    29,    30,    31,    16,    48,    85,
      26,    53,    54,    55,    56,    68,    57,    80,    58,    11,
      12,    13,    14,    35,    36,    37,    21,    22,    39,    61,
      62,    73,    98,    99,   100,   121,   136,   151,   101,   102,
     103,   104,   105,   157,   153,   174,   179,   184,   187
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -106
static const short int yypact[] =
{
       7,    15,    22,    67,    24,    50,  -106,  -106,  -106,  -106,
      46,    34,  -106,    21,  -106,   112,   114,   -27,     8,    30,
    -106,   106,  -106,  -106,   113,   115,  -106,  -106,  -106,   108,
    -106,  -106,   116,   117,  -106,  -106,  -106,  -106,  -106,   120,
    -106,    89,   121,   -27,     0,     0,    83,   122,   124,     0,
     125,    88,    76,   119,  -106,  -106,  -106,  -106,  -106,   123,
      90,    -3,  -106,     0,  -106,    48,  -106,  -106,  -106,    92,
      -2,    -2,   128,  -106,  -106,  -106,   129,  -106,     0,  -106,
    -106,  -106,  -106,  -106,  -106,   131,  -106,   132,    51,    -2,
    -106,  -106,    51,   130,   134,   135,   136,  -106,    16,  -106,
      82,  -106,  -106,  -106,  -106,  -106,   137,    18,     0,     0,
       0,     0,    97,    57,    57,  -106,  -106,  -106,  -106,  -106,
    -106,   107,  -106,   138,   139,   140,   141,   105,  -106,  -106,
    -106,    -2,     0,     0,     0,   145,   109,   146,   144,  -106,
     147,    80,    68,  -106,  -106,     4,    -1,  -106,    51,    91,
     150,   151,  -106,   152,  -106,  -106,  -106,   153,    18,    57,
      57,   118,  -106,   126,   155,   156,   127,   158,    53,  -106,
    -106,  -106,  -106,  -106,   111,   133,   104,   142,  -106,   143,
       0,    -8,   148,  -106,   149,   154,  -106,   157,  -106
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -106,  -106,  -106,  -106,    10,  -106,  -106,  -106,  -106,   -70,
    -106,   -45,   -64,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
     160,  -106,   -25,  -106,  -106,  -106,  -106,   159,  -106,  -106,
     161,  -106,   -90,  -105,    52,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,     6,  -106,  -106,  -106,  -106
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -64
static const short int yytable[] =
{
      59,    87,   107,    78,    65,    74,    86,    86,   128,   129,
       1,    51,    51,    51,    86,    27,    28,    51,    76,   106,
       5,    60,     6,    32,    33,    86,   112,    15,    34,   154,
     155,   156,    81,    82,    83,    84,    60,   150,    10,   113,
     114,   113,   114,    52,    52,    52,    19,   182,   152,    52,
      27,    28,   149,    50,   164,   165,    77,    17,   158,    78,
      18,   137,    23,   123,   124,   125,   126,    86,   139,   139,
     139,    38,     7,     8,     9,    10,    92,    93,    94,    95,
      96,    86,    86,    93,    94,    95,    96,   138,   140,   141,
     147,    78,    97,   148,    93,    94,    95,    96,    97,   115,
     116,   117,   118,   119,   120,     7,     8,     9,    10,    97,
     170,   171,   172,   173,   159,   160,    24,    25,    19,    43,
      41,    42,    47,    69,    10,    44,    45,    46,    49,    67,
      70,    63,    64,    66,    71,   181,    79,    88,    72,   108,
      89,    90,    91,   109,   110,   111,   127,   122,    97,   131,
     132,   133,   134,   135,   142,   145,   144,   177,   146,   143,
     -61,   161,   162,   175,   163,   -62,   -63,   166,   169,   167,
     152,    20,     0,   130,   176,     0,     0,     0,   168,     0,
      40,     0,     0,   178,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,   186,     0,   180,     0,     0,
       0,     0,     0,     0,     0,   185,     0,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75
};

static const short int yycheck[] =
{
      45,    71,    92,    11,    49,     8,    70,    71,   113,   114,
       3,    13,    13,    13,    78,    42,    43,    13,    63,    89,
       5,    46,     0,    15,    16,    89,    10,     3,    18,    30,
      31,    32,    34,    35,    36,    37,    61,   142,    41,    23,
      24,    23,    24,    45,    45,    45,    12,    55,    44,    45,
      42,    43,   142,    43,   159,   160,     8,     7,   148,    11,
      14,   131,    41,   108,   109,   110,   111,   131,   132,   133,
     134,    41,    38,    39,    40,    41,    25,    26,    27,    28,
      29,   145,   146,    26,    27,    28,    29,   132,   133,   134,
      10,    11,    41,    25,    26,    27,    28,    29,    41,    17,
      18,    19,    20,    21,    22,    38,    39,    40,    41,    41,
      57,    58,    59,    60,    23,    24,     4,     3,    12,    11,
       7,     6,    33,    47,    41,     9,     9,     7,     7,    41,
      11,     9,     8,     8,    11,   180,    44,     9,    48,     9,
      11,    10,    10,     9,     9,     9,    49,    10,    41,    11,
      11,    11,    11,    48,     9,    11,    10,    53,    11,    50,
      10,    10,    10,    52,    11,    10,    10,    49,    10,   163,
      44,    11,    -1,   121,    41,    -1,    -1,    -1,    51,    -1,
      21,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    62,    63,    64,     5,     0,    38,    39,    40,
      41,    80,    81,    82,    83,     3,    68,     7,    14,    12,
      81,    87,    88,    41,     4,     3,    71,    42,    43,    65,
      66,    67,    15,    16,    65,    84,    85,    86,    41,    89,
      88,     7,     6,    11,     9,     9,     7,    33,    69,     7,
      65,    13,    45,    72,    73,    74,    75,    77,    79,    72,
      83,    90,    91,     9,     8,    72,     8,    41,    76,    47,
      11,    11,    48,    92,     8,    91,    72,     8,    11,    44,
      78,    34,    35,    36,    37,    70,    73,    70,     9,    11,
      10,    10,    25,    26,    27,    28,    29,    41,    93,    94,
      95,    99,   100,   101,   102,   103,    70,    93,     9,     9,
       9,     9,    10,    23,    24,    17,    18,    19,    20,    21,
      22,    96,    10,    72,    72,    72,    72,    49,    94,    94,
      95,    11,    11,    11,    11,    48,    97,    70,    72,    73,
      72,    72,     9,    50,    10,    11,    11,    10,    25,    93,
      94,    98,    44,   105,    30,    31,    32,   104,    93,    23,
      24,    10,    10,    11,    94,    94,    49,   105,    51,    10,
      57,    58,    59,    60,   106,    52,    41,    53,    41,   107,
      54,    72,    55,    41,   108,    56,    41,   109,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#ifndef	YYINITDEPTH
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 124 "pentestparser.y"
    {
	scheme->SetBeginTime(string((yyvsp[-3].sval)));
	scheme->SetEndTime(strTime);			//设置方案的时间
;}
    break;

  case 8:
#line 132 "pentestparser.y"
    {
	strTime = string((yyvsp[0].sval));
;}
    break;

  case 10:
#line 139 "pentestparser.y"
    {
	finalGoal.strHost = string((yyvsp[-3].sval));
	temp = string((yyvsp[-1].sval));
	finalGoal.accType = temp;
	scheme->SetSchemeGoal(finalGoal);		//设置方案的最终目标

;}
    break;

  case 11:
#line 148 "pentestparser.y"
    {(yyval.sval)="user";;}
    break;

  case 12:
#line 149 "pentestparser.y"
    {(yyval.sval)="guest";;}
    break;

  case 13:
#line 150 "pentestparser.y"
    {(yyval.sval)="root";;}
    break;

  case 14:
#line 151 "pentestparser.y"
    {(yyval.sval)="administrator";;}
    break;

  case 23:
#line 160 "pentestparser.y"
    {
	temp=(yyvsp[0].sval);
	scheme->SetTarget(temp);			//设置方案的对象
;}
    break;

  case 24:
#line 165 "pentestparser.y"
    {
	temp = string((yyvsp[-2].sval));
	temp += " ";
	char str[10];
	temp += string(itoa((yyvsp[0].ival), str, 10));
	scheme->SetTarget(temp);			//设置方案的对象
;}
    break;

  case 25:
#line 174 "pentestparser.y"
    {
	(yyval.ival) = (yyvsp[0].ival);
;}
    break;

  case 26:
#line 178 "pentestparser.y"
    {
	strIp = (yyvsp[0].sval);
;}
    break;

  case 29:
#line 185 "pentestparser.y"
    {	
	vari = new Variable();
	vari->iType = (yyvsp[-1].ival);
	vari->name = string((yyvsp[0].sval));
	vecVariable.push_back(vari);
;}
    break;

  case 31:
#line 192 "pentestparser.y"
    {(yyval.ival)=0;;}
    break;

  case 32:
#line 193 "pentestparser.y"
    {(yyval.ival)=1;;}
    break;

  case 33:
#line 194 "pentestparser.y"
    {(yyval.ival) =2;;}
    break;

  case 34:
#line 197 "pentestparser.y"
    {
	int i = 0;
	for (itorVariable = vecVariable.begin(); itorVariable != vecVariable.end(); ++itorVariable)
	{
		if ((*itorVariable)->name == string((yyvsp[-2].sval)))
		{
			if (variableType ==0)
			{
				vecVariable[i]->value.time = &strTime;
			}
			else if (variableType == 1)
			{
				vecVariable[i]->value.goal = caseGoal;
			}
			else
			{
				vecVariable[i]->value.exceptation = caseExceptation;
			}
			
		}
		else 
		{
			//cout << "error" << endl;
		}
		++i;
	}
;}
    break;

  case 35:
#line 225 "pentestparser.y"
    {
			variableType = 0;
		;}
    break;

  case 36:
#line 229 "pentestparser.y"
    {
			variableType = 1;
		;}
    break;

  case 37:
#line 233 "pentestparser.y"
    {
			variableType = 2;
		;}
    break;

  case 38:
#line 243 "pentestparser.y"
    {
	caseGoal = new Goal();
	caseGoal->strHost = strIp;
	temp = string((yyvsp[-1].sval));
	caseGoal->accType = temp;
	/*
	if (strcmp(temp, "guest") == 0)
	{
		finalGoal.acc = USER;
	}
	else if (strcmp(temp, "user") == 0)
	{
		finalGoal.acc = USER;
	}
	else if (strcmp(temp, "guest") == 0)
	{
		finalGoal.acc = ROOT;
	}
	else
	{
		finalGoal.acc = ADMINSTRATOR;
	}*/
;}
    break;

  case 39:
#line 268 "pentestparser.y"
    {
	caseExceptation = new Exceptation();
	caseExceptation->strHost = strIp;
	temp = string((yyvsp[-1].sval));
	caseExceptation->accType = temp;
	/*if (strcmp(temp, "guest") == 0)
	{
		finalGoal.acc = USER;
	}
	else if (strcmp(temp, "user") == 0)
	{
		finalGoal.acc = USER;
	}
	else if (strcmp(temp, "guest") == 0)
	{
		finalGoal.acc = ROOT;
	}
	else
	{
		finalGoal.acc = ADMINSTRATOR;
	}*/
;}
    break;

  case 42:
#line 294 "pentestparser.y"
    {
;}
    break;

  case 43:
#line 298 "pentestparser.y"
    {
	strPathName = (yyvsp[0].sval);
;}
    break;

  case 47:
#line 307 "pentestparser.y"
    {
	pentestpath = new PentestPath();
	pentestpath->pathName = strPathName;
	scheme->InsertPath(*pentestpath);
	scheme->InsertCase(strPathName, *pentestcase);
;}
    break;

  case 54:
#line 324 "pentestparser.y"
    {
	expType = 1;
	;}
    break;

  case 55:
#line 327 "pentestparser.y"
    {expType = 2;;}
    break;

  case 56:
#line 328 "pentestparser.y"
    {expType = 3;;}
    break;

  case 57:
#line 329 "pentestparser.y"
    {expType = 4;;}
    break;

  case 58:
#line 330 "pentestparser.y"
    {expType = 5;;}
    break;

  case 59:
#line 332 "pentestparser.y"
    {
	expType = 6;
	;}
    break;

  case 60:
#line 341 "pentestparser.y"
    {
		pentestcase = new PentestCase();
		pentestcase->method = strMethod;
		pentestcase->cvenumber = string((yyvsp[-9].sval));
		for (itorVariable = vecVariable.begin(); itorVariable != vecVariable.end(); ++itorVariable)
		{
			if ((*itorVariable)->name == strGoalName)
			{
				pentestcase->goal = *((*itorVariable)->value.goal);
			}
			else if ((*itorVariable)->name == strExcepteName)
			{
				pentestcase->exp = *((*itorVariable)->value.exceptation);
			}

		}

	     ;}
    break;

  case 74:
#line 377 "pentestparser.y"
    {temp = "ftp";;}
    break;

  case 75:
#line 378 "pentestparser.y"
    {temp = "telnet";;}
    break;

  case 76:
#line 379 "pentestparser.y"
    {temp = "web";;}
    break;

  case 77:
#line 381 "pentestparser.y"
    {
	(yyval.ival) = (yyvsp[0].ival);
;}
    break;

  case 78:
#line 386 "pentestparser.y"
    {
				strMethod = "overflow";
			;}
    break;

  case 79:
#line 390 "pentestparser.y"
    {
				strMethod = "raceconditon";	
			;}
    break;

  case 80:
#line 394 "pentestparser.y"
    {
				strMethod = "passwordcrack";
			;}
    break;

  case 81:
#line 398 "pentestparser.y"
    {
				strMethod = "login"
			;}
    break;

  case 82:
#line 413 "pentestparser.y"
    {
	strGoalName = string((yyvsp[0].sval));
;}
    break;

  case 83:
#line 418 "pentestparser.y"
    {
	strExcepteName = string((yyvsp[0].sval));	
;}
    break;

  case 84:
#line 423 "pentestparser.y"
    {
	(yyval.sval) = (yyvsp[0].sval);
;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1788 "ptsYacc.tab.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 426 "pentestparser.y"


void yyerror(char *s)
{
   //printf("line%d:%s\n",lineNo,s);
   sprintf(bufError,"line %d:\n%s", lineNo, s);
}
