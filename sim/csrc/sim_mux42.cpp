#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vmux42.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux42* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vmux42;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();
  top->sel=0b00;  top->din[0]=0b11;  step_and_dump_wave();
                  top->din[0]=0b01;  step_and_dump_wave();
  top->sel=0b01;  top->din[1]=0b10;  step_and_dump_wave();
                  top->din[1]=0b00;  step_and_dump_wave();
  top->sel=0b10;  top->din[2]=0b11;  step_and_dump_wave();
                  top->din[2]=0b01;  step_and_dump_wave();
  top->sel=0b11;  top->din[3]=0b10;  step_and_dump_wave();
                  top->din[3]=0b00;  step_and_dump_wave();
  sim_exit();
}

