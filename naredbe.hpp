#ifndef __tt__
#define __tt__
#include"asp.hpp"
#include<string>
#include<vector>
#include<map>
extern stack<map<string,pair<tip*,izraz*>>> lokalne;
using namespace std;
class subprogram;
void yyerror(string s);
void listmaker(vector<pair<string,tip*>>*l,vector<string>* args, tip* tp);
void mapmaker(map<string,tip*>* mapa, vector<pair<string,tip*>>* args);
void argsRemover(vector<pair<string,tip*>>* args);
void mapsRemover(map<string,tip*>* m);
void functRemover(vector<subprogram*>* vsp);
bool argCheck(const vector<pair<string,tip*>>& map1,const vector<pair<string,tip*>>& map2);
class naredba{
	public:
		virtual ~naredba()
		{}
		virtual void dodela(){}
		virtual bool provera(int i)const=0;
		virtual naredba* kopija()const=0;
		virtual Value* codegen()const=0;
};
class blok:public naredba{
	public:
		blok(vector<naredba*>redovi){
			rd.resize(0);
			for(auto e:redovi)
				rd.push_back(e->kopija());
		}
		blok(const blok& z){
			rd.resize(0);
			for(auto e:z.rd)
				rd.push_back(e->kopija());
		}
		~blok();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		vector<naredba*>rd;
};
class ispisE:public naredba{
	public:
		ispisE(izraz* i):e(i->kopija())
		{}
		ispisE(const ispisE& i){
			e=i.e->kopija();
		}
		~ispisE();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		izraz* e;
};
class citajE:public naredba{
	public:
		citajE(izraz* i):e(i->kopija())
		{}
		citajE(const citajE& c){
			e=c.e->kopija();
		}
		~citajE();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		izraz* e;

};
class dodelaE:public naredba{
	public:
		dodelaE(izraz* s,izraz* i):ime(s->kopija()),e(i->kopija())
		{}
		dodelaE(const dodelaE& d){
			ime=d.ime->kopija();
			e=d.e->kopija();
		}
		~dodelaE();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		izraz* ime;
		izraz* e;
};

class ifThen:public naredba {
	public:
		ifThen(izraz* i1,naredba* nr):iz(i1->kopija()),naredbe(nr->kopija())
		{}
		ifThen(const ifThen& i){
			iz=i.iz->kopija();
			naredbe=i.naredbe->kopija();
		}
		~ifThen();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		izraz* iz;
		naredba* naredbe;
};
class ifThenElse:public naredba{
	public:
		ifThenElse(izraz* i1,naredba* nr1,naredba* nr2):iz(i1->kopija()),naredbe(nr1->kopija()),elseN(nr2->kopija())
		{}
		ifThenElse(const ifThenElse& t){
			iz=t.iz->kopija();
			naredbe=t.naredbe->kopija();
			elseN=t.elseN->kopija();
		}
		~ifThenElse();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		izraz* iz;
		naredba* naredbe;
		naredba* elseN;
};
class Break:public naredba{
	public:
		Break()
		{}
		~Break()
		{}
		void dodela(){}
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
};
class Continue:public naredba{
	public:
		Continue()
		{}
		~Continue()
		{}
		void dodela(){}
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
};
class kraj:public naredba{
	public:
		kraj()
		{}
		~kraj()
		{}
		void dodela(){}
		bool provera(int i)const{return true;}
		naredba* kopija()const;
		Value* codegen()const;
};

class While:public naredba{
	public:
		While(izraz* i1,naredba* nr):iz(i1->kopija()),naredbe(nr->kopija())
		{}
		While(const While& w){
			iz=w.iz->kopija();
			naredbe=w.naredbe->kopija();
		}
		~While();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		izraz* iz;
		naredba* naredbe;
};

class repeatUntil:public naredba{
	public:
		repeatUntil(izraz* i1,naredba* nr):iz(i1->kopija()),naredbe(nr->kopija())
		{}
		repeatUntil(const repeatUntil& w){
			iz=w.iz->kopija();
			naredbe=w.naredbe->kopija();
		}
		~repeatUntil();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		izraz* iz;
		naredba* naredbe;
};

class forTo:public naredba{
	public:
		forTo(string str,izraz* iz1,izraz* iz2, naredba* nar):s(str),i1(iz1->kopija()),i2(iz2->kopija()),nr(nar->kopija())
		{}
		forTo(const forTo& f){
			s=f.s;
			i1=f.i1->kopija();
			i2=f.i2->kopija();
			nr=f.nr->kopija();
		}
		~forTo();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		string s;
		izraz* i1;
		izraz* i2;
		naredba* nr;
};
class procedura:public naredba{
	public:
		procedura(string s,vector<izraz*>i):id(s)
		{	
			args.resize(0);
			for(auto e:i)
				args.push_back(e->kopija());
		}
		procedura(const procedura& p){
			id=p.id;
			args.resize(0);
			for(auto e:p.args)
				args.push_back(e->kopija());
		}
		~procedura();
		void dodela();
		bool provera(int i)const;
		naredba* kopija()const;
		Value* codegen()const;
	private:
		string id;
		vector<izraz*> args;
};

