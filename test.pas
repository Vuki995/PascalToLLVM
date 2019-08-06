program Hello;
type
ime,prezime=int;
ti=array [3 .. 4] of array [0 .. 7] of ^char;
pas=ti;	
const
ime=23;
prezime='test';
var
ulica:int;
provera:^^int;
provera2:^int;
kuca:ti;
kucica:float;
grad: char;
te:bool;
a1:array [0 .. 2] of int;
a2:array [0 .. 2] of int;
function test(a,b:int) : int ;forward;
function test2(a,b:int) :array[1 .. 3]of array [2 .. 7] of ^ char ;
var flo:float;k:int;
begin
	k=test(a,b);
	test2=test2(a,b-1);
end;
function test(a,b:int) : int ;
begin
	writeln(2);
	test=3;
end;
procedure test3(a,b:int);
var
i:int;
begin
	for i = 2 to 5 do
	begin
		writeln(i);
		break;
	end;
end;
begin
	ulica=3;
	a1[0]=1;
	a1[1]=2;
	a2=a1;
	writeln(a2[1]);
	writeln((3+ulica)*3);
	provera2=@ulica;
	provera=@ provera2;
	provera=@ provera2;
	writeln(provera^^);
	te=true;
	ulica=ime;
	for i = 2 to 5 do
	begin
		writeln(i);
		continue;
	end;
	ulica=test(1,2)+2;
	test3(3,4);
	writeln('test');
	if(2<3)then
	begin
		if(2)then
		begin
			writeln('test');
		end;		
	end
	else
	begin
		writeln(2);
	end;
	ulica=1;
	repeat
		ulica=ulica+1;
		writeln('petlja');
		writeln(test(5,6));
	until ulica == 4 ;
end.

