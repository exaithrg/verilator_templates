#include <nvboard.h>
#include <Vled_ring.h>

static TOP_NAME led_ring;
#define dut led_ring

void nvboard_bind_all_pins(Vled_ring* top);

static void single_cycle() {
  dut.clk = 0; dut.eval();
  dut.clk = 1; dut.eval();
}

static void reset(int n) {
  dut.rst = 1;
  while (n -- > 0) single_cycle();
  dut.rst = 0;
}

static void reset_n(int n) {
  dut.rst = 1;
  while (n -- > 0) single_cycle();
  dut.rst = 0;
}

int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();

  reset_n(10);

  while(1) {
    nvboard_update();
    single_cycle();
  }
}
