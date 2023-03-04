//***************************************************************
// Description: 
// File Name: led_ring.v
// Author: Haoran Geng
// Email: 
// Created Time: Wed 01 Mar 2023 07:13:21 PM CST
// Revision history:
//***************************************************************
module led_ring(
    input clk,
    input rst,
    output reg [15:0] led
);
    reg [31:0] count;
    always @(posedge clk) begin
      if (rst) begin 
          led <= 16'b1; 
          count <= 32'b0; 
      end else begin
        if (count == 0) led <= {led[14:0], led[15]};
        count <= (count >= 5000000 ? 32'b0 : count + 1);
      end
    end
endmodule

