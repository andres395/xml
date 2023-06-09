# F´ Cross-Compilation Tutorial

## Table of Contents

* <a href="#Introduction">1. Introduction</a>
  * <a href="#Cross-Compiling">1.1. Cross-Compiling</a>
  * <a href="#Upload-to-the-Raspberry-Pi">1.2. Upload to the Raspberry Pi</a>
  * <a href="#Running-Ref-on-the-Raspberry-Pi">1.3. Running Ref on the Raspberry Pi</a>
  * <a href="#Setting-A-Default-Toolchain">1.4. Setting A Default Toolchain</a>
* <a href="#Conclusion">2. Conclusion</a>

## 1. Introduction

In this section, we will take our Ref topology and cross-compile it for the
Raspberry Pi. In order to fully benefit from this tutorial, the user should
acquire a Raspberry Pi and have the cross-compilation toolchain as described
in [RPI](https://github.com/nasa/fprime/blob/master/RPI/README.md).

This part of the tutorial requires the user to have gone through the previous
sections and have a complete Ref topology. The user should also have an
understanding of the Raspberry Pi and specifically how to SSH into the Pi and
run applications.

<a name="Cross-Compiling"></a>
### 1.1. Cross-Compiling

In order to cross-compile for a specific architecture, the user needs to
generate a new build directory using a CMake toolchain file for that specific
architecture. F´ includes a toolchain for the Raspberry Pi (assuming that the
tools are installed correctly). This toolchain is called “raspberrypi”. The 
cross-compilation build for the Raspberry Pi can be generated by running the
following commands in the Ref directory:

```sh
fprime-util generate raspberrypi
```

followed by:
```sh
fprime-util build raspberrypi
```

This will generate the binary at `Ref/build-artifacts/raspberrypi/bin/Ref`. 

<a name="Upload-to-the-Raspberry-Pi"></a>
### 1.2. Upload to the Raspberry Pi

The user can then run the ground system as before with some additional
arguments:
```sh
fprime-gds -n --dictionary build-artifacts/raspberrypi/dict/RefTopologyAppDictionary.xml
```

Assuming that there is no firewall or other network limitations between the 
Raspberry Pi and the host, the user can then copy the binary to the Raspberry
Pi by running the following from the Ref directory:

```sh
scp build-artifacts/raspberrypi/bin/Ref pi@<YOUR RASPBERRY PI IP ADDRESS>:~
```

This will use the secure copy protocol (scp) to copy the executable over to
your Raspberry Pi's home directory.

<a name="Running-Ref-on-the-Raspberry-Pi"></a>
### 1.3. Running Ref on the Raspberry Pi

You can log into the Raspberry Pi via SSH by running:
```sh
ssh pi@<YOUR RASPBERRY PI IP ADDRESS>
```

Finally, you can run the Ref deployment on the Raspberry Pi as follows:
```sh
./Ref -a <ground system ip> -p 50000
```

Now the Raspberry Pi should be powered up and running the Ref deployment and
our host system should be running the ground system. 

> If the code worked when running natively but it isn't connecting for this
example then the cause is likely a firewall or network issue. Make sure
port 50000 is exposed to the Pi, and that the Pi can ping the ground system
machine.

<a name="Setting-A-Default-Toolchain"></a>
### 1.4. Setting A Default Toolchain

As we have seen in the previous sections, cross-compilation builds can be done
explicitly by setting the toolchain. However, some users may wish to make a
particular toolchain the default and don't want to specify it every time.

A recommended way of setting a default toolchain in F´ is by adding a 
[settings.ini file](../../UsersGuide/user/settings.md). This file provides
build-time configuration settings for F´ and can be used to set a default
toolchain as follows:

```ini
[fprime]
; ... other options in file ...
default_toolchain: raspberrypi
```

Now the "raspberrypi" build can be created with a call to 
`fprime-util generate` and the original native build can be made by explicitly 
setting the native toolchain: `fprime-util generate native`.

### 2. Conclusion

The Cross-Compilation tutorial has shown us how to cross-compile our simple Ref
application to the Raspberry Pi. We have seen how to copy our deployment to the
Raspberry Pi and run the ground system on our host computer to interact with
our deployment on the Raspberry Pi.

The user is now directed back to the [Tutorials](../README.md) for further
reading or to the [GPS Tutorial](../GpsTutorial/Tutorial.md) for a more
advanced tutorial. For information on porting F´ to a new platform please
refer to the [User's Guide](../../UsersGuide/guide.md).