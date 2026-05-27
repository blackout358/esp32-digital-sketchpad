#!/bin/bash

echo "$1"

ffmpeg -i "$1".png -vcodec rawvideo -f rawvideo -pix_fmt rgb565be "$1".raw
xxd -i "$1".raw "$1".h 
rm "$1".raw
