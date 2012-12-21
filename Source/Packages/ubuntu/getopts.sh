#!/bin/bash

while getopts ":d:v:n:m:h" opt; do
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
    h)
      echo "Usage: `basename $0` -d <DIST> -v <VERSION> -h"
      echo " -d <DIST>      Set Ubuntu Distribution (default: ${MAINDIST})"
      echo " -v <VERSION>   Set package version (default: ${VERSION})"
      echo " -n <NAME>      Set packager name  (default: ${CHANGELOG_NAME})"
      echo " -m <EMAIL>     Set packager email (default: ${CHANGELOG_EMAIL})"
      echo " -h             Show this help text"
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

