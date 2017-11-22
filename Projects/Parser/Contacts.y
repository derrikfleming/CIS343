%{
/********************************************************************/
/*  Contact.y                                                       */
/*  Authors:                                                        */
/*      Derrik Fleming                                              */
/*      Nathan Lindenbaum                                           */ 
/********************************************************************/

#include <stdio.h>
int yylex (void);
int yyerror(char* msg);
%}
%union{
	int iVal;
	char *sVal;
}

%start file 				
%token NAME
%type<sVal> NAME
%token PHONE
%type<sVal> PHONE
%token EMAIL
%type<sVal> EMAIL
%token STREET_NUM
%type<iVal> STREET_NUM
%token STREET_NAME
%type<sVal> STREET_NAME
%token STREET_TYPE
%type<sVal> STREET_TYPE
%token ZIPCODE
%type<iVal> ZIPCODE
%type<sVal> contact



%%

file:			contact
                      |	contact file
;

contact:	     NAME NAME STREET_NUM STREET_NAME STREET_TYPE ZIPCODE;

%%
int main(int argc, char ** argv) {
	yyparse();
}
int yyerror (char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
}