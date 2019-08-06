#include<list>
#include<algorithm>
#include"naredbe.hpp"
extern map<string,izraz*> konstante;
extern map<string,pair<tip*,izraz*>> globalne;
extern map<string,subprogram*>funkcije;
extern stack<map<string,pair<tip*,izraz*>>> lokalne; 
extern void alokacija(tip* a,tip* b,tip* s);
using namespace std;


naredba* blok::kopija()const{
	return new blok(*this);
}

naredba* ispisE::kopija()const{
	return new ispisE(*this);
}
naredba* citajE::kopija()const{
	return new citajE(*this);
}
naredba* dodelaE::kopija()const{
	return new dodelaE(*this);
}

naredba* ifThen::kopija()const{
	return new ifThen(*this);
}

naredba* ifThenElse::kopija()const{
	return new ifThenElse(*this);
}

naredba* Break::kopija()const{
	return new Break(*this);
}

naredba* Continue::kopija()const{
	return new Continue(*this);
}

naredba* While::kopija()const{
	return new While(*this);
}

naredba* repeatUntil::kopija()const{
	return new repeatUntil(*this);
}

naredba* forTo::kopija()const{
	return new forTo(*this);
}

naredba* procedura::kopija()const{
	return new procedura(*this);
}

naredba* kraj::kopija()const{
	return new kraj(*this);
}

subprogram* funkcijaDekl::kopija()const{
	return new funkcijaDekl(*this);
}

subprogram* funkcija::kopija()const{
	return new funkcija(*this); 	
}

subprogram* procedurDekl::kopija()const{
	return new procedurDekl(*this);
}

subprogram* procedur::kopija()const{
	return new procedur(*this);
}

blok::~blok(){
for(auto n:rd)
	delete n;
}

ifThen::~ifThen(){
delete iz;
delete naredbe;
}

ifThenElse::~ifThenElse(){
delete iz;
delete naredbe;
delete elseN;
}

While::~While(){
delete iz;
delete naredbe;
}

repeatUntil::~repeatUntil(){
delete iz;
delete naredbe;
}


dodelaE::~dodelaE(){
delete ime;
delete e;
}


ispisE::~ispisE(){
delete e;
}
citajE::~citajE(){
delete e;
}
forTo::~forTo(){
delete i1;
delete i2;
delete nr;	
}

procedura::~procedura(){
for(auto r:args)
	delete r;
}

funkcijaDekl::~funkcijaDekl(){
	delete tp;
	unsigned i=args.size();
	for(unsigned j=0;j<i;j++)
		delete args[j].second;
}

funkcija::~funkcija(){
	map<string,tip*>::iterator ti;
	for(ti=vars.begin();ti!=vars.end();ti++){
		delete ti->second;}
	delete telo;
}
procedurDekl::~procedurDekl(){
	unsigned i=args.size();
	for(unsigned j=0;j<i;j++)
		delete args[j].second;
}
procedur::~procedur(){
	map<string,tip*>::iterator ti;
	for(ti=vars.begin();ti!=vars.end();ti++){
		delete ti->second;}
	delete telo;
}

Glavno::~Glavno(){
	unsigned t=prom.size();
	for(unsigned i=0;i<t;i++){
		delete prom[i].second;
	}
	prom.clear();
	t=fje.size();
	for(unsigned i=0;i<t;i++){
		delete fje[i];	
	}
	fje.clear();
	t=procedure.size();
	for(unsigned i=0;i<t;i++){
		delete procedure[i];	
	}
	procedure.clear();
	delete telo;
}
/*-----------semanticka provera---------------*/


void blok::dodela(){
	for(auto args:rd)
		args->dodela();
}

void ispisE::dodela(){
	e->dodela();
}

void dodelaE::dodela(){
	ime->dodela();
	e->dodela();
}

void citajE::dodela(){
	e->dodela();
}

void ifThen::dodela(){
	iz->dodela();
	naredbe->dodela();
}

void ifThenElse::dodela(){
	iz->dodela();
	naredbe->dodela();
	elseN->dodela();
}

void While::dodela(){
	iz->dodela();
	naredbe->dodela();
}

void repeatUntil::dodela(){
	iz->dodela();
	naredbe->dodela();
}

void forTo::dodela(){
	i1->dodela();
	i2->dodela();
	if(!(lokalne.size()>0)){//ako ne postoji lokalni skup elemenata, naravi jedan i ubaci promenljivu
			map<string,pair<tip*,izraz*>> tmp;
			tmp[s]=pair<tip*,izraz*>(new Int(),i1->kopija());
			lokalne.push(tmp);
			nr->dodela();
			tmp=lokalne.top();
			for(map<string,pair<tip*,izraz*>>::iterator ti=tmp.begin();ti!=tmp.end();ti++){
				delete ti->second.first;
				delete ti->second.second;
			}
			tmp.clear();
			lokalne.pop();
			return;
		}
		if((lokalne.size()>0)&&lokalne.top().find(s)==lokalne.top().end()){//ako postoji skup ali ne sadrzi element, dodaj element
			lokalne.top()[s]=pair<tip*,izraz*>(new Int(),i1->kopija());
			nr->dodela();
			delete lokalne.top()[s].first;
			delete lokalne.top()[s].second;
			lokalne.top().erase(s);
			return;
		}
	nr->dodela();
}

void procedura::dodela(){
	for(auto a:args)
		a->dodela();
}

void funkcijaDekl::dodela(){
	return;
}

void funkcija::dodela(){
	map<string,pair<tip*,izraz*>> tmp;
	for(map<string,tip*>::const_iterator ti=vars.begin();ti!=vars.end();ti++){
		tmp[ti->first]=pair<tip*,izraz*>(ti->second->kopija(),NULL);
	}
	lokalne.push(tmp);
	telo->dodela();
	tmp=lokalne.top();
	for(map<string,pair<tip*,izraz*>>::iterator ti=tmp.begin();ti!=tmp.end();ti++){
		delete ti->second.first;
	}
	tmp.clear();
	lokalne.pop();
	return;
}

