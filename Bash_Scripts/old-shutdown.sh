echo "turn off PCS services"
service cron stop

kill -2 $(pidof RoboDiscoveryService)


PID=$(pidof RoboVision3DService)
kill -15 $PID
while pgrep -x "RoboVision3DSer" > /dev/null; do 
    sleep 1
done

kill -2 $(pidof IPMonitor)
kill -2 $(pidof ResetApp)

echo "turn off clock to supervisor IC"
gpio mode 23 pwm
gpio pwm 23 0
# Make Clock Outout Pin As Input
gpio mode 23 in


echo "Issue shutdown Command"
shutdown -h now
