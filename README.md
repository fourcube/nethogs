# nethogs

Fork of http://nethogs.sf.net. 

**Warning**: nethogs works by looking up process information inside the /proc filesystem. When connections are opened and closed very quickly, it may not be able to associate a packet with a process. The information data nethogs gives might therefor not be 100% reliable.

## New Features 

- Line mode 
  - (`sudo nethogs -t`) works again
  - consistently use `\t` as column separator
- Output can be filtered by process command line or PID (`sudo nethogs -f sshd -f netcat`) 
- Less CPU usage
- Traffic Filter with filter expression (`sudo nethogs -f sshd -f netcat -l "dst port 22 or src port 22"`)
- View mode switch (sudo nethogs -v kbps|b|kb|mb)

## Introduction

NetHogs is a small 'net top' tool. Instead of breaking the traffic down per protocol or per subnet, like most tools do, it groups bandwidth by process. NetHogs does not rely on a special kernel module to be loaded. If there's suddenly a lot of network traffic, you can fire up NetHogs and immediately see which PID is causing this. This makes it easy to indentify programs that have gone wild and are suddenly taking up your bandwidth.

Since NetHogs heavily relies on /proc, it currently runs on Linux only. 

## Installation

Dependencies:
- libpcap-dev 
- libncurses5-dev

```
make clean && make
sudo make install
```

## Running

```
sudo nethogs [-f <processname>]* [-d refresh_interval] [-t tracemode / line based output] [-l <filter expression>] [-v <view mode>] device*
```

## Status

* Only IPv4 TCP is currently supported // Source code looks like IPv6 is implemented ???
* Sort the output by other values than network usage
* Make it work correctly on machines with multiple IP addresses
* Integrate into another tool??

## License

GPL
