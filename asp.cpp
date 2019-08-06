#include"asp.hpp"
#include"naredbe.hpp"
extern map<string,izraz*> konstante;
extern map<string,pair<tip*,izraz*>> globalne;
extern map<string,subprogram*>funkcije;
extern stack<map<string,pair<tip*,izraz*>>> lokalne; 

cons::cons(int fn,tip* tp):i(fn),t(tp){
}
cons::cons(float fn,tip* tp):f(fn),t(tp){
}
cons::cons(char fn,tip* tp):c(fn),t(tp){
}
cons::cons(string fn,tip* tp):s(fn),t(tp){
}
cons::cons(bool fn,tip* tp):b(fn),t(tp){
}
cons::cons(const cons& x){
	t=x.t->kopija();
	i=x.i;
	f=x.f;
	c=x.c;
	s=x.s;
	b=x.b;
}
prom::prom(string s,tip* t):ime(s),tp(t){
}

prom::prom(const prom& p){
	ime=p.ime;
	tp=p.tp->kopija();
}

cons::~cons(){
	delete t;
}
prom::~prom(){
	delete tp;
}

poziv::poziv(const poziv& p):operacija(p){
	str=p.str;
	tp=p.tp->kopija();
}
poziv::~poziv(){
	delete tp;
}
struktura::struktura(const struktura& s):operacija(s){
	str=s.str;
}
/*ispis metode vracaju "--" ako nisu promenljive ili ime promenljive ako jesu, array, pointer, adresa i struktura radi rekurzivni poziv
svrha je provera da li je izraz neka memorisana vrednost ili ne i koji joj je id (koristi se za @ i dodelu)*/
string cons::ispis()const{ 
	return "--";
}

string prom::ispis()const{
	return ime;
}

string zbir::ispis()const{
	return "--";
}

string razlika::ispis()const{
	return "--";
}

string proizvod::ispis()const{
	return "--";
}

string kolicnik::ispis()const{
	return "--";
}

string BitAnd::ispis()const{
	return "--";
}

string BitOr::ispis()const{
	return "--";
}

string BitNot::ispis()const{
	return "--";
}

string eq::ispis()const{
	return "--";
}

string neq::ispis()const{
	return "--";
}

string grtr::ispis()const{
	return "--";
}

string lss::ispis()const{
	return "--";
}

string And::ispis()const{
	return "--";
}

string Orr::ispis()const{
	return "--";
}

string Not::ispis()const{
	return "--";
}

string poziv::ispis()const{
	return "--";
}

string Niz::ispis()const{
	return niz[0]->ispis();
}

string pokazivac::ispis()const{
	return niz[0]->ispis();
}

string adresa::ispis()const{
	return niz[0]->ispis();
}

string struktura::ispis()const{
	return niz[0]->ispis();
}

izraz* cons::kopija() const{
	return new cons(*this);
}

izraz* prom::kopija() const{
	return new prom(*this);
}

izraz* zbir::kopija() const{
	return new zbir(*this);
}

izraz* razlika::kopija() const{
	return new razlika(*this);
}

izraz* proizvod::kopija() const{
	return new proizvod(*this);
}

izraz* kolicnik::kopija() const{
	return new kolicnik(*this);
}

izraz* BitAnd::kopija() const{
	return new BitAnd(*this);
}

izraz* BitOr::kopija() const{
	return new BitOr(*this);
}

izraz* BitNot::kopija() const{
	return new BitNot(*this);
}

izraz* grtr::kopija() const{
	return new grtr(*this);
}

izraz* lss::kopija() const{
	return new lss(*this);
}

izraz* eq::kopija() const{
	return new eq(*this);
}

izraz* neq::kopija() const{
	return new neq(*this);
}

izraz* And::kopija() const{
	return new And(*this);
}

izraz* Orr::kopija() const{
	return new Orr(*this);
}

izraz* Not::kopija() const{
	return new Not(*this);
}

izraz* poziv::kopija() const{
	return new poziv(*this);
}

izraz* Niz::kopija() const{
	return new Niz(*this);
}

izraz* pokazivac::kopija() const{
	return new pokazivac(*this);
}

izraz* adresa::kopija() const{
	return new adresa(*this);
}

izraz* struktura::kopija()const{
	return new struktura(*this);
}
/*-------------semanticka provera---------------------*/

