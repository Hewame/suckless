#!/bin/bash
# Author: Hewa Saleem

# Set the Keyboard Layouts on the fly.
# Archwiki: If you want the default variant, specify an empty 
# string as the variant (the comma must stay)

layouts="us,de,iq,ar"
variants=",,ku_ara," 
sw_key="grp:alt_shift_toggle"
setxkbmap -layout $layouts -variant $variants -option $sw_key

active_layout () {
    if [[ "$(xkblayout)" = "iq" ]]; then
        keyl="KU";
    else
        keyl="$(xkblayout | tr [:lower:] [:upper:])";
    fi
}

more_status () {
    # Caps Lock Status
    caps=$(xset q | awk '/Caps/ {print $4}')
    # Full Date Info
    datum=$(date '+%R:%S %a %d/%m/%Y')
    # Wifi state: UP or DOWN
    wifi=$(cat /sys/class/net/wl*/operstate | tr [:lower:] [:upper:])
}

while true; do
    active_layout
    more_status
    xsetroot -name "[ Wifi: $wifi ] [ CAPS: $caps ] [ $datum ] [ $keyl ]"
    sleep 0.1
done

