//***************************************************************
// Description: 
// File Name: mux42.v
// Author: Haoran Geng
// Email: 
// Created Time: Thu 02 Mar 2023 10:23:12 PM CST
// Revision history:
//***************************************************************

module mux42(din,sel,dout);
    input  [1:0] din [3:0];
    input  [1:0] sel;
    output [1:0] dout;

    MuxKeyWithDefault #(
        .NR_KEY(4),
        .KEY_LEN(2),
        .DATA_LEN(2)
    ) u_mkwd (
        .out(dout), 
        .key(sel), 
        .default_out(2'b00), 
        .lut({
            2'b00, din[0],
            2'b01, din[1],
            2'b10, din[2],
            2'b11, din[3]
        })
    );
endmodule

