TOPNAME = mux41

VERILATOR = verilator
# verilator --trace --cc --exe --build -j 4 -Wall csrc/sim_top.cpp vsrc/doubleclick.v	
VERILATOR_CFLAGS += -MMD --trace --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default
# all:
#     verilator --trace --cc --exe --build -j 4 -Wall sim_mux41.cpp mux41.v

.PHONY: sim
sim:
	./build/$(TOPNAME)
	# ./build/V$(TOPNAME)

.PHONY: wave
wave:
	gtkwave ./dump.vcd &
	
.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
	rm dump.vcd

