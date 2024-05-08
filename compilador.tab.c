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
#line 6 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

#include "pilha.h"
#include "tabela_simbolos.h"
#include "desvios.h"

int num_vars;
int num_vars_bloco;

int nivel_lex = 0;
int rotulo_print = 0;
int desloc;

entrada_tabela_simbolos *ident_comando;

pilha_t *tab_simbolos;
pilha_t *pilha_rotulos;
pilha_t *operacoes_pilha;
pilha_t *expressoes_pilha;
pilha_t *termos_pilha;
pilha_t *fatores_pilha;
pilha_t *num_vars_pilha;
pilha_t *ident_comando_pilha;

char comando[50];
char mensagem_erro[50];
char ident[TAM_TOKEN];


#line 106 "compilador.tab.c"

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

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_ABRE_PARENTESES = 4,            /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 5,           /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 6,                    /* VIRGULA  */
  YYSYMBOL_PONTO_E_VIRGULA = 7,            /* PONTO_E_VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 8,                /* DOIS_PONTOS  */
  YYSYMBOL_PONTO = 9,                      /* PONTO  */
  YYSYMBOL_T_BEGIN = 10,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 11,                     /* T_END  */
  YYSYMBOL_VAR = 12,                       /* VAR  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_ATRIBUICAO = 14,                /* ATRIBUICAO  */
  YYSYMBOL_LABEL = 15,                     /* LABEL  */
  YYSYMBOL_TYPE = 16,                      /* TYPE  */
  YYSYMBOL_ARRAY = 17,                     /* ARRAY  */
  YYSYMBOL_OF = 18,                        /* OF  */
  YYSYMBOL_PROCEDURE = 19,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 20,                  /* FUNCTION  */
  YYSYMBOL_GOTO = 21,                      /* GOTO  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_DO = 25,                        /* DO  */
  YYSYMBOL_IGUAL = 26,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 27,                 /* DIFERENTE  */
  YYSYMBOL_MENOR = 28,                     /* MENOR  */
  YYSYMBOL_MENOR_OU_IGUAL = 29,            /* MENOR_OU_IGUAL  */
  YYSYMBOL_MAIOR = 30,                     /* MAIOR  */
  YYSYMBOL_MAIOR_OU_IGUAL = 31,            /* MAIOR_OU_IGUAL  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_THEN = 34,                      /* THEN  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_SOMA = 36,                      /* SOMA  */
  YYSYMBOL_SUBTRAI = 37,                   /* SUBTRAI  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_MUL = 39,                       /* MUL  */
  YYSYMBOL_MOD = 40,                       /* MOD  */
  YYSYMBOL_INTEGER = 41,                   /* INTEGER  */
  YYSYMBOL_LONGINT = 42,                   /* LONGINT  */
  YYSYMBOL_REAL = 43,                      /* REAL  */
  YYSYMBOL_CHAR = 44,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 45,                   /* BOOLEAN  */
  YYSYMBOL_NUMERO = 46,                    /* NUMERO  */
  YYSYMBOL_READ = 47,                      /* READ  */
  YYSYMBOL_WRITE = 48,                     /* WRITE  */
  YYSYMBOL_LOWER_THAN_ELSE = 49,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_programa = 51,                  /* programa  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_bloco = 53,                     /* bloco  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_parte_declara_vars = 55,        /* parte_declara_vars  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_declara_vars = 57,              /* declara_vars  */
  YYSYMBOL_declara_var = 58,               /* declara_var  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_60_5 = 60,                      /* $@5  */
  YYSYMBOL_tipo = 61,                      /* tipo  */
  YYSYMBOL_lista_id_var = 62,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 63,              /* lista_idents  */
  YYSYMBOL_lista_aux = 64,                 /* lista_aux  */
  YYSYMBOL_expressao = 65,                 /* expressao  */
  YYSYMBOL_expressao_simples = 66,         /* expressao_simples  */
  YYSYMBOL_sinal_ou_or = 67,               /* sinal_ou_or  */
  YYSYMBOL_sinal = 68,                     /* sinal  */
  YYSYMBOL_termo = 69,                     /* termo  */
  YYSYMBOL_operacao_termo = 70,            /* operacao_termo  */
  YYSYMBOL_fator = 71,                     /* fator  */
  YYSYMBOL_72_6 = 72,                      /* $@6  */
  YYSYMBOL_var_ou_func = 73,               /* var_ou_func  */
  YYSYMBOL_variavel = 74,                  /* variavel  */
  YYSYMBOL_chamada_de_funcao = 75,         /* chamada_de_funcao  */
  YYSYMBOL_relacao = 76,                   /* relacao  */
  YYSYMBOL_comando_composto = 77,          /* comando_composto  */
  YYSYMBOL_comandos = 78,                  /* comandos  */
  YYSYMBOL_comando = 79,                   /* comando  */
  YYSYMBOL_comando_sem_rotulo = 80,        /* comando_sem_rotulo  */
  YYSYMBOL_81_7 = 81,                      /* $@7  */
  YYSYMBOL_trata_ident = 82,               /* trata_ident  */
  YYSYMBOL_atribuicao = 83,                /* atribuicao  */
  YYSYMBOL_84_8 = 84,                      /* $@8  */
  YYSYMBOL_chama_proc = 85,                /* chama_proc  */
  YYSYMBOL_comando_repetitivo = 86,        /* comando_repetitivo  */
  YYSYMBOL_87_9 = 87,                      /* $@9  */
  YYSYMBOL_88_10 = 88,                     /* $@10  */
  YYSYMBOL_comando_condicional = 89,       /* comando_condicional  */
  YYSYMBOL_90_11 = 90,                     /* $@11  */
  YYSYMBOL_bloco_if = 91,                  /* bloco_if  */
  YYSYMBOL_92_12 = 92,                     /* $@12  */
  YYSYMBOL_bloco_else = 93,                /* bloco_else  */
  YYSYMBOL_94_13 = 94,                     /* $@13  */
  YYSYMBOL_comando_read = 95,              /* comando_read  */
  YYSYMBOL_read_params = 96,               /* read_params  */
  YYSYMBOL_comando_write = 97,             /* comando_write  */
  YYSYMBOL_write_params = 98               /* write_params  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    60,    73,    73,   112,   113,   113,   118,
     119,   122,   125,   122,   133,   136,   141,   148,   157,   158,
     161,   162,   171,   172,   191,   206,   218,   226,   227,   234,
     239,   247,   252,   268,   273,   278,   287,   286,   314,   322,
     327,   330,   331,   335,   345,   349,   354,   359,   364,   369,
     374,   382,   385,   386,   387,   390,   391,   395,   394,   404,
     405,   406,   407,   408,   411,   412,   416,   415,   465,   471,
     482,   470,   504,   504,   521,   520,   537,   536,   550,   558,
     562,   566,   572,   576,   580
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "PONTO", "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO",
  "LABEL", "TYPE", "ARRAY", "OF", "PROCEDURE", "FUNCTION", "GOTO", "IF",
  "ELSE", "WHILE", "DO", "IGUAL", "DIFERENTE", "MENOR", "MENOR_OU_IGUAL",
  "MAIOR", "MAIOR_OU_IGUAL", "OR", "AND", "THEN", "NOT", "SOMA", "SUBTRAI",
  "DIV", "MUL", "MOD", "INTEGER", "LONGINT", "REAL", "CHAR", "BOOLEAN",
  "NUMERO", "READ", "WRITE", "LOWER_THAN_ELSE", "$accept", "programa",
  "$@1", "bloco", "$@2", "parte_declara_vars", "$@3", "declara_vars",
  "declara_var", "$@4", "$@5", "tipo", "lista_id_var", "lista_idents",
  "lista_aux", "expressao", "expressao_simples", "sinal_ou_or", "sinal",
  "termo", "operacao_termo", "fator", "$@6", "var_ou_func", "variavel",
  "chamada_de_funcao", "relacao", "comando_composto", "comandos",
  "comando", "comando_sem_rotulo", "$@7", "trata_ident", "atribuicao",
  "$@8", "chama_proc", "comando_repetitivo", "$@9", "$@10",
  "comando_condicional", "$@11", "bloco_if", "$@12", "bloco_else", "$@13",
  "comando_read", "read_params", "comando_write", "write_params", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -61,    12,    15,   -61,    20,    45,    -4,   -61,   -61,    26,
     -61,    47,    -4,   -61,   -61,    44,    48,   -61,    51,    58,
      -3,   -61,   -61,   -61,   -61,    63,    52,    68,   -61,    64,
      69,   -61,   -61,   -61,    55,   -61,   -61,    66,   -61,    67,
      70,     2,    10,    72,     2,   -61,    -3,     2,    59,   -61,
     -61,    22,   -61,   -61,   -61,   -61,     2,   -61,     0,   -61,
     -61,   -61,    56,    37,     0,   -22,   -61,   -61,   -61,    35,
     -61,    46,   -61,   -61,   -61,   -61,    73,   -16,     2,    78,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
       0,   -61,     2,   -22,   -61,   -61,   -61,     0,   -61,    74,
     -61,     2,    54,    10,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,    51,   -22,   -10,   -61,   -61,   -61,    10,
     -61,    82,   -61,   -61,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    20,    21,     0,
      19,     0,     0,     4,    18,     0,     6,     3,     0,     0,
      52,     5,    11,    57,    69,     0,     0,     0,    61,     0,
      54,    56,    59,    60,     0,    62,    63,     8,    10,     0,
      68,     0,    72,     0,     0,    51,    52,     0,    78,     9,
      17,     0,    66,    58,    64,    65,     0,    36,     0,    29,
      30,    38,     0,    22,     0,    26,    31,    55,    81,     0,
      84,     0,    53,    74,    76,    73,     0,     0,     0,     0,
      43,    40,    70,    45,    46,    47,    48,    49,    50,    28,
       0,    27,     0,    25,    35,    34,    33,     0,    79,     0,
      82,     0,     0,    72,    16,    14,    15,    12,    67,    39,
      37,    41,    42,     0,    24,    23,    32,    80,    83,    72,
      77,     0,    71,    75,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    53,   -61,
     -61,   -61,   -61,   -61,    79,   -42,     1,   -61,   -60,   -40,
     -61,   -50,   -61,   -61,   -61,   -61,   -61,   -18,    50,   -61,
     -41,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    15,    16,    18,    19,    37,    38,    39,
     121,   107,    51,     9,    10,    62,    63,    90,    64,    65,
      97,    66,    80,   110,   111,   112,    92,    28,    29,    30,
      31,    40,    53,    54,    78,    55,    32,    41,   113,    33,
      34,    48,   102,    75,   103,    35,    69,    36,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    67,    70,    91,    56,    73,    56,    20,    81,     7,
      23,    94,     3,    57,    79,    57,    95,    96,     4,   -72,
      20,    24,    89,    23,    93,   105,    59,    60,    76,   106,
      77,    11,    12,     5,    24,    58,   108,    58,    59,    60,
      98,    99,     8,    25,    26,    27,    61,   116,    61,     6,
     114,   100,   101,    17,    13,    91,    43,    26,    27,   118,
      -7,    20,   120,    83,    84,    85,    86,    87,    88,    89,
      22,    42,    44,    59,    60,    45,    46,    47,   123,   -11,
      50,    82,    74,   109,    52,    68,   104,   117,   119,   124,
      49,    14,     0,   115,     0,   122,    72
};

static const yytype_int8 yycheck[] =
{
      18,    42,    44,    63,     4,    47,     4,    10,    58,    13,
      13,    33,     0,    13,    56,    13,    38,    39,     3,    22,
      10,    24,    32,    13,    64,    41,    36,    37,     6,    45,
       8,     5,     6,    13,    24,    35,    78,    35,    36,    37,
       5,     6,    46,    46,    47,    48,    46,    97,    46,     4,
      90,     5,     6,     9,     7,   115,     4,    47,    48,   101,
      12,    10,   103,    26,    27,    28,    29,    30,    31,    32,
      12,     8,     4,    36,    37,    11,     7,    22,   119,    13,
      13,    25,    23,     5,    14,    13,    13,    13,    34,     7,
      37,    12,    -1,    92,    -1,   113,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,    13,     4,    13,    46,    63,
      64,     5,     6,     7,    64,    53,    54,     9,    55,    56,
      10,    77,    12,    13,    24,    46,    47,    48,    77,    78,
      79,    80,    86,    89,    90,    95,    97,    57,    58,    59,
      81,    87,     8,     4,     4,    11,     7,    22,    91,    58,
      13,    62,    14,    82,    83,    85,     4,    13,    35,    36,
      37,    46,    65,    66,    68,    69,    71,    80,    13,    96,
      65,    98,    78,    65,    23,    93,     6,     8,    84,    65,
      72,    71,    25,    26,    27,    28,    29,    30,    31,    32,
      67,    68,    76,    69,    33,    38,    39,    70,     5,     6,
       5,     6,    92,    94,    13,    41,    45,    61,    65,     5,
      73,    74,    75,    88,    69,    66,    71,    13,    65,    34,
      80,    60,    77,    80,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    51,    54,    53,    55,    56,    55,    57,
      57,    59,    60,    58,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    72,    71,    71,    71,
      71,    73,    73,    74,    75,    76,    76,    76,    76,    76,
      76,    77,    78,    78,    78,    79,    79,    81,    80,    80,
      80,    80,    80,    80,    82,    82,    84,    83,    85,    87,
      88,    86,    90,    89,    92,    91,    94,    93,    93,    95,
      96,    96,    97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     3,     0,     0,     3,     2,
       1,     0,     0,     6,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     0,     3,     1,     3,
       2,     1,     1,     0,     0,     1,     1,     1,     1,     1,
       1,     3,     0,     3,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     0,
       0,     6,     0,     3,     0,     5,     0,     3,     0,     4,
       3,     1,     4,     3,     1
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
  case 2: /* $@1: %empty  */
