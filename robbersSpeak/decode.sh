#!/bin/bash
#Decodes the string given. Works best with file redirection

sed "s/\([bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ]\)o\1/\1/g" $1
