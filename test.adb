with Ada.Text_IO;             use Ada.Text_IO;
with Ada.Integer_Text_IO;     use Ada.Integer_Text_IO;
with Ada.Float_Text_IO;       use Ada.Float_Text_IO;
with Ada.Strings.Fixed;       use Ada.Strings.Fixed;
with Ada.Numerics.Elementary_Functions; use Ada.Numerics.Elementary_Functions;

procedure Factory_Simulator_Test is

   -- =========================================================================
   -- 1. ТИПЫ И ПЕРЕЧИСЛЕНИЯ
   -- =========================================================================
   
   type Part_Kind is (
      Gear, Shaft, Bearing, Bolt, Nut, Washer, Spring, Valve, Piston, Cylinder,
      Rotor, Stator, Coil, Core, Magnet, Sensor, Actuator, Relay, Switch, Fuse,
      Wire, Cable, Connector, Terminal, Board, Chip, Resistor, Capacitor, Diode, Transistor
   );

   type Status_Type is (Idle, Running, Error, Maintenance, Offline, Unknown);

   type Station_ID is range 1 .. 50;
   type Matrix_Index is range 1 .. 20;

   type Station_Record is record
      ID        : Station_ID;
      Kind      : Part_Kind;
      Status    : Status_Type;
      Efficiency: Float;
      Load      : Integer;
   end record;

   type Station_Array is array (Station_ID) of Station_Record;
   type Matrix_Type is array (Matrix_Index, Matrix_Index) of Float;
   type Config_Array is array (1 .. 50) of Integer;

   -- =========================================================================
   -- 2. КОНСТАНТЫ И ИНИЦИАЛИЗАЦИЯ МАССИВОВ
   -- =========================================================================

   Default_Config : constant Config_Array := (
      10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
      11, 21, 31, 41, 51, 61, 71, 81, 91, 101,
      12, 22, 32, 42, 52, 62, 72, 82, 92, 102,
      13, 23, 33, 43, 53, 63, 73, 83, 93, 103,
      14, 24, 34, 44, 54, 64, 74, 84, 94, 104
   );

   -- =========================================================================
   -- 3. ФУНКЦИИ С БОЛЬШИМИ ОПЕРАТОРАМИ CASE
   -- =========================================================================

   function Get_Base_Weight (P : Part_Kind) return Float is
   begin
      case P is
         when Gear       => return 1.25;
         when Shaft      => return 3.40;
         when Bearing    => return 0.85;
         when Bolt       => return 0.12;
         when Nut        => return 0.05;
         when Washer     => return 0.02;
         when Spring     => return 0.15;
         when Valve      => return 2.10;
         when Piston     => return 4.50;
         when Cylinder   => return 8.30;
         when Rotor      => return 5.60;
         when Stator     => return 6.20;
         when Coil       => return 1.80;
         when Core       => return 3.10;
         when Magnet     => return 0.95;
         when Sensor     => return 0.35;
         when Actuator   => return 2.75;
         when Relay      => return 0.45;
         when Switch     => return 0.25;
         when Fuse       => return 0.10;
         when Wire       => return 0.08;
         when Cable      => return 1.50;
         when Connector  => return 0.30;
         when Terminal   => return 0.15;
         when Board      => return 0.55;
         when Chip       => return 0.01;
         when Resistor   => return 0.005;
         when Capacitor  => return 0.01;
         when Diode      => return 0.008;
         when Transistor => return 0.012;
      end case;
   end Get_Base_Weight;

   function Status_To_String (S : Status_Type) return String is
   begin
      case S is
         when Idle        => return "IDLE       ";
         when Running     => return "RUNNING    ";
         when Error       => return "ERROR      ";
         when Maintenance => return "MAINTENANCE";
         when Offline     => return "OFFLINE    ";
         when Unknown     => return "UNKNOWN    ";
      end case;
   end Status_To_String;

   -- =========================================================================
   -- 4. МАТЕМАТИКА МАТРИЦ
   -- =========================================================================

   procedure Initialize_Matrix (M : out Matrix_Type; Val : Float) is
   begin
      for I in Matrix_Index loop
         for J in Matrix_Index loop
            M(I, J) := Val;
         end loop;
      end loop;
   end Initialize_Matrix;

   procedure Multiply_Matrices (A, B : in Matrix_Type; C : out Matrix_Type) is
      Temp_Sum : Float;
   begin
      for I in Matrix_Index loop
         for J in Matrix_Index loop
            Temp_Sum := 0.0;
            for K in Matrix_Index loop
               Temp_Sum := Temp_Sum + A(I, K) * B(K, J);
            end loop;
            C(I, J) := Temp_Sum;
         end loop;
      end loop;
   end Multiply_Matrices;

   -- =========================================================================
   -- 5. БОЛЬШАЯ ЦЕПОЧКА IF-ELSIF
   -- =========================================================================

   procedure Assign_Priority (ID : Station_ID; Priority : out Integer) is
   begin
      if ID = 1 then Priority := 10;
      elsif ID = 2 then Priority := 12;
      elsif ID = 3 then Priority := 14;
      elsif ID = 4 then Priority := 16;
      elsif ID = 5 then Priority := 18;
      elsif ID = 6 then Priority := 20;
      elsif ID = 7 then Priority := 22;
      elsif ID = 8 then Priority := 24;
      elsif ID = 9 then Priority := 26;
      elsif ID = 10 then Priority := 28;
      elsif ID = 11 then Priority := 30;
      elsif ID = 12 then Priority := 32;
      elsif ID = 13 then Priority := 34;
      elsif ID = 14 then Priority := 36;
      elsif ID = 15 then Priority := 38;
      elsif ID = 16 then Priority := 40;
      elsif ID = 17 then Priority := 42;
      elsif ID = 18 then Priority := 44;
      elsif ID = 19 then Priority := 46;
      elsif ID = 20 then Priority := 48;
      elsif ID = 21 then Priority := 50;
      elsif ID = 22 then Priority := 52;
      elsif ID = 23 then Priority := 54;
      elsif ID = 24 then Priority := 56;
      elsif ID = 25 then Priority := 58;
      elsif ID = 26 then Priority := 60;
      elsif ID = 27 then Priority := 62;
      elsif ID = 28 then Priority := 64;
      elsif ID = 29 then Priority := 66;
      elsif ID = 30 then Priority := 68;
      elsif ID = 31 then Priority := 70;
      elsif ID = 32 then Priority := 72;
      elsif ID = 33 then Priority := 74;
      elsif ID = 34 then Priority := 76;
      elsif ID = 35 then Priority := 78;
      elsif ID = 36 then Priority := 80;
      elsif ID = 37 then Priority := 82;
      elsif ID = 38 then Priority := 84;
      elsif ID = 39 then Priority := 86;
      elsif ID = 40 then Priority := 88;
      elsif ID = 41 then Priority := 90;
      elsif ID = 42 then Priority := 92;
      elsif ID = 43 then Priority := 94;
      elsif ID = 44 then Priority := 96;
      elsif ID = 45 then Priority := 98;
      elsif ID = 46 then Priority := 100;
      elsif ID = 47 then Priority := 102;
      elsif ID = 48 then Priority := 104;
      elsif ID = 49 then Priority := 106;
      elsif ID = 50 then Priority := 108;
      else Priority := 0;
      end if;
   end Assign_Priority;

   -- =========================================================================
   -- 6. ГЛАВНЫЙ БЛОК И ВЛОЖЕННЫЕ ЦИКЛЫ
   -- =========================================================================

   Stations : Station_Array;
   Mat_A, Mat_B, Mat_C : Matrix_Type;
   Current_Priority : Integer;
   Total_Weight : Float := 0.0;

