# NPC Makefile based on nvboard/example/Makefile

TOPNAME = mux42
NXDC_FILES = constr/mux42.nxdc
INC_PATH ?=

VERILATOR = verilator
# verilator --trace --cc --exe --build -j 4 -Wall csrc/sim_top.cpp vsrc/doubleclick.v	
VERILATOR_CFLAGS += -MMD --trace --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default
	# @echo "make all"
	# original mk all
	# verilator --trace --cc --exe --build -j 4 -Wall csrc/sim_top.cpp vsrc/doubleclick.v	

run: $(BIN)
	@$^

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	# @echo "make sim"
	./build/mux21

wave:
	gtkwave wave.vcd
	
clean:
	rm -rf $(BUILD_DIR)
	rm wave.vcd

# include ../Makefile

.PHONY: default all clean run sim wave

