#!/bin/sh


FILE=$1
THREADS=$2
EXECUTABLE="word_counter_app"
BUILD_DIR="build"
EXECUTABLE_PATH="$BUILD_DIR/src/$EXECUTABLE"

if [ ! -d $BUILD_DIR ]
then
     mkdir $BUILD_DIR
fi

# Build the project:

cd "$BUILD_DIR" || exit 1

# Check if build is needed (change the flag)
NEEDS_BUILD=false

# Check if executable exists
if [ ! -f "../$EXECUTABLE_PATH" ]; then
    NEEDS_BUILD=false
fi

# Perform build if needed
if [ "$NEEDS_BUILD" = true ]; then
    echo "🔧 Building the project..."
    cmake .. || { echo "CMake failed"; exit 1; }
    make clean 
    make -j || { echo "Make failed"; exit 1; }
    echo "✅ Build complete."
fi

if [ -z "$FILE" ]; then
    echo "\n\tUsage: $0 <filename>\n"
    exit 1
fi

echo "$FILE"
# Run the program:
echo "\n ****************__________ OUTPUT __________ ****************\n\n"
cd ..
./"$EXECUTABLE_PATH" "$FILE"
