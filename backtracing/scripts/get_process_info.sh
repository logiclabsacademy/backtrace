#!/bin/bash

PROCESS_NAME=$1

if [ -z "$PROCESS_NAME" ]; then
    echo "Usage: $0 <process_name>"
    exit 1
fi

# Get the process information
ps -C "$PROCESS_NAME" -o pid,comm,%cpu,%mem,start_time --no-headers | while read -r pid comm cpu mem start_time; do
    echo "Process Name: $comm"
    echo "Process ID: $pid"
    echo "CPU Usage: $cpu%"
    echo "Memory Usage: $mem%"
    echo "Start Time: $start_time"
    echo "-----------------------------"
done

# Check if no process was found
if [ $? -ne 0 ]; then
    echo "No process found with the name $PROCESS_NAME"
fi

