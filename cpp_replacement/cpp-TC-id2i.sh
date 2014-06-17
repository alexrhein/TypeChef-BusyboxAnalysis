#!/bin/bash
currentpath=$(pwd)
params=( "$@" )
#pipedData=""#$(</dev/stdin)

#  n=0
#  while read line
#  do
#        let n=n+1
#        echo "Line $n contains $line" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
#        pipedData="$pipedData\n$line"
# done
cpp=false
useDefNullInput=false
useStdinInput=false
useFileInput=false
firstInputFile=""
lastFileOnCmd=""


allParams=""
i=0
for arg in "${params[@]}"; do
   i=$(expr $i + 1)
   allParams="$allParams $arg"
   if [[ $arg == "-E" ]]
   then
     cpp=true
   elif [[ $arg == "-" ]]
   then
     useStdinInput=true
   elif [[ $arg == "/dev/null" ]]
   then
     useDefNullInput=true
   elif [ -e $arg ]
   then
     if [[ $firstInputFile == "" && $arg == *.c && $i -gt 1 ]]
     then
       firstInputFile=$arg
     else
       lastFileOnCmd=$arg
     fi
   fi
done
#echo $allParams
if [ "$cpp" = true ] ; then
  if [ "$useDefNullInput" == true ] ; 
  then 
    echo "devNull" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt #ignore
    $allParams
  elif [ "$useStdinInput" == true ] ; 
  then 
    echo "stdIn" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt 
    #capture stdin
    pipedData=$(</dev/stdin)
    echo "$allParams" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
    echo "$pipedData" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
    echo "$pipedData" | $allParams
  else #suppose that input file has been provided
    if [[ ! $firstInputFile == *scripts/* && ! $firstInputFile == "" ]] ;
    then
      echo "fileInput"  >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
      echo "file: $firstInputFile"  >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
      fileNameNoExtension=${firstInputFile%.*}
      #cp "$firstInputFile" "$firstInputFile.bak"
      echo "/local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/analyzeBusybox_one.sh $fileNameNoExtension" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
      echo "$fileNameNoExtension" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
      #call TypeChef
      cd /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement
      echo $allParams > /local/ifdeftoif/ifdeftoif/lastGCCoptions.txt
      /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/analyzeBusybox_one.sh $fileNameNoExtension > /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/LastTC_call.txt
      #go back to original dir
      cd $currentpath
      #run cpp on generated ifdeftoif file
      cpp "$fileNameNoExtension"_ifdeftoif.c -o "$fileNameNoExtension"_ifdeftoif_cpped.c
      cp "$fileNameNoExtension"_ifdeftoif_cpped.c "$lastFileOnCmd"
      echo "$allParams" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
    else
      $allParams
    fi
  fi
else
  $allParams
fi

#if [[ $params == *-E* ]]
#then
	#echo "CPP options: $params"
	#echo "$params" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
	## echo "pipedData:" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
	##echo "$pipedData" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
	#$params #| $pipedData
#else
	##echo "$params" >> /local/ifdeftoif/TypeChef-BusyboxAnalysis_CPP_replacement/cpp_replacement/cpp-log.txt
	#$params #| $pipedData
#fi


