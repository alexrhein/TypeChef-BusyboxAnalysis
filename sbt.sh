#!/bin/sh
SBT_OPTS="-XX:+UseConcMarkSweepGC -XX:+CMSClassUnloadingEnabled -XX:PermSize=256M -XX:MaxPermSize=512M"
exec java -Xmx1024M ${SBT_OPTS} -jar ./sbt-launch.jar "$@"
