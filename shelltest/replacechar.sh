#!/bin/bash
# replace all file of folder char
# example
#
#
# $: ./replacetest.sh ~/old/
#
if [ -d "$1" ]; then
echo $1
#sed -ri 's/__([^ELASTOS].*)_H__/__ELASTOS_TEXT_\1_H__/g' `grep __[^ELASTOS].*_H__ -rl $1`
sed -ri 's/_C([^_Elastos].*)\.h/_Elastos_Text_C\1.h/g' `grep _C[^_Elastos].*\.h -rl $1`
else
echo "Please input right directory!!!"
fi
