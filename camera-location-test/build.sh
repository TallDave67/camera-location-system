#!/bin/sh
DIRECTORY="build"
if [ -d "$DIRECTORY" ]
then
    echo "$DIRECTORY exists on your filesystem."
else
  mkdir $DIRECTORY
fi
cd $DIRECTORY
DIRECTORY="lib"
if [ -d "$DIRECTORY" ]
then
    echo "$DIRECTORY exists on your filesystem."
else
  mkdir $DIRECTORY
fi

cp "../../camera-location-engine/build/src/camera/libcamera_location_engine-src-camera.a" lib/.
cmake ../
truncate --size -1 ./CMakeFiles/camera_location_test.dir/link.txt
echo -n "lib/libcamera_location_engine-src-camera.a " >> ./CMakeFiles/camera_location_test.dir/link.txt
make VERBOSE=1
