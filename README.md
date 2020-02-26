# STM32F103C8T6 / Ubuntu 18.04

## Install stlink
Install stlink into /opt folder.

```
# install libusb
sudo apt-get install libusb-1.0-0-dev

 # step into /opt if exists
cd /opt

# copy github folder into /opt
git clone https://github.com/texane/stlink.git

# step into stlink
cd stlink

# clean
make clean

# build and install
cd build/Release && make install

# install udev rules
sudo cp etc/udev/rules.d/49-stlinkv* /etc/udev/rules.d/

# restart sudo restart udev
sudo udevadm control --reload

# trigger
sudo udevadm trigger

# If error occurs
# st-info: error while loading shared libraries: libstlink.so.1:
#          cannot open shared object file: No such file or directory
sudo ldconfig
```
## Acknowledgement
- [Geoffrey Brown](https://github.com/geoffreymbrown/STM32-Template)
- [STM32 microcontroller #1: toolchain & LED blink](http://emsyfs.blogspot.com/2016/03/stm32-microcontroller-1-toolchain-led.html)
