module circuito0 (
    input logic x,
    input logic y,
    input logic z,
    output logic f1,
    output logic f2
);
assign f1 = x | ((~y) & z);
assign f2 = (x & (~y)) | ((~x) & z);
endmodule 