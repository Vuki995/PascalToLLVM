#ifndef __te__
#define __te__
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include"tipovi.hpp"
#include"codegen.hpp"
using namespace std;
void yyerror(string s);
class tip;
class izraz{
	public:
	virtual ~izraz(){
	}
	virtual void dodela(){}//dodela tipova promenljivama
	virtual izraz* kopija() const=0;
	virtual tip* provera()const=0;
	virtual string ispis()const=0;//dva u jedan metoda test da li ima 1 promenljivu i koji joj je id, "--" ne moze da se pojavi kao id 
	virtual Value* codegen()const=0;
};

class cons:public izraz{
	public:
		cons(int fn,tip* tp);
		cons(float fn,tip* tp);
		cons(char fn,tip* tp);
		cons(string fn,tip* tp);
		cons(bool fn,tip* tp);
		cons(const cons& x);
		tip* provera()const;
		string ispis()const;
		~cons();
		izraz* kopija() const;
		void dodela();
		
		Value* codegen()const;
	private:
		int i;
		float f;
		char c;
		string s;
		bool b;
		tip* t;
};

class prom:public izraz{
	public:
		prom(string s,tip* t);
		prom(const prom& p);
		~prom();
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		void dodela();
		Value* codegen()const;
	private:
		string ime;
		tip* tp;
};



class operacija:public izraz{
	public:
		operacija(izraz* a){
			niz.resize(0);
			niz.push_back(a->kopija());
		}
		operacija(izraz* a,izraz* b){
			niz.resize(0);
			niz.push_back(a->kopija());
			niz.push_back(b->kopija());
		}
		operacija(izraz* a,izraz* b,izraz* c){
			niz.resize(0);
			niz.push_back(a->kopija());
			niz.push_back(b->kopija());
			niz.push_back(c->kopija());
		}
		operacija(vector<izraz*>tmp){
			niz.resize(0);
			for(auto e:tmp)
				niz.push_back(e->kopija());
		}
		~operacija(){
			for(auto e:niz){
				delete(e);
				}
		}
		operacija(const operacija& z){
			niz.resize(0);
			for(auto e:z.niz)
				niz.push_back(e->kopija());
		}
		void dodela();
	protected:
		vector<izraz*>niz;
};
class zbir:public operacija{
	public:
		zbir(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
};
class razlika:public operacija{
	public:
		razlika(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
};
class proizvod:public operacija{
	public:
		proizvod(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
 
};
class kolicnik:public operacija{
	public:
		kolicnik(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
 
};
class BitAnd:public operacija{
	public:
		BitAnd(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
};
class BitOr:public operacija{
	public:
		BitOr(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
};
class BitNot:public operacija{
	public:
		BitNot(izraz* a):operacija(a)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
};
class grtr:public operacija{
	public:
		grtr(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
 
};
class eq:public operacija{
	public:
		eq(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
 
};
class lss:public operacija{
	public:
		lss(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
	 
};
class neq:public operacija{
	public:
		neq(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
 
};

class And:public operacija{
	public:
		And(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;

};

class Orr:public operacija{
	public:
		Orr(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;

};

class Not:public operacija{
	public:
		Not(izraz* a):operacija(a)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;

};

class poziv:public operacija{
	public:
		poziv(string s,vector<izraz*>tmp,tip* t):operacija(tmp),str(s),tp(t)
		{}
		poziv(const poziv& p);
		~poziv();
		void dodela();
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
 
	private:
		string str;
		tip* tp;
};
class Niz:public operacija{
	public:
		Niz(izraz* a,izraz* b):operacija(a,b)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
};
class pokazivac:public operacija{
	public:
		pokazivac(izraz* a):operacija(a)
		{}
		tip* provera()const;
		izraz* kopija() const;
		string ispis()const;
		Value* codegen()const;
};
class adresa:public operacija{
	public:
		adresa(izraz* a):operacija(a)
		{}
		tip* provera()const;
		izraz* kopija()const;
		string ispis()const;
		Value* codegen()const;
};
class struktura:public operacija{
	public:
		struktura(izraz* a, string id):operacija(a),str(id)
		{}
		struktura(const struktura& s);
		tip* provera()const;
		izraz* kopija()const;
		string ispis()const;
		Value* codegen()const;
		
	private:
		string str;
};
#endif