void procedurDekl::dodela(){
	return;
}

void procedur::dodela(){
	map<string,pair<tip*,izraz*>> tmp;
	for(map<string,tip*>::const_iterator ti=vars.begin();ti!=vars.end();ti++){
		tmp[ti->first]=pair<tip*,izraz*>(ti->second->kopija(),NULL);
	}
	lokalne.push(tmp);
	telo->dodela();
	tmp=lokalne.top();
	for(map<string,pair<tip*,izraz*>>::iterator ti=tmp.begin();ti!=tmp.end();ti++){
		delete ti->second.first;
	}
	tmp.clear();
	lokalne.pop();
	return;
	
}
/*------provera----*/
bool blok::provera(int i)const{
	unsigned t=rd.size();
	for(unsigned j=0;j<t;j++){
		if(!(rd[j]->provera(i))){
			cout<<"greska u redu "<<j+1<<endl;
			return false;
		}
	}
	return true;
}

bool ispisE::provera(int i)const{
	tip* tmp=e->provera();
	string s=tmp->naziv();
	if(s=="char"||s=="string"||s=="int"||s=="float"||s=="pointer"){
		delete tmp;
		return true;
	}
	delete tmp;
	cout<<"greska u ispisu"<<endl;
	return false;
}

bool citajE::provera(int i)const{
	tip* tmp=e->provera();
	string s=tmp->naziv();
	if(e->ispis()=="--"){
		cout<<"ovo nije promenljiva"<<endl;
		return false;
	}
	if(s=="char"||s=="int"||s=="float"){
		delete tmp;
		return true;
	}
	delete tmp;
	cout<<"greska u citanju"<<endl;
	return false;
}

bool dodelaE::provera(int i)const{
	tip* tmpime=ime->provera();	//privremeni tipovi koji ce biti izbrisani, koriste se za pozicioniranje
	tip* tmp=e->provera();
	string si=tmpime->naziv();
	string se=tmp->naziv();
	tip* stvarna=NULL;			//pravi tip koji ce imati svoju vrednost alociranu
	if(!((si=="int"&&se=="float")||(si=="float"&&se=="int"))){//prolazi ako int u float ili float u int, ako ne proverava da li su jednaki
		if(!(tmpime->poredi(tmp))){
			cout<<"pogresni tipovi: "<<tmpime->naziv()<<" i "<<tmp->naziv()<<endl;
			return false;}
	}
	string id=ime->ispis();
	string ids=e->ispis();
	
	if(lokalne.size()>0&&(lokalne.top().find(ids)!=lokalne.top().end())){
		if(lokalne.top()[ids].second==NULL){
			cout<<"nije inicijalizovana prom "<<ids<<endl;
			return false;
		}
	}
	int dali=0;	//pomocna promenljiva za proveru alokacije
	if(konstante.find(id)!=konstante.end()){
		cout<<"ovo je konstanta"<<endl;
		return false;}
	if(globalne.find(id)!=globalne.end()){
		dali=1;
		stvarna=globalne[id].first;
	}
	else if(lokalne.size()>0&&(lokalne.top().find(id)!=lokalne.top().end())){
		if(lokalne.top()[id].second!=NULL)
			delete lokalne.top()[id].second;
		lokalne.top()[id].second=e->kopija();
		dali=2;
		stvarna=lokalne.top()[id].first;
	}
	else {
		cout<<"ne postoji element za dodelu"<<endl;
		return false;}
	if(dali==0){			//provera da li je adresa u koju dodeljujemo vrednost vec alocirana ili ne(provera za pointere)
		cout<<"nesta nije uspelo pri proveri dodele"<<endl;
		return false;}
	if(dali==1){
		if(!(globalne[id].first->alocirano(tmpime))){
			cout<<"nije alocirana globalna"<<endl;
			return false;}
	}
	if(dali==2){
		if(!(lokalne.top()[id].first->alocirano(tmpime))){
			cout<<"nije alocirana lokalna"<<endl;
			return false;}
	}
	alokacija(tmpime,tmp,stvarna);
	delete tmpime;
	delete tmp;
	stvarna=NULL;
	return true;
}

bool ifThen::provera(int i)const{
	tip* tmp=iz->provera();
	string s=tmp->naziv();
	if(s=="int"||s=="float"||s=="bool"){
		delete tmp;
		return naredbe->provera(i);
	}
	delete tmp;
	cout<<"nisu dobri tipovi za ifthen"<<endl;
	return false;
}

bool ifThenElse::provera(int i)const{
	tip* tmp=iz->provera();
	string s=tmp->naziv();
	if(s=="int"||s=="float"||s=="bool"){
		delete tmp;
		if(naredbe->provera(i)&&elseN->provera(i)){
		return true;
		}
	}
	cout<<"nisu dobri tipovi za ifthenelse"<<endl;
	return false;
}
bool Break::provera(int i)const{
	if(i!=1){
		cout<<"nije u nekoj prelji za break"<<endl;
		return false;}
	return true;
}
bool Continue::provera(int i)const{
	if(i!=1){
		cout<<"nije u petlji za continue"<<endl;
		return false;}
	return true;
}
bool While::provera(int i)const{
	tip* tmp=iz->provera();
	string s=tmp->naziv();
	if(s=="int"||s=="float"||s=="bool"){
		delete tmp;
		return  naredbe->provera(1);
	}
	delete tmp;
	cout<<"losi tipovi za while"<<endl;
	return false;
}

bool repeatUntil::provera(int i)const{
	tip* tmp=iz->provera();
	string s=tmp->naziv();
	if(s=="int"||s=="float"||s=="bool"){
		delete tmp;
		return  naredbe->provera(1);
	}
	delete tmp;
	cout<<"nisu dobri tipovi za repeat"<<endl;
	return false;
}

