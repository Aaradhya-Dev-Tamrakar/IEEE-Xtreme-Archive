var n,m,i,j,k,t,zz,ans:longint;
    a,b:array[0..100100]of longint;
    pop:array[-10000..10000]of longint;
function gcd(a,b:longint):longint;
begin if (a mod b)=0 then exit(b);exit(gcd(b,a mod b));end;

procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l;j:=r;x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if not(i>j) then begin
      y:=a[i];a[i]:=a[j];a[j]:=y;
      inc(i);j:=j-1;
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
readln(n,k);m:=gcd(n,k);
for i:=1 to n do read(b[i]);
for i:=1 to m do begin
  fillchar(pop,sizeof(pop),0);
  for j:=0 to (n div m)-1 do a[j+1]:=b[j*m+i];
  sort(1,n div m);
  t:=a[(n div m+1)div 2];
  for j:=1 to (n div m) do ans:=ans+abs(a[j]-t);
end;
writeln(ans);
end.


