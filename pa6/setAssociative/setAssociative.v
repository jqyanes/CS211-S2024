input [2:0]  read_address;

input        set_0_line_0_valid;
input        set_0_line_0_tag;
input [15:0] set_0_line_0_block;

input        set_0_line_1_valid;
input        set_0_line_1_tag;
input [15:0] set_0_line_1_block;

input        set_1_line_0_valid;
input        set_1_line_0_tag;
input [15:0] set_1_line_0_block;

input        set_1_line_1_valid;
input        set_1_line_1_tag;
input [15:0] set_1_line_1_block;

output       read_hit;
output [7:0] read_byte;

wire set_0_select;
wire set_1_select;

wire set_0_line_0_valid_select;
wire set_0_line_1_valid_select;
wire set_1_line_0_valid_select;
wire set_1_line_1_valid_select;
wire set_0_valid_select;
wire set_1_valid_select;
wire line_0_valid_select;
wire line_1_valid_select;

wire set_0_line_0_match;
wire set_0_line_1_match;
wire set_1_line_0_match;
wire set_1_line_1_match;
wire set_0_match;
wire set_1_match;
wire line_0_match;
wire line_1_match;

wire set_0_line_0_hit;
wire set_0_line_1_hit;
wire set_1_line_0_hit;
wire set_1_line_1_hit;
wire line_0_hit;
wire line_1_hit;

wire a_select;
wire b_select;

wire set_0_a_select;
wire set_0_b_select;
wire set_1_a_select;
wire set_1_b_select;
wire set_0_a_0_select;
wire set_0_b_0_select;
wire set_1_a_0_select;
wire set_1_b_0_select;
wire set_0_a_1_select;
wire set_0_b_1_select;
wire set_1_a_1_select;
wire set_1_b_1_select;

wire set_0_a_line_0_block_07_select;
wire set_0_a_line_0_block_06_select;
wire set_0_a_line_0_block_05_select;
wire set_0_a_line_0_block_04_select;
wire set_0_a_line_0_block_03_select;
wire set_0_a_line_0_block_02_select;
wire set_0_a_line_0_block_01_select;
wire set_0_a_line_0_block_00_select;

wire set_1_a_line_0_block_07_select;
wire set_1_a_line_0_block_06_select;
wire set_1_a_line_0_block_05_select;
wire set_1_a_line_0_block_04_select;
wire set_1_a_line_0_block_03_select;
wire set_1_a_line_0_block_02_select;
wire set_1_a_line_0_block_01_select;
wire set_1_a_line_0_block_00_select;

wire set_0_b_line_0_block_07_select;
wire set_0_b_line_0_block_06_select;
wire set_0_b_line_0_block_05_select;
wire set_0_b_line_0_block_04_select;
wire set_0_b_line_0_block_03_select;
wire set_0_b_line_0_block_02_select;
wire set_0_b_line_0_block_01_select;
wire set_0_b_line_0_block_00_select;

wire set_1_b_line_0_block_07_select;
wire set_1_b_line_0_block_06_select;
wire set_1_b_line_0_block_05_select;
wire set_1_b_line_0_block_04_select;
wire set_1_b_line_0_block_03_select;
wire set_1_b_line_0_block_02_select;
wire set_1_b_line_0_block_01_select;
wire set_1_b_line_0_block_00_select;

wire set_0_line_0_block_07_select;
wire set_0_line_0_block_06_select;
wire set_0_line_0_block_05_select;
wire set_0_line_0_block_04_select;
wire set_0_line_0_block_03_select;
wire set_0_line_0_block_02_select;
wire set_0_line_0_block_01_select;
wire set_0_line_0_block_00_select;

wire set_1_line_0_block_07_select;
wire set_1_line_0_block_06_select;
wire set_1_line_0_block_05_select;
wire set_1_line_0_block_04_select;
wire set_1_line_0_block_03_select;
wire set_1_line_0_block_02_select;
wire set_1_line_0_block_01_select;
wire set_1_line_0_block_00_select;