bool forTo::provera(int i)const{
	tip* tmp1=i1->provera();
	tip* tmp2=i2->provera();
	if(tmp1->naziv()=="int"&&tmp2->naziv()=="int"){
		delete tmp1;
		delete tmp2;	
		if(!(lokalne.size()>0)){//ako ne postoji lokalni skup elemenata, naravi jedan i ubaci promenljivu
			map<string,pair<tip*,izraz*>> tmp;
			tmp[s]=pair<tip*,izraz*>(new Int(),i1->kopija());
			lokalne.push(tmp);
			bool bl=nr->provera(1);
			tmp=lokalne.top();
			for(map<string,pair<tip*,izraz*>>::iterator ti=tmp.begin();ti!=tmp.end();ti++){
				delete ti->second.first;
				delete ti->second.second;
			}
			tmp.clear();
			lokalne.pop();
			return bl;
		}
		if((lokalne.size()>0)&&lokalne.top().find(s)==lokalne.top().end()){//ako postoji skup ali ne sadrzi element, dodaj element
			lokalne.top()[s]=pair<tip*,izraz*>(new Int(),i1->kopija());
			bool bl=nr->provera(1);
			delete lokalne.top()[s].first;
			delete lokalne.top()[s].second;
			lokalne.top().erase(s);
			return bl;
		}
		return  nr->provera(1);
	}
	delete tmp1;
	delete tmp2;
	cout<<"losi tipovi za forto"<<endl;
	return false;
}

bool procedura::provera(int i)const{
	if(funkcije[id]->Tip()!=NULL){
		cout<<"ovo je funkcija "<<id<<endl;
		return false;
	}
	if(funkcije[id]->kod()==NULL){
		cout<<"ova procedura nema telo"<<id<<endl;
		return false;
	}
	if(funkcije[id]->argumenti().size()!=args.size()){
		cout<<"pogresan broj argumenata"<<id<<endl;
		return false;
	}
	unsigned t=args.size();
	for(unsigned i=0;i<t;i++){
		tip* tmp=args[i]->provera();
		if(!((funkcije[id]->argumenti())[i].second->poredi(tmp))){
			cout<<"pogresan tip argumenta"<<endl;
			delete tmp;
			return false;
		}
		delete tmp;
	}
	return true;
}

bool funkcijaDekl::unos()const{
	if(funkcije.find(id)==funkcije.end()){
		funkcije[id]=new funkcijaDekl(*this);
		}
	else{
		cout<<"vec postoji deklaracija funkcije "<<id<<endl;
		return false;}
	unsigned t=args.size();
	for(unsigned i=0;i<t;i++){
		if(konstante.find(args[i].first)!=konstante.end()){
			cout<<"postoji promenljiva "<<args[i].first<<endl;
			return false;}
		if(globalne.find(args[i].first)!=globalne.end()){
			cout<<"postoji promenljiva "<<args[i].first<<endl;
			return false;}
	}
	
	return true;
}

bool funkcijaDekl::provera()const{
	cout<<"ova funkcija je i dalje samo deklaracija: "<<id<<endl;
	return false;}

bool funkcija::unos()const{
	if(funkcije.find(id)==funkcije.end())
		funkcije[id]=new funkcija(*this);
	else{
		if(funkcije[id]->kod()==NULL){
			if(argCheck(args,(funkcije[id]->argumenti()))&&tp->poredi(funkcije[id]->Tip()) ){
				delete funkcije[id];
				funkcije[id]=new funkcija(*this);
			}
			else{
				cout<<"pogresni argumenti "<<id<<endl;
				return false;}
		}
		else{
			cout<<"vec je kreirana funkcija sa imenom "<<id<<endl;
			return false;}
	}
	map<string,tip*>::const_iterator ti;
	for(ti=vars.begin();ti!=vars.end();ti++){
		if(konstante.find(ti->first)!=konstante.end()){
			cout<<"postoji promenljiva "<<ti->first<<endl;
			return false;}
		if(globalne.find(ti->first)!=globalne.end()){
			cout<<"postoji promenljiva "<<ti->first<<endl;
			return false;}
	}
	return true;
}

bool funkcija::provera()const{
	map<string,pair<tip*,izraz*>> tmp;
	for(map<string,tip*>::const_iterator ti=vars.begin();ti!=vars.end();ti++){
		tmp[ti->first]=pair<tip*,izraz*>(ti->second->kopija(),NULL);
	}
	lokalne.push(tmp);
	if(!(telo->provera(0))){
		cout<<"greska u telu funkcije "<<id<<endl;
		return false;}
	if(lokalne.top()[id].second==NULL){
		cout<<"funkcija ne vraca vrednost "<<id<<endl;
		return false;}
	tmp=lokalne.top();
	for(map<string,pair<tip*,izraz*>>::iterator ti=tmp.begin();ti!=tmp.end();ti++){
		delete ti->second.first;
		delete ti->second.second;
	}
	tmp.clear();
	lokalne.pop();
	return true;
}

bool procedurDekl::unos()const{
	if(funkcije.find(id)==funkcije.end()){
		funkcije[id]=new procedurDekl(*this);
		}
	else{
		cout<<"vec postoji deklaracija procedure "<<id<<endl;
		return false;}
	unsigned t=args.size();
	for(unsigned i=0;i<t;i++){
		if(konstante.find(args[i].first)!=konstante.end()){
			cout<<"postoji promenljiva "<<args[i].first<<endl;
			return false;}
		if(globalne.find(args[i].first)!=globalne.end()){
			cout<<"postoji promenljiva "<<args[i].first<<endl;
			return false;}
	}
	return true;
}

bool procedurDekl::provera()const{
	cout<<"ova procedura je samo deklaracija: "<<id<<endl;
	return false;
}

