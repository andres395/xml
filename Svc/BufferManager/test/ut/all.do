#!/bin/sh

# ----------------------------------------------------------------------
# all.do
# ----------------------------------------------------------------------

. ./defs.sh

redo ../../all
redo-ifchange tester
isf_target ut
