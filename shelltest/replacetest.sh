#!/bin/bash
awk -F ':' '{print $2}' test | tr "\n" " " > test1
