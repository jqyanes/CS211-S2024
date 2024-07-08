input [3:0] numeral_bit;

output a; 
output b;
output c;
output d;
output e;
output f;
output g;

wire not_numeral_bit_3;
wire not_numeral_bit_2;
wire not_numeral_bit_1;
wire not_numeral_bit_0;

wire is_00;
wire is_01;
wire is_02;
wire is_03;
wire is_04;
wire is_05;
wire is_06;
wire is_07;
wire is_08;
wire is_09;

wire not_00;
wire not_01;
wire not_02;
wire not_03;
wire not_04;
wire not_05;
wire not_06;
wire not_07;
wire not_08;
wire not_09;

wire not_3_and_not_2;
wire not_1_and_not_0;
wire not_1_and_0;
wire 1_and_not_0;
wire 1_and_0;
wire not_3_and_2;
wire 3_and_not_2;
wire is_00_or_is_02;
wire is_06_or_is_08;
wire not_01_and_not_07;
wire not_02_and_not_03;
wire not_00_and_not_01;

assign not_numeral_bit_3 = ~ numeral_bit[3];
assign not_numeral_bit_2 = ~ numeral_bit[2];
assign not_numeral_bit_1 = ~ numeral_bit[1];
assign not_numeral_bit_0 = ~ numeral_bit[0];

assign not_3_and_not_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_1_and_not_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign not_1_and_0 = not_numeral_bit_1 & numeral_bit[0];
assign 1_and_not_0 = numeral_bit[1] & not_numeral_bit_0;
assign 1_and_0 = numeral_bit[1] & numeral_bit[0];
assign not_3_and_2 = not_numeral_bit_3 & numeral_bit[2];
assign 3_and_not_2 = numeral_bit[3] & not_numeral_bit_2;

assign is_00 = not_3_and_not_2 & not_1_and_not_0;
assign is_01 = not_3_and_not_2 & not_1_and_0;
assign is_02 = not_3_and_not_2 & 1_and_not_0;
assign is_03 = not_3_and_not_2 & 1_and_0;
assign is_04 = not_3_and_2 & not_1_and_not_0;
assign is_05 = not_3_and_2 & not_1_and_0;
assign is_06 = not_3_and_2 & 1_and_not_0;
assign is_07 = not_3_and_2 & 1_and_0;
assign is_08 = 3_and_not_2 & not_1_and_not_0;
assign is_09 = 3_and_not_2 & not_1_and_0;

assign not_00 = ~ is_00;
assign not_01 = ~ is_01;
assign not_02 = ~ is_02;
assign not_03 = ~ is_03;
assign not_04 = ~ is_04;
assign not_05 = ~ is_05;
assign not_06 = ~ is_06;
assign not_07 = ~ is_07;
assign not_08 = ~ is_08;
assign not_09 = ~ is_09;

assign is_00_or_is_02 = is_00 | is_02;
assign is_06_or_is_08 = is_06 | is_08;
assign not_01_and_not_07 = not_01 & not_07;
assign not_02_and_not_03 = not_02 & not_03;
assign not_00_and_not_01 = not_00 & not_01;

assign a = not_01 & not_04;
assign b = not_05 & not_06;
assign c = not_02;
assign d = a & not_07;
assign e = is_00_or_is_02 | is_06_or_is_08;
assign f = not_01_and_not_07 & not_02_and_not_03;
assign g = not_00 & not_01_and_not_07;