/*---dodela tipova promenljivama---*/

void cons::dodela(){
return;
}

void prom::dodela(){
	if(globalne.find(ime)!=globalne.end()){
		delete tp;
		tp=globalne[ime].first->kopija();
		return;
	}
	if(lokalne.size()>0&&(lokalne.top().find(ime)!=lokalne.top().end())){
		delete tp;
		tp=(lokalne.top())[ime].first->kopija();
		return;
	}
	cout<<"ne postoji ta promenljiva "<<ime<<"dodela"<<endl;
	exit(EXIT_FAILURE);
}

void operacija::dodela(){
	for(auto args:niz)
		args->dodela();
	return;
}
void poziv::dodela(){
	if(funkcije.find(str)==funkcije.end()){
		cout<<"ne postoji funkcija "<<str<<endl;
		exit(EXIT_FAILURE);
	}
	if(funkcije[str]->Tip()==NULL){
		cout<<"ovo je procedura "<<str<<endl;
		exit(EXIT_FAILURE);
	}
	if(funkcije[str]->kod()==NULL){
		cout<<"ova funkcija nema telo"<<endl;
		exit(EXIT_FAILURE);
	}
	operacija::dodela();
	delete tp;
	tp=funkcije[str]->Tip()->kopija();

}
/*---provera tipova citavog programa---*/

tip* cons::provera()const{
	return t->kopija();
}

tip* prom::provera()const{ //gleda da li je negde sacuvana promenljiva i vraca njen tip
	if(tp->naziv()!="void")
		return tp->kopija();
	if(globalne.find(ime)!=globalne.end()){
		return globalne[ime].first->kopija();
	}
	if(lokalne.size()>0&&(lokalne.top().find(ime)!=lokalne.top().end())){
		return (lokalne.top())[ime].first->kopija();
	}
	cout<<"ne postoji ta promenljiva "<<ime<<" provera"<<endl;
	exit(EXIT_FAILURE);
}

tip* zbir::provera()const{//poredi tipove i vraca kompatibilne
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	if(s1=="int"&&s2=="int"){
		delete t2;
		return t1;
		}
	if(s1=="float"&&s2=="float"){
		delete t2;
		return t1;
		}
	if((s1=="int"&&s2=="float")||(s1=="float"&&s2=="int")){
			if(s1=="float"){
				delete t2;
				return t1;
			}
			if(s2=="float"){
				delete t1;
				return t2;
			}
		}
	cout<<"pogresni tipovi za + :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* razlika::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	if(s1=="int"&&s2=="int"){
		delete t2;
		return t1;
		}
	if(s1=="float"&&s2=="float"){
		delete t2;
		return t1;
		}
	if((s1=="int"&&s2=="float")||(s1=="float"&&s2=="int")){
			if(s1=="float"){
				delete t2;
				return t1;
			}
			if(s2=="float"){
				delete t1;
				return t2;
			}
		}
	cout<<"pogresni tipovi za - :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* proizvod::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	if(s1=="int"&&s2=="int"){
		delete t2;
		return t1;
		}
	if(s1=="float"&&s2=="float"){
		delete t2;
		return t1;
		}
	if((s1=="int"&&s2=="float")||(s1=="float"&&s2=="int")){
			if(s1=="float"){
				delete t2;
				return t1;
			}
			if(s2=="float"){
				delete t1;
				return t2;
			}
		}
	cout<<"pogresni tipovi za * :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* kolicnik::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	if(s1=="int"&&s2=="int"){
		delete t2;
		return t1;
		}
	if(s1=="float"&&s2=="float"){
		delete t2;
		return t1;
		}
	if((s1=="int"&&s2=="float")||(s1=="float"&&s2=="int")){
			if(s1=="float"){
				delete t2;
				return t1;
			}
			if(s2=="float"){
				delete t1;
				return t2;
			}
		}
	cout<<"pogresni tipovi za / :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* BitAnd::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	tip* tmp=new Int();
	if((s1=="int"||s1=="bool")&&(s2=="int"||s2=="bool")){
		delete t1;
		delete t2;
		return tmp;
		}
	cout<<"pogresni tipovi za bitand ,treba int ili bool"<<endl;
	exit(EXIT_FAILURE);
	
}

