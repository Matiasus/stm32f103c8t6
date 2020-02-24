# STM32F103C8T6 / Ubuntu 18.04

## Install stlink
Install stlink into /opt folder.

```sh
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
cp etc/udev/rules.d/49-stlinkv* /etc/udev/rules.d/

# restart sudo restart udev
udevadm control --reload

# trigger
udevadm trigger
```