wire set_0_a_line_1_block_07_select;
wire set_0_a_line_1_block_06_select;
wire set_0_a_line_1_block_05_select;
wire set_0_a_line_1_block_04_select;
wire set_0_a_line_1_block_03_select;
wire set_0_a_line_1_block_02_select;
wire set_0_a_line_1_block_01_select;
wire set_0_a_line_1_block_00_select;

wire set_1_a_line_1_block_07_select;
wire set_1_a_line_1_block_06_select;
wire set_1_a_line_1_block_05_select;
wire set_1_a_line_1_block_04_select;
wire set_1_a_line_1_block_03_select;
wire set_1_a_line_1_block_02_select;
wire set_1_a_line_1_block_01_select;
wire set_1_a_line_1_block_00_select;

wire set_0_b_line_1_block_07_select;
wire set_0_b_line_1_block_06_select;
wire set_0_b_line_1_block_05_select;
wire set_0_b_line_1_block_04_select;
wire set_0_b_line_1_block_03_select;
wire set_0_b_line_1_block_02_select;
wire set_0_b_line_1_block_01_select;
wire set_0_b_line_1_block_00_select;

wire set_1_b_line_1_block_07_select;
wire set_1_b_line_1_block_06_select;
wire set_1_b_line_1_block_05_select;
wire set_1_b_line_1_block_04_select;
wire set_1_b_line_1_block_03_select;
wire set_1_b_line_1_block_02_select;
wire set_1_b_line_1_block_01_select;
wire set_1_b_line_1_block_00_select;

wire set_0_line_1_block_07_select;
wire set_0_line_1_block_06_select;
wire set_0_line_1_block_05_select;
wire set_0_line_1_block_04_select;
wire set_0_line_1_block_03_select;
wire set_0_line_1_block_02_select;
wire set_0_line_1_block_01_select;
wire set_0_line_1_block_00_select;

wire set_1_line_1_block_07_select;
wire set_1_line_1_block_06_select;
wire set_1_line_1_block_05_select;
wire set_1_line_1_block_04_select;
wire set_1_line_1_block_03_select;
wire set_1_line_1_block_02_select;
wire set_1_line_1_block_01_select;
wire set_1_line_1_block_00_select;

wire line_0_block_07;
wire line_0_block_06;
wire line_0_block_05;
wire line_0_block_04;
wire line_0_block_03;
wire line_0_block_02;
wire line_0_block_01;
wire line_0_block_00;

wire line_1_block_07;
wire line_1_block_06;
wire line_1_block_05;
wire line_1_block_04;
wire line_1_block_03;
wire line_1_block_02;
wire line_1_block_01;
wire line_1_block_00;

wire line_0_block_07_match;
wire line_0_block_06_match;
wire line_0_block_05_match;
wire line_0_block_04_match;
wire line_0_block_03_match;
wire line_0_block_02_match;
wire line_0_block_01_match;
wire line_0_block_00_match;

wire line_1_block_07_match;
wire line_1_block_06_match;
wire line_1_block_05_match;
wire line_1_block_04_match;
wire line_1_block_03_match;
wire line_1_block_02_match;
wire line_1_block_01_match;
wire line_1_block_00_match;

wire block_07;
wire block_06;
wire block_05;
wire block_04;
wire block_03;
wire block_02;
wire block_01;
wire block_00;

assign set_0_select = ~read_address[1];
assign set_1_select = ~set_0_select;

assign set_0_line_0_valid_select = set_0_select & set_0_line_0_valid;
assign set_0_line_1_valid_select = set_0_select & set_0_line_1_valid;
assign set_1_line_0_valid_select = set_1_select & set_1_line_0_valid;
assign set_1_line_1_valid_select = set_1_select & set_1_line_1_valid;

