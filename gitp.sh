#!/bin/sh
$ARG
echo "Enter your commit message:"
read ARG
git add .
git commit -m "$ARG"
git push