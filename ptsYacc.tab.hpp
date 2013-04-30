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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 36 "pentestparser.y"
typedef union YYSTYPE {
  char	*sval;
  int	ival;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 163 "ptsYacc.tab.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



