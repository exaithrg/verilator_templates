//***************************************************************
// Description: 
// File Name: mux42.v
// Author: Haoran Geng
// Email: 
// Created Time: Thu 02 Mar 2023 10:23:12 PM CST
// Revision history:
//***************************************************************

module mux42(a,s,y);
  input  [1:0] a [3:0];
  input  [1:0] s;
  output [1:0] y;
  MuxKeyWithDefault #(4, 2, 2) i0 (y, s, 2'b00, {
    2'b00, a[0],
    2'b01, a[1],
    2'b10, a[2],
    2'b11, a[3]
  });
endmodule

