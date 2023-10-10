#!/bin/bash

while true
do
    echo "|----SOC----|----PMIC----| "
    #vcgencmd measure_temp
    echo "$(vcgencmd measure_temp) | $(vcgencmd measure_temp pmic)"
    echo "|-----------|------------| "
    #vcgencmd measure_temp pmic
    sleep 1
done

LD_LIBRARY_PATHLD_LIBRARY_PATH