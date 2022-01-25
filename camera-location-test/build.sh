#!/bin/sh
DIRECTORY="build"
if [ -d "$DIRECTORY" ]
then
    echo "$DIRECTORY exists on your filesystem."
else
  mkdir $DIRECTORY
fi
cd $DIRECTORY

# generate the build system
cmake ../

# manually copy over the library file we need to a folder in this build ...
cp "../../camera-location-engine/build/src/camera/libcamera_location_engine-src-camera.a" lib/.
# ... and add it's name to end of the one-line list of library files in the link.txt file
truncate --size -1 ./CMakeFiles/camera_location_test.dir/link.txt
echo -n "lib/libcamera_location_engine-src-camera.a " >> ./CMakeFiles/camera_location_test.dir/link.txt

# run the build
make VERBOSE=1