bool procedur::unos()const{
	if(funkcije.find(id)==funkcije.end())
		funkcije[id]=new procedur(*this);
	else{
		if(funkcije[id]->kod()==NULL){
			if(argCheck(args,(funkcije[id]->argumenti())) ){
				delete funkcije[id];
				funkcije[id]=new procedur(*this);
			}
			else{
				cout<<"pogresni argumenti "<<id<<endl;
				return false;}
		}
		else{
			cout<<"vec je kreirana procedura sa imenom "<<id<<endl;
			return false;}
	}
	map<string,tip*>::const_iterator ti;
	for(ti=vars.begin();ti!=vars.end();ti++){
		if(konstante.find(ti->first)!=konstante.end()){
			cout<<"postoji promenljiva u konstante"<<endl;
			return false;}
		if(globalne.find(ti->first)!=globalne.end()){
			cout<<"postoji promenljiva u promenljive"<<endl;
			return false;}
	}
	return true;
}

bool procedur::provera()const{
	map<string,pair<tip*,izraz*>> tmp;
	for(map<string,tip*>::const_iterator ti=vars.begin();ti!=vars.end();ti++){
		tmp[ti->first]=pair<tip*,izraz*>(ti->second->kopija(),NULL);
	}
	lokalne.push(tmp);
	if(!(telo->provera(0))){
		cout<<"nesta nije uredu u telu procedura "<<id<<endl;
		return false;}
	tmp=lokalne.top();
	for(map<string,pair<tip*,izraz*>>::iterator ti=tmp.begin();ti!=tmp.end();ti++){
		delete ti->second.first;
		delete ti->second.second;
	}
	tmp.clear();
	lokalne.pop();
	return true;
}

bool Glavno::provera()const{
	unsigned t=prom.size();
	for(unsigned i=0;i<t;i++){
		if(globalne.find(prom[i].first)==globalne.end()&&konstante.find(prom[i].first)==konstante.end())
			globalne[prom[i].first]=pair<tip*,izraz*>(prom[i].second->kopija(),NULL);
		else{
			cout<<"vec je definisana promenljiva "<<prom[i].first<<endl;
			return false;}
	}
	t=fje.size();
	for(unsigned i=0;i<t;i++){
		if(!fje[i]->unos()){
			cout<<"nije uspeo unos procedure "<<endl;
			return false;}
	}
	t=procedure.size();
	for(unsigned i=0;i<t;i++){
		if(!procedure[i]->unos()){
			cout<<"nije uspeo unos funkcije"<<endl;
			return false;}
	}

	map<string,subprogram*>::iterator ti;
	for(ti=funkcije.begin();ti!=funkcije.end();ti++){
		if(!(ti->second->provera())){
			cout<<"greska u funkciji/proceduri"<<endl;
			return false;}
	}
	if(!telo->provera(0)){
		cout<<"greska u glavnom delu koda"<<endl;
		return false;}
	t=fje.size();
	for(unsigned i=0;i<t;i++){
		fje[i]->dodela();
	}
	t=procedure.size();
	for(unsigned i=0;i<t;i++){
		procedure[i]->dodela();
	}

	telo->dodela();

	/*ciscenje sadrzaja koji vise necemo koristiti*/
	map<string,izraz*>::iterator ti1;
	for(ti1=konstante.begin();ti1!=konstante.end();ti1++){
		delete ti1->second;
	}
	map<string,pair<tip*,izraz*>>::iterator ti2;
	for(ti2=globalne.begin();ti2!=globalne.end();ti2++){
		delete ti2->second.first;
		delete ti2->second.second;
	}

	
	map<string,subprogram*>::iterator ti3;
	for(ti3=funkcije.begin();ti3!=funkcije.end();ti3++){
		delete ti3->second;
	}
	konstante.clear();
	globalne.clear();
	funkcije.clear();

	return true;
}

void listmaker(vector<pair<string,tip*>>*l,vector<string>* args, tip* tp){
	unsigned t=args->size();
	for(unsigned i=0;i<t;i++){
		pair<string,tip*> tmp((*args)[i],tp->kopija());
		if(!(find(l->begin(),l->end(),tmp)!=l->end()))
			l->push_back(tmp);
		else{
			cout<<"vec je definisan taj tip u nizu"<<endl;
			delete tmp.second;
			exit(EXIT_FAILURE);
		}
	}
}


void mapmaker(map<string,tip*>* mapa, vector<pair<string,tip*>>* args){
	unsigned t=args->size();
	for(unsigned i=0;i<t;i++){
		if(mapa->find((*args)[i].first)==mapa->end()){
			(*mapa)[(*args)[i].first]=(*args)[i].second->kopija();
			}	
		else{
			cout<<"vec je definisan taj tip u nizu"<<endl;
			exit(EXIT_FAILURE);
		}
	}
}


void argsRemover(vector<pair<string,tip*>>* args){
	unsigned t=args->size();
	for(unsigned i=0;i<t;i++){
		delete (*args)[i].second;
	}
	delete args;
}

void mapsRemover(map<string,tip*>* m){
	map<string,tip*>::iterator ti;
	for(ti=(*m).begin();ti!=(*m).end();ti++)
		delete ti->second;
}

void functRemover(vector<subprogram*>* vsp){
	unsigned t=vsp->size();
	for(unsigned i=0;i<t;i++)
		delete (*vsp)[i];
	delete vsp;
}

bool argCheck(const vector<pair<string,tip*>>& map1,const vector<pair<string,tip*>>& map2){
	if(map1.size()!=map2.size())
		return false;
	unsigned t=map1.size();
	for(unsigned i=0;i<t;i++){
		if((map1)[i].first!=(map2)[i].first)
			return false;
		if(!((map1)[i].second->poredi((map2)[i].second)))
			return false;
	}
	return true;
}

/*-----------------codegen---------------*/


Value* blok::codegen()const{
	unsigned t=rd.size();
	for(unsigned i=0;i<t;i++){
		if(rd[i]->codegen()==nullptr)
			return nullptr;

		}
	return ConstantInt::get(TheContext,APInt(32,0));
}