#line 60 "compilador.y"
   {
      geraCodigo (NULL, "INPP");
   }
#line 1285 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA bloco PONTO  */
#line 66 "compilador.y"
   {
      geraCodigo (NULL, "PARA");
   }
#line 1293 "compilador.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 73 "compilador.y"
   {
      num_vars_bloco = 0;
   }
#line 1301 "compilador.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 113 "compilador.y"
     { 
      desloc = 0; 
   }
#line 1309 "compilador.tab.c"
    break;

  case 11: /* $@4: %empty  */
#line 122 "compilador.y"
              { num_vars = 0; }
#line 1315 "compilador.tab.c"
    break;

  case 12: /* $@5: %empty  */
#line 125 "compilador.y"
   { 
      /* Aloca memória pras variáveis */
      sprintf(comando, "AMEM %d", num_vars);
      geraCodigo(NULL, comando);
   }
#line 1325 "compilador.tab.c"
    break;

  case 14: /* tipo: INTEGER  */
#line 133 "compilador.y"
              {
      atualiza_tipo(t_integer, num_vars);
   }
#line 1333 "compilador.tab.c"
    break;

  case 15: /* tipo: BOOLEAN  */
#line 136 "compilador.y"
             {
      atualiza_tipo(t_boolean, num_vars);
   }
