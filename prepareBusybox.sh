#!/bin/bash

path=$(cd "$(dirname "$0")"; pwd)

srcPath="busybox-1.18.5"
srcPathArchive="busybox-1.18.5.tar.bz2"
mkRun="run.sh"
systemSourceArchive="includes-redhat.tar.bz2"
systemSourceFolder="systems/redhat/usr"
redhatFolder="systems/redhat"
typeChef="../TypeChef"
hercules="../Hercules"


# Check for busybox source files
if [ ! -d $srcPath ]; then
	# Busybox directory does not exist
	if [ ! -f $srcPathArchive ]; then
		#Download source files
		echo "Downloading BusyBox source files."
		wget http://www.busybox.net/downloads/busybox-1.18.5.tar.bz2
	fi
	# Extract source files
	tar xvjf busybox-1.18.5.tar.bz2
fi

# Check for run.sh file
if [ ! -f $mkRun ]; then
	java -Xmx1024M -Xss256M -XX:PermSize=256M -XX:MaxPermSize=512M -jar sbt-launch.jar mkrun
fi

# Prepare busybox script, creates presence condition files
./run.sh de.fosd.typechef.busybox.ProcessFileList busybox/busybox_pcs.txt busybox-1.18.5/

# Check system source files
if [ ! -d $systemSourceFolder ]; then
	if [ ! -f $systemSourceArchive ]; then
		#Download system files
		echo "Downloading system source files."
		wget http://www.cs.cmu.edu/%7Eckaestne/tmp/includes-redhat.tar.bz2
	fi
	# Create redhat folder
	if [ ! -d $redhatFolder ]; then
		mkdir -p $redhatFolder
	fi
	# Extract system files
	tar xvjf $systemSourceArchive -C $redhatFolder
fi


# replace busybox sources with our modified versions (modified if ifdeftoif was possible otherwise)
cd "ifdeftoif_modified_files/"
cp -rfv ./* ../
cd ..
