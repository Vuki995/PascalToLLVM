#include"codegen.hpp"
 string imestr="struct";
 LLVMContext TheContext;
 IRBuilder<> Builder(TheContext);
 Module* TheModule;
 legacy::FunctionPassManager *TheFPM;
 map<string,AllocaInst*> lok;
 map<string,GlobalVariable*> glob;
 map<string,Value*> tekst;
 map<string,StructType*>struk;
 Value* retrn=nullptr;
 bool addr=false;
AllocaInst* createEntryBlockA(Function* TheFunction,const string& name, tip* tp){
	IRBuilder<>TmpB(&TheFunction->getEntryBlock(),TheFunction->getEntryBlock().begin());
	return TmpB.CreateAlloca(tp->codegen(),0,name);
}

Value* AorP(Value* v){
if(v->getType()->isPointerTy())
	return Builder.CreateLoad(v,"loadtmp");
	return v;
}
