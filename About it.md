A C++ command-line utility that takes an IPv4 address as 
input and calculates essential networking parameters. This tool is 
useful for network topology planning, cybersecurity analysis, and 
validating host configurations.
Validates IPv4 input formatting and octet ranges (0-255).
Identifies network class (A, B, C, D, E).
Determines if the address is Private, Public, or Loopback.
Automatically assigns the default Subnet Mask based on the detected 
network class.
Converts both the decimal IPv4 address and Subnet Mask into their 
binary.
Calculates the total number of network bits, host bits, and usable IP 
addresses on the network.
Compilation and Execution

Compile the source code using your preferred compiler:
```bash
   g++ IPv4SubnetConverter.cpp -o subnet_converter
