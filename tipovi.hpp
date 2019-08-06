#ifndef __tp__
#define __tp__
#include<iostream>
#include<string>
#include<map>
#include"codegen.hpp"
using namespace std;
using namespace llvm;
class tip{
     public:
	virtual ~tip()
	{}
	virtual tip* kopija()const=0;
	virtual string naziv()const=0;
	virtual bool poredi( tip* t)const=0;
	virtual int pocetak()const{return 0;}
	virtual int kraj()const{return 0;}
	virtual int getinit()const{return 1;}
	virtual void setinit(int i){return;}
	virtual void setime(string s){return;}//postavlja novo ime strukture
	virtual tip* sledeci()const{return NULL;}
	virtual pair<string,tip*> iter(int i)const{ pair<string,tip*> ad; return ad;}
	virtual Type* codegen()const=0;
	virtual bool alocirano(tip* a)const{return true;}//provera da li pointeri pokazuju negde,sve ostale vracaju true, koristi za dodelu
};
class Int:public tip{
	public:
		tip* kopija()const;
		string naziv()const;
		bool poredi( tip* t)const;
		Type* codegen()const;
		~Int(){}
};
class Float:public tip{
	public:
		tip* kopija()const;
		string naziv()const;
		bool poredi( tip* t)const;
		Type* codegen()const;
		~Float(){}
};
class Char:public tip{
	public:
		tip* kopija()const;
		string naziv()const;
		int getinit()const{
			return 1;
		}
		bool poredi( tip* t)const;
		Type* codegen()const;
		~Char(){}
};
class String:public tip{
	public:
		String(int n):i(n)
		{}
		String(const String& s){
			i=s.i;
		}
		int getinit()const{
			return i;
		}
		void setinit(int n){
			i=n;
		}
		tip* kopija()const;
		string naziv()const;
		bool poredi( tip* t)const;
		Type* codegen()const;
		~String(){}
	private:
		unsigned i;
};
class Pointer: public tip{
	public:
		Pointer(tip* m):mem(m->kopija())
		{}
		~Pointer()
		{delete mem;}
		Pointer(const Pointer& p){
			mem=p.mem->kopija();
			init=p.init;
		}
		tip* kopija()const;
		string naziv()const;
		tip* sledeci()const{
			return mem;
		}
		int getinit()const{
			return init;
		}
		void setinit(int a){
			init=a;
		}
		bool poredi( tip* t)const;
		bool alocirano(tip* a)const{//prolazi dok ne nadje poklapajuci tip, ako tokom pretrage init!=1 prijavljue gresku
			if(poredi(a))
				return true;
			if(init==0){
			cout<<"nije alocirano"<<endl;
			return false;}
			return mem->alocirano(a);
		}
		Type* codegen()const;
	private:
		tip* mem;
		int init=0;
};
class Array: public tip{
	public:
		Array(tip* m,int s,int e):mem(m->kopija()),start(s),end(e)
		{}
		~Array()
		{delete mem;}
		Array(const Array& a){
			mem=a.mem->kopija();
			start=a.start;
			end=a.end;
		}
		tip* kopija()const;
		string naziv()const;
		int pocetak()const{
			return start;
		}
		int kraj()const{
			return end;
		}
		tip* sledeci()const{
			return mem;
		}
		bool poredi( tip* t)const;
		Type* codegen()const;
	private:
		tip* mem;
		int start;
		int end;
};
class Tmp:public tip{
	public:
		tip* kopija()const;
		string naziv()const;
		bool poredi(tip* t)const;
		Type* codegen()const;
		~Tmp(){}

};
class Bool:public tip{
	public:
		tip* kopija()const;
		string naziv()const;
		bool poredi(tip* t)const;
		Type* codegen()const;
		~Bool(){}
};
class Struct:public tip{
	public:
		Struct(string s,vector<pair<string,tip*>> t):ime(s){
			tps.resize(0);
			for(auto a:t){
				pair<string,tip*> st(a.first,a.second->kopija());
				tps.push_back(st);
			}
			unsigned q=tps.size();
			for(unsigned i=0;i<q;i++){
				for(unsigned j=0;j<q;j++){
					if(tps[i].first==tps[j].first&&i!=j){
						cout<<"nazivi tipova u strukturi se poklapaju"<<endl;
						exit(EXIT_FAILURE);
					}						
				}
			}
		}
		Struct(const Struct& s){
			ime=s.ime;
			tps.resize(0);
			for(auto a:s.tps){
				pair<string,tip*> st(a.first,a.second->kopija());
				tps.push_back(st);
			}			
		}
		~Struct(){
			for(auto a:tps){
				delete a.second;
			}
		}
		int getinit()const{
			return tps.size();
		}
		pair<string,tip*> iter(int i)const{
			return tps[i];
		}
		tip* kopija()const;
		string naziv()const;
		void setime(string s){
			ime=s;
		}
		bool poredi( tip* t)const;
		Type* codegen()const;
	private:
		string ime;
		vector<pair<string,tip*>> tps;
};
#endif
