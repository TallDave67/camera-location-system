#!/bin/sh
cd camera-location-engine
./build.sh
cd ../camera-location-test
./build.sh
./run.sh
cd ../camera-location-engine
./run.sh