Value* ispisE::codegen()const{
	Value* tmp=e->codegen();
	tip* tp=e->provera();
	string s=tp->naziv();
	delete tp;
	if(tmp==nullptr){
		cout<<"prazan codegen"<<endl;
		return nullptr;}
	vector<Value*>argS;
	if(s=="char"){//u slucaju samo jednog karaktera, ne treba nam printf
		Function* TheFunction=TheModule->getFunction("putchar");
		if(TheFunction==nullptr){
			vector<Type*> ArgsT;
			ArgsT.push_back(Type::getInt8Ty(TheContext));
			FunctionType* FT=FunctionType::get(Type::getInt32Ty(TheContext),ArgsT,false);
			TheFunction=Function::Create(FT,Function::ExternalLinkage,"putchar",TheModule);//putchar
		}
		tmp=AorP(tmp);
		argS.push_back(tmp);
		return Builder.CreateCall(TheFunction,argS,"writechr");
	}
	Function* TheFunction=TheModule->getFunction("printf");//priprema printf
	if(TheFunction==nullptr){
		vector<Type*> ArgsT;
		ArgsT.push_back(PointerType::get(Type::getInt8Ty(TheContext),0));
		FunctionType* FT=FunctionType::get(Type::getInt32Ty(TheContext),ArgsT,true);
		TheFunction=Function::Create(FT,Function::ExternalLinkage,"printf",TheModule);//kreiranje ako nema
	}
	if(s=="string"){
		argS.push_back(tmp);
		Builder.CreateCall(TheFunction,argS,"writeln");//ispis stringa sa ispisom \n nakon
		argS.clear();
		Value* str=tekst["\n"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("\n","str");
			tekst["\n"]=str;
		}
		argS.push_back(str);
		return Builder.CreateCall(TheFunction,argS,"newline");
	}
	if(s=="int"||s=="pointer"){		//ispis int vrednosti
		Value* str=tekst["%d"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("%d","str");
			tekst["%d"]=str;
		}
		argS.push_back(str);
		tmp=AorP(tmp);
		argS.push_back(tmp);
		Builder.CreateCall(TheFunction,argS,"writeln");
		argS.clear();
		str=tekst["\n"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("\n","str");
			tekst["\n"]=str;
		}
		argS.push_back(str);
		return Builder.CreateCall(TheFunction,argS,"newline");
	}
	if(s=="float"){		//ispis float vrednosti
		Value* str=tekst["%f"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("%f","str");
			tekst["%f"]=str;
		}
		argS.push_back(str);
		tmp=AorP(tmp);
		argS.push_back(tmp);
		Builder.CreateCall(TheFunction,argS,"writeln");
		argS.clear();
		str=tekst["\n"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("\n","str");
			tekst["\n"]=str;
		}
		argS.push_back(str);
		return Builder.CreateCall(TheFunction,argS,"newline");
	}
	cout<<"nesta ne radi ispis"<<endl;
	return nullptr;
}

Value* citajE::codegen()const{
	Value* v=e->codegen();
	if(v==nullptr)
		return nullptr;
	tip* tmp=e->provera();
	string s=tmp->naziv();
	delete tmp;
	vector<Value*>argS;
	Function* TheFunction=TheModule->getFunction("scanf");//priprema scanf
	if(TheFunction==nullptr){
		vector<Type*> ArgsT;
		ArgsT.push_back(PointerType::get(Type::getInt8Ty(TheContext),0));
		FunctionType* FT=FunctionType::get(Type::getInt32Ty(TheContext),ArgsT,true);
		TheFunction=Function::Create(FT,Function::ExternalLinkage,"scanf",TheModule);//kreiranje ako nema
	}
	if(s=="int"){
		Value* str=tekst["%d"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("%d","str");
			tekst["%d"]=str;
		}
		argS.push_back(str);
		argS.push_back(v);
		return Builder.CreateCall(TheFunction,argS,"read");
	}
	if(s=="float"){
		Value* str=tekst["%f"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("%f","str");
			tekst["%f"]=str;
		}
		argS.push_back(str);
		argS.push_back(v);
		return Builder.CreateCall(TheFunction,argS,"read");
	}
	if(s=="char"){
		Value* str=tekst["%c"]; 
		if(str==nullptr){
			str=Builder.CreateGlobalStringPtr("%c","str");
			tekst["%c"]=str;
		}
		argS.push_back(str);
		argS.push_back(v);
		return Builder.CreateCall(TheFunction,argS,"read");
	}
	cout<<"nesta ne radi citanje"<<endl;
	return nullptr;
}

Value* dodelaE::codegen()const{
	Value* r=ime->codegen();
	Value* d=e->codegen();
	if(r==nullptr||d==nullptr){
		cout<<"jedna od vrednosti je nullptr "<<ime->ispis()<<endl;
		return nullptr;}
	if(!addr){//ako ne ocekujemo adresu, uradi load (ako je pointer)
		d=AorP(d);
	}
	addr=false;
	tip* t1=ime->provera();
	tip* t2=e->provera();
	string s1=t1->naziv();
	string s2=t2->naziv();
	if(s1=="int"&&s2=="float"){
		d=Builder.CreateFPToSI(d,Type::getInt32Ty(TheContext),"conv");
	}
	if(s1=="float"&&s2=="int"){
		d=Builder.CreateSIToFP(d,Type::getFloatTy(TheContext),"conv");

	}
	delete t1;
	delete t2;
	Builder.CreateStore(d,r);
	return ConstantInt::get(TheContext,APInt(32,0));
}