tip* BitOr::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	tip* tmp=new Int();
	if((s1=="int"||s1=="bool")&&(s2=="int"||s2=="bool")){
		delete t1;
		delete t2;
		return tmp;
		}
	cout<<"pogresni tipovi za bitand ,treba int ili bool"<<endl;
	exit(EXIT_FAILURE);
	
}

tip* BitNot::provera()const{
	tip* t1=niz[0]->provera();
	string s1=t1->naziv();
	if(s1=="int"||s1=="bool"){
		return t1;
		}
	cout<<"pogresni tipovi za bitand ,treba int ili bool"<<endl;
	exit(EXIT_FAILURE);
	
}

tip* grtr::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	tip* tmp=new Bool();
	if((s1=="int"||s1=="float")&&(s2=="int"||s2=="float")){
		delete t1;
		delete t2;
		return tmp;
		}
	if(s2=="bool"&&s2=="bool"){
		delete t1;
		delete t2;
		return tmp;
		}
	cout<<"pogresni tipovi za > :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* lss::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	tip* tmp=new Bool();
	if((s1=="int"||s1=="float")&&(s2=="int"||s2=="float")){
		delete t1;
		delete t2;
		return tmp;
		}
	if(s1=="bool"&&s2=="bool"){
		delete t1;
		delete t2;
		return tmp;
		}
	cout<<"pogresni tipovi za < :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* eq::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	tip* tmp=new Bool();
	if((s1=="int"||s1=="float")&&(s2=="int"||s2=="float")){
		delete t1;
		delete t2;
		return tmp;
		}
	if(s1=="bool"&&s2=="bool"){
		delete t1;
		delete t2;
		return tmp;
		}
	cout<<"pogresni tipovi za = :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* neq::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	tip* tmp=new Bool();
	if((s1=="int"||s1=="float")&&(s2=="int"||s2=="float")){
		delete t1;
		delete t2;
		return tmp;
		}
	if(s1=="bool"&&s2=="bool"){
		delete t1;
		delete t2;
		return tmp;
		}
	cout<<"pogresni tipovi za <> :"<<s1<<" i "<<s2<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* And::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	tip* tmp=new Bool();
	if((s1=="int"||s1=="float"||s1=="bool")&&(s2=="int"||s2=="float"||s2=="bool")){
		delete t1;
		delete t2;
		return tmp;
	}
	cout<<"pogresni tipovi za AND :"<<t1->naziv()<<" i "<<t2->naziv()<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* Orr::provera()const{
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	tip* tmp=new Bool();
	if((t1->naziv()=="int"||t1->naziv()=="float"||t1->naziv()=="bool")&&(t2->naziv()=="int"||t2->naziv()=="float"||t2->naziv()=="bool")){
		delete t1;
		delete t2;
		return tmp;
	}
	cout<<"pogresni tipovi za OR :"<<t1->naziv()<<" i "<<t2->naziv()<<" nisu kompatibilni"<<endl;
	exit(EXIT_FAILURE);
}

tip* Not::provera()const{
	tip* t1=niz[0]->provera();
	tip* tmp=new Bool();
	if(t1->naziv()=="int"||t1->naziv()=="float"||t1->naziv()=="bool"){
		delete t1;
		return tmp;
	}
	cout<<"pogresni tip za NOT : "<<t1->naziv()<<endl;
	exit(EXIT_FAILURE);
}

