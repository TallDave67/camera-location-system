# Camera Location System

## Specs

* Linux distro "Pop!_OS 21.10"
* cmake version 3.18.4
* The CXX compiler identification is GNU 11.2.0
* opencv 4.5.3

## Description

This system is capable of determining the location of a camera based on a photo of a chessboard pattern taken by the camera.

There are 2 projects in this system.

* camera-location-engine: builds executable camera_location_engine which is an Interactive UI using opencv
* camera-location-test: builds executable camera_location_test which is a unit test program using google test

## Build & Run

You can build & run both projects with the single script [pipeline.sh](pipeline.sh).

### camera-location-engine

You can also build & run just the camera-location-engine project with the 2 scripts [engine build.sh](camera-location-engine/build.sh) and [engine run.sh](camera-location-engine/run.sh).

### camera-location-test

You can also build & run just the camera-location-test project with the 2 scripts [test build.sh](camera-location-test/build.sh) and [test run.sh](camera-location-test/run.sh).

Note that the test build depends upon the camera-location-engine build having been completed already.  Also, you will see that the build.sh script does not use cmake to pull in the engine library files.  Instead, the shell script performs these two unorthodox steps that may cause problems with your build:

* copies the necessary engine library files into the cmake created build/lib folder
* edits the cmake created build/CMakeFiles/camera_location_test.dir/link.txt file and appends the names of these engine libraries

So as long as your cmake version creates the same build directory structure as cmake 3.18.4 there should not be a problem.

## Using the Interactive UI

* Left-mouse button: select corners
* Enter key (CR): run location determination
* Backspace key (BS): erase selected corners and any camera position results
* Escape key (ESC): exit the UI

![Open UI](camera-location-engine/io/output/01_open_ui.png)

### Successful Camera Location

Use the left-mouse button to click on 4 corners in the order you would walk them.

When you click the 4th corner, red lines will be drawn connecting the corners.

If you selected the corners in the correct order, the red shape you see will be a box.

![4 Board Corners Selected](camera-location-engine/io/output/02_board_corners_good.png)

Press CR on the keyboard to run the routine that determines the camera position.

![Camera Position Determined](camera-location-engine/io/output/03_camera_position_good.png)

Press BS or simply click on another point to try again.

Press ESC to exit.

### Unsuccessful Camera Location

The corners you selected may not create a red box that has sufficient chessboard squares inside of it.

![4 Board Corners Not Selected](camera-location-engine/io/output/04_board_corners_bad.png)

In which case the location determination routine will not find the camera position.

![Camera Position Not Determined](camera-location-engine/io/output/05_camera_position_bad.png)

### Output Logging

When you run the UI using the run.sh script it will automatically redirect program stdout to the io/output/output.txt file.

You will also find a sample version of this output file there.

[Sample Output](camera-location-engine/io/output/output_sample.txt)