#line 1341 "compilador.tab.c"
    break;

  case 16: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 142 "compilador.y"
   {
      insere_simbolo(cria_simbolo(var_simples, token, cria_atributos_var_simples(t_indefinido, desloc)));
      num_vars++;
      num_vars_bloco++;
      desloc++;
   }
#line 1352 "compilador.tab.c"
    break;

  case 17: /* lista_id_var: IDENT  */
#line 149 "compilador.y"
   {
      insere_simbolo(cria_simbolo(var_simples, token, cria_atributos_var_simples(t_indefinido, desloc)));
      num_vars++;
      num_vars_bloco++;
      desloc++;
   }
#line 1363 "compilador.tab.c"
    break;

  case 23: /* expressao: expressao_simples relacao expressao_simples  */
#line 173 "compilador.y"
   {
      tipo *t1, *t2;
      t1 = (tipo *)remove_topo(&expressoes_pilha);
      t2 = (tipo *)remove_topo(&expressoes_pilha);

      if (*t1 != *t2)
         imprimeErro("Comparação de tipos diferentes");

      tipo tipo_bool = t_boolean;
      insere_topo(&expressoes_pilha, &tipo_bool);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      sprintf(comando, "%s", gera_operacao_mepa(*op));
      geraCodigo(NULL, comando);
   }