/*poziv funkcije, provera da li postoji, da li ima tip, kod i argumente*/
tip* poziv::provera()const{
	if(tp->naziv()!="void")
		return tp->kopija();
	if(funkcije.find(str)==funkcije.end()){
		cout<<"ne postoji funkcija "<<str<<endl;
		exit(EXIT_FAILURE);
	}
	if(funkcije[str]->Tip()==NULL){
		cout<<"ovo je procedura "<<str<<endl;
		exit(EXIT_FAILURE);
	}
	if(funkcije[str]->kod()==NULL){
		cout<<"ova funkcija nema telo"<<endl;
		exit(EXIT_FAILURE);
	}
	if(funkcije[str]->argumenti().size()!=niz.size()){
		cout<<"pogresan broj argumenata: "<<funkcije[str]->argumenti().size()<<"!="<<niz.size()<<endl;
		exit(EXIT_FAILURE);
	}
	unsigned t=niz.size();
	for(unsigned i=0;i<t;i++){
		tip* tmp=niz[i]->provera();
		if(!((funkcije[str]->argumenti())[i].second->poredi(tmp))){
			cout<<"pogresan tip argumenta"<<endl;
			exit(EXIT_FAILURE);
		}
		delete tmp;
	}
	return funkcije[str]->Tip()->kopija();
}
/*izvlacenje vrednosti niza, posto ako se trazi [] za neki izraz, ocekuje se da mu je tip array, zato se vraca tip sledeceg (tj tip elementa niza) jer kad kaze a=b[i], a ne dobije vrednost array vec vrednost elementa na i*/
tip* Niz::provera()const{
	tip* t1=niz[1]->provera();
	tip* t0=niz[0]->provera();
	string tmp=t1->naziv();
		if(tmp!="int"){
			cout<<"nije int tip za array"<<endl;
			exit(EXIT_FAILURE);
		}
		tmp=t0->naziv();
		if(tmp!="array"){
			cout<<"nije dobar tip podataka za array"<<endl;
			exit(EXIT_FAILURE);	
		}	
	delete t1;
	t1=t0->sledeci()->kopija();
	delete t0;
	return t1;
}
tip* pokazivac::provera()const{
		tip* tmp=niz[0]->provera();
		if((tmp->naziv())!="pointer"){
			cout<<"nije dobar tip podataka za pointer"<<endl;
			exit(EXIT_FAILURE);	
		}
	tip* tmp2=tmp->sledeci()->kopija();
	delete tmp;
	return tmp2;
}
/*vraca pointer tip koji pokazuje na tip izraza, ispis je funkcija koja vraca ime promenljive, ako ne postoji samo jedna promenljiva onda je to problem jer ne postoji memorijska adresa koju treba proslediti*/
tip* adresa::provera()const{
	if((ispis())=="--"){
		cout<<"mora da bude sacuvana informacija (promenljiva)"<<endl;
		exit(EXIT_FAILURE);
	}
	tip* tmp1=niz[0]->provera();
	tip* tmp=tmp1->kopija();
	delete tmp1; 
	tmp1=new Pointer(tmp);
	delete tmp;
	tmp1->setinit(1);
	return tmp1;
}

tip* struktura::provera()const{
	tip* tmp=niz[0]->provera();
		if((tmp->naziv())!="struct"){
			cout<<"nije dobar tip podataka za strukturu"<<endl;
			exit(EXIT_FAILURE);	
		}
	tip* tmp2;
	int t=tmp->getinit();
	for(int i=0;i<t;i++){
		pair<string,tip*> st=tmp->iter(i);
		if(st.first==str){
			tmp2=st.second->kopija();
			delete tmp;
			return tmp2;
		}
	}
	cout<<"nepostojeci element strukture"<<endl;
	exit(EXIT_FAILURE);
	return tmp;
}

/*----------codegen---------------*/

Value* cons::codegen()const{
	if(t->naziv()=="int"){
		return ConstantInt::get(TheContext,APInt(32,i));}
	if(t->naziv()=="float")
		return ConstantFP::get(TheContext,APFloat(f));
	if(t->naziv()=="char")
		return ConstantInt::get(TheContext,APInt(8,(int)c));
	if(t->naziv()=="bool")
		return ConstantInt::get(TheContext,APInt(1,b?1:0));
	if(t->naziv()=="string"){
		Value* str=tekst[s]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr(s,"str",0);
			tekst[s]=str;
		}
		return str;
	} 
	return nullptr;
}

Value* prom::codegen()const{
	Value* tmp=nullptr;
	if(lok.find(ime)!=lok.end())
		tmp=lok[ime];
	else {
		tmp=glob[ime];
	}
	if(tmp==nullptr)
		yyerror("promenljiva "+ ime+" nije definisana");
	return tmp;
}

Value* zbir::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	l=AorP(l);
	d=AorP(d);
	if(t1->naziv()=="int"&&t2->naziv()=="int"){
		delete t1;
		delete t2;
		return Builder.CreateAdd(l,d,"addtmp");
	}
	if(t1->naziv()=="int"){
		l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
	} 
	if(t2->naziv()=="int"){
		d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
	} 
	delete t1;
	delete t2;
	return Builder.CreateFAdd(l,d,"addtmp");
}

