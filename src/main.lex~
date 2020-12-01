%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
	int	chars=0,words=0,lines=0;
	std::map <std::string,int> ID_list;
%}

%%

MAIN	main
INT 	int
CHAR 	char
STRING	string
IF 	if
WHILE 	while
FOR 	for
RETURN 	return
PRINTF	printf
SCANF	scanf
LPAREN 	"("
RPAREN 	")"
LBRACE 	"{"
RBRACE 	"}"
AND 	"&&"
OR 	"||"
NOT 	"!"
SUM 	"+"
SUB 	"-"
MUL 	"*"
DIV 	"/"
MOD 	"%"
EQ 	"=="
UEQ 	"!="
BEQ 	">="
LEQ 	"<="
BQ 	">"
LQ 	"<"
EV 	"="
COMMA	","
SEMICOLON ";"
ID	[a-zA-Z_]*([a-zA-Z_0-9]+)
NUMBER	[0-9]+
word	[a-zA-Z]+
line	\n
commentbegin	"/*"
commentelement	.|\n
commentend	"*/"
%x COMMENT

%%

{MAIN} {return MAIN;}
{INT} {printf("INT  %s\n",yytext);return INT;}
{CHAR} {printf("CHAR	%s\n",yytext);return CHAR;}
{STRING} {printf("STRING	%s\n",yytext);return STRING;}
{IF} {return IF;}
{WHILE} {return WHILE;}
{FOR}	{return FOR;}
{RETURN} {return RETURN;}
{PRINTF} {return PRINTF;}
{SCANF}	{return SCANF;}
{LPAREN} {return LPAREN;}
{RPAREN} {return RPAREN;}
{LBRACE} {return LBRACE;}
{RBRACE} {return RBRACE;}
{AND} {printf("AND  %s\n",yytext);return AND;}
{OR} {printf("OR  %s\n",yytext);return OR;}
{NOT} {printf("NOT  %s\n",yytext);return NOT;}
{SUM} {printf("SUM  %s\n",yytext);return SUM;}
{SUB} {printf("SUB  %s\n",yytext);return SUB;}
{MUL} {printf("MUL  %s\n",yytext);return MUL;}
{DIV} {printf("DIV  %s\n",yytext);return DIV;}
{MOD} {printf("MOD  %s\n",yytext);return MOD;}
{EQ} {return EQ;}
{UEQ} {return UEQ;}
{BEQ} {return BEQ;}
{LEQ} {return LEQ;}
{BQ} {return BQ;}
{LQ} {return LQ;}
{EV} {return EV;}
{COMMA}	{return COMMA;}
{SEMICOLON} {return SEMICOLON;}
{NUMBER} {return NUMBER;}
{ID} {
	 std::string A=yytext;
	 if(ID_list.find(A)!=ID_list.end())
		{printf("ID  %s  %d\n",yytext,ID_list.find(A)->second);}
	 else
		{ID_list[A]=ID_list.size()-1;printf("ID  %s  %d\n",yytext,ID_list.size()-1);}
}
{word}	{words++;chars+=strlen(yytext);}
{line}	{lines++;}
{char}	{chars++;}
{commentbegin}	{BEGIN COMMENT;}
<COMMENT>{commentelement} {}
<COMMENT>{commentend} {BEGIN INITIAL;}

%%
