#! /bin/bash

data=$1
length=$(cat $DATA | wc -l)
i=1
counter=0
current_length=$length
length_less=$((length - 1))

until [ $i -gt $length_less ]; do
    current_pair=$(current_length -n $current_length $data | head -n 2)
    current_value=$(echo $current_pair | sed "s/^[0-9]*//g")
    previous_value=$(echo $current_pair | sed "s/[0-9]*$//g")
    if [ $current_value -gt $previous_value ]; then
        ((counter = counter + 1))
    fi

    current_length=$((length_less - i))
    ((i = start + 1))
done

echo $counter

