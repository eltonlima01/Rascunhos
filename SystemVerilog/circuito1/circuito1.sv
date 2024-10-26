module circuito1 (
    input logic x, y, z,
    output logic f1, f2
);
    logic w1, w2, w3, w4, w5;
    assign w1 = ~y;
    assign w2 = w1 & z;
    assign f1 = w2 | x;
    assign w3 = ~y;
    assign w5 = w3 & x;
    assign w4 = ~x;
    assign w6 = w4 & z;
    assign f2 = w5 | w6;
endmodule 