begin
   Put_Line("=== FACTORY SIMULATOR TEST STARTED ===");
   
   -- Инициализация станций
   for I in Station_ID loop
      Stations(I).ID := I;
      Stations(I).Kind := Part_Kind'Val((Integer(I) mod 30));
      Stations(I).Status := Running;
      Stations(I).Efficiency := Float(I) * 1.5;
      Stations(I).Load := Default_Config(Integer(I));
   end loop;

   -- Инициализация и перемножение матриц
   Initialize_Matrix(Mat_A, 1.05);
   Initialize_Matrix(Mat_B, 0.95);
   Multiply_Matrices(Mat_A, Mat_B, Mat_C);

   Put_Line("Processing stations...");
   
   -- Обработка станций
   for I in Station_ID loop
      Assign_Priority(I, Current_Priority);
      
      if Stations(I).Status = Running then
         Total_Weight := Total_Weight + Get_Base_Weight(Stations(I).Kind);
         
         -- Симуляция нагрузки
         for J in 1 .. 10 loop
            Stations(I).Efficiency := Stations(I).Efficiency * 1.01;
            if Stations(I).Efficiency > 150.0 then
               Stations(I).Status := Maintenance;
               exit;
            end if;
         end loop;
      end if;
      
      -- Вывод статуса (каждый 10-й)
      if Integer(I) mod 10 = 0 then
         Put("Station "); 
         Put(Integer(I), Width => 3);
         Put(" | Priority: ");
         Put(Current_Priority, Width => 4);
         Put(" | Status: ");
         Put_Line(Status_To_String(Stations(I).Status));
      end if;
   end loop;

   Put("Total calculated weight: ");
   Put(Total_Weight, Fore => 5, Aft => 3, Exp => 0);
   New_Line;
   
   Put_Line("=== FACTORY SIMULATOR TEST COMPLETED ===");

exception
   when Constraint_Error => 
      Put_Line("FATAL: Constraint Error occurred during simulation.");
   when Program_Error => 
      Put_Line("FATAL: Program Error detected.");
   when Storage_Error => 
      Put_Line("FATAL: Out of memory.");
   when others => 
      Put_Line("FATAL: Unknown exception caught.");
end Factory_Simulator_Test;