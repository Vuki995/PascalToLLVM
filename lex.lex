%option noyywrap
%option noinput
%option nounput
%{
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
#include"naredbe.hpp"
#include"yac.tab.hpp"
%}
%%
"int" return int_token;
"true" {yylval.b=new bool(true);return bool_token;}
"false" {yylval.b=new bool(false);return bool_token;}
"bool" return bool_type;
"float" return float_token;
"char" return char_token;
"array" return array_token;
"record" return record_token;
"of" return of_token;
"repeat" return repeat_token;
"until" return until_token;
"and" return and_token;
"or" return or_token;
"not" return not_token;
"type" return type_token;
"program" return program_token;
"const" return const_token;
"var" return var_token;
"function" return function_token;
"procedure" return procedure_token;
"forward"  return forward_token;
"begin" return begin_token;
"end" return end_token;
"break"	return break_token;
"continue"  return continue_token;
"exit"  return exit_token;
"writeln" return print_token;
"read" return read_token;
"if" return if_token;
"then" return then_token;
"else" return else_token;
"while" return while_token;
"for" return for_token;
"to" return to_token;
"do" return do_token;
">" return GT;
"<" return LT;
"!=" return NE;
"==" return EQ;
"&" return bita_token;
"|" return bito_token;
"~" return bitn_token;
[a-zA-Z][a-zA-Z0-9_]* {yylval.nm=new string(yytext); 
			return id_token;}
\'([^\']*)\' {string tmp(yytext);
		yylval.pr=new string(tmp.substr(1,tmp.size()-2));
		return string_token;}
[0-9]+\.?([0-9])? {yylval.f=atof(yytext);return num_token;}
[\.;\+\-\*/(\)=:,\[\]\^\@] return *yytext;
[\n\t ] {}
. {cerr<<"nepostojeci simbol"<<*yytext<<endl;
	exit(EXIT_FAILURE);}
%%
