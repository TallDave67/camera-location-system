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

# manually copy over the library files we need to a folder in this build ...
cp "../../camera-location-engine/build/src/agent/libcamera_location_engine-src-agent.a" lib/.
cp "../../camera-location-engine/build/src/camera/libcamera_location_engine-src-camera.a" lib/.
cp "../../camera-location-engine/build/src/image/libcamera_location_engine-src-image.a" lib/.
cp "../../camera-location-engine/build/src/input/libcamera_location_engine-src-input.a" lib/.
cp "../../camera-location-engine/build/src/transformer/libcamera_location_engine-src-transformer.a" lib/.

# ... and add their names to end of the one-line list of library files in the link.txt file
truncate --size -1 ./CMakeFiles/camera_location_test.dir/link.txt
LIBRARIES="\
lib/libcamera_location_engine-src-agent.a \
lib/libcamera_location_engine-src-camera.a \
lib/libcamera_location_engine-src-image.a \
lib/libcamera_location_engine-src-input.a \
lib/libcamera_location_engine-src-transformer.a " 
echo -n $LIBRARIES >> ./CMakeFiles/camera_location_test.dir/link.txt

# run the build
make VERBOSE=1
