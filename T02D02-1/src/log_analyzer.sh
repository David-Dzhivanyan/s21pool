#!bin/bash
logway=$1
countUniqFile=$(awk '{print $1}' $logway | uniq -d | wc -l)
countListElement=$(wc -l $logway | awk '{print $1}')
countUniqHash=$(awk -F " - " '{print $4}' files.log | uniq -c | wc -l)
echo $countUniqFile $countListElement $countUniqHash
