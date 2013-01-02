#!/bin/bash --

CHANGELOG_NAME="Astade Developers"
CHANGELOG_EMAIL="dev@astade.tigris.org"
DIST="precise"
PATCHLEVEL=1
DIST_PATCHLEVEL=1

while getopts ":d:v:n:m:p:P:h" opt; do
  case $opt in
    d)
      DIST=$OPTARG
      ;;
    v)
      VERSION=$OPTARG
      ;;
    n)
      CHANGELOG_NAME=$OPTARG
      ;;
    m)
      CHANGELOG_EMAIL=$OPTARG
      ;;
    p)
      PATCHLEVEL=$OPTARG
      ;;
    P)
      DIST_PATCHLEVEL=$OPTARG
      ;;
    h)
      echo "Usage: `basename $0` -d <DIST> -v <VERSION> -h"
      echo " -d <DIST>                  Set Ubuntu Distribution (default: ${MAINDIST})"
      echo " -v <VERSION>               Set package version (default: ${VERSION})"
      echo " -n <NAME>                  Set packager name  (default: ${CHANGELOG_NAME})"
      echo " -m <EMAIL>                 Set packager email (default: ${CHANGELOG_EMAIL})"
      echo " -p <PATCHLEVEL>            Set patch level  (default: ${PATCHLEVEL})"
      echo " -P <DIST_PATCHLEVEL>       Set backport patch level (default: ${DIST_PATCHLEVEL})"
      echo " -h             		Show this help text"
      echo
      exit 1
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