assign set_0_line_0_match = read_address[2] ~^ set_0_line_0_tag;
assign set_0_line_1_match = read_address[2] ~^ set_0_line_1_tag;
assign set_1_line_0_match = read_address[2] ~^ set_1_line_0_tag;
assign set_1_line_1_match = read_address[2] ~^ set_1_line_1_tag;
assign line_0_match = set_0_line_0_match | set_1_line_0_match;
assign line_1_match = set_0_line_1_match | set_1_line_1_match;

assign set_0_line_0_hit = set_0_line_0_valid_select & set_0_line_0_match;
assign set_0_line_1_hit = set_0_line_1_valid_select & set_0_line_1_match;
assign set_1_line_0_hit = set_1_line_0_valid_select & set_1_line_0_match;
assign set_1_line_1_hit = set_1_line_1_valid_select & set_1_line_1_match;
assign line_0_hit = set_0_line_0_hit | set_1_line_0_hit;
assign line_1_hit = set_0_line_1_hit | set_1_line_1_hit;

assign read_hit = line_0_hit | line_1_hit;

assign b_select = read_address[0];
assign a_select = ~b_select;


assign set_0_a_select = set_0_select & a_select;
assign set_0_b_select = set_0_select & b_select;
assign set_1_a_select = set_1_select & a_select;
assign set_1_b_select = set_1_select & b_select;
assign set_0_a_0_select = set_0_line_0_match & set_0_a_select;
assign set_0_b_0_select = set_0_line_0_match & set_0_b_select;
assign set_0_a_1_select = set_0_line_1_match & set_0_a_select;
assign set_0_b_1_select = set_0_line_1_match & set_0_b_select;
assign set_1_a_0_select = set_1_line_0_match & set_1_a_select;
assign set_1_b_0_select = set_1_line_0_match & set_1_b_select;
assign set_1_a_1_select = set_1_line_1_match & set_1_a_select;
assign set_1_b_1_select = set_1_line_1_match & set_1_b_select;

assign set_0_a_line_0_block_07_select = set_0_a_0_select & set_0_line_0_block[7];
assign set_0_a_line_0_block_06_select = set_0_a_0_select & set_0_line_0_block[6];
assign set_0_a_line_0_block_05_select = set_0_a_0_select & set_0_line_0_block[5];
assign set_0_a_line_0_block_04_select = set_0_a_0_select & set_0_line_0_block[4];
assign set_0_a_line_0_block_03_select = set_0_a_0_select & set_0_line_0_block[3];
assign set_0_a_line_0_block_02_select = set_0_a_0_select & set_0_line_0_block[2];
assign set_0_a_line_0_block_01_select = set_0_a_0_select & set_0_line_0_block[1];
assign set_0_a_line_0_block_00_select = set_0_a_0_select & set_0_line_0_block[0];

assign set_1_a_line_0_block_07_select = set_1_a_0_select & set_1_line_0_block[7];
assign set_1_a_line_0_block_06_select = set_1_a_0_select & set_1_line_0_block[6];
assign set_1_a_line_0_block_05_select = set_1_a_0_select & set_1_line_0_block[5];
assign set_1_a_line_0_block_04_select = set_1_a_0_select & set_1_line_0_block[4];
assign set_1_a_line_0_block_03_select = set_1_a_0_select & set_1_line_0_block[3];
assign set_1_a_line_0_block_02_select = set_1_a_0_select & set_1_line_0_block[2];
assign set_1_a_line_0_block_01_select = set_1_a_0_select & set_1_line_0_block[1];
assign set_1_a_line_0_block_00_select = set_1_a_0_select & set_1_line_0_block[0];

assign set_0_a_line_1_block_07_select = set_0_a_1_select & set_0_line_1_block[7];
assign set_0_a_line_1_block_06_select = set_0_a_1_select & set_0_line_1_block[6];
assign set_0_a_line_1_block_05_select = set_0_a_1_select & set_0_line_1_block[5];
assign set_0_a_line_1_block_04_select = set_0_a_1_select & set_0_line_1_block[4];
assign set_0_a_line_1_block_03_select = set_0_a_1_select & set_0_line_1_block[3];
assign set_0_a_line_1_block_02_select = set_0_a_1_select & set_0_line_1_block[2];
assign set_0_a_line_1_block_01_select = set_0_a_1_select & set_0_line_1_block[1];
assign set_0_a_line_1_block_00_select = set_0_a_1_select & set_0_line_1_block[0];

