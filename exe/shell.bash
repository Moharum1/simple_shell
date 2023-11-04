#!/bin/bash

echo "parent process ID : $$"
echo "The current process ID : $PPID"

# Calculate the maximum PID based on PID width
if [ "$(getconf LONG_BIT)" == "64" ]; then
    max_pid=$((2**22 - 1))  # 22 bits for PIDs on 64-bit systems
else
    max_pid=$((2**15 - 1))  # 15 bits for PIDs on 32-bit systems
fi

echo "The max pid in this system is $max_pid"