//---------------------------------------------------------------------------
// Wishbone UART 
//
// Register Description:
//
//    0x00 DAT      [ 0 | 0 | 0 | full | 0 | 0 | dato | empty ]
//    0x04 DATAIN
//    0x08 DATAOUT
//    0x0C RESET
//
//---------------------------------------------------------------------------

module wb_fifo #(
	parameter          DATO_WIDTH  = 8,
	parameter          FIFO_LENGTH = 5
) (
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
	output reg  [31:0] wb_dat_o
);

//---------------------------------------------------------------------------
// Actual UART engine
//---------------------------------------------------------------------------
reg wclk;
wire [7:0] datin;
reg rclk;

wire [7:0] datout;
wire full;
wire empty;
wire dato;
reg rst;

FIFO #(
		.DATO_WIDTH(DATO_WIDTH),
		.FIFO_LENGTH(FIFO_LENGTH)

) fifo0 (
		.wclk(wclk),
		.datin(datin),
		.rclk(rclk),
		.rst(rst),
		.datout(datout),
		.full(full),
		.empty(empty),
		.dato(dato)
);

//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------
wire [7:0] dat = { 3'b0, full, 2'b0, dato, empty };

wire wb_rd = wb_stb_i & wb_cyc_i & ~wb_we_i;
wire wb_wr = wb_stb_i & wb_cyc_i &  wb_we_i;

reg  ack;

assign wb_ack_o       = wb_stb_i & wb_cyc_i & ack;

assign datin = wb_dat_i[7:0];

always @(posedge clk)
begin
	if (reset) begin
		wb_dat_o[31:8] <= 24'b0;
		wclk  <= 0;
		rclk <= 0;
		rst <= 1;
		ack    <= 0;
	end else begin
		wb_dat_o[31:8] <= 24'b0;
		wclk  <= 0;
		rclk <= 0;
		rst <= 0;
		ack    <= 0;

		if (wb_rd & ~ack) begin
			ack <= 1;

			case (wb_adr_i[3:2])
				2'b00: begin
					wb_dat_o[7:0] <= dat;
				end
				2'b01: begin
					wb_dat_o[7:0] <= datout;
					rclk <= 1;
				end
				default: begin
					wb_dat_o[7:0] <= 8'b0;
				end
			endcase

		end else if (wb_wr & ~ack ) begin
			ack <= 1;

			case (wb_adr_i[3:2])
				2'b10: begin
					wclk <= 1;
				end

				2'b11: begin
					rst <= 1;
				end
				default: begin
					wb_dat_o[7:0] <= 8'b0;
				end
			endcase
		end
	end
end


endmodule