Value* razlika::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	l=AorP(l);
	d=AorP(d);
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	if(t1->naziv()=="int"&&t2->naziv()=="int"){
		delete t1;
		delete t2;
		return Builder.CreateSub(l,d,"subtmp");
	}
	if(t1->naziv()=="int"){
		l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
	} 
	if(t2->naziv()=="int"){
		d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
	} 
	delete t1;
	delete t2;
	return Builder.CreateFSub(l,d,"subtmp");
}

Value* proizvod::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	l=AorP(l);
	d=AorP(d);
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	if(t1->naziv()=="int"&&t2->naziv()=="int"){
		delete t1;
		delete t2;
		return Builder.CreateMul(l,d,"multmp");
	}
	if(t1->naziv()=="int"){
		l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
	} 
	if(t2->naziv()=="int"){
		d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
	} 
	delete t1;
	delete t2;
	return Builder.CreateFMul(l,d,"multmp");
}

Value* kolicnik::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	l=AorP(l);
	d=AorP(d);
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	if(t1->naziv()=="int"&&t2->naziv()=="int"){
		delete t1;
		delete t2;
		return Builder.CreateSDiv(l,d,"divtmp");
	}
	if(t1->naziv()=="int"){
		l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
	} 
	if(t2->naziv()=="int"){
		d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
	} 
	delete t1;
	delete t2;
	return Builder.CreateFDiv(l,d,"divtmp");
}

Value* BitAnd::codegen()const{
	Value* l=niz[0]->codegen();
	Value* r=niz[1]->codegen();
	if(l==nullptr||r==nullptr)
		return nullptr;
	l=AorP(l);
	r=AorP(r);
	tip* tmp=niz[0]->provera();
	if(tmp->naziv()=="bool")
		l=Builder.CreateZExt(l,Type::getInt32Ty(TheContext),"booltoint");
	delete tmp;
	tmp=niz[1]->provera();
	if(tmp->naziv()=="bool")
		r=Builder.CreateZExt(r,Type::getInt32Ty(TheContext),"booltoint");
	delete tmp;
	l=Builder.CreateAnd(l,r,"bitandtmp");
	return l;
}

Value* BitOr::codegen()const{
	Value* l=niz[0]->codegen();
	Value* r=niz[1]->codegen();
	if(l==nullptr||r==nullptr)
		return nullptr;
	l=AorP(l);
	r=AorP(r);
	tip* tmp=niz[0]->provera();
	if(tmp->naziv()=="bool")
		l=Builder.CreateZExt(l,Type::getInt32Ty(TheContext),"booltoint");
	delete tmp;
	tmp=niz[1]->provera();
	if(tmp->naziv()=="bool")
		r=Builder.CreateZExt(r,Type::getInt32Ty(TheContext),"booltoint");
	delete tmp;
	l=Builder.CreateOr(l,r,"bitortmp");
	return l;
}

Value* BitNot::codegen()const{
	Value* v=niz[0]->codegen();
	if (v==nullptr)
		return nullptr;
	v=AorP(v);
	tip* tmp=niz[0]->provera();
	if(tmp->naziv()=="bool")
		v=Builder.CreateZExt(v,Type::getInt32Ty(TheContext),"booltoint");
	v=Builder.CreateNot(v,"bitnottmp");
	delete tmp;
	return v;
}

Value* eq::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	l=AorP(l);
	d=AorP(d);
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	if((t1->naziv()=="int"&&t2->naziv()=="int")||(t1->naziv()=="bool"&&t2->naziv()=="bool")){
		delete t1;
		delete t2;
		return Builder.CreateICmpEQ(l,d,"eqtmp");
	}
	if(t1->naziv()=="float"||t2->naziv()=="float"){
		if(t1->naziv()=="int")
			l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
		if(t2->naziv()=="int")
			d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
		delete t1;
		delete t2;
		return Builder.CreateFCmpUEQ(l,d,"eqtmp");
	}
	return nullptr;
}


Value* neq::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	l=AorP(l);
	d=AorP(d);
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	if((t1->naziv()=="int"&&t2->naziv()=="int")||(t1->naziv()=="bool"&&t2->naziv()=="bool")){
		delete t1;
		delete t2;
		return Builder.CreateICmpNE(l,d,"neqtmp");
	}
	if(t1->naziv()=="float"||t2->naziv()=="float"){
		if(t1->naziv()=="int")
			l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
		if(t2->naziv()=="int")
			d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
		delete t1;
		delete t2;
		return Builder.CreateFCmpUNE(l,d,"neqtmp");
	}
	return nullptr;
}

