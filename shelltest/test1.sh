#!/bin/bash
#echo "a,b,c,d" | sed 's/,/n/g' | tr -t 'n' ','
#datamid2=`echo $uuiddata | awk -F '-' '{print $5}'`
#awk 'BEGIN {count=0;print"[start]user count is", count;} {count=count+1;print $0;} END{print "[end] user count is ", count}' /etc/passwd 

#ls -l ~ | awk 'BEGIN {size=0; print "[start]size is ", size} {if($5>4096*1024){size=size+$5;}} END{print "[end]size is ", size/1024/1024, "M"} '

awk -F ':' 'BEGIN {count=0;} {name[count] = $1; count++;} END {for(i=0;i < NR; i++) print i, name[i]}' /etc/passwd
