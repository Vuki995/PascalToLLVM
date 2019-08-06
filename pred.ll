
%knjiga = type { [7 x i8*], i32, [19 x %strana] }
%strana = type { i32, i32 }

@ber = common global [1 x [2 x i8*]]* null
@hari = common global %knjiga zeroinitializer
@fl = common global float 0.000000e+00
@provera = common global i32** null
@provera2 = common global i32* null
@ulica = common global i32 0
@kuca = common global [1 x [7 x i8*]] zeroinitializer
@kucica = common global float 0.000000e+00
@grad = common global i8 0
@te = common global i1 0
@ili = common global i32 0
@str = private unnamed_addr constant [3 x i8] c"%d\00"
@str.1 = private unnamed_addr constant [2 x i8] c"\0A\00"
@str.2 = private unnamed_addr constant [3 x i8] c"%c\00"
@str.3 = private unnamed_addr constant [3 x i8] c"\5Cn\00"

define i32 @test(i32 %a, i32 %b) {
entry:
  %test = alloca i32
  %mata = alloca %knjiga
  %b2 = alloca i32
  %a1 = alloca i32
  store i32 %a, i32* %a1
  store i32 %b, i32* %b2
  store i32 4, i32* getelementptr inbounds (%knjiga, %knjiga* @hari, i32 0, i32 1)
  store i8 99, i8* @grad
  store i1 true, i1* @te
  %loadtmp = load i32, i32* getelementptr inbounds (%knjiga, %knjiga* @hari, i32 0, i32 1)
  store i32 %loadtmp, i32* %test
  %retval = load i32, i32* %test
  ret i32 %retval
  %loadtmp3 = load i32, i32* %a1
  %loadtmp4 = load i32, i32* %b2
  %addtmp = add i32 %loadtmp3, %loadtmp4
  %writeln = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str, i32 0, i32 0), i32 %addtmp)
  %newline = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @str.1, i32 0, i32 0))
  %test5 = load i32, i32* %test
  ret i32 %test5
}

declare i32 @printf(i8*, ...)

define i32 @zbir(i32 %a) {
entry:
  %zbir = alloca i32
  %a1 = alloca i32
  store i32 %a, i32* %a1
  %loadtmp = load i32, i32* %a1
  %eqtmp = icmp eq i32 %loadtmp, 0
  br i1 %eqtmp, label %then, label %ifcont

then:                                             ; preds = %entry
  store i32 0, i32* %zbir
  %retval = load i32, i32* %zbir
  ret i32 %retval
  br label %ifcont

ifcont:                                           ; preds = %then, %entry
  %loadtmp2 = load i32, i32* %a1
  %subtmp = sub i32 %loadtmp2, 1
  %calltmp = call i32 @zbir(i32 %subtmp)
  %loadtmp3 = load i32, i32* %a1
  %addtmp = add i32 %loadtmp3, %calltmp
  store i32 %addtmp, i32* %zbir
  %retval4 = load i32, i32* %zbir
  ret i32 %retval4
  %zbir5 = load i32, i32* %zbir
  ret i32 %zbir5
}

define void @test1() {
entry:
  %test = alloca i32
  %mata = alloca %knjiga
  %loadtmp = load i32, i32* getelementptr inbounds (%knjiga, %knjiga* @hari, i32 0, i32 1)
  store i32 %loadtmp, i32* %test
  ret void
  %loadtmp1 = load i32, i32* %test
  %writeln = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str, i32 0, i32 0), i32 %loadtmp1)
  %newline = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @str.1, i32 0, i32 0))
  ret void
}

define i32 @main() {
entry:
  store float 0x4012666660000000, float* @fl
  %loadtmp = load float, float* @fl
  %conv = fptosi float %loadtmp to i32
  store i32 %conv, i32* getelementptr inbounds (%knjiga, %knjiga* @hari, i32 0, i32 1)
  store i32 40, i32* getelementptr inbounds (%knjiga, %knjiga* @hari, i32 0, i32 2, i64 1, i32 0)
  store i32 4, i32* @ulica
  store i32* @ulica, i32** @provera2
  %loadtmp1 = load i32*, i32** @provera2
  %writeln = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str, i32 0, i32 0), i32* %loadtmp1)
  %newline = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @str.1, i32 0, i32 0))
  store i32 0, i32* @ili
  %read = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str.2, i32 0, i32 0), i8* @grad)
  %loadtmp2 = load i8, i8* @grad
  %writechr = call i32 @putchar(i8 %loadtmp2)
  %loadtmp3 = load i32, i32* getelementptr inbounds (%knjiga, %knjiga* @hari, i32 0, i32 1)
  %loadtmp4 = load i32, i32* getelementptr inbounds (%knjiga, %knjiga* @hari, i32 0, i32 2, i64 1, i32 0)
  %calltmp = call i32 @test(i32 %loadtmp3, i32 %loadtmp4)
  store i32 %calltmp, i32* @ulica
  br label %beforeloop

beforeloop:                                       ; preds = %ifcont, %entry
  %loadtmp5 = load i32, i32* @ulica
  %loadtmp6 = load i32, i32* @ili
  %grtrtmp = icmp sgt i32 %loadtmp5, %loadtmp6
  br i1 %grtrtmp, label %loop, label %afterloop

loop:                                             ; preds = %beforeloop
  %loadtmp7 = load i32, i32* @ulica
  %writeln8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str, i32 0, i32 0), i32 %loadtmp7)
  %newline9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @str.1, i32 0, i32 0))
  %loadtmp10 = load i32, i32* @ulica
  %eqtmp = icmp eq i32 %loadtmp10, 1
  br i1 %eqtmp, label %then, label %ifcont

then:                                             ; preds = %loop
  br label %afterloop
  br label %ifcont

ifcont:                                           ; preds = %then, %loop
  %calltmp11 = call i32 @zbir(i32 8)
  %writeln12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str, i32 0, i32 0), i32 %calltmp11)
  %newline13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @str.1, i32 0, i32 0))
  %writeln14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @str.3, i32 0, i32 0))
  %newline15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @str.1, i32 0, i32 0))
  %loadtmp16 = load i32, i32* @ulica
  %subtmp = sub i32 %loadtmp16, 1
  store i32 %subtmp, i32* @ulica
  br label %beforeloop

afterloop:                                        ; preds = %then, %beforeloop
  call void @test1()
  ret i32 0
}

declare i32 @scanf(i8*, ...)

declare i32 @putchar(i8)
