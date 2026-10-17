with Ada.Text_IO; use Ada.Text_IO;

procedure Functions is
    function Add (A : Integer; B : Integer) return Integer is
    begin
        return A + B;
    end Add;
    Result : Integer := Add (2, 3);
begin
    Put_Line ("Function test");
end Functions;
