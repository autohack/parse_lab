%{
#include <stdio.h>
#include <stdlib.h>

void yyerror (const char *str) 
{
	fprintf(stderr, "error: %s\n", str);		// error function
}

int yywrap() 
{
	return 1;
}
// main function 
int main() 
{
	return	yyparse(); // calling parse funtion 
	
}

%}

%%

%token SELECT FROM INT CHAR VARCHAR  PRIMARY KEY STRING IDENTIFIER WHERE AND OR DROP DELETE TABLE ALTER COLUMN ADD CREATE INTO VALUES INSERT UPDATE SET NUMBER;
/* production for sql grammar */

start: 			line  | sline | line start | sline start;		/*start state */

sline: 			SELECT items FROM IDENTIFIER semi '\n' {printf("Easy select with items \n");}
			
				| SELECT items using pro_condition semi '\n' { printf("Conditional select with items \n");}
				
				| SELECT '*' FROM IDENTIFIER semi '\n' {printf("all select with * \n");}
				
				| SELECT '*' using pro_condition semi '\n' {printf("conditional select with *  \n");};


new_line:		SELECT items using pro_condition| SELECT items FROM IDENTIFIER 		/*for nested select query */
				| SELECT '*' FROM IDENTIFIER | SELECT '*' using pro_condition ;


line:			DELETE FROM IDENTIFIER semi '\n'			{printf("Deleting complete rows.\n");}

				| DELETE FROM IDENTIFIER WHERE condition semi '\n' 	{ printf("Deleting data from particular table.\n"); }
			
				
				| DROP TABLE IDENTIFIER semi '\n'					{printf("Dropping table.\n");}
				
				| ALTER TABLE IDENTIFIER DROP COLUMN items semi '\n' {printf("Alter this table\n");}
		

				| ALTER TABLE IDENTIFIER ADD IDENTIFIER IDENTIFIER semi '\n' {printf("ADD in ALTER this TABLE\n");}
		
				| INSERT INTO IDENTIFIER VALUES leftbr alpha_items rightbr semi '\n' { printf("INSERTing INTO TABLE");}
		
				| INSERT INTO IDENTIFIER leftbr items rightbr VALUES leftbr alpha_items rightbr semi '\n' { printf("INSERTing INTO TABLE with items");}
				
				| CREATE TABLE IDENTIFIER leftbr hyper_items rightbr semi '\n' { printf("creating TABLE\n"); }


				| UPDATE IDENTIFIER SET up_cond semi '\n' { printf("updating without condition\n" );}
		
				| UPDATE IDENTIFIER SET up_cond WHERE pro_condition semi '\n' { printf("updating with nested condition\n" );};
		
pro_condition: 	IDENTIFIER comparator leftbr new_line rightbr | condition ;


alpha_items:	 NUMBER new_alpha_item|  STRING new_alpha_item ;

new_alpha_item: ',' NUMBER new_alpha_item | ',' STRING new_alpha_item |/*e*/ ;

create_items:	p_create_items pp;

pp: 			PRIMARY KEY |/*e*/ ;

p_create_items:	IDENTIFIER INT | IDENTIFIER CHAR leftbr NUMBER rightbr | IDENTIFIER VARCHAR leftbr NUMBER rightbr;

hyper_items: 	create_items  new_hyper_items;

new_hyper_items:  ',' create_items new_hyper_items|/*e*/ ;

items: 			IDENTIFIER new_items;

new_items: 		',' IDENTIFIER new_items|/*e*/ ;


comparator:		'=' | "<=" | '<' | ">=" | '>';

leftbr:			'(';

rightbr:		')';

semi: 			';';

ao: 			AND | OR ; 

using: 			FROM nes2 WHERE;

nes2: 			IDENTIFIER |  leftbr new_line rightbr |/*e*/ ;

up_cond:		IDENTIFIER '=' STRING new_up_cond | IDENTIFIER '=' NUMBER new_up_cond;

new_up_cond:	',' IDENTIFIER '=' STRING new_up_cond | ',' IDENTIFIER '=' NUMBER new_up_cond |/*e*/ ;

condition: 		IDENTIFIER comparator STRING new_condition | IDENTIFIER comparator NUMBER new_condition;

new_condition: 	ao IDENTIFIER comparator STRING new_condition | ao IDENTIFIER comparator NUMBER new_condition | /*e*/;

%%