assign set_1_a_line_1_block_07_select = set_1_a_1_select & set_1_line_1_block[7];
assign set_1_a_line_1_block_06_select = set_1_a_1_select & set_1_line_1_block[6];
assign set_1_a_line_1_block_05_select = set_1_a_1_select & set_1_line_1_block[5];
assign set_1_a_line_1_block_04_select = set_1_a_1_select & set_1_line_1_block[4];
assign set_1_a_line_1_block_03_select = set_1_a_1_select & set_1_line_1_block[3];
assign set_1_a_line_1_block_02_select = set_1_a_1_select & set_1_line_1_block[2];
assign set_1_a_line_1_block_01_select = set_1_a_1_select & set_1_line_1_block[1];
assign set_1_a_line_1_block_00_select = set_1_a_1_select & set_1_line_1_block[0];

assign set_0_b_line_0_block_07_select = set_0_b_0_select & set_0_line_0_block[15];
assign set_0_b_line_0_block_06_select = set_0_b_0_select & set_0_line_0_block[14];
assign set_0_b_line_0_block_05_select = set_0_b_0_select & set_0_line_0_block[13];
assign set_0_b_line_0_block_04_select = set_0_b_0_select & set_0_line_0_block[12];
assign set_0_b_line_0_block_03_select = set_0_b_0_select & set_0_line_0_block[11];
assign set_0_b_line_0_block_02_select = set_0_b_0_select & set_0_line_0_block[10];
assign set_0_b_line_0_block_01_select = set_0_b_0_select & set_0_line_0_block[9];
assign set_0_b_line_0_block_00_select = set_0_b_0_select & set_0_line_0_block[8];

assign set_1_b_line_0_block_07_select = set_1_b_0_select & set_1_line_0_block[15];
assign set_1_b_line_0_block_06_select = set_1_b_0_select & set_1_line_0_block[14];
assign set_1_b_line_0_block_05_select = set_1_b_0_select & set_1_line_0_block[13];
assign set_1_b_line_0_block_04_select = set_1_b_0_select & set_1_line_0_block[12];
assign set_1_b_line_0_block_03_select = set_1_b_0_select & set_1_line_0_block[11];
assign set_1_b_line_0_block_02_select = set_1_b_0_select & set_1_line_0_block[10];
assign set_1_b_line_0_block_01_select = set_1_b_0_select & set_1_line_0_block[9];
assign set_1_b_line_0_block_00_select = set_1_b_0_select & set_1_line_0_block[8];

assign set_0_b_line_1_block_07_select = set_0_b_1_select & set_0_line_1_block[15];
assign set_0_b_line_1_block_06_select = set_0_b_1_select & set_0_line_1_block[14];
assign set_0_b_line_1_block_05_select = set_0_b_1_select & set_0_line_1_block[13];
assign set_0_b_line_1_block_04_select = set_0_b_1_select & set_0_line_1_block[12];
assign set_0_b_line_1_block_03_select = set_0_b_1_select & set_0_line_1_block[11];
assign set_0_b_line_1_block_02_select = set_0_b_1_select & set_0_line_1_block[10];
assign set_0_b_line_1_block_01_select = set_0_b_1_select & set_0_line_1_block[9];
assign set_0_b_line_1_block_00_select = set_0_b_1_select & set_0_line_1_block[8];

