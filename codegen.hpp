#ifndef __COD__
#define __COD__
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/Scalar.h"
#include"tipovi.hpp"
using namespace std;
using namespace llvm;
class tip;
extern string imestr;//string za imenovanje struktura
extern bool addr;//provera da li se vraca adresa ili vrednost
extern LLVMContext TheContext;
extern IRBuilder<> Builder;
extern Module* TheModule;
extern legacy::FunctionPassManager *TheFPM;
extern Value* retrn; //cuva vrednost koja treba da se vrati za trenutnu fju (ako je null, vrati void)
extern map<string,AllocaInst*> lok;
extern map<string,GlobalVariable*> glob;  //za cuvanje globalnih prom
extern map<string,Value*> tekst; //za cuvanje stringova
extern map<string,StructType*>struk; //mapa koja sadrzi jedinstvene strukture
AllocaInst* createEntryBlockA(Function* TheFunction, const string& name, tip* tp);
Value* AorP(Value* v);
#endif
