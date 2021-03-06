{
ID:hzhua201
PROB:ditch
LANG:PASCAL
}

const maxn=200;

var a:array[0..maxn+1,0..maxn+1] of longint;
    gap,gapv:array[0..maxn+1] of longint;
    n,m,i1,i2,t1,t2,t3,aug,flow:longint;
    flag:boolean;


procedure init;
begin
    assign(input,'ditch.in');
    reset(input);
    assign(output,'ditch.out');
    rewrite(output);
end;


procedure endln;
begin
    close(input);
    close(output);
    halt;
end;


procedure auge(p:longint);
var mingap,augt,i1:longint;
begin
    mingap:=n-1;
    augt:=aug;
    if p=n then
      begin
        inc(flow,aug);
        flag:=true;
        exit;
      end;
    for i1:=1 to n do
      if a[p,i1]>0 then
        begin
          if gap[i1]+1=gap[p] then
            begin
              if a[p,i1]<aug then
                aug:=a[p,i1];
              auge(i1);
              if gap[1]>=n then exit;
              if flag then break;
              aug:=augt;
            end;
          if gap[i1]<mingap then mingap:=gap[i1];
        end;
    if not flag then
        begin
          dec(gapv[gap[p]]);
          if gapv[gap[p]]=0 then gap[1]:=n;
          gap[p]:=mingap+1;
          inc(gapv[gap[p]]);
        end
      else
        begin
          dec(a[p,i1],aug);
          inc(a[i1,p],aug);
        end;
end;

begin
init;
fillchar(a,sizeof(a),0);
fillchar(gap,sizeof(gap),0);
fillchar(gapv,sizeof(gapv),0);
read(m,n);
for i1:=1 to m do
    begin
      read(t1,t2,t3);
      inc(a[t1,t2],t3);
    end;
gapv[0]:=n;
flow:=0;
while gap[1]<n do
    begin
      aug:=maxlongint;
      flag:=false;
      auge(1);
    end;
writeln(flow);
endln;
end.
