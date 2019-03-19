#!/bin/bash

chmod gu+rw $HOME

f="$HOME/.vimrc"
g="$HOME/.viminfo"

rm -f $f $g
touch $f $g
chmod gu+rw $f $g

echo "*encoding=utf-8"        > $g

echo ":set nocompatible"    >  $f
echo ":syntax on"        >> $f
echo ":set autoindent"        >> $f
echo ":set smartindent"        >> $f
echo ":set hlsearch"        >> $f
echo ":set mouse=a"        >> $f
echo ":set number"        >> $f
echo ":set ruler"        >> $f
echo ":set background=dark"    >> $f
echo ":set bs=2"        >> $f
echo "let skip_defaults_vim=1"    >> $f
echo 'set viminfo=""'        >> $f

