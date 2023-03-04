// #include "verilated.h"
// #include "verilated_vcd_c.h"
// #include "Vmux42.h"
#include <nvboard.h>
#include <Vmux42.h>

static TOP_NAME mux42;
#define dut mux42

void nvboard_bind_all_pins(Vmux42* top);

int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();

  while(1) {
    nvboard_update();
    dut.eval();
  }

}

