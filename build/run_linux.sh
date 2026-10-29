#!/bin/sh
SCRIPT_DIR=$(dirname "$(readlink -f "$0")")
export LD_LIBRARY_PATH="$SCRIPT_DIR/lib:$LD_LIBRARY_PATH"
cd "$SCRIPT_DIR"
exec ./game.out

