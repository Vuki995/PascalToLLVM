program Hello;
type
qwer=^ array[1 .. 2] of array[ 3 .. 5] of ^char;
ime,prezime=int;
ti=array [3 .. 4] of array [0 .. 7] of ^char;
pas=ti;	
strana=record
	broj:int;
	velicina:int;
end;
knjiga=record
	titula : array [1 .. 8] of ^char;
	godina: int;
	strane: array [1 .. 20] of strana;
	end;
const
tee=true;
var
ber:qwer;
hari:knjiga;
fl:float;
provera:^^int;
provera2:^int;
ulica:int;
kuca:ti;
kucica:float;
grad: char;
te:bool;
ili:int;
function test(a,b:int):int;
var mata:knjiga;
begin
	hari.godina=4;
	grad='c';
	te=tee;
	test=hari.godina;
	exit;
	writeln(a+b);
end;

function zbir(a:int):int;
begin
	if (a==0) then
	begin
		zbir=0;
		exit;
	end;
	zbir=a+zbir(a-1);
	exit;
end;

procedure test1();
var mata:knjiga;
test:int;
begin
	test=hari.godina;
	exit;
	writeln(test);
end;
begin
	fl=4.6;
	hari.godina=fl;
	hari.strane[1].broj=40;
	ulica=4;
	provera2=@ulica;
	writeln(provera2);
	ili=0;
	read(grad);
	writeln(grad);
	ulica=test(hari.godina,hari.strane[1].broj);
	while ulica>ili do
	begin
		writeln(ulica);
		if( ulica==1) then
		begin
			break;
		end;
		writeln(zbir(8));
		ulica=ulica-1;
	end;
	test1();
	
end.