Value* ifThen::codegen()const{
	Value* CondV=iz->codegen();
	if(CondV==nullptr)
		return nullptr;
	tip* tp=iz->provera();
	if(tp->naziv()!="bool"){
		if(tp->naziv()=="float")
			CondV=Builder.CreateFPToSI(CondV,Type::getInt32Ty(TheContext),"fptoi");
		CondV=Builder.CreateICmpNE(CondV,ConstantInt::get(TheContext,APInt(32,0)),"necmp");
	}
	delete tp;
	Function* TheFunction=Builder.GetInsertBlock()->getParent();
	BasicBlock* ThenBB=BasicBlock::Create(TheContext,"then",TheFunction);
	BasicBlock* MergeBB=BasicBlock::Create(TheContext,"ifcont");

	Builder.CreateCondBr(CondV,ThenBB,MergeBB);
	
	Builder.SetInsertPoint(ThenBB);
	Value* ThenV=naredbe->codegen();
	if(ThenV==nullptr)
		return nullptr;
	Builder.CreateBr(MergeBB);
	ThenBB=Builder.GetInsertBlock();
	
	TheFunction->getBasicBlockList().push_back(MergeBB);
	Builder.SetInsertPoint(MergeBB);
	return ConstantInt::get(TheContext,APInt(32,0));   
}

Value* ifThenElse::codegen()const{
	Value* CondV=iz->codegen();
	if(CondV==nullptr)
		return nullptr;
	tip* tp=iz->provera();
	if(tp->naziv()!="bool"){
		if(tp->naziv()=="float")
			CondV=Builder.CreateFPToSI(CondV,Type::getInt32Ty(TheContext),"fptoi");
		CondV=Builder.CreateICmpNE(CondV,ConstantInt::get(TheContext,APInt(32,0)),"necmp");
	}
	delete tp;

	Function* TheFunction=Builder.GetInsertBlock()->getParent();
	BasicBlock* ThenBB=BasicBlock::Create(TheContext,"then",TheFunction);
	BasicBlock* ElseBB=BasicBlock::Create(TheContext,"else");
	BasicBlock* MergeBB=BasicBlock::Create(TheContext,"ifcont");

	Builder.CreateCondBr(CondV,ThenBB,MergeBB);
	
	Builder.SetInsertPoint(ThenBB);
	Value* ThenV=naredbe->codegen();
	if(ThenV==nullptr)
		return nullptr;
	Builder.CreateBr(MergeBB);
	ThenBB=Builder.GetInsertBlock();
		
	TheFunction->getBasicBlockList().push_back(ElseBB);
	Builder.SetInsertPoint(ElseBB);
	Value* ElseV=elseN->codegen();
	if(ElseV==nullptr)
		return nullptr;
	Builder.CreateBr(MergeBB);
	ElseBB=Builder.GetInsertBlock();

	TheFunction->getBasicBlockList().push_back(MergeBB);
	Builder.SetInsertPoint(MergeBB);
	return ConstantInt::get(TheContext,APInt(32,0));
}
BasicBlock* BreakBB=nullptr;
BasicBlock* ContinueBB=nullptr;

Value* Break::codegen()const{
	if(BreakBB==nullptr)
		yyerror("neka greska sa break blokom");
	return Builder.CreateBr(BreakBB);
}

Value* Continue::codegen()const{
	if(ContinueBB==nullptr)
		yyerror("neka greska sa continue blokom");
	return Builder.CreateBr(ContinueBB);
}

Value* kraj::codegen()const{
	if(retrn==nullptr)
		return Builder.CreateRetVoid();
	Value* RetVal=Builder.CreateLoad(retrn,"retval");
	return Builder.CreateRet(RetVal);
	
}

Value* While::codegen()const{
	Function* TheFunction=Builder.GetInsertBlock()->getParent();
	BasicBlock* BeforeLoopBB=BasicBlock::Create(TheContext,"beforeloop");
	BasicBlock* LoopBB=BasicBlock::Create(TheContext,"loop");
	BasicBlock* AfterLoopBB=BasicBlock::Create(TheContext,"afterloop");
	
	BasicBlock* bl1=BreakBB;
	BasicBlock* bl2=ContinueBB;

	Builder.CreateBr(BeforeLoopBB);
	TheFunction->getBasicBlockList().push_back(BeforeLoopBB);
	Builder.SetInsertPoint(BeforeLoopBB);
	BeforeLoopBB=Builder.GetInsertBlock();
	

	Value* CondV=iz->codegen();
	if(CondV==nullptr)
		return nullptr;
	tip* tp=iz->provera();
	if(tp->naziv()!="bool"){
		if(tp->naziv()=="float")
			CondV=Builder.CreateFPToSI(CondV,Type::getInt32Ty(TheContext),"fptoi");
		CondV=Builder.CreateICmpNE(CondV,ConstantInt::get(TheContext,APInt(32,0)),"necmp");
	}
	delete tp;
	Builder.CreateCondBr(CondV,LoopBB,AfterLoopBB);//provera pre i tokom jer uslov mozda nije ispunjen na pocetku
	
	TheFunction->getBasicBlockList().push_back(LoopBB);
	Builder.SetInsertPoint(LoopBB);//postavlja i sacuva jer telo mozda generise druge blokove i povratni blok nece biti isti
	LoopBB=Builder.GetInsertBlock();

	BreakBB=AfterLoopBB;
	ContinueBB=BeforeLoopBB;

	Value* BodyV=naredbe->codegen();//generisanje tela i postavljanje i vracanje tacki za break i continue

	BreakBB=bl1;
	ContinueBB=bl2;

	if(BodyV==nullptr)
		return nullptr;
	
	Builder.CreateBr(BeforeLoopBB);
	Builder.SetInsertPoint(AfterLoopBB);
	TheFunction->getBasicBlockList().push_back(AfterLoopBB);
	
	return ConstantInt::get(TheContext,APInt(32,0));
}

