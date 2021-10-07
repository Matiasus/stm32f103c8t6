# Start with stm32 in Ubuntu 20.04

# Dependencies / Softwer
- [Install libusb](https://github.com/Matiasus/stm32f103c8t6#install-libusb) - userspace USB programming library development files,
- [Install stlink](https://github.com/Matiasus/stm32f103c8t6#install-stlink) - open source toolset to program and debug STM32 devices and boards,
- [Install GNU Arm Embedded Toolchain](https://github.com/Matiasus/stm32f103c8t6#install-gnu-toolchain) - is a ready-to-use, open-source suite of tools for C, C++ and assembly programming.

## Install [libusb](https://packages.ubuntu.com/search?lang=en&keywords=libusb-1.0-0-dev)
```console
ubuntu@ubuntu:~$ sudo apt-get install libusb-1.0-0-dev
```

## Install [stlink](https://github.com/stlink-org/stlink)
There are two possible ways described how to install [stlink](https://github.com/stlink-org/stlink), e.g.:
- using [.deb package](https://github.com/Matiasus/stm32f103c8t6#install-deb-package)
- from [source](https://github.com/Matiasus/stm32f103c8t6#install-from-source)

### Install .deb package
Download and install [.deb](https://github.com/stlink-org/stlink/releases) package using Software Center. Another possible way to install stlink is described in section below.

### Install from source
Install stlink into folder `/opt`
```console
ubuntu@ubuntu:~$ cd /opt
ubuntu@ubuntu:~$ git clone https://github.com/texane/stlink.git
ubuntu@ubuntu:~$ cd stlink
ubuntu@ubuntu:~$ make clean
ubuntu@ubuntu:~$ make release
ubuntu@ubuntu:~$ make install
```

#### Install / Copy stlink rules
```console
// install udev rules
ubuntu@ubuntu:~$ sudo cp etc/udev/rules.d/49-stlinkv* /etc/udev/rules.d/
// restart sudo restart udev
ubuntu@ubuntu:~$ sudo udevadm control --reload
// using this command no need to disconnect and connect device
ubuntu@ubuntu:~$ sudo udevadm trigger
``` 
#### Troubleshooting
```console
// error message
st-info: error while loading shared libraries: libstlink.so.1:
cannot open shared object file: No such file or directory.
// solving
ubuntu@ubuntu:~$ sudo ldconfig
```

## Install [GNU Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
The GNU Arm Embedded toolchain contains integrated and validated packages featuring the GCC compiler, libraries, and other tools necessary for bare-metal software development. 

Download and extract [GNU Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads). Then copy extracted files into folder `/opt/gcc-arm`:
```console
ubuntu@ubuntu:~$ sudo cp -a /home/<your name of home directory>/Downloads/<Extracted GNU Toolchain package>  /opt/gcc-arm
```
Structure of folder `/opt/gcc-arm` should look like:
- arm-none-eabi
- bin
- lib
- share

### Create symbolic links
```console
ubuntu@ubuntu:~$ sudo ln -s /opt/gcc-arm/bin/arm-none-eabi-gcc /usr/bin/arm-none-eabi-gcc
ubuntu@ubuntu:~$ sudo ln -s /opt/gcc-arm/bin/arm-none-eabi-ar /usr/bin/arm-none-eabi-ar
ubuntu@ubuntu:~$ sudo ln -s /opt/gcc-arm/bin/arm-none-eabi-as /usr/bin/arm-none-eabi-as
ubuntu@ubuntu:~$ sudo ln -s /opt/gcc-arm/bin/arm-none-eabi-objcopy /usr/bin/arm-none-eabi-objcopy
ubuntu@ubuntu:~$ sudo ln -s /opt/gcc-arm/bin/arm-none-eabi-size /usr/bin/arm-none-eabi-size
```
### Trobleshooting
```console
// error message
arm-none-eabi-gdb: error while loading shared libraries: libncurses.so.5: 
cannot open shared object file: No such file or directory
// solve
ubuntu@ubuntu:~$ sudo apt-get install libncurses5
```

# Links
- [GDB cannot find libncurses](https://stackoverflow.com/questions/53450745/message-unable-to-run-arm-none-eabi-gdb-cannot-find-libncurses-so-5)
- [Compiling](https://github.com/stlink-org/stlink/blob/develop/doc/compiling.md)
- [How to install arm-none-eabi-gdb](https://itectec.com/ubuntu/ubuntu-how-to-install-arm-none-eabi-gdb-on-ubuntu-20-04-lts-focal-fossa/)
- [Led blink](http://emsyfs.blogspot.com/2016/03/stm32-microcontroller-1-toolchain-led.html)
- [Installing & using ST-Link v2 to flash STM32 targets on Linux](https://fishpepper.de/2016/09/16/installing-using-st-link-v2-to-flash-stm32-on-linux/)
- [Verify correct udev configuration for device access #764](https://github.com/stlink-org/stlink/issues/764)
