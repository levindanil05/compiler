procedure Test is
   x : integer;
   y : float := 3.14;
   flag : boolean := true;
begin
   x := 1 + 2 * 3;
   if x > 5 then
      x := x - 1;
   elsif x = 5 then
      x := 0;
   else
      x := 10;
   end if;
   while x < 10 loop
      x := x + 1;
   end loop;
   return;
end Test;