Value* repeatUntil::codegen()const{
	Function* TheFunction=Builder.GetInsertBlock()->getParent();
	BasicBlock* CondLoopBB=BasicBlock::Create(TheContext,"condloop");
	BasicBlock* LoopBB=BasicBlock::Create(TheContext,"loop");
	BasicBlock* AfterLoopBB=BasicBlock::Create(TheContext,"afterloop");
	
	BasicBlock* bl1=BreakBB;
	BasicBlock* bl2=ContinueBB;

	Builder.CreateBr(LoopBB);
	TheFunction->getBasicBlockList().push_back(LoopBB);
	Builder.SetInsertPoint(LoopBB);
	LoopBB=Builder.GetInsertBlock();

	BreakBB=AfterLoopBB;
	ContinueBB=CondLoopBB;

	Value* BodyV=naredbe->codegen();//generisanje tela i postavljanje i vracanje tacki za break i continue

	BreakBB=bl1;
	ContinueBB=bl2;

	if(BodyV==nullptr)
		return nullptr;
	Builder.CreateBr(CondLoopBB);

	TheFunction->getBasicBlockList().push_back(CondLoopBB);//provera uslova
	Builder.SetInsertPoint(CondLoopBB);
	CondLoopBB=Builder.GetInsertBlock();
	
	Value* CondV=iz->codegen();
	if(CondV==nullptr)
		return nullptr;
	tip* tp=iz->provera();
	if(tp->naziv()!="bool"){
		if(tp->naziv()=="float")
			CondV=Builder.CreateFPToSI(CondV,Type::getInt32Ty(TheContext),"fptoi");
		CondV=Builder.CreateICmpEQ(CondV,ConstantInt::get(TheContext,APInt(32,0)),"necmp");
	}
	else
		CondV=Builder.CreateICmpEQ(CondV,ConstantInt::get(TheContext,APInt(1,0)),"necmp");		
	delete tp;
	Builder.CreateCondBr(CondV,LoopBB,AfterLoopBB);//provera da li nastaviti repeat ili izaci

	Builder.SetInsertPoint(AfterLoopBB);
	TheFunction->getBasicBlockList().push_back(AfterLoopBB);
	
	return ConstantInt::get(TheContext,APInt(32,0));


	
}

Value* forTo::codegen()const{
	Function* TheFunction=Builder.GetInsertBlock()->getParent();
	BasicBlock* BeforeLoopBB=BasicBlock::Create(TheContext,"beforeloop");
	BasicBlock* LoopBB=BasicBlock::Create(TheContext,"loop");
	BasicBlock* IncrementBB=BasicBlock::Create(TheContext,"increment");
	BasicBlock* AfterLoopBB=BasicBlock::Create(TheContext,"afterloop");
	AllocaInst* OldVal=nullptr;

	if(lok.find(s)!=lok.end())//inicijalizacija start vrednosti  i obezbedjivanje prostora
		OldVal=lok[s];
	tip* tp=i1->provera();
	AllocaInst* I=createEntryBlockA(TheFunction,s,tp);
	delete tp;
	lok[s]=I;
	Value* StartV=i1->codegen();
	if(StartV==nullptr)
		return nullptr;
	Builder.CreateStore(StartV,I);
	
	Builder.CreateBr(BeforeLoopBB);//beforeloop
	TheFunction->getBasicBlockList().push_back(BeforeLoopBB);
	Builder.SetInsertPoint(BeforeLoopBB);
	BeforeLoopBB=Builder.GetInsertBlock();

	
	BasicBlock* bl1=BreakBB;
	BasicBlock* bl2=ContinueBB;

	StartV=Builder.CreateLoad(I,s);
	Value* CondV=i2->codegen();
	if(CondV==nullptr)
		return nullptr;
	CondV=Builder.CreateICmpNE(StartV,CondV,"neqcmp");
	Builder.CreateCondBr(CondV,LoopBB,AfterLoopBB);
	
	TheFunction->getBasicBlockList().push_back(LoopBB);
	Builder.SetInsertPoint(LoopBB);
	LoopBB=Builder.GetInsertBlock();
	
	BreakBB=AfterLoopBB;	//za break i continue komande, break ide na after a continue se inkrementira 
	ContinueBB=IncrementBB;

	Value* BodyV=nr->codegen();

	BreakBB=bl1;	//nakon bodyV->codegen() mozemo da vratimo prethodne vrednosti
	ContinueBB=bl2;

	if(BodyV==nullptr)
		return nullptr;

	Builder.CreateBr(IncrementBB);	//increment blok
	TheFunction->getBasicBlockList().push_back(IncrementBB);
	Builder.SetInsertPoint(IncrementBB);
	IncrementBB=Builder.GetInsertBlock();
	
	Value* StepV=ConstantInt::get(TheContext,APInt(32,1));
	if(StepV==nullptr)
		return nullptr;
	Value* TmpV=Builder.CreateLoad(I,s);
	Value* NextV=Builder.CreateAdd(TmpV,StepV,"nextvar");
	Builder.CreateStore(NextV,I);
	Builder.CreateBr(BeforeLoopBB);//vraca se u before loop da se ponovo proveri uslov

	Builder.SetInsertPoint(AfterLoopBB);//after blok
	TheFunction->getBasicBlockList().push_back(AfterLoopBB);
	
	if(OldVal!=nullptr)
		lok[s]=OldVal;
	else
		lok.erase(s);
	
	return ConstantInt::get(TheContext,APInt(32,0));
	
}

Value* procedura::codegen()const{
	Function* CalleeF=TheModule->getFunction(id);
	if(CalleeF==nullptr)
		yyerror("procedura "+id+" ne postoji");
	vector<Value*> ArgsF;
	unsigned t=args.size();
	for(unsigned i=0;i<t;i++){
		Value* tmp=args[i]->codegen();
		if(!addr)
			tmp=AorP(tmp);
		addr=false;
		ArgsF.push_back(tmp);
	}
	Builder.CreateCall(CalleeF,ArgsF); 	//nema ime niti vraca ista posto je ovo uvek void
	return ConstantInt::get(TheContext,APInt(32,0));
}

Function* funkcijaDekl::codegen()const{
	vector<Type*> ArgsT;
	unsigned t=args.size();
	for(unsigned i=0;i<t;i++){
		ArgsT.push_back(args[i].second->codegen());
	}
	FunctionType* FT=FunctionType::get(tp->codegen(),ArgsT,false);
	Function* F=Function::Create(FT,Function::ExternalLinkage,id,TheModule);
	
	t=0;
	for(auto &Arg:F->args())
		Arg.setName(args[t++].first);
	return F;
}

