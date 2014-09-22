#!/bin/bash

${1?"Usage: $0 ARGUMENT"}

wget "http://imgur.com/a/$1" -O -|grep '"thumb-' |cut -d\- -f2 |cut -d\" -f1|
while read id
    do
        echo "Downloading $id image file"
        wget -c "http://i.imgur.com/$id.jpg"
done

#YcQqn
