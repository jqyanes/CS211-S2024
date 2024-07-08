input [7:0] minuend;
input [7:0] subtrahend;
output [7:0] difference;

wire inv_subtrahend_7;
wire inv_subtrahend_6;
wire inv_subtrahend_5;
wire inv_subtrahend_4;
wire inv_subtrahend_3;
wire inv_subtrahend_2;
wire inv_subtrahend_1;
wire inv_subtrahend_0;

wire negator_carry_0;
wire negator_carry_1;
wire negator_carry_2;
wire negator_carry_3;
wire negator_carry_4;
wire negator_carry_5;
wire negator_carry_6;
wire negator_carry_7;

wire neg_subtrahend_7;
wire neg_subtrahend_6;
wire neg_subtrahend_5;
wire neg_subtrahend_4;
wire neg_subtrahend_3;
wire neg_subtrahend_2;
wire neg_subtrahend_1;
wire neg_subtrahend_0;

wire carry_0;
wire carry_1;
wire carry_2;
wire carry_3;
wire carry_4;
wire carry_5;
wire carry_6;

wire xor_1_and_carry;
wire xor_2_and_carry;
wire xor_3_and_carry;
wire xor_4_and_carry;
wire xor_5_and_carry;
wire xor_6_and_carry;

wire 1_and_1;
wire 2_and_2;
wire 3_and_3;
wire 4_and_4;
wire 5_and_5;
wire 6_and_6;

wire 1_xor_1;
wire 2_xor_2;
wire 3_xor_3;
wire 4_xor_4;
wire 5_xor_5;
wire 6_xor_6;
wire 7_xor_7;



assign inv_subtrahend_7 = ~ subtrahend[7];
assign inv_subtrahend_6 = ~ subtrahend[6];
assign inv_subtrahend_5 = ~ subtrahend[5];
assign inv_subtrahend_4 = ~ subtrahend[4];
assign inv_subtrahend_3 = ~ subtrahend[3];
assign inv_subtrahend_2 = ~ subtrahend[2];
assign inv_subtrahend_1 = ~ subtrahend[1];
assign inv_subtrahend_0 = ~ subtrahend[0];

assign negator_carry_0 = inv_subtrahend_0;
assign negator_carry_1 = negator_carry_0 & inv_subtrahend_1;
assign negator_carry_2 = negator_carry_1 & inv_subtrahend_2;
assign negator_carry_3 = negator_carry_2 & inv_subtrahend_3;
assign negator_carry_4 = negator_carry_3 & inv_subtrahend_4;
assign negator_carry_5 = negator_carry_4 & inv_subtrahend_5;
assign negator_carry_6 = negator_carry_5 & inv_subtrahend_6;
assign negator_carry_7 = negator_carry_6 & inv_subtrahend_7;

assign neg_subtrahend_0 = ~ inv_subtrahend_0;
assign neg_subtrahend_1 = negator_carry_0 ^ inv_subtrahend_1;
assign neg_subtrahend_2 = negator_carry_1 ^ inv_subtrahend_2;
assign neg_subtrahend_3 = negator_carry_2 ^ inv_subtrahend_3;
assign neg_subtrahend_4 = negator_carry_3 ^ inv_subtrahend_4;
assign neg_subtrahend_5 = negator_carry_4 ^ inv_subtrahend_5;
assign neg_subtrahend_6 = negator_carry_5 ^ inv_subtrahend_6;
assign neg_subtrahend_7 = negator_carry_6 ^ inv_subtrahend_7;

assign difference[0] = minuend[0] ^ neg_subtrahend_0;
assign carry_0 = minuend[0] & neg_subtrahend_0;

assign 1_and_1 = minuend[1] & neg_subtrahend_1;
assign 2_and_2 = minuend[2] & neg_subtrahend_2;
assign 3_and_3 = minuend[3] & neg_subtrahend_3;
assign 4_and_4 = minuend[4] & neg_subtrahend_4;
assign 5_and_5 = minuend[5] & neg_subtrahend_5;
assign 6_and_6 = minuend[6] & neg_subtrahend_6;

assign 1_xor_1 = minuend[1] ^ neg_subtrahend_1;
assign 2_xor_2 = minuend[2] ^ neg_subtrahend_2;
assign 3_xor_3 = minuend[3] ^ neg_subtrahend_3;
assign 4_xor_4 = minuend[4] ^ neg_subtrahend_4;
assign 5_xor_5 = minuend[5] ^ neg_subtrahend_5;
assign 6_xor_6 = minuend[6] ^ neg_subtrahend_6;
assign 7_xor_7 = minuend[7] ^ neg_subtrahend_7;

assign difference[1] = 1_xor_1 ^ carry_0;
assign xor_1_and_carry = 1_xor_1 & carry_0;
assign carry_1 = xor_1_and_carry | 1_and_1;

assign difference[2] = 2_xor_2 ^ carry_1;
assign xor_2_and_carry = 2_xor_2 & carry_1;
assign carry_2 = xor_2_and_carry | 2_and_2;

assign difference[3] = 3_xor_3 ^ carry_2;
assign xor_3_and_carry = 3_xor_3 & carry_2;
assign carry_3 = xor_3_and_carry | 3_and_3;

assign difference[4] = 4_xor_4 ^ carry_3;
assign xor_4_and_carry = 4_xor_4 & carry_3;
assign carry_4 = xor_4_and_carry | 4_and_4;

assign difference[5] = 5_xor_5 ^ carry_4;
assign xor_5_and_carry = 5_xor_5 & carry_4;
assign carry_5 = xor_5_and_carry | 5_and_5;

assign difference[6] = 6_xor_6 ^ carry_5;
assign xor_6_and_carry = 6_xor_6 & carry_5;
assign carry_6 = xor_6_and_carry | 6_and_6;

assign difference[7] = 7_xor_7 ^ carry_6;

