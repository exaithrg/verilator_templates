//***************************************************************
// Description: 
// File Name: mux21e.v
// Author: Haoran Geng
// Email: 
// Created Time: Thu 02 Mar 2023 10:19:41 PM CST
// Revision history:
//***************************************************************
module mux21e(a,b,s,y);
  input   a,b,s;
  output  y;
  MuxKey #(2, 1, 1) i0 (y, s, {
    1'b0, a,
    1'b1, b
  });
endmodule
