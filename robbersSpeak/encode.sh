#!/bin/bash
#Encodes the string given. Works best with file redirection

sed "s/\([bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ]\)/\1o\l\1/g" $1