class subprogram{
	public:
		virtual ~subprogram()
		{}
		virtual naredba* kod()const=0;
		virtual vector<pair<string,tip*>> argumenti() const=0;
		virtual void postaviTelo(naredba* t){}
		virtual tip* Tip(){return NULL;}
		virtual bool unos()const=0;
		virtual bool provera()const=0;
		virtual void dodela(){}
		virtual subprogram* kopija()const=0;
		virtual Function* codegen()const=0;
};
class funkcijaDekl:public subprogram{
	public:
		funkcijaDekl(string s,vector<pair<string,tip*>> v,tip* t):id(s),tp(t->kopija())
		{args.resize(0);
		for(auto e:v)
			args.push_back(pair<string,tip*>(e.first,e.second->kopija()));
		}
		funkcijaDekl(const funkcijaDekl& fd){
			id=fd.id;
			tp=fd.tp->kopija();
			args.resize(0);
			for(auto e:fd.args)
				args.push_back(pair<string,tip*>(e.first,e.second->kopija()));	
		}
		~funkcijaDekl();
		naredba* kod()const{
			return NULL;}
		vector<pair<string,tip*>> argumenti() const{
			return args;
		}
		void postaviTelo(naredba* t){
			cout<<"ovo je samo deklaracija za funkciju "<< id <<", nema telo"<<endl;
			exit(EXIT_FAILURE);}
		tip* Tip(){return tp;}
		bool unos()const;
		bool provera()const;
		void dodela();
		subprogram* kopija()const;
		Function* codegen()const;
		
	protected:
		string id;
		vector<pair<string,tip*>> args;
		tip* tp;
};
class funkcija:public funkcijaDekl{
public:
    funkcija(string s,vector<pair<string,tip*>> v,tip* t,map<string,tip*> vr,naredba* i): funkcijaDekl(s,v,t), telo(i->kopija())
		{
			for(std::map<string,tip*>::const_iterator e=vr.begin();e!=vr.end();e++){
				if(vars.find(e->first)!=vars.end()){
					cout<<"vec postoji promenljiva "<<e->first<<endl;
					exit(EXIT_FAILURE);
				}
				vars[e->first]=e->second->kopija();
			}
			mapmaker(&vars,&args);
			if(vars.find(id)==vars.end())
				vars[id]=tp->kopija();
			else
				yyerror("vec postoji lokalna promenljiva "+id);
		}
		funkcija(const funkcija& fa):funkcijaDekl(fa){
			telo=fa.telo->kopija();
			for(std::map<string,tip*>::const_iterator e=fa.vars.begin();e!=fa.vars.end();e++){
				if(vars.find(e->first)!=vars.end()){
					cout<<"vec postoji promenljiva "<<e->first<<endl;
					exit(EXIT_FAILURE);
				}
				vars[e->first]=e->second->kopija();
			}
		}
		~funkcija();
		naredba* kod()const{
			return telo;}
		void postaviTelo(naredba* t){
			telo=t;
		}
		tip* Tip(){return tp;}
		bool unos()const;
		bool provera()const;
		void dodela();
		subprogram* kopija()const;
		Function* codegen()const;
	private:
		map<string,tip*> vars;
		naredba* telo;
};
class procedurDekl:public subprogram{
	public:
		procedurDekl(string s, vector<pair<string,tip*>> v):id(s)
		{args.resize(0);
		for(auto e:v)
			args.push_back(pair<string,tip*>(e.first,e.second->kopija()));
		}
		procedurDekl(const procedurDekl& fd){
			id=fd.id;
			args.resize(0);
			for(auto e:fd.args)
				args.push_back(pair<string,tip*>(e.first,e.second->kopija()));	
		}
		~procedurDekl();
		naredba* kod()const{
			return NULL;}
		vector<pair<string,tip*>> argumenti() const{
			return args;
		}
		void postaviTelo(naredba* t){
			cout<<"ovo je samo deklaracija za proceduru "<< id <<", nema telo"<<endl;
			exit(EXIT_FAILURE);}
		bool unos()const;
		bool provera()const;
		void dodela();
		subprogram* kopija()const;
		Function* codegen()const;
	protected:
		string id;
		vector<pair<string,tip*>> args;
};
class procedur:public procedurDekl{
	public:
		procedur(string s, vector<pair<string,tip*>> v,	map<string,tip*> vr,naredba* i):procedurDekl(s,v),telo(i->kopija())
		{
			for(std::map<string,tip*>::const_iterator e=vr.begin();e!=vr.end();e++){
				if(vars.find(e->first)!=vars.end()){
					cout<<"vec postoji promenljiva "<<e->first<<endl;
					exit(EXIT_FAILURE);
				}
				vars[e->first]=e->second->kopija();
			}
			mapmaker(&vars,&args);
		}
		procedur(const procedur& fa):procedurDekl(fa){
			telo=fa.telo->kopija();
			for(std::map<string,tip*>::const_iterator e=fa.vars.begin();e!=fa.vars.end();e++){
				if(vars.find(e->first)!=vars.end()){
					cout<<"vec postoji promenljiva "<<e->first<<endl;
					exit(EXIT_FAILURE);
				}
				vars[e->first]=e->second->kopija();
			}
		}
		~procedur();
		naredba* kod()const{
			return telo;}
		void postaviTelo(naredba* t){
			telo=t;
		}
		bool unos()const;
		bool provera()const;
		void dodela();
		subprogram* kopija()const;
		Function* codegen()const;
	private:
		map<string,tip*>vars;
		naredba* telo;
};

class Glavno{
	public:
		Glavno(string s,vector<pair<string,tip*>> pr,vector<subprogram*> funk,vector<subprogram*> proc,naredba* n):naziv(s),telo(n->kopija())
		{
			prom.resize(0);
			for(auto e:pr)
				prom.push_back(pair<string,tip*>(e.first,e.second->kopija()));
			fje.resize(0);
			for(auto e:funk)
				fje.push_back(e->kopija());
			procedure.resize(0);
			for(auto e:proc)
				procedure.push_back(e->kopija());
		}
		~Glavno();
		bool provera()const;
		Value* codegen()const;
	private:
		string naziv;
		vector<pair<string,tip*>> prom;
		vector<subprogram*> fje;
		vector<subprogram*> procedure;
		naredba* telo;
};
#endif
