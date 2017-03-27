# parse_lab

#for run : 
yacc -d sql.y
flex sql.l
gcc lex.yy.c y.tab.c -o sql
./sql


gcc modified.c -o modified
./modified


Write a recursive descent parser for the SQL language you have designed in the previous assignment. You are allowed to modify the grammar and language but be prepared with the justifications for the changes you make. Your parser should be able to identify the multiple syntax errors.

Write a C program to display the syntax tree corresponding to a syntactically correct input.

Re-implement the parser using the Bison tool. 
