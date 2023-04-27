# Verilator_Templates

**Support Verilator Version: `4.210`**

Manual: [Verilator_4.210_Users_Guide](https://github.com/exaithrg/Verilator_4.210_Users_Guide)

## TODO
use top.cpp and top.v in all templates

## comb

Template for combinational logic (mux42)

## seq

Template for sequential logic (lfsr)

## More Info

```
/home/geng/D/Manuals/IC_Design/verilator
https://github.com/NJU-ProjectN/nvboard
https://github.com/exaithrg/iverilog_templates
https://github.com/exaithrg/nvboard_templates
```



# How to install Verilator 5.008 with zsh

Guide: https://verilator.org/guide/latest/install.html

**Brief**:

```sh
# Prerequisites:
#sudo apt-get install git perl python3 make autoconf g++ flex bison ccache
#sudo apt-get install libgoogle-perftools-dev numactl perl-doc
#sudo apt-get install libfl2  # Ubuntu only (ignore if gives error)
#sudo apt-get install libfl-dev  # Ubuntu only (ignore if gives error)
#sudo apt-get install zlibc zlib1g zlib1g-dev  # Ubuntu only (ignore if gives error)

git clone https://github.com/verilator/verilator   # Only first time

# Every time you need to build:
unsetenv VERILATOR_ROOT  # For csh; ignore error if on bash
unset VERILATOR_ROOT  # For bash
cd verilator
git pull         # Make sure git repository is up-to-date
git tag          # See what versions exist
#git checkout master      # Use development branch (e.g. recent bug fixes)
#git checkout stable      # Use most recent stable release
#git checkout v{version}  # Switch to specified release version

autoconf         # Create ./configure script
# export VERILATOR_ROOT=`pwd`   # if your shell is bash
# setenv VERILATOR_ROOT `pwd`   # if your shell is csh
./configure      # Configure and create Makefile
make -j `nproc`  # Build Verilator itself (if error, try just 'make')
make test
# If you get "make: help2man: no such file or directory make"
# sudo apt install help2man # Thanks: https://blog.csdn.net/weixin_70720143/article/details/129652016
sudo make install
```

**Result**:

![image-20230427143651652](readme.assets/image-20230427143651652.png)

# THE END
