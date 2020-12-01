%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
	int	chars=0,words=0,lines=0;
	std::map <std::string,int> ID_list;
%}

%%

INT 	int
CHAR 	char
STRING	string
IF 	if
WHILE 	while
FOR 	for
RETURN 	return
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

{INT} {printf("INT  %s\n",yytext);}
{CHAR} {printf("CHAR	%s\n",yytext);}
{STRING} {printf("STRING	%s\n",yytext);}
{IF} {printf("IF %s\n",yytext);}
{WHILE} {printf("WHILE  %s\n",yytext);}
{FOR}	{printf("FOR	%s\n",yytext);}
{RETURN} {printf("RETURN  %s\n",yytext);}
{LPAREN} {printf("LPAREN  %s\n",yytext);}
{RPAREN} {printf("RPAREN  %s\n",yytext);}
{LBRACE} {printf("LBRACE  %s\n",yytext);}
{RBRACE} {printf("RBRACE  %s\n",yytext);}
{AND} {printf("AND  %s\n",yytext);}
{OR} {printf("OR  %s\n",yytext);}
{NOT} {printf("NOT  %s\n",yytext);}
{SUM} {printf("SUM  %s\n",yytext);}
{SUB} {printf("SUB  %s\n",yytext);}
{MUL} {printf("MUL  %s\n",yytext);}
{DIV} {printf("DIV  %s\n",yytext);}
{MOD} {printf("MOD  %s\n",yytext);}
{EQ} {printf("EQ  %s\n",yytext);}
{UEQ} {printf("UEQ  %s\n",yytext);}
{BEQ} {printf("BEQ  %s\n",yytext);}
{LEQ} {printf("LEQ  %s\n",yytext);}
{BQ} {printf("BQ  %s\n",yytext);}
{LQ} {printf("LQ  %s\n",yytext);}
{EV} {printf("EV  %s\n",yytext);}
{SEMICOLON} {printf("SEMICOLON  %s\n",yytext);}
{NUMBER} {printf("NUMBER  %s  %s\n",yytext,yytext);}
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