assign set_1_b_line_1_block_07_select = set_1_b_1_select & set_1_line_1_block[15];
assign set_1_b_line_1_block_06_select = set_1_b_1_select & set_1_line_1_block[14];
assign set_1_b_line_1_block_05_select = set_1_b_1_select & set_1_line_1_block[13];
assign set_1_b_line_1_block_04_select = set_1_b_1_select & set_1_line_1_block[12];
assign set_1_b_line_1_block_03_select = set_1_b_1_select & set_1_line_1_block[11];
assign set_1_b_line_1_block_02_select = set_1_b_1_select & set_1_line_1_block[10];
assign set_1_b_line_1_block_01_select = set_1_b_1_select & set_1_line_1_block[9];
assign set_1_b_line_1_block_00_select = set_1_b_1_select & set_1_line_1_block[8];

assign set_0_line_0_block_07_select = set_0_a_line_0_block_07_select | set_0_b_line_0_block_07_select;
assign set_0_line_0_block_06_select = set_0_a_line_0_block_06_select | set_0_b_line_0_block_06_select;
assign set_0_line_0_block_05_select = set_0_a_line_0_block_05_select | set_0_b_line_0_block_05_select;
assign set_0_line_0_block_04_select = set_0_a_line_0_block_04_select | set_0_b_line_0_block_04_select;
assign set_0_line_0_block_03_select = set_0_a_line_0_block_03_select | set_0_b_line_0_block_03_select;
assign set_0_line_0_block_02_select = set_0_a_line_0_block_02_select | set_0_b_line_0_block_02_select;
assign set_0_line_0_block_01_select = set_0_a_line_0_block_01_select | set_0_b_line_0_block_01_select;
assign set_0_line_0_block_00_select = set_0_a_line_0_block_00_select | set_0_b_line_0_block_00_select;

assign set_1_line_0_block_07_select = set_1_a_line_0_block_07_select | set_1_b_line_0_block_07_select;
assign set_1_line_0_block_06_select = set_1_a_line_0_block_06_select | set_1_b_line_0_block_06_select;
assign set_1_line_0_block_05_select = set_1_a_line_0_block_05_select | set_1_b_line_0_block_05_select;
assign set_1_line_0_block_04_select = set_1_a_line_0_block_04_select | set_1_b_line_0_block_04_select;
assign set_1_line_0_block_03_select = set_1_a_line_0_block_03_select | set_1_b_line_0_block_03_select;
assign set_1_line_0_block_02_select = set_1_a_line_0_block_02_select | set_1_b_line_0_block_02_select;
assign set_1_line_0_block_01_select = set_1_a_line_0_block_01_select | set_1_b_line_0_block_01_select;
assign set_1_line_0_block_00_select = set_1_a_line_0_block_00_select | set_1_b_line_0_block_00_select;

assign set_0_line_1_block_07_select = set_0_a_line_1_block_07_select | set_0_b_line_1_block_07_select;
assign set_0_line_1_block_06_select = set_0_a_line_1_block_06_select | set_0_b_line_1_block_06_select;
assign set_0_line_1_block_05_select = set_0_a_line_1_block_05_select | set_0_b_line_1_block_05_select;
assign set_0_line_1_block_04_select = set_0_a_line_1_block_04_select | set_0_b_line_1_block_04_select;
assign set_0_line_1_block_03_select = set_0_a_line_1_block_03_select | set_0_b_line_1_block_03_select;
assign set_0_line_1_block_02_select = set_0_a_line_1_block_02_select | set_0_b_line_1_block_02_select;
assign set_0_line_1_block_01_select = set_0_a_line_1_block_01_select | set_0_b_line_1_block_01_select;
assign set_0_line_1_block_00_select = set_0_a_line_1_block_00_select | set_0_b_line_1_block_00_select;

assign set_1_line_1_block_07_select = set_1_a_line_1_block_07_select | set_1_b_line_1_block_07_select;
assign set_1_line_1_block_06_select = set_1_a_line_1_block_06_select | set_1_b_line_1_block_06_select;
assign set_1_line_1_block_05_select = set_1_a_line_1_block_05_select | set_1_b_line_1_block_05_select;
assign set_1_line_1_block_04_select = set_1_a_line_1_block_04_select | set_1_b_line_1_block_04_select;
assign set_1_line_1_block_03_select = set_1_a_line_1_block_03_select | set_1_b_line_1_block_03_select;
assign set_1_line_1_block_02_select = set_1_a_line_1_block_02_select | set_1_b_line_1_block_02_select;
assign set_1_line_1_block_01_select = set_1_a_line_1_block_01_select | set_1_b_line_1_block_01_select;
assign set_1_line_1_block_00_select = set_1_a_line_1_block_00_select | set_1_b_line_1_block_00_select;