#line 1383 "compilador.tab.c"
    break;

  case 24: /* expressao_simples: expressao_simples sinal_ou_or termo  */
#line 192 "compilador.y"
   {
      tipo *t1, *t2;
      t1 = (tipo *)remove_topo(&expressoes_pilha);
      t2 = (tipo *)remove_topo(&termos_pilha);

      if (*t1 != *t2)
         imprimeErro("Expressão usa tipos diferentes");

      insere_topo(&expressoes_pilha, t1);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      sprintf(comando, "%s", gera_operacao_mepa(*op));
      geraCodigo(NULL, comando);
   }
#line 1402 "compilador.tab.c"
    break;

  case 25: /* expressao_simples: sinal termo  */
#line 207 "compilador.y"
   {
      tipo *t1 = (tipo *)remove_topo(&termos_pilha);
      insere_topo(&expressoes_pilha, t1);

      operacoes *op = (operacoes *)remove_topo(&operacoes_pilha);
      // inverte sinal do termo
      if (*op == op_subt) {
         sprintf(comando, "INVR");
         geraCodigo(NULL, comando);
      }
   }
#line 1418 "compilador.tab.c"
    break;

  case 26: /* expressao_simples: termo  */
#line 219 "compilador.y"
   {
      tipo *t1 = (tipo *)remove_topo(&termos_pilha);
      insere_topo(&expressoes_pilha, t1);
   }
