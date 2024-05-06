#!/bin/sh
$ARG
read ARG
git add .
git commit -m "$ARG"
git push