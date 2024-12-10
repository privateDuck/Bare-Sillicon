grammar bs;


program         : declaration* EOF;
declaration     : global
                | function
                | typedef
                ;

typedef             : TYPEDEF type ID ';';
global              : udef_type ID '=' init_element ';';
function            : udef_type ID '(' params ? ')' block;
params              : param_decl (',' param_decl)*;
param_decl          : udef_type ID;
block               : '{' statement* '}';

statement       returns [ bool isDead = false]
                : var_decl
                | array_decl
                | expr ';'
                | goto_label
                | compound
                | if
                | ifelse
                | while
                | for1
                | for2
                | goto
                | goto_if
                | return
                | break
                | continue
                ;

var_decl            returns [bool isDead = false]: udef_type ID '=' expr ';';
array_decl          : udef_type ID '[' SIGNED_INT ']' ('=' array_initializer)? ';';
array_initializer   : '{' init_element (',' init_element)* '}';
init_element        : atom=(SIGNED_INT | UNSIGNED_INT)      #InitIntLiteral
                    | CHAR                                  #InitCharLiteral
                    | STRING_LITERAL                        #InitStringLiteral
                    ;

goto_label      : ID ':';
compound        : block;
if              : IF '(' expr ')' statement;
ifelse          : IF '(' expr ')' pos=statement ELSE neg=statement;
while           returns [bool noCond = false]: WHILE '(' expr ')' statement;
for1            : FOR '(' var_decl ? ';' cond=expr ? ';' end_oper=expr ? ')' statement;
for2            : FOR '(' ID FROM start_val=expr TO end_val=expr ')' statement;
goto            : GOTO ID ';';
goto_if         returns [int state = 0]: GOTO ID IF cond=expr ';'; // state: 0 - runtime eval, 1 - always true, 2 - always false
return          : RETURN expr ';';
break           : BREAK ';';
continue        : CONTINUE ';';

expr            returns [ bool isConst = false, long long eValue = 0, bool isDc = false, bool isDead = false, int eType = 0]
                : '(' expr ')'                                       #Paran
                | <assoc=left> ID '(' args ? ')'                     #Call
                | <assoc=right> op=('++' | '--') operand=ID          #PreID
                | <assoc=right> op=(PLUS | MINUS) operand=expr          #UnaryPN
                | <assoc=right> '(' udef_type ')' expr               #StaticCast
                | <assoc=right> REINTERPRET_CAST '<' udef_type '>' '(' expr ')' #ReinterpretCast
                | <assoc=right> '[' expr (':' alignment) ? ']'       #Dereference
                | <assoc=right> '&' ID                               #AddressOf
                | <assoc=right> op=('~' | '!') operand=expr          #BNeg_LNot
                | <assoc=left> left=expr op=('*' | '/') right=expr   #MulDiv
                | <assoc=left> left=expr '%' right=expr              #Mod
                | <assoc=left> left=expr op=('+' | '-') right=expr   #AddSub
                | <assoc=left> left=expr '>>' right=expr             #RShift
                | <assoc=left> left=expr '<<' right=expr             #LShift
                | <assoc=left> left=expr op=('>' | '<') right=expr   #GL
                | <assoc=left> left=expr op=('>=' | '<=') right=expr #GeLe
                | <assoc=left> left=expr op=('==' | '!=') right=expr #EqNeq
                | <assoc=left> left=expr '&' right=expr              #BitAnd
                | <assoc=left> left=expr '^' right=expr              #BitXor
                | <assoc=left> left=expr '|' right=expr              #BitOr
                | <assoc=left> left=expr '&&' right=expr             #LogicAnd
                | <assoc=left> left=expr '||' right=expr             #LogicOr
                | <assoc=left> ID '=' expr                           #DSimpleAssign
                | <assoc=left> ID cop=('+=' | '-=') expr             #DAddSubCompAssign
                | <assoc=left> ID cop=('*=' | '/=' | '%=') expr      #DMulDivModCompAssign
                | <assoc=left> ID cop=('<<=' | '>>=') expr           #DLSRSCompAssign
                | <assoc=left> ID cop=('&=' | '^=' | '|=') expr      #DAndXorOrCompAssign

                | <assoc=left> '[' deref=expr (':' alignment) ? ']' '=' e=expr                       #ISimpleAssign
                | <assoc=left> '[' deref=expr (':' alignment) ? ']' cop=('+=' | '-=') e=expr         #IAddSubCompAssign
                | <assoc=left> '[' deref=expr (':' alignment) ? ']' cop=('*=' | '/=' | '%=') e=expr  #IMulDivModCompAssign
                | <assoc=left> '[' deref=expr (':' alignment) ? ']' cop=('<<=' | '>>=') e=expr       #ILSRSCompAssign
                | <assoc=left> '[' deref=expr (':' alignment) ? ']' cop=('&=' | '^=' | '|=') e=expr  #IAndXorOrCompAssign
                
                | atom=ID                                            #ID
                | atom=UNSIGNED_INT                                  #IntegerLiteral
                | atom=STRING_LITERAL                                #StringLiteral
                | atom=CHAR                                          #CharLiteral
                ;

args            : expr (',' expr)*;


type            : BYTE_t | CHAR_t   #TypeSigned8
                | UBYTE_t| UCHAR_t  #TypeUnsigned8
                | INT_t             #TypeSignedWORD
                | UINT_t            #TypeUnsignedWORD
                ;

udef_type: type | ID;
alignment       : ALIGN;

// type tokens
BYTE_t  : 'byte';
CHAR_t  : 'char';
INT_t   : 'int';
UBYTE_t : 'u8' | 'ubyte';
UCHAR_t : 'uchar';
UINT_t  : 'uint';

// control keywords
GOTO    : 'goto';
IF      : 'if';
ELSE    : 'else';
WHILE   : 'while';
FOR     : 'for';
RETURN  : 'return';
BREAK   : 'break';
CONTINUE: 'continue';
STATIC  : 'static';
REINTERPRET_CAST : 'reinterpret_cast';
FROM    : 'from';
TO      : 'to';
TYPEDEF : 'typedef';
FN      : 'function' | 'func' | 'fn';
ALIGN   : 'sb' | 'ub' | 'sw' | 'uw' | 'si' | 'ui' | '1s' | '1u' | '2s' | '2u' | '4s' | '4u';

PLUS   : '+';
MINUS  : '-';

ID              : [a-zA-Z_][a-zA-Z0-9_]*;
CHAR            : '\'' .*? '\'';
STRING_LITERAL  : UNTERMINATED_STRING_LITERAL '"';

UNTERMINATED_STRING_LITERAL : '"' (~["\\\r\n] | '\\' (. | EOF))*;

UNSIGNED_INT    : HEX | BIN | DECIMAL;
SIGNED_INT      :   HEX
                |   BIN
                |   DECIMAL
                ;

fragment SIGN
    :   PLUS | MINUS
    ;

fragment HEX
    :   '0' [xX] [0-9a-fA-F]+
    ;

fragment BIN
    :   '0' [bB] [01]+
    ;

fragment DECIMAL
    :   [0-9]+
    ;

Newline : ('\r' '\n'? | '\n') -> channel(HIDDEN);
Whitespace : [ \t]+ -> channel(HIDDEN) ;
BlockComment : '/*' .*? '*/' -> channel(HIDDEN) ;
LineComment : '//' ~[\r\n]* -> channel(HIDDEN) ;