Value* lss::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	l=AorP(l);
	d=AorP(d);
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	if((t1->naziv()=="int"&&t2->naziv()=="int")||(t1->naziv()=="bool"&&t2->naziv()=="bool")){
		delete t1;
		delete t2;
		return Builder.CreateICmpSLT(l,d,"lsstmp");
	}
	if(t1->naziv()=="float"||t2->naziv()=="float"){
		if(t1->naziv()=="int")
			l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
		if(t2->naziv()=="int")
			d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
		delete t1;
		delete t2;
		return Builder.CreateFCmpULT(l,d,"lsstmp");
	}
	return nullptr;
}

Value* grtr::codegen()const{
	Value* l=niz[0]->codegen();
	Value* d=niz[1]->codegen();
	if(l==nullptr||d==nullptr)
		return nullptr;
	l=AorP(l);
	d=AorP(d);
	tip* t1=niz[0]->provera();
	tip* t2=niz[1]->provera();
	if((t1->naziv()=="int"&&t2->naziv()=="int")||(t1->naziv()=="bool"&&t2->naziv()=="bool")){
		delete t1;
		delete t2;
		return Builder.CreateICmpSGT(l,d,"grtrtmp");
	}
	if(t1->naziv()=="float"||t2->naziv()=="float"){
		if(t1->naziv()=="int")
			l=Builder.CreateSIToFP(l,Type::getFloatTy(TheContext),"conv");
		if(t2->naziv()=="int")
			d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");
		delete t1;
		delete t2;
		return Builder.CreateFCmpUGT(l,d,"grtrtmp");
	}
	return nullptr;
}

Value* And::codegen()const{
	Value* l=niz[0]->codegen();//kod za levu stranu
	BasicBlock* parent=Builder.GetInsertBlock();
	Function* TheFunction=parent->getParent();
	BasicBlock* TrueBB=BasicBlock::Create(TheContext,"TrueAnd");
	BasicBlock* AfterBB=BasicBlock::Create(TheContext,"AfterAnd");
	
	l=AorP(l);
	tip* tmp=niz[0]->provera();
	if(tmp->naziv()=="float")
		l=Builder.CreateFCmpONE(l,ConstantFP::get(TheContext,APFloat(0.0)),"floatcmp");
	if(tmp->naziv()=="int")
		l=Builder.CreateICmpNE(l,ConstantInt::get(TheContext,APInt(32,0)),"inttmp");
	delete tmp;
	Builder.CreateCondBr(l,TrueBB,AfterBB);

	TheFunction->getBasicBlockList().push_back(TrueBB);
	Builder.SetInsertPoint(TrueBB);
	TrueBB=Builder.GetInsertBlock();

	Value* r=niz[1]->codegen();
	if(r==nullptr)
		return nullptr;
	r=AorP(r);
	tmp=niz[1]->provera();
	if(tmp->naziv()=="float")
		r=Builder.CreateFCmpONE(r,ConstantFP::get(TheContext,APFloat(0.0)),"floatcmp");
	if(tmp->naziv()=="int")
		r=Builder.CreateICmpNE(r,ConstantInt::get(TheContext,APInt(32,0)),"inttmp");
	Builder.CreateBr(AfterBB);

	TheFunction->getBasicBlockList().push_back(AfterBB);
	Builder.SetInsertPoint(AfterBB);
	
	PHINode* pn=Builder.CreatePHI(Type::getInt1Ty(TheContext),2,"andtmp");
	pn->addIncoming(ConstantInt::get(TheContext,APInt(1,0)),parent);
	pn->addIncoming(r,TrueBB);
	return pn;
}

