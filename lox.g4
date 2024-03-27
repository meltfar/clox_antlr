grammar lox;

WHITESPACE: [ \t]+ -> skip;
NEWLINE: ( '\r' '\n'?|'\n') -> skip;

NUMBER: DIGIT+ ('.' DIGIT+)?;
STRING_LITERAL: '"' (~["\\\r\n] | EscapeSequence)* '"';
fragment EscapeSequence:
	'\\' [btnfr"'\\]
	| '\\' ([0-3]? [0-7])? [0-7]
	| '\\' 'u'+ HexDigit HexDigit HexDigit HexDigit;
fragment HexDigit: [0-9a-fA-F];
IDENTIFIER: ALPHA (ALPHA | DIGIT)*;
ALPHA: [a-zA-Z_];
DIGIT: [0-9];

program: declaration* EOF;


declaration: classDec | funDec | varDec | statement;

classDec:
	'class' IDENTIFIER ('(' IDENTIFIER ')')? '{' function* '}';

funDec: 'func' function;

varDec: 'var' IDENTIFIER ('=' expression)? ';';

statement:
	exprStmt
	| forStmt
	| ifStmt
	| printStmt
	| returnStmt
	| whileStmt
	| block;

exprStmt: expression ';';

forStmt: 'for' '(' (varDec | exprStmt | ';') expression? ';' expression? ';' ')' block;

ifStmt: 'if' '(' expression ')' block ( 'else' block)?;

printStmt: 'print' expression ';';
returnStmt: 'return' expression? ';';
whileStmt: 'while' '(' expression ')' block;
block: '{' declaration* '}';

expression: assignment;
assignment: (call '.')? IDENTIFIER '=' assignment | logic_or;

logic_or: logic_and ('or' logic_and)*;
logic_and: equality ( 'and' equality)*;
equality: comparison (('!=' | '==') comparison)*;
comparison: term (('>' | '>=' | '<' | '<=') term)*;
term: factor (('-' | '+') factor)*;
factor: unary (('/' | '*') unary)*;

unary: ('!' | '-') unary | call;
call: primay ('(' arguments? ')' | '.' IDENTIFIER)*;

primay:
	'true'
	| 'false'
	| 'nil'
	| 'this'
	| NUMBER
	| STRING_LITERAL
	| IDENTIFIER
	| '(' expression ')'
	| 'super' '.' IDENTIFIER;

function: IDENTIFIER '(' parameters? ')' block;
parameters: IDENTIFIER (',' IDENTIFIER)*;
arguments: expression (',' expression)*;