with Ada.Text_IO; use Ada.Text_IO;

procedure Conditions is
    Value : Integer := 7;
begin
    if Value > 0 then
        Put_Line ("positive");
    else
        Put_Line ("not positive");
    end if;
end Conditions;
