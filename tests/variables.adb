with Ada.Text_IO; use Ada.Text_IO;

procedure Variables is
    Count : Integer := 10;
    Ratio : Float := 2.5;
    Ready : Boolean := True;
begin
    Count := Count + 1;
    Put_Line ("Variables test");
end Variables;