Value* Orr::codegen()const{
	Value* l=niz[0]->codegen();//kod za levu stranu
	BasicBlock* parent=Builder.GetInsertBlock();
	Function* TheFunction=parent->getParent();
	BasicBlock* FalseBB=BasicBlock::Create(TheContext,"FalseOr");
	BasicBlock* AfterBB=BasicBlock::Create(TheContext,"AfterOr");
	
	l=AorP(l);
	tip* tmp=niz[0]->provera();
	if(tmp->naziv()=="float")
		l=Builder.CreateFCmpONE(l,ConstantFP::get(TheContext,APFloat(0.0)),"floatcmp");
	if(tmp->naziv()=="int")
		l=Builder.CreateICmpNE(l,ConstantInt::get(TheContext,APInt(32,0)),"inttmp");
	delete tmp;
	Builder.CreateCondBr(l,AfterBB,FalseBB);

	TheFunction->getBasicBlockList().push_back(FalseBB);
	Builder.SetInsertPoint(FalseBB);
	FalseBB=Builder.GetInsertBlock();

	Value* r=niz[1]->codegen();
	if(r==nullptr)
		return nullptr;
	r=AorP(r);
	tmp=niz[1]->provera();
	if(tmp->naziv()=="float")
		r=Builder.CreateFCmpONE(r,ConstantFP::get(TheContext,APFloat(0.0)),"floatcmp");
	if(tmp->naziv()=="int")
		r=Builder.CreateICmpNE(r,ConstantInt::get(TheContext,APInt(32,0)),"inttmp");
	Builder.CreateBr(AfterBB);

	TheFunction->getBasicBlockList().push_back(AfterBB);
	Builder.SetInsertPoint(AfterBB);
	
	PHINode* pn=Builder.CreatePHI(Type::getInt1Ty(TheContext),2,"ortmp");
	pn->addIncoming(ConstantInt::get(TheContext,APInt(1,1)),parent);
	pn->addIncoming(r,FalseBB);
	return pn;
}

Value* Not::codegen()const{
	Value* v=niz[0]->codegen();
	if(v==nullptr)
		return nullptr;
	v=AorP(v);
	tip* tmp=niz[0]->provera();
	if(tmp->naziv()=="float")
		v=Builder.CreateFCmpONE(v,ConstantFP::get(TheContext,APFloat(0.0)),"floatcmp");
	if(tmp->naziv()=="int")
		v=Builder.CreateICmpNE(v,ConstantInt::get(TheContext,APInt(32,0)),"inttmp");
	delete tmp;
	v=Builder.CreateXor(v,ConstantInt::get(TheContext,APInt(1,1)),"nottmp");
	if(v==nullptr)
		return nullptr;
	return v;
}

Value* poziv::codegen()const{
	Function* CalleeF=TheModule->getFunction(str);
	if(CalleeF==nullptr)
		yyerror("funkcija "+str+" ne postoji");
	vector<Value*> ArgsF;
	unsigned t=niz.size();
	for(unsigned i=0;i<t;i++){
		Value* tmp=niz[i]->codegen();
		tmp=AorP(tmp);
		ArgsF.push_back(tmp);
	}
	return Builder.CreateCall(CalleeF,ArgsF,"calltmp");
}

Value* Niz::codegen()const{
	Value* n=niz[0]->codegen();
	//n=Builder.CreateLoad(n);
	Value* i=niz[1]->codegen();
	i=AorP(i);
	i=Builder.CreateSExt(i,Type::getInt64Ty(TheContext),"tmpext");
	Value* ar[2]={ConstantInt::get(TheContext,APInt(64,0)),i};
	return Builder.CreateGEP(n,ar,"arraytmp");
}

Value* pokazivac::codegen()const{
	Value* tmp=niz[0]->codegen();
	return Builder.CreateLoad(tmp,"pointertmp");
}

Value* adresa::codegen()const{
	Value* tmp=niz[0]->codegen();
	if(tmp==nullptr)
		yyerror("promenljiva kojoj trazite adresu nije definisana");
	addr=true;
	return tmp;
}
Value* struktura::codegen()const{
	Value* tmp=niz[0]->codegen();
	tip* tp=niz[0]->provera();
	int t=tp->getinit();
	string s;
	int i;
	for(i=0;i<t;i++){
		s=tp->iter(i).first;
		if(s==str)
			break;
	}
	if(i==t){
		cout<<"nesta nije uspelo, ne postoji taj element u strukturi"<<endl;
		delete tp;
		exit(EXIT_FAILURE);
	}
	Value* ar[2]={ConstantInt::get(TheContext,APInt(32,0)),ConstantInt::get(TheContext,APInt(32,i))};
	delete tp;
	return Builder.CreateGEP(tmp,ar,"structtmp");
}