#line 1427 "compilador.tab.c"
    break;

  case 28: /* sinal_ou_or: OR  */
#line 228 "compilador.y"
   {
      operacoes op = op_or;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1436 "compilador.tab.c"
    break;

  case 29: /* sinal: SOMA  */
#line 235 "compilador.y"
   {
      operacoes op = op_soma;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1445 "compilador.tab.c"
    break;

  case 30: /* sinal: SUBTRAI  */
#line 240 "compilador.y"
   {
      operacoes op = op_subt;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1454 "compilador.tab.c"
    break;

  case 31: /* termo: fator  */
#line 248 "compilador.y"
   {
      tipo *t1 = (tipo *)remove_topo(&fatores_pilha);
      insere_topo(&termos_pilha, t1);
   }
#line 1463 "compilador.tab.c"
    break;

  case 32: /* termo: termo operacao_termo fator  */
#line 253 "compilador.y"
   {
      tipo *t1, *t2;
      t1 = (tipo *)remove_topo(&termos_pilha);
      t2 = (tipo *)remove_topo(&fatores_pilha);

      if (*t1 != *t2)
         imprimeErro("Termo usa tipos diferentes!");

      insere_topo(&termos_pilha, t1);
      operacoes *op = remove_topo(&operacoes_pilha);
      sprintf(comando, "%s", gera_operacao_mepa(*op));
      geraCodigo(NULL, comando);
   }
#line 1481 "compilador.tab.c"
    break;

  case 33: /* operacao_termo: MUL  */
#line 269 "compilador.y"
   {
      operacoes op = op_mult;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1490 "compilador.tab.c"
    break;

  case 34: /* operacao_termo: DIV  */
#line 274 "compilador.y"
   {
      operacoes op = op_div;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1499 "compilador.tab.c"
    break;

  case 35: /* operacao_termo: AND  */
#line 279 "compilador.y"
   {
      operacoes op = op_and;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1508 "compilador.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 287 "compilador.y"
   {
      entrada_tabela_simbolos *simb =  busca(token);
      tipo t;

      switch(simb->cat) {
         case var_simples:
            atributos_var_simples *atr_var = (atributos_var_simples *)simb->atributos;
            t = atr_var->tipo_var;
            break;

         case funcao:
            atributos_funcao *atr_func = (atributos_funcao *)simb->atributos;
            t = atr_func->tipo_funcao;
            break;

         case param_formal:
            atributos_param_formal *atr_param = (atributos_param_formal *)simb->atributos;
            t = atr_param->tipo_param;
            break; 
      }

      strncpy(ident, token, strlen(token));
      ident[strlen(token)] = '\0';

      insere_topo(&fatores_pilha, &t);
   }
#line 1539 "compilador.tab.c"
    break;

  case 38: /* fator: NUMERO  */
#line 315 "compilador.y"
   {
      sprintf(comando, "CRCT %s", token);
      geraCodigo(NULL, comando);

      tipo inteiro = t_integer;
      insere_topo(&fatores_pilha, &inteiro);
   }
#line 1551 "compilador.tab.c"
    break;

  case 39: /* fator: ABRE_PARENTESES expressao FECHA_PARENTESES  */
#line 323 "compilador.y"
   {
      tipo *t = (tipo *)remove_topo(&expressoes_pilha);
      insere_topo(&fatores_pilha, t);
   }
#line 1560 "compilador.tab.c"
    break;

  case 43: /* variavel: %empty  */
#line 335 "compilador.y"
   {
      entrada_tabela_simbolos *simb = busca(ident);
      if (simb == NULL) {
         sprintf(mensagem_erro, "Símbolo %s não encontrado", ident);
         imprimeErro(mensagem_erro);
      }
      gera_carregamento(simb);
   }
#line 1573 "compilador.tab.c"
    break;

  case 45: /* relacao: IGUAL  */
#line 350 "compilador.y"
   {
      operacoes op = op_igual;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1582 "compilador.tab.c"
    break;

  case 46: /* relacao: DIFERENTE  */
#line 355 "compilador.y"
   {
      operacoes op = op_diferente;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1591 "compilador.tab.c"
    break;

  case 47: /* relacao: MENOR  */
#line 360 "compilador.y"
   {
      operacoes op = op_menor;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1600 "compilador.tab.c"
    break;

  case 48: /* relacao: MENOR_OU_IGUAL  */
#line 365 "compilador.y"
   {
      operacoes op = op_menor_ou_igual;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1609 "compilador.tab.c"
    break;

  case 49: /* relacao: MAIOR  */
#line 370 "compilador.y"
   {
      operacoes op = op_maior;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1618 "compilador.tab.c"
    break;

  case 50: /* relacao: MAIOR_OU_IGUAL  */
#line 375 "compilador.y"
   {
      operacoes op = op_maior_ou_igual;
      insere_topo(&operacoes_pilha, &op);
   }
#line 1627 "compilador.tab.c"
    break;

  case 57: /* $@7: %empty  */
#line 395 "compilador.y"
   {
      ident_comando = busca(token);
      if (ident_comando == NULL) {
         sprintf(mensagem_erro, "Símbolo %s não encontrado", token);
         imprimeErro(mensagem_erro);
      }
   }
#line 1639 "compilador.tab.c"
    break;

  case 66: /* $@8: %empty  */
#line 416 "compilador.y"
   {
      insere_topo(&ident_comando_pilha, ident_comando);
   }
#line 1647 "compilador.tab.c"
    break;

  case 67: /* atribuicao: ATRIBUICAO $@8 expressao  */
#line 420 "compilador.y"
   {
      ident_comando = remove_topo(&ident_comando_pilha);
      tipo *t = remove_topo(&expressoes_pilha);

      switch(ident_comando->cat) {
         case var_simples:
            atributos_var_simples *atr_var = (atributos_var_simples *)ident_comando->atributos;
            if (atr_var->tipo_var != *t)
               imprimeErro("Atribuição de valor que não é do tipo da variável");
            
            sprintf(comando, "ARMZ %d, %d", ident_comando->nivel, atr_var->deslocamento);
            break;

         case param_formal:
            atributos_param_formal *atr_param = (atributos_param_formal *)ident_comando->atributos;
            if (atr_param->tipo_param != *t)
               imprimeErro("Atribuição de valor que não é do tipo da variável");

            if (atr_param->pass == pass_valor)
               sprintf(comando, "ARMZ %d, %d", ident_comando->nivel, atr_param->deslocamento);
            else if (atr_param->pass == pass_referencia)
               sprintf(comando, "ARMI %d, %d", ident_comando->nivel, atr_param->deslocamento);
            else
               imprimeErro("Tipo de passagem do símbolo indefinido");
            break;

         case funcao:
            atributos_funcao *atr_func = (atributos_funcao *)ident_comando->atributos;
            if (atr_func->tipo_funcao != *t)
               imprimeErro("Atribuição de valor que não é do tipo da variável");

            sprintf(comando, "ARMZ %d, %d", ident_comando->nivel, atr_func->deslocamento);
            break;

         default:
            sprintf(mensagem_erro, "Um valor não pode ser atribuído ao símbolo %s", ident_comando->id);
            imprimeErro(mensagem_erro);
            break;
      }

      geraCodigo(NULL, comando);
      ident_comando = NULL;
   }
#line 1695 "compilador.tab.c"
    break;

  case 69: /* $@9: %empty  */
#line 471 "compilador.y"
        {
		char *WhileInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *WhileFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		insere_topo(&pilha_rotulos, WhileInicio);
		insere_topo(&pilha_rotulos, WhileFim);
		geraCodigo(pega_rotulo(pilha_rotulos, 2), "NADA");
	}
#line 1710 "compilador.tab.c"
    break;

  case 70: /* $@10: %empty  */
#line 482 "compilador.y"
        {
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", pega_rotulo(pilha_rotulos, 1));
		geraCodigo(NULL, dsvf);
	}
#line 1720 "compilador.tab.c"
    break;

  case 71: /* comando_repetitivo: WHILE $@9 expressao DO $@10 comando_composto  */
#line 488 "compilador.y"
        {
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(pilha_rotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(pilha_rotulos, 1));
		geraCodigo(rot, "NADA");

		remove_topo(&pilha_rotulos);
      remove_topo(&pilha_rotulos);
	}
#line 1737 "compilador.tab.c"
    break;

  case 72: /* $@11: %empty  */
#line 504 "compilador.y"
   {
      char * RotElse = cria_rotulo(rotulo_print);
      rotulo_print++;
      char * RotFim = cria_rotulo(rotulo_print);
      rotulo_print++;

      insere_topo(&pilha_rotulos, RotElse);
      insere_topo(&pilha_rotulos, RotFim);
   }
#line 1751 "compilador.tab.c"
    break;

  case 73: /* comando_condicional: $@11 bloco_if bloco_else  */
#line 514 "compilador.y"
   {
      remove_topo(&pilha_rotulos);
      remove_topo(&pilha_rotulos);
   }
#line 1760 "compilador.tab.c"
    break;

  case 74: /* $@12: %empty  */
#line 521 "compilador.y"
   {
      // verifica se expressão é booleana
      tipo *t = (tipo *)remove_topo(&expressoes_pilha);

      if (*t != t_boolean){
         imprimeErro("Expressão não é booleana");
      }

      // Gera DSVF com rotulo
      sprintf(comando, "DSVF %s", pega_rotulo(pilha_rotulos, 0));
      geraCodigo(NULL, comando);
   }
#line 1777 "compilador.tab.c"
    break;

  case 76: /* $@13: %empty  */
#line 537 "compilador.y"
   {
      // gera desvio para fim do if
      sprintf(comando, "DSVS %s", pega_rotulo(pilha_rotulos, 1));
      geraCodigo(NULL, comando);

      // gera rotulo do else
      geraCodigo(pega_rotulo(pilha_rotulos, 0), "NADA");
   }
#line 1790 "compilador.tab.c"
    break;

  case 77: /* bloco_else: ELSE $@13 comando_sem_rotulo  */
#line 546 "compilador.y"
   {
      // gera rotulo de fim do if
      geraCodigo(pega_rotulo(pilha_rotulos, 1), "NADA");
   }
#line 1799 "compilador.tab.c"
    break;

  case 78: /* bloco_else: %empty  */
#line 551 "compilador.y"
   {
      // gera rotulo do else
      geraCodigo(pega_rotulo(pilha_rotulos, 0), "NADA");
   }
#line 1808 "compilador.tab.c"
    break;

  case 80: /* read_params: read_params VIRGULA IDENT  */
#line 563 "compilador.y"
   {
      leitura(token);
   }
#line 1816 "compilador.tab.c"
    break;

  case 81: /* read_params: IDENT  */
#line 567 "compilador.y"
   {
      leitura(token);
   }
#line 1824 "compilador.tab.c"
    break;

  case 83: /* write_params: write_params VIRGULA expressao  */
#line 577 "compilador.y"
   {
      geraCodigo(NULL, "IMPR");
   }
#line 1832 "compilador.tab.c"
    break;

  case 84: /* write_params: expressao  */
#line 581 "compilador.y"
   {
      geraCodigo(NULL, "IMPR");
   }
#line 1840 "compilador.tab.c"
    break;


#line 1844 "compilador.tab.c"

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

#line 586 "compilador.y"


int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
   inicializa_tabela_simbolos();
   inicializa_pilha(&num_vars_pilha);
   inicializa_pilha(&pilha_rotulos);
   inicializa_pilha(&expressoes_pilha);
   inicializa_pilha(&termos_pilha);
   inicializa_pilha(&fatores_pilha);
   inicializa_pilha(&operacoes_pilha);
   inicializa_pilha(&ident_comando_pilha);

   yyin=fp;
   yyparse();

   return 0;
}
