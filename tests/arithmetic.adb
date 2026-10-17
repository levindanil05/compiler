with Ada.Text_IO; use Ada.Text_IO;

procedure Arithmetic is
    A : Integer := 12;
    B : Integer := 4;
    Sum : Integer;
    Difference : Integer;
begin
    Sum := A + B;
    Difference := A - B;
    Put_Line ("Arithmetic test");
end Arithmetic;
