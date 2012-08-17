{$mode objfpc}

program BA_Player;
uses crt,sysutils,cthreads,unix,strings;
var
f:file of byte;
t:byte;
i,j,k,z:integer;
tempstr:ansistring;

Function PlayAudio(p : pointer):Longint;
var pp:PPChar;
begin
getmem(pp,3*sizeof(PChar));
PP[0]:='/usr/bin/ffplay';
PP[1]:='-nodisp';
PP[2]:='t.mp3';
pp[3]:=nil;
fpexecv('/usr/bin/ffplay',pp);
playaudio:=0;
End;


begin
assign(f,'img.data');reset(f);
//BeginThread(@playaudio);
for z:=1 to 5256 do
begin
tempstr:='';
for i:=1 to 60 do
  begin
  for j:=1 to 10 do
    begin
    read(f,t);
    for k:=0 to 7 do
      if (t and (1 shl k))>0 then
        tempstr+='BA'
      else
        tempstr+=#32#32
    end;
  tempstr+=#10#13
  end;
writeln(tempstr);
sleep(40);
clrscr();  
end;
close(f);
end.