Function* funkcija::codegen()const{
	Function* TheFunction= TheModule->getFunction(id);
	
	if(TheFunction==nullptr)
		TheFunction=funkcijaDekl::codegen();
	if(!TheFunction)
		return nullptr;
	
	if(!TheFunction->empty())
		yyerror("funkcija "+id+" ne moze da se predefinise");
	BasicBlock* BB=BasicBlock::Create(TheContext,"entry",TheFunction);
	Builder.SetInsertPoint(BB);
	
	lok.clear();
	unsigned t=0;
	for(auto &Arg:TheFunction->args()){
		AllocaInst* alloca=createEntryBlockA(TheFunction,Arg.getName(),args[t++].second);
		Builder.CreateStore(&Arg,alloca);
		lok[Arg.getName()]=alloca;
	}
	for(map<string,tip*>::const_iterator ti=vars.begin();ti!=vars.end();ti++){
		if(lok.find(ti->first)==lok.end()){
			AllocaInst* alloca=createEntryBlockA(TheFunction,ti->first,ti->second);
			lok[ti->first]=alloca;
		}
	}
	Value* tmp=retrn;
	retrn=lok[id];
	Value* BodyV=telo->codegen();
	retrn=tmp;
	Value* RetVal=Builder.CreateLoad(lok[id],id);
	if(BodyV){
		Builder.CreateRet(RetVal);
		verifyFunction(*TheFunction);
		return TheFunction;

	}
	TheFunction->eraseFromParent();
	return nullptr;
}

Function* procedurDekl::codegen()const{
	vector<Type*> ArgsT;
	unsigned t=args.size();
	for(unsigned i=0;i<t;i++){
		ArgsT.push_back(args[i].second->codegen());
	}
	FunctionType* FT=FunctionType::get(Type::getVoidTy(TheContext),ArgsT,false);
	Function* F=Function::Create(FT,Function::ExternalLinkage,id,TheModule);
	
	t=0;
	for(auto &Arg:F->args())
		Arg.setName(args[t++].first);
	return F;
}

Function* procedur::codegen()const{
	Function* TheFunction= TheModule->getFunction(id);
	
	if(TheFunction==nullptr)
		TheFunction=procedurDekl::codegen();
	if(!TheFunction)
		return nullptr;
	if(!TheFunction->empty())
		yyerror("procedura "+id+" ne moze da se predefinise");
	BasicBlock* BB=BasicBlock::Create(TheContext,"entry",TheFunction);
	Builder.SetInsertPoint(BB);
	
	lok.clear();
	unsigned t=0;
	for(auto &Arg:TheFunction->args()){
		AllocaInst* alloca=createEntryBlockA(TheFunction,Arg.getName(),args[t++].second);
		Builder.CreateStore(&Arg,alloca);
		lok[Arg.getName()]=alloca;
	}
	for(map<string,tip*>::const_iterator ti=vars.begin();ti!=vars.end();ti++){
		if(lok.find(ti->first)==lok.end()){
			AllocaInst* alloca=createEntryBlockA(TheFunction,ti->first,ti->second);
			lok[ti->first]=alloca;
		}
	}
	Value* tmp=retrn;
	retrn=nullptr;
	Value* BodyV=telo->codegen();
	retrn=tmp;
	if(BodyV){
		Builder.CreateRetVoid();
		verifyFunction(*TheFunction);
		return TheFunction;
	}
	TheFunction->eraseFromParent();
	return nullptr;
}

Value* Glavno::codegen()const{
	lok.clear();
	unsigned t=prom.size();
	for(unsigned i=0;i<t;i++){//unos i inicializacija globalnih prom
		GlobalVariable* glvar=new GlobalVariable(*TheModule,prom[i].second->codegen(),false,
				GlobalValue::CommonLinkage,0,prom[i].first);
		glob[prom[i].first]=glvar;
		string s=prom[i].second->naziv();
		if(s=="int")
			glvar->setInitializer(ConstantInt::get(TheContext,APInt(64,0)));
		if(s=="float")
			glvar->setInitializer(ConstantFP::get(TheContext,APFloat(0.0)));
		if(s=="char")
			glvar->setInitializer(ConstantInt::get(TheContext,APInt(8,0)));
		if(s=="array")
			glvar->setInitializer(ConstantAggregateZero::get(prom[i].second->codegen()));
		if(s=="pointer")
			glvar->setInitializer(Constant::getNullValue(prom[i].second->codegen()));
		if(s=="bool")
			glvar->setInitializer(ConstantInt::get(TheContext,APInt(2,0)));
		if(s=="struct")
			glvar->setInitializer(ConstantAggregateZero::get(prom[i].second->codegen()));
	}
	
	t=fje.size();
	for(unsigned i=0;i<t;i++){
		if(fje[i]->codegen()==nullptr)
			return nullptr;
	}
	t=procedure.size();
	for(unsigned i=0;i<t;i++){
		if(procedure[i]->codegen()==nullptr)
			return nullptr;
	}
	/*kreiranje main funkcije*/
	vector<Type*> v(0);
	FunctionType* FP=FunctionType::get(Type::getInt32Ty(TheContext),v,false);
	Function* F=Function::Create(FP,Function::ExternalLinkage,"main",TheModule);
	if(!F)
		return nullptr;
	BasicBlock* BB=BasicBlock::Create(TheContext,"entry",F);
	Builder.SetInsertPoint(BB);
	Value* tmp=retrn;
	retrn=ConstantInt::get(TheContext,APInt(32,0));
	if(telo->codegen()){
		retrn=tmp;
		Builder.CreateRet(ConstantInt::get(TheContext,APInt(32,0)));
		verifyFunction(*F);
		return F;
	}
	else{
		F->eraseFromParent();
		return nullptr;
	}
}

