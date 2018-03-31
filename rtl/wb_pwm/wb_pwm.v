//---------------------------------------------------------------------------
// Wishbone UART 
//
// Register Description:
//
//    0x00   en0
//    0x04   period0
//    0x08   duty0

//    0x0C   en1
//    0x10   period1
//    0x14   duty1

//    0x18   en2
//    0x1C   period2
//    0x20   duty2

//    0x24   en3
//    0x28   period3
//    0x2C   duty3

//    0x30   en4
//    0x34   period4
//    0x38   duty4

//    0x3C   en5
//    0x40   period5
//    0x44   duty5

//    0x48   en6
//    0x4C   period6
//    0x50   duty6

//    0x54   en7
//    0x58   period7
//    0x5C   duty7
//
//---------------------------------------------------------------------------

module wb_pwm (
	input              clk,
	input              reset,
	// Wishbone interface
	input              wb_stb_i,
	input              wb_cyc_i,
	output             wb_ack_o,
	input              wb_we_i,
	input       [31:0] wb_adr_i,
	input        [3:0] wb_sel_i,
	input       [31:0] wb_dat_i,
	output reg  [31:0] wb_dat_o,
	// Pwm Wires
	output      [7:0]  pwmo
);

//---------------------------------------------------------------------------
// Actual PWM engine
//---------------------------------------------------------------------------

reg        wr;
reg        rd;
reg  [7:0] din;
reg  [6:0] adrs;
wire [7:0] dout;

pwm pwm0(	
	.clk(clk),
	.rst(reset),
	.rd(rd),
	.wr(wr),
	.din(din),
	.adrs(adrs),
	.dout(dout),
	.pwmo(pwmo)
);

//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------

wire wb_rd = wb_stb_i & wb_cyc_i & ~wb_we_i;
wire wb_wr = wb_stb_i & wb_cyc_i &  wb_we_i;

reg  ack;

assign wb_ack_o = wb_stb_i & wb_cyc_i & ack;

always @(posedge clk)
begin
	if (reset) begin
		wb_dat_o[31:8] <= 24'b0;
		ack <= 0;
	end else begin
		wb_dat_o[31:8] <= 24'b0;
		ack <= 0;

		if (wb_rd & ~ack) begin
			ack <= 1;
			rd <= 1;

			adrs <= wb_adr_i;
			wb_dat_o[7:0] <= dout;

		end else if (wb_wr & ~ack ) begin
			ack <= 1;
			wr <= 1;

			adrs <= wb_adr_i;
			din <= wb_dat_i[7:0];

		end else begin
			rd <= 0;
			wr <= 0;
		end
	end
end


endmodule
