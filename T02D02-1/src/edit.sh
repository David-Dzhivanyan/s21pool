#!/bin/bash
sed -i "" "s/$2/$3/g" $1
way=$(pwd)/$1
size=$(wc -c $1 | awk '{print $1}' )
date=$(stat $1 | awk -F '"' '{print $2}')
sha=$(shasum -a 256 $1 | awk '{print $1}' )
log="$way - $size - $date - $sha - sha256"
echo $log >> files.log
