%{

/********************************************************************/
/*  Contact.lex                                                     */
/*  Authors:                                                        */
/*      Derrik Fleming                                              */
/*      Nathan Lindenbaum                                           */ 
/********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "Contacts.tab.h"

%}

%%

[A-Z][a-z]+                           { printf("Name: %s\n", yytext); 
                                 yylval.sVal = yytext; return NAME; }
[2-9]{1}[0-9]{2}-[0-9]{4}            { printf("Phone: %s\n", yytext);
                                yylval.sVal = yytext; return PHONE; } 
[A-Za-z]+[@][A-Za-z\.]+[\.]("com")   { printf("Email: %s\n", yytext);
                                yylval.sVal = yytext; return EMAIL; }
[0-9]{4}                     { printf("sNumber: %d\n", atoi(yytext)); 
                     yylval.iVal = atoi(yytext); return STREET_NUM; } 
[A-Z]{3,}			 	             { printf("sName: %s\n", yytext); 
                          yylval.sVal = yytext; return STREET_NAME; } 
(AV|RD|DR)			                 { printf("sType: %s\n", yytext); 
                          yylval.sVal = yytext; return STREET_TYPE; } 
[0-9]{5}   		             { printf("Zipcode: %d\n", atoi(yytext)); 
                        yylval.iVal = atoi(yytext); return ZIPCODE; } 

[ \t\n]				  ;
.				  { printf("Unexpected input!\n"); }

%%
int yywrap(void) {
	return 1;
}