assign line_0_block_07 = set_0_line_0_block_07_select | set_1_line_0_block_07_select;
assign line_0_block_06 = set_0_line_0_block_06_select | set_1_line_0_block_06_select;
assign line_0_block_05 = set_0_line_0_block_05_select | set_1_line_0_block_05_select;
assign line_0_block_04 = set_0_line_0_block_04_select | set_1_line_0_block_04_select;
assign line_0_block_03 = set_0_line_0_block_03_select | set_1_line_0_block_03_select;
assign line_0_block_02 = set_0_line_0_block_02_select | set_1_line_0_block_02_select;
assign line_0_block_01 = set_0_line_0_block_01_select | set_1_line_0_block_01_select;
assign line_0_block_00 = set_0_line_0_block_00_select | set_1_line_0_block_00_select;

assign line_1_block_07 = set_0_line_1_block_07_select | set_1_line_1_block_07_select;
assign line_1_block_06 = set_0_line_1_block_06_select | set_1_line_1_block_06_select;
assign line_1_block_05 = set_0_line_1_block_05_select | set_1_line_1_block_05_select;
assign line_1_block_04 = set_0_line_1_block_04_select | set_1_line_1_block_04_select;
assign line_1_block_03 = set_0_line_1_block_03_select | set_1_line_1_block_03_select;
assign line_1_block_02 = set_0_line_1_block_02_select | set_1_line_1_block_02_select;
assign line_1_block_01 = set_0_line_1_block_01_select | set_1_line_1_block_01_select;
assign line_1_block_00 = set_0_line_1_block_00_select | set_1_line_1_block_00_select;

assign line_0_block_07_match = line_0_match & line_0_block_07;
assign line_0_block_06_match = line_0_match & line_0_block_06;
assign line_0_block_05_match = line_0_match & line_0_block_05;
assign line_0_block_04_match = line_0_match & line_0_block_04;
assign line_0_block_03_match = line_0_match & line_0_block_03;
assign line_0_block_02_match = line_0_match & line_0_block_02;
assign line_0_block_01_match = line_0_match & line_0_block_01;
assign line_0_block_00_match = line_0_match & line_0_block_00;

assign line_1_block_07_match = line_1_match & line_1_block_07;
assign line_1_block_06_match = line_1_match & line_1_block_06;
assign line_1_block_05_match = line_1_match & line_1_block_05;
assign line_1_block_04_match = line_1_match & line_1_block_04;
assign line_1_block_03_match = line_1_match & line_1_block_03;
assign line_1_block_02_match = line_1_match & line_1_block_02;
assign line_1_block_01_match = line_1_match & line_1_block_01;
assign line_1_block_00_match = line_1_match & line_1_block_00;

assign block_07 = line_0_block_07_match | line_1_block_07_match;
assign block_06 = line_0_block_06_match | line_1_block_06_match;
assign block_05 = line_0_block_05_match | line_1_block_05_match;
assign block_04 = line_0_block_04_match | line_1_block_04_match;
assign block_03 = line_0_block_03_match | line_1_block_03_match;
assign block_02 = line_0_block_02_match | line_1_block_02_match;
assign block_01 = line_0_block_01_match | line_1_block_01_match;
assign block_00 = line_0_block_00_match | line_1_block_00_match;

assign read_byte[7] = block_07;
assign read_byte[6] = block_06;
assign read_byte[5] = block_05;
assign read_byte[4] = block_04;
assign read_byte[3] = block_03;
assign read_byte[2] = block_02;
assign read_byte[1] = block_01;
assign read_byte[0] = block_00;

