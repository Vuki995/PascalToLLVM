#include"tipovi.hpp"
using namespace std;



tip* Int::kopija()const{
return new Int(*this);
}

tip* Float::kopija()const{
return new Float(*this);
}

tip* Char::kopija()const{
return new Char(*this);
}

tip* String::kopija()const{
return new String(*this);
}

tip* Pointer::kopija()const{
return new Pointer(*this);
}

tip* Array::kopija()const{
return new Array(*this);
}

tip* Tmp::kopija()const{
	return new Tmp(*this);
}

tip* Bool::kopija()const{
	return new Bool(*this);
}

tip* Struct::kopija()const{
	return new Struct(*this);
}

string Int::naziv()const{
return "int";}

string Float::naziv()const{
return "float";}

string Char::naziv()const{
return "char";}

string String::naziv()const{
return "string";}

string Array::naziv()const{
return "array";}

string Pointer::naziv()const{
return "pointer";}

string Tmp::naziv()const{
return "void";}

string Bool::naziv()const{
return "bool";}

string Struct::naziv()const{
return "struct";
}

bool Int::poredi( tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
return true;
}

bool Float::poredi( tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
return true;
}

bool Char::poredi( tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
return true;
}

bool String::poredi( tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
return true;
}

bool Array::poredi( tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
if(((*this).pocetak()!=t->pocetak())||((*this).kraj()!=t->kraj()))
	return false;
return mem->poredi(t->sledeci());
}

bool Pointer::poredi( tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
return mem->poredi(t->sledeci());
}

bool Tmp::poredi(tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
return true;
}

bool Bool::poredi(tip* t)const{
if(t==NULL)
	return false;
if((*this).naziv()!=t->naziv())
	return false;
return true;
}

bool Struct::poredi(tip* t)const{
if(t==NULL)
	return false;
if(naziv()!=t->naziv())
	return false;
if(getinit()!=t->getinit())
	return false;
unsigned u=tps.size();
for(unsigned i=0;i<u;i++){
	pair<string,tip*> st=t->iter(i);
	if(st.first!=tps[i].first)
		return false;
	if(!(st.second->poredi(tps[i].second)))
		return false;
}
return true;
}

void alokacija(tip* a,tip* b,tip* s){ //dokle god oba dva pokazuju na pointere, u levom se init vrednost postavlja na 1
	tip* tmp1=s;
	tip* tmp2=b;
	while(!tmp1->poredi(a)&&tmp1->naziv()!="struct"){
		tmp1=tmp1->sledeci();
	}
	while(tmp1->naziv()=="pointer"&&tmp2->naziv()=="pointer"&&tmp2->getinit()==1){
		tmp1->setinit(1);
		tmp1=tmp1->sledeci();
		tmp2=tmp2->sledeci();
	}
	tmp1=NULL;
	tmp2=NULL;
}


/*--------------codegen----------------*/

Type* Int::codegen()const{
	return Type::getInt32Ty(TheContext);
}

Type* Float::codegen()const{
	return Type::getFloatTy(TheContext);
}

Type* Char::codegen()const{
	return Type::getInt8Ty(TheContext);
}

Type* String::codegen()const{
	return ArrayType::get(Type::getInt8Ty(TheContext),i+1);
}

Type* Pointer::codegen()const{
	return PointerType::get(mem->codegen(),0);
}

Type* Array::codegen()const{
	return ArrayType::get(mem->codegen(),end-start);
}

Type* Bool::codegen()const{
	return Type::getInt1Ty(TheContext);
}

Type* Tmp::codegen()const{
	return NULL;
}
Type* Struct::codegen()const{
	if(struk.find(ime)==struk.end()){
		StructType* tmp=StructType::create(TheContext,ime);
		vector<Type*>clanovi;
		for(auto a:tps){
			clanovi.push_back(a.second->codegen());
		}
		tmp->setBody(clanovi);
		struk[ime]=tmp;
		return tmp;
	}
	return struk[ime];
}





