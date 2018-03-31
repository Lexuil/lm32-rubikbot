module pwm(clk,rst,rd,wr,din,adrs,dout,pwmo);
	
	input clk;
	input rst;
	input rd;
	input wr;
	input [7:0] din;
	input [6:0] adrs;
	output reg [7:0] dout;
	output [7:0] pwmo;
	
reg [7:0] dinf;

reg [7:0] period0 = 0;
reg [7:0] period1 = 0;
reg [7:0] period2 = 0;
reg [7:0] period3 = 0;
reg [7:0] period4 = 0;
reg [7:0] period5 = 0;
reg [7:0] period6 = 0;
reg [7:0] period7 = 0;

reg [7:0] duty0 = 0;
reg [7:0] duty1 = 0;
reg [7:0] duty2 = 0;
reg [7:0] duty3 = 0;
reg [7:0] duty4 = 0;
reg [7:0] duty5 = 0;
reg [7:0] duty6 = 0;
reg [7:0] duty7 = 0;

reg en0 = 0;
reg en1 = 0;
reg en2 = 0;
reg en3 = 0;
reg en4 = 0;
reg en5 = 0;
reg en6 = 0;
reg en7 = 0;

	
counter pwm0(.clk(clk), .period(period0), .duty(duty0), .state(pwmo[0]), .en(en0));
counter pwm1(.clk(clk), .period(period1), .duty(duty1), .state(pwmo[1]), .en(en1));
counter pwm2(.clk(clk), .period(period2), .duty(duty2), .state(pwmo[2]), .en(en2));
counter pwm3(.clk(clk), .period(period3), .duty(duty3), .state(pwmo[3]), .en(en3));
counter pwm4(.clk(clk), .period(period4), .duty(duty4), .state(pwmo[4]), .en(en4));
counter pwm5(.clk(clk), .period(period5), .duty(duty5), .state(pwmo[5]), .en(en5));
counter pwm6(.clk(clk), .period(period6), .duty(duty6), .state(pwmo[6]), .en(en6));
counter pwm7(.clk(clk), .period(period7), .duty(duty7), .state(pwmo[7]), .en(en7));

	
	always @(posedge clk) begin

		if (rst) begin
			period0 = 0;
			period1 = 0;
			period2 = 0;
			period3 = 0;
			period4 = 0;
			period5 = 0;
			period6 = 0;
			period7 = 0;

			duty0 = 0;
			duty1 = 0;
			duty2 = 0;
			duty3 = 0;
			duty4 = 0;
			duty5 = 0;
			duty6 = 0;
			duty7 = 0;

			en0 = 0;
			en1 = 0;
			en2 = 0;
			en3 = 0;
			en4 = 0;
			en5 = 0;
			en6 = 0;
			en7 = 0;
		end
	
		if(wr == 1) begin
			
			dinf = din;
			
			case(adrs)
				7'h00: en0 = dinf;
				7'h04: period0 = dinf;
				7'h08: duty0 = dinf;
				
				7'h0c: en1 = dinf;
				7'h10: period1 = dinf;
				7'h14: duty1 = dinf;
				
				7'h18: en2 = dinf;
				7'h1c: period2 = dinf;
				7'h20: duty2 = dinf;
				
				7'h24: en3 = dinf;
				7'h28: period3 = dinf;
				7'h2c: duty3 = dinf;
				
				7'h30: en4 = dinf;
				7'h34: period4 = dinf;
				7'h38: duty4 = dinf;
				
				7'h3c: en5 = dinf;
				7'h40: period5 = dinf;
				7'h44: duty5 = dinf;
				
				7'h48: en6 = dinf;
				7'h4c: period6 = dinf;
				7'h50: duty6 = dinf;
				
				7'h54: en7 = dinf;
				7'h58: period7 = dinf;
				7'h5c: duty7 = dinf;
				
			default
				dinf = din;
				
			endcase
		end
		
		if(rd == 1) begin
			
			case(adrs)
				7'h00: dout = en0;
				7'h04: dout = period0;
				7'h08: dout = duty0;
				
				7'h0c: dout = en1;
				7'h10: dout = period1;
				7'h14: dout = duty1;
				
				7'h18: dout = en2;
				7'h1c: dout = period2;
				7'h20: dout = duty2;
				
				7'h24: dout = en3;
				7'h28: dout = period3;
				7'h2c: dout = duty3;
				
				7'h30: dout = en4;
				7'h34: dout = period4;
				7'h38: dout = duty4;
				
				7'h3c: dout = en5;
				7'h40: dout = period5;
				7'h44: dout = duty5;
				
				7'h48: dout = en6;
				7'h4c: dout = period6;
				7'h50: dout = duty6;
				
				7'h54: dout = en7;
				7'h58: dout = period7;
				7'h5c: dout = duty7;
				
			default
				dinf = din;
				
			endcase
		end
		
	end


endmodule
