#!/bin/bash

osascript <<EOF
    tell application "System Events"
        tell process "Terminal"
            set frontmost to true
        end tell
    end tell

    tell application "Terminal"
        if((font of first window as string)is equal to "Mario16px") then
            set font of first window to "Andale Mono"
        else
            set font of first window to "Mario16px"
        end if
    end tell
EOF
