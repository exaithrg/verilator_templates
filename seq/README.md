# NOTE

Based on NVboard Example

**flow**:

```
mk
mk run(run nvboard)
mk sim(if using verilator for simulating)
mk wave(if .vcd file is generated)
```

**If you want to change top name:**

```
➜  npc git:(pa0) ✗ find . -name "*" | xargs grep "led_ring" 
./constr/led_ring.nxdc:top=led_ring
./vsrc/led_ring.v:// File Name: led_ring.v
./vsrc/led_ring.v:module led_ring(
./csrc/led_ring.cpp:#include <Vled_ring.h>
./csrc/led_ring.cpp:static TOP_NAME led_ring;
./csrc/led_ring.cpp:#define dut led_ring
./csrc/led_ring.cpp:void nvboard_bind_all_pins(Vled_ring* top);
./Makefile:TOPNAME = led_ring
./Makefile:NXDC_FILES = constr/led_ring.nxdc
./Makefile:	./build/led_ring
➜  npc git:(pa0) ✗
